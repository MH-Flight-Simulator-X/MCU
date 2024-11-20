#ifndef DEBUG_H
#define DEBUG_H

#include <stdint.h>
#include <stdio.h>

#define DEBUG_BUFFER_SIZE 512

void debug_print(const char* str);
void debug_println(const char *format, ...);
void debug_printf(const char *format, ...);
void float_to_string(char *buffer, size_t size, float number);
void debug_print_float(float num);

#endif // DEBUG_H
