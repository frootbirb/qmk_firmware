#include QMK_KEYBOARD_H
#include "frootbirb.h"

enum encoder_names {
	_LEFT,
	_RIGHT,
	_MIDDLE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	/*
		| Knob 1: Vol Dn/Up |      | Knob 2: Page Dn/Up |
		| Press: Mute       | Home | Press: Play/Pause  |
		| Hold: Layer 2     | Up   | RGB Mode           |
		| Left              | Down | Right              |
	 */
	[0] = LAYOUT(
		KC_MUTE, KC_HOME, KC_MPLY,
		MO(1)  , KC_UP  , RGB_MOD,
		KC_LEFT, KC_DOWN, KC_RGHT
	),
	/*
		| RESET          | N/A  | Media Stop |
		| Held: Layer 2  | Home | RGB Mode   |
		| Media Previous | End  | Media Next |
	 */
	[1] = LAYOUT(
		RESET  , BL_STEP, KC_STOP,
		_______, KC_HOME, RGB_MOD,
		KC_MPRV, KC_END , KC_MNXT
	),
};

void encoder_update_user(uint8_t index, bool clockwise) {
	if (index == _LEFT) {
		if (clockwise) {
			tap_code(KC_VOLU);
		} else {
			tap_code(KC_VOLD);
		}
	}
	else if (index == _MIDDLE) {
		if (clockwise) {
			tap_code(KC_DOWN);
		} else {
			tap_code(KC_UP);
		}
	}
	else if (index == _RIGHT) {
		tap_code16(C(KC_TAB));
	} else {
		tap_code16(S(C(KC_TAB)));
	}
}
