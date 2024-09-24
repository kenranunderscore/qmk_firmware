#pragma once

#include "quantum.h"
#include QMK_KEYBOARD_H

#define MTGAP 0
#define QWERTY 1
#define SYM 2
#define NUM 3
#define NAV 4

/* Layer modifiers */
#define LA_SYM MO(SYM)
#define LA_NAV MO(NAV)

/* Mod taps */
#define MS(kc) LSFT_T(KC_##kc)
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
#define TMB_L2 LT(NUM, KC_BSPC)
#define TMB_L3 KC_SPC
#define TMB_R1 KC_ENT
#define TMB_R2 LT(SYM, KC_ESC)
#define TMB_R3 KC_LGUI
#define NAV_TAB LT(NAV, KC_TAB)
#define NAV_Y LT(NAV, KC_Y)

#define OS_SHFT OSM(MOD_LSFT)

/* A wrapper around the LAYOUT macro to pass through evaluated arguments. */
#define LAYOUT_WRAPPER(...) LAYOUT(__VA_ARGS__)

/* Core MTGAP layout */
// left              ┌────────┬────────┬────────┬────────┬────────┐
#define MTGAP_TOP_L   NAV_Y,   KC_P,    KC_O,    KC_U,    KC_J
#define MTGAP_MID_L   KC_I,    KC_N,    KC_E,    KC_A,    KC_COMM
#define MTGAP_BOT_L   MS(Q),   MA(Z),   MC(SLSH),MG(DOT), KC_SCLN

#define MTGAP_TOP_L_6 NAV_TAB, MTGAP_TOP_L
#define MTGAP_MID_L_6 KC_BSPC, MTGAP_MID_L
#define MTGAP_BOT_L_6 KC_LSFT, MTGAP_BOT_L

#define MTGAP_TOP_L_6_ALT NAV_TAB, KC_Y, KC_P, KC_O, KC_U, KC_J
#define MTGAP_BOT_L_6_ALT OS_SHFT, KC_Q, MA(Z), MC(SLSH), MG(DOT), KC_SCLN

// right             ┌────────┬────────┬────────┬────────┬────────┐
#define MTGAP_TOP_R   KC_K,    KC_D,    KC_L,    KC_C,    KC_W
#define MTGAP_MID_R   KC_M,    KC_H,    KC_T,    KC_S,    KC_R
#define MTGAP_BOT_R   KC_B,    MG(F),   MC(G),   MA(V),   MS(X)

#define MTGAP_TOP_R_6 MTGAP_TOP_R, KC_MINS
#define MTGAP_MID_R_6 MTGAP_MID_R, KC_QUOT
#define MTGAP_BOT_R_6 MTGAP_BOT_R, KC_RSFT

#define MTGAP_BOT_R_6_ALT KC_B, MG(F), MC(G), MA(V), KC_X, OSM(MOD_RSFT)

// left              ┌────────┬────────┬────────┬────────┬────────┐
#define SYM_TOP_L     KC_EXLM, KC_QUOT, KC_LCBR, KC_RCBR, KC_GRV
#define SYM_MID_L     KC_ASTR, KC_DQT,  KC_LPRN, KC_RPRN, KC_TILD
#define SYM_BOT_L     KC_EQL,  KC_PIPE, KC_LBRC, KC_RBRC, KC_PERC

#define SYM_TOP_L_6   _______, SYM_TOP_L
#define SYM_MID_L_6   _______, SYM_MID_L
#define SYM_BOT_L_6   _______, SYM_BOT_L

// right             ┌────────┬────────┬────────┬────────┬────────┐
#define SYM_TOP_R     _______, _______, _______, _______, _______
#define SYM_MID_R     _______, _______, _______, _______, _______
#define SYM_BOT_R     _______, _______, _______, _______, _______

#define SYM_TOP_R_6   SYM_TOP_R, _______
#define SYM_MID_R_6   SYM_MID_R, _______
#define SYM_BOT_R_6   SYM_BOT_R, _______

// left              ┌────────┬────────┬────────┬────────┬────────┐
#define NUM_TOP_L     KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define NUM_MID_L     _______, _______, _______, _______, _______
#define NUM_BOT_L     MS(F1),  MA(F2),  MC(F3),  MG(F4),  KC_F5

#define NUM_TOP_L_6   _______, NUM_TOP_L
#define NUM_MID_L_6   _______, NUM_MID_L
#define NUM_BOT_L_6   _______, NUM_BOT_L

// right             ┌────────┬────────┬────────┬────────┬────────┐
#define NUM_TOP_R     KC_6,    KC_7,    KC_8,    KC_9,    KC_0
#define NUM_MID_R     KC_BSLS, KC_CIRC, KC_MINS, KC_UNDS, KC_DLR
#define NUM_BOT_R     KC_F6,   MG(F7),  MC(F8),  MA(F9),  MS(F10)

#define NUM_TOP_R_6   NUM_TOP_R, _______
#define NUM_MID_R_6   NUM_MID_R, _______
#define NUM_BOT_R_6   NUM_BOT_R, _______

// left              ┌────────┬────────┬────────┬────────┬────────┐
#define NAV_TOP_L     XXXXXXX, RGB_HUI, RGB_SAI, RGB_VAI, RGB_TOG
#define NAV_MID_L     RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, KC_VOLD
#define NAV_BOT_L     KC_LSFT, KC_LALT, KC_LCTL, KC_LGUI, XXXXXXX

#define NAV_TOP_L_6   XXXXXXX, NAV_TOP_L
#define NAV_MID_L_6   _______, NAV_MID_L
#define NAV_BOT_L_6   _______, NAV_BOT_L

// right             ┌────────┬────────┬────────┬────────┬────────┐
#define NAV_TOP_R     KC_PGDN, KC_PGUP, KC_TAB,  KC_DEL,  KC_BSPC
#define NAV_MID_R     KC_CAPS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
#define NAV_BOT_R     S_GER,   A_UML,   O_UML,   U_UML,   KC_ENT

#define NAV_TOP_R_6   NAV_TOP_R, _______
#define NAV_MID_R_6   NAV_MID_R, _______
#define NAV_BOT_R_6   NAV_BOT_R, _______

// misc              ┌────────┬────────┬────────┬────────┬────────┐
#define ROW_TRANSP    _______, _______, _______, _______, _______
#define ROW_BLANK     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX

#define ROW_6_TRANSP  ROW_TRANSP, _______
#define ROW_6_BLANK   ROW_BLANK,  XXXXXXX
