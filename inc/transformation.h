
#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H

#include "../include/cglm/cglm.h"
#include "plane.h"

typedef struct
{
  uint8_t flag_id;
  mat4 mvp_matrix;
} MvpMatrixEntry;

void generate_mvp_matrix(Sprite *sprite, Aircraft *aircraft, mat4 result);
void generate_mvp_matrix_entry(vec3 position, float pitch, float yaw, uint8_t flags, uint8_t id, MvpMatrixEntry *entry);

#endif // TRANSFORMATION_H
