#include "frootbirb.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    LAYOUT_ortho_5x15(
        xxxx,    KC_1,    KC_2,    KC_3, KC_4,   KC_5,    KC_PAST, KC_EQL, KC_PMNS, KC_6,   KC_7,    KC_8,    KC_9,    KC_0,    RCTL(KC_F),
        KC_ESC,  KC_Q,    KC_W,    KC_E, KC_R,   KC_T,    KC_P7,   KC_P8,  KC_P9,   KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,    xxxx,
        KC_TAB,  KC_A,    KC_S,    KC_D, KC_F,   KC_G,    KC_P4,   KC_P5,  KC_P6,   KC_H,   KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C, KC_V,   KC_B,    KC_P1,   KC_P2,  KC_P3,   KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_LSFT,
        KC_LCTL, KC_LWIN, KC_LALT, COPY, KC_SPC, SFT_ENT, SYM_SLS, KC_P0,  NAV_DOT, KC_SPC, KC_BSPC, xxxx,    KC_LEFT, KC_DOWN, KC_RGHT
    ),

    LAYOUT_ortho_5x15( // mac layer
        MAC_LCK, ____,    ____,    ____,    ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, RGUI(KC_F),
        ____,    ____,    ____,    ____,    ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
        ____,    ____,    ____,    ____,    ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
        ____,    ____,    ____,    ____,    ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
        KC_RCMD, KC_LALT, KC_LCTL, MACCOPY, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____
    ),

    LAYOUT_ortho_5x15( // symbol layer
        RESET, ____,    ____,    ____,    ____,    ____,    ____, ____, ____, ____,    ____,    ____,    ____,    ____,    ____,
        ____,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    ____, ____, ____, ____,    KC_UNDS, KC_AT,   KC_HASH, KC_DLR,  ____,
        ____,  KC_TILD, KC_QUES, KC_EXLM, KC_SLSH, KC_AMPR, ____, ____, ____, KC_PIPE, PAREN,   BRACE,   BRACK,   ABRCK,   KC_GRV,
        ____,  KC_PLUS, KC_MINS, KC_ASTR, KC_BSLS, KC_EQL,  ____, ____, ____, ____,    KC_CIRC, KC_PERC, ____,    ____,    ____,
        ____,  ____,    ____,    ____,    ____,    ____,    ____, ____, ____, ____,    KC_DEL,  ____,    ____,    ____,    ____
    ),

    LAYOUT_ortho_5x15( // function layer
        KC_PWR, ____,  ____,   ____,   ____,   ____, ____, ____, ____, ____, ____,    ____,    ____,    ____,    RGUI(KC_SPC),
        ____,   KC_F1, KC_F2,  KC_F3,  KC_F4,  ____, ____, ____, ____, ____, RGB_TOG, RGB_VAD, RGB_VAI, ____,    ____,
        ____,   KC_F5, KC_F6,  KC_F7,  KC_F8,  ____, ____, ____, ____, ____, KC_INS,  KC_NLCK, KC_CAPS, KC_SLCK, ____,
        ____,   KC_F9, KC_F10, KC_F11, KC_F12, ____, ____, ____, ____, ____, ____,    ____,    MAC_SCR, KC_PGUP, ____,
        ____,   ____,  ____,   ____,   ____,   ____, ____, ____, ____, ____, ____,    TG(MAC), KC_HOME, KC_PGDN, KC_END
    ),
};
