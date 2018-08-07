#include "planck.h"

// Layer Definitions
#define NUM 1
#define NAV 2
#define SND 3

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
  BRACKET,
  ANGLE_BRACKET,
  COPY_PASTE,
  COPY_PASTE_ALL
};

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  [PAREN] = ACTION_TAP_DANCE_DOUBLE(KC_LEFT_PAREN, KC_RIGHT_PAREN),
  [BRACE] = ACTION_TAP_DANCE_DOUBLE(KC_LEFT_CURLY_BRACE, KC_RIGHT_CURLY_BRACE),
  [BRACKET] = ACTION_TAP_DANCE_DOUBLE(KC_LBRACKET, KC_RBRACKET),
  [ANGLE_BRACKET] = ACTION_TAP_DANCE_DOUBLE(KC_LEFT_ANGLE_BRACKET, KC_RIGHT_ANGLE_BRACKET),
  [COPY_PASTE] = ACTION_TAP_DANCE_FN(copy_paste),
  [COPY_PASTE_ALL] = ACTION_TAP_DANCE_FN(copy_paste_all)
  };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	KEYMAP(
		KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_KP_SLASH, KC_EQUAL, KC_KP_MINUS, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, 
		KC_NO, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_KP_7, KC_KP_8, KC_KP_9, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_NO, 
		KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_KP_4, KC_KP_5, KC_KP_6, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, 
		KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_KP_1, KC_KP_2, KC_KP_3, KC_N, KC_M, KC_COMM, KC_DOT, KC_UP, TD(COPY_PASTE), 
		KC_LCTRL, KC_LGUI, KC_LALT, TD(COPY_PASTE), KC_SPC, LT(NUM, KC_ENT), KC_PAST, KC_KP_DOT, KC_KP_0, KC_SPC, MO(NAV), OSL(SND), KC_LEFT, KC_DOWN, KC_RGHT),

	KEYMAP(
		KC_TRNS, KC_MINS, KC_7, KC_8, KC_9, KC_ASTR, KC_TILD, KC_UNDS, KC_AT, KC_HASH, KC_DLR, KC_DEL,  
		KC_TRNS, KC_PLUS, KC_4, KC_5, KC_6, KC_SLSH, KC_BSLS, TD(PAREN), TD(BRACE), TD(BRACKET), TD(ANGLE_BRACKET), KC_AMPR, 
		KC_TRNS, KC_EQL, KC_1, KC_2, KC_3, KC_GRV, KC_CIRC, KC_EXLM, KC_QUES, KC_PERC, KC_TRNS, TD(COPY_PASTE_ALL), 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_0, KC_DOT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	KEYMAP(
		KC_PWR, KC_F1, KC_F2, KC_F3, KC_F4, KC_TRNS, KC_TRNS, LGUI(LCTL(KC_LEFT)), LGUI(LCTL(KC_D)), LGUI(LCTL(KC_F4)), LGUI(LCTL(KC_RGHT)), LGUI(KC_S), 
		KC_TRNS, KC_F5, KC_F6, KC_F7, KC_F8, KC_TRNS, KC_TRNS, KC_INS, KC_NLCK, KC_CAPS, KC_SLCK, LGUI(KC_D), 
		KC_TRNS, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS, KC_TRNS, LSFT(KC_TAB), KC_TAB, KC_PSCR, KC_PGUP, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_PGDN, KC_END)

};