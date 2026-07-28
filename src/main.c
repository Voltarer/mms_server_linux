#define _GNU_SOURCE
#include "hal_thread.h"
#include "hal_time.h"
#include "iec61850_server.h"
#include "mms_common.h"
#include "static_model.h"
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <sys/socket.h>
#include <linux/rtnetlink.h>
#include <unistd.h>
#include <stdbool.h>  

#include "models/include/common.h"
#include "models/include/status.h"
#include "models/include/mac.h"
#include "models/include/capabilities.h"
#include "models/include/autoneg.h"
#include "models/include/speed.h"
#include "models/include/mtu.h"
#include "models/include/flow_control.h"
#include "models/include/error.h"
#include "models/include/rxcnt.h"
#include "models/include/txcnt.h"

#include "models/include/channel.h"
#include "models/include/traffic_errors.h"
#include "models/include/health.h"
#include "models/include/mirroring.h"

#define NUM_PORTS 28

static IedServer g_iedServer = NULL;
extern IedModel iedModel;

static int running = 1;
volatile int32_t g_pending_speed_update[NUM_PORTS];
volatile int32_t g_pending_autongt_update[NUM_PORTS];
volatile int32_t g_pending_mtu_update[NUM_PORTS];
volatile int32_t g_pending_flow_update[NUM_PORTS];

void sigint_handler(int signalId) { running = 0; }

static DataAttribute* get_port_attr(const char* attr_suffix, int port_idx) {
    char path[128];
    snprintf(path, sizeof(path), "SwitchBridge/LPCP%d.%s", port_idx + 1, attr_suffix);
    return (DataAttribute*)IedModel_getModelNodeByObjectReference(&iedModel, path);
}

// Вспомогательная функция для обновления Quality (q) и Timestamp (t)
static void update_quality_and_time(IedServer server, int port_idx, const char* node_name, bool is_valid, uint64_t timeMs) {
    char attr_q[64];
    char attr_t[64];
    snprintf(attr_q, sizeof(attr_q), "%s.q", node_name);
    snprintf(attr_t, sizeof(attr_t), "%s.t", node_name);

    DataAttribute* da_q = get_port_attr(attr_q, port_idx);
    if (da_q) {
        MmsValue* qVal = MmsValue_newBitString(13);
        if (is_valid) {
            MmsValue_setBitStringBit(qVal, 0, 0);
            MmsValue_setBitStringBit(qVal, 1, 0);
        } else {
            MmsValue_setBitStringBit(qVal, 0, 0);
            MmsValue_setBitStringBit(qVal, 1, 1);
            MmsValue_setBitStringBit(qVal, 6, 1);
            MmsValue_setBitStringBit(qVal, 7, 1);
        }
        IedServer_updateAttributeValue(server, da_q, qVal);
        MmsValue_delete(qVal);
    }

    DataAttribute* da_t = get_port_attr(attr_t, port_idx);
    if (da_t) {
        Timestamp ts;
        Timestamp_clearFlags(&ts);
        Timestamp_setTimeInMilliseconds(&ts, timeMs);
        IedServer_updateTimestampAttributeValue(server, da_t, &ts);
    }
}

static MmsDataAccessError adminCfgWriteHandler(DataAttribute* attr, MmsValue* value, ClientConnection connection, void* parameter) {
    if (MmsValue_getType(value) == MMS_BOOLEAN) {
        bool enable = MmsValue_getBoolean(value);
        int port_idx = (int)(intptr_t)parameter;
        printf("MMS: Админ. статус порта %d -> %s\n", port_idx + 1, enable ? "UP" : "DOWN");
        if (set_hardware_port_status(port_idx, enable) == 0) return DATA_ACCESS_ERROR_SUCCESS;
        return DATA_ACCESS_ERROR_OBJECT_ACCESS_DENIED;
    }
    return DATA_ACCESS_ERROR_TYPE_INCONSISTENT;
}

static MmsDataAccessError speedWriteHandler(DataAttribute* attr, MmsValue* value, ClientConnection connection, void* parameter) {
    if (MmsValue_getType(value) == MMS_INTEGER) {
        int32_t mau_type = MmsValue_toInt32(value);
        int port_idx = (int)(intptr_t)parameter;
        
        // --- ПРОВЕРКА АВТОСОГЛАСОВАНИЯ ---
        DataAttribute* da_autongt = get_port_attr("AutoNgtCfg.setVal", port_idx);
        if (da_autongt) {
            MmsValue* auto_val = IedServer_getAttributeValue(g_iedServer, da_autongt);
            if (auto_val && MmsValue_getBoolean(auto_val)) {
                printf("MMS: [ОТКЛОНЕНО] Попытка изменить MauCfg (скорость) при включенном AutoNgtCfg на порту %d\n", port_idx + 1);
                return DATA_ACCESS_ERROR_OBJECT_ACCESS_DENIED;
            }
        }

        // Проверка допустимости значения (опционально, фильтруем только нужные MAU)
        if (mau_type != 11 && mau_type != 14 && mau_type != 15 && 
            mau_type != 16 && mau_type != 29 && mau_type != 30) {
            printf("MMS: [ОШИБКА] Неизвестный MAU Type %d (не по RFC 4836)\n", mau_type);
            return DATA_ACCESS_ERROR_OBJECT_VALUE_INVALID;
        }

        printf("MMS: Получена команда MAU Type %d (RFC 4836) для порта %d\n", mau_type, port_idx + 1);
        
        if (set_hardware_port_speed(port_idx, mau_type) == 0) {
            g_pending_speed_update[port_idx] = mau_type;
            return DATA_ACCESS_ERROR_SUCCESS;
        }
        return DATA_ACCESS_ERROR_OBJECT_ACCESS_DENIED;
    }
    return DATA_ACCESS_ERROR_TYPE_INCONSISTENT;
}

static MmsDataAccessError autoNgtWriteHandler(DataAttribute* attr, MmsValue* value, ClientConnection connection, void* parameter) {
    if (MmsValue_getType(value) == MMS_BOOLEAN) {
        bool autongt_enable = MmsValue_getBoolean(value);
        int port_idx = (int)(intptr_t)parameter;
        printf("MMS: Автосогласование порта %d -> %s\n", port_idx + 1, autongt_enable ? "ON" : "OFF");
        if (set_autongt(port_idx, autongt_enable ? 1 : 0) == 0) {
            g_pending_autongt_update[port_idx] = autongt_enable ? 1 : 0;
            return DATA_ACCESS_ERROR_SUCCESS;
        }
        return DATA_ACCESS_ERROR_OBJECT_ACCESS_DENIED;
    }
    return DATA_ACCESS_ERROR_TYPE_INCONSISTENT;
}

static MmsDataAccessError flowWriteHandler(DataAttribute* attr, MmsValue* value, ClientConnection connection, void* parameter) {
    if (MmsValue_getType(value) == MMS_BOOLEAN) {
        bool enable = MmsValue_getBoolean(value);
        int port_idx = (int)(intptr_t)parameter;
        if (set_hardware_flow_control(port_idx, enable ? 1 : 0) == 0) {
            g_pending_flow_update[port_idx] = enable ? 1 : 0;
            return DATA_ACCESS_ERROR_SUCCESS;
        }
    }
    return DATA_ACCESS_ERROR_TYPE_INCONSISTENT;
}

static MmsDataAccessError mtuWriteHandler(DataAttribute* attr, MmsValue* value, ClientConnection connection, void* parameter) {
    if (MmsValue_getType(value) == MMS_INTEGER) {
        int32_t new_mtu = MmsValue_toInt32(value);
        int port_idx = (int)(intptr_t)parameter;
        
        // --- ПРОВЕРКА ГРАНИЦ MTU ---
        if (new_mtu < 64 || new_mtu > 16383) {
            printf("MMS: [ОШИБКА] Попытка установить MTU %d для порта %d. Допустимый диапазон: 64..16383\n", 
                   new_mtu, port_idx + 1);
            return DATA_ACCESS_ERROR_OBJECT_VALUE_INVALID; 
        }

        printf("MMS: MTU порта %d -> %d\n", port_idx + 1, new_mtu);
        if (set_hardware_mtu(port_idx, new_mtu) == 0) {
            g_pending_mtu_update[port_idx] = new_mtu;
            return DATA_ACCESS_ERROR_SUCCESS;
        }
        return DATA_ACCESS_ERROR_OBJECT_ACCESS_DENIED;
    }
    return DATA_ACCESS_ERROR_TYPE_INCONSISTENT;
}

void initialize_static_port_attributes(IedServer server, int port_idx) {
    char ifname[16];
    char mac_address[18];
    
    get_hardware_ifname(port_idx, ifname, sizeof(ifname));

    if (!is_port_present(port_idx)) {
        printf("Init port %d: [ABSENT] (Интерфейс %s не найден в ОС)\n", port_idx + 1, ifname);
        DataAttribute* da_portnam = get_port_attr("PortNam.setVal", port_idx);
        if (da_portnam) IedServer_updateVisibleStringAttributeValue(server, da_portnam, "ABSENT");
        DataAttribute* da_status = get_port_attr("Mau.stVal", port_idx);
        if (da_status) IedServer_updateInt32AttributeValue(server, da_status, 2); // DOWN
        return;
    }

    printf("Init port %d: ifname = %s [OK]\n", port_idx + 1, ifname);

    DataAttribute* da_portnam = get_port_attr("PortNam.setVal", port_idx);
    if (da_portnam) {
        IedServer_updateVisibleStringAttributeValue(server, da_portnam, ifname);
    }

    // MAC-адрес
    DataAttribute* da_mac = get_port_attr("PortMac.setVal", port_idx);
    if (da_mac) {
        if (get_hardware_mac_address(port_idx, mac_address, sizeof(mac_address)) == 0) {
            IedServer_updateVisibleStringAttributeValue(server, da_mac, mac_address);
        } else {
            fprintf(stderr, "[WARN] Port %d (%s): Не удалось получить MAC, установлен по умолчанию\n", port_idx + 1, ifname);
            IedServer_updateVisibleStringAttributeValue(server, da_mac, "00:00:00:00:00:00");
        }
    }

    // Административный статус
    int admin_status = get_hardware_admin_status(port_idx);
    DataAttribute* da_admin = get_port_attr("AdminCfg.setVal", port_idx);
    if (da_admin) {
        if (admin_status != -1) {
            IedServer_updateBooleanAttributeValue(server, da_admin, admin_status == 1);
        } else {
            fprintf(stderr, "[WARN] Port %d (%s): Не удалось получить админ. статус, установлен DOWN\n", port_idx + 1, ifname);
            IedServer_updateBooleanAttributeValue(server, da_admin, false);
        }
    }

    // Автосогласование (конфигурация)
    int initial_autongt = get_hardware_autongt(port_idx);
    DataAttribute* da_autongt_cfg = get_port_attr("AutoNgtCfg.setVal", port_idx);
    if (da_autongt_cfg) {
        if (initial_autongt != -1) {
            IedServer_updateBooleanAttributeValue(server, da_autongt_cfg, initial_autongt == 1);
        } else {
            fprintf(stderr, "[WARN] Port %d (%s): Не удалось получить автосогласование, установлено OFF\n", port_idx + 1, ifname);
            IedServer_updateBooleanAttributeValue(server, da_autongt_cfg, false);
        }
    }

    // Скорость (конфигурация)
    int initial_speed = get_hardware_port_speed(port_idx);
    DataAttribute* da_speed_cfg = get_port_attr("MauCfg.setVal", port_idx);
    if (da_speed_cfg) {
        if (initial_speed > 0) {
            IedServer_updateInt32AttributeValue(server, da_speed_cfg, initial_speed);
        } else {
            fprintf(stderr, "[WARN] Port %d (%s): Не удалось получить скорость, установлена 0\n", port_idx + 1, ifname);
            IedServer_updateInt32AttributeValue(server, da_speed_cfg, 0);
        }
    }

    // MTU (конфигурация)
    int initial_mtu = get_hardware_mtu(port_idx);
    DataAttribute* da_mtu_cfg = get_port_attr("MtuCfg.setVal", port_idx);
    if (da_mtu_cfg) {
        if (initial_mtu > 0) {
            IedServer_updateInt32AttributeValue(server, da_mtu_cfg, initial_mtu);
        } else {
            fprintf(stderr, "[WARN] Port %d (%s): Не удалось получить MTU, установлен 1500\n", port_idx + 1, ifname);
            IedServer_updateInt32AttributeValue(server, da_mtu_cfg, 1500);
        }
    }

    // Flow Control (конфигурация)
    int flow = get_hardware_flow_control(port_idx);
    DataAttribute* da_flow_cfg = get_port_attr("FlowControlCfg.setVal", port_idx);
    if (da_flow_cfg) {
        if (flow != -1) {
            IedServer_updateBooleanAttributeValue(server, da_flow_cfg, flow == 1);
        } else {
            fprintf(stderr, "[WARN] Port %d (%s): Не удалось получить Flow Control, установлен OFF\n", port_idx + 1, ifname);
            IedServer_updateBooleanAttributeValue(server, da_flow_cfg, false);
        }
    }

    // Статус порта (Mau.stVal)
    int status = get_hardware_port_status(port_idx);
    DataAttribute* da_status = get_port_attr("Mau.stVal", port_idx);
    if (da_status) {
        if (status != -1) {
            IedServer_updateInt32AttributeValue(server, da_status, status);
        } else {
            IedServer_updateInt32AttributeValue(server, da_status, 2);
        }
    }

    // Автосогласование статус (AutoNgt.stVal)
    int autongt_st = get_hardware_autongt(port_idx);
    DataAttribute* da_autongt_st = get_port_attr("AutoNgt.stVal", port_idx);
    if (da_autongt_st) {
        if (autongt_st != -1) {
            IedServer_updateBooleanAttributeValue(server, da_autongt_st, autongt_st == 1);
        } else {
            IedServer_updateBooleanAttributeValue(server, da_autongt_st, false);
        }
    }

    // MTU статус (Mtu.stVal)
    int mtu_st = get_hardware_mtu(port_idx);
    DataAttribute* da_mtu_st = get_port_attr("Mtu.stVal", port_idx);
    if (da_mtu_st) {
        if (mtu_st > 0) {
            IedServer_updateInt32AttributeValue(server, da_mtu_st, mtu_st);
        } else {
            IedServer_updateInt32AttributeValue(server, da_mtu_st, 1500);
        }
    }

    // Flow Control статус (FlowControl.stVal)
    int flow_st = get_hardware_flow_control(port_idx);
    DataAttribute* da_flow_st = get_port_attr("FlowControl.stVal", port_idx);
    if (da_flow_st) {
        if (flow_st != -1) {
            IedServer_updateBooleanAttributeValue(server, da_flow_st, flow_st == 1);
        } else {
            IedServer_updateBooleanAttributeValue(server, da_flow_st, false);
        }
    }

    // Начальный статус RxCnt (RxCnt.stVal)
    int64_t rx_st = get_hardware_rx_cnt(port_idx);
    DataAttribute* da_rx_st = get_port_attr("RxCnt.actVal", port_idx);
    if (da_rx_st) {
        IedServer_updateInt64AttributeValue(server, da_rx_st, (rx_st >= 0) ? rx_st : 0);
    }

    // Начальный статус TxCnt (TxCnt.stVal)
    int64_t tx_st = get_hardware_tx_cnt(port_idx);
    DataAttribute* da_tx_st = get_port_attr("TxCnt.actVal", port_idx);
    if (da_tx_st) {
        IedServer_updateInt64AttributeValue(server, da_tx_st, (tx_st >= 0) ? tx_st : 0);
    }

    DataAttribute* da_d = get_port_attr("MauCfg.d", port_idx);
    if (da_d) {
        IedServer_updateVisibleStringAttributeValue(server, da_d, "Port speed configuration");
    }

    DataAttribute* da_dU = get_port_attr("MauCfg.dU", port_idx);
    if (da_dU) {
        IedServer_updateVisibleStringAttributeValue(server, da_dU, "Настройка скорости порта");
    }

    }

int main(int argc, char** argv) {
    signal(SIGINT, sigint_handler);

    for (int i = 0; i < NUM_PORTS; i++) {
        g_pending_speed_update[i] = -1;
        g_pending_autongt_update[i] = -1;
        g_pending_mtu_update[i] = -1;
        g_pending_flow_update[i] = -1;
    }

    g_iedServer = IedServer_create(&iedModel);

    for (int i = 0; i < NUM_PORTS; i++) {
        IedServer_handleWriteAccess(g_iedServer, get_port_attr("AdminCfg.setVal", i), adminCfgWriteHandler, (void*)(intptr_t)i);
        IedServer_handleWriteAccess(g_iedServer, get_port_attr("MauCfg.setVal", i), speedWriteHandler, (void*)(intptr_t)i);
        IedServer_handleWriteAccess(g_iedServer, get_port_attr("AutoNgtCfg.setVal", i), autoNgtWriteHandler, (void*)(intptr_t)i);
        IedServer_handleWriteAccess(g_iedServer, get_port_attr("MtuCfg.setVal", i), mtuWriteHandler, (void*)(intptr_t)i);
        IedServer_handleWriteAccess(g_iedServer, get_port_attr("FlowControlCfg.setVal", i), flowWriteHandler, (void*)(intptr_t)i);
    }

    IedServer_start(g_iedServer, 102);

    if (!IedServer_isRunning(g_iedServer)) {
        printf("Ошибка: запуск сервера не удался. Выполните команду под sudo!\n");
        IedServer_destroy(g_iedServer);
        return -1;
    }

    printf("MMS Сервер запущен на порту 102.\n");

    IedServer_lockDataModel(g_iedServer);
    for (int i = 0; i < NUM_PORTS; i++) {
        initialize_static_port_attributes(g_iedServer, i);
    }
    IedServer_unlockDataModel(g_iedServer);

    while (running) {
        uint64_t timeMs = Hal_getTimeInMs();

        IedServer_lockDataModel(g_iedServer);

        for (int i = 0; i < NUM_PORTS; i++) {
            // Если физического интерфейса в системе нет, выставляем INVALID-качество и скипаем опросы
            if (!is_port_present(i)) {
                IedServer_updateInt32AttributeValue(g_iedServer, get_port_attr("Mau.stVal", i), 2); // DOWN
                update_quality_and_time(g_iedServer, i, "Mau", false, timeMs);
                update_quality_and_time(g_iedServer, i, "AutoNgt", false, timeMs);
                update_quality_and_time(g_iedServer, i, "Mtu", false, timeMs);
                update_quality_and_time(g_iedServer, i, "FlowControl", false, timeMs);
                update_quality_and_time(g_iedServer, i, "RxCnt", false, timeMs);
                update_quality_and_time(g_iedServer, i, "TxCnt", false, timeMs);

                update_quality_and_time(g_iedServer, i, "ChLiv", false, timeMs);
                update_quality_and_time(g_iedServer, i, "RedChLiv", false, timeMs);
                update_quality_and_time(g_iedServer, i, "InOv", false, timeMs);
                update_quality_and_time(g_iedServer, i, "OutOv", false, timeMs);
                update_quality_and_time(g_iedServer, i, "FerPort", false, timeMs);
                update_quality_and_time(g_iedServer, i, "Health", false, timeMs);
                update_quality_and_time(g_iedServer, i, "Beh", false, timeMs);
                update_quality_and_time(g_iedServer, i, "Mir", false, timeMs);
                continue;
            }

            // Обработка отложенных обновлений (MMS -> Железо)
            if (g_pending_speed_update[i] != -1) {
                IedServer_updateInt32AttributeValue(g_iedServer, get_port_attr("MauCfg.setVal", i), g_pending_speed_update[i]);
                g_pending_speed_update[i] = -1;
            }

            if (g_pending_autongt_update[i] != -1) {
                IedServer_updateBooleanAttributeValue(g_iedServer, get_port_attr("AutoNgt.stVal", i), g_pending_autongt_update[i] == 1);
                g_pending_autongt_update[i] = -1;
            }

            if (g_pending_mtu_update[i] != -1) {
                IedServer_updateInt32AttributeValue(g_iedServer, get_port_attr("Mtu.stVal", i), g_pending_mtu_update[i]);
                g_pending_mtu_update[i] = -1;
            }

            if (g_pending_flow_update[i] != -1) {
                IedServer_updateBooleanAttributeValue(g_iedServer, get_port_attr("FlowControl.stVal", i), g_pending_flow_update[i] == 1);
                g_pending_flow_update[i] = -1;
            }

            // Опрос железа и обновление модели (Железо -> MMS)
            int status = get_hardware_port_status(i);
            bool status_valid = (status != -1);
            if (status_valid) {
                IedServer_updateInt32AttributeValue(g_iedServer, get_port_attr("Mau.stVal", i), (int32_t)status);
            }
            update_quality_and_time(g_iedServer, i, "Mau", status_valid, timeMs);

            int autongt = get_hardware_autongt(i);
            bool autongt_valid = (autongt != -1);
            if (autongt_valid) {
                IedServer_updateBooleanAttributeValue(g_iedServer, get_port_attr("AutoNgt.stVal", i), autongt == 1);
            }
            update_quality_and_time(g_iedServer, i, "AutoNgt", autongt_valid, timeMs);

            int mtu = get_hardware_mtu(i);
            bool mtu_valid = (mtu != -1);
            if (mtu_valid) {
                IedServer_updateInt32AttributeValue(g_iedServer, get_port_attr("Mtu.stVal", i), mtu);
            }
            update_quality_and_time(g_iedServer, i, "Mtu", mtu_valid, timeMs);

            int flow = get_hardware_flow_control(i);
            bool flow_valid = (flow != -1);
            if (flow_valid) {
                IedServer_updateBooleanAttributeValue(g_iedServer, get_port_attr("FlowControl.stVal", i), flow == 1);
            }
            update_quality_and_time(g_iedServer, i, "FlowControl", flow_valid, timeMs);

            // Опрос счетчика принятых пакетов (RxCnt)
            int64_t rx_cnt = get_hardware_rx_cnt(i);
            bool rx_cnt_valid = (rx_cnt != -1);
            if (rx_cnt_valid) {
                IedServer_updateInt64AttributeValue(g_iedServer, get_port_attr("RxCnt.actVal", i), rx_cnt);
            }
            update_quality_and_time(g_iedServer, i, "RxCnt", rx_cnt_valid, timeMs);

            // Опрос счетчика переданных пакетов (TxCnt)
            int64_t tx_cnt = get_hardware_tx_cnt(i);
            bool tx_cnt_valid = (tx_cnt != -1);
            if (tx_cnt_valid) {
                IedServer_updateInt64AttributeValue(g_iedServer, get_port_attr("TxCnt.actVal", i), tx_cnt);
            }
            update_quality_and_time(g_iedServer, i, "TxCnt", tx_cnt_valid, timeMs);

            // Модуль: Channel (Каналы) 
            int chliv = get_hardware_chliv(i);
            bool chliv_valid = (chliv != -1);
            if (chliv_valid) IedServer_updateBooleanAttributeValue(g_iedServer, get_port_attr("ChLiv.stVal", i), chliv == 1);
            update_quality_and_time(g_iedServer, i, "ChLiv", chliv_valid, timeMs);

            int redchliv = get_hardware_redchliv(i);
            bool redchliv_valid = (redchliv != -1);
            if (redchliv_valid) IedServer_updateBooleanAttributeValue(g_iedServer, get_port_attr("RedChLiv.stVal", i), redchliv == 1);
            update_quality_and_time(g_iedServer, i, "RedChLiv", redchliv_valid, timeMs);

            // Модуль: Traffic Errors (Ошибки и переполнения)
            int inov = get_hardware_in_ov(i);
            bool inov_valid = (inov != -1);
            if (inov_valid) IedServer_updateBooleanAttributeValue(g_iedServer, get_port_attr("InOv.stVal", i), inov == 1);
            update_quality_and_time(g_iedServer, i, "InOv", inov_valid, timeMs);

            int outov = get_hardware_out_ov(i);
            bool outov_valid = (outov != -1);
            if (outov_valid) IedServer_updateBooleanAttributeValue(g_iedServer, get_port_attr("OutOv.stVal", i), outov == 1);
            update_quality_and_time(g_iedServer, i, "OutOv", outov_valid, timeMs);

            int32_t fer = get_hardware_fer_port(i);
            bool fer_valid = (fer != -1);
            if (fer_valid) IedServer_updateInt32AttributeValue(g_iedServer, get_port_attr("FerPort.stVal", i), fer);
            update_quality_and_time(g_iedServer, i, "FerPort", fer_valid, timeMs);

            // Модуль: Health & Behavior (Здоровье и Поведение)
            int health = get_hardware_health(i);
            bool health_valid = (health != -1);
            if (health_valid) IedServer_updateInt32AttributeValue(g_iedServer, get_port_attr("Health.stVal", i), health);
            update_quality_and_time(g_iedServer, i, "Health", health_valid, timeMs);

            int beh = get_hardware_beh(i);
            bool beh_valid = (beh != -1);
            if (beh_valid) IedServer_updateInt32AttributeValue(g_iedServer, get_port_attr("Beh.stVal", i), beh);
            update_quality_and_time(g_iedServer, i, "Beh", beh_valid, timeMs);

            // Модуль: Mirroring (Зеркалирование)
            int mir = get_hardware_mir(i);
            bool mir_valid = (mir != -1);
            if (mir_valid) IedServer_updateBooleanAttributeValue(g_iedServer, get_port_attr("Mir.stVal", i), mir == 1);
            update_quality_and_time(g_iedServer, i, "Mir", mir_valid, timeMs);
        }

        IedServer_unlockDataModel(g_iedServer);
        Thread_sleep(100);
    }

    IedServer_stop(g_iedServer);
    IedServer_destroy(g_iedServer);

    printf("Сервер успешно остановлен.\n");
    return 0;
}