#pragma once

#include "quantum.h"
#include QMK_KEYBOARD_H

// TODO: tap dance: shift shift -> toggle caps?
// TODO: combos for layers, maybe one-shot

/* Layer taps */
#define LT1(kc) LT(SYMBOL, KC_##kc)
#define LT2(kc) LT(NUM_NAV, KC_##kc)
#define LT3(kc) LT(ADJUST, KC_##kc)

/* Layer modifiers */
#define LM1 MO(SYMBOL)
#define LM2 MO(NUM_NAV)
#define LM3 MO(ADJUST)

/* Mod taps */
#define MA(kc) LALT_T(KC_##kc)
#define MC(kc) LCTL_T(KC_##kc)
#define MG(kc) LGUI_T(KC_##kc)

#define LAYOUT_WRAPPER(...) LAYOUT(__VA_ARGS__)

/* Colemak DH */
#define COLEMAK_TOP_L KC_Q,    KC_W,    KC_F,    KC_P,    KC_B
#define COLEMAK_MID_L KC_A,    KC_R,    KC_S,    KC_T,    KC_G
#define COLEMAK_BOT_L KC_Z,    KC_X,    KC_C,    KC_D,    KC_V

#define COLEMAK_TOP_R KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN
#define COLEMAK_MID_R KC_M,    KC_N,    KC_E,    KC_I,    KC_O
#define COLEMAK_BOT_R KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH

/* Symbols */
#define SYMBOL_TOP_L  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC
#define SYMBOL_MID_L  KC_GRV,  KC_TILD, KC_LPRN, KC_RPRN, _______
#define SYMBOL_BOT_L  _______, _______, KC_LCBR, KC_RCBR, _______

#define SYMBOL_TOP_R  KC_CIRC, KC_AMPR, KC_ASTR, KC_BSLS, KC_PIPE
#define SYMBOL_MID_R  KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, _______
#define SYMBOL_BOT_R  _______, _______, _______, _______, _______

/* Numbers, function keys, RGB and navigation */
#define NUM_NAV_TOP_L KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define NUM_NAV_MID_L _______, _______, _______, _______, _______
#define NUM_NAV_BOT_L KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5

#define NUM_NAV_TOP_R KC_6,    KC_7,    KC_8,    KC_9,    KC_0
#define NUM_NAV_MID_R _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
#define NUM_NAV_BOT_R KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10

/* RGB, audio */
#define ADJUST_TOP_L  _______, _______, _______, _______, _______
#define ADJUST_MID_L  RGB_TOG, RGB_SAI, RGB_HUI, RGB_MOD, _______
#define ADJUST_BOT_L  _______, RGB_SAD, RGB_VAD, RGB_RMOD, _______

#define ADJUST_TOP_R  _______, _______, _______, _______, _______
#define ADJUST_MID_R  _______, KC_VOLU, KC_VOLD, KC_MUTE, _______
#define ADJUST_BOT_R  _______, _______, _______, _______, _______

enum userspace_layers {
    COLEMAK = 0,
    SYMBOL,
    NUM_NAV,
    ADJUST,
};
