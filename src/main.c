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
    printf("Starting server failed! (Check if port 102 is free and you have "
           "Admin rights)\\n");
    IedServer_destroy(iedServer);
    exit(-1);
  }

  signal(SIGINT, sigint_handler);

  DataAttribute *stValAttrs[TOTAL_PORTS] = {
      IEDMODEL_Bridge_LPCP1_PhyHealth_stVal,  IEDMODEL_Bridge_LPCP2_PhyHealth_stVal,
      IEDMODEL_Bridge_LPCP3_PhyHealth_stVal,  IEDMODEL_Bridge_LPCP4_PhyHealth_stVal,
      IEDMODEL_Bridge_LPCP5_PhyHealth_stVal,  IEDMODEL_Bridge_LPCP6_PhyHealth_stVal,
      IEDMODEL_Bridge_LPCP7_PhyHealth_stVal,  IEDMODEL_Bridge_LPCP8_PhyHealth_stVal,
      IEDMODEL_Bridge_LPCP9_PhyHealth_stVal,  IEDMODEL_Bridge_LPCP10_PhyHealth_stVal,
      IEDMODEL_Bridge_LPCP11_PhyHealth_stVal, IEDMODEL_Bridge_LPCP12_PhyHealth_stVal,
      IEDMODEL_Bridge_LPCP13_PhyHealth_stVal, IEDMODEL_Bridge_LPCP14_PhyHealth_stVal,
      IEDMODEL_Bridge_LPCP15_PhyHealth_stVal, IEDMODEL_Bridge_LPCP16_PhyHealth_stVal,
      IEDMODEL_Bridge_LPCP17_PhyHealth_stVal, IEDMODEL_Bridge_LPCP18_PhyHealth_stVal,
      IEDMODEL_Bridge_LPCP19_PhyHealth_stVal, IEDMODEL_Bridge_LPCP20_PhyHealth_stVal,
      IEDMODEL_Bridge_LPCP21_PhyHealth_stVal, IEDMODEL_Bridge_LPCP22_PhyHealth_stVal,
      IEDMODEL_Bridge_LPCP23_PhyHealth_stVal, IEDMODEL_Bridge_LPCP24_PhyHealth_stVal,
      IEDMODEL_Bridge_LPCP25_PhyHealth_stVal, IEDMODEL_Bridge_LPCP26_PhyHealth_stVal,
      IEDMODEL_Bridge_LPCP27_PhyHealth_stVal, IEDMODEL_Bridge_LPCP28_PhyHealth_stVal};

  DataAttribute *qAttrs[TOTAL_PORTS] = {
      IEDMODEL_Bridge_LPCP1_PhyHealth_q,  IEDMODEL_Bridge_LPCP2_PhyHealth_q,
      IEDMODEL_Bridge_LPCP3_PhyHealth_q,  IEDMODEL_Bridge_LPCP4_PhyHealth_q,
      IEDMODEL_Bridge_LPCP5_PhyHealth_q,  IEDMODEL_Bridge_LPCP6_PhyHealth_q,
      IEDMODEL_Bridge_LPCP7_PhyHealth_q,  IEDMODEL_Bridge_LPCP8_PhyHealth_q,
      IEDMODEL_Bridge_LPCP9_PhyHealth_q,  IEDMODEL_Bridge_LPCP10_PhyHealth_q,
      IEDMODEL_Bridge_LPCP11_PhyHealth_q, IEDMODEL_Bridge_LPCP12_PhyHealth_q,
      IEDMODEL_Bridge_LPCP13_PhyHealth_q, IEDMODEL_Bridge_LPCP14_PhyHealth_q,
      IEDMODEL_Bridge_LPCP15_PhyHealth_q, IEDMODEL_Bridge_LPCP16_PhyHealth_q,
      IEDMODEL_Bridge_LPCP17_PhyHealth_q, IEDMODEL_Bridge_LPCP18_PhyHealth_q,
      IEDMODEL_Bridge_LPCP19_PhyHealth_q, IEDMODEL_Bridge_LPCP20_PhyHealth_q,
      IEDMODEL_Bridge_LPCP21_PhyHealth_q, IEDMODEL_Bridge_LPCP22_PhyHealth_q,
      IEDMODEL_Bridge_LPCP23_PhyHealth_q, IEDMODEL_Bridge_LPCP24_PhyHealth_q,
      IEDMODEL_Bridge_LPCP25_PhyHealth_q, IEDMODEL_Bridge_LPCP26_PhyHealth_q,
      IEDMODEL_Bridge_LPCP27_PhyHealth_q, IEDMODEL_Bridge_LPCP28_PhyHealth_q};

  DataAttribute *tAttrs[TOTAL_PORTS] = {
      IEDMODEL_Bridge_LPCP1_PhyHealth_t,  IEDMODEL_Bridge_LPCP2_PhyHealth_t,
      IEDMODEL_Bridge_LPCP3_PhyHealth_t,  IEDMODEL_Bridge_LPCP4_PhyHealth_t,
      IEDMODEL_Bridge_LPCP5_PhyHealth_t,  IEDMODEL_Bridge_LPCP6_PhyHealth_t,
      IEDMODEL_Bridge_LPCP7_PhyHealth_t,  IEDMODEL_Bridge_LPCP8_PhyHealth_t,
      IEDMODEL_Bridge_LPCP9_PhyHealth_t,  IEDMODEL_Bridge_LPCP10_PhyHealth_t,
      IEDMODEL_Bridge_LPCP11_PhyHealth_t, IEDMODEL_Bridge_LPCP12_PhyHealth_t,
      IEDMODEL_Bridge_LPCP13_PhyHealth_t, IEDMODEL_Bridge_LPCP14_PhyHealth_t,
      IEDMODEL_Bridge_LPCP15_PhyHealth_t, IEDMODEL_Bridge_LPCP16_PhyHealth_t,
      IEDMODEL_Bridge_LPCP17_PhyHealth_t, IEDMODEL_Bridge_LPCP18_PhyHealth_t,
      IEDMODEL_Bridge_LPCP19_PhyHealth_t, IEDMODEL_Bridge_LPCP20_PhyHealth_t,
      IEDMODEL_Bridge_LPCP21_PhyHealth_t, IEDMODEL_Bridge_LPCP22_PhyHealth_t,
      IEDMODEL_Bridge_LPCP23_PhyHealth_t, IEDMODEL_Bridge_LPCP24_PhyHealth_t,
      IEDMODEL_Bridge_LPCP25_PhyHealth_t, IEDMODEL_Bridge_LPCP26_PhyHealth_t,
      IEDMODEL_Bridge_LPCP27_PhyHealth_t, IEDMODEL_Bridge_LPCP28_PhyHealth_t};

  printf("MMS Server is running...\\n");

  while (running) {
    uint64_t timeMs = Hal_getTimeInMs();

    IedServer_lockDataModel(iedServer);

    for (int i = 0; i < TOTAL_PORTS; i++) {
      int portNum = i + 1;
      int healthStatus = 1; // По умолчанию OK

#ifdef TARGET_MIPS
      rtk_port_linkStatus_t link_status;
      rtk_port_media_t port_media;
      int result =
          rtrpc_port_linkMedia_get(0, portNum, &link_status, &port_media);
      healthStatus = (link_status == PORT_LINKUP) ? 1 : 3;
#else
      /* Логика для симуляции (Windows/Ubuntu) */
      healthStatus = (portNum % 5 == 0) ? 3 : 1; // Каждый 5-й порт "в аларме"
#endif

      IedServer_updateInt32AttributeValue(iedServer, stValAttrs[i],
                                          healthStatus);
    }

    IedServer_unlockDataModel(iedServer);
    Thread_sleep(100);
  }

  IedServer_stop(iedServer);
  IedServer_destroy(iedServer);

#ifdef _WIN32
  WSACleanup();
#endif

  printf("Server stopped.\\n");
  return 0;
}