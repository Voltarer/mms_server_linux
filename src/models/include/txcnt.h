#ifndef MODELS_INCLUDE_TXCNT_H
#define MODELS_INCLUDE_TXCNT_H

#include <stdint.h>

/**
 * Получить реальное значение счетчика переданных пакетов из sysfs Linux.
 * @param port_idx Индекс端口 (0 .. NUM_PORTS-1)
 * @return Количество переданных пакетов или -1 в случае ошибки чтения.
 */
int64_t get_hardware_tx_cnt(int port_idx);

#endif // MODELS_INCLUDE_TXCNT_H