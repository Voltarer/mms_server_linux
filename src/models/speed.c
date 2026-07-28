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
#include <stdint.h>

#include "speed.h"
#include "common.h"
#include "include/error.h"

// Константы RFC 4836
#define MAU_TYPE_10BASET_HD      11
#define MAU_TYPE_10BASET_FD      14
#define MAU_TYPE_100BASETX_HD    15
#define MAU_TYPE_100BASETX_FD    16
#define MAU_TYPE_1000BASET_HD    29
#define MAU_TYPE_1000BASET_FD    30

int get_hardware_port_speed(int port_idx) {
#ifndef _WIN32
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        LOG_ERROR_DETAILED("socket");
        return -1;
    }

    struct ifreq ifr;
    struct ethtool_cmd ecmd;
    get_hardware_ifname(port_idx, ifr.ifr_name, IFNAMSIZ);

    ifr.ifr_data = (caddr_t)&ecmd;
    ecmd.cmd = ETHTOOL_GSET;
    
    if (ioctl(sockfd, SIOCETHTOOL, &ifr) < 0) {
        fprintf(stderr, "[ERROR] Port %d (%s): ", port_idx, ifr.ifr_name);
        LOG_ERROR_DETAILED("ioctl(SIOCETHTOOL)");
        close(sockfd);
        return -1;
    }

    close(sockfd);
    
    uint32_t speed = ethtool_cmd_speed(&ecmd);
    uint8_t duplex = ecmd.duplex;
    
    if (speed == 65535 || speed == 0) {
        return -1; // Линк в дауне или неизвестная скорость
    }

    // Маппинг в RFC 4836
    if (speed == SPEED_1000) {
        return (duplex == DUPLEX_FULL) ? MAU_TYPE_1000BASET_FD : MAU_TYPE_1000BASET_HD;
    } else if (speed == SPEED_100) {
        return (duplex == DUPLEX_FULL) ? MAU_TYPE_100BASETX_FD : MAU_TYPE_100BASETX_HD;
    } else if (speed == SPEED_10) {
        return (duplex == DUPLEX_FULL) ? MAU_TYPE_10BASET_FD : MAU_TYPE_10BASET_HD;
    }

    return -1; // Неизвестный стандарт
#else
    LOG_ERROR("Функция не поддерживается на Windows");
    return -1;
#endif
}

int set_hardware_port_speed(int port_idx, int mau_type) {
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        LOG_ERROR_DETAILED("socket");
        return -1;
    }

    struct ifreq ifr;
    struct ethtool_cmd ecmd;
    get_hardware_ifname(port_idx, ifr.ifr_name, IFNAMSIZ);

    ifr.ifr_data = (caddr_t)&ecmd;
    ecmd.cmd = ETHTOOL_GSET;
    if (ioctl(sockfd, SIOCETHTOOL, &ifr) < 0) {
        fprintf(stderr, "[ERROR] Port %d (%s): ", port_idx, ifr.ifr_name);
        LOG_ERROR_DETAILED("ioctl(SIOCETHTOOL) GSET");
        close(sockfd);
        return -1;
    }

    uint32_t speed = SPEED_100;
    uint8_t duplex = DUPLEX_FULL;

    // Расшифровка из RFC 4836
    switch(mau_type) {
        case MAU_TYPE_10BASET_HD:   speed = SPEED_10;   duplex = DUPLEX_HALF; break; 
        case MAU_TYPE_10BASET_FD:   speed = SPEED_10;   duplex = DUPLEX_FULL; break; 
        case MAU_TYPE_100BASETX_HD: speed = SPEED_100;  duplex = DUPLEX_HALF; break; 
        case MAU_TYPE_100BASETX_FD: speed = SPEED_100;  duplex = DUPLEX_FULL; break; 
        case MAU_TYPE_1000BASET_HD: speed = SPEED_1000; duplex = DUPLEX_HALF; break; 
        case MAU_TYPE_1000BASET_FD: speed = SPEED_1000; duplex = DUPLEX_FULL; break; 
        default:
            fprintf(stderr, "[ERROR] Port %d (%s): Неподдерживаемый MAU Type %d\n", port_idx, ifr.ifr_name, mau_type);
            close(sockfd);
            return -1;
    }

    ethtool_cmd_speed_set(&ecmd, speed);
    ecmd.duplex = duplex;
    ecmd.autoneg = AUTONEG_DISABLE; 
    ecmd.cmd = ETHTOOL_SSET;

    if (ioctl(sockfd, SIOCETHTOOL, &ifr) < 0) {
        fprintf(stderr, "[ERROR] Port %d (%s): ", port_idx, ifr.ifr_name);
        LOG_ERROR_DETAILED("ioctl(SIOCETHTOOL) SSET");
        close(sockfd);
        return -1;
    }

    close(sockfd);
    printf("Hardware: Для %s установлен режим %d Mbps / %s Duplex (MAU: %d)\n", 
           ifr.ifr_name, speed, (duplex == DUPLEX_FULL) ? "FULL" : "HALF", mau_type);
    return 0;
}