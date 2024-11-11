
#include "../include/cglm/cglm.h"
#include "transformation.h"
#include <stdio.h>


void generate_model_matrix(vec3 sprite_position, float pitch, float yaw, mat4 result )
{

  mat4 position_transform_matrix;
  glm_translate_make(position_transform_matrix,sprite_position);

  mat4 identity_matrix;
  glm_mat4_identity(identity_matrix);

  mat4 pitch_transform_matrix;
  vec3 pitch_identity = {1, 0, 0};
  glm_rotate_make(pitch_transform_matrix, pitch, pitch_identity);


  mat4 yaw_transform_matrix;
  vec3 yaw_identity = {0, 1, 0};
  glm_rotate_make(yaw_transform_matrix, yaw, yaw_identity);


  mat4* matrices[4] ={&position_transform_matrix, &yaw_transform_matrix, &pitch_transform_matrix, &identity_matrix};
  glm_mat4_mulN(matrices, 4, result);


}

void generate_camera_matrix(vec3 aircraft_position, mat4 result)
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
  vec3 eye = {aircraft_position[0], aircraft_position[1] + height_offset, aircraft_position[2] - distance_offset};
  vec3 center = (vec3){aircraft_position[0], aircraft_position[1], aircraft_position[2]};
  vec3 up = {1, 0, 0};

  glm_lookat(eye,center, up, result);


}


void generate_mvp_matrix_entry(vec3 position, float pitch, float yaw, uint8_t flags, uint8_t id, MvpMatrixEntry *entry)
{
  entry->flag_id = (flags << 4) | (id & 0x0F);
  generate_model_matrix(position, pitch, yaw, entry->mvp_matrix);
}

