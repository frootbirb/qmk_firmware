#ifndef FROOTBIRB
#define FROOTBIRB

#include "quantum.h"

// Prettify common keycodes
#define ____ KC_TRNS
#define xxxx KC_NO

// Prettify long macro names
#define PAREN TD(PARENTHESES)
#define BRACE TD(BRACES)
#define BRACK TD(BRACKETS)
#define ABRCK TD(ANGLE_BRACKETS)
#define COPY  TD(COPY_PASTE)

#define SFT_ENT MT(MOD_LSFT, KC_ENT)
#define NAV_DOT LT(NAV, KC_DOT)

// ---------------------- Key Combos ---------------------- //

// Key combo definitions
enum combos {
	CMB_PPLS = 0,
	CMB_PAST,
	CMB_1,
	CMB_2,
	CMB_3,
	CMB_4,
	CMB_5,
	CMB_6,
	CMB_7,
	CMB_8,
	CMB_9,
	CMB_0,
};

// ---------------------- Tap Dance ---------------------- //

// Tap Dance Declarations
enum {
	PARENTHESES = 0,
	BRACES,
	BRACKETS,
	ANGLE_BRACKETS,
	COPY_PASTE,
};

// Macro definitions
void copy_paste(qk_tap_dance_state_t *state, void *user_data);

// Layer Definitions
enum Layer {
	DEF = 0,
	SYM,
	NAV,
	GAM,
	NUM,
};

// ---------------------- Handle custom keycodes ---------------------- //

// Custom password keycodes
enum custom_keycodes {
	TOG_OS = SAFE_RANGE,
	PASSWD,
	MOD_1,
	MOD_2,
	MOD_3,
	MOD_4,
	MOD_5,
	MOD_6,
	FIND,
	SYS_FND,
	SCRNSHT,
};

static const uint16_t mac_pc_codes[][2] = {
	{	// MOD_1
		KC_LCTL,
		KC_RCMD
	}, {// MOD_2
		KC_LWIN,
		KC_LALT
	}, {// MOD_3
		KC_LALT,
		KC_LCTL
	}, {// MOD_4
		KC_RCTL,
		KC_LCMD
	}, {// MOD_5
		KC_RWIN,
		KC_RALT
	}, {// MOD_6
		KC_RALT,
		KC_RCTL
	}, {// FIND
		RCTL(KC_F),
		RGUI(KC_F)
	}, {// SYS_FND
		LWIN(KC_S),
		RGUI(KC_SPC)
	}, {// SCRNSHT
		KC_PSCR,
		RGUI(S(KC_4))
	},
};

#endif
