#include "debug.h"
#include "sl_debug_swo.h"
#include <stdio.h>
#include <string.h>

static char debug_buffer[DEBUG_BUFFER_SIZE];

void debug_flush() {
    memset(debug_buffer, 0, DEBUG_BUFFER_SIZE);
}

void debug_print(const char* str) {
    int len = strlen(str) + 2;

    if (len >= DEBUG_BUFFER_SIZE)
        len = DEBUG_BUFFER_SIZE;


    memcpy(debug_buffer, str, len);

    debug_buffer[len - 1] = '\n';
    debug_buffer[len] = '\0';


    for (int i = 0; i < len + 1; i++) {
        sl_debug_swo_write_u8(0, debug_buffer[i]);
    }

    debug_flush();
}

