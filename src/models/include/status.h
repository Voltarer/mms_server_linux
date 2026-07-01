#ifndef STATUS_H
#define STATUS_H

/**
 * Получить статус физического соединения (carrier).
 * @param port_idx  индекс порта (0-based)
 * @return          1 – link up, 2 – link down, -1 – ошибка
 */
int get_hardware_port_status(int port_idx);

/**
 * Получить административный статус интерфейса (UP/DOWN).
 * @param port_idx  индекс порта
 * @return          1 – UP, 0 – DOWN, -1 – ошибка
 */
int get_hardware_admin_status(int port_idx);

/**
 * Установить административный статус интерфейса.
 * @param port_idx  индекс порта
 * @param enable    1 – UP, 0 – DOWN
 * @return          0 при успехе, -1 при ошибке
 */
int set_hardware_port_status(int port_idx, int enable);

#endif // STATUS_H