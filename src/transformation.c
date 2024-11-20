#include <aircraft.h>
#include "../include/cglm/cglm.h"
#include "transformation.h"
#include <stdio.h>
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

// Generate a combined rotation matrix from pitch, yaw and roll
static void generate_rotation_matrix(double pitch, double yaw, double roll, mat4 result)
{
  mat4 pitch_matrix, yaw_matrix, roll_matrix;

  vec3 pitch_axis = {1, 0, 0}; // Pitch rotates around X-axis
  vec3 yaw_axis = {0, 1, 0};   // Yaw rotates around Y-axis
  vec3 roll_axis = {0, 0, 1};  // Roll rotates around Z-axis

  glm_rotate_make(pitch_matrix, glm_rad(pitch), pitch_axis);

  glm_rotate_make(yaw_matrix, glm_rad(yaw), yaw_axis);

  glm_rotate_make(roll_matrix, glm_rad(roll), roll_axis);

  // Combine roll and pitch
  glm_mat4_mul(yaw_matrix, roll_matrix, result);
  glm_mat4_mul(result, pitch_matrix, result);
}

// Generate the Model-View-Projection (MVP) matrix
void generate_mvp_matrix(Sprite *sprite, Aircraft *aircraft, mat4 result)
{
  if (sprite->status == 2)
  {
    debug_println("Sprite status is 2, skipping MVP generation.");
    return;
  }

  mat4 identity_matrix;
  glm_mat4_identity(identity_matrix);

  // Translation matrix for the sprite position
  mat4 sprite_translation_matrix;
  vec3 sprite_position = {sprite->x, sprite->y, sprite->z};
  glm_translate_make(sprite_translation_matrix, sprite_position);

  // Generate the model matrix: translation * rotation
  mat4 sprite_rotation_matrix;
  generate_rotation_matrix(sprite->pitch, sprite->yaw, sprite->roll, sprite_rotation_matrix);

  mat4 model_matrix;
  glm_mat4_mul(sprite_translation_matrix, sprite_rotation_matrix, model_matrix);

  // Apply a fixed downward tilt of 20 degrees to the camera
  mat4 camera_tilt_matrix;
  vec3 tilt_axis = {1, 0, 0};
  glm_rotate_make(camera_tilt_matrix, glm_rad(-20.0f), tilt_axis);

  // Generate the camera's local transformation
  mat4 camera_rotation_matrix;
  generate_rotation_matrix(aircraft->pitch, aircraft->yaw, aircraft->roll, camera_rotation_matrix);

  // Combine the fixed tilt with the camera's rotation
  glm_mat4_mul(camera_rotation_matrix, camera_tilt_matrix, camera_rotation_matrix);

  // Translate the camera backwards 20 units along its -Z axis
  vec4 camera_offset = {0, 0, 20, 1};
  vec4 translated_offset;
  glm_mat4_mulv(camera_rotation_matrix, camera_offset, translated_offset);

  // Update camera position in world space
  vec3 adjusted_camera_position = {
      aircraft->x + translated_offset[0],
      aircraft->y + translated_offset[1],
      aircraft->z + translated_offset[2]};

  // View matrix (inverse of camera's transformation)
  mat4 camera_translation_matrix;
  vec3 neg_adjusted_camera_position = {
      -adjusted_camera_position[0],
      -adjusted_camera_position[1],
      -adjusted_camera_position[2]};
  glm_translate_make(camera_translation_matrix, neg_adjusted_camera_position);


  mat4 transposed_camera_rotation_matrix;
  glm_mat4_transpose_to(camera_rotation_matrix, transposed_camera_rotation_matrix);

  glm_mat4_mul(transposed_camera_rotation_matrix, camera_translation_matrix, camera_rotation_matrix);

  // Generate the projection matrix
  mat4 projection_matrix;
  glm_perspective(glm_rad(45.0f), 4.0f / 3.0f, 1.0f, 1000.0f, projection_matrix);

  // Compute the MVP matrix: projection * view * model
  mat4 view_projection;
  glm_mat4_mul(projection_matrix, camera_rotation_matrix, view_projection);

  glm_mat4_mul(view_projection, model_matrix, result);
}
