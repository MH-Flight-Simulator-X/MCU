#ifndef FPGA_H
#define FPGA_H

#include "transformation.h"
#include <stdint.h>

typedef struct
{
  uint8_t flag_id;
  mat4 mvp_matrix;
} MvpMatrixEntry;

void fpga_frame_send(MvpMatrixEntry *entries, uint8_t entry_count, uint32_t frame_counter);
void fpga_reset();

#endif // FPGA_H
