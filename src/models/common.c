#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>   // Для системного вызова access()
#include <stdbool.h>
#include "common.h"
#include "include/error.h"

void get_hardware_ifname(int port_idx, char* dest, size_t max_len) {
    if (dest == NULL || max_len == 0) {
        LOG_ERROR("Некорректные параметры в get_hardware_ifname");
        return;
    }
    
    // Вариант А: Статическое соответствие без смещения +1
    // Первые 24 порта (индексы 0..23) -> lan0..lan23
    if (port_idx < 24) {
        snprintf(dest, max_len, "lan%d", port_idx);
    } 
    // Остальные 4 порта (индексы 24..27) -> optical0..optical3
    else {
        snprintf(dest, max_len, "optical%d", port_idx - 24);
    }
}

bool is_port_present(int port_idx) {
    char ifname[16];
    char sys_path[64];
    
    if (port_idx < 0 || port_idx >= 28) return false;
    
    get_hardware_ifname(port_idx, ifname, sizeof(ifname));
    
    // Метод на 100% надежен на встроенных системах (uClibc/MIPS)
    snprintf(sys_path, sizeof(sys_path), "/sys/class/net/%s", ifname);
    
    return (access(sys_path, F_OK) == 0);
}