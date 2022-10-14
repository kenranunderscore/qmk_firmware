#include "kenranunderscore.h"
#include "oneshot.h"
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
        LA_NAV, MC(SPC), KC_ESC, LA_SYM ),

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

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
    case LA_SYM:
    case LA_NAV:
        return true;
    default:
        return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
    case LA_SYM:
    case LA_NAV:
    case KC_LSFT:
    case OS_SHFT:
    case OS_CTRL:
    case OS_ALT:
    case OS_CMD:
        return true;
    default:
        return false;
    }
}

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_cmd_state = os_up_unqueued;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    update_oneshot(
        &os_shft_state, KC_LSFT, OS_SHFT,
        keycode, record
    );
    update_oneshot(
        &os_ctrl_state, KC_LCTL, OS_CTRL,
        keycode, record
    );
    update_oneshot(
        &os_alt_state, KC_LALT, OS_ALT,
        keycode, record
    );
    update_oneshot(
        &os_cmd_state, KC_LCMD, OS_CMD,
        keycode, record
    );
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, SYM, NAV, NUM);
}
