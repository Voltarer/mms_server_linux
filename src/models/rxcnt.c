#include "models/include/rxcnt.h"
#include "models/include/common.h"
#include <stdio.h>
#include <stdlib.h>

int64_t get_hardware_rx_cnt(int port_idx) {
    // Проверяем, существует ли интерфейс в системе
    if (!is_port_present(port_idx)) {
        return -1;
    }

    char ifname[16];

    get_hardware_ifname(port_idx, ifname, sizeof(ifname));

    char path[128];

    snprintf(path, sizeof(path), "/sys/class/net/%s/statistics/rx_packets", ifname);

    FILE* fp = fopen(path, "r");
    if (!fp) {
        return -1; // Возвращаем ошибку, если нет доступа к файлу
    }

    int64_t cnt = 0;
    if (fscanf(fp, "%lld", (long long*)&cnt) != 1) {
        fclose(fp);
        return -1; // Ошибка парсинга значения
    }

    fclose(fp);
    return cnt;
}