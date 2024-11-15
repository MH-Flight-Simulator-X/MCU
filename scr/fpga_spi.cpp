#include "fpga_spi.h"
#include "transformation.h"
#include "fixedpoint.h"
#include "spi.h"
#include "debug.h"
#include <string.h>

void convert_float_to_fixedpoint_bytes(float value, uint8_t *buffer)
{
  fp fixed_value = fl2fp(value);
  buffer[0] = (fixed_value >> 16) & 0xFF;
  buffer[1] = (fixed_value >> 8) & 0xFF;
  buffer[2] = fixed_value & 0xFF;
}
float convert_fixedpoint_bytes_to_float(const uint8_t *buffer)
{
  int32_t fixed_value = (buffer[0] << 16) | (buffer[1] << 8) | buffer[2];
  if (fixed_value & (1 << 23))
  {
    fixed_value |= 0xFF000000;
  }
  return fp2fl(fixed_value);
}

void print_buffer(uint8_t *buffer, int size)
{
  uint8_t entry_count = buffer[0];
  debug_printf("Entry count: %d\n", entry_count);
  int offset = 1;

  for (uint8_t entry = 0; entry < entry_count; entry++)
  {
    if (offset >= size)
      break;

    // Print the entry number and flag ID
    debug_printf("\nEntry %d:\n", entry);
    debug_printf("  Flag ID: 0x%02X\n", buffer[offset]);
    offset += 1;

    debug_printf("  Matrix:\n");
    // Iterate over the 4x4 matrix
    for (int row = 0; row < 4; row++)
    {
      for (int col = 0; col < 4; col++)
      {
        if (offset + 2 >= size)
          break;

        float value = convert_fixedpoint_bytes_to_float(&buffer[offset]);
        char str[20];
        float_to_string(str, sizeof(str), value);

        debug_printf("    %s ", str);

        // Move the offset forward by 3 bytes
        offset += 3;
      }
      debug_printf("\n");
    }
  }

  debug_printf("\nBuffer (Hex Dump):\n");
  for (int i = 0; i < size; i++)
  {
    debug_printf("0x%02X ", buffer[i]);
    if ((i + 1) % 8 == 0)
    {
      debug_printf("\n");
    }
  }
  debug_printf("\n");
}

void fpga_frame_send(MvpMatrixEntry *entries, uint8_t entry_count)
{
  const int entry_size = 1 + 16 * 3;
  const int total_size = 1 + entry_count * entry_size;

  uint8_t buffer[total_size];
  memset(buffer, 0, total_size);

  buffer[0] = entry_count;

  for (uint8_t n = 0; n < entry_count; n++)
  {
    int offset = 1 + n * entry_size;
    buffer[offset] = entries[n].flag_id;
    offset += 1;

    for (int i = 0; i < 4; i++)
    {
      for (int j = 0; j < 4; j++)
      {
        convert_float_to_fixedpoint_bytes(entries[n].mvp_matrix[i][j], &buffer[offset]);
        offset += 3;
      }
    }
  }
  spi_transfer(buffer, total_size);
//  print_buffer(buffer, total_size);
}
