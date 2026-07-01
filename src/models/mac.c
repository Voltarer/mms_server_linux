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

#include "mac.h"
#include "common.h"
#include "include/error.h"

int get_hardware_mac_address(int port_idx, char* mac_str, size_t max_len) {
    if (mac_str == NULL || max_len < 18) {
        LOG_ERROR("Некорректный буфер для MAC-адреса");
        return -1;
    }

    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        LOG_ERROR_DETAILED("socket");
        return -1;
    }

    struct ifreq ifr;
    get_hardware_ifname(port_idx, ifr.ifr_name, IFNAMSIZ);

    if (ioctl(sockfd, SIOCGIFHWADDR, &ifr) < 0) {
        fprintf(stderr, "[ERROR] Port %d (%s): ", port_idx, ifr.ifr_name);
        LOG_ERROR_DETAILED("ioctl(SIOCGIFHWADDR)");
        close(sockfd);
        return -1;
    }

    close(sockfd);
    
    unsigned char* mac = (unsigned char*)ifr.ifr_hwaddr.sa_data;
    snprintf(mac_str, max_len, "%02X:%02X:%02X:%02X:%02X:%02X",
             mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
    return 0;
}