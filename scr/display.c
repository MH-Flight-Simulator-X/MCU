#include "sl_i2cspm_instances.h"
#include "sl_simple_led_instances.h"
#include "sl_simple_led.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

uint8_t display_clear = 0b00100000;
char *string;

void display_write_single_data(uint8_t reg, uint8_t command)
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

void display_write_data(uint8_t *command)
{
  I2C_TransferSeq_TypeDef seq;
  seq.addr = 0b11000000;
  seq.flags = I2C_FLAG_WRITE;

  // input
  uint8_t data[7];
  data[0] = 0x60;
  for (int i = 1; i <= 6; i++)
  {
    data[i] = command[i - 1];
  }
  seq.buf[0].data = data;
  seq.buf[0].len = 7;

  // output
  seq.buf[1].data = NULL;
  seq.buf[1].len = 0;

  I2C_TransferReturn_TypeDef res = I2CSPM_Transfer(sl_i2cspm_display, &seq);
}

void display_print_string(char str[])
{

  display_write_single_data(0x60, display_clear);
  display_write_single_data(0x61, display_clear);
  display_write_single_data(0x62, display_clear);
  display_write_single_data(0x63, display_clear);
  display_write_single_data(0x64, display_clear);
  display_write_single_data(0x65, display_clear);

  int len = strlen(str);
  uint8_t ascii_values[len];
  int i = 0;
  while (str[i] != '\0')
  {
    ascii_values[i] = (int)str[i];
    i++;
  }
  display_write_data(ascii_values);
}

void display_print_and_rotate_string(void)
{
  int len = strlen(string);

  display_print_string(string);
  char first_char = string[0];
  for (int i = 0; i < len - 1; i++)
  {
    string[i] = string[i + 1];
  }
  string[len - 1] = first_char;

}

void display_set_string(char str[])
{
  string = (char *)realloc(string, strlen(str) * sizeof(char));
  strcpy(string, str);
}

void display_init(void)
{
  string = (char *)malloc(36 * sizeof(char));
  strcpy(string, "WELCOME TO FLYING FUCKING SIMULATOR. FASTEN YOUR SEATBELTS ");

  display_set_string("FUCK YOU 1234 ");

  sl_i2cspm_init_instances();

  display_write_single_data(0x07, 0x00); // Ensure test mode is turned off
  display_write_single_data(0x04, 0x01); // Turn off standby modus
  display_write_single_data(0x02, 0x0F); // Set max brightness
  display_write_single_data(0x03, 0x05); // Only display 5 digits
  display_write_single_data(0x0C, 0x00); // Set all digits to be 16 segment displays (Can be removed)
  display_write_single_data(0x01, 0xFF); // Ensure decode mode is on (Can be removed)
}

// long double num = 123.4567890123456789L;
// char str[100];  // Allocate enough space for the string

// // Convert long double to string with 15 decimal places
//  double double_num = (double) num;

// // Use snprintf to format the double as a string
// snprintf(str, sizeof(str), "%.8f", double_num);
// display_print_string("2.54");
