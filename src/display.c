#include "sl_i2cspm_instances.h"
#include "sl_simple_led_instances.h"
#include "sl_simple_led.h"
#include "aircraft.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *string;
int display_counter;
Aircraft *aircraft_pointer;

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

  I2CSPM_Transfer(sl_i2cspm_display, &seq);
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

  I2CSPM_Transfer(sl_i2cspm_display, &seq);
}

void display_clear(void)
{
  display_write_single_data(0x60, 0b00100000);
  display_write_single_data(0x61, 0b00100000);
  display_write_single_data(0x62, 0b00100000);
  display_write_single_data(0x63, 0b00100000);
  display_write_single_data(0x64, 0b00100000);
  display_write_single_data(0x65, 0b00100000);
}

void display_print_string()
{
  display_clear();

  int len = strlen(string);
  uint8_t ascii_values[len];
  int i = 0;
  while (string[i] != '\0')
  {
    ascii_values[i] = (int)string[i];
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

void float_to(char *buffer, size_t size, double number)
{

  char tempBuffer[50];
  float_to_string(tempBuffer);

  char *dot = strchr(tempBuffer, '.');
  if (dot)
  {
    int intPartLen = dot - tempBuffer;               // Length of the integer part
    char lastDigitChar = tempBuffer[intPartLen - 1]; // Get the last digit

    uint8_t lastDigit = (uint8_t)lastDigitChar; // Convert to numeric

    uint8_t modifiedDigit = lastDigit | 0b10000000; // Set MSB

    tempBuffer[intPartLen - 1] = (char)modifiedDigit;

    memmove(&tempBuffer[intPartLen], &tempBuffer[intPartLen + 1], strlen(tempBuffer) - intPartLen);
  }

  if (number < 0)
  {
    snprintf(buffer, size, "%s", tempBuffer);
  }
  else
  {
    snprintf(buffer, size, "%s", tempBuffer);
  }
}

void display_set_number()
{

  double num = display_counter == 0   ? aircraft_pointer->pitch
               : display_counter == 1 ? aircraft_pointer->roll
               : display_counter == 2 ? aircraft_pointer->speed
                                      : 0;

  char value[50];
  float_to(value, sizeof(value), num);
  value[4] = 0b00010000;
  value[5] = display_counter == 0   ? 0b01110000
             : display_counter == 1 ? 0b01110010
             : display_counter == 2 ? 0b01010011
                                    : 0;

  display_set_string(value);
}

void display_init(Aircraft *aircraft)
{
  aircraft_pointer = aircraft;
  sl_i2cspm_init_instances();
  display_counter = 0;
  display_write_single_data(0x07, 0x00); // Ensure test mode is turned off
  display_write_single_data(0x04, 0x01); // Turn off standby modus
  display_write_single_data(0x02, 0x0F); // Set max brightness
  display_write_single_data(0x03, 0x05); // Only display 5 digits
  display_write_single_data(0x0C, 0x00); // Set all digits to be 16 segment displays (Can be removed)
  display_write_single_data(0x01, 0xFF); // Ensure decode mode is on (Can be removed)
}

void display_toggle_display(void)
{

  display_counter = (display_counter + 1) % 3;
}
