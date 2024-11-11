#include "sl_i2cspm_instances.h"
#include "sl_simple_led_instances.h"
#include "sl_simple_led.h"
#include <stddef.h>

uint8_t chars[6] = {0x46, 0x55, 0x43, 0x4B, 0x10, 0x10};

void display_write_data(uint8_t reg, uint8_t command)
{
  I2C_TransferSeq_TypeDef seq;
  seq.addr = 0b11000000;
  seq.flags = I2C_FLAG_WRITE;

  // input
  uint8_t data[2];
  data[0] = reg;
  data[1] = command;
  seq.buf[0].data = data;
  seq.buf[0].len = 2;

  // output
  seq.buf[1].data = NULL;
  seq.buf[1].len = 0;

  I2C_TransferReturn_TypeDef res = I2CSPM_Transfer(sl_i2cspm_display, &seq);
  /*
  if (res < 0)
  {
    sl_led_turn_on(&sl_led_led1);
  }
  else
  {
    sl_led_turn_on(&sl_led_led0);
  }
  */
}

void display_init(void)
{
  sl_i2cspm_init_instances();

  display_write_data(0x07, 0x00); // Ensure test mode is turned off
  display_write_data(0x04, 0x01); // Turn off standby modus
  display_write_data(0x02, 0x0F); // Set max brightness
  display_write_data(0x03, 0x05); // Only display 5 digits
  display_write_data(0x0C, 0x00); // Set all digits to be 16 segment displays (Can be removed)
  display_write_data(0x01, 0xFF); // Ensure decode mode is on (Can be removed)

  display_write_data(0x60, 0b10000111);
  display_write_data(0x61, 0b10000111);
  display_write_data(0x62, 0b10100000);
  display_write_data(0x63, 0b10100000);
  display_write_data(0x64, 0b10100000);
  display_write_data(0x65, 0b10100000);
}

void display_print_testing(int iteration)
{
  display_write_data(0x60, chars[6 % iteration]);
  display_write_data(0x61, chars[6 % iteration + 1]);
  display_write_data(0x62, chars[6 % iteration + 2]);
  display_write_data(0x63, chars[6 % iteration + 3]);
  display_write_data(0x64, chars[6 % iteration + 4]);
  display_write_data(0x65, chars[6 % iteration + 5]);
}
