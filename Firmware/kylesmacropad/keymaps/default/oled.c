#include QMK_KEYBOARD_H

#ifdef OLED_DRIVER_ENABLE

static const char *layer_names[] = {"Schoolwork", "Racing", "General"};

// Volume placeholder, update as needed
static int volume_level = 50;

void oled_task_user(void) {
    oled_clear();

    oled_set_cursor(0, 0);
    oled_write("KylesMacropad\n", false);

    oled_write("Layer:\n", false);
    oled_write_ln(layer_names[layer_state_get()], false);

    oled_write("Volume:\n", false);
    oled_write_int(volume_level);
}

#endif