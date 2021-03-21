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

/* A wrapper around the LAYOUT macro to pass through evaluated arguments. */
#define LAYOUT_WRAPPER(...) LAYOUT(__VA_ARGS__)

/* Thumb keys */
// I'm aiming to use only 3 thumb keys, so I won't have to change much when
// using a Corne or similar.
#define THMB_L1 LT2(DEL)
#define THMB_L2 LM1
#define THMB_L3 KC_SPC
#define THMB_R1 MC(ENT)
#define THMB_R2 LT1(ESC)
#define THMB_R3 LM2

/* Colemak DH */
// left              ┌────────┬────────┬────────┬────────┬────────┬────────┐
#define MTGAP_TOP_L   MA(TAB), KC_Y,    KC_P,    KC_O,    KC_U,    KC_J
#define MTGAP_MID_L   MC(BSPC),KC_I,    KC_N,    KC_E,    KC_A,    KC_COMM
#define MTGAP_BOT_L   KC_LSFT, KC_Q,    KC_Z,    KC_SLSH, KC_DOT,  KC_SCLN

// right             ┌────────┬────────┬────────┬────────┬────────┬────────┐
#define MTGAP_TOP_R   KC_K,    KC_D,    KC_L,    KC_C,    KC_W,    MA(MINS)
#define MTGAP_MID_R   KC_M,    KC_H,    KC_T,    KC_S,    KC_R,    KC_QUOT
#define MTGAP_BOT_R   KC_B,    KC_F,    KC_G,    KC_V,    KC_X,    KC_RSFT

/* Symbols */
// left              ┌────────┬────────┬────────┬────────┬────────┬────────┐
#define SYMBOL_TOP_L  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC
#define SYMBOL_MID_L  _______, KC_EQL,  KC_GRV,  KC_LPRN, KC_RPRN, KC_TILD
#define SYMBOL_BOT_L  _______, _______, _______, KC_LCBR, KC_RCBR, _______

// right             ┌────────┬────────┬────────┬────────┬────────┬────────┐
#define SYMBOL_TOP_R  KC_CIRC, KC_AMPR, KC_ASTR, KC_BSLS, KC_PIPE, _______
#define SYMBOL_MID_R  KC_PLUS, KC_MINS, KC_UNDS, KC_LBRC, KC_RBRC, _______
#define SYMBOL_BOT_R  _______, _______, _______, _______, _______, _______

/* Numbers, function keys, RGB and navigation */
// left              ┌────────┬────────┬────────┬────────┬────────┬────────┐
#define NUM_NAV_TOP_L _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define NUM_NAV_MID_L _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define NUM_NAV_BOT_L _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX

// right             ┌────────┬────────┬────────┬────────┬────────┬────────┐
#define NUM_NAV_TOP_R KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______
#define NUM_NAV_MID_R XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______
#define NUM_NAV_BOT_R XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______

/* RGB, audio */
// left              ┌────────┬────────┬────────┬────────┬────────┬────────┐
#define ADJUST_TOP_L  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
#define ADJUST_MID_L  _______, RGB_TOG, RGB_SAI, RGB_HUI, RGB_MOD, _______
#define ADJUST_BOT_L  _______, _______, RGB_SAD, RGB_VAD, RGB_RMOD,_______

// right             ┌────────┬────────┬────────┬────────┬────────┬────────┐
#define ADJUST_TOP_R  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______
#define ADJUST_MID_R  _______, KC_VOLU, KC_VOLD, KC_MUTE, _______, _______
#define ADJUST_BOT_R  _______, _______, _______, _______, _______, _______

// misc              ┌────────┬────────┬────────┬────────┬────────┬────────┐
#define ROW_6_TRANSP  _______, _______, _______, _______, _______, _______

enum userspace_layers {
    MTGAP = 0,
    SYMBOL,
    NUM_NAV,
    ADJUST,
};

/* enum userspace_keycodes { */
/*     MTG_CMM = SAFE_RANGE, */
/*     MTG_SLS, */
/*     MTG_DOT, */
/*     MTG_CLN, */
/* }; */
