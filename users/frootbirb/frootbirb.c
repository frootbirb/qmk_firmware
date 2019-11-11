#include "frootbirb.h"

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [PARENTHESES] = ACTION_TAP_DANCE_DOUBLE(KC_LEFT_PAREN, KC_RIGHT_PAREN),
    [BRACES] = ACTION_TAP_DANCE_DOUBLE(KC_LEFT_CURLY_BRACE, KC_RIGHT_CURLY_BRACE),
    [BRACKETS] = ACTION_TAP_DANCE_DOUBLE(KC_LBRACKET, KC_RBRACKET),
    [ANGLE_BRACKETS] = ACTION_TAP_DANCE_DOUBLE(KC_LEFT_ANGLE_BRACKET, KC_RIGHT_ANGLE_BRACKET),
    [COPY_PASTE_MAC] = ACTION_TAP_DANCE_FN(copy_paste_mac),
    [COPY_PASTE] = ACTION_TAP_DANCE_FN(copy_paste),
};

// Macro definitions
void copy_paste_mac(qk_tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            register_code(KC_RGUI); register_code(KC_V); unregister_code(KC_V); unregister_code(KC_RGUI);
            break;
        case 2:
            register_code(KC_RGUI); register_code(KC_C); unregister_code(KC_C); unregister_code(KC_RGUI);
            break;
    }
}

void copy_paste(qk_tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            register_code(KC_LCTL); register_code(KC_V); unregister_code(KC_V); unregister_code(KC_LCTL);
            break;
        case 2:
            register_code(KC_LCTL); register_code(KC_C); unregister_code(KC_C); unregister_code(KC_LCTL);
            break;
    }
}