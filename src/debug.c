#include "debug.h"
#include "sl_debug_swo.h"
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>

/*********************************************************************************************
 * @file debug.h
 * @brief Debug utilities for SWO (Serial Wire Output) based debugging
 *
 * This file provides functions for debug output through SWO interface,
 * commonly used in ARM Cortex-M debugging. It includes utilities for
 * printing strings, formatted text, and floating-point numbers.
 *********************************************************************************************/

/*********************************************************************************************
 * @brief Writes a string to the SWO debug output
 * @param str Null-terminated string to output
 *
 * Outputs each character of the string through SWO channel 0
 *********************************************************************************************/
void debug_print(const char *str)
{
  for (size_t i = 0; i < strlen(str); i++)
  {
    sl_debug_swo_write_u8(0, str[i]);
  }
}

/*********************************************************************************************
 * @brief Prints formatted text followed by a newline
 * @param format Printf-style format string
 * @param ... Variable arguments matching format string
 *
 * Combines debug_printf() functionality with automatic newline
 *********************************************************************************************/
void debug_println(const char *format, ...)
{
  va_list args;
  debug_printf(format, args);
  debug_print("\n");
}

/*********************************************************************************************
 * @brief Converts a floating-point number to string representation
 * @param buffer Output buffer to store the resulting string
 * @param size Size of the output buffer
 * @param number Floating-point number to convert
 *
 * Converts number to string with 4 decimal places of precision
 * Handles negative numbers and includes a trailing space
 *********************************************************************************************/
void float_to_string(char *buffer, size_t size, float number)
{
  int integerPart = fabs((int)number);
  float fractionalPart = fabs(number - integerPart);
  int fractionalInt = (int)(fractionalPart * 10000 + 0.5);

  snprintf(buffer, size, "%s%d.%04d ", number < 0 ? "-" : "", integerPart, fractionalInt);
}

/*********************************************************************************************
 * @brief Prints formatted text to SWO debug output
 * @param format Printf-style format string
 * @param ... Variable arguments matching format string
 *
 * Provides printf-like formatting with output through SWO
 * Limited to 512 characters of output
 *********************************************************************************************/
void debug_printf(const char *format, ...)
{
  char buffer[512];

  va_list args;
  va_start(args, format);

  vsnprintf(buffer, sizeof(buffer), format, args);

  va_end(args);

  debug_print(buffer);
}

/*********************************************************************************************
 * @brief Prints a floating-point number to SWO debug output
 * @param num Number to print
 *
 * Converts the number to string and outputs it with 4 decimal places
 *********************************************************************************************/
void debug_print_float(float num)
{
  char value[50];
  float_to_string(value, sizeof(value), num);
  debug_printf("%s", value);
}
