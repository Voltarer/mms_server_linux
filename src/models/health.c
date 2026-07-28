#include "models/include/health.h"
#include "models/include/common.h"
#include "models/include/channel.h"
#include "models/include/traffic_errors.h"
#include <stdio.h>

int get_hardware_health(int port_idx) {
    if (!is_port_present(port_idx)) return -1;

    int carrier = get_hardware_chliv(port_idx);
    int in_ov = get_hardware_in_ov(port_idx);
    int out_ov = get_hardware_out_ov(port_idx);
    
    // Базовая логика оценки «Здоровья»
    if (carrier == 0) {
        return 2; // Warning: Линк упал (можно расценивать и как Alarm(3) в зависимости от ТЗ)
    }
    
    if (in_ov == 1 || out_ov == 1) {
        return 2; // Warning: Идут потери пакетов
    }

    return 1; // 1 = Ok
}

int get_hardware_beh(int port_idx) {
    if (!is_port_present(port_idx)) return -1;
    
    // В IEC 61850 Behaviour: 1(on), 2(blocked), 3(test), 4(test/blocked), 5(off)
    // В простейшем случае, если порт админски поднят, он "on", иначе "off".
    char ifname[16];
    get_hardware_ifname(port_idx, ifname, sizeof(ifname));
    
    char path[256];
    snprintf(path, sizeof(path), "/sys/class/net/%s/operstate", ifname);
    
    FILE* fp = fopen(path, "r");
    if (!fp) return 1; // По умолчанию
    
    char state[32] = {0};
    fscanf(fp, "%31s", state);
    fclose(fp);
    
    // Если админски опущен (down), возвращаем off (5), иначе on (1)
    if (state[0] == 'd' && state[1] == 'o') {
        return 5; // off
    }
    return 1; // on
}