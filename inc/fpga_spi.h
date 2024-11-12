#ifndef FPGA_SPI_H
#define FPGA_SPI_H

#include "transformation.h"
#include <stdint.h>

void fpga_frame_send(MvpMatrixEntry *entries, uint8_t entry_count);

#endif // FPGA_SPI_H
