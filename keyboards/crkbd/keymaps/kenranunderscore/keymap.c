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
#include "oneshot.h"
#include QMK_KEYBOARD_H

#define LA_SYM MO(SYM)
#define LA_NAV MO(NAV)

enum layers {
    DEF,
    SYM,
    NAV,
    NUM,
};

enum keycodes {
    // Custom oneshot mod implementation with no timers.
    OS_SHFT = SAFE_RANGE,
    OS_CTRL,
    OS_ALT,
    OS_CMD,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [DEF] = LAYOUT_WRAPPER(
        XXXXXXX, KC_Y,   KC_P,    KC_O,    KC_U,    KC_J,     KC_K,    KC_D,    KC_L,    KC_C,    KC_W,    XXXXXXX,
        XXXXXXX, KC_I,   KC_N,    KC_E,    KC_A,    KC_COMM,  KC_M,    KC_H,    KC_T,    KC_S,    KC_R,    XXXXXXX,
        XXXXXXX, KC_Q,   KC_Z,    KC_SLSH, KC_DOT,  KC_SCLN,  KC_B,    KC_F,    KC_G,    KC_V,    KC_X,    XXXXXXX,
                             XXXXXXX,  LA_NAV,  KC_SPC, KC_ENT,  LA_SYM,  XXXXXXX ),

    [SYM] = LAYOUT_WRAPPER(
        _______, KC_ESC,  KC_LBRC, KC_LCBR, KC_LPRN, KC_TILD, KC_CIRC, KC_RPRN, KC_RCBR, KC_RBRC, KC_GRV,  _______,
        _______, KC_MINS, KC_ASTR, KC_EQL,  KC_UNDS, KC_DLR,  KC_HASH, OS_CMD,  OS_CTRL, OS_ALT,  OS_SHFT, _______,
        _______, KC_PLUS, KC_PIPE, KC_AT,   KC_BSLS, KC_PERC, KC_QUOT, KC_AMPR, KC_SCLN, KC_COLN, KC_EXLM, _______,
                             _______, _______, _______, _______, _______, _______ ),

    [NAV] = LAYOUT_WRAPPER(
        _______, KC_TAB,  XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLU, RESET,   XXXXXXX, XXXXXXX, KC_DEL,  KC_BSPC, _______,
        _______, OS_SHFT, OS_ALT,  OS_CTRL, OS_CMD,  KC_VOLD, KC_CAPS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PGDN, KC_PGUP, XXXXXXX, KC_ENT,  _______,
                             _______, _______, _______, _______, _______, _______ ),

    [NUM] = LAYOUT_WRAPPER(
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
        _______, OS_SHFT, OS_ALT,  OS_CTRL, OS_CMD,  KC_F11,  KC_F10,  OS_CMD,  OS_CTRL, OS_ALT,  OS_SHFT, _______,
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
                             _______, _______, _______, _______, _______, _______ ),
};

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
    case LA_SYM:
    /* case LA_NAV: */
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

/* #ifdef OLED_DRIVER_ENABLE */

/* oled_rotation_t oled_init_user(oled_rotation_t rotation) { */
/*     if (!is_keyboard_master()) { */
/*       return OLED_ROTATION_180;  // flips the display 180 degrees if offhand */
/*     } */
/*     return rotation; */
/* } */

/* void oled_render_layer_state(void) { */
/*     oled_write_P(PSTR("Layer: "), false); */
/*     switch (layer_state) { */
/*         case DEF: */
/*             oled_write_ln_P(PSTR("MTGAP"), false); */
/*             break; */
/*         case SYM: */
/*             oled_write_ln_P(PSTR("SYM"), false); */
/*             break; */
/*         case NAV: */
/*             oled_write_ln_P(PSTR("NAV"), false); */
/*             break; */
/*         case NUM: */
/*             oled_write_ln_P(PSTR("NUM"), false); */
/*             break; */
/*         default: */
/*             oled_write_ln_P(PSTR("<undefined>"), false); */
/*     } */
/* } */


/* void render_bootmagic_status(bool status) { */
/*     /\* Show Ctrl-Gui Swap options *\/ */
/*     static const char PROGMEM logo[][2][3] = { */
/*         {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}}, */
/*         {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}}, */
/*     }; */
/*     if (status) { */
/*         oled_write_ln_P(logo[0][0], false); */
/*         oled_write_ln_P(logo[0][1], false); */
/*     } else { */
/*         oled_write_ln_P(logo[1][0], false); */
/*         oled_write_ln_P(logo[1][1], false); */
/*     } */
/* } */

/* void oled_render_logo(void) { */
/*     static const char PROGMEM crkbd_logo[] = { */
/*         0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94, */
/*         0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4, */
/*         0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4, */
/*         0}; */
/*     oled_write_P(crkbd_logo, false); */
/* } */

/* void oled_task_user(void) { */
/*     if (is_keyboard_master()) { */
/*         oled_render_layer_state(); */
/*     } else { */
/*         oled_render_logo(); */
/*     } */
/* } */

/* #endif // OLED_DRIVER_ENABLE */
