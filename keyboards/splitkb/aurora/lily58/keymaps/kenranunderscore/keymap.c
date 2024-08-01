#include "kenranunderscore.h"
#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MTGAP] = LAYOUT_WRAPPER(
        XXXXXXX, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, XXXXXXX,
        MTGAP_TOP_L,                   MTGAP_TOP_R,
        MTGAP_MID_L,                   MTGAP_MID_R,
        MTGAP_BOT_L, XXXXXXX, XXXXXXX, MTGAP_BOT_R,
        XXXXXXX, TMB_L1, TMB_L2,  TMB_L3,  TMB_R1,  TMB_R2, TMB_R3, XXXXXXX ),

    [SYM] = LAYOUT_WRAPPER(
        ROW_6_TRANSP,                      ROW_6_TRANSP,
        SYM_TOP_L,                       SYM_TOP_R,
        SYM_MID_L,                       SYM_MID_R,
        SYM_BOT_L,   XXXXXXX, XXXXXXX,   SYM_BOT_R,
        _______, _______, _______, _______, _______, _______, _______, _______ ),

    [NUM] = LAYOUT_WRAPPER(
        ROW_6_TRANSP,                      ROW_6_TRANSP,
        NUM_TOP_L,                       NUM_TOP_R,
        NUM_MID_L,                       NUM_MID_R,
        NUM_BOT_L,   XXXXXXX, XXXXXXX,   NUM_BOT_R,
        _______, _______, _______, _______, _______, _______, _______, _______ ),

    [NAV] = LAYOUT_WRAPPER(
        ROW_6_TRANSP,                      ROW_6_TRANSP,
        NAV_TOP_L,                       NAV_TOP_R,
        NAV_MID_L,                       NAV_MID_R,
        NAV_BOT_L,   XXXXXXX, XXXXXXX,   NAV_BOT_R,
        _______, _______, _______, _______, _______, _______, _______, _______ ),
};
