#pragma once

#include "quantum.h"
#include QMK_KEYBOARD_H

/* Layer taps */
#define LT1(kc) LT(SYM, KC_##kc)
#define LT2(kc) LT(NAV, KC_##kc)
#define LT3(kc) LT(NUM, KC_##kc)

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

/* One-shot modifiers */
#define O(mod) OSM(MOD_##mod)

/* Common thumb keys */
#define TMB_L1 KC_LALT
#define TMB_L2 LA_NAV
#define TMB_L3 KC_SPC
#define TMB_R1 KC_ENT
#define TMB_R2 LA_SYM
#define TMB_R3 KC_RALT

/* A wrapper around the LAYOUT macro to pass through evaluated arguments. */
#define LAYOUT_WRAPPER(...) LAYOUT(__VA_ARGS__)

/* Core MTGAP layout */
// left              ┌────────┬────────┬────────┬────────┬────────┐
#define MTGAP_TOP_L   KC_Y,    KC_P,    KC_O,    KC_U,    KC_J
#define MTGAP_MID_L   KC_I,    KC_N,    KC_E,    KC_A,    KC_COMM
#define MTGAP_BOT_L   KC_Q,    KC_Z,    KC_SLSH, KC_DOT,  KC_SCLN

// right             ┌────────┬────────┬────────┬────────┬────────┐
#define MTGAP_TOP_R   KC_K,    KC_D,    KC_L,    KC_C,    KC_W
#define MTGAP_MID_R   KC_M,    KC_H,    KC_T,    KC_S,    KC_R
#define MTGAP_BOT_R   KC_B,    KC_F,    KC_G,    KC_V,    KC_X

/* Symbols */
// left              ┌────────┬────────┬────────┬────────┬────────┐
#define SYM_TOP_L     KC_ESC,  KC_LBRC, KC_LCBR, KC_LPRN, KC_TILD
#define SYM_MID_L     KC_MINS, KC_ASTR, KC_EQL,  KC_UNDS, KC_DLR
#define SYM_BOT_L     KC_PLUS, KC_PIPE, KC_AT,   KC_BSLS, KC_QUOT

// right             ┌────────┬────────┬────────┬────────┬────────┐
#define SYM_TOP_R     KC_CIRC, KC_RPRN, KC_RCBR, KC_RBRC, KC_GRV
#define SYM_MID_R     KC_HASH, OS_CMD,  OS_CTRL, OS_ALT,  OS_SHFT
#define SYM_BOT_R     KC_PERC, KC_AMPR, KC_LT,   KC_GT,   KC_EXLM

/* Numbers, function keys, and navigation */
// left              ┌────────┬────────┬────────┬────────┬────────┐
#define NAV_TOP_L     KC_TAB,  XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLU
#define NAV_MID_L     OS_SHFT, OS_ALT,  OS_CTRL, OS_CMD,  KC_VOLD
#define NAV_BOT_L     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX

// right             ┌────────┬────────┬────────┬────────┬────────┐
#define NAV_TOP_R     KC_PGDN, KC_PGUP, KC_TAB,  KC_DEL,  KC_BSPC
#define NAV_MID_R     KC_CAPS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
#define NAV_BOT_R     S_GER,   A_UML,   O_UML,   U_UML,   KC_ENT

/* RGB, audio */
// left              ┌────────┬────────┬────────┬────────┬────────┐
#define NUM_TOP_L     KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define NUM_MID_L     OS_SHFT, OS_ALT,  OS_CTRL, OS_CMD,  KC_F11
#define NUM_BOT_L     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5

// right             ┌────────┬────────┬────────┬────────┬────────┐
#define NUM_TOP_R     KC_6,    KC_7,    KC_8,    KC_9,    KC_0
#define NUM_MID_R     KC_F10,  OS_CMD,  OS_CTRL, OS_ALT,  OS_SHFT
#define NUM_BOT_R     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10

// misc              ┌────────┬────────┬────────┬────────┬────────┐
#define ROW_5_TRANSP  _______, _______, _______, _______, _______
#define ROW_5_BLANK   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX

/* 6-key variants of the rows */
#define MTGAP_TOP_L_6   KC_TAB,   MTGAP_TOP_L
#define MTGAP_MID_L_6   MC(BSPC), MTGAP_MID_L
#define MTGAP_BOT_L_6   KC_LSFT,  MTGAP_BOT_L

#define MTGAP_TOP_R_6   MTGAP_TOP_R, KC_ESC
#define MTGAP_MID_R_6   MTGAP_MID_R, MC(QUOT)
#define MTGAP_BOT_R_6   MTGAP_BOT_R, KC_RSFT

#define SYM_TOP_L_6     _______, SYM_TOP_L
#define SYM_MID_L_6     _______, SYM_MID_L
#define SYM_BOT_L_6     _______, SYM_BOT_L

#define SYM_TOP_R_6     SYM_TOP_R, _______
#define SYM_MID_R_6     SYM_MID_R, _______
#define SYM_BOT_R_6     SYM_BOT_R, _______

#define NAV_TOP_L_6     _______, NAV_TOP_L
#define NAV_MID_L_6     _______, NAV_MID_L
#define NAV_BOT_L_6     _______, NAV_BOT_L

#define NAV_TOP_R_6     NAV_TOP_R, _______
#define NAV_MID_R_6     NAV_MID_R, _______
#define NAV_BOT_R_6     NAV_BOT_R, _______

#define NUM_TOP_L_6     _______, NUM_TOP_L
#define NUM_MID_L_6     _______, NUM_MID_L
#define NUM_BOT_L_6     _______, NUM_BOT_L

#define NUM_TOP_R_6     NUM_TOP_R, _______
#define NUM_MID_R_6     NUM_MID_R, _______
#define NUM_BOT_R_6     NUM_BOT_R, _______

enum userspace_layers {
    MTGAP = 0,
    SYM,
    NAV,
    NUM,
};
