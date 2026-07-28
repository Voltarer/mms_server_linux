#ifndef MIRRORING_H
#define MIRRORING_H
#include <stdint.h>

// Возвращает 1 (Зеркалирование активно), 0 (Выключено) или -1
int get_hardware_mir(int port_idx);

#endif // MIRRORING_H