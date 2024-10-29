#include "i2cspm.h"

void i2c_init()
{
  I2CSPM_Init_TypeDef i2c_init = {
      .port = I2C0,         // Use I2C unit 0
      .sclPort = gpioPortA, // SCL on PA1
      .sclPin = 1,
      .sdaPort = gpioPortA, // SDA on PA0
      .sdaPin = 0,
      .i2cRefFreq = 0,                     // Use currently configured reference clock
      .i2cMaxFreq = I2C_FREQ_STANDARD_MAX, // Standard mode (100kHz)
      .i2cClhr = i2cClockHLRStandard       // Set to standard mode
  };

  // Initialize the I2C peripheral
  I2CSPM_Init(&i2c_init);
}

// Function to send data to a display using I2C
void send_data_to_display(uint8_t display_number, uint16_t data)
{
  I2C_TransferSeq_TypeDef seq;
  uint8_t                 i2c_write_data[3];

  // Set the slave address and set the direction to write
  seq.addr = DISPLAY_DRIVER_ADDRESS << 1; // I2C address in 7-bit form
  seq.flags = I2C_FLAG_WRITE;

  // Prepare data to be sent (register + 16-bit data)
  i2c_write_data[0] = display_number;     // Register for the specific display
  i2c_write_data[1] = (data >> 8) & 0xFF; // High byte of data
  i2c_write_data[2] = data & 0xFF;        // Low byte of data

  // Set the data buffers for the transfer
  seq.buf[0].data = i2c_write_data;
  seq.buf[0].len = 3; // Send 3 bytes

  // Perform the transfer
  I2CSPM_Transfer(I2C0, &seq);
}
