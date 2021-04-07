#include QMK_KEYBOARD_H
#include "frootbirb.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [DEF] = LAYOUT_6x6(
		xxxx,    KC_1,  KC_2,  KC_3, KC_4, KC_5,                                          KC_6,   KC_7, KC_8,    KC_9,    KC_0,    xxxx,
		KC_ESC,  KC_Q,  KC_W,  KC_E, KC_R, KC_T,                                          KC_Y,   KC_U, KC_I,    KC_O,    KC_P,    FIND,
		KC_TAB,  KC_A,  KC_S,  KC_D, KC_F, KC_G,                                          KC_H,   KC_J, KC_K,    KC_L,    KC_SCLN, KC_QUOT,
		KC_LSFT, KC_Z,  KC_X,  KC_C, KC_V, KC_B,   TG(NUM), TG(GAM),    xxxx,    TG(NUM), KC_N,   KC_M, KC_COMM, KC_DOT,  KC_UP,   KC_RSFT,
		MOD_1,   MOD_2, MOD_3, COPY, xxxx,                  MO(NAV),    MO(NAV),                  xxxx, xxxx,    KC_LEFT, KC_DOWN, KC_RGHT,
		                                   KC_SPC, SFT_ENT, MO(SYM),    MO(SYM), KC_SPC,  KC_BSPC
    ),
	[GAM] = LAYOUT_6x6(
		____, xxxx,    KC_1,  KC_2,  KC_3, KC_4,                              ____, ____, ____, ____, ____, ____,
		____, KC_ESC,  KC_Q,  KC_W,  KC_E, KC_R,                              ____, ____, ____, ____, ____, ____,
		____, KC_TAB,  KC_A,  KC_S,  KC_D, KC_F,                              ____, ____, ____, ____, ____, ____,
		____, KC_LSFT, KC_Z,  KC_X,  KC_C, KC_V, ____,   ____,    ____, ____, ____, ____, ____, ____, ____, ____,
		____, MOD_1,   MOD_2, MOD_3, COPY,               ____,    ____,             ____, ____, ____, ____, ____,
		                                   ____, KC_SPC, ____,    ____, ____, ____
    ),
	[NUM] = LAYOUT_6x6(
		____, ____, KC_PMNS, KC_EQL, KC_PSLS, ____,                            ____, KC_PMNS, KC_EQL, KC_PSLS, ____, ____,
		____, ____, KC_P7,   KC_P8,  KC_P9,   ____,                            ____, KC_P7,   KC_P8,  KC_P9,   ____, ____,
		____, ____, KC_P4,   KC_P5,  KC_P6,   ____,                            ____, KC_P4,   KC_P5,  KC_P6,   ____, ____,
		____, ____, KC_P1,   KC_P2,  KC_P3,   ____, ____, ____,    ____, ____, ____, KC_P1,   KC_P2,  KC_P3,   ____, ____,
		____, ____, ____,    KC_P0,  KC_DOT,              ____,    ____,             ____,    KC_P0,  KC_DOT,  ____, ____,
		                                      ____, ____, ____,    ____, ____, ____
    ),
    [SYM] = LAYOUT_6x6(
		RESET, ____,    ____,    ____,    ____,    ____,                                    ____,    ____,    ____,    ____,    ____,    ____,
		____,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                                    ____,    KC_UNDS, KC_AT,   KC_HASH, KC_DLR,  ____,
		____,  KC_TILD, KC_QUES, KC_EXLM, KC_SLSH, KC_AMPR,                                 KC_PIPE, PAREN,   BRACE,   BRACK,   ABRCK,   KC_GRV,
		____,  KC_PLUS, KC_MINS, KC_ASTR, KC_BSLS, KC_EQL, ____, ____,    ____, ____, ____, ____,    KC_CIRC, KC_PERC, ____,    ____,    ____,
		____,  ____,    ____,    ____,                           ____,    ____,                      ____,    ____,    ____,    ____,    ____,
		                                           ____,   ____, ____,    ____, ____, ____
    ),
    [NAV] = LAYOUT_6x6(
		KC_PWR, ____,  ____,   ____,   ____,   ____,                                   ____, ____,    RGB_HUD, RGB_HUI, ____,    PASSWD,
		____,   KC_F1, KC_F2,  KC_F3,  KC_F4,  ____,                                   ____, RGB_TOG, RGB_VAD, RGB_VAI, RGB_MOD, SYS_FND,
		____,   KC_F5, KC_F6,  KC_F7,  KC_F8,  ____,                                   ____, KC_INS,  KC_NLCK, KC_CAPS, KC_SLCK, ____,
		____,   KC_F9, KC_F10, KC_F11, KC_F12, ____, ____, ____,    ____, ____, ____,  ____, ____,    ____,    SCRNSHT, KC_PGUP, KC_CAPS,
		MOD_4,  MOD_5, MOD_6,  ____,                       ____,    ____,                    ____,    TOG_OS,  KC_HOME, KC_PGDN, KC_END,
		                                       ____, ____, ____,    ____, ____, KC_DEL
    ),
};

void 
keyboard_pre_init_user(void) 
{ 
    setPinInputHigh(D0); 
    setPinInputHigh(D1); 
}

void keyboard_post_init_user(void) {
#ifdef CONSOLE_ENABLE
// Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  debug_keyboard=true;
#endif
}