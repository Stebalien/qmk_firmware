#include QMK_KEYBOARD_H
#include "version.h"

enum layers {
    BASE = 0,
    SHIFT,
    SYMB,
    NAV,
    KEYB,
};

#define KC_WNEXT LGUI(KC_TAB)
#define KC_WPREV SGUI(KC_TAB)
#define UL(k) LT(SHIFT,k)
#define DL(k) LT(SYMB,k)
#define NL(k) LT(NAV,k)

// TODO: tap dance app+app -> esc
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_moonlander(
    KC_ESC,          KC_1,            KC_2,            KC_3,            KC_4,            KC_5,            XXXXXXX,                   XXXXXXX,         KC_6,            KC_7,            KC_8,            KC_9,            KC_0,            MO(KEYB),
    KC_DLR,          KC_Q,            KC_W,            KC_E,            KC_R,            KC_T,            KC_TAB,                    S(KC_TAB),       KC_Y,            KC_U,            KC_I,            KC_O,            KC_P,            KC_BSLASH,
    DL(KC_GRAVE),    KC_A,            KC_S,            KC_D,            KC_F,            KC_G,            KC_DEL,                    KC_BSPACE,       KC_H,            KC_J,            KC_K,            KC_L,            KC_B,            NL(KC_QUOT),
    KC_LGUI,         CTL_T(KC_SCOLON),KC_Z,            KC_X,            KC_C,            KC_V,                                                        KC_N,            KC_M,            KC_COMMA,        KC_DOT,          RALT_T(KC_SLSH), KC_RGUI,
    KC_WPREV,        KC_LEFT,         KC_RIGHT,        KC_UP,           KC_DOWN,                          KC_APP,                    KC_ESC,                           KC_MINUS,        KC_LBRC,         KC_RBRC,         KC_EQUAL,        KC_WNEXT,
                                                                        UL(KC_APP),      DL(KC_TAB),      KC_COPY,                   KC_PASTE,        NL(KC_ENT),      KC_SPACE
   ),
  [SHIFT] = LAYOUT_moonlander(
    _______,         _______,         _______,         _______,         _______,         _______,         _______,                   _______,         _______,         _______,         _______,         _______,         _______,         _______,
    _______,         _______,         _______,         _______,         _______,         _______,         _______,                   _______,         _______,         _______,         _______,         _______,         _______,         _______,
    _______,         _______,         _______,         _______,         _______,         _______,         _______,                   _______,         _______,         _______,         _______,         _______,         _______,         _______,
    _______,         _______,         _______,         _______,         _______,         _______,                                                     _______,         _______,         _______,         _______,         _______,         _______,
    _______,         _______,         _______,         _______,         _______,                          _______,                   _______,                          _______,         _______,         _______,         _______,         _______,
                                                                        _______,         _______,         _______,                   _______,         _______,         KC_ENT
  ),
  [SYMB] = LAYOUT_moonlander(
    _______,         _______,         _______,         _______,         _______,         _______,         _______,                   _______,         _______,         _______,         _______,         _______,         _______,         _______,
    _______,         _______,         KC_AMPR,         KC_PIPE,         _______,         KC_AT,           _______,                   _______,         KC_ASTR,         KC_7,            KC_8,            KC_9,            KC_HASH,         _______,
    _______,         KC_LBRC,         KC_RBRC,         KC_LPRN,         KC_RPRN,         KC_UNDS,         _______,                   _______,         KC_MINUS,        KC_4,            KC_5,            KC_6,            KC_EQL,          _______,
    _______,         KC_LABK,         KC_RABK,         KC_LCBR,         KC_RCBR,         KC_DLR,                                                      KC_PLUS,         KC_1,            KC_2,            KC_3,            KC_EXLM,         _______,
    _______,         _______,         _______,         _______,         _______,                          _______,                   _______,                          KC_0,            KC_LPRN,         KC_RPRN,         _______,         _______,
                                                                        _______,         _______,         _______,                   _______,         _______,         _______
  ),
  [NAV] = LAYOUT_moonlander(
    _______,         _______,         _______,         _______,         _______,         _______,         _______,                   _______,         _______,         _______,         _______,         _______,         _______,         _______,
    _______,         _______,         KC_MS_WH_UP,     KC_MS_UP,        KC_MS_WH_DOWN,   _______,         _______,                   _______,         _______,         KC_PGUP,         _______,         KC_PGDOWN,       _______,         _______,
    MO(SHIFT),       _______,         KC_MS_LEFT,      KC_MS_DOWN,      KC_MS_RIGHT,     _______,         _______,                   _______,         KC_LEFT,         KC_DOWN,         KC_UP,           KC_RIGHT,        _______,         _______,
    _______,         _______,         _______,         _______,         _______,         _______,                                                     _______,         _______,         _______,         _______,         _______,         _______,
    _______,         _______,         _______,         _______,         _______,                          _______,                   _______,                          _______,         _______,         _______,         _______,         _______,
                                                                        KC_MS_BTN1,      KC_MS_BTN2,      KC_MS_BTN3,                _______,         _______,         _______
  ),
  [KEYB] = LAYOUT_moonlander(
    _______,         _______,         _______,         _______,         _______,         _______,         _______,                   _______,         _______,         _______,         _______,         _______,         _______,         _______,
    _______,         _______,         _______,         _______,         _______,         _______,         _______,                   _______,         _______,         _______,         _______,         _______,         _______,         _______,
    _______,         _______,         _______,         _______,         _______,         _______,         _______,                   _______,         _______,         _______,         _______,         _______,         _______,         _______,
    _______,         _______,         _______,         _______,         _______,         _______,                                                     _______,         _______,         _______,         _______,         _______,         _______,
    RESET,           _______,         _______,         _______,         _______,                          _______,                   _______,                          _______,         _______,         _______,         _______,         _______,
                                                                        _______,         _______,         _______,                   _______,         _______,         _______
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (IS_LAYER_ON(SHIFT)) {
        if (keymap_key_to_keycode(SHIFT, record->event.key) == KC_TRANSPARENT) {
            if (record->event.pressed) {
                add_mods(MOD_LSFT);
            } else {
                del_mods(MOD_LSFT);
            }
        }
    }
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    #ifdef RGB_MATRIX_ENABLE
    if (rgb_matrix_is_enabled()) {
        rgblight_mode(1);
        switch (get_highest_layer(state)) {
        case BASE:
            rgblight_sethsv(190,255,255);
            break;
        case SHIFT:
            break;
        case SYMB:
            break;
        case NAV:
            break;
        case KEYB:
            rgblight_sethsv(255,0,255);
            break;
        default: //  for any other layers, or the default layer
            break;
        }
    }
    #endif
    return state;
}

void keyboard_post_init_user(void) {
    if (!rgb_matrix_is_enabled()) {
        return;
    }
    rgblight_mode(1);
    rgblight_sethsv(190,255,255);
}

void rgb_matrix_indicators_user(void) {
    if (!rgb_matrix_is_enabled()) {
        return;
    }
    #ifdef RGB_MATRIX_ENABLE
    switch (get_highest_layer(layer_state)) {
    case BASE:
        break;
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
    case NAV:
        // movement
        rgb_matrix_set_color(12, 0xff, 0x00, 0xff);
        rgb_matrix_set_color(16, 0xff, 0x00, 0xff);
        rgb_matrix_set_color(17, 0xff, 0x00, 0xff);
        rgb_matrix_set_color(22, 0xff, 0x00, 0xff);

        // scroll
        rgb_matrix_set_color(11, 0xff, 0x00, 0x55);
        rgb_matrix_set_color(21, 0xff, 0x00, 0x55);

        // arrows
        rgb_matrix_set_color(63, 0xff, 0x00, 0xff);
        rgb_matrix_set_color(58, 0xff, 0x00, 0xff);
        rgb_matrix_set_color(53, 0xff, 0x00, 0xff);
        rgb_matrix_set_color(48, 0xff, 0x00, 0xff);

        // page
        rgb_matrix_set_color(47, 0xff, 0x00, 0x55);
        rgb_matrix_set_color(57, 0xff, 0x00, 0x55);

        // Buttons
        rgb_matrix_set_color(32, 0x00, 0x00, 0xff);
        rgb_matrix_set_color(33, 0x00, 0x00, 0xff);
        rgb_matrix_set_color(34, 0x00, 0x00, 0xff);
        break;
    case KEYB:
        break;
    default:
        break;
    }
    #endif
}
