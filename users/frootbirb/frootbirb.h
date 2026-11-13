#ifndef FROOTBIRB
#define FROOTBIRB

#include "quantum.h"

// Prettify common keycodes
#define ____ KC_TRNS
#define _______ KC_TRNS
#define xxxx KC_NO

// Prettify long macro names
#define W_PASTE LCTL(KC_V)
#define M_PASTE LWIN(KC_V)
#define SFT_ENT LSFT_T(KC_ENT)
#define NAV_DOT LT(NAV, KC_DOT)
#define TSKMGR	LCTL(LSFT(KC_ESC))

#define KC_LB LOPT(KC_3)
#define KC_EU LSFT(LOPT(KC_2))

// ---------------------- Layer Definitions ---------------------- //

enum Layer {
	DEF = 0,
	SYM,
	NAV,
	MAC,
};

// ---------------------- Handle custom keycodes ---------------------- //

// Custom password keycodes
enum custom_keycodes {
	PASSWRD = SAFE_RANGE,
};

#endif
