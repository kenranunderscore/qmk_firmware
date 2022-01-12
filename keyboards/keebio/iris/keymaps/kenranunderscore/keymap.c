#include "kenranunderscore.h"
#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MTGAP] =
    LAYOUT_WRAPPER(
                   NUM_NAV_TOP_L,                                                     NUM_NAV_TOP_R,
                   MTGAP_TOP_L,                                                         MTGAP_TOP_R,
                   MTGAP_MID_L,                                                         MTGAP_MID_R,
                   MTGAP_BOT_L,               _______,           _______,               MTGAP_BOT_R,
                            THMB_L1, THMB_L2, THMB_L3,           THMB_R1, THMB_R2, THMB_R3
                   ),
    [SYMBOL] =
    LAYOUT_WRAPPER(
                   ROW_6_TRANSP,                                                       ROW_6_TRANSP,
                   SYMBOL_TOP_L,                                                       SYMBOL_TOP_R,
                   SYMBOL_MID_L,                                                       SYMBOL_MID_R,
                   SYMBOL_BOT_L,              _______,           _______,              SYMBOL_BOT_R,
                            _______, _______, _______,           _______, _______, _______        
                   ),
    [NUM_NAV] =
    LAYOUT_WRAPPER(
                   ROW_6_TRANSP,                                                       ROW_6_TRANSP,
                   NUM_NAV_TOP_L,                                                     NUM_NAV_TOP_R,
                   NUM_NAV_MID_L,                                                     NUM_NAV_MID_R,
                   NUM_NAV_BOT_L,             _______,           _______,             NUM_NAV_BOT_R,
                            _______, _______, _______,           _______, _______, _______
                   ),
    [ADJUST] =
    LAYOUT_WRAPPER(
                   ROW_6_TRANSP,                                                       ROW_6_TRANSP,
                   ADJUST_TOP_L,                                                       ADJUST_TOP_R,
                   ADJUST_MID_L,                                                       ADJUST_MID_R,
                   ADJUST_BOT_L,              _______,           _______,              ADJUST_BOT_R,
                            _______, _______, _______,           _______, _______, _______
                   )
};
