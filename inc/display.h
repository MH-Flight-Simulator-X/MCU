#include "stdint.h"

void display_init(Aircraft *aircraft);
void display_write_single_data(uint8_t reg, uint8_t command);
void display_write_data(uint8_t *command);
void display_print_and_rotate_string(void);
void display_set_string(char str[]);
void display_print_string();
void display_set_number();
void display_toggle_display(void);
void display_init_controller(Aircraft *aircraft);
