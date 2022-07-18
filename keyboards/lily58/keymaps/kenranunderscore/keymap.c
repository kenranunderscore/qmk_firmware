#include "kenranunderscore.h"
#include "oneshot.h"
#include QMK_KEYBOARD_H

#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MTGAP] = LAYOUT_WRAPPER(
        XXXXXXX, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, XXXXXXX,
        KC_TAB,  MTGAP_TOP_L,                   MTGAP_TOP_R, KC_ESC,
        MC(BSPC),MTGAP_MID_L,                   MTGAP_MID_R, KC_QUOT,
        O(LSFT), MTGAP_BOT_L, XXXXXXX, XXXXXXX, MTGAP_BOT_R, O(RSFT),
        XXXXXXX, XXXXXXX, LA_NAV,  KC_SPC,  KC_ENT,  LA_SYM, XXXXXXX, XXXXXXX ),

    [SYM] = LAYOUT_WRAPPER(
        XXXXXXX, ROW_5_TRANSP,                 ROW_5_TRANSP, XXXXXXX,
        _______, SYM_TOP_L,                       SYM_TOP_R, _______,
        _______, SYM_MID_L,                       SYM_MID_R, _______,
        _______, SYM_BOT_L,   XXXXXXX, XXXXXXX,   SYM_BOT_R, _______,
        _______, _______, _______, _______, _______, _______, _______, _______ ),

    [NAV] = LAYOUT_WRAPPER(
        XXXXXXX, ROW_5_TRANSP,                 ROW_5_TRANSP, XXXXXXX,
        _______, NAV_TOP_L,                       NAV_TOP_R, _______,
        _______, NAV_MID_L,                       NAV_MID_R, _______,
        _______, NAV_BOT_L,   XXXXXXX, XXXXXXX,   NAV_BOT_R, _______,
        _______, _______, _______, _______, _______, _______, _______, _______ ),

    [NUM] = LAYOUT_WRAPPER(
        XXXXXXX, ROW_5_TRANSP,                 ROW_5_TRANSP, XXXXXXX,
        _______, NUM_TOP_L,                       NUM_TOP_R, _______,
        _______, NUM_MID_L,                       NUM_MID_R, _______,
        _______, NUM_BOT_L,   XXXXXXX, XXXXXXX,   NUM_BOT_R, _______,
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

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, SYM, NAV, NUM);
}

extern uint8_t is_master;

#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
  return false;
}

#endif // OLED_ENABLE
