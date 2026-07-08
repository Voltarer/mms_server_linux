#include "models/include/txcnt.h"
#include "models/include/common.h"
#include <stdio.h>
#include <stdlib.h>

int64_t get_hardware_tx_cnt(int port_idx) {
    // Проверяем, существует ли интерфейс в системе
    if (!is_port_present(port_idx)) {
        return -1;
    }

    char ifname[16];

    get_hardware_ifname(port_idx, ifname, sizeof(ifname));

    char path[128];

    snprintf(path, sizeof(path), "/sys/class/net/%s/statistics/tx_packets", ifname);

    FILE* fp = fopen(path, "r");
    if (!fp) {
        return -1;
    }

    int64_t cnt = 0;
    if (fscanf(fp, "%lld", (long long*)&cnt) != 1) {
        fclose(fp);
        return -1;
    }

    fclose(fp);
    return cnt;
}