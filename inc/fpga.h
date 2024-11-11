#ifndef GAME_H
#define GAME_H

#include <stdint.h>
#include "../include/cglm/cglm.h"

typedef struct {
    uint8_t flag_id; // 4 bits for flags, 4 bits for ID
    mat4 model_view_matrix;
} ModelViewMatrixEntry;

#endif // GAME_H
