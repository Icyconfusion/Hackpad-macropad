#include QMK_KEYBOARD_H

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { // Left encoder: cycle layers
        if (clockwise) {
            layer_move((layer_state_get() + 1) % 3);
        } else {
            layer_move((layer_state_get() + 2) % 3);
        }
        return false;
    } else if (index == 1) { // Right encoder
        if (layer_state_is(_SCHOOLWORK)) {
            if (clockwise) {
                tap_code16(C(KC_TAB));      // Ctrl+Tab
            } else {
                tap_code16(C(S(KC_TAB)));  // Ctrl+Shift+Tab
            }
        } else {
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
        }
        return false;
    }
    return true;
}