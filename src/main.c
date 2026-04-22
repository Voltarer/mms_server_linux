#define _GNU_SOURCE
#include "hal_thread.h"
#include "hal_time.h"
#include "iec61850_server.h"
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

static int running = 1;
void sigint_handler(int signalId) { running = 0; }

int main(int argc, char **argv) {
    signal(SIGINT, sigint_handler);

    IedServer iedServer = IedServer_create(&iedModel);
    IedServer_start(iedServer, 102);

    if (!IedServer_isRunning(iedServer)) {
        printf("Ошибка: не удалось запустить MMS сервер.\n");
        IedServer_destroy(iedServer);
        return -1;
    }

    // Массив атрибутов значений (stVal)
    DataAttribute* stValAttrs[TOTAL_PORTS] = {
        IEDMODEL_Bridge_LPCP1_Health_stVal,  IEDMODEL_Bridge_LPCP2_Health_stVal,
        IEDMODEL_Bridge_LPCP3_Health_stVal,  IEDMODEL_Bridge_LPCP4_Health_stVal,
        IEDMODEL_Bridge_LPCP5_Health_stVal,  IEDMODEL_Bridge_LPCP6_Health_stVal,
        IEDMODEL_Bridge_LPCP7_Health_stVal,  IEDMODEL_Bridge_LPCP8_Health_stVal,
        IEDMODEL_Bridge_LPCP9_Health_stVal,  IEDMODEL_Bridge_LPCP10_Health_stVal,
        IEDMODEL_Bridge_LPCP11_Health_stVal, IEDMODEL_Bridge_LPCP12_Health_stVal,
        IEDMODEL_Bridge_LPCP13_Health_stVal, IEDMODEL_Bridge_LPCP14_Health_stVal,
        IEDMODEL_Bridge_LPCP15_Health_stVal, IEDMODEL_Bridge_LPCP16_Health_stVal,
        IEDMODEL_Bridge_LPCP17_Health_stVal, IEDMODEL_Bridge_LPCP18_Health_stVal,
        IEDMODEL_Bridge_LPCP19_Health_stVal, IEDMODEL_Bridge_LPCP20_Health_stVal,
        IEDMODEL_Bridge_LPCP21_Health_stVal, IEDMODEL_Bridge_LPCP22_Health_stVal,
        IEDMODEL_Bridge_LPCP23_Health_stVal, IEDMODEL_Bridge_LPCP24_Health_stVal,
        IEDMODEL_Bridge_LPCP25_Health_stVal, IEDMODEL_Bridge_LPCP26_Health_stVal,
        IEDMODEL_Bridge_LPCP27_Health_stVal, IEDMODEL_Bridge_LPCP28_Health_stVal
    };

    // Массив атрибутов времени (t)
    DataAttribute* tAttrs[TOTAL_PORTS] = {
        IEDMODEL_Bridge_LPCP1_Health_t,  IEDMODEL_Bridge_LPCP2_Health_t,
        IEDMODEL_Bridge_LPCP3_Health_t,  IEDMODEL_Bridge_LPCP4_Health_t,
        IEDMODEL_Bridge_LPCP5_Health_t,  IEDMODEL_Bridge_LPCP6_Health_t,
        IEDMODEL_Bridge_LPCP7_Health_t,  IEDMODEL_Bridge_LPCP8_Health_t,
        IEDMODEL_Bridge_LPCP9_Health_t,  IEDMODEL_Bridge_LPCP10_Health_t,
        IEDMODEL_Bridge_LPCP11_Health_t, IEDMODEL_Bridge_LPCP12_Health_t,
        IEDMODEL_Bridge_LPCP13_Health_t, IEDMODEL_Bridge_LPCP14_Health_t,
        IEDMODEL_Bridge_LPCP15_Health_t, IEDMODEL_Bridge_LPCP16_Health_t,
        IEDMODEL_Bridge_LPCP17_Health_t, IEDMODEL_Bridge_LPCP18_Health_t,
        IEDMODEL_Bridge_LPCP19_Health_t, IEDMODEL_Bridge_LPCP20_Health_t,
        IEDMODEL_Bridge_LPCP21_Health_t, IEDMODEL_Bridge_LPCP22_Health_t,
        IEDMODEL_Bridge_LPCP23_Health_t, IEDMODEL_Bridge_LPCP24_Health_t,
        IEDMODEL_Bridge_LPCP25_Health_t, IEDMODEL_Bridge_LPCP26_Health_t,
        IEDMODEL_Bridge_LPCP27_Health_t, IEDMODEL_Bridge_LPCP28_Health_t
    };

    int nl_fd = -1;
#ifndef _WIN32
    nl_fd = socket(AF_NETLINK, SOCK_RAW, NETLINK_ROUTE);
#endif

    printf("Сервер запущен. Мониторинг %d портов...\n", TOTAL_PORTS);

    while (running) {
        uint64_t timeMs = Hal_getTimeInMs();
        
        IedServer_lockDataModel(iedServer);
        for (int i = 0; i < TOTAL_PORTS; i++) {
            if (stValAttrs[i] && tAttrs[i]) {
                int status = get_hardware_port_status(i, nl_fd);
                IedServer_updateInt32AttributeValue(iedServer, stValAttrs[i], status);

                MmsValue* utcTime = MmsValue_newUtcTime(timeMs / 1000); // секунды
                MmsValue_setUtcTimeMs(utcTime, timeMs); 
                
                IedServer_updateAttributeValue(iedServer, tAttrs[i], utcTime);
                
                MmsValue_delete(utcTime);
            }
        }
        IedServer_unlockDataModel(iedServer);

        Thread_sleep(1000); 
    }

    IedServer_stop(iedServer);
    IedServer_destroy(iedServer);
    if (nl_fd >= 0) close(nl_fd);
    return 0;
}