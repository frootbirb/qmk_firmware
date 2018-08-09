#include "planck.h"

// Layer Definitions
#define NUM 1
#define NAV 2
#define SND 3

// Prettify common keycodes
#define __ KC_TRNS
#define xx KC_NO

// Macro definitions
void copy_paste(qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
    case 1:
      register_code(KC_LCTL); register_code(KC_C); unregister_code(KC_C); unregister_code(KC_LCTL); 
      break;
    case 2:
      register_code(KC_LCTL); register_code(KC_V); unregister_code(KC_V); unregister_code(KC_LCTL); 
      break;
  }
}

void copy_paste_all(qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
    case 1:
      register_code(KC_LCTL); register_code(KC_A); unregister_code(KC_A); register_code(KC_C); unregister_code(KC_C); unregister_code(KC_LCTL); 
      break;
    case 2:
      register_code(KC_LCTL); register_code(KC_V); unregister_code(KC_V); unregister_code(KC_LCTL); 
      break;
  }
}
 
// Tap Dance Declarations
enum {
  PAREN = 0,
  BRACE,
  BRCK,
  A_BRCK,
  CP,
  CPA
};

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  [PAREN] = ACTION_TAP_DANCE_DOUBLE(KC_LEFT_PAREN, KC_RIGHT_PAREN),
  [BRACE] = ACTION_TAP_DANCE_DOUBLE(KC_LEFT_CURLY_BRACE, KC_RIGHT_CURLY_BRACE),
  [BRCK] = ACTION_TAP_DANCE_DOUBLE(KC_LBRACKET, KC_RBRACKET),
  [A_BRCK] = ACTION_TAP_DANCE_DOUBLE(KC_LEFT_ANGLE_BRACKET, KC_RIGHT_ANGLE_BRACKET),
  [CP] = ACTION_TAP_DANCE_FN(copy_paste),
  [CPA] = ACTION_TAP_DANCE_FN(copy_paste_all)
  };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	KEYMAP(
		KC_ESC,		KC_Q,		KC_W,		KC_E,	KC_R,	KC_T,			KC_Y,	KC_U,		KC_I,		KC_O,		KC_P,		KC_BSPC,
		KC_TAB,		KC_A,		KC_S,		KC_D,	KC_F,	KC_G,			KC_H,	KC_J,		KC_K,		KC_L,		KC_SCLN,	KC_QUOT, 
		KC_LSFT,	KC_Z,		KC_X,		KC_C,	KC_V,	KC_B,			KC_N,	KC_M,		KC_COMM,	KC_DOT,		KC_UP,		TD(CP),
		KC_LCTRL,	KC_LGUI,	KC_LALT,	TD(CP),	KC_SPC,	LT(NUM,	KC_ENT),	KC_SPC,	MO(NAV),	OSL(SND),	KC_LEFT,	KC_DOWN,	KC_RGHT
	),

	KEYMAP(
		__,	KC_MINS,	KC_7,	KC_8,	KC_9,	KC_ASTR,	KC_TILD,	KC_UNDS,	KC_AT,		KC_HASH,	KC_DLR,		KC_DEL,
		__,	KC_PLUS,	KC_4,	KC_5,	KC_6,	KC_SLSH,	KC_BSLS,	TD(PAREN),	TD(BRACE),	TD(BRCK),	TD(A_BRCK),	KC_AMPR,
		__,	KC_EQL,		KC_1,	KC_2,	KC_3,	KC_GRV,		KC_CIRC,	KC_EXLM,	KC_QUES,	KC_PERC,	__,		TD(CPA),
		__,	__,		__,	KC_0,	KC_DOT,	__,		__,		__,		__,		__,		__,		__
	),

	KEYMAP(
		KC_PWR,	KC_F1,	KC_F2,	KC_F3,	KC_F4,	__,	__,	__,	__,		__,		__,		LGUI(KC_S),
		__,	KC_F5,	KC_F6,	KC_F7,	KC_F8,	__,	__,	KC_INS,	KC_NLCK,	KC_CAPS,	KC_SLCK,	__,
		__,	KC_F9,	KC_F10,	KC_F11,	KC_F12,	__,	__,	__,	__,		KC_PSCR,	KC_PGUP,	__,
		__,	__,	__,	__,	__,	__,	__,	__,	__,		KC_HOME,	KC_PGDN,	KC_END
	),

	KEYMAP(
		MEH(KC_F1),	MEH(KC_F2),	MEH(KC_F3),	MEH(KC_F4),	MEH(KC_F5),	MEH(KC_F6),	HYPR(KC_F1),	HYPR(KC_F2),	HYPR(KC_F3),	HYPR(KC_F4),	HYPR(KC_F5),	HYPR(KC_F6),
		MEH(KC_F7),	MEH(KC_F8),	MEH(KC_F9),	MEH(KC_F10),	MEH(KC_F11),	MEH(KC_F12),	HYPR(KC_F7),	HYPR(KC_F8),	HYPR(KC_F9),	HYPR(KC_F10),	HYPR(KC_F11),	HYPR(KC_F12), 
		MEH(KC_F13),	MEH(KC_F14),	MEH(KC_F15),	MEH(KC_F16),	MEH(KC_F17),	MEH(KC_F18),	HYPR(KC_F13),	HYPR(KC_F14),	HYPR(KC_F15),	HYPR(KC_F16),	HYPR(KC_F17),	HYPR(KC_F18), 
		MEH(KC_F19),	MEH(KC_F20),	MEH(KC_F21),	MEH(KC_F22),	MEH(KC_F23),	MEH(KC_F24),	HYPR(KC_F19),	HYPR(KC_F20),	__,		HYPR(KC_F22),	HYPR(KC_F23),	HYPR(KC_F24)
	)

};
