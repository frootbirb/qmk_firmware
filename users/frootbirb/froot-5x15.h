#include QMK_KEYBOARD_H
#include "frootbirb.h"

// ---------------------- Key Combos ---------------------- //

// Key combo definitions
enum combos {
	CMB_PPLS = 0,
	CMB_PAST,
};

// Pressing the - and = numpad keys makes +
const uint16_t PROGMEM pls_combo[] = {KC_PMNS, KC_EQL, COMBO_END};
// Pressing the / and = numpad keys makes *
const uint16_t PROGMEM ast_combo[] = {KC_PSLS, KC_EQL, COMBO_END};

combo_t key_combos[] = {
	[CMB_PPLS] = COMBO(pls_combo, KC_PPLS),
	[CMB_PAST] = COMBO(ast_combo, KC_PAST),
};

// ---------------------- Keymap ---------------------- //

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[DEF] = LAYOUT_ortho_5x15(
		xxxx,    KC_1,    KC_2,    KC_3,    KC_4,   KC_5,    KC_PMNS, KC_EQL, KC_PSLS, KC_6,   KC_7,    KC_8,    KC_9,    KC_0,    LWIN(LSFT(KC_S)),
		KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,    KC_P7,   KC_P8,  KC_P9,   KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,    LCTL(KC_F),
		KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,   KC_G,    KC_P4,   KC_P5,  KC_P6,   KC_H,   KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
		KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,    KC_P1,   KC_P2,  KC_P3,   KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_RSFT,
		KC_LCTL, KC_LWIN, KC_LALT, W_PASTE, KC_SPC, SFT_ENT, MO(SYM), KC_P0,  NAV_DOT, KC_SPC, KC_BSPC, KC_DEL,  KC_LEFT, KC_DOWN, KC_RGHT
	),

	[SYM] = LAYOUT_ortho_5x15(
		QK_BOOT, _______, _______, _______, _______, _______, ____, ____, ____, _______, _______, _______, _______, _______, TSKMGR,
		_______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    ____, ____, ____, KC_PERC, KC_UNDS, KC_AT,   KC_HASH, KC_DLR,  ____,
		_______, KC_TILD, KC_QUES, KC_EXLM, KC_SLSH, KC_AMPR, ____, ____, ____, KC_PIPE, KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC, KC_GRV,
		_______, KC_PLUS, KC_MINS, KC_ASTR, KC_BSLS, KC_EQL,  ____, ____, ____, KC_CIRC, KC_LCBR, KC_RCBR, KC_LT,   KC_GT,   ____,
		_______, _______, _______, _______, _______, _______, ____, ____, ____, _______, _______, _______, _______, _______, ____
	),

	[NAV] = LAYOUT_ortho_5x15(
		KC_PWR,  ____,  ____,   ____,   ____,   ____, ____, ____, ____, ____, _______, UG_HUED, UG_HUEU, _______, PASSWRD,
		_______, KC_F1, KC_F2,  KC_F3,  KC_F4,  ____, ____, ____, ____, ____, UG_TOGG, UG_VALD, UG_VALU, UG_NEXT, LWIN(KC_S),
		_______, KC_F5, KC_F6,  KC_F7,  KC_F8,  ____, ____, ____, ____, ____, KC_INS,  KC_NUM,  KC_CAPS, KC_SCRL, ____,
		KC_CAPS, KC_F9, KC_F10, KC_F11, KC_F12, ____, ____, ____, ____, ____, _______, _______, _______, KC_PGUP, KC_CAPS,
		_______, ____,  ____,   ____,   ____,   ____, ____, ____, ____, ____, _______, TG(MAC), KC_HOME, KC_PGDN, KC_END
	),

	[MAC] = LAYOUT_ortho_5x15(
		_______, _______, _______, _______, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, LCMD(LSFT(KC_4)),
		_______, _______, _______, _______, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, LCMD(KC_F),
		_______, _______, _______, _______, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
		_______, _______, _______, _______, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
		KC_LCMD, KC_LOPT, KC_LCTL, M_PASTE, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____
	),
};
