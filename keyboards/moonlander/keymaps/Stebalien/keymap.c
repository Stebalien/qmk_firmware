#include QMK_KEYBOARD_H
#include "version.h"

enum layers {
    BASE = 0,
    SYMB,
    FUNC,
};

#define KC_WNEXT LGUI(KC_TAB)
#define KC_WPREV SGUI(KC_TAB)
#define UL(k) LT(SYMB,k)

// TODO: tap dance app+app -> esc
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_moonlander(
    KC_ESC,          KC_1,            KC_2,            KC_3,            KC_4,            KC_5,            XXXXXXX,                   XXXXXXX,         KC_6,            KC_7,            KC_8,            KC_9,            KC_0,            OSL(FUNC),
    KC_DLR,          KC_Q,            KC_W,            KC_E,            KC_R,            KC_T,            KC_TAB,                    S(KC_TAB),       KC_Y,            KC_U,            KC_I,            KC_O,            KC_P,            KC_BSLASH,
    UL(KC_GRAVE),    KC_A,            KC_S,            KC_D,            KC_F,            KC_G,            KC_DEL,                    KC_BSPACE,       KC_H,            KC_J,            KC_K,            KC_L,            CTL_T(KC_SCOLON),KC_QUOT,
    KC_LGUI,         KC_Z,            KC_X,            KC_C,            KC_V,            KC_B,                                                        KC_N,            KC_M,            KC_COMMA,        KC_DOT,          RALT_T(KC_SLSH), KC_RGUI,
    KC_WPREV,        KC_LEFT,         KC_RIGHT,        KC_UP,           KC_DOWN,                          KC_APP,                    KC_LCTL,                          KC_MINUS,        KC_LBRC,         KC_RBRC,         KC_EQUAL,        KC_WNEXT,
                                                                        S(KC_ENT),       CTL_T(KC_TAB),   LALT_T(KC_SPACE),          KC_PASTE,        KC_COPY,         KC_SPACE
   ),
  [SYMB] = LAYOUT_moonlander(
    _______,         _______,         _______,         _______,         _______,         _______,         _______,                   _______,         _______,         _______,         _______,         _______,         _______,         _______,
    _______,         _______,         _______,         KC_LBRC,         KC_RBRC,         _______,         _______,                   _______,         KC_ASTR,         KC_7,            KC_8,            KC_9,            _______,         _______,
    _______,         _______,         _______,         KC_LPRN,         KC_RPRN,         _______,         _______,                   _______,         KC_MINUS,        KC_4,            KC_5,            KC_6,            KC_DOT,          _______,
    _______,         _______,         _______,         KC_LCBR,         KC_RCBR,         _______,                                                     KC_PLUS,         KC_1,            KC_2,            KC_3,            _______,         _______,
    _______,         _______,         _______,         _______,         _______,                          _______,                   _______,                          KC_0,            KC_LPRN,         KC_RPRN,         _______,         _______,
                                                                        _______,         _______,         _______,                   _______,         _______,         _______
  ),
  [FUNC] = LAYOUT_moonlander(
    _______,         KC_F1,           KC_F2,           KC_F3,           KC_F4,           KC_F5,           XXXXXXX,                   XXXXXXX,         KC_F6,           KC_F7,           KC_F8,           KC_F9,           KC_F10,          KC_NO,
    _______,         _______,         _______,         _______,         _______,         _______,         _______,                   _______,         _______,         _______,         _______,         _______,         _______,         _______,
    _______,         _______,         _______,         _______,         _______,         _______,         _______,                   _______,         _______,         _______,         _______,         _______,         _______,         _______,
    _______,         _______,         _______,         _______,         _______,         _______,                                                     _______,         _______,         _______,         _______,         _______,         _______,
    RESET,           _______,         _______,         _______,         _______,                          _______,                   _______,                          _______,         _______,         _______,         _______,         _______,
                                                                        _______,         _______,         _______,                   _______,         _______,         _______
  ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return state;
}

void keyboard_post_init_user(void) {
    #ifdef RGB_MATRIX_ENABLE
    if (!rgb_matrix_is_enabled()) {
        return;
    }
    rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
    #endif
}

void rgb_matrix_indicators_user(void) {
    #ifdef RGB_MATRIX_ENABLE
    if (!rgb_matrix_is_enabled()) {
        return;
    }
    switch (get_highest_layer(layer_state)) {
    case SYMB:
        rgb_matrix_set_color(57, 0xff, 0x00, 0xff);
        rgb_matrix_set_color(58, 0xff, 0x00, 0xff);
        rgb_matrix_set_color(59, 0xff, 0x00, 0xff);
        rgb_matrix_set_color(60, 0xff, 0x00, 0xff);

        rgb_matrix_set_color(52, 0xff, 0x00, 0xff);
        rgb_matrix_set_color(53, 0xff, 0x00, 0xff);
        rgb_matrix_set_color(54, 0xff, 0x00, 0xff);

        rgb_matrix_set_color(47, 0xff, 0x00, 0xff);
        rgb_matrix_set_color(48, 0xff, 0x00, 0xff);
        rgb_matrix_set_color(49, 0xff, 0x00, 0xff);
        break;
    case FUNC:
        rgb_matrix_set_color(4, 0x55, 0x55, 0x55);
        rgb_matrix_set_color(36, 0xff, 0x00, 0x00);

        rgb_matrix_set_color(5, 0xff, 0x00, 0xff);
        rgb_matrix_set_color(10, 0xff, 0x00, 0xff);
        rgb_matrix_set_color(15, 0xff, 0x00, 0xff);
        rgb_matrix_set_color(20, 0xff, 0x00, 0xff);
        rgb_matrix_set_color(25, 0xff, 0x00, 0xff);
        rgb_matrix_set_color(41, 0xff, 0x00, 0xff);
        rgb_matrix_set_color(46, 0xff, 0x00, 0xff);
        rgb_matrix_set_color(51, 0xff, 0x00, 0xff);
        rgb_matrix_set_color(56, 0xff, 0x00, 0xff);
        rgb_matrix_set_color(61, 0xff, 0x00, 0xff);
        break;
    default:
        rgb_matrix_set_color_all(0x57, 0xbe, 0xff);
        break;
    }
    #endif
}
