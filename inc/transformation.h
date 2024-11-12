
#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H

#include "../include/cglm/cglm.h"

typedef struct
{
  uint8_t flag_id;
  mat4 mvp_matrix;
} MvpMatrixEntry;


void generate_model_matrix(vec3 sprite_position, float pitch, float yaw, mat4 result);
void generate_camera_matrix(vec3 aircraft_position, mat4 result);
void generate_mvp_matrix_entry(vec3 position, float pitch, float yaw, uint8_t flags, uint8_t id, MvpMatrixEntry *entry);

#endif  // TRANSFORMATION_H
