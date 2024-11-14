#ifndef FPGA_SPI_H
#define FPGA_SPI_H

#include "transformation.h"
#include <stdint.h>

typedef struct
{
  uint8_t flag_id;
  mat4 mvp_matrix;
} MvpMatrixEntry;

void fpga_frame_send(MvpMatrixEntry *entries, uint8_t entry_count);

#endif // FPGA_SPI_H
