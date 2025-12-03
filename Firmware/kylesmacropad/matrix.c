#include "kylesmacropad.h"
#include "matrix.h"
#include "quantum.h"
#include "wait.h"
#include "pico/stdlib.h"

static bool matrix[MATRIX_ROWS][MATRIX_COLS];

// Charlieplex pins array
static const uint8_t charlie_pins[NUM_CHARLIE_PINS] = {0, 1, 2, 4, 3};

// 16 switches (including 2 encoder buttons) mapped as charlieplex pairs (high, low)
static const uint8_t charlie_switch_map[16][2] = {
    {0, 2}, // P1->P3
    {2, 0}, // P3->P1
    {0, 3}, // P1->P4
    {3, 0}, // P4->P1
    {0, 4}, // P1->P5
    {4, 0}, // P5->P1
    {1, 2}, // P2->P3
    {2, 1}, // P3->P2
    {1, 3}, // P2->P4
    {3, 1}, // P4->P2
    {1, 4}, // P2->P5
    {4, 1}, // P5->P2
    {2, 3}, // P3->P4
    {3, 2}, // P4->P3
    {2, 4}, // P3->P5
    {4, 2}  // P5->P3
};

static void set_pin_input(uint8_t gpio) {
    gpio_set_dir(gpio, GPIO_IN);
    gpio_disable_pulls(gpio);
}

static void set_pin_output(uint8_t gpio, bool level) {
    gpio_set_dir(gpio, GPIO_OUT);
    gpio_put(gpio, level);
}

void matrix_init(void) {
    for (int i = 0; i < NUM_CHARLIE_PINS; i++) {
        gpio_init(charlie_pins[i]);
        set_pin_input(charlie_pins[i]);
    }

    gpio_init(ENCODER_LEFT_A);
    gpio_init(ENCODER_LEFT_B);
    gpio_init(ENCODER_RIGHT_A);
    gpio_init(ENCODER_RIGHT_B);

    gpio_pull_up(ENCODER_LEFT_A);
    gpio_pull_up(ENCODER_LEFT_B);
    gpio_pull_up(ENCODER_RIGHT_A);
    gpio_pull_up(ENCODER_RIGHT_B);
}

void matrix_scan(void) {
    for (uint8_t i = 0; i < 16; i++) {
        uint8_t high_idx = charlie_switch_map[i][0];
        uint8_t low_idx = charlie_switch_map[i][1];

        for (int p = 0; p < NUM_CHARLIE_PINS; p++) {
            set_pin_input(charlie_pins[p]);
        }

        set_pin_output(charlie_pins[high_idx], true);
        set_pin_output(charlie_pins[low_idx], false);

        wait_us(5);

        bool pressed = gpio_get(charlie_pins[low_idx]) == 1;

        uint8_t row = i / MATRIX_COLS;
        uint8_t col = i % MATRIX_COLS;
        matrix[row][col] = pressed;
    }
}

bool matrix_is_on(uint8_t row, uint8_t col) {
    return matrix[row][col];
}

uint8_t matrix_get_row_count(void) {
    return MATRIX_ROWS;
}

uint8_t matrix_get_col_count(void) {
    return MATRIX_COLS;
}