#include "debug.h"
#include "sl_debug_swo.h"
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>


static char debug_buffer[DEBUG_BUFFER_SIZE];

void debug_print(const char* str) {
  int len = strlen(str);

  if (len >= DEBUG_BUFFER_SIZE) {
    len = DEBUG_BUFFER_SIZE - 1;
    debug_buffer[len - 1] = '\n';
  }
  memcpy(debug_buffer, str, len);
  debug_buffer[len] = '\0';

  for (int i = 0; i < len + 1; i++) {
      sl_debug_swo_write_u8(0, debug_buffer[i]);
  }
}


void debug_println(const char* str) {
  debug_print(str);
  debug_print("\n");
}

void float_to_string(char *buffer, size_t size, double number) {
  int integerPart = fabs((int)number);
  double fractionalPart = fabs(number - integerPart);
  int fractionalInt = (int)(fractionalPart * 10000 + 0.5);

  snprintf(buffer, size, "%s%d.%04d", number < 0 ? "-" : "", integerPart, fractionalInt);

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
