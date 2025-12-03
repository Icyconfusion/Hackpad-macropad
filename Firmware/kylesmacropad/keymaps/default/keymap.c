#include QMK_KEYBOARD_H

enum layers {
    SCHOOLWORK,
    RACING,
    GENERAL
};

enum custom_keycodes {
    KC_BTN0 = SAFE_RANGE,
    KC_BTN1,
    KC_BTN2,
    KC_BTN3,
    KC_BTN4,
    KC_BTN5,
    KC_BTN6,
    KC_BTN7,
    KC_BTN8,
    KC_BTN9,
    KC_BTN10,
    KC_BTN11,
    KC_BTN12,
    KC_BTN13,
    KC_BTN14,
    KC_BTN15,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_SCHOOLWORK] = LAYOUT(
        KC_BTN0, KC_BTN1, KC_BTN2, KC_BTN3,
        KC_BTN4, KC_BTN5, KC_BTN6, KC_BTN7,
        KC_BTN8, KC_BTN9, KC_BTN10, KC_BTN11,
        KC_BTN12, KC_BTN13, KC_BTN14, KC_BTN15
    ),
    [_RACING] = LAYOUT(
        KC_BTN0, KC_BTN1, KC_BTN2, KC_BTN3,
        KC_BTN4, KC_BTN5, KC_BTN6, KC_BTN7,
        KC_BTN8, KC_BTN9, KC_BTN10, KC_BTN11,
        KC_BTN12, KC_BTN13, KC_BTN14, KC_BTN15
    ),
    [_GENERAL] = LAYOUT(
        KC_BTN0, KC_BTN1, KC_BTN2, KC_BTN3,
        KC_BTN4, KC_BTN5, KC_BTN6, KC_BTN7,
        KC_BTN8, KC_BTN9, KC_BTN10, KC_BTN11,
        KC_BTN12, KC_BTN13, KC_BTN14, KC_BTN15
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // You can add custom behaviour here for your buttons if needed.
    return true;
}