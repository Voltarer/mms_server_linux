#ifndef CHANNEL_H
#define CHANNEL_H
#include <stdint.h>

// Возвращает 1 (Live), 0 (Down) или -1 (Ошибка)
int get_hardware_chliv(int port_idx);
int get_hardware_redchliv(int port_idx);

#endif // CHANNEL_H