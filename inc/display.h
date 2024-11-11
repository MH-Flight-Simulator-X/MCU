#include "stdint.h"

void display_init(void);
void display_write_data(uint8_t reg, uint8_t command);
void display_print_testing(int iteration);