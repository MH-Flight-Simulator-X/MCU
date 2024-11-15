#include "../include/cglm/cglm.h"
#include "transformation.h"
#include <stdio.h>
#include "plane.h"
#include "debug.h"

// Helper function to print a matrix for debugging
void print_matrix(mat4 matrix)
{
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      debug_print_float(matrix[i][j]);
      debug_printf("  ");
    }
    debug_printf("\n");
  }
  debug_printf("\n");
}

// Generate a view matrix based on the sprite's orientation (roll, pitch, yaw)
static void generate_view_matrix(Sprite *sprite, mat4 result)
{
  mat4 pitch_matrix;
  vec3 pitch_axis = {1, 0, 0};
  glm_rotate_make(pitch_matrix, glm_rad(sprite->pitch), pitch_axis);

  mat4 yaw_matrix;
  vec3 yaw_axis = {0, 1, 0};
  glm_rotate_make(yaw_matrix, glm_rad(sprite->yaw), yaw_axis);

  mat4 roll_matrix;
  vec3 roll_axis = {0, 0, 1};
  glm_rotate_make(roll_matrix, glm_rad(sprite->roll), roll_axis);

  // Combine the roll, yaw, and pitch matrices to form the final view matrix
  glm_mat4_mul(roll_matrix, yaw_matrix, result);
  glm_mat4_mul(result, pitch_matrix, result);
}

// Generate the Model-View-Projection (MVP) matrix for the sprite and aircraft
void generate_mvp_matrix(Sprite *sprite, Aircraft *aircraft, mat4 result)
{
  mat4 identity_matrix;
  glm_mat4_identity(identity_matrix);

  // Translation matrix for the sprite position
  mat4 translation_matrix;
  vec3 sprite_position = {sprite->x, sprite->y, sprite->z};
  glm_translate_make(translation_matrix, sprite_position);

  // Generate the model matrix: translation * rotation
  mat4 sprite_view_matrix;
  generate_view_matrix(sprite, sprite_view_matrix);

  mat4 model_matrix;
  glm_mat4_mul(translation_matrix, sprite_view_matrix, model_matrix);

  // Generate the view matrix for the aircraft
  mat4 view_matrix;
  generate_view_matrix((Sprite *)aircraft, view_matrix);

  // Generate the projection matrix
  mat4 projection_matrix;
  glm_perspective(glm_rad(45.0f), 4.0f / 3.0f, 1.0f, 1000.0f, projection_matrix);

  // Compute the MVP matrix: projection * view * model
  mat4 view_projection;
  glm_mat4_mul(projection_matrix, view_matrix, view_projection);

  glm_mat4_mul(view_projection, model_matrix, result);
  // debug_printf("Final MVP Matrix:\n");
  // print_matrix(result);
}
