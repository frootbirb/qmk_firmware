#include "planck.h"

// Prettify common keycodes
#define ____ KC_TRNS
#define xxxx KC_NO
#define SFT_ENT MT(MOD_LSFT, KC_ENT)

#define PAREN TD(PARENTHESES)
#define BRACE TD(BRACES)
#define BRACK TD(BRACKETS)
#define ABRCK TD(ANGLE_BRACKETS)

// Tap Dance Declarations
enum {
    PARENTHESES = 0,
    BRACES,
    BRACKETS,
    ANGLE_BRACKETS,
    COPY_PASTE_MAC,
    COPY_PASTE,
};

// Key combo definitions
enum combos {
	CMB_A = 0,
	CMB_S,
	CMB_D,
	CMB_F,
	CMB_G,
	CMB_H,
	CMB_J,
	CMB_K,
	CMB_L,
	CMB_SCLN,
};

const uint16_t PROGMEM A_combo[] = {KC_Q, KC_Z, COMBO_END};
const uint16_t PROGMEM S_combo[] = {KC_W, KC_X, COMBO_END};
const uint16_t PROGMEM D_combo[] = {KC_E, KC_C, COMBO_END};
const uint16_t PROGMEM F_combo[] = {KC_R, KC_V, COMBO_END};
const uint16_t PROGMEM G_combo[] = {KC_T, KC_B, COMBO_END};
const uint16_t PROGMEM H_combo[] = {KC_Y, KC_N, COMBO_END};
const uint16_t PROGMEM J_combo[] = {KC_U, KC_M, COMBO_END};
const uint16_t PROGMEM K_combo[] = {KC_I, KC_COMM, COMBO_END};
const uint16_t PROGMEM L_combo[] = {KC_O, KC_DOT, COMBO_END};
const uint16_t PROGMEM scln_combo[] = {KC_P, KC_UP, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
	[CMB_A] = COMBO(A_combo, KC_A),
	[CMB_S] = COMBO(S_combo, KC_S),
	[CMB_D] = COMBO(D_combo, KC_D),
	[CMB_F] = COMBO(F_combo, KC_F),
	[CMB_G] = COMBO(G_combo, KC_G),
	[CMB_H] = COMBO(H_combo, KC_H),
	[CMB_J] = COMBO(J_combo, KC_J),
	[CMB_K] = COMBO(K_combo, KC_K),
	[CMB_L] = COMBO(L_combo, KC_L),
	[CMB_SCLN] = COMBO(scln_combo, KC_SCLN),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    KEYMAP(
        KC_ESC,  KC_Q,    KC_W,    KC_E, KC_R,  KC_T,    KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,    xxxx,
        KC_TAB,  KC_Z,    KC_X,    KC_C, KC_V,  KC_B,    KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SCLN, KC_QUOT,
        MO(2),   KC_1,    KC_2,    KC_3, KC_4,  KC_5,    KC_6,   KC_7,    KC_8,    KC_9,    KC_0,    KC_UP,
        KC_LCTL, KC_LWIN, KC_LALT, xxxx, MO(1), SFT_ENT, KC_SPC, KC_BSPC, xxxx,    KC_LEFT, KC_RGHT, KC_DOWN
    ),
 
    KEYMAP( // symbol layer
        RESET, KC_TILD, KC_QUES, KC_EXLM, KC_SLSH, KC_AMPR, KC_PIPE, KC_UNDS, KC_AT,   KC_HASH, KC_DLR,  ____,
        ____,  KC_PLUS, KC_MINS, KC_ASTR, KC_BSLS, KC_EQL,  ____,    PAREN,   BRACE,   BRACK,   ABRCK,   KC_GRV,
        ____,  ____,    ____,    ____,    ____,    ____,    ____,    KC_CIRC, KC_PERC, ____,    ____,    ____,
        ____,  ____,    ____,    ____,    ____,    ____,    ____,    KC_DEL,  ____,    ____,    ____,    ____
    ),

    KEYMAP( // navigation layer
        KC_PWR, KC_F1, KC_F2,  KC_F3,  KC_F4,  ____, ____, ____,   ____,    ____,    ____,    ____,
        ____,   KC_F5, KC_F6,  KC_F7,  KC_F8,  ____, ____, KC_INS, KC_NLCK, KC_CAPS, KC_SLCK, ____,
        ____,   KC_F9, KC_F10, KC_F11, KC_F12, ____, ____, ____,   ____,    ____,    ____,    KC_PGUP,
        ____,   ____,  ____,   ____,   ____,   ____, ____, ____,   ____,    KC_HOME, KC_END,  KC_PGDN
    ),
};
