#include "debug.h"
#include "sl_debug_swo.h"
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>


void debug_print(const char* str) {
  for (size_t i = 0; i < strlen(str); i++) {
      sl_debug_swo_write_u8(0, str[i]);
  }
}


void debug_println(const char *format, ...) {
  va_list args;
  debug_printf(format, args);
  debug_print("\n");
}

void float_to_string(char *buffer, size_t size, double number) {
  int integerPart = fabs((int)number);
  double fractionalPart = fabs(number - integerPart);
  int fractionalInt = (int)(fractionalPart * 10000 + 0.5);

  snprintf(buffer, size, "%s%d.%04d ", number < 0 ? "-" : "", integerPart, fractionalInt);

}


void debug_printf(const char *format, ...) {
  char buffer[512];

  va_list args;
  va_start(args, format);

  vsnprintf(buffer, sizeof(buffer), format, args);

  va_end(args);

  debug_print(buffer);
}

void debug_print_float(double num){
  char value[50];
  float_to_string(value, sizeof(value), num);
  debug_printf("%s", value);
}
