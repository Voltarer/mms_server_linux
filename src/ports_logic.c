#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <linux/sockios.h>
#include <linux/ethtool.h>
#include <linux/rtnetlink.h>
#include <net/if.h>
#include <errno.h>

/**
 * Заполняет буфер именем текущего интерфейса. 
 */
void get_hardware_ifname(int port_idx, char* dest, size_t max_len) {
    snprintf(dest, max_len, "lan%d", port_idx);
}

int get_hardware_port_status(int port_idx) {
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) return -1; // Исправлено: возвращаем -1 при ошибке

    struct ifreq ifr;
    get_hardware_ifname(port_idx, ifr.ifr_name, IFNAMSIZ);

    if (ioctl(sockfd, SIOCGIFFLAGS, &ifr) < 0) {
        close(sockfd);
        return -1; // Исправлено: возвращаем -1 при ошибке
    }
    close(sockfd);
    
    return (ifr.ifr_flags & IFF_RUNNING) ? 1 : 2;
}

int get_hardware_admin_status(int port_idx) {
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) return -1;

    struct ifreq ifr;
    get_hardware_ifname(port_idx, ifr.ifr_name, IFNAMSIZ);

    if (ioctl(sockfd, SIOCGIFFLAGS, &ifr) < 0) {
        close(sockfd);
        return -1; // Исправлено
    }
    close(sockfd);
    
    return (ifr.ifr_flags & IFF_UP) ? 1 : 0;
}

int get_hardware_mac_address(int port_idx, char* mac_str, size_t max_len) {
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) return -1;

    struct ifreq ifr;
    get_hardware_ifname(port_idx, ifr.ifr_name, IFNAMSIZ);

    if (ioctl(sockfd, SIOCGIFHWADDR, &ifr) < 0) {
        close(sockfd);
        return -1;
    }

    close(sockfd);
    
    unsigned char* mac = (unsigned char*)ifr.ifr_hwaddr.sa_data;
    snprintf(mac_str, max_len, "%02X:%02X:%02X:%02X:%02X:%02X",
             mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
    return 0;
}

int32_t get_hardware_capabilities(int port_idx) {
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) return -1; // Исправлено

    struct ifreq ifr;
    struct ethtool_cmd ecmd;
    get_hardware_ifname(port_idx, ifr.ifr_name, IFNAMSIZ);

    ifr.ifr_data = (caddr_t)&ecmd;
    ecmd.cmd = ETHTOOL_GSET;

    if (ioctl(sockfd, SIOCETHTOOL, &ifr) < 0) {
        close(sockfd);
        return -1; // Исправлено
    }
    close(sockfd);

    int32_t capabilities = 0;
    if (ecmd.supported & SUPPORTED_10baseT_Half)  capabilities |= (1 << 0);
    if (ecmd.supported & SUPPORTED_10baseT_Full)  capabilities |= (1 << 1);
    if (ecmd.supported & SUPPORTED_100baseT_Half) capabilities |= (1 << 2);
    if (ecmd.supported & SUPPORTED_100baseT_Full) capabilities |= (1 << 3);
    if (ecmd.supported & SUPPORTED_1000baseT_Half) capabilities |= (1 << 4);
    if (ecmd.supported & SUPPORTED_1000baseT_Full) capabilities |= (1 << 5);

    return capabilities;
}

void print_hardware_capabilities_string(int port_idx) {
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) return;

    struct ifreq ifr;
    struct ethtool_cmd ecmd;
    get_hardware_ifname(port_idx, ifr.ifr_name, IFNAMSIZ);

    ifr.ifr_data = (caddr_t)&ecmd;
    ecmd.cmd = ETHTOOL_GSET;

    if (ioctl(sockfd, SIOCETHTOOL, &ifr) < 0) {
        close(sockfd);
        return;
    }
    close(sockfd);

    printf("Hardware: Поддерживаемые режимы порта %s: [", ifr.ifr_name);
    int first = 1;
    if (ecmd.supported & SUPPORTED_10baseT_Half) { printf("%s10baseT/Half", first?"":", "); first=0; }
    if (ecmd.supported & SUPPORTED_10baseT_Full) { printf("%s10baseT/Full", first?"":", "); first=0; }
    if (ecmd.supported & SUPPORTED_100baseT_Half) { printf("%s100baseT/Half", first?"":", "); first=0; }
    if (ecmd.supported & SUPPORTED_100baseT_Full) { printf("%s100baseT/Full", first?"":", "); first=0; }
    if (ecmd.supported & SUPPORTED_1000baseT_Half) { printf("%s1000baseT/Half", first?"":", "); first=0; }
    if (ecmd.supported & SUPPORTED_1000baseT_Full) { printf("%s1000baseT/Full", first?"":", "); first=0; }
    printf("]\n");
}

int set_hardware_port_status(int port_idx, int enable) {
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) return -1;

    struct ifreq ifr;
    get_hardware_ifname(port_idx, ifr.ifr_name, IFNAMSIZ);

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
    printf("Hardware: Интерфейс %s переведен в %s\n", ifr.ifr_name, enable ? "UP" : "DOWN");
    return 0;
}

/**
    Настраивает одновременно и скорость, и дуплекс.
 */
int set_hardware_port_speed(int port_idx, int mode_val) {
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) return -1;

    struct ifreq ifr;
    struct ethtool_cmd ecmd;
    get_hardware_ifname(port_idx, ifr.ifr_name, IFNAMSIZ);

    ifr.ifr_data = (caddr_t)&ecmd;
    ecmd.cmd = ETHTOOL_GSET;
    if (ioctl(sockfd, SIOCETHTOOL, &ifr) < 0) {
        if (errno != EOPNOTSUPP) {
            perror("Ошибка ioctl(SIOCETHTOOL) GSET");
        }
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
        if (errno != EOPNOTSUPP) {
            perror("Ошибка ioctl(SIOCETHTOOL) SSET (Speed)"); 
        }
        close(sockfd);
        return -1;
    }

    close(sockfd);
    printf("Hardware: Для %s установлен режим %d Mbps / %s Duplex\n", 
           ifr.ifr_name, speed, (duplex == DUPLEX_FULL) ? "FULL" : "HALF");
    return 0;
}

int get_hardware_port_speed(int port_idx) {
#ifndef _WIN32
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) return -1;

    struct ifreq ifr;
    struct ethtool_cmd ecmd;
    get_hardware_ifname(port_idx, ifr.ifr_name, IFNAMSIZ);

    ifr.ifr_data = (caddr_t)&ecmd;
    ecmd.cmd = ETHTOOL_GSET;
    
    if (ioctl(sockfd, SIOCETHTOOL, &ifr) < 0) {
        close(sockfd);
        return -1;
    }

    close(sockfd);
    int speed = ethtool_cmd_speed(&ecmd);
    
    if (speed == 65535) return -1; 
    return speed;
#else
    return -1;
#endif
}

int set_autongt(int port_idx, int autongt_enable) {
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) return -1;

    struct ifreq ifr;
    struct ethtool_cmd ecmd;
    get_hardware_ifname(port_idx, ifr.ifr_name, IFNAMSIZ);

    ifr.ifr_data = (caddr_t)&ecmd;
    ecmd.cmd = ETHTOOL_GSET;
    if (ioctl(sockfd, SIOCETHTOOL, &ifr) < 0) {
        if (errno != EOPNOTSUPP) {
            perror("Ошибка ioctl(SIOCETHTOOL) GSET (AutoNgt)");
        }
        close(sockfd);
        return -1;
    }

    ecmd.autoneg = autongt_enable ? AUTONEG_ENABLE : AUTONEG_DISABLE;
    ecmd.cmd = ETHTOOL_SSET;

    if (ioctl(sockfd, SIOCETHTOOL, &ifr) < 0) {
        if (errno != EOPNOTSUPP) {
            perror("Ошибка ioctl(SIOCETHTOOL) SSET (AutoNgt)");
        }
        close(sockfd);
        return -1;
    }

    close(sockfd);
    printf("Hardware: Автосогласование интерфейса %s -> %s\n", ifr.ifr_name, autongt_enable ? "ВКЛЮЧЕНО" : "ВЫКЛЮЧЕНО");
    return 0;
}

int get_hardware_autongt(int port_idx) {
#ifndef _WIN32
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) return -1;

    struct ifreq ifr;
    struct ethtool_cmd ecmd;
    get_hardware_ifname(port_idx, ifr.ifr_name, IFNAMSIZ);

    ifr.ifr_data = (caddr_t)&ecmd;
    ecmd.cmd = ETHTOOL_GSET;
    
    if (ioctl(sockfd, SIOCETHTOOL, &ifr) < 0) {
        if (errno != EOPNOTSUPP) {
            perror("Ошибка ioctl(SIOCETHTOOL) GSET (get_autongt)");
        }
        close(sockfd);
        return -1;
    }

    close(sockfd);
    return (ecmd.autoneg == AUTONEG_ENABLE) ? 1 : 0;
#else
    return -1; // Исправлено на -1
#endif
}

int get_hardware_mtu(int port_idx) {
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) return -1;

    struct ifreq ifr;
    get_hardware_ifname(port_idx, ifr.ifr_name, IFNAMSIZ);

    if (ioctl(sockfd, SIOCGIFMTU, &ifr) < 0) {
        if (errno != EOPNOTSUPP) {
            perror("Ошибка ioctl(SIOCGIFMTU)");
        }
        close(sockfd);
        return -1;
    }

    close(sockfd);
    return ifr.ifr_mtu;
}

int set_hardware_mtu(int port_idx, int mtu_value) {
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) return -1;

    struct ifreq ifr;
    get_hardware_ifname(port_idx, ifr.ifr_name, IFNAMSIZ);

    ifr.ifr_mtu = mtu_value;

    if (ioctl(sockfd, SIOCSIFMTU, &ifr) < 0) {
        if (errno != EOPNOTSUPP) {
            perror("Ошибка ioctl(SIOCSIFMTU)");
        }
        close(sockfd);
        return -1;
    }

    close(sockfd);
    printf("Hardware: MTU для %s успешно изменен на %d\n", ifr.ifr_name, mtu_value);
    return 0;
}

int get_hardware_flow_control(int port_idx) {
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) return -1;

    struct ifreq ifr;
    struct ethtool_pauseparam epause;
    get_hardware_ifname(port_idx, ifr.ifr_name, IFNAMSIZ);

    epause.cmd = ETHTOOL_GPAUSEPARAM;
    ifr.ifr_data = (caddr_t)&epause;

    if (ioctl(sockfd, SIOCETHTOOL, &ifr) < 0) {
        if (errno != EOPNOTSUPP) {
            perror("Ошибка ioctl(ETHTOOL_GPAUSEPARAM)");
        }
        close(sockfd);
        return -1; 
    }

    close(sockfd);
    return (epause.rx_pause || epause.tx_pause) ? 1 : 0;
}

int set_hardware_flow_control(int port_idx, int enable) {
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) return -1;

    struct ifreq ifr;
    struct ethtool_pauseparam epause;
    get_hardware_ifname(port_idx, ifr.ifr_name, IFNAMSIZ);

    epause.cmd = ETHTOOL_GPAUSEPARAM;
    ifr.ifr_data = (caddr_t)&epause;
    ioctl(sockfd, SIOCETHTOOL, &ifr);

    epause.cmd = ETHTOOL_SPAUSEPARAM;
    epause.rx_pause = enable ? 1 : 0;
    epause.tx_pause = enable ? 1 : 0;
    
    if (ioctl(sockfd, SIOCETHTOOL, &ifr) < 0) {
        if (errno != EOPNOTSUPP) {
            perror("Ошибка ioctl(ETHTOOL_SPAUSEPARAM)");
        }
        close(sockfd);
        return -1;
    }

    close(sockfd);
    printf("Hardware: Flow Control для %s установлен в %s\n", ifr.ifr_name, enable ? "ON" : "OFF");
    return 0;
}