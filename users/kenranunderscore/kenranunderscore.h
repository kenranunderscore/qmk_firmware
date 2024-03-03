#pragma once

#include "quantum.h"
#include QMK_KEYBOARD_H

/* Layer modifiers */
#define LA_SYM MO(SYM)
#define LA_NAV MO(NAV)

/* Mod taps */
#define MA(kc) LALT_T(KC_##kc)
#define MC(kc) LCTL_T(KC_##kc)
#define MG(kc) LGUI_T(KC_##kc)

/* Umlauts and German ß; depend on US AltGr Intl layout */
#define A_UML RALT(KC_Q)
#define O_UML RALT(KC_P)
#define U_UML RALT(KC_Y)
#define S_GER RALT(KC_S)

/* Common keys */
#define TMB_L1 KC_LALT
#define TMB_L2 LT(NUM, KC_ESC)
#define TMB_L3 KC_SPC
#define TMB_R1 KC_ENT
#define TMB_R2 LT(SYM, KC_ESC)
#define TMB_R3 KC_LGUI
#define NAV_TAB LT(NAV, KC_TAB)

/* A wrapper around the LAYOUT macro to pass through evaluated arguments. */
#define LAYOUT_WRAPPER(...) LAYOUT(__VA_ARGS__)

// IDEA: use top-left MG for (some new?) navigation layer instead?

/* Core MTGAP layout */
// left              ┌────────┬────────┬────────┬────────┬────────┬────────┐
#define MTGAP_TOP_L   NAV_TAB, KC_Y,    KC_P,    KC_O,    KC_U,    KC_J
#define MTGAP_MID_L   MC(BSPC),KC_I,    KC_N,    KC_E,    KC_A,    KC_COMM
#define MTGAP_BOT_L   KC_LSFT, KC_Q,    KC_Z,    KC_SLSH, KC_DOT,  KC_SCLN

// right             ┌────────┬────────┬────────┬────────┬────────┬────────┐
#define MTGAP_TOP_R   KC_K,    KC_D,    KC_L,    KC_C,    KC_W,    MG(MINS)
#define MTGAP_MID_R   KC_M,    KC_H,    KC_T,    KC_S,    KC_R,    MC(QUOT)
#define MTGAP_BOT_R   KC_B,    KC_F,    KC_G,    KC_V,    KC_X,    KC_RSFT

// left              ┌────────┬────────┬────────┬────────┬────────┬────────┐
#define SYM_TOP_L     _______, KC_EXLM, KC_HASH, KC_LCBR, KC_RCBR, KC_GRV
#define SYM_MID_L     _______, KC_ASTR, KC_EQL,  KC_LPRN, KC_RPRN, KC_TILD
#define SYM_BOT_L     _______, KC_PLUS, KC_PIPE, KC_LBRC, KC_RBRC, KC_PERC

// right             ┌────────┬────────┬────────┬────────┬────────┬────────┐
#define SYM_TOP_R     _______, _______, _______, _______, _______, _______
#define SYM_MID_R     _______, _______, _______, _______, _______, _______
#define SYM_BOT_R     _______, _______, _______, _______, _______, _______

// left              ┌────────┬────────┬────────┬────────┬────────┬────────┐
#define NUM_TOP_L     _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define NUM_MID_L     _______, _______, _______, _______, _______, _______
#define NUM_BOT_L     _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5

// right             ┌────────┬────────┬────────┬────────┬────────┬────────┐
#define NUM_TOP_R     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______
#define NUM_MID_R     _______, KC_CIRC, KC_DLR,  KC_UNDS, _______, _______
#define NUM_BOT_R     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______

// left              ┌────────┬────────┬────────┬────────┬────────┬────────┐
#define NAV_TOP_L     _______, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX
#define NAV_MID_L     _______, _______, _______, _______, _______, KC_VOLD
#define NAV_BOT_L     _______, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX

// right             ┌────────┬────────┬────────┬────────┬────────┬────────┐
#define NAV_TOP_R     KC_PGDN, KC_PGUP, KC_TAB,  KC_DEL,  KC_BSPC, _______
#define NAV_MID_R     KC_CAPS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______
#define NAV_BOT_R     S_GER,   A_UML,   O_UML,   U_UML,   KC_ENT,  _______

// misc              ┌────────┬────────┬────────┬────────┬────────┬────────┐
#define ROW_6_TRANSP  _______, _______, _______, _______, _______, _______
#define ROW_6_BLANK   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX

enum userspace_layers {
    MTGAP = 0,
    SYM,
    NUM,
    NAV,
};
