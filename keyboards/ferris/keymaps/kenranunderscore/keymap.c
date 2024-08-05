#include "kenranunderscore.h"
#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

/* enum ferris_tap_dances { */
/*   TD_Q_ESC */
/* }; */

/* // Tap Dance Definitions */
/* qk_tap_dance_action_t tap_dance_actions[] = { */
/*     // Tap once for Q, twice for ESC */
/*     [TD_Q_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC) */
/* }; */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MTGAP] = LAYOUT_WRAPPER(
        MTGAP_TOP_L, MTGAP_TOP_R,
        MTGAP_MID_L, MTGAP_MID_R,
        MTGAP_BOT_L, MTGAP_BOT_R,
        TMB_L2, TMB_L3, TMB_R1, TMB_R2 ),

    [SYM] = LAYOUT_WRAPPER(
        SYM_TOP_L, SYM_TOP_R,
        SYM_MID_L, SYM_MID_R,
        SYM_BOT_L, SYM_BOT_R,
        _______, _______, _______, _______ ),

    [NAV] = LAYOUT_WRAPPER(
        NAV_TOP_L, NAV_TOP_R,
        NAV_MID_L, NAV_MID_R,
        NAV_BOT_L, NAV_BOT_R,
        _______, _______, _______, _______ ),

    [NUM] = LAYOUT_WRAPPER(
        NUM_TOP_L, NUM_TOP_R,
        NUM_MID_L, NUM_MID_R,
        NUM_BOT_L, NUM_BOT_R,
        _______, _______, _______, _______ ),
};
