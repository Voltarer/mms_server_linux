#include "iec61850_server.h"
#include "hal_thread.h"
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

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

    printf("MMS Server (Realtek Integrated) is running...\n");

    while (running) {
        /* Переменные для хранения данных от SDK */
        rtk_port_linkStatus_t link_status;
        rtk_port_media_t port_media;

        IedServer_lockDataModel(iedServer);

        /* Опрашиваем порты с 1 по 4 */
        for (int port = 1; port <= 4; port++) {
            /* Вызываем функцию SDK (unit 0, порт i) */
            if (rtrpc_port_linkMedia_get(0, port, &link_status, &port_media) == 0) {
                
                /* PORT_LINKUP определяется библиотекой rtrpc_port.h */
                bool isUp = (link_status == PORT_LINKUP);
                
                /* Обновляем значения в модели МЭК 61850 */
                /* Мы используем GGIO1.Ind1 для 1 порта, Ind2 для 2-го и т.д. */
                if (port == 1) IedServer_updateBooleanAttributeValue(iedServer, IED_MODEL_GenericIO_GGIO1_Ind1_stVal, isUp);
                if (port == 2) IedServer_updateBooleanAttributeValue(iedServer, IED_MODEL_GenericIO_GGIO1_Ind2_stVal, isUp);
                if (port == 3) IedServer_updateBooleanAttributeValue(iedServer, IED_MODEL_GenericIO_GGIO1_Ind3_stVal, isUp);
                if (port == 4) IedServer_updateBooleanAttributeValue(iedServer, IED_MODEL_GenericIO_GGIO1_Ind4_stVal, isUp);

                if (isUp) {
                    printf("Port %d: LINK UP (Media: %d)\n", port, port_media);
                }
            } else {
                /* Если SDK вернул ошибку, выводим в консоль для отладки */
                printf("Error: Failed to get status for Port %d\n", port);
            }
        }

        IedServer_unlockDataModel(iedServer);

        Thread_sleep(1000); // Опрос раз в секунду
    }

    IedServer_stop(iedServer);
    IedServer_destroy(iedServer);

    return 0;
}