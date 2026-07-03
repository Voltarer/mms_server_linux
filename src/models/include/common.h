#ifndef COMMON_H
#define COMMON_H

#include <stddef.h>   // size_t
#include <stdbool.h>  // bool

/**
 * Вариант А: Статическое сопоставление индексов и имен интерфейсов.
 * Заполняет буфер dest точным именем интерфейса для заданного индекса порта.
 * Индексы 0..23 -> lan0..lan23
 * Индексы 24..27 -> optical0..optical3
 */
void get_hardware_ifname(int port_idx, char* dest, size_t max_len);

/**
 * Проверяет физическое существование интерфейса в операционной системе Linux.
 * Возвращает true, если интерфейс существует, и false, если отсутствует.
 */
bool is_port_present(int port_idx);

#endif // COMMON_H