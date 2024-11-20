#ifndef GAME_H
#define GAME_H

#include <stdint.h>

#define CAMERA_LAG 10

void game_init();
void game_process_action(uint32_t frame_counter, uint32_t * game_active);
void game_process_wait(uint32_t frame_counter, uint32_t * game_active);

#endif // GAME_H
