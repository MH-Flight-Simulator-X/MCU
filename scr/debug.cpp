#include "debug.h"
#include "sl_debug_swo.h"
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>


static char debug_buffer[DEBUG_BUFFER_SIZE];

void debug_flush() {
  memset(debug_buffer, 0, DEBUG_BUFFER_SIZE);
}

void debug_print(const char* str) {
  int len = strlen(str) + 2;

  if (len >= DEBUG_BUFFER_SIZE) {
    len = DEBUG_BUFFER_SIZE;
    debug_buffer[len - 1] = '\n';
    debug_buffer[len] = '\0';
  }

  memcpy(debug_buffer, str, len);

  for (int i = 0; i < len + 1; i++) {
      sl_debug_swo_write_u8(0, debug_buffer[i]);
  }

  debug_flush();
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
