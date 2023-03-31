#include "kenranunderscore.h"
#include "oneshot.h"
#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MTGAP] = LAYOUT_WRAPPER(
        XXXXXXX, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, XXXXXXX,
        MTGAP_TOP_L_6,                   MTGAP_TOP_R_6,
        MTGAP_MID_L_6,                   MTGAP_MID_R_6,
        MTGAP_BOT_L_6, XXXXXXX, XXXXXXX, MTGAP_BOT_R_6,
        XXXXXXX, TMB_L1, TMB_L2,  TMB_L3,  TMB_R1,  TMB_R2, TMB_R3, XXXXXXX ),

    [SYM] = LAYOUT_WRAPPER(
        XXXXXXX, ROW_5_TRANSP,                 ROW_5_TRANSP, XXXXXXX,
        SYM_TOP_L_6,                       SYM_TOP_R_6,
        SYM_MID_L_6,                       SYM_MID_R_6,
        SYM_BOT_L_6,   XXXXXXX, XXXXXXX,   SYM_BOT_R_6,
        _______, _______, _______, _______, _______, _______, _______, _______ ),

    [NAV] = LAYOUT_WRAPPER(
        XXXXXXX, ROW_5_TRANSP,                 ROW_5_TRANSP, XXXXXXX,
        NAV_TOP_L_6,                       NAV_TOP_R_6,
        NAV_MID_L_6,                       NAV_MID_R_6,
        NAV_BOT_L_6,   XXXXXXX, XXXXXXX,   NAV_BOT_R_6,
        _______, _______, _______, _______, _______, _______, _______, _______ ),

    [NUM] = LAYOUT_WRAPPER(
        XXXXXXX, ROW_5_TRANSP,                 ROW_5_TRANSP, XXXXXXX,
        NUM_TOP_L_6,                       NUM_TOP_R_6,
        NUM_MID_L_6,                       NUM_MID_R_6,
        NUM_BOT_L_6,   XXXXXXX, XXXXXXX,   NUM_BOT_R_6,
        _______, _______, _______, _______, _______, _______, _______, _______ ),
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
