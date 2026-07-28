#include "models/include/mirroring.h"
#include "models/include/common.h"

int get_hardware_mir(int port_idx) {
    if (!is_port_present(port_idx)) return -1;

    return 0; 
}