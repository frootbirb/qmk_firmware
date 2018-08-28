#include "xd75.h" 

// Layer Definitions
#define DEF 0
#define MAC 1
#define SYM 2
#define NAV 3

// Prettify common keycodes
#define ____ KC_TRNS
#define xxxx KC_NO

// Prettify long keycodes
#define COPY TD(COPY_PASTE)
#define MACCOPY TD(COPY_PASTE_MAC)

#define PAREN TD(PARENTHESES)
#define BRACE TD(BRACES)
#define BRACK TD(BRACKETS)
#define ABRCK TD(ANGLE_BRACKETS)

#define SFT_ENT MT(MOD_LSFT, KC_ENT)
#define MAC_LCK RGUI(LCTL(KC_Q))
#define MAC_SCR RGUI(S(KC_4))

// Macro definitions
void copy_paste_mac(qk_tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            register_code(KC_RGUI); register_code(KC_V); unregister_code(KC_V); unregister_code(KC_RGUI);
            break;
        case 2:
            register_code(KC_RGUI); register_code(KC_C); unregister_code(KC_C); unregister_code(KC_RGUI);
            break;
    }
}

void copy_paste(qk_tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            register_code(KC_LCTL); register_code(KC_V); unregister_code(KC_V); unregister_code(KC_LCTL);
            break;
        case 2:
            register_code(KC_LCTL); register_code(KC_C); unregister_code(KC_C); unregister_code(KC_LCTL);
            break;
    }
}

// Tap Dance Declarations
enum {
    PARENTHESES = 0,
    BRACES,
    BRACKETS,
    ANGLE_BRACKETS,
    COPY_PASTE_MAC,
    COPY_PASTE
};

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [PARENTHESES] = ACTION_TAP_DANCE_DOUBLE(KC_LEFT_PAREN, KC_RIGHT_PAREN),
    [BRACES] = ACTION_TAP_DANCE_DOUBLE(KC_LEFT_CURLY_BRACE, KC_RIGHT_CURLY_BRACE),
    [BRACKETS] = ACTION_TAP_DANCE_DOUBLE(KC_LBRACKET, KC_RBRACKET),
    [ANGLE_BRACKETS] = ACTION_TAP_DANCE_DOUBLE(KC_LEFT_ANGLE_BRACKET, KC_RIGHT_ANGLE_BRACKET),
    [COPY_PASTE_MAC] = ACTION_TAP_DANCE_FN(copy_paste_mac),
    [COPY_PASTE] = ACTION_TAP_DANCE_FN(copy_paste)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    KEYMAP(
        xxxx,    KC_1,    KC_2,    KC_3, KC_4,   KC_5,    KC_PSLS, KC_EQL, KC_PMNS, KC_6,   KC_7,    KC_8,    KC_9,    KC_0,    RCTL(KC_F),
        KC_ESC,  KC_Q,    KC_W,    KC_E, KC_R,   KC_T,    KC_P7,   KC_P8,  KC_P9,   KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,    xxxx,
        KC_TAB,  KC_A,    KC_S,    KC_D, KC_F,   KC_G,    KC_P4,   KC_P5,  KC_P6,   KC_H,   KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C, KC_V,   KC_B,    KC_P1,   KC_P2,  KC_P3,   KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_LSFT,
        KC_LCTL, KC_LWIN, KC_LALT, COPY, KC_SPC, SFT_ENT, MO(SYM), KC_P0,  KC_BSPC, KC_SPC, MO(NAV), DF(MAC), KC_LEFT, KC_DOWN, KC_RGHT
    ),

    KEYMAP( // mac layer
        MAC_LCK, ____,    ____,    ____,    ____, ____, ____, ____, ____, ____, ____, ____,    ____, ____, RGUI(KC_F),
        ____,    ____,    ____,    ____,    ____, ____, ____, ____, ____, ____, ____, ____,    ____, ____, ____,
        ____,    ____,    ____,    ____,    ____, ____, ____, ____, ____, ____, ____, ____,    ____, ____, ____,
        xxxx,    ____,    ____,    ____,    ____, ____, ____, ____, ____, ____, ____, ____,    ____, ____, ____,
        KC_RCMD, KC_LALT, KC_LCTL, MACCOPY, ____, ____, ____, ____, ____, ____, ____, DF(DEF), ____, ____, ____
    ),

    KEYMAP( // symbol layer
        RESET, ____,    ____,    ____,    ____,    ____,    ____, ____, ____,   ____,    ____,    ____,    ____,    ____,    ____,
        ____,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    ____, ____, ____,   ____,    KC_UNDS, KC_AT,   KC_HASH, KC_DLR,  ____,
        ____,  KC_TILD, KC_QUES, KC_EXLM, KC_SLSH, KC_AMPR, ____, ____, ____,   KC_PIPE, PAREN,   BRACE,   BRACK,   ABRCK,   KC_GRV,
        ____,  KC_PLUS, KC_MINS, KC_ASTR, KC_BSLS, KC_EQL,  ____, ____, ____,   ____,    KC_CIRC, KC_PERC, ____,    ____,    ____,
        ____,  ____,    ____,    ____,    ____,    ____,    ____, ____, KC_DEL, ____,    ____,    ____,    ____,    ____,    ____
    ),

    KEYMAP( // function layer
        KC_PWR, ____,  ____,   ____,   ____,   ____, ____, ____, ____, ____, ____,    ____,    ____,    ____,    RGUI(KC_SPC),
        ____,   KC_F1, KC_F2,  KC_F3,  KC_F4,  ____, ____, ____, ____, ____, RGB_TOG, RGB_VAD, RGB_VAI, ____,    ____,
        ____,   KC_F5, KC_F6,  KC_F7,  KC_F8,  ____, ____, ____, ____, ____, KC_INS,  KC_NLCK, KC_CAPS, KC_SLCK, ____,
        ____,   KC_F9, KC_F10, KC_F11, KC_F12, ____, ____, ____, ____, ____, ____,    ____,    MAC_SCR, KC_PGUP, ____,
        ____,   ____,  ____,   ____,   ____,   ____, ____, ____, ____, ____, ____,    ____,    KC_HOME, KC_PGDN, KC_END
    ),
};
