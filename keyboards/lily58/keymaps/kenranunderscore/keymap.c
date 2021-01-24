#include "kenranunderscore.h"
#include QMK_KEYBOARD_H

#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

extern uint8_t is_master;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MTGAP] =
    LAYOUT_WRAPPER(
                   NUM_NAV_TOP_L,                                                     NUM_NAV_TOP_R,
                   MTGAP_TOP_L,                                                         MTGAP_TOP_R,
                   MTGAP_MID_L,                                                         MTGAP_MID_R,
                   MTGAP_BOT_L,               _______,           _______,               MTGAP_BOT_R,
                   XXXXXXX, THMB_L1, THMB_L2, THMB_L3,           THMB_R1, THMB_R2, THMB_R3, XXXXXXX
                   ),
    [SYMBOL] =
    LAYOUT_WRAPPER(
                   ROW_6_TRANSP,                                                       ROW_6_TRANSP,
                   SYMBOL_TOP_L,                                                       SYMBOL_TOP_R,
                   SYMBOL_MID_L,                                                       SYMBOL_MID_R,
                   SYMBOL_BOT_L,              _______,           _______,              SYMBOL_BOT_R,
                   _______, _______, _______, _______,           _______, _______, _______, _______
                   ),
    [NUM_NAV] =
    LAYOUT_WRAPPER(
                   ROW_6_TRANSP,                                                       ROW_6_TRANSP,
                   NUM_NAV_TOP_L,                                                     NUM_NAV_TOP_R,
                   NUM_NAV_MID_L,                                                     NUM_NAV_MID_R,
                   NUM_NAV_BOT_L,             _______,           _______,             NUM_NAV_BOT_R,
                   _______, _______, _______, _______,           _______, _______, _______, _______
                   ),
    [ADJUST] =
    LAYOUT_WRAPPER(
                   ROW_6_TRANSP,                                                       ROW_6_TRANSP,
                   ADJUST_TOP_L,                                                       ADJUST_TOP_R,
                   ADJUST_MID_L,                                                       ADJUST_MID_R,
                   ADJUST_BOT_L,              _______,           _______,              ADJUST_BOT_R,
                   _______, _______, _______, _______,           _______, _______, _______, _______
                   )
};

//SSD1306 OLED update loop, make sure to enable OLED_DRIVER_ENABLE=yes in rules.mk
#ifdef OLED_DRIVER_ENABLE

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

void oled_task_user(void) {
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
}
#endif // OLED_DRIVER_ENABLE
