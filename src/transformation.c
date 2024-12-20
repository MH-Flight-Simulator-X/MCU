#include <aircraft.h>
#include "../include/cglm/cglm.h"
#include "transformation.h"
#include <stdio.h>
#include "debug.h"

/*********************************************************************************************
 * @file transformation.c
 * @brief Implementation of 3D transformation utilities for aircraft and sprite rendering
 *
 * This file implements the core transformation logic for 3D graphics rendering,
 * including matrix operations for Model-View-Projection (MVP) calculations.
 *********************************************************************************************/

/*********************************************************************************************
 * @brief Debug utility to print a 4x4 matrix
 *
 * Prints each element of the matrix in a formatted grid layout.
 * Uses debug_print_float for consistent floating-point output formatting.
 *
 * @param matrix The 4x4 matrix to print
 *********************************************************************************************/
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

/*********************************************************************************************
 * @brief Creates a combined rotation matrix from Euler angles
 *
 * Generates rotation matrices for pitch, yaw, and roll separately, then combines them
 * in the order: Yaw * Roll * Pitch. This order ensures proper aircraft-like rotations.
 *
 * @param pitch Rotation around X-axis in degrees
 * @param yaw Rotation around Y-axis in degrees
 * @param roll Rotation around Z-axis in degrees
 * @param result Output parameter for the combined rotation matrix
 *********************************************************************************************/
static void generate_rotation_matrix(float pitch, float yaw, float roll, mat4 result)
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

/*********************************************************************************************
 * @brief Generates the Model-View-Projection (MVP) matrix for rendering
 *
 * Creates the complete transformation pipeline for rendering sprites relative to
 * an aircraft's position and orientation. The transformation consists of:
 *
 * 1. Model Matrix:
 *    - Translates sprite to its world position
 *    - Applies sprite's local rotation
 *
 * 2. View Matrix:
 *    - Positions camera behind aircraft (-Z axis)
 *    - Applies fixed -20° downward tilt
 *    - Includes aircraft's orientation
 *    - Translates 20 units back from aircraft
 *
 * 3. Projection Matrix:
 *    - 45° field of view
 *    - 4:3 aspect ratio
 *    - Near plane: 1.0, Far plane: 1000.0
 *
 * @param sprite Pointer to the Sprite being rendered
 * @param aircraft Pointer to the Aircraft (camera position)
 * @param result Output parameter for the final MVP matrix
 *
 * @note Early returns if sprite->status == 2
 * @note Camera position is computed in aircraft's local space then transformed to world space
 *********************************************************************************************/
void generate_mvp_matrix(Sprite *sprite, Sprite *camera, mat4 result)
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
  generate_rotation_matrix(camera->pitch, camera->yaw, camera->roll, camera_rotation_matrix);

  // Combine the fixed tilt with the camera's rotation
  glm_mat4_mul(camera_rotation_matrix, camera_tilt_matrix, camera_rotation_matrix);

  // Translate the camera backwards 20 units along its -Z axis
  vec4 camera_offset = {0, 0, 20, 1};
  vec4 translated_offset;
  glm_mat4_mulv(camera_rotation_matrix, camera_offset, translated_offset);

  // Update camera position in world space
  vec3 adjusted_camera_position = {
      camera->x + translated_offset[0],
      camera->y + translated_offset[1],
      camera->z + translated_offset[2]};

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
