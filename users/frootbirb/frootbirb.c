#include "frootbirb.h"
#include "secrets.h"

// ---------------------- Handle fancy lighting ---------------------- //

#ifdef RGBLIGHT_ENABLE
const rgblight_segment_t PROGMEM win_lightlayer[] = RGBLIGHT_LAYER_SEGMENTS(
	{0, 6, HSV_CYAN}
);

const rgblight_segment_t PROGMEM mac_lightlayer[] = RGBLIGHT_LAYER_SEGMENTS(
	{0, 6, HSV_WHITE}
);

const rgblight_segment_t PROGMEM caps_lightlayer[] = RGBLIGHT_LAYER_SEGMENTS(
	{0, 6, HSV_RED}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
	win_lightlayer,
	mac_lightlayer,
	caps_lightlayer
);

void keyboard_post_init_user(void) {
	// Enable the LED layers
	rgblight_layers = my_rgb_layers;
	rgblight_set_layer_state(0, true);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, MAC));
    return state;
}

bool led_update_user(led_t led_state) {
	rgblight_set_layer_state(2, led_state.caps_lock);
	return true;
}
#endif

// ---------------------- Handle custom keycodes ---------------------- //

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	if (record->event.pressed) {
		switch (keycode) {
			// ---------------------- Special keys ---------------------- //
			case PASSWRD:
                send_string(layer_state_is(MAC) ? MAC_PASSWD : SERVER_PASSWD);
                SEND_STRING(SS_DELAY(50) SS_TAP(X_ENTER));
				return false;
		}
	}
	return true;
};
