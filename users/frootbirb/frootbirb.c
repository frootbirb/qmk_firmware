#include "frootbirb.h"

bool is_mac = false; // Default to windows operation for extended character code sequences

// ---------------------- Key Combos ---------------------- //

// Pressing the - and = numpad keys makes +
const uint16_t PROGMEM pls_combo[] = {KC_PMNS, KC_EQL, COMBO_END};
// Pressing the / and = numpad keys makes *
const uint16_t PROGMEM ast_combo[] = {KC_PSLS, KC_EQL, COMBO_END};

// Mostly for Planck - the top two rows together make their number
// e.g. Q + A = 1, W + S = 2
const uint16_t PROGMEM combo_1[] = {KC_Q, KC_A, COMBO_END};
const uint16_t PROGMEM combo_2[] = {KC_W, KC_S, COMBO_END};
const uint16_t PROGMEM combo_3[] = {KC_E, KC_D, COMBO_END};
const uint16_t PROGMEM combo_4[] = {KC_R, KC_F, COMBO_END};
const uint16_t PROGMEM combo_5[] = {KC_T, KC_G, COMBO_END};
const uint16_t PROGMEM combo_6[] = {KC_Y, KC_H, COMBO_END};
const uint16_t PROGMEM combo_7[] = {KC_U, KC_J, COMBO_END};
const uint16_t PROGMEM combo_8[] = {KC_I, KC_K, COMBO_END};
const uint16_t PROGMEM combo_9[] = {KC_O, KC_L, COMBO_END};
const uint16_t PROGMEM combo_0[] = {KC_P, KC_SCLN, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
	[CMB_PPLS] = COMBO(pls_combo, KC_PPLS),
	[CMB_PAST] = COMBO(ast_combo, KC_PAST),
	[CMB_1] = COMBO(combo_1, KC_1),
	[CMB_2] = COMBO(combo_2, KC_2),
	[CMB_3] = COMBO(combo_3, KC_3),
	[CMB_4] = COMBO(combo_4, KC_4),
	[CMB_5] = COMBO(combo_5, KC_5),
	[CMB_6] = COMBO(combo_6, KC_6),
	[CMB_7] = COMBO(combo_7, KC_7),
	[CMB_8] = COMBO(combo_8, KC_8),
	[CMB_9] = COMBO(combo_9, KC_9),
	[CMB_0] = COMBO(combo_0, KC_0),
};

// ---------------------- Tap Dance ---------------------- //

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
	[PARENTHESES] = ACTION_TAP_DANCE_DOUBLE(KC_LEFT_PAREN, KC_RIGHT_PAREN),
	[BRACES] = ACTION_TAP_DANCE_DOUBLE(KC_LEFT_CURLY_BRACE, KC_RIGHT_CURLY_BRACE),
	[BRACKETS] = ACTION_TAP_DANCE_DOUBLE(KC_LBRACKET, KC_RBRACKET),
	[ANGLE_BRACKETS] = ACTION_TAP_DANCE_DOUBLE(KC_LEFT_ANGLE_BRACKET, KC_RIGHT_ANGLE_BRACKET),
	[COPY_PASTE] = ACTION_TAP_DANCE_FN(copy_paste),
};

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

// ---------------------- Handle custom keycodes ---------------------- //

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
					SEND_STRING("K$^1i8Ny#M" SS_DELAY(50) SS_TAP(X_ENTER));
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
