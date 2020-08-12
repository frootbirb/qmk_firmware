#include "frootbirb.h"

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [PARENTHESES] = ACTION_TAP_DANCE_DOUBLE(KC_LEFT_PAREN, KC_RIGHT_PAREN),
    [BRACES] = ACTION_TAP_DANCE_DOUBLE(KC_LEFT_CURLY_BRACE, KC_RIGHT_CURLY_BRACE),
    [BRACKETS] = ACTION_TAP_DANCE_DOUBLE(KC_LBRACKET, KC_RBRACKET),
    [ANGLE_BRACKETS] = ACTION_TAP_DANCE_DOUBLE(KC_LEFT_ANGLE_BRACKET, KC_RIGHT_ANGLE_BRACKET),
    [COPY_PASTE] = ACTION_TAP_DANCE_FN(copy_paste),
};

bool is_mac = false; // Default to windows operation for extended character code sequences

void copy_paste(qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
    case 1:
      if (is_mac) {
        register_code(KC_RGUI); register_code(KC_V); unregister_code(KC_V); unregister_code(KC_RGUI);
      }
      else {
        register_code(KC_LCTL); register_code(KC_V); unregister_code(KC_V); unregister_code(KC_LCTL);
      }
      break;
    case 2:
      if (is_mac) {
        register_code(KC_RGUI); register_code(KC_C); unregister_code(KC_C); unregister_code(KC_RGUI);
      }
      else {
        register_code(KC_LCTL); register_code(KC_C); unregister_code(KC_C); unregister_code(KC_LCTL);
      }
      break;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case TOG_OS:
      if (record->event.pressed) {
        is_mac = ! is_mac;
      }
      return false;
	  
    case PASSWD:
      if (record->event.pressed) {
		if (is_mac) {
		  SEND_STRING("t2JJE5^do7" SS_DELAY(50) SS_TAP(X_ENTER));
		}
		else {
          SEND_STRING("7Wk2O&o2Y##ZgWO*b*u" SS_DELAY(50) SS_TAP(X_ENTER));
		}
      }
      return false;
	  
	case MOD_1: case MOD_2: case MOD_3: case MOD_4: case MOD_5: case MOD_6: 
	case FIND: case SYS_FND: case SCRNSHT:
      if (record->event.pressed) {
		  // Choose code to send based on whether this is in Mac mode
		  register_code16(mac_pc_codes[keycode - MOD_1][is_mac]);
	  } 
	  else {
		  // Choose code to clear based on whether this is in Mac mode
		  unregister_code16(mac_pc_codes[keycode - MOD_1][is_mac]);
	  }
      return false;
  }
  return true;
};