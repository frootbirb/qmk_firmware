#include "xd75.h"

// Layer Definitions
#define DEF 0
#define MAC 1
#define SYM 2
#define NAV 3

// Prettify common keycodes
#define __ KC_TRNS
#define xx KC_NO

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
  PAREN = 0,
  BRACE,
  BRCK,
  A_BRCK,
  CPM,
  CP
};

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  [PAREN] = ACTION_TAP_DANCE_DOUBLE(KC_LEFT_PAREN, KC_RIGHT_PAREN),
  [BRACE] = ACTION_TAP_DANCE_DOUBLE(KC_LEFT_CURLY_BRACE, KC_RIGHT_CURLY_BRACE),
  [BRCK] = ACTION_TAP_DANCE_DOUBLE(KC_LBRACKET, KC_RBRACKET),
  [A_BRCK] = ACTION_TAP_DANCE_DOUBLE(KC_LEFT_ANGLE_BRACKET, KC_RIGHT_ANGLE_BRACKET),
  [CPM] = ACTION_TAP_DANCE_FN(copy_paste_mac),
  [CP] = ACTION_TAP_DANCE_FN(copy_paste)
  };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    KEYMAP(
        xx,		KC_1,		KC_2,		KC_3,	KC_4,	KC_5,			KC_PSLS,	KC_EQUAL,	KC_PMNS,	KC_6,		KC_7,		KC_8,		KC_9,		KC_0,		RCTL(KC_F),
        KC_ESC,		KC_Q,		KC_W,		KC_E,	KC_R,	KC_T,			KC_KP_7,	KC_KP_8,	KC_KP_9,	KC_Y,		KC_U,		KC_I,		KC_O,		KC_P,		xx,
        KC_TAB,		KC_A,		KC_S,		KC_D,	KC_F,	KC_G,			KC_KP_4,	KC_KP_5,	KC_KP_6,	KC_H,		KC_J,		KC_K,		KC_L,		KC_SCLN,	KC_QUOT,
	KC_LSFT,	KC_Z,		KC_X,		KC_C,	KC_V,	KC_B,			KC_KP_1,	KC_KP_2,	KC_KP_3,	KC_N,		KC_M,		KC_COMM,	KC_DOT,		KC_UP,		KC_LSFT,
        KC_LCTRL,	KC_LWIN,	KC_LALT,	TD(CP),	KC_SPC,	MT(MOD_LSFT, KC_ENT),	MO(SYM),	KC_KP_0,	KC_BSPC,	KC_SPC,		MO(NAV),	DF(MAC),	KC_LEFT,	KC_DOWN,	KC_RGHT
	),

    KEYMAP( // mac layer
        RGUI(LCTL(KC_Q)),	__,		__,		__,		__,	__,	__,	__,	__,	__,	__,	__,		__,	__,	RGUI(KC_F),
        __,			__,		__,		__,		__,	__,	__,	__,	__,	__,	__,	__,		__,	__,	__,
        __,			__,		__,		__,		__,	__,	__,	__,	__,	__,	__,	__,		__,	__,	__,
        xx,			__,		__,		__,		__,	__,	__,	__,	__,	__,	__,	__,		__,	__,	__,
        KC_RCMD,		KC_LALT,	KC_LCTRL,	TD(CPM),	__,	__,	__,	__,	__,	__,	__,	DF(DEF),	__,	__,	__
	),

    KEYMAP( // symbol layer
        KC_PWR,	__,		__,		__,		__,		__,		__,	__,	__,	__,		__,		__,		__,		__,		__,
        __,	KC_6,		KC_7,		KC_8,		KC_9,		KC_0,		__,	__,	__,	__,		KC_UNDS,	KC_AT,		KC_HASH,	KC_DLR,		__,
        __,	KC_TILD,	KC_QUES,	KC_EXLM,	KC_SLSH,	KC_AMPR,	__,	__,	__,	KC_PIPE,	TD(PAREN),	TD(BRACE),	TD(BRCK),	TD(A_BRCK),	KC_GRV,
        __,	KC_PLUS,	KC_MINUS,	KC_ASTR,	KC_BSLS,	KC_EQL,		__,	__,	__,	__,		KC_CIRC,	KC_PERC,	__,		__,		__,
        __,	__,		__,		__,		__,		__,		__,	__,	KC_DEL,	__,		__,		__,		__,		__,		__
	),

    KEYMAP( // function layer
        RESET,	__,	__,	__,	__,	__,	__,	__,	__,	__,	__,		__,		__,		__,		RGUI(KC_SPC),
        __,	KC_F1,	KC_F2,	KC_F3,	KC_F4,	__,	__,	__,	__,	__,	RGB_TOG,	RGB_VAD,	RGB_VAI,	__,		__,
        __,	KC_F5,	KC_F6,	KC_F7,	KC_F8,	__,	__,	__,	__,	__,	KC_INS,		KC_NLCK,	KC_CAPS,	KC_SLCK,	__,
        __,	KC_F9,	KC_F10,	KC_F11,	KC_F12,	__,	__,	__,	__,	__,	__,		__,		RGUI(S(KC_4)),	KC_PGUP,	__,
        __,	__,	__,	__,	__,	__,	__,	__,	__,	__,	__,		__,		KC_HOME,	KC_PGDN,	KC_END
	),

};
