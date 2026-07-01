#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <linux/sockios.h>
#include <linux/ethtool.h>
#include <net/if.h>
#include <errno.h>

#include "autoneg.h"
#include "common.h"
#include "include/error.h"

int get_hardware_autongt(int port_idx) {
#ifndef _WIN32
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        LOG_ERROR_PORT_DETAILED(port_idx, "socket");
        return -1;
    }

    struct ifreq ifr;
    struct ethtool_cmd ecmd;
    get_hardware_ifname(port_idx, ifr.ifr_name, IFNAMSIZ);

    ifr.ifr_data = (caddr_t)&ecmd;
    ecmd.cmd = ETHTOOL_GSET;
    
    if (ioctl(sockfd, SIOCETHTOOL, &ifr) < 0) {
        LOG_ERROR_PORT_DETAILED(port_idx, "ioctl(SIOCETHTOOL)");
        close(sockfd);
        return -1;
    }

    close(sockfd);
    return (ecmd.autoneg == AUTONEG_ENABLE) ? 1 : 0;
#else
    LOG_ERROR_PORT(port_idx, "Функция не поддерживается на Windows");
    return -1;
#endif
}

int set_autongt(int port_idx, int autongt_enable) {
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        LOG_ERROR_PORT_DETAILED(port_idx, "socket");
        return -1;
    }

    struct ifreq ifr;
    struct ethtool_cmd ecmd;
    get_hardware_ifname(port_idx, ifr.ifr_name, IFNAMSIZ);

    ifr.ifr_data = (caddr_t)&ecmd;
    ecmd.cmd = ETHTOOL_GSET;
    if (ioctl(sockfd, SIOCETHTOOL, &ifr) < 0) {
        LOG_ERROR_PORT_DETAILED(port_idx, "ioctl(SIOCETHTOOL) GSET");
        close(sockfd);
        return -1;
    }

    ecmd.autoneg = autongt_enable ? AUTONEG_ENABLE : AUTONEG_DISABLE;
    ecmd.cmd = ETHTOOL_SSET;

    if (ioctl(sockfd, SIOCETHTOOL, &ifr) < 0) {
        LOG_ERROR_PORT_DETAILED(port_idx, "ioctl(SIOCETHTOOL) SSET");
        close(sockfd);
        return -1;
    }

    close(sockfd);
    printf("Hardware: Автосогласование интерфейса %s -> %s\n", ifr.ifr_name, autongt_enable ? "ВКЛЮЧЕНО" : "ВЫКЛЮЧЕНО");
    return 0;
}