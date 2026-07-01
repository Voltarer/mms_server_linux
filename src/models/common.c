#define _GNU_SOURCE
#include <stdio.h>
#include "common.h"
#include "include/error.h"

void get_hardware_ifname(int port_idx, char* dest, size_t max_len) {
    if (dest == NULL || max_len == 0) {
        LOG_ERROR("Некорректные параметры в get_hardware_ifname");
        return;
    }
    // Первые 24 порта (0..23)
    if (port_idx < 24) {
        snprintf(dest, max_len, "lan%d", port_idx + 1);
    } 
    // Остальные 4 порта (24..27)
    else {
        snprintf(dest, max_len, "optical%d", port_idx - 24);
    }
}