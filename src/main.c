#include "hal_thread.h"
#include "hal_time.h"
#include "iec61850_server.h"
#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
    #include <winsock2.h>
    #include <windows.h>  
    #include <signal.h>
#else
    #include <signal.h>
    #include <unistd.h>
#endif

#ifdef TARGET_MIPS
    #include "dal/rtrpc/rtrpc_port.h"
#endif

#include "static_model.h"

#define TOTAL_PORTS 28

static int running = 1;
void sigint_handler(int signalId) { running = 0; }

int main(int argc, char **argv) {

#ifdef _WIN32
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);
#endif

    IedServer iedServer = IedServer_create(&iedModel);

    IedServer_start(iedServer, 102);

    if (!IedServer_isRunning(iedServer)) {
        printf("Starting server failed! (Check if port 102 is free and you have Admin rights)\n");
        IedServer_destroy(iedServer);
        exit(-1);
    }

    signal(SIGINT, sigint_handler);

    // Массивы для хранения указателей на атрибуты модели (Health)
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

    DataAttribute* qAttrs[TOTAL_PORTS] = {
        IEDMODEL_Bridge_LPCP1_Health_q,  IEDMODEL_Bridge_LPCP2_Health_q,
        IEDMODEL_Bridge_LPCP3_Health_q,  IEDMODEL_Bridge_LPCP4_Health_q,
        IEDMODEL_Bridge_LPCP5_Health_q,  IEDMODEL_Bridge_LPCP6_Health_q,
        IEDMODEL_Bridge_LPCP7_Health_q,  IEDMODEL_Bridge_LPCP8_Health_q,
        IEDMODEL_Bridge_LPCP9_Health_q,  IEDMODEL_Bridge_LPCP10_Health_q,
        IEDMODEL_Bridge_LPCP11_Health_q, IEDMODEL_Bridge_LPCP12_Health_q,
        IEDMODEL_Bridge_LPCP13_Health_q, IEDMODEL_Bridge_LPCP14_Health_q,
        IEDMODEL_Bridge_LPCP15_Health_q, IEDMODEL_Bridge_LPCP16_Health_q,
        IEDMODEL_Bridge_LPCP17_Health_q, IEDMODEL_Bridge_LPCP18_Health_q,
        IEDMODEL_Bridge_LPCP19_Health_q, IEDMODEL_Bridge_LPCP20_Health_q,
        IEDMODEL_Bridge_LPCP21_Health_q, IEDMODEL_Bridge_LPCP22_Health_q,
        IEDMODEL_Bridge_LPCP23_Health_q, IEDMODEL_Bridge_LPCP24_Health_q,
        IEDMODEL_Bridge_LPCP25_Health_q, IEDMODEL_Bridge_LPCP26_Health_q,
        IEDMODEL_Bridge_LPCP27_Health_q, IEDMODEL_Bridge_LPCP28_Health_q
    };

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

    printf("MMS Server is running...\n");

    while (running) {
        uint64_t timeMs = Hal_getTimeInMs();

        IedServer_lockDataModel(iedServer);

        for (int i = 0; i < TOTAL_PORTS; i++) {
            if (stValAttrs[i] == NULL) continue;

            int portNum = i + 1;
            int healthStatus = 1; // Ok

#ifdef TARGET_MIPS
            rtk_port_linkStatus_t link_status;
            rtk_port_media_t port_media;
            // Получаем статус из Realtek SDK
            if (rtrpc_port_linkMedia_get(0, portNum, &link_status, &port_media) == 0) {
                if (link_status == PORT_LINKDOWN) {
                    healthStatus = 2; // Warning
                }
            }
#endif
            IedServer_updateInt32AttributeValue(iedServer, stValAttrs[i], healthStatus);
            IedServer_updateQuality(iedServer, qAttrs[i], QUALITY_VALIDITY_GOOD);
            IedServer_updateTimestampAttributeValue(iedServer, tAttrs[i], timeMs);
        }

        IedServer_unlockDataModel(iedServer);
        Thread_sleep(500);
    }

    IedServer_stop(iedServer);
    IedServer_destroy(iedServer);

#ifdef _WIN32
    WSACleanup();
#endif

    return 0;
}