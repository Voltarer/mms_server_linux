#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <linux/sockios.h>
#include <net/if.h>
#include <errno.h>

#include "status.h"
#include "common.h"
#include "include/error.h"

int get_hardware_port_status(int port_idx) {
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        LOG_ERROR_PORT_DETAILED(port_idx, "socket");
        return -1;
    }

    struct ifreq ifr;
    get_hardware_ifname(port_idx, ifr.ifr_name, IFNAMSIZ);

    if (ioctl(sockfd, SIOCGIFFLAGS, &ifr) < 0) {
        LOG_ERROR_PORT_DETAILED(port_idx, "ioctl(SIOCGIFFLAGS)");
        close(sockfd);
        return -1;
    }
    close(sockfd);
    
    return (ifr.ifr_flags & IFF_RUNNING) ? 1 : 2;
}

int get_hardware_admin_status(int port_idx) {
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        LOG_ERROR_PORT_DETAILED(port_idx, "socket");
        return -1;
    }

    struct ifreq ifr;
    get_hardware_ifname(port_idx, ifr.ifr_name, IFNAMSIZ);

    if (ioctl(sockfd, SIOCGIFFLAGS, &ifr) < 0) {
        LOG_ERROR_PORT_DETAILED(port_idx, "ioctl(SIOCGIFFLAGS)");
        close(sockfd);
        return -1;
    }
    close(sockfd);
    
    return (ifr.ifr_flags & IFF_UP) ? 1 : 0;
}

int set_hardware_port_status(int port_idx, int enable) {
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        LOG_ERROR_PORT_DETAILED(port_idx, "socket");
        return -1;
    }

    struct ifreq ifr;
    get_hardware_ifname(port_idx, ifr.ifr_name, IFNAMSIZ);

    if (ioctl(sockfd, SIOCGIFFLAGS, &ifr) < 0) {
        LOG_ERROR_PORT_DETAILED(port_idx, "ioctl(SIOCGIFFLAGS)");
        close(sockfd);
        return -1;
    }

    if (enable) ifr.ifr_flags |= IFF_UP;
    else ifr.ifr_flags &= ~IFF_UP;

    if (ioctl(sockfd, SIOCSIFFLAGS, &ifr) < 0) {
        LOG_ERROR_PORT_DETAILED(port_idx, "ioctl(SIOCSIFFLAGS)");
        close(sockfd);
        return -1;
    }

    close(sockfd);
    printf("Hardware: Интерфейс %s переведен в %s\n", ifr.ifr_name, enable ? "UP" : "DOWN");
    return 0;
}