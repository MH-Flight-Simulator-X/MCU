#ifndef DEBUG_H
#define DEBUG_H

#include <stdint.h>

#define DEBUG_BUFFER_SIZE 4096

void debug_flush(void);

void debug_print(const char* str);

#endif // DEBUG_H
