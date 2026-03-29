#include "hal_thread.h"
#include "hal_time.h"
#include "iec61850_server.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#ifdef _WIN32
    #include <winsock2.h>
    #include <windows.h>  
    #include <signal.h>
#else
    #include <signal.h>
    #include <unistd.h>
    #include <sys/socket.h>
    #include <linux/rtnetlink.h>
    #include <net/if.h>
#endif

#include "static_model.h"

#define TOTAL_PORTS 28

static int running = 1;
void sigint_handler(int signalId) { running = 0; }

#ifndef _WIN32
// Функция парсинга атрибутов из твоего примера netlink
void parseRtattr(struct rtattr *tb[], int max, struct rtattr *rta, int len) {
    memset(tb, 0, sizeof(struct rtattr *) * (max + 1));
    while (RTA_OK(rta, len)) {
        if (rta->rta_type <= max) tb[rta->rta_type] = rta;
        rta = RTA_NEXT(rta, len);
    }
}

// Получение статуса конкретного интерфейса через Netlink
int get_port_status_netlink(int nl_fd, int port_idx) {
    char buf[4096];
    struct nlmsghdr *nlh;
    struct ifinfomsg *ifi;
    int len;
    
    // Формируем запрос RTM_GETLINK для получения состояния всех линков
    struct {
        struct nlmsghdr nlh;
        struct ifinfomsg ifi;
    } req;

    memset(&req, 0, sizeof(req));
    req.nlh.nlmsg_len = NLMSG_LENGTH(sizeof(struct ifinfomsg));
    req.nlh.nlmsg_flags = NLM_F_REQUEST | NLM_F_DUMP;
    req.nlh.nlmsg_type = RTM_GETLINK;
    req.ifi.ifi_family = AF_UNSPEC;

    if (send(nl_fd, &req, req.nlh.nlmsg_len, 0) < 0) return 2;

    // Ожидаемое имя интерфейса (например, eth1, eth2...)
    char target_ifname[IFNAMSIZ];
    snprintf(target_ifname, IFNAMSIZ, "eth%d", port_idx + 1);

    while ((len = recv(nl_fd, buf, sizeof(buf), 0)) > 0) {
        for (nlh = (struct nlmsghdr *)buf; NLMSG_OK(nlh, len); nlh = NLMSG_NEXT(nlh, len)) {
            if (nlh->nlmsg_type == NLMSG_DONE) return 2; // Конец данных, порт не найден
            if (nlh->nlmsg_type == NLMSG_ERROR) return 2;

            ifi = (struct ifinfomsg *)NLMSG_DATA(nlh);
            struct rtattr *tb[IFLA_MAX + 1];
            parseRtattr(tb, IFLA_MAX, IFLA_RTA(ifi), nlh->nlmsg_len);

            if (tb[IFLA_IFNAME]) {
                char *ifname = (char *)RTA_DATA(tb[IFLA_IFNAME]);
                if (strcmp(ifname, target_ifname) == 0) {
                    // Проверяем флаг IFF_RUNNING (наличие линка)
                    return (ifi->ifi_flags & IFF_RUNNING) ? 1 : 2;
                }
            }
        }
    }
    return 2;
}
#endif

int main(int argc, char **argv) {
#ifdef _WIN32
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);
#endif

    int nl_fd = -1;
#ifndef _WIN32
    nl_fd = socket(AF_NETLINK, SOCK_RAW, NETLINK_ROUTE);
    if (nl_fd < 0) {
        printf("Error creating netlink socket: %s\n", strerror(errno));
    }
#endif

    IedServer iedServer = IedServer_create(&iedModel);
    IedServer_start(iedServer, 102);

    if (!IedServer_isRunning(iedServer)) {
        printf("Starting server failed! (Port 102)\n");
        IedServer_destroy(iedServer);
        if (nl_fd >= 0) close(nl_fd);
        exit(-1);
    }

    signal(SIGINT, sigint_handler);

    // Массивы указателей на атрибуты модели (Health)
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

    printf("MMS Server (Netlink version) is running...\n");

    while (running) {
        uint64_t timeMs = Hal_getTimeInMs();
        Timestamp ts;
        Timestamp_clearFlags(&ts);
        Timestamp_setTimeInMilliseconds(&ts, timeMs);

        IedServer_lockDataModel(iedServer);

        for (int i = 0; i < TOTAL_PORTS; i++) {
            if (stValAttrs[i] == NULL) continue;

            int healthStatus = 1; // По умолчанию Ok
#ifndef _WIN32
            if (nl_fd >= 0) {
                healthStatus = get_port_status_netlink(nl_fd, i);
            }
#endif
            IedServer_updateInt32AttributeValue(iedServer, stValAttrs[i], (int32_t)healthStatus);
            IedServer_updateQuality(iedServer, qAttrs[i], QUALITY_VALIDITY_GOOD);
            IedServer_updateTimestampAttributeValue(iedServer, tAttrs[i], &ts);
        }

        IedServer_unlockDataModel(iedServer);
        Thread_sleep(500);
    }

    IedServer_stop(iedServer);
    IedServer_destroy(iedServer);
    if (nl_fd >= 0) close(nl_fd);

#ifdef _WIN32
    WSACleanup();
#endif
    return 0;
}