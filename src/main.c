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

static IedServer g_iedServer = NULL;

// Импорт функций из ports_logic.c
extern void get_hardware_ifname(int port_idx, char* dest, size_t max_len);
extern int get_hardware_port_status(int port_idx, int nl_fd);
extern int get_hardware_admin_status(int port_idx);
extern int get_hardware_mac_address(int port_idx, char* mac_str, size_t max_len);
extern int32_t get_hardware_capabilities(int port_idx);

extern void print_hardware_capabilities_string(int port_idx);
extern int set_hardware_port_status(int port_idx, int enable);

extern int set_hardware_port_speed(int port_idx, int speed_mbps);
extern int get_hardware_port_speed(int port_idx);

extern int set_autongt(int port_idx, int autongt_enable);
extern int get_hardware_autongt(int port_idx);

extern int get_hardware_mtu(int port_idx);
extern int set_hardware_mtu(int port_idx, int mtu_value);

extern int get_hardware_flow_control(int port_idx);
extern int set_hardware_flow_control(int port_idx, int enable);

static int running = 1;
volatile int32_t g_pending_speed_update = -1;
volatile int32_t g_pending_autongt_update = -1;
volatile int32_t g_pending_mtu_update = -1;
volatile int32_t g_pending_flow_update = -1;

void sigint_handler(int signalId) { running = 0; }

/* Обработчик записи статуса порта (Вкл/Выкл) через AdminCfg */
static MmsDataAccessError
adminCfgWriteHandler(DataAttribute* attr, MmsValue* value, ClientConnection connection, void* parameter)
{
    if (MmsValue_getType(value) == MMS_BOOLEAN) {
        bool enable = MmsValue_getBoolean(value);
        int port_idx = (int)(intptr_t)parameter;

        printf("MMS: Запрос на изменение админ. статуса порта (AdminCfg) -> %s\n", enable ? "UP" : "DOWN");

        if (set_hardware_port_status(port_idx, enable) == 0) {
            return DATA_ACCESS_ERROR_SUCCESS;
        } else {
            return DATA_ACCESS_ERROR_OBJECT_ACCESS_DENIED;
        }
    }
    return DATA_ACCESS_ERROR_TYPE_INCONSISTENT;
}

/* Обработчик записи скорости (MauCfg.setVal) */
static MmsDataAccessError
speedWriteHandler(DataAttribute* attr, MmsValue* value, ClientConnection connection, void* parameter)
{
    if (MmsValue_getType(value) == MMS_INTEGER) {
        int32_t new_speed = MmsValue_toInt32(value);
        int port_idx = (int)(intptr_t)parameter;

        printf("MMS: Запрос на запись скорости порта -> %d Mbps\n", new_speed);

        if (set_hardware_port_speed(port_idx, new_speed) == 0) {
            g_pending_speed_update = new_speed;
            return DATA_ACCESS_ERROR_SUCCESS;
        } else {
            return DATA_ACCESS_ERROR_OBJECT_ACCESS_DENIED;
        }
    }
    return DATA_ACCESS_ERROR_TYPE_INCONSISTENT;
}

/* Обработчик записи автосогласования (AutoNgtCfg.setVal) */
static MmsDataAccessError
autoNgtWriteHandler(DataAttribute* attr, MmsValue* value, ClientConnection connection, void* parameter)
{
    if (MmsValue_getType(value) == MMS_BOOLEAN) {
        bool autongt_enable = MmsValue_getBoolean(value);
        int port_idx = (int)(intptr_t)parameter;

        printf("MMS: Запрос на изменение автосогласования -> %s\n", autongt_enable ? "ON" : "OFF");

        if (set_autongt(port_idx, autongt_enable ? 1 : 0) == 0) {
            g_pending_autongt_update = autongt_enable ? 1 : 0;
            return DATA_ACCESS_ERROR_SUCCESS;
        } else {
            return DATA_ACCESS_ERROR_OBJECT_ACCESS_DENIED;
        }
    }
    return DATA_ACCESS_ERROR_TYPE_INCONSISTENT;
}

/* Обработчик flow control */
static MmsDataAccessError flowWriteHandler(DataAttribute* attr, MmsValue* value, ClientConnection connection, void* parameter) {
    if (MmsValue_getType(value) == MMS_BOOLEAN) {
        bool enable = MmsValue_getBoolean(value);
        if (set_hardware_flow_control((int)(intptr_t)parameter, enable ? 1 : 0) == 0) {
            g_pending_flow_update = enable ? 1 : 0;
            return DATA_ACCESS_ERROR_SUCCESS;
        }
    }
    return DATA_ACCESS_ERROR_TYPE_INCONSISTENT;
}

/* Обработчик записи MTU (MtuCfg.setVal) */
static MmsDataAccessError
mtuWriteHandler(DataAttribute* attr, MmsValue* value, ClientConnection connection, void* parameter)
{
    if (MmsValue_getType(value) == MMS_INTEGER) {
        int32_t new_mtu = MmsValue_toInt32(value);
        int port_idx = (int)(intptr_t)parameter;

        printf("MMS: Запрос на изменение MTU -> %d\n", new_mtu);

        if (set_hardware_mtu(port_idx, new_mtu) == 0) {
            g_pending_mtu_update = new_mtu;
            return DATA_ACCESS_ERROR_SUCCESS;
        } else {
            return DATA_ACCESS_ERROR_OBJECT_ACCESS_DENIED;
        }
    }
    return DATA_ACCESS_ERROR_TYPE_INCONSISTENT;
}

/**
 * Инициализация статических и динамических параметров порта при запуске
 */
void initialize_static_port_attributes(IedServer server, int port_idx) {
    char ifname[16];
    char mac_address[18];
    
    // 1. Читаем и выводим имя порта в PortNam.setVal
    get_hardware_ifname(port_idx, ifname, sizeof(ifname));
    IedServer_updateVisibleStringAttributeValue(server, IEDMODEL_Bridge_LPCP1_PortNam_setVal, ifname);
    printf("MMS Инициализация: LPCP1.PortNam.setVal = %s\n", ifname);

    // 2. Читаем и выводим мак-адрес в PortMac.setVal
    if (get_hardware_mac_address(port_idx, mac_address, sizeof(mac_address)) == 0) {
        IedServer_updateVisibleStringAttributeValue(server, IEDMODEL_Bridge_LPCP1_PortMac_setVal, mac_address);
        printf("MMS Инициализация: LPCP1.PortMac.setVal = %s\n", mac_address);
    } else {
        IedServer_updateVisibleStringAttributeValue(server, IEDMODEL_Bridge_LPCP1_PortMac_setVal, "00:00:00:00:00:00");
        printf("MMS Предупреждение: Не удалось прочитать MAC-адрес устройства\n");
    }

    // 3. Выводим список поддерживаемых режимов в лог текстом
    print_hardware_capabilities_string(port_idx);

    // И записываем режимы в MauCfgCap (INT32) согласно модели
    int32_t caps = get_hardware_capabilities(port_idx);
    IedServer_updateInt32AttributeValue(server, IEDMODEL_Bridge_LPCP1_MauCfgCap_setVal, caps);
    printf("MMS Инициализация: LPCP1.MauCfgCap.setVal = %d (Битовая маска)\n", caps);

    // 4. Инициализация AdminCfg (Включен или Выключен)
    bool is_admin_up = (get_hardware_admin_status(port_idx) != 0);
    IedServer_updateBooleanAttributeValue(server, IEDMODEL_Bridge_LPCP1_AdminCfg_setVal, is_admin_up);
    printf("MMS Инициализация: LPCP1.AdminCfg.setVal = %s\n", is_admin_up ? "True (Включен)" : "False (Выключен)");

    // 5. Инициализация начального состояния Автосогласования (AutoNgt)
    int initial_autongt = get_hardware_autongt(port_idx);
    if (initial_autongt != -1) {
        bool is_auto = (initial_autongt == 1);
        // Записываем и в фактический статус (stVal) и в конфигурацию (setVal)
        IedServer_updateBooleanAttributeValue(server, IEDMODEL_Bridge_LPCP1_AutoNgt_stVal, is_auto);
        IedServer_updateBooleanAttributeValue(server, IEDMODEL_Bridge_LPCP1_AutoNgtCfg_setVal, is_auto);
        printf("MMS Инициализация: Автосогласование = %s\n", is_auto ? "ON" : "OFF");
    } else {
        printf("Внимание: Не удалось прочитать начальное состояние автосогласования\n");
    }

    // 6. Инициализация начальной Скорости (Mau)
    int initial_speed = get_hardware_port_speed(port_idx);
    if (initial_speed > 0) {
        // Записываем и в фактический статус (stVal) и в конфигурацию (setVal)
        IedServer_updateInt32AttributeValue(server, IEDMODEL_Bridge_LPCP1_MauCfg_stVal, initial_speed);
        IedServer_updateInt32AttributeValue(server, IEDMODEL_Bridge_LPCP1_MauCfg_setVal, initial_speed);
        printf("MMS Инициализация: Текущая скорость = %d Mbps\n", initial_speed);
    } else {
        printf("Внимание: Не удалось прочитать начальную скорость (возможно, нет линка)\n");
    }

    // Инициализация MTU
    int initial_mtu = get_hardware_mtu(port_idx);
    if (initial_mtu > 0) {
        IedServer_updateInt32AttributeValue(server, IEDMODEL_Bridge_LPCP1_Mtu_stVal, initial_mtu);
        IedServer_updateInt32AttributeValue(server, IEDMODEL_Bridge_LPCP1_MtuCfg_setVal, initial_mtu);
        printf("MMS Инициализация: Текущий MTU = %d\n", initial_mtu);
    }

    // Инициализация Flow Control
    int flow = get_hardware_flow_control(port_idx);
    if (flow != -1) {
        bool flow_bool = (flow == 1);
        IedServer_updateBooleanAttributeValue(server, IEDMODEL_Bridge_LPCP1_FlowControl_stVal, flow_bool);
        IedServer_updateBooleanAttributeValue(server, IEDMODEL_Bridge_LPCP1_FlowControlCfg_setVal, flow_bool);
        printf("MMS Инициализация: Flow Control = %s\n", flow_bool ? "ON" : "OFF");
    }
}

int main(int argc, char** argv) {
    signal(SIGINT, sigint_handler);

    g_iedServer = IedServer_create(&iedModel);

    // Регистрируем обработчики записи MMS
    IedServer_handleWriteAccess(g_iedServer,
        IEDMODEL_Bridge_LPCP1_AdminCfg_setVal, adminCfgWriteHandler, (void*)(intptr_t)0);
    
    IedServer_handleWriteAccess(g_iedServer,
        IEDMODEL_Bridge_LPCP1_MauCfg_setVal, speedWriteHandler, (void*)(intptr_t)0);
        
    IedServer_handleWriteAccess(g_iedServer,
        IEDMODEL_Bridge_LPCP1_AutoNgtCfg_setVal, autoNgtWriteHandler, (void*)(intptr_t)0);

    IedServer_handleWriteAccess(g_iedServer,
        IEDMODEL_Bridge_LPCP1_MtuCfg_setVal, mtuWriteHandler, (void*)(intptr_t)0);

    IedServer_handleWriteAccess(g_iedServer, 
        IEDMODEL_Bridge_LPCP1_FlowControlCfg_setVal, flowWriteHandler, (void*)(intptr_t)0);

    IedServer_start(g_iedServer, 102);

    if (!IedServer_isRunning(g_iedServer)) {
        printf("Ошибка: запуск сервера не удался. Выполните команду под sudo!\n");
        IedServer_destroy(g_iedServer);
        return -1;
    }

    printf("MMS Сервер запущен на порту 102.\n");

    // Инициализируем атрибуты реальными данными из ОС
    IedServer_lockDataModel(g_iedServer);
    initialize_static_port_attributes(g_iedServer, 0); // Индекс порта 0
    IedServer_unlockDataModel(g_iedServer);

    int nl_fd = socket(AF_NETLINK, SOCK_RAW, NETLINK_ROUTE);
    if (nl_fd < 0) {
        perror("Предупреждение: Ошибка открытия Netlink сокета для чтения Link Status");
    }

    while (running) {
        uint64_t timeMs = Hal_getTimeInMs();

        IedServer_lockDataModel(g_iedServer);

        // Обновление измененной скорости в stVal (после команды клиента)
        if (g_pending_speed_update != -1) {
            IedServer_updateInt32AttributeValue(g_iedServer,
                IEDMODEL_Bridge_LPCP1_MauCfg_stVal, g_pending_speed_update);
            g_pending_speed_update = -1;
        }

        // Обновление измененного автосогласования в stVal (после команды клиента)
        if (g_pending_autongt_update != -1) {
            IedServer_updateBooleanAttributeValue(g_iedServer,
                IEDMODEL_Bridge_LPCP1_AutoNgt_stVal, g_pending_autongt_update == 1);
            g_pending_autongt_update = -1;
        }

        // Периодическое обновление статуса Link (Физически кабель подключен)
        if (nl_fd >= 0) {
            int status0 = get_hardware_port_status(0, nl_fd);
            IedServer_updateInt32AttributeValue(g_iedServer,
                IEDMODEL_Bridge_LPCP1_Mau_stVal, (int32_t)status0);
            
            MmsValue* ts0 = MmsValue_newUtcTime(timeMs / 1000);
            IedServer_updateAttributeValue(g_iedServer, IEDMODEL_Bridge_LPCP1_Mau_t, ts0);
            MmsValue_delete(ts0);
        }

        // В основном цикле (while(running)) добавляем обновление статуса:
        if (g_pending_mtu_update != -1) {
            IedServer_updateInt32AttributeValue(g_iedServer,
                IEDMODEL_Bridge_LPCP1_Mtu_stVal, g_pending_mtu_update);
            g_pending_mtu_update = -1;
        }

        if (g_pending_flow_update != -1) {
            IedServer_updateBooleanAttributeValue(g_iedServer, IEDMODEL_Bridge_LPCP1_FlowControl_stVal, g_pending_flow_update == 1);
            g_pending_flow_update = -1;
        }

        IedServer_unlockDataModel(g_iedServer);

        Thread_sleep(100);
    }

    IedServer_stop(g_iedServer);
    IedServer_destroy(g_iedServer);
    if (nl_fd >= 0) close(nl_fd);

    printf("Сервер успешно остановлен.\n");
    return 0;
}