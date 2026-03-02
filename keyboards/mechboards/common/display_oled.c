
#include "quantum.h"

static uint16_t current_keycode = 0xFF;

char basic_codes_to_name[57] = {
    ' ', ' ', ' ', ' ',
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T',
    '_', '-', '=', '[', ']', '\\', '#', ';', '\'', '`', ',', '.', '/'
};

const char *keycode_string(uint16_t keycode) {
    char *keycode_str;
    static char key;

    switch (keycode) {
        case 0 ... 56:
            key = pgm_read_byte(&basic_codes_to_name[keycode]);
            return &key;

        case QK_MODS ... QK_MODS_MAX:
            keycode_str = "MOD\0";
            break;

        case KC_DEL:
            keycode_str = "Del\0";
            break;
        case KC_MUTE:
            keycode_str = "Mute\0";
            break;
        case KC_VOLU:
            keycode_str = "VolUp\0";
            break;
        case KC_VOLD:
            keycode_str = "VolDn\0";
            break;
        case KC_MNXT:
            keycode_str = "Next\0";
            break;
        case KC_MPRV:
            keycode_str = "Prev\0";
            break;
        case KC_MSTP:
            keycode_str = "Stop\0";
            break;
        case KC_MPLY:
            keycode_str = "Play\0";
            break;

        default:
            keycode_str = "\0";
            break;
    }

    return keycode_str;
}

const char *layer_string(uint32_t layer) {
    char *layer_str;
    switch (layer) {
        case 0:
            layer_str = "Base\0";
            break;
        case 1:
            layer_str = "Func\0";
            break;
        case 2:
            layer_str = "Media\0";
            break;
        case 3:
            layer_str = "Other\0";
            break;
        default:
            return get_u16_str(layer, ' ');
    }

    return layer_str;
}

// Keyboard - Keyboard init
void keyboard_post_init_kb(void) {
    if (!is_keyboard_master()) {
        keyboard_post_init_user();
        return;
    }

    const char *layer_name = layer_string(get_highest_layer(layer_state));
    oled_set_cursor(0, 0);
    oled_write_ln(layer_name, false);

    keyboard_post_init_user();
}

// Keyboard - Oled init
oled_rotation_t oled_init_kb(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }

    return rotation;
}

// Keyboard - Oled render loop
bool oled_task_kb(void) {
    if (!oled_task_user()) {
        return false;
    }

    static uint16_t last_keycode = 0xFF;

    if (!is_keyboard_master()) {
        // Only render on the master oled
        return false;
    }

    if (last_keycode == current_keycode) {
        // We have nothing to update
        return false;
    }

    oled_set_cursor(0, 4); // x, y

    const char *keycode_text = keycode_string(current_keycode);
    oled_write_ln(keycode_text, false);

    last_keycode = current_keycode;
    return false;
}

// Keyboard - On key pressed
bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    current_keycode = keycode;
    return process_record_user(keycode, record);
}

// Keyboard - On layer changed
layer_state_t layer_state_set_kb(layer_state_t state) {
    state = layer_state_set_user(state);
    oled_set_cursor(0, 0);
    oled_write_ln(layer_string(get_highest_layer(state)), false);
    return state;
}
