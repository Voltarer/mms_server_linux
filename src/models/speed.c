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

#include "speed.h"
#include "common.h"
#include "include/error.h"

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
    int speed = ethtool_cmd_speed(&ecmd);
    
    if (speed == 65535) {
        fprintf(stderr, "[ERROR] Port %d (%s): Некорректное значение скорости (65535)\n", port_idx, ifr.ifr_name);
        return -1;
    }
    return speed;
#else
    LOG_ERROR("Функция не поддерживается на Windows");
    return -1;
#endif
}

int set_hardware_port_speed(int port_idx, int mode_val) {
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

    int speed = SPEED_100;
    int duplex = DUPLEX_FULL;

    switch(mode_val) {
        case 1:  speed = SPEED_10;   duplex = DUPLEX_HALF; break; 
        case 2:  speed = SPEED_10;   duplex = DUPLEX_FULL; break; 
        case 4:  speed = SPEED_100;  duplex = DUPLEX_HALF; break; 
        case 8:  speed = SPEED_100;  duplex = DUPLEX_FULL; break; 
        case 16: speed = SPEED_1000; duplex = DUPLEX_HALF; break; 
        case 32: speed = SPEED_1000; duplex = DUPLEX_FULL; break; 
        default:
            if (mode_val == 10 || mode_val == 100 || mode_val == 1000) {
                speed = mode_val;
                duplex = DUPLEX_FULL; 
            } else {
                fprintf(stderr, "[ERROR] Port %d (%s): Неподдерживаемый режим скорости %d\n", port_idx, ifr.ifr_name, mode_val);
                close(sockfd);
                return -1;
            }
            break;
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
    printf("Hardware: Для %s установлен режим %d Mbps / %s Duplex\n", 
           ifr.ifr_name, speed, (duplex == DUPLEX_FULL) ? "FULL" : "HALF");
    return 0;
}