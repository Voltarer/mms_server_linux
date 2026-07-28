#ifndef HEALTH_H
#define HEALTH_H
#include <stdint.h>

// Возвращает HealthKind: 1 (Ok), 2 (Warning), 3 (Alarm) или -1
int get_hardware_health(int port_idx);

// Возвращает BehaviourModeKind: 1 (on), 2 (blocked), 3 (test), 4 (test/blocked), 5 (off) или -1
int get_hardware_beh(int port_idx);

#endif // HEALTH_H