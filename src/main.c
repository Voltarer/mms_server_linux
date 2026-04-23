#define _GNU_SOURCE
#include "hal_thread.h"
#include "hal_time.h"
#include "iec61850_server.h"
#include "mms_common.h"
#include "static_model.h"
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#ifndef _WIN32
    #include <sys/socket.h>
    #include <linux/rtnetlink.h>
    #include <unistd.h>
#endif

#define TOTAL_PORTS 28

extern int get_hardware_port_status(int port_idx, int nl_fd);
extern int set_hardware_port_status(int port_idx, int enable);

static int running = 1;
void sigint_handler(int signalId) { running = 0; }

DataAttribute* mauAttrs[TOTAL_PORTS];

/**
 * Обработчик записи. 
 * Сигнатура исправлена согласно результатам grep:
 * (DataAttribute*, MmsValue*, ClientConnection, void*)
 */
static MmsDataAccessError
writeAccessHandler(DataAttribute* attr, MmsValue* value, ClientConnection connection, void* parameter)
{
    for (int i = 0; i < TOTAL_PORTS; i++) {
        if (attr == mauAttrs[i]) {
            int newVal = MmsValue_toInt32(value);
            // Логика управления: 1 - включить порт, остальное (например, 5) - выключить
            printf("MMS: Получена команда для порта %d, значение: %d\n", i + 1, newVal);
            set_hardware_port_status(i, (newVal == 1));
            return DATA_ACCESS_ERROR_SUCCESS;
        }
    }
    return DATA_ACCESS_ERROR_SUCCESS; 
}

int main(int argc, char **argv) {
    signal(SIGINT, sigint_handler);

    IedServer iedServer = IedServer_create(&iedModel);

    // 1. Привязка атрибутов управления из статической модели к массиву
    mauAttrs[0] = IEDMODEL_Bridge_LPCP1_Mau_stVal;
    mauAttrs[1] = IEDMODEL_Bridge_LPCP2_Mau_stVal;
    mauAttrs[2] = IEDMODEL_Bridge_LPCP3_Mau_stVal;
    mauAttrs[3] = IEDMODEL_Bridge_LPCP4_Mau_stVal;
    mauAttrs[4] = IEDMODEL_Bridge_LPCP5_Mau_stVal;
    mauAttrs[5] = IEDMODEL_Bridge_LPCP6_Mau_stVal;
    mauAttrs[6] = IEDMODEL_Bridge_LPCP7_Mau_stVal;
    mauAttrs[7] = IEDMODEL_Bridge_LPCP8_Mau_stVal;
    mauAttrs[8] = IEDMODEL_Bridge_LPCP9_Mau_stVal;
    mauAttrs[9] = IEDMODEL_Bridge_LPCP10_Mau_stVal;
    mauAttrs[10] = IEDMODEL_Bridge_LPCP11_Mau_stVal;
    mauAttrs[11] = IEDMODEL_Bridge_LPCP12_Mau_stVal;
    mauAttrs[12] = IEDMODEL_Bridge_LPCP13_Mau_stVal;
    mauAttrs[13] = IEDMODEL_Bridge_LPCP14_Mau_stVal;
    mauAttrs[14] = IEDMODEL_Bridge_LPCP15_Mau_stVal;
    mauAttrs[15] = IEDMODEL_Bridge_LPCP16_Mau_stVal;
    mauAttrs[16] = IEDMODEL_Bridge_LPCP17_Mau_stVal;
    mauAttrs[17] = IEDMODEL_Bridge_LPCP18_Mau_stVal;
    mauAttrs[18] = IEDMODEL_Bridge_LPCP19_Mau_stVal;
    mauAttrs[19] = IEDMODEL_Bridge_LPCP20_Mau_stVal;
    mauAttrs[20] = IEDMODEL_Bridge_LPCP21_Mau_stVal;
    mauAttrs[21] = IEDMODEL_Bridge_LPCP22_Mau_stVal;
    mauAttrs[22] = IEDMODEL_Bridge_LPCP23_Mau_stVal;
    mauAttrs[23] = IEDMODEL_Bridge_LPCP24_Mau_stVal;
    mauAttrs[24] = IEDMODEL_Bridge_LPCP25_Mau_stVal;
    mauAttrs[25] = IEDMODEL_Bridge_LPCP26_Mau_stVal;
    mauAttrs[26] = IEDMODEL_Bridge_LPCP27_Mau_stVal;
    mauAttrs[27] = IEDMODEL_Bridge_LPCP28_Mau_stVal;

    // 2. Регистрация обработчика записи для каждого атрибута MAU
    // Это делается один раз при запуске
    for (int i = 0; i < TOTAL_PORTS; i++) {
        if (mauAttrs[i] != NULL) {
            IedServer_handleWriteAccess(iedServer, mauAttrs[i], writeAccessHandler, NULL);
        }
    }
    
    IedServer_start(iedServer, 102);

    if (!IedServer_isRunning(iedServer)) {
        printf("Ошибка: запуск MMS сервера не удался.\n");
        IedServer_destroy(iedServer);
        return -1;
    }

    int nl_fd = -1;
#ifndef _WIN32
    nl_fd = socket(AF_NETLINK, SOCK_RAW, NETLINK_ROUTE);
#endif

    printf("MIPS MMS Сервер запущен на порту 102. Ожидание команд...\n");

    while (running) {
        uint64_t timeMs = Hal_getTimeInMs();
        
        IedServer_lockDataModel(iedServer);
        
        /* Здесь можно добавить логику обновления Health_stVal через get_hardware_port_status */
        
        IedServer_unlockDataModel(iedServer);
        
        Thread_sleep(1000); 
    }

    IedServer_stop(iedServer);
    IedServer_destroy(iedServer);
    
#ifndef _WIN32
    if (nl_fd >= 0) close(nl_fd);
#endif

    return 0;
}