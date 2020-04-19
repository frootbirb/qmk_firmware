#include "frootbirb.h"

// Custom password keycodes
enum custom_keycodes {
  SER_PAS = SAFE_RANGE,
  MAC_PAS
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MAC_PAS:
      if (record->event.pressed) {
        SEND_STRING("RlfEV67zE@Zw@kh!Lj61");
      }
      break;

    case SER_PAS:
      if (record->event.pressed) {
        SEND_STRING("7Wk2O&o2Y##ZgWO*b*u");
      }
      break;
  }
  return true;
};

// Handle the Mac layer switch
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
	switch (id) {
		case 0:
			layer_invert(NAV);
			layer_invert(MNAV);
			break;
	}
	
	return MACRO_NONE;
}

// Initialize color backlighting
void matrix_init_user(void) {
	rgblight_enable();
	for (int i = 0; i < RGBLED_NUM; i++) {
		setrgb(204, 102, 0, (LED_TYPE *)&led[i]);
	}
	rgblight_mode(RGBLIGHT_MODE_BREATHING);
};

// Key combo definitions
enum combos {
	CMB_PPLS = 0,
	CMB_PAST,
};

// Pressing the - and = numpad keys makes +
const uint16_t PROGMEM pls_combo[] = {KC_PMNS, KC_EQL, COMBO_END};
// Pressing the / and = numpad keys makes *
const uint16_t PROGMEM ast_combo[] = {KC_PSLS, KC_EQL, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [CMB_PPLS] = COMBO(pls_combo, KC_PPLS),
  [CMB_PAST] = COMBO(ast_combo, KC_PAST),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    LAYOUT_ortho_5x15(
        xxxx,    KC_1,    KC_2,    KC_3, KC_4,   KC_5,    KC_PMNS, KC_EQL, KC_PSLS, KC_6,   KC_7,    KC_8,    KC_9,    KC_0,    xxxx,
        KC_ESC,  KC_Q,    KC_W,    KC_E, KC_R,   KC_T,    KC_P7,   KC_P8,  KC_P9,   KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,    RCTL(KC_F),
        KC_TAB,  KC_A,    KC_S,    KC_D, KC_F,   KC_G,    KC_P4,   KC_P5,  KC_P6,   KC_H,   KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C, KC_V,   KC_B,    KC_P1,   KC_P2,  KC_P3,   KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_RSFT,
        KC_LCTL, KC_LWIN, KC_LALT, COPY, KC_SPC, SFT_ENT, MO(SYM), KC_P0,  NAV_DOT, KC_SPC, KC_BSPC, xxxx,    KC_LEFT, KC_DOWN, KC_RGHT
    ),

    LAYOUT_ortho_5x15( // mac layer
        MAC_LCK, ____,    ____,    ____,    ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
        ____,    ____,    ____,    ____,    ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, RGUI(KC_F),
        ____,    ____,    ____,    ____,    ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
        ____,    ____,    ____,    ____,    ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
        KC_RCMD, KC_LALT, KC_LCTL, MACCOPY, ____, ____, ____, ____, M(0), ____, ____, ____, ____, ____, ____
    ),

    LAYOUT_ortho_5x15( // symbol layer
        RESET, ____,    ____,    ____,    ____,    ____,    ____, ____, ____, ____,    ____,    ____,    ____,    ____,    SER_PAS,
        ____,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    ____, ____, ____, ____,    KC_UNDS, KC_AT,   KC_HASH, KC_DLR,  ____,
        ____,  KC_TILD, KC_QUES, KC_EXLM, KC_SLSH, KC_AMPR, ____, ____, ____, KC_PIPE, PAREN,   BRACE,   BRACK,   ABRCK,   KC_GRV,
        ____,  KC_PLUS, KC_MINS, KC_ASTR, KC_BSLS, KC_EQL,  ____, ____, ____, ____,    KC_CIRC, KC_PERC, ____,    ____,    ____,
        ____,  ____,    ____,    ____,    ____,    ____,    ____, ____, ____, ____,    ____,    ____,    ____,    ____,    ____
    ),

    LAYOUT_ortho_5x15( // navigation layer
        KC_PWR,  ____,    ____,    ____,   ____,   ____, ____, ____, ____, ____, ____,    RGB_HUD, RGB_HUI, ____,    SER_PAS,
        ____,    KC_F1,   KC_F2,   KC_F3,  KC_F4,  ____, ____, ____, ____, ____, RGB_TOG, RGB_VAD, RGB_VAI, RGB_MOD, LGUI(KC_S),
        ____,    KC_F5,   KC_F6,   KC_F7,  KC_F8,  ____, ____, ____, ____, ____, KC_INS,  KC_NLCK, KC_CAPS, KC_SLCK, ____,
        ____,    KC_F9,   KC_F10,  KC_F11, KC_F12, ____, ____, ____, ____, ____, ____,    ____,    KC_PSCR, KC_PGUP, KC_CAPS,
        KC_RCTL, KC_RWIN, KC_RALT, ____,   ____,   ____, ____, ____, ____, ____, KC_DEL,  TG(MAC), KC_HOME, KC_PGDN, KC_END
    ),

    LAYOUT_ortho_5x15( // mac navigation layer
        ____,    ____,    ____,    ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,    ____, MAC_PAS,
        ____,    ____,    ____,    ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,    ____, RGUI(KC_SPC),
        ____,    ____,    ____,    ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,    ____, ____,
        ____,    ____,    ____,    ____, ____, ____, ____, ____, ____, ____, ____, ____, MAC_SCR, ____, ____,
        KC_LCMD, KC_RALT, KC_RCTL, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,    ____, ____
    ),
};
