#include "kenranunderscore.h"
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
        ROW_6_BLANK, ROW_6_BLANK,
        MTGAP_TOP_L_6_ALT,                   MTGAP_TOP_R_6,
        MTGAP_MID_L_6,                   MTGAP_MID_R_6,
        MTGAP_BOT_L_6_ALT, XXXXXXX, XXXXXXX, MTGAP_BOT_R_6_ALT,
        XXXXXXX, XXXXXXX, TMB_L2,  TMB_L3,  TMB_R1,  TMB_R2, XXXXXXX, XXXXXXX ),

    [SYM] = LAYOUT_WRAPPER(
        ROW_6_TRANSP,                       ROW_6_TRANSP,
        SYM_TOP_L_6,                       SYM_TOP_R_6,
        SYM_MID_L_6,                       SYM_MID_R_6,
        SYM_BOT_L_6,   XXXXXXX, XXXXXXX,   SYM_BOT_R_6,
        _______, _______, _______, _______, _______, _______, _______, _______ ),

    [NUM] = LAYOUT_WRAPPER(
        ROW_6_TRANSP,                       ROW_6_TRANSP,
        NUM_TOP_L_6,                       NUM_TOP_R_6,
        NUM_MID_L_6,                       NUM_MID_R_6,
        NUM_BOT_L_6,   XXXXXXX, XXXXXXX,   NUM_BOT_R_6,
        _______, _______, _______, _______, _______, _______, _______, _______ ),

    [NAV] = LAYOUT_WRAPPER(
        ROW_6_TRANSP,                       ROW_6_TRANSP,
        NAV_TOP_L_6,                       NAV_TOP_R_6,
        NAV_MID_L_6,                       NAV_MID_R_6,
        NAV_BOT_L_6,   XXXXXXX, XXXXXXX,   NAV_BOT_R_6,
        _______, _______, _______, _______, _______, _______, _______, _______ ),
};

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
