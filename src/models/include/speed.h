#ifndef SPEED_H
#define SPEED_H

/**
 * Получить текущую скорость порта (в Мбит/с).
 * @param port_idx  индекс порта
 * @return          скорость (10, 100, 1000) или -1 при ошибке
 */
int get_hardware_port_speed(int port_idx);

/**
 * Установить скорость и дуплекс.
 * @param port_idx  индекс порта
 * @param mode_val  код режима (1 – 10/Half, 2 – 10/Full, 4 – 100/Half,
 *                  8 – 100/Full, 16 – 1000/Half, 32 – 1000/Full,
 *                  также можно передать 10, 100 или 1000 для Full Duplex)
 * @return          0 при успехе, -1 при ошибке
 */
int set_hardware_port_speed(int port_idx, int mode_val);

#endif // SPEED_H