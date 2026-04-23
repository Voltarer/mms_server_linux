#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifdef _WIN32
    #include <windows.h>
#else
    #include <sys/socket.h>
    #include <sys/ioctl.h>
    #include <linux/rtnetlink.h>
    #include <net/if.h>
    #include <unistd.h>
    
    #ifndef IFF_RUNNING
        #define IFF_RUNNING 0x40
    #endif
#endif

/**
 * Получение статуса линка через Netlink
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
            
            char expected_name[16];
            snprintf(expected_name, sizeof(expected_name), "eth%d", port_idx);
            
            if (strcmp(ifname, expected_name) == 0) {
                return (ifi->ifi_flags & IFF_RUNNING) ? 1 : 2;
            }
        }
        nh = NLMSG_NEXT(nh, len);
    }
    return 1;
#else
    return 1;
#endif
}

/**
 * Управление интерфейсом (Up/Down) через ioctl
 */
int set_hardware_port_status(int port_idx, int enable) {
#ifndef _WIN32
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) return -1;

    struct ifreq ifr;
    snprintf(ifr.ifr_name, IFNAMSIZ, "eth%d", port_idx);

    if (ioctl(sockfd, SIOCGIFFLAGS, &ifr) < 0) {
        close(sockfd);
        return -1;
    }

    if (enable) ifr.ifr_flags |= (IFF_UP);
    else ifr.ifr_flags &= ~(IFF_UP);

    if (ioctl(sockfd, SIOCSIFFLAGS, &ifr) < 0) {
        close(sockfd);
        return -1;
    }

    close(sockfd);
    printf("Интерфейс eth%d переведен в %s\n", port_idx, enable ? "UP" : "DOWN");
    return 0;
#else
    return 0;
#endif
}