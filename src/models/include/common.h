#ifndef COMMON_H
#define COMMON_H

#include <stddef.h>   // size_t
#include <stdbool.h>  // bool (необходимо для функции проверки наличия порта)

/**
 * Выполняет сканирование сетевых интерфейсов в Linux (через getifaddrs),
 * отбирает подходящие порты (lanX, opticalX) и сопоставляет их с индексами MMS.
 */
void discover_hardware_ports(void);

/**
 * Проверяет, был ли успешно обнаружен физический интерфейс для данного индекса.
 * Возвращает true, если интерфейс существует, и false, если отсутствует.
 */
bool is_port_present(int port_idx);

/**
 * Заполняет буфер dest реальным именем интерфейса для заданного индекса порта.
 * Если интерфейс для этого индекса не был найден в системе, запишет "unknown".
 */
void get_hardware_ifname(int port_idx, char* dest, size_t max_len);

#endif // COMMON_H