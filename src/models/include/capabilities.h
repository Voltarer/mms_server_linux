#ifndef CAPABILITIES_H
#define CAPABILITIES_H

#include <stdint.h>   // int32_t

/**
 * Получить битовую маску поддерживаемых режимов.
 * Биты: 0 – 10baseT/Half, 1 – 10baseT/Full, 2 – 100baseT/Half,
 *       3 – 100baseT/Full, 4 – 1000baseT/Half, 5 – 1000baseT/Full.
 * @param port_idx  индекс порта
 * @return          битовая маска или -1 при ошибке
 */
int32_t get_hardware_capabilities(int port_idx);

/**
 * Вывести на печать строку с перечислением поддерживаемых режимов.
 * @param port_idx  индекс порта
 */
void print_hardware_capabilities_string(int port_idx);

#endif // CAPABILITIES_H