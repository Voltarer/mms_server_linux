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

#include "capabilities.h"
#include "common.h"
#include "include/error.h"

// Константы RFC 4836
#define MAU_TYPE_10BASET_HD      11
#define MAU_TYPE_10BASET_FD      14
#define MAU_TYPE_100BASETX_HD    15
#define MAU_TYPE_100BASETX_FD    16
#define MAU_TYPE_1000BASET_HD    29
#define MAU_TYPE_1000BASET_FD    30

int32_t get_hardware_capabilities(int port_idx) {
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

    // Возвращаем максимально поддерживаемый режим по RFC 4836 (сверху вниз)
    if (ecmd.supported & SUPPORTED_1000baseT_Full) return MAU_TYPE_1000BASET_FD;
    if (ecmd.supported & SUPPORTED_1000baseT_Half) return MAU_TYPE_1000BASET_HD;
    if (ecmd.supported & SUPPORTED_100baseT_Full) return MAU_TYPE_100BASETX_FD;
    if (ecmd.supported & SUPPORTED_100baseT_Half) return MAU_TYPE_100BASETX_HD;
    if (ecmd.supported & SUPPORTED_10baseT_Full) return MAU_TYPE_10BASET_FD;
    if (ecmd.supported & SUPPORTED_10baseT_Half) return MAU_TYPE_10BASET_HD;

    return 0; // Ничего не поддерживается / Не удалось определить
}

void print_hardware_capabilities_string(int port_idx) {

    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        LOG_ERROR_DETAILED("socket");
        return;
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
        return;
    }
    close(sockfd);

    printf("Hardware: Поддерживаемые режимы порта %s: [", ifr.ifr_name);
    int first = 1;
    if (ecmd.supported & SUPPORTED_10baseT_Half) { printf("%s10baseT/Half", first ? "" : ", "); first=0; }
    if (ecmd.supported & SUPPORTED_10baseT_Full) { printf("%s10baseT/Full", first ? "" : ", "); first=0; }
    if (ecmd.supported & SUPPORTED_100baseT_Half) { printf("%s100baseT/Half", first ? "" : ", "); first=0; }
    if (ecmd.supported & SUPPORTED_100baseT_Full) { printf("%s100baseT/Full", first ? "" : ", "); first=0; }
    if (ecmd.supported & SUPPORTED_1000baseT_Half) { printf("%s1000baseT/Half", first ? "" : ", "); first=0; }
    if (ecmd.supported & SUPPORTED_1000baseT_Full) { printf("%s1000baseT/Full", first ? "" : ", "); first=0; }
    printf("]\n");
}