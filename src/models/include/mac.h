#ifndef MAC_H
#define MAC_H

#include <stddef.h>   // size_t

/**
 * Получить MAC-адрес порта в виде строки "XX:XX:XX:XX:XX:XX".
 * @param port_idx  индекс порта
 * @param mac_str   буфер для строки (должен быть не менее 18 байт)
 * @param max_len   размер буфера
 * @return          0 при успехе, -1 при ошибке
 */
int get_hardware_mac_address(int port_idx, char* mac_str, size_t max_len);

#endif // MAC_H