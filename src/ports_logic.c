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

// Глобальная настройка имени интерфейса. 
#define TARGET_INTERFACE "enp3s0"

/**
 * Заполняет буфер именем текущего интерфейса
 */
void get_hardware_ifname(int port_idx, char* dest, size_t max_len) {
    snprintf(dest, max_len, "%s", TARGET_INTERFACE);
}

/**
 * Получение физического статуса линка (есть сигнал/нет сигнала)
 */
int get_hardware_port_status(int port_idx, int nl_fd) {
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
            
            char expected_name[IF_NAMESIZE];
            get_hardware_ifname(port_idx, expected_name, sizeof(expected_name));
            
            if (strcmp(ifname, expected_name) == 0) {
                return (ifi->ifi_flags & IFF_RUNNING) ? 1 : 2;
            }
        }
        nh = NLMSG_NEXT(nh, len);
    }
    return 1;
}

/**
 * Получение административного статуса порта (Включен ли программно)
 * Возвращает: 1 (UP), 0 (DOWN)
 */
int get_hardware_admin_status(int port_idx) {
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) return 0;

    struct ifreq ifr;
    get_hardware_ifname(port_idx, ifr.ifr_name, IFNAMSIZ);

    if (ioctl(sockfd, SIOCGIFFLAGS, &ifr) < 0) {
        close(sockfd);
        return 0;
    }
    close(sockfd);
    
    // IFF_UP означает, что порт административно поднят
    return (ifr.ifr_flags & IFF_UP) ? 1 : 0;
}

/**
 * Получение MAC-адреса интерфейса в виде строки
 */
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

/**
 * Получение поддерживаемых режимов порта (Битовая маска для модели INT32)
 */
int32_t get_hardware_capabilities(int port_idx) {
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) return 0;

    struct ifreq ifr;
    struct ethtool_cmd ecmd;
    get_hardware_ifname(port_idx, ifr.ifr_name, IFNAMSIZ);

    ifr.ifr_data = (caddr_t)&ecmd;
    ecmd.cmd = ETHTOOL_GSET;

    if (ioctl(sockfd, SIOCETHTOOL, &ifr) < 0) {
        close(sockfd);
        return 0; 
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

/**
 * Вывод поддерживаемых режимов текстом через запятую в консоль
 */
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

/**
 * Управление административным состоянием интерфейса (Up/Down)
 */
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
 * Принудительная установка скорости порта
 */
int set_hardware_port_speed(int port_idx, int speed_mbps) {
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) return -1;

    struct ifreq ifr;
    struct ethtool_cmd ecmd;
    get_hardware_ifname(port_idx, ifr.ifr_name, IFNAMSIZ);

    ifr.ifr_data = (caddr_t)&ecmd;
    ecmd.cmd = ETHTOOL_GSET;
    if (ioctl(sockfd, SIOCETHTOOL, &ifr) < 0) {
        perror("Ошибка ioctl(SIOCETHTOOL) GSET");
        close(sockfd);
        return -1;
    }

    ethtool_cmd_speed_set(&ecmd, speed_mbps);
    ecmd.autoneg = AUTONEG_DISABLE; 
    ecmd.cmd = ETHTOOL_SSET;

    if (ioctl(sockfd, SIOCETHTOOL, &ifr) < 0) {
        perror("Ошибка ioctl(SIOCETHTOOL) SSET (Speed)"); 
        close(sockfd);
        return -1;
    }

    close(sockfd);
    printf("Hardware: Скорость %s установлена в %d Mbps\n", ifr.ifr_name, speed_mbps);
    return 0;
}

/**
 * Чтение текущей скорости порта
 * Возвращает скорость в Mbps или -1 при ошибке/неизвестной скорости
 */
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
    
    // 65535 (или SPEED_UNKNOWN) означает, что скорость не определена (например, кабель не подключен)
    if (speed == 65535) return -1; 
    return speed;
#else
    return -1;
#endif
}

/**
 * Переключение автосогласования (On/Off)
 */
int set_autongt(int port_idx, int autongt_enable) {
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) return -1;

    struct ifreq ifr;
    struct ethtool_cmd ecmd;
    get_hardware_ifname(port_idx, ifr.ifr_name, IFNAMSIZ);

    ifr.ifr_data = (caddr_t)&ecmd;
    ecmd.cmd = ETHTOOL_GSET;
    if (ioctl(sockfd, SIOCETHTOOL, &ifr) < 0) {
        perror("Ошибка ioctl(SIOCETHTOOL) GSET (AutoNgt)");
        close(sockfd);
        return -1;
    }

    ecmd.autoneg = autongt_enable ? AUTONEG_ENABLE : AUTONEG_DISABLE;
    ecmd.cmd = ETHTOOL_SSET;

    if (ioctl(sockfd, SIOCETHTOOL, &ifr) < 0) {
        perror("Ошибка ioctl(SIOCETHTOOL) SSET (AutoNgt)");
        close(sockfd);
        return -1;
    }

    close(sockfd);
    printf("Hardware: Автосогласование интерфейса %s -> %s\n", ifr.ifr_name, autongt_enable ? "ВКЛЮЧЕНО" : "ВЫКЛЮЧЕНО");
    return 0;
}

/**
 * Чтение текущего статуса автосогласования
 * Возвращает 1 (ON), 0 (OFF), или -1 (Ошибка)
 */
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
        perror("Ошибка ioctl(SIOCETHTOOL) GSET (get_autongt)");
        close(sockfd);
        return -1;
    }

    close(sockfd);
    return (ecmd.autoneg == AUTONEG_ENABLE) ? 1 : 0;
#else
    return 0;
#endif
}
/**
 * Получение текущего значения MTU порта
 */
int get_hardware_mtu(int port_idx) {
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) return -1;

    struct ifreq ifr;
    get_hardware_ifname(port_idx, ifr.ifr_name, IFNAMSIZ);

    if (ioctl(sockfd, SIOCGIFMTU, &ifr) < 0) {
        perror("Ошибка ioctl(SIOCGIFMTU)");
        close(sockfd);
        return -1;
    }

    close(sockfd);
    return ifr.ifr_mtu;
}

/**
 * Установка значения MTU порта
 */
int set_hardware_mtu(int port_idx, int mtu_value) {
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) return -1;

    struct ifreq ifr;
    get_hardware_ifname(port_idx, ifr.ifr_name, IFNAMSIZ);

    ifr.ifr_mtu = mtu_value;

    if (ioctl(sockfd, SIOCSIFMTU, &ifr) < 0) {
        perror("Ошибка ioctl(SIOCSIFMTU)");
        close(sockfd);
        return -1;
    }

    close(sockfd);
    printf("Hardware: MTU для %s успешно изменен на %d\n", ifr.ifr_name, mtu_value);
    return 0;
}

/**
 * Чтение текущего состояния Flow Control
 * Возвращает 1 (Включен RX или TX), 0 (Выключен), -1 (Ошибка)
 */
int get_hardware_flow_control(int port_idx) {
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) return -1;

    struct ifreq ifr;
    struct ethtool_pauseparam epause;
    get_hardware_ifname(port_idx, ifr.ifr_name, IFNAMSIZ);

    epause.cmd = ETHTOOL_GPAUSEPARAM;
    ifr.ifr_data = (caddr_t)&epause;

    if (ioctl(sockfd, SIOCETHTOOL, &ifr) < 0) {
        perror("Ошибка ioctl(ETHTOOL_GPAUSEPARAM)");
        close(sockfd);
        return -1;
    }

    close(sockfd);
    // Возвращаем 1, если включен хотя бы один из механизмов (RX или TX пауза)
    return (epause.rx_pause || epause.tx_pause) ? 1 : 0;
}
/**
 * Установка Flow Control (симметричный режим: RX + TX)
 */
int set_hardware_flow_control(int port_idx, int enable) {
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) return -1;

    struct ifreq ifr;
    struct ethtool_pauseparam epause;
    get_hardware_ifname(port_idx, ifr.ifr_name, IFNAMSIZ);

    // Сначала читаем текущие параметры, чтобы не испортить поле autoneg
    epause.cmd = ETHTOOL_GPAUSEPARAM;
    ifr.ifr_data = (caddr_t)&epause;
    ioctl(sockfd, SIOCETHTOOL, &ifr);

    // Устанавливаем новые значения
    epause.cmd = ETHTOOL_SPAUSEPARAM;
    epause.rx_pause = enable ? 1 : 0;
    epause.tx_pause = enable ? 1 : 0;
    // Обычно flow control autoneg согласуется с общим autoneg
    
    if (ioctl(sockfd, SIOCETHTOOL, &ifr) < 0) {
        perror("Ошибка ioctl(ETHTOOL_SPAUSEPARAM)");
        close(sockfd);
        return -1;
    }

    close(sockfd);
    printf("Hardware: Flow Control для %s установлен в %s\n", ifr.ifr_name, enable ? "ON" : "OFF");
    return 0;
}