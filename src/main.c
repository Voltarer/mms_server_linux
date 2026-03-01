#include "iec61850_server.h"
#include "hal_thread.h"
#include "hal_time.h"
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

/* Подключение Realtek SDK */
#include "dal/rtrpc/rtrpc_port.h"

/* Подключение сгенерированной модели данных */
#include "static_model.h"

#define TOTAL_PORTS 28

static int running = 1;

void sigint_handler(int signalId) {
    running = 0;
}

int main(int argc, char** argv) {

    IedServer iedServer = IedServer_create(&iedModel);

    IedServer_start(iedServer, 102);

    if (!IedServer_isRunning(iedServer)) {
        printf("Starting server failed! Exit.\n");
        IedServer_destroy(iedServer);
        exit(-1);
    }
    signal(SIGINT, sigint_handler);
    
    printf("MMS Server (Realtek MIPS) is running...\n");

    DataAttribute* stValAttrs[TOTAL_PORTS] = {
        IEDMODEL_LD0_LPCP1_PhyHealth_stVal,  IEDMODEL_LD0_LPCP2_PhyHealth_stVal,
        IEDMODEL_LD0_LPCP3_PhyHealth_stVal,  IEDMODEL_LD0_LPCP4_PhyHealth_stVal,
        IEDMODEL_LD0_LPCP5_PhyHealth_stVal,  IEDMODEL_LD0_LPCP6_PhyHealth_stVal,
        IEDMODEL_LD0_LPCP7_PhyHealth_stVal,  IEDMODEL_LD0_LPCP8_PhyHealth_stVal,
        IEDMODEL_LD0_LPCP9_PhyHealth_stVal,  IEDMODEL_LD0_LPCP10_PhyHealth_stVal,
        IEDMODEL_LD0_LPCP11_PhyHealth_stVal, IEDMODEL_LD0_LPCP12_PhyHealth_stVal,
        IEDMODEL_LD0_LPCP13_PhyHealth_stVal, IEDMODEL_LD0_LPCP14_PhyHealth_stVal,
        IEDMODEL_LD0_LPCP15_PhyHealth_stVal, IEDMODEL_LD0_LPCP16_PhyHealth_stVal,
        IEDMODEL_LD0_LPCP17_PhyHealth_stVal, IEDMODEL_LD0_LPCP18_PhyHealth_stVal,
        IEDMODEL_LD0_LPCP19_PhyHealth_stVal, IEDMODEL_LD0_LPCP20_PhyHealth_stVal,
        IEDMODEL_LD0_LPCP21_PhyHealth_stVal, IEDMODEL_LD0_LPCP22_PhyHealth_stVal,
        IEDMODEL_LD0_LPCP23_PhyHealth_stVal, IEDMODEL_LD0_LPCP24_PhyHealth_stVal,
        IEDMODEL_LD0_LPCP25_PhyHealth_stVal, IEDMODEL_LD0_LPCP26_PhyHealth_stVal,
        IEDMODEL_LD0_LPCP27_PhyHealth_stVal, IEDMODEL_LD0_LPCP28_PhyHealth_stVal
    };

    DataAttribute* qAttrs[TOTAL_PORTS] = {
        IEDMODEL_LD0_LPCP1_PhyHealth_q,  IEDMODEL_LD0_LPCP2_PhyHealth_q,
        IEDMODEL_LD0_LPCP3_PhyHealth_q,  IEDMODEL_LD0_LPCP4_PhyHealth_q,
        IEDMODEL_LD0_LPCP5_PhyHealth_q,  IEDMODEL_LD0_LPCP6_PhyHealth_q,
        IEDMODEL_LD0_LPCP7_PhyHealth_q,  IEDMODEL_LD0_LPCP8_PhyHealth_q,
        IEDMODEL_LD0_LPCP9_PhyHealth_q,  IEDMODEL_LD0_LPCP10_PhyHealth_q,
        IEDMODEL_LD0_LPCP11_PhyHealth_q, IEDMODEL_LD0_LPCP12_PhyHealth_q,
        IEDMODEL_LD0_LPCP13_PhyHealth_q, IEDMODEL_LD0_LPCP14_PhyHealth_q,
        IEDMODEL_LD0_LPCP15_PhyHealth_q, IEDMODEL_LD0_LPCP16_PhyHealth_q,
        IEDMODEL_LD0_LPCP17_PhyHealth_q, IEDMODEL_LD0_LPCP18_PhyHealth_q,
        IEDMODEL_LD0_LPCP19_PhyHealth_q, IEDMODEL_LD0_LPCP20_PhyHealth_q,
        IEDMODEL_LD0_LPCP21_PhyHealth_q, IEDMODEL_LD0_LPCP22_PhyHealth_q,
        IEDMODEL_LD0_LPCP23_PhyHealth_q, IEDMODEL_LD0_LPCP24_PhyHealth_q,
        IEDMODEL_LD0_LPCP25_PhyHealth_q, IEDMODEL_LD0_LPCP26_PhyHealth_q,
        IEDMODEL_LD0_LPCP27_PhyHealth_q, IEDMODEL_LD0_LPCP28_PhyHealth_q
    };

    DataAttribute* tAttrs[TOTAL_PORTS] = {
        IEDMODEL_LD0_LPCP1_PhyHealth_t,  IEDMODEL_LD0_LPCP2_PhyHealth_t,
        IEDMODEL_LD0_LPCP3_PhyHealth_t,  IEDMODEL_LD0_LPCP4_PhyHealth_t,
        IEDMODEL_LD0_LPCP5_PhyHealth_t,  IEDMODEL_LD0_LPCP6_PhyHealth_t,
        IEDMODEL_LD0_LPCP7_PhyHealth_t,  IEDMODEL_LD0_LPCP8_PhyHealth_t,
        IEDMODEL_LD0_LPCP9_PhyHealth_t,  IEDMODEL_LD0_LPCP10_PhyHealth_t,
        IEDMODEL_LD0_LPCP11_PhyHealth_t, IEDMODEL_LD0_LPCP12_PhyHealth_t,
        IEDMODEL_LD0_LPCP13_PhyHealth_t, IEDMODEL_LD0_LPCP14_PhyHealth_t,
        IEDMODEL_LD0_LPCP15_PhyHealth_t, IEDMODEL_LD0_LPCP16_PhyHealth_t,
        IEDMODEL_LD0_LPCP17_PhyHealth_t, IEDMODEL_LD0_LPCP18_PhyHealth_t,
        IEDMODEL_LD0_LPCP19_PhyHealth_t, IEDMODEL_LD0_LPCP20_PhyHealth_t,
        IEDMODEL_LD0_LPCP21_PhyHealth_t, IEDMODEL_LD0_LPCP22_PhyHealth_t,
        IEDMODEL_LD0_LPCP23_PhyHealth_t, IEDMODEL_LD0_LPCP24_PhyHealth_t,
        IEDMODEL_LD0_LPCP25_PhyHealth_t, IEDMODEL_LD0_LPCP26_PhyHealth_t,
        IEDMODEL_LD0_LPCP27_PhyHealth_t, IEDMODEL_LD0_LPCP28_PhyHealth_t
    };

    while (running) {
        rtk_port_linkStatus_t link_status;
        rtk_port_media_t port_media;
        uint64_t timeMs = Hal_getTimeInMs();
        Timestamp ts;
        Timestamp_setTimeInMilliseconds(&ts, timeMs);
        IedServer_lockDataModel(iedServer);

        for (int i = 0; i < TOTAL_PORTS; i++) {
            int portNum = i + 1; 
            Quality quality = QUALITY_VALIDITY_GOOD;
            
            int result = rtrpc_port_linkMedia_get(0, portNum, &link_status, &port_media);
            
            if (result != 0) {
                quality = QUALITY_VALIDITY_INVALID;
            }

            /* 1 = Ok (Link UP), 3 = Alarm (Link DOWN) */
            int healthStatus = (link_status == PORT_LINKUP) ? 1 : 3;
            
            IedServer_updateInt32AttributeValue(iedServer, stValAttrs[i], healthStatus);
            IedServer_updateQuality(iedServer, qAttrs[i], quality);
            IedServer_updateTimestampAttributeValue(iedServer, tAttrs[i], &ts);
        }

        IedServer_unlockDataModel(iedServer);
        Thread_sleep(1000);
    }

    IedServer_stop(iedServer);
    IedServer_destroy(iedServer);

    printf("Server stopped.\n");
    return 0;
}