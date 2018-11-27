#ifndef FROOTBIRB
#define FROOTBIRB

#include "quantum.h"

// Layer Definitions
#define DEF 0
#define MAC 1
#define SYM 2
#define NAV 3
#define NUM 4

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
#define SYM_SPC LT(SYM, KC_SPC)
#define NAV_DOT LT(NAV, KC_DOT)
#define MAC_LCK RGUI(LCTL(KC_Q))
#define MAC_SCR RGUI(S(KC_4))
#define TAB_NUM LT(NUM, KC_TAB)

// Macro definitions
void copy_paste_mac(qk_tap_dance_state_t *state, void *user_data);
void copy_paste(qk_tap_dance_state_t *state, void *user_data);

// Tap Dance Declarations
enum {
    PARENTHESES = 0,
    BRACES,
    BRACKETS,
    ANGLE_BRACKETS,
    COPY_PASTE_MAC,
    COPY_PASTE
};

#endif
