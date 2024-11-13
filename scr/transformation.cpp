
#include "../include/cglm/cglm.h"
#include "transformation.h"
#include <stdio.h>
#include "plane.h"

static void generate_view_matrix(Sprite *sprite, mat4 result)
{
  mat4 pitch_matrix;
  vec3 pitch_identity = {1, 0, 0};
  glm_rotate_make(pitch_matrix, sprite->pitch, pitch_identity);

  mat4 yaw_matrix;
  vec3 yaw_identity = {0, 1, 0};
  glm_rotate_make(yaw_matrix, sprite->yaw, yaw_identity);

  mat4 roll_matrix;
  vec3 roll_identity = {0, 0, 1};
  glm_rotate_make(roll_matrix, sprite->roll, roll_identity);

  mat4 *view_matrices[3] = {&roll_matrix, &yaw_matrix, &pitch_matrix};
  glm_mat4_mulN(view_matrices, 3, result);
}

void generate_mvp_matrix(Sprite *sprite, Aircraft *aircraft, mat4 result)
{

  // Model matrix
  mat4 identity_matrix;
  glm_mat4_identity(identity_matrix);

  mat4 sprite_position_matrix;
  vec3 sprite_position = {sprite->x, sprite->y, sprite->z};
  glm_translate_make(sprite_position_matrix, sprite_position);

  mat4 sprite_view_matrix;
  generate_view_matrix(sprite, sprite_view_matrix);

  mat4 model_matrix;
  mat4 *model_matrices[3] = {&identity_matrix, &sprite_position_matrix, &sprite_view_matrix};
  glm_mat4_mulN(model_matrices, 3, model_matrix);

  // View matrix

  mat4 view_matrix;
  generate_view_matrix((Sprite *)aircraft, view_matrix);

  // Projection matrix
  mat4 projection_matrix;
  glm_perspective(glm_rad(45), 4.0 / 3.0, 1.0, 1000.0, projection_matrix);

  // mvp matrix
  mat4 *matrices[4] = {&model_matrix, &view_matrix, &projection_matrix};
  glm_mat4_mulN(matrices, 4, result);
}

void generate_mvp_matrix_entry(vec3 position, float pitch, float yaw, uint8_t flags, uint8_t id, MvpMatrixEntry *entry)
{
  entry->flag_id = (flags << 4) | (id & 0x0F);
  // generate_model_matrix(position, pitch, yaw, entry->mvp_matrix);
}

// for (int i = 0; i < 4; i++)
// {
//   printf("\n");
//   for (int j = 0; j < 4; j++)
//   {
//     printf(" %.6f  ", aircraft_view_matrix[i][j]);
//   }
// }