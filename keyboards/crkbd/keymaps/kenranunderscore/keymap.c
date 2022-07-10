/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "kenranunderscore.h"
#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [MTGAP] = LAYOUT_WRAPPER(MTGAP_TOP_L, MTGAP_TOP_R,
                           MTGAP_MID_L, MTGAP_MID_R,
                           MTGAP_BOT_L, MTGAP_BOT_R,
                           THMB_L1, THMB_L2, THMB_L3, THMB_R1, THMB_R2, THMB_R3),

  [SYMBOL] = LAYOUT_WRAPPER(SYMBOL_TOP_L, SYMBOL_TOP_R,
                            SYMBOL_MID_L, SYMBOL_MID_R,
                            SYMBOL_BOT_L, SYMBOL_BOT_R,
                            ROW_6_TRANSP),

  [NUM_NAV] = LAYOUT_WRAPPER(NUM_NAV_TOP_L, NUM_NAV_TOP_R,
                             NUM_NAV_MID_L, NUM_NAV_MID_R,
                             NUM_NAV_BOT_L, NUM_NAV_BOT_R,
                             ROW_6_TRANSP),

  [ADJUST] = LAYOUT_WRAPPER(ADJUST_TOP_L, ADJUST_TOP_R,
                            ADJUST_MID_L, ADJUST_MID_R,
                            ADJUST_BOT_L, ADJUST_BOT_R,
                            ROW_6_TRANSP),
};

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
      return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
    }
    return rotation;
}

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case MTGAP:
            oled_write_ln_P(PSTR("MTGAP"), false);
            break;
        case SYMBOL:
            oled_write_ln_P(PSTR("SYM"), false);
            break;
        case NUM_NAV:
            oled_write_ln_P(PSTR("NUM"), false);
            break;
        case ADJUST:
            oled_write_ln_P(PSTR("ADJS"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undefined"), false);
    }
}


void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
    } else {
        oled_render_logo();
    }
}

#endif // OLED_DRIVER_ENABLE
