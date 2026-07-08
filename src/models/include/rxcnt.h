#ifndef MODELS_INCLUDE_RXCNT_H
#define MODELS_INCLUDE_RXCNT_H

#include <stdint.h>

/**
 * Получить реальное значение счетчика принятых пакетов из sysfs Linux.
 * @param port_idx Индекс порта (0 .. NUM_PORTS-1)
 * @return Количество принятых пакетов или -1 в случае ошибки чтения.
 */
int64_t get_hardware_rx_cnt(int port_idx);

#endif // MODELS_INCLUDE_RXCNT_H