/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglmc_persp_rh_zo_h
#define cglmc_persp_rh_zo_h
#ifdef __cplusplus
extern "C" {
#endif

#include "../../cglm.h"

CGLM_EXPORT
void
glmc_frustum_rh_zo( left,     right,
                    bottom,   top,
                    nearZ,    farZ,
                   mat4  dest);

CGLM_EXPORT
void
glmc_perspective_rh_zo( fovy,
                        aspect,
                        nearVal,
                        farVal,
                       mat4 dest);

CGLM_EXPORT
void
glmc_persp_move_far_rh_zo(mat4 proj,  deltaFar);

CGLM_EXPORT
void
glmc_persp_decomp_rh_zo(mat4 proj,
                         * __restrict nearZ,  * __restrict farZ,
                         * __restrict top,    * __restrict bottom,
                         * __restrict left,   * __restrict right);

CGLM_EXPORT
void
glmc_persp_decompv_rh_zo(mat4 proj,  dest[6]);

CGLM_EXPORT
void
glmc_persp_decomp_x_rh_zo(mat4 proj,
                           * __restrict left,
                           * __restrict right);

CGLM_EXPORT
void
glmc_persp_decomp_y_rh_zo(mat4 proj,
                           * __restrict top,
                           * __restrict bottom);

CGLM_EXPORT
void
glmc_persp_decomp_z_rh_zo(mat4 proj,
                           * __restrict nearZ,
                           * __restrict farZ);

CGLM_EXPORT
void
glmc_persp_decomp_far_rh_zo(mat4 proj,  * __restrict farZ);

CGLM_EXPORT
void
glmc_persp_decomp_near_rh_zo(mat4 proj,  * __restrict nearZ);

CGLM_EXPORT
void
glmc_persp_sizes_rh_zo(mat4 proj,  fovy, vec4 dest);

CGLM_EXPORT

glmc_persp_fovy_rh_zo(mat4 proj);

CGLM_EXPORT

glmc_persp_aspect_rh_zo(mat4 proj);

#ifdef __cplusplus
}
#endif
#endif /* cglmc_persp_rh_zo_h */
