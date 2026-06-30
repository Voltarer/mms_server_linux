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

#define NUM_PORTS 28

static IedServer g_iedServer = NULL;
extern IedModel iedModel;

extern void get_hardware_ifname(int port_idx, char* dest, size_t max_len);
extern int get_hardware_port_status(int port_idx);
extern int get_hardware_admin_status(int port_idx);
extern int get_hardware_mac_address(int port_idx, char* mac_str, size_t max_len);
extern int32_t get_hardware_capabilities(int port_idx);
extern void print_hardware_capabilities_string(int port_idx);
extern int set_hardware_port_status(int port_idx, int enable);
extern int set_hardware_port_speed(int port_idx, int mode_val);
extern int get_hardware_port_speed(int port_idx);
extern int set_autongt(int port_idx, int autongt_enable);
extern int get_hardware_autongt(int port_idx);
extern int get_hardware_mtu(int port_idx);
extern int set_hardware_mtu(int port_idx, int mtu_value);
extern int get_hardware_flow_control(int port_idx);
extern int set_hardware_flow_control(int port_idx, int enable);

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
        // Бинарная строка 13 бит для Quality IEC 61850
        MmsValue* qVal = MmsValue_newBitString(13);
        
        if (is_valid) {
            // Validity: GOOD (00)
            MmsValue_setBitStringBit(qVal, 0, 0);
            MmsValue_setBitStringBit(qVal, 1, 0);
        } else {
            // Validity: INVALID (01)
            MmsValue_setBitStringBit(qVal, 0, 0);
            MmsValue_setBitStringBit(qVal, 1, 1);
            
            // "Оживляем" Quality Details: выставляем флаги, поясняющие причину невалидности
            MmsValue_setBitStringBit(qVal, 6, 1); // Бит 6: Failure (Аппаратный сбой)
            MmsValue_setBitStringBit(qVal, 7, 1); // Бит 7: OldData (Устаревшие данные)
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
        printf("MMS: Админ. статус порта lan%d -> %s\n", port_idx, enable ? "UP" : "DOWN");
        if (set_hardware_port_status(port_idx, enable) == 0) return DATA_ACCESS_ERROR_SUCCESS;
        return DATA_ACCESS_ERROR_OBJECT_ACCESS_DENIED;
    }
    return DATA_ACCESS_ERROR_TYPE_INCONSISTENT;
}

static MmsDataAccessError speedWriteHandler(DataAttribute* attr, MmsValue* value, ClientConnection connection, void* parameter) {
    if (MmsValue_getType(value) == MMS_INTEGER) {
        int32_t mode_val = MmsValue_toInt32(value);
        int port_idx = (int)(intptr_t)parameter;
        printf("MMS: Получена команда режима %d для lan%d\n", mode_val, port_idx);
        if (set_hardware_port_speed(port_idx, mode_val) == 0) {
            g_pending_speed_update[port_idx] = mode_val;
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
        printf("MMS: Автосогласование lan%d -> %s\n", port_idx, autongt_enable ? "ON" : "OFF");
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
        printf("MMS: MTU lan%d -> %d\n", port_idx, new_mtu);
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
    DataAttribute* da_portnam = get_port_attr("PortNam.setVal", port_idx);
    if(da_portnam) IedServer_updateVisibleStringAttributeValue(server, da_portnam, ifname);

    DataAttribute* da_mac = get_port_attr("PortMac.setVal", port_idx);
    if (da_mac) {
        if (get_hardware_mac_address(port_idx, mac_address, sizeof(mac_address)) == 0) {
            IedServer_updateVisibleStringAttributeValue(server, da_mac, mac_address);
        } else {
            IedServer_updateVisibleStringAttributeValue(server, da_mac, "00:00:00:00:00:00");
        }
    }

    int32_t caps = get_hardware_capabilities(port_idx);
    DataAttribute* da_caps = get_port_attr("MauCfgCap.setVal", port_idx);
    if(da_caps) IedServer_updateInt32AttributeValue(server, da_caps, caps);

    int admin_status = get_hardware_admin_status(port_idx);
    bool is_admin_up = (admin_status == 1);
    DataAttribute* da_admin = get_port_attr("AdminCfg.setVal", port_idx);
    if(da_admin) IedServer_updateBooleanAttributeValue(server, da_admin, is_admin_up);

    int initial_autongt = get_hardware_autongt(port_idx);
    if (initial_autongt != -1) {
        bool is_auto = (initial_autongt == 1);
        IedServer_updateBooleanAttributeValue(server, get_port_attr("AutoNgtCfg.setVal", port_idx), is_auto);
    }

    int initial_speed = get_hardware_port_speed(port_idx);
    if (initial_speed > 0) {
        IedServer_updateInt32AttributeValue(server, get_port_attr("MauCfg.setVal", port_idx), initial_speed);
    }

    int initial_mtu = get_hardware_mtu(port_idx);
    if (initial_mtu > 0) {
        IedServer_updateInt32AttributeValue(server, get_port_attr("MtuCfg.setVal", port_idx), initial_mtu);
    }

    int flow = get_hardware_flow_control(port_idx);
    if (flow != -1) {
        bool flow_bool = (flow == 1);
        IedServer_updateBooleanAttributeValue(server, get_port_attr("FlowControlCfg.setVal", port_idx), flow_bool);
    }
}

int main(int argc, char** argv) {
    signal(SIGINT, sigint_handler);

    for(int i=0; i<NUM_PORTS; i++) {
        g_pending_speed_update[i] = -1;
        g_pending_autongt_update[i] = -1;
        g_pending_mtu_update[i] = -1;
        g_pending_flow_update[i] = -1;
    }

    g_iedServer = IedServer_create(&iedModel);

    for(int i=0; i<NUM_PORTS; i++) {
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
    for(int i=0; i<NUM_PORTS; i++) {
        initialize_static_port_attributes(g_iedServer, i);
    }
    IedServer_unlockDataModel(g_iedServer);

    while (running) {
        uint64_t timeMs = Hal_getTimeInMs();

        IedServer_lockDataModel(g_iedServer);

        for(int i=0; i<NUM_PORTS; i++) {
            // Обработка отложенных обновлений (MMS -> Железо)
            if (g_pending_speed_update[i] != -1) {
                IedServer_updateInt32AttributeValue(g_iedServer, get_port_attr("MauCfg.stVal", i), g_pending_speed_update[i]);
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
            
            // 1. Статус порта (Mau)
            int status = get_hardware_port_status(i);
            bool status_valid = (status != -1);
            if (status_valid) {
                IedServer_updateInt32AttributeValue(g_iedServer, get_port_attr("Mau.stVal", i), (int32_t)status);
            }
            update_quality_and_time(g_iedServer, i, "Mau", status_valid, timeMs);

            // 2. Автосогласование (AutoNgt)
            int autongt = get_hardware_autongt(i);
            bool autongt_valid = (autongt != -1);
            if (autongt_valid) {
                IedServer_updateBooleanAttributeValue(g_iedServer, get_port_attr("AutoNgt.stVal", i), autongt == 1);
            }
            update_quality_and_time(g_iedServer, i, "AutoNgt", autongt_valid, timeMs);

            // 3. MTU
            int mtu = get_hardware_mtu(i);
            bool mtu_valid = (mtu != -1);
            if (mtu_valid) {
                IedServer_updateInt32AttributeValue(g_iedServer, get_port_attr("Mtu.stVal", i), mtu);
            }
            update_quality_and_time(g_iedServer, i, "Mtu", mtu_valid, timeMs);

            // 4. Управление потоком (FlowControl)
            int flow = get_hardware_flow_control(i);
            bool flow_valid = (flow != -1);
            if (flow_valid) {
                IedServer_updateBooleanAttributeValue(g_iedServer, get_port_attr("FlowControl.stVal", i), flow == 1);
            }
            update_quality_and_time(g_iedServer, i, "FlowControl", flow_valid, timeMs);
        }

        IedServer_unlockDataModel(g_iedServer);
        Thread_sleep(100);
    }

    IedServer_stop(g_iedServer);
    IedServer_destroy(g_iedServer);

    printf("Сервер успешно остановлен.\n");
    return 0;
}