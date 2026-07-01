#ifndef FLOW_CONTROL_H
#define FLOW_CONTROL_H

/**
 * Получить состояние управления потоком (RX или TX паузы).
 * @param port_idx  индекс порта
 * @return          1 – включено, 0 – выключено, -1 – ошибка
 */
int get_hardware_flow_control(int port_idx);

/**
 * Установить управление потоком (включает и RX, и TX паузы).
 * @param port_idx  индекс порта
 * @param enable    1 – включить, 0 – выключить
 * @return          0 при успехе, -1 при ошибке
 */
int set_hardware_flow_control(int port_idx, int enable);

#endif // FLOW_CONTROL_H