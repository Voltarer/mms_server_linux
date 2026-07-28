#ifndef TRAFFIC_ERRORS_H
#define TRAFFIC_ERRORS_H
#include <stdint.h>

// Возвращает 1 (Переполнение), 0 (Норма) или -1
int get_hardware_in_ov(int port_idx);
int get_hardware_out_ov(int port_idx);

// Возвращает частоту ошибок (Frame Error Rate) или -1
int32_t get_hardware_fer_port(int port_idx);

#endif // TRAFFIC_ERRORS_H