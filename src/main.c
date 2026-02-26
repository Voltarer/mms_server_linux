#include "iec61850_server.h"
#include "hal_thread.h"
#include "hal_time.h"
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

#include "dal/rtrpc/rtrpc_port.h"
#include "static_model.h"

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

    DataAttribute* stValAttrs[] = {
        IEDMODEL_LD0_LPCP1_PhyHealth_stVal, IEDMODEL_LD0_LPCP2_PhyHealth_stVal,
        IEDMODEL_LD0_LPCP3_PhyHealth_stVal, IEDMODEL_LD0_LPCP4_PhyHealth_stVal,
        IEDMODEL_LD0_LPCP5_PhyHealth_stVal, IEDMODEL_LD0_LPCP6_PhyHealth_stVal
    };

    DataAttribute* qAttrs[] = {
        IEDMODEL_LD0_LPCP1_PhyHealth_q, IEDMODEL_LD0_LPCP2_PhyHealth_q,
        IEDMODEL_LD0_LPCP3_PhyHealth_q, IEDMODEL_LD0_LPCP4_PhyHealth_q,
        IEDMODEL_LD0_LPCP5_PhyHealth_q, IEDMODEL_LD0_LPCP6_PhyHealth_q
    };

    DataAttribute* tAttrs[] = {
        IEDMODEL_LD0_LPCP1_PhyHealth_t, IEDMODEL_LD0_LPCP2_PhyHealth_t,
        IEDMODEL_LD0_LPCP3_PhyHealth_t, IEDMODEL_LD0_LPCP4_PhyHealth_t,
        IEDMODEL_LD0_LPCP5_PhyHealth_t, IEDMODEL_LD0_LPCP6_PhyHealth_t
    };

    while (running) {
        rtk_port_linkStatus_t link_status;
        rtk_port_media_t port_media;
        
        uint64_t timeMs = Hal_getTimeInMs();
        Timestamp ts;
        Timestamp_setTimeInMilliseconds(&ts, timeMs);

        IedServer_lockDataModel(iedServer);

        for (int i = 0; i < 6; i++) {
            int portNum = i + 1; 
            Quality quality = QUALITY_VALIDITY_GOOD;
            
            int result = rtrpc_port_linkMedia_get(0, portNum, &link_status, &port_media);
            
            if (result != 0) {
                quality = QUALITY_VALIDITY_INVALID;
            }

            int healthStatus = (link_status == PORT_LINKUP) ? 1 : 3;
            
            /* Обновление атрибутов в памяти сервера */
            IedServer_updateInt32AttributeValue(iedServer, stValAttrs[i], healthStatus);
            IedServer_updateQuality(iedServer, qAttrs[i], quality);
            IedServer_updateTimestampAttributeValue(iedServer, tAttrs[i], &ts);
        }

        IedServer_unlockDataModel(iedServer);

        Thread_sleep(1000);
    }

    IedServer_stop(iedServer);
    IedServer_destroy(iedServer);
    
    return 0;
}