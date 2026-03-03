#include QMK_KEYBOARD_H

#include "gpio.h"

// Layers
#define LAYER_BAE 0
#define LAYER_FUNC 1
#define LAYER_MEDIA 2
#define LAYER_OTHER 3

// Left-hand home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LCTL_T(KC_D)
#define HOME_F LSFT_T(KC_F)

// Right-hand home row mods
#define HOME_J RSFT_T(KC_J)
#define HOME_K RCTL_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_SCLN RGUI_T(KC_SCLN)

// Custom
#define SHIFT_QUOT LSFT_T(KC_QUOT)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // ----------------------------------------------------------------------------------------------------------------
    // | 1      |  2  |  3  |  4   |  5    |  6   |                      |  7   |  8    |  9    |  0   |   -   |   =   |
    // | TAB    |  Q  |  W  |  E   |  R    |  T   |                      |  Y   |  U    |  I    |  O   |   P   |   \   |
    // | SHIFT  |  A  |  S  |  D   |  F    |  G   |                      |  H   |  J    |  K    |  L   |   ;   |   '   |
    // | CTRL   |  Z  |  X  |  C   |  V    |  B   |   [      |  |  ]     |  N   |  M    |  ,    |  .   |   /   |   `   |
    //                      | ALT  | LOWER | GUI  |  SPACE   |  | ENTER  | ESC  | BSPC  | RAISE |
    [LAYER_BAE] = LAYOUT(
        KC_1,       KC_2,   KC_3,   KC_4,    KC_5,    KC_6,                         KC_7,   KC_8,    KC_9,     KC_0,   KC_MINS,    KC_EQL,
        KC_TAB,     KC_Q,   KC_W,   KC_E,    KC_R,    KC_T,                         KC_Y,   KC_U,    KC_I,     KC_O,   KC_P,       KC_BSLS,
        KC_LSFT,    KC_A,   KC_S,   KC_D,    KC_F,    KC_G,                         KC_H,   KC_J,    KC_K,     KC_L,   KC_SCLN,    SHIFT_QUOT,
        KC_LCTL,    KC_Z,   KC_X,   KC_C,    KC_V,    KC_B,   KC_LBRC,  KC_RBRC,    KC_N,   KC_M,    KC_COMM,  KC_DOT, KC_SLSH,    KC_GRV,
                                    KC_LALT, MO(1),   KC_LGUI,  KC_SPC,   KC_ENT,     KC_ESC, KC_BSPC, MO(2)),

    // ----------------------------------------------------------------------------------------------------------------
    // | F1     |  F2 |  F3 |  F4  |  F5  |  F6  |                      |  F7  |  F8   |  F9   |  F10  |   F11 |   F12 |
    // | TAB    |     |     |  END |      |      |                      |      |       |  INST |       |       |       |
    // | SHIFT  |     |     |  DEL |      |      |                      | HOME |       |       |       |       |       |
    // | CTRL   |     |     |      |      |      |          |  |        | LEFT | DOWN  | UP    | RIGHT |       |       |
    //                      | ALT  | GUI  | LOWER|  SPACE   |  | ENTER  | ESC  | BSPC  | RAISE |
    [LAYER_FUNC] = LAYOUT(
        KC_F1,      KC_F2,  KC_F3,  KC_F4,      KC_F5,      KC_F6,                              KC_F7,      KC_F8,   KC_F9,     KC_F10,     KC_F11, KC_F12,
        KC_TRNS,    KC_NO,  KC_NO,  KC_END,     KC_NO,      KC_NO,                              KC_NO,      KC_NO,   KC_INS,    KC_NO,      KC_NO,  KC_NO,
        KC_TRNS,    KC_NO,  KC_NO,  KC_DEL,     KC_NO,      KC_NO,                              KC_HOME,    KC_NO,   KC_NO,     KC_NO,      KC_NO,  KC_PGUP,
        KC_TRNS,    KC_NO,  KC_NO,  KC_NO,      KC_NO,      KC_NO,   KC_NO,   KC_NO,      KC_LEFT,    KC_DOWN, KC_UP,     KC_RIGHT,   KC_NO,  KC_PGDN,
                                    KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS, MO(3)),

    // ----------------------------------------------------------------------------------------------------------------
    // |        |     |      |      |      |      |                      |      |       |       |      | VOLD  | VOLU  |
    // |        |     |      |      |      |      |                      |      |       |       | MPLY |       |       |
    // |        |     | PSCR |      |      |      |                      |      |       |       |      |       |       |
    // |        |     |      |      |      |      |          |  |        |      | MUTE  |       |      |       |       |
    //                       |      |      | LOWER|          |  |        |      |       |       |
    [LAYER_MEDIA] = LAYOUT(
        KC_NO, KC_NO, KC_NO,    KC_NO, KC_NO, KC_NO,                KC_NO, KC_NO,   KC_NO, KC_NO, KC_VOLD, KC_VOLU,
        KC_NO, KC_NO, KC_NO,    KC_NO, KC_NO, KC_NO,                KC_NO, KC_NO,   KC_NO, KC_NO, KC_MPLY, KC_NO,
        KC_NO, KC_NO, KC_PSCR,  KC_NO, KC_NO, KC_NO,                KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO,    KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO, KC_NO, KC_MUTE, KC_NO, KC_NO, KC_NO, KC_NO,
                                KC_NO, KC_NO, MO(3), KC_NO,  KC_NO, KC_NO, KC_NO,   KC_NO),

    // ----------------------------------------------------------------------------------------------------------------
    // |        |     |     |      |      |      |                      |      |       |       |      |       |       |
    // |        |     |     |      |      |      |                      |      |       |       |      |       |       |
    // |        |     |     |      |      |      |                      |      |       |       |      |       |       |
    // |        |     |     |      |      |      |          |  |        |      |       |       |      |       |       |
    //                      |      |      |      |          |  |        |      |       |       |
    [LAYER_OTHER] = LAYOUT(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                             KC_NO, KC_NO, KC_TRNS, KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO)
};

void keyboard_pre_init_user(void) {
    // Disable led lights
    gpio_set_pin_output(24);
    gpio_write_pin_high(24);
}

void keyboard_post_init_user(void) {
    debug_enable=true;
    debug_matrix=false;
    debug_keyboard=true;

    static const char image [] PROGMEM = {
        // 'logo', 32x32px
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xe0, 0xf0, 0x70, 0x30, 0x30, 0x70,
        0xff, 0xff, 0xff, 0x30, 0x30, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00,
        0x3f, 0x7f, 0x7f, 0xe0, 0xe0, 0xe0, 0xe0, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };

    oled_set_cursor(0, 12);
    oled_write_raw_P(image, sizeof(image));
}
