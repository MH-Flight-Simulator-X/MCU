#include "sl_i2cspm_instances.h"
#include "sl_simple_led_instances.h"
#include "sl_simple_led.h"
#include "aircraft.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*********************************************************************************************
 * @file display.c
 * @brief Driver for controlling a 16-segment I2C LED display module
 *
 * This file implements a driver for controlling a 6-digit 16-segment LED display via I2C.
 * It provides functionality for displaying aircraft telemetry data (pitch, roll, speed)
 * with proper decimal point formatting and text scrolling capabilities.
 * 
 * Key features:
 * - I2C communication (address 0xC0)
 * - Three display modes for aircraft parameters
 * - Dynamic string handling with scrolling
 * - Decimal point formatting for numeric values
 * - Configurable brightness and power modes
 *********************************************************************************************/


char *string;
int display_counter;
Aircraft *aircraft_pointer;

/*********************************************************************************************
 * @brief Writes a single command byte to a specific register on the display
 * @param reg The register address to write to (0x00-0xFF)
 * @param command The command byte to write
 *********************************************************************************************/
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

/*********************************************************************************************
 * @brief Writes multiple bytes of data to consecutive registers starting at 0x60
 * @param command Pointer to array of bytes to write (expects 6 bytes)
 * @details Writes to registers 0x60-0x65, which control individual display digits
 *********************************************************************************************/
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

/*********************************************************************************************
 * @brief Clears all segments on the display
 * @details Writes 0x20 (blank) to registers 0x60-0x65
 *********************************************************************************************/
void display_clear(void)
{
  display_write_single_data(0x60, 0b00100000);
  display_write_single_data(0x61, 0b00100000);
  display_write_single_data(0x62, 0b00100000);
  display_write_single_data(0x63, 0b00100000);
  display_write_single_data(0x64, 0b00100000);
  display_write_single_data(0x65, 0b00100000);
}

/*********************************************************************************************
 * @brief Displays the current string on the LED display
 * @details Converts the global string to ASCII values and writes to display
 *********************************************************************************************/
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

/*********************************************************************************************
 * @brief Displays string and rotates it one position left
 * @details Used for scrolling text effect. First character moves to end of string
 *********************************************************************************************/
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

/*********************************************************************************************
 * @brief Updates the global string variable with new content
 * @param str New string to be displayed
 * @details Reallocates memory for string and copies new content
 *********************************************************************************************/
void display_set_string(char str[])
{
  string = (char *)realloc(string, strlen(str) * sizeof(char));
  strcpy(string, str);
}

/*********************************************************************************************
 * @brief Converts float number to display-friendly string format
 * @param buffer Output buffer for converted string
 * @param size Size of output buffer
 * @param number Float number to convert
 * @details Sets MSB of digit before decimal point for decimal point display
 *********************************************************************************************/
void float_to(char *buffer, size_t size, float number)
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

/*********************************************************************************************
 * @brief Updates display with current aircraft parameter value
 * @details Displays either pitch, roll, or speed based on display_counter:
 *          - 0: Pitch
 *          - 1: Roll
 *          - 2: Speed
 *          Formats number with appropriate decimal point and unit indicator
 *********************************************************************************************/
void display_set_number()
{

  float num = display_counter == 0   ? aircraft_pointer->pitch
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

/*********************************************************************************************
 * @brief Initializes the display module
 * @param aircraft Pointer to Aircraft structure containing flight data
 * @details Configures:
 *          - Test mode off
 *          - Standby mode off
 *          - Maximum brightness
 *          - 5-digit display
 *          - 16-segment mode
 *          - Decode mode on
 *********************************************************************************************/
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

/*********************************************************************************************
 * @brief Cycles through display modes
 * @details Increments display_counter (0->1->2->0) to switch between:
 *          - Pitch display
 *          - Roll display
 *          - Speed display
 *********************************************************************************************/
void display_toggle_display(void)
{

  display_counter = (display_counter + 1) % 3;
}

