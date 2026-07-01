#ifndef COMMON_H
#define COMMON_H

#include <stddef.h>   // size_t

/**
 * Заполняет буфер именем интерфейса для заданного индекса порта.
 * Формат: "lan%d" (индекс + 1).
 */
void get_hardware_ifname(int port_idx, char* dest, size_t max_len);

#endif // COMMON_H