#ifndef DEBUG_H
#define DEBUG_H

#include <stdint.h>
#include <stdio.h>

#define DEBUG_BUFFER_SIZE 512

void debug_flush(void);
void debug_print(const char* str);
void debug_printf(const char *format, ...);
void float_to_string(char *buffer, size_t size, double number);

#endif // DEBUG_H
