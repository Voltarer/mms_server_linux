#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifdef _WIN32
    #include <windows.h>
#else
    #include <sys/socket.h>
    #include <linux/rtnetlink.h>
    #include <net/if.h>
    #include <unistd.h>
    // Флаг наличия физического линка
    #ifndef IFF_RUNNING
        #define IFF_RUNNING 0x40
    #endif
#endif

/**
 * Получение статуса порта через rtnetlink
 * @param port_idx Индекс порта (0, 1, 2...)
 * @param nl_fd Открытый сокет Netlink
 * @return 1 - Link Up (OK), 2 - Link Down (Warning)
 */
int get_hardware_port_status(int port_idx, int nl_fd) {
#ifndef _WIN32
    if (nl_fd < 0) return 1;

    struct {
        struct nlmsghdr nlh;
        struct ifinfomsg ifi;
    } req = {
        .nlh.nlmsg_len = NLMSG_LENGTH(sizeof(struct ifinfomsg)),
        .nlh.nlmsg_type = RTM_GETLINK,
        .nlh.nlmsg_flags = NLM_F_REQUEST | NLM_F_DUMP,
        .ifi.ifi_family = AF_UNSPEC,
    };

    if (send(nl_fd, &req, req.nlh.nlmsg_len, 0) < 0) return 1;

    char buf[8192];
    int len = recv(nl_fd, buf, sizeof(buf), 0);
    if (len <= 0) return 1;

    struct nlmsghdr *nh = (struct nlmsghdr *)buf;
    while (NLMSG_OK(nh, len)) {
        if (nh->nlmsg_type == RTM_NEWLINK) {
            struct ifinfomsg *ifi = NLMSG_DATA(nh);
            char ifname[IF_NAMESIZE];
            if_indextoname(ifi->ifi_index, ifname);
            
            // Сопоставление: индекс 0 -> eth0, индекс 1 -> eth1 и т.д.
            char expected_name[16];
            snprintf(expected_name, sizeof(expected_name), "eth%d", port_idx);
            
            if (strcmp(ifname, expected_name) == 0) {
                return (ifi->ifi_flags & IFF_RUNNING) ? 1 : 2;
            }
        }
        nh = NLMSG_NEXT(nh, len);
    }
    return 1; // По умолчанию считаем, что все ок
#else
    // Заглушка для Windows
    return 1;
#endif
}