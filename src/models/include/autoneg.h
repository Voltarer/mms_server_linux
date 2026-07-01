#ifndef AUTONEG_H
#define AUTONEG_H

/**
 * Получить состояние автосогласования.
 * @param port_idx  индекс порта
 * @return          1 – включено, 0 – выключено, -1 – ошибка
 */
int get_hardware_autongt(int port_idx);   // имя сохранено как в исходнике

/**
 * Установить автосогласование.
 * @param port_idx         индекс порта
 * @param autongt_enable   1 – включить, 0 – выключить
 * @return                 0 при успехе, -1 при ошибке
 */
int set_autongt(int port_idx, int autongt_enable);

#endif // AUTONEG_H