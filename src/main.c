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

#ifndef _WIN32
    #include <sys/socket.h>
    #include <linux/rtnetlink.h>
    #include <unistd.h>
#endif

static IedServer g_iedServer = NULL;

extern int get_hardware_port_status(int port_idx, int nl_fd);
extern int set_hardware_port_status(int port_idx, int enable);
extern int set_hardware_port_speed(int port_idx, int speed_mbps);

static int running = 1;
// Переменная для безопасного обновления stVal из основного цикла (избегаем deadlock)
volatile int32_t g_pending_speed_update = -1;

void sigint_handler(int signalId) { running = 0; }

/* Обработчик записи статуса порта (Mau.stVal) */
static MmsDataAccessError
writeAccessHandler(DataAttribute* attr, MmsValue* value, ClientConnection connection, void* parameter)
{
    if (MmsValue_getType(value) == MMS_INTEGER) {
        int32_t val = MmsValue_toInt32(value);
        int port_idx = (int)(intptr_t)parameter;

        printf("MMS: Запись статуса для порта %d -> %d\n", port_idx, val);

        if (set_hardware_port_status(port_idx, val) == 0) {
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
            printf("Hardware: Скорость порта успешно изменена на %d Mbps\n", new_speed);
            
            // Саму переменную setVal библиотека обновит сама, если вернем SUCCESS.
            // Но нам нужно обновить еще и stVal. Чтобы не вызвать Deadlock,
            // мы выставляем флаг для основного цикла.
            g_pending_speed_update = new_speed;

            return DATA_ACCESS_ERROR_SUCCESS;
        } else {
            printf("Hardware Error: Не удалось изменить скорость (проверьте права или имя интерфейса)\n");
            // ВАЖНО: Мы больше не пишем сюда MmsValue_setInt32(attr->mmsValue, 0),
            // чтобы значение не сбрасывалось в ноль при ошибке.
            return DATA_ACCESS_ERROR_OBJECT_ACCESS_DENIED;
        }
    }
    return DATA_ACCESS_ERROR_TYPE_INCONSISTENT;
}

int main(int argc, char** argv) {
    signal(SIGINT, sigint_handler);

    g_iedServer = IedServer_create(&iedModel);

    // Привязываем обработчики
    IedServer_handleWriteAccess(g_iedServer,
        IEDMODEL_Bridge_LPCP1_Mau_stVal, writeAccessHandler, (void*)(intptr_t)0);
    IedServer_handleWriteAccess(g_iedServer,
        IEDMODEL_Bridge_LPCP1_MauCfg_setVal, speedWriteHandler, (void*)(intptr_t)0);

    IedServer_start(g_iedServer, 102);

    if (!IedServer_isRunning(g_iedServer)) {
        printf("Ошибка: запуск сервера не удался. Проверьте права root (sudo)!\n");
        IedServer_destroy(g_iedServer);
        return -1;
    }

    printf("MMS Сервер готов. Порт 102. Ожидание команд из IEDScout...\n");

    int nl_fd = -1;
#ifndef _WIN32
    nl_fd = socket(AF_NETLINK, SOCK_RAW, NETLINK_ROUTE);
#endif

    while (running) {
        uint64_t timeMs = Hal_getTimeInMs();

        IedServer_lockDataModel(g_iedServer);

        // 1. Проверяем, нет ли отложенных обновлений скорости из обработчика
        if (g_pending_speed_update != -1) {
            IedServer_updateInt32AttributeValue(g_iedServer,
                IEDMODEL_Bridge_LPCP1_MauCfg_stVal, g_pending_speed_update);
            g_pending_speed_update = -1; // Сбрасываем флаг
        }

        // 2. Обновляем статус линка (UP/DOWN)
        if (nl_fd >= 0) {
            int status0 = get_hardware_port_status(0, nl_fd);
            IedServer_updateInt32AttributeValue(g_iedServer,
                IEDMODEL_Bridge_LPCP1_Mau_stVal, (int32_t)status0);
            
            // Обновляем метку времени (опционально)
            MmsValue* ts0 = MmsValue_newUtcTime(timeMs / 1000);
            IedServer_updateAttributeValue(g_iedServer, IEDMODEL_Bridge_LPCP1_Mau_t, ts0);
            MmsValue_delete(ts0);
        }

        IedServer_unlockDataModel(g_iedServer);

        Thread_sleep(100);
    }

    IedServer_stop(g_iedServer);
    IedServer_destroy(g_iedServer);
    if (nl_fd >= 0) close(nl_fd);

    printf("Сервер остановлен.\n");
    return 0;
}