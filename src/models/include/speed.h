#ifndef SPEED_H
#define SPEED_H

/**
 * Получить текущий режим работы порта в виде MAU Type (RFC 4836).
 * @param port_idx  индекс порта
 * @return          код MAU Type (например, 11, 14, 15, 16, 29, 30) или -1 при ошибке
 */
int get_hardware_port_speed(int port_idx);

/**
 * Установить скорость и дуплекс порта через код MAU Type (RFC 4836).
 * @param port_idx  индекс порта
 * @param mau_type  код типа среды (11, 14, 15, 16, 29, 30)
 * @return          0 при успехе, -1 при ошибке
 */
int set_hardware_port_speed(int port_idx, int mau_type);

#endif // SPEED_H