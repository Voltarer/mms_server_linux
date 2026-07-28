#ifndef CAPABILITIES_H
#define CAPABILITIES_H

#include <stdint.h>   // int32_t

/**
 * Получить максимальный поддерживаемый режим по стандарту RFC 4836 (dot3MauType).
 * Возвращает константу типа MAU (например, 30 для 1000BaseT-FD, 16 для 100BaseTX-FD).
 * @param port_idx  индекс порта
 * @return          значение MAU Type (RFC 4836) или -1 при ошибке
 */
int32_t get_hardware_capabilities(int port_idx);

/**
 * Вывести на печать строку с перечислением поддерживаемых физических режимов.
 * @param port_idx  индекс порта
 */
void print_hardware_capabilities_string(int port_idx);

#endif // CAPABILITIES_H