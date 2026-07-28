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

#include "flow_control.h"
#include "common.h"
#include "error.h"

int get_hardware_flow_control(int port_idx) {
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        //LOG_ERROR_PORT_DETAILED(port_idx, "socket");
        return -1;
    }

    struct ifreq ifr;
    memset(&ifr, 0, sizeof(ifr)); 
    get_hardware_ifname(port_idx, ifr.ifr_name, IFNAMSIZ);

    struct ethtool_pauseparam epause;
    memset(&epause, 0, sizeof(epause)); 
    
    epause.cmd = ETHTOOL_GPAUSEPARAM;
    ifr.ifr_data = (caddr_t)&epause;

    if (ioctl(sockfd, SIOCETHTOOL, &ifr) < 0) {
        //LOG_ERROR_PORT_DETAILED(port_idx, "ioctl(ETHTOOL_GPAUSEPARAM)");
        close(sockfd);
        return -1;
    }

    close(sockfd);
    return (epause.rx_pause || epause.tx_pause) ? 1 : 0;
}

int set_hardware_flow_control(int port_idx, int enable) {
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        //LOG_ERROR_PORT_DETAILED(port_idx, "socket");
        return -1;
    }

    struct ifreq ifr;
    memset(&ifr, 0, sizeof(ifr)); 
    get_hardware_ifname(port_idx, ifr.ifr_name, IFNAMSIZ);

    struct ethtool_pauseparam epause;
    memset(&epause, 0, sizeof(epause)); 

    epause.cmd = ETHTOOL_GPAUSEPARAM;
    ifr.ifr_data = (caddr_t)&epause;
    
    if (ioctl(sockfd, SIOCETHTOOL, &ifr) < 0) {
        //LOG_ERROR_PORT_DETAILED(port_idx, "ioctl(ETHTOOL_GPAUSEPARAM) перед set");
        close(sockfd);
        return -1; 
    }

    epause.cmd = ETHTOOL_SPAUSEPARAM;
    epause.rx_pause = enable ? 1 : 0;
    epause.tx_pause = enable ? 1 : 0;
    
    if (ioctl(sockfd, SIOCETHTOOL, &ifr) < 0) {
        //LOG_ERROR_PORT_DETAILED(port_idx, "ioctl(ETHTOOL_SPAUSEPARAM)");
        close(sockfd);
        return -1;
    }

    close(sockfd);
    printf("Hardware: Flow Control для %s установлен в %s\n", ifr.ifr_name, enable ? "ON" : "OFF");
    return 0;
}