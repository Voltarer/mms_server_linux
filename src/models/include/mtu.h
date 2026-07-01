#ifndef MTU_H
#define MTU_H

#include <stddef.h>   // для size_t

/**
 * Получить текущее значение MTU для порта.
 * @param port_idx  индекс порта (0-based)
 * @return          MTU в байтах или -1 при ошибке
 */
int get_hardware_mtu(int port_idx);

/**
 * Установить MTU для порта.
 * @param port_idx   индекс порта
 * @param mtu_value  новое значение MTU
 * @return           0 при успехе, -1 при ошибке
 */
int set_hardware_mtu(int port_idx, int mtu_value);

#endif // MTU_H