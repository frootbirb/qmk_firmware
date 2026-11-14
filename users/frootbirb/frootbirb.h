#ifndef FROOTBIRB
#define FROOTBIRB

#include "quantum.h"

// Prettify common keycodes
#define _______ KC_TRNS
#define xxxx KC_NO

// Prettify long macro names
#define W_PASTE LCTL(KC_V)
#define M_PASTE LWIN(KC_V)
#define SFT_ENT LSFT_T(KC_ENT)
#define NAV_DOT LT(NAV, KC_DOT)
#define WINSHOT LWIN(LSFT(KC_S))
#define MACSHOT LCMD(LSFT(KC_4))

#define KC_LB LOPT(KC_3)
#define KC_EU LSFT(LOPT(KC_2))

// ---------------------- Layer Definitions ---------------------- //

enum Layer {
	DEF = 0,
	MAC,
	SYM,
	NAV,
    MAC_NAV,
};

// ---------------------- Handle custom keycodes ---------------------- //

// Custom password keycodes
enum custom_keycodes {
    WINPASS = SAFE_RANGE,
    MACPASS,
};

#endif
