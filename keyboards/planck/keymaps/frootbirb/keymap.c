#include "planck.h"
#include "frootbirb.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    KEYMAP(
        KC_ESC,  KC_Q,    KC_W,    KC_E, KC_R,   KC_T,    KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_TAB,  KC_A,    KC_S,    KC_D, KC_F,   KC_G,    KC_H,   KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        MO(NUM), KC_Z,    KC_X,    KC_C, KC_V,   KC_B,    KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_LSFT,
        KC_LCTL, KC_LGUI, KC_LALT, COPY, KC_SPC, SFT_ENT, KC_SPC, MO(NAV), xxxx,    KC_LEFT, KC_DOWN, KC_RGHT
    ),

    KEYMAP( // mac layer
        ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
        ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
        ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
        ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____
    ),

    KEYMAP( // symbol layer
        RESET, ____,    ____,    ____,    ____,    ____,    ____,    KC_UNDS, KC_AT,   KC_HASH, KC_DLR,  KC_DEL,
        ____,  KC_TILD, KC_QUES, KC_EXLM, KC_SLSH, KC_AMPR, KC_PIPE, PAREN,   BRACE,   BRACK,   ABRCK,   KC_GRV,
        ____,  KC_PLUS, KC_MINS, KC_ASTR, KC_BSLS, KC_EQL,  ____,    KC_CIRC, KC_PERC, ____,    ____,    ____,
        ____,  ____,    ____,    ____,    ____,    ____,    ____,    ____,    ____,    ____,    ____,    ____
    ),

    KEYMAP( // nav layer
        KC_PWR, KC_F1, KC_F2,  KC_F3,  KC_F4,  ____, ____, ____,   ____,    ____,    ____,    LGUI(KC_S),
        ____,   KC_F5, KC_F6,  KC_F7,  KC_F8,  ____, ____, KC_INS, KC_NLCK, KC_CAPS, KC_SLCK, ____,
        ____,   KC_F9, KC_F10, KC_F11, KC_F12, ____, ____, ____,   ____,    KC_PSCR, KC_PGUP, ____,
        ____,   ____,  ____,   ____,   ____,   ____, ____, ____,   ____,    KC_HOME, KC_PGDN, KC_END
    ),

    KEYMAP( // num layer
        ____, KC_MINS, KC_7, KC_8, KC_9, KC_ASTR, ____, ____, ____, ____, ____, ____,
        ____, KC_PLUS, KC_4, KC_5, KC_6, KC_SLSH, ____, ____, ____, ____, ____, ____,
        ____, KC_EQL,  KC_1, KC_2, KC_3, KC_DOT,  ____, ____, ____, ____, ____, ____,
        ____, ____,    ____, ____, KC_0, ____,    ____, ____, ____, ____, ____, ____
    )
};
