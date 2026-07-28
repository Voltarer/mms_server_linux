#include "models/include/traffic_errors.h"
#include "models/include/common.h"
#include <stdio.h>

// Аналогичная вспомогательная функция чтения (можно вынести в common.c для красоты)
static int read_net_stat(const char* ifname, const char* stat_name, long long* out_value) {
    char path[256];
    snprintf(path, sizeof(path), "/sys/class/net/%s/statistics/%s", ifname, stat_name);
    
    FILE* fp = fopen(path, "r");
    if (!fp) return -1;
    
    int res = fscanf(fp, "%lld", out_value);
    fclose(fp);
    
    return (res == 1) ? 0 : -1;
}

int get_hardware_in_ov(int port_idx) {
    char ifname[16];
    get_hardware_ifname(port_idx, ifname, sizeof(ifname));
    if (!is_port_present(port_idx)) return -1;

    long long rx_dropped = 0;
    if (read_net_stat(ifname, "rx_dropped", &rx_dropped) == 0) {
        // Если счетчик дропов больше 0, значит были переполнения на входе
        return (rx_dropped > 0) ? 1 : 0;
    }
    return -1;
}

int get_hardware_out_ov(int port_idx) {
    char ifname[16];
    get_hardware_ifname(port_idx, ifname, sizeof(ifname));
    if (!is_port_present(port_idx)) return -1;

    long long tx_dropped = 0;
    if (read_net_stat(ifname, "tx_dropped", &tx_dropped) == 0) {
        // Если счетчик дропов больше 0, значит были переполнения на выходе
        return (tx_dropped > 0) ? 1 : 0;
    }
    return -1;
}

int32_t get_hardware_fer_port(int port_idx) {
    char ifname[16];
    get_hardware_ifname(port_idx, ifname, sizeof(ifname));
    if (!is_port_present(port_idx)) return -1;

    long long rx_errors = 0;
    long long rx_crc_errors = 0;
    
    // Суммируем общие ошибки и CRC ошибки фреймов
    if (read_net_stat(ifname, "rx_errors", &rx_errors) == 0) {
        read_net_stat(ifname, "rx_crc_errors", &rx_crc_errors); // игнорируем ошибку чтения CRC
        
        // Здесь мы просто возвращаем накопленное количество ошибок как INT32.
        return (int32_t)(rx_errors + rx_crc_errors); 
    }
    return -1;
}