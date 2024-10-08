
#include <stdio.h>
#include "cglm/cglm.h"



void generate_transform(float x, float y, float z, float pitch, float yaw){

    mat4 position_transform_matrix;
    glm_translate_make(position_transform_matrix, (vec3) {x, y, z});


    mat4 identity_matrix;
    glm_mat4_identity(identity_matrix);

    mat4 pitch_transform_matrix;
    glm_rotate_make(pitch_transform_matrix, pitch, (vec3) {1, 0, 0});


    mat4 yaw_transform_matrix;
    glm_rotate_make(yaw_transform_matrix, yaw, (vec3) {0, 1, 0});

    mat4 perspective_transform_matrix;
    glm_perspective(1, 1.8, 1, 1000, perspective_transform_matrix);

    mat4 result_transform_matrix;
    glm_mat4_mulN(
            (mat4 *[]) {&identity_matrix, &position_transform_matrix, &yaw_transform_matrix,
                        &pitch_transform_matrix, &perspective_transform_matrix}, 5,
            result_transform_matrix);


    for (int i = 0; i < 4; i++) {
        printf("\n");
        for (int j = 0; j < 4; j++) {
            printf(" %.6f  ", result_transform_matrix[i][j]);  // Replace with actual FPGA communication function
        }
    }
}