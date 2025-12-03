#pragma once

#include <stdint.h>
#include <stdbool.h>

#define MATRIX_ROWS 4
#define MATRIX_COLS 4

void matrix_init(void);
void matrix_scan(void);
bool matrix_is_on(uint8_t row, uint8_t col);
uint8_t matrix_get_row_count(void);
uint8_t matrix_get_col_count(void);