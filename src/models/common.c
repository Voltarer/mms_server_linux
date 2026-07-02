#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ifaddrs.h> // Добавлено для getifaddrs
#include "common.h"
#include "include/error.h"

#define MAX_PORTS 28

typedef struct {
    char ifname[16];
    bool exists;
} PhysicalPort;

// Внутренний массив для хранения обнаруженных интерфейсов
static PhysicalPort g_ports[MAX_PORTS];

// Функция динамического обнаружения интерфейсов в Linux
void discover_hardware_ports(void) {
    struct ifaddrs *ifaddr, *ifa;

    // Сбрасываем карту портов перед сканированием
    for (int i = 0; i < MAX_PORTS; i++) {
        g_ports[i].exists = false;
        g_ports[i].ifname[0] = '\0';
    }

    if (getifaddrs(&ifaddr) == -1) {
        LOG_ERROR("Ошибка: не удалось выполнить getifaddrs для сканирования портов");
        return;
    }

    // Проходим по всем интерфейсам, которые видит ОС Linux
    for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
        if (ifa->ifa_name == NULL) continue;

        char *name = ifa->ifa_name;
        int port_idx = -1;

        // Фильтруем интерфейсы lan0...lan23
        if (strncmp(name, "lan", 3) == 0) {
            int num = atoi(name + 3);
            if (num >= 0 && num < 24) {
                port_idx = num;
            }
        } 
        // Фильтруем интерфейсы optical0...optical3
        else if (strncmp(name, "optical", 7) == 0) {
            int num = atoi(name + 7);
            if (num >= 0 && num < 4) {
                port_idx = 24 + num; // Занимают индексы 24..27
            }
        }

        // Если интерфейс подошел, сохраняем его
        if (port_idx != -1 && port_idx < MAX_PORTS) {
            if (!g_ports[port_idx].exists) {
                strncpy(g_ports[port_idx].ifname, name, sizeof(g_ports[port_idx].ifname) - 1);
                g_ports[port_idx].exists = true;
                printf("[INFO] Динамически привязан интерфейс: %s -> Индекс MMS: %d (LPCP%d)\n", 
                       name, port_idx + 1, port_idx + 1);
            }
        }
    }

    freeifaddrs(ifaddr);
}

// Проверка: существует ли физический интерфейс для этого индекса
bool is_port_present(int port_idx) {
    if (port_idx < 0 || port_idx >= MAX_PORTS) return false;
    return g_ports[port_idx].exists;
}

// Возвращает имя интерфейса, если он существует
void get_hardware_ifname(int port_idx, char* dest, size_t max_len) {
    if (dest == NULL || max_len == 0) {
        LOG_ERROR("Некорректные параметры в get_hardware_ifname");
        return;
    }

    if (port_idx >= 0 && port_idx < MAX_PORTS && g_ports[port_idx].exists) {
        snprintf(dest, max_len, "%s", g_ports[port_idx].ifname);
    } else {
        snprintf(dest, max_len, "unknown");
    }
}