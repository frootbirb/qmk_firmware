#include "planck.h"
#include "frootbirb.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    KEYMAP(
        KC_ESC,  KC_Q,  KC_W,  KC_E, KC_R,    KC_T,    KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,    FIND,
        KC_TAB,  KC_A,  KC_S,  KC_D, KC_F,    KC_G,    KC_H,   KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        MO(NAV), KC_Z,  KC_X,  KC_C, KC_V,    KC_B,    KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_RSFT,
        MOD_1,   MOD_2, MOD_3, COPY, MO(SYM), SFT_ENT, KC_SPC, KC_BSPC, xxxx,    KC_LEFT, KC_DOWN, KC_RGHT
    ),
 
    KEYMAP( // symbol layer
        RESET, ____,    ____,    ____,    ____,    ____,    ____,    KC_UNDS, KC_AT,   KC_HASH, KC_DLR, ____,
        ____,  KC_TILD, KC_QUES, KC_EXLM, KC_SLSH, KC_AMPR, KC_PIPE, PAREN,   BRACE,   BRACK,   ABRCK,  KC_GRV,
        ____,  KC_PLUS, KC_MINS, KC_ASTR, KC_BSLS, KC_EQL,  ____,    KC_CIRC, KC_PERC, ____,    ____,   ____,
        ____,  ____,    ____,    ____,    ____,    ____,    ____,    ____,    ____,    ____,    ____,   ____
    ),

    KEYMAP( // navigation layer
        KC_PWR, KC_F1, KC_F2,  KC_F3,  KC_F4,  ____, ____, ____,   ____,    ____,    ____,    SYS_FND,
        ____,   KC_F5, KC_F6,  KC_F7,  KC_F8,  ____, ____, KC_INS, KC_NLCK, KC_CAPS, KC_SLCK, ____,
        ____,   KC_F9, KC_F10, KC_F11, KC_F12, ____, ____, ____,   ____,    SCRNSHT, KC_PGUP, KC_CAPS,
        MOD_4,  MOD_5, MOD_6,  ____,   ____,   ____, ____, KC_DEL, TOG_OS,  KC_HOME, KC_PGDN, KC_END
    ), 
};
