#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <linux/netlink.h>
#include <linux/rtnetlink.h>
#include <net/if.h>

#include "mtu.h"
#include "common.h"
#include "include/error.h"

// Вспомогательная функция: отправка и получение ответа
static int netlink_request(int nl_sock, const void *req, size_t req_len,
                           void *resp, size_t *resp_len) {
    struct sockaddr_nl addr = {
        .nl_family = AF_NETLINK,
        .nl_pid = 0,
        .nl_groups = 0
    };
    struct iovec iov = {
        .iov_base = (void *)req,
        .iov_len = req_len
    };
    struct msghdr msg = {
        .msg_name = &addr,
        .msg_namelen = sizeof(addr),
        .msg_iov = &iov,
        .msg_iovlen = 1,
        .msg_control = NULL,
        .msg_controllen = 0,
        .msg_flags = 0
    };

    if (sendmsg(nl_sock, &msg, 0) < 0) {
        LOG_ERROR_DETAILED("sendmsg");
        return -1;
    }

    // Подготавливаем структуру для получения ответа
    iov.iov_base = resp;
    iov.iov_len = *resp_len;
    // Очищаем адрес источника для recvmsg
    msg.msg_name = NULL;
    msg.msg_namelen = 0;

    ssize_t n = recvmsg(nl_sock, &msg, 0);
    if (n < 0) {
        LOG_ERROR_DETAILED("recvmsg");
        return -1;
    }
    *resp_len = n;
    return 0;
}

int get_hardware_mtu(int port_idx) {
    // Netlink работает через SOCK_RAW
    int nl_sock = socket(AF_NETLINK, SOCK_RAW, NETLINK_ROUTE);
    if (nl_sock < 0) {
        LOG_ERROR_PORT_DETAILED(port_idx, "socket(NETLINK_ROUTE)");
        return -1;
    }

    char ifname[IFNAMSIZ];
    get_hardware_ifname(port_idx, ifname, sizeof(ifname));

    unsigned int ifindex = if_nametoindex(ifname);
    if (ifindex == 0) {
        fprintf(stderr, "[ERROR] Порт %d: Неизвестный интерфейс: %s\n", port_idx, ifname);
        close(nl_sock);
        return -1;
    }

    struct {
        struct nlmsghdr nh;
        struct ifinfomsg ifi;
    } req;
    memset(&req, 0, sizeof(req));

    req.nh.nlmsg_len = NLMSG_LENGTH(sizeof(struct ifinfomsg));
    req.nh.nlmsg_type = RTM_GETLINK;

    req.nh.nlmsg_flags = NLM_F_REQUEST; 
    req.nh.nlmsg_seq = 1;
    req.nh.nlmsg_pid = getpid();

    req.ifi.ifi_family = AF_UNSPEC;
    req.ifi.ifi_index = ifindex;

    char resp[4096];
    size_t resp_len = sizeof(resp);

    if (netlink_request(nl_sock, &req, req.nh.nlmsg_len, resp, &resp_len) < 0) {
        close(nl_sock);
        return -1;
    }
    close(nl_sock);

    // Парсим ответ
    struct nlmsghdr *nlh = (struct nlmsghdr *)resp;
    if (nlh->nlmsg_type == NLMSG_ERROR) {
        struct nlmsgerr *err = (struct nlmsgerr *)NLMSG_DATA(nlh);
        errno = -err->error;
        LOG_ERROR_PORT_DETAILED(port_idx, "Netlink error response");
        return -1;
    }

    if (nlh->nlmsg_type == RTM_NEWLINK) {
        struct ifinfomsg *ifi = NLMSG_DATA(nlh);
        struct rtattr *rta = IFLA_RTA(ifi);
        int rta_len = NLMSG_PAYLOAD(nlh, sizeof(struct ifinfomsg));

        while (RTA_OK(rta, rta_len)) {
            if (rta->rta_type == IFLA_MTU) {
                unsigned int mtu = *(unsigned int *)RTA_DATA(rta);
                return (int)mtu;
            }
            rta = RTA_NEXT(rta, rta_len);
        }
    }

    LOG_ERROR_PORT(port_idx, "MTU не найден в ответе netlink");
    return -1;
}

int set_hardware_mtu(int port_idx, int mtu_value) {

    int nl_sock = socket(AF_NETLINK, SOCK_RAW, NETLINK_ROUTE);
    if (nl_sock < 0) {
        LOG_ERROR_PORT_DETAILED(port_idx, "socket(NETLINK_ROUTE)");
        return -1;
    }

    char ifname[IFNAMSIZ];
    get_hardware_ifname(port_idx, ifname, sizeof(ifname));

    unsigned int ifindex = if_nametoindex(ifname);
    if (ifindex == 0) {
        fprintf(stderr, "[ERROR] Порт %d: Неизвестный интерфейс: %s\n", port_idx, ifname);
        close(nl_sock);
        return -1;
    }

    struct {
        struct nlmsghdr nh;
        struct ifinfomsg ifi;
        char attrbuf[512];
    } req;
    memset(&req, 0, sizeof(req));

    req.nh.nlmsg_len = NLMSG_LENGTH(sizeof(struct ifinfomsg));
    req.nh.nlmsg_type = RTM_NEWLINK;

    req.nh.nlmsg_flags = NLM_F_REQUEST | NLM_F_ACK; 
    req.nh.nlmsg_seq = 1;
    req.nh.nlmsg_pid = getpid();

    req.ifi.ifi_family = AF_UNSPEC;
    req.ifi.ifi_index = ifindex;
    req.ifi.ifi_change = 0; 

    // Добавляем атрибут по правилам выравнивания Netlink
    struct rtattr *rta = (struct rtattr *)(((char *)&req) + NLMSG_ALIGN(req.nh.nlmsg_len));
    rta->rta_type = IFLA_MTU;
    rta->rta_len = RTA_LENGTH(sizeof(unsigned int));
    *(unsigned int *)RTA_DATA(rta) = mtu_value;
    
    req.nh.nlmsg_len = NLMSG_ALIGN(req.nh.nlmsg_len) + rta->rta_len;

    char resp[4096];
    size_t resp_len = sizeof(resp);
    
    if (netlink_request(nl_sock, &req, req.nh.nlmsg_len, resp, &resp_len) < 0) {
        close(nl_sock);
        return -1;
    }

    close(nl_sock);

    // Проверяем ACK пакет от ядра
    struct nlmsghdr *nlh = (struct nlmsghdr *)resp;
    if (nlh->nlmsg_type == NLMSG_ERROR) {
        struct nlmsgerr *err = (struct nlmsgerr *)NLMSG_DATA(nlh);
        if (err->error != 0) { // 0 означает успешное выполнение (ACK)
            errno = -err->error;
            LOG_ERROR_PORT_DETAILED(port_idx, "Ядро вернуло ошибку при установке MTU");
            return -1;
        }
    }

    printf("Hardware: MTU для %s успешно изменен на %d\n", ifname, mtu_value);
    return 0;
}