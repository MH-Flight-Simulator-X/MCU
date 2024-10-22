
#include "cglm/cglm.h"
#include <stdio.h>

void generate_model_matrix(vec3 sprite_position, float pitch, float yaw)
{

  mat4 position_transform_matrix;
  glm_translate_make(position_transform_matrix, (vec3){sprite_position[0], sprite_position[1], sprite_position[2]});

  mat4 identity_matrix;
  glm_mat4_identity(identity_matrix);

  mat4 pitch_transform_matrix;
  glm_rotate_make(pitch_transform_matrix, pitch, (vec3){1, 0, 0});

  mat4 yaw_transform_matrix;
  glm_rotate_make(yaw_transform_matrix, yaw, (vec3){0, 1, 0});

  mat4 result_transform_matrix;
  glm_mat4_mulN(
      (mat4 *[]){&position_transform_matrix, &yaw_transform_matrix, &pitch_transform_matrix, &identity_matrix}, 4,
      result_transform_matrix);

  return result_transform_matrix;
}

void generate_camera_matrix(vec3 aircraft_position)
{
  //   for (int i = 0; i < 4; i++)
  //   {
  //     printf("\n");
  //     for (int j = 0; j < 4; j++)
  //     {
  //       printf(" %.6f  ", result_transform_matrix[i][j]); // Replace with actual FPGA communication function
  //     }
  //   }

  // aircraft_position = {a, b, c}
  // camera_position = {x, y = b + height_offset,z = c - distance_offset}
  int height_offset = 10;
  int distance_offset = 10;

  mat4 lookat_matrix;
  glm_lookat((vec3){aircraft_position[0], aircraft_position[1] + height_offset, aircraft_position[2] - distance_offset},
             (vec3){aircraft_position[0], aircraft_position[1], aircraft_position[2]}, (vec3){1, 0, 0}, lookat_matrix);

  return lookat_matrix;
}
