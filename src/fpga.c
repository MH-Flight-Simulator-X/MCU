#include <fpga.h>
#include "transformation.h"
#include "fixedpoint.h"
#include "debug.h"
#include <string.h>
#include "em_gpio.h"
#include "sl_emlib_gpio_init_FPGA_Reset_config.h"
#include "spidrv.h"
#include "sl_spidrv_instances.h"


/*********************************************************************************************
 * @file fpga.c
 * @brief Implementation of FPGA communication interface
 *********************************************************************************************/

/*********************************************************************************************
 * @brief Converts a floating-point value to a 3-byte fixed-point representation
 *
 * Uses 8.16 fixed-point format:
 * - 8 bits for integer part
 * - 16 bits for fractional part
 * - Total of 24 bits stored in 3 bytes
 *********************************************************************************************/
void convert_float_to_fixedpoint_bytes(float value, uint8_t *buffer)
{
  fp fixed_value = fl2fp(value);
  buffer[0] = (fixed_value >> 16) & 0xFF; // Most significant byte
  buffer[1] = (fixed_value >> 8) & 0xFF;  // Middle byte
  buffer[2] = fixed_value & 0xFF;         // Least significant byte
}

/*********************************************************************************************
 * @brief Converts a 3-byte fixed-point representation back to float
 *
 * Handles sign extension for negative numbers by checking bit 23
 * and filling the upper byte with 1's if necessary
 *********************************************************************************************/
float convert_fixedpoint_bytes_to_float(const uint8_t *buffer)
{
  int32_t fixed_value = (buffer[0] << 16) | (buffer[1] << 8) | buffer[2];
  if (fixed_value & (1 << 23)) // Check sign bit
  {
    fixed_value |= 0xFF000000; // Sign extend to 32 bits
  }
  return fp2fl(fixed_value);
}

/*********************************************************************************************
 * @brief Debug utility to print buffer contents in human-readable format
 *
 * Prints the matrix entries with the following format:
 * - Entry count
 * - For each entry:
 *   - Flag ID
 *   - 4x4 matrix values in human-readable float format
 * - Optional hexadecimal dump of the entire buffer
 *********************************************************************************************/
void print_buffer(uint8_t *buffer, int size, bool hexdump)
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

  if (hexdump)
  {
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
}

/*********************************************************************************************
 * @brief Sends a frame of transformation matrices to the FPGA
 *
 * Protocol format:
 * Byte 0: Number of matrix entries
 * For each entry:
 *   Byte 0: Flag ID
 *   Bytes 1-48: Matrix data (16 elements × 3 bytes per element)
 *   Matrix is stored in column-major order for FPGA processing
 *
 * Debug output is printed every 30 frames if frame_counter is provided
 *********************************************************************************************/
void fpga_frame_send(MvpMatrixEntry *entries, uint8_t entry_count, uint32_t frame_counter)
{

  const int entry_size = 1 + 16 * 3;
  const int total_size = 1 + (entry_count)*entry_size;

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
        convert_float_to_fixedpoint_bytes(entries[n].mvp_matrix[j][i], &buffer[offset]);
        offset += 3;
      }
    }
  }
  spi_transfer(buffer, total_size);
  if (frame_counter % 30 == 0)
    print_buffer(buffer, total_size, 0);
}

/*********************************************************************************************
 * @brief Performs a hardware reset of the FPGA
 *
 * Reset sequence:
 * 1. Assert reset pin low
 * 2. Assert reset pin high
 *
 * Uses GPIO pins defined in FPGA_Reset_config
 *********************************************************************************************/
void fpga_reset()
{
  GPIO_PinOutClear(SL_EMLIB_GPIO_INIT_FPGA_RESET_PORT, SL_EMLIB_GPIO_INIT_FPGA_RESET_PIN);
  GPIO_PinOutSet(SL_EMLIB_GPIO_INIT_FPGA_RESET_PORT, SL_EMLIB_GPIO_INIT_FPGA_RESET_PIN);
}

/*********************************************************************************************
 * @brief Initializes the SPI interface
 *
 * Initializes all SPI driver instances using the Silicon Labs SPIDRV
 * initialization function. This must be called before any SPI transfers
 * can occur.
 *********************************************************************************************/
void spi_init(void)
{
  sl_spidrv_init_instances();
}

/*********************************************************************************************
 * @brief Performs a blocking SPI transfer
 *
 * @param buffer      Pointer to the data buffer to transmit
 * @param byte_count  Number of bytes to transfer
 *
 * @note This function performs a blocking transmit operation. If the transfer
 *       fails, a debug message will be printed.
 *
 * @warning The buffer must be valid and contain at least byte_count bytes
 *********************************************************************************************/
void spi_transfer(void *buffer, int byte_count)
{
  Ecode_t ecode = SPIDRV_MTransmitB(FPGA_SPI_INSTANCE, buffer, byte_count);
  if (ecode != ECODE_EMDRV_SPIDRV_OK)
    debug_print("Something went wrong with SPI transfer\n");
}
