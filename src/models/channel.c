#include "models/include/channel.h"
#include "models/include/common.h"
#include <stdio.h>
#include <stdlib.h>

// Вспомогательная функция для чтения целого числа из sysfs
static int read_sysfs_int(const char* ifname, const char* path_suffix, int* out_value) {
    char path[256];
    snprintf(path, sizeof(path), "/sys/class/net/%s/%s", ifname, path_suffix);
    
    FILE* fp = fopen(path, "r");
    if (!fp) return -1;
    
    int res = fscanf(fp, "%d", out_value);
    fclose(fp);
    
    return (res == 1) ? 0 : -1;
}

int get_hardware_chliv(int port_idx) {
    char ifname[16];
    get_hardware_ifname(port_idx, ifname, sizeof(ifname));
    
    if (!is_port_present(port_idx)) return -1;

    int carrier = 0;
    // carrier: 1 = link up (канал жив), 0 = link down
    if (read_sysfs_int(ifname, "carrier", &carrier) == 0) {
        return carrier;
    }
    return -1;
}

int get_hardware_redchliv(int port_idx) {

    return get_hardware_chliv(port_idx); 
}