#include "kenranunderscore.h"

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, SYMBOL, NUM_NAV, ADJUST);
}

/* uint16_t mtgap_alt_keymap[2][4] = {{ KC_COMM, KC_SLSH, KC_DOT, KC_COLN }, { KC_SCLN, KC_LABK, KC_RABK, KC_QUES }}; */

/* bool process_record_user(uint16_t keycode, keyrecord_t *record) { */
/*   switch (keycode) { */
/*     case MTG_CMM ... MTG_CLN: */
/*       if (record->event.pressed) { */
/*         const uint8_t mod_state = get_mods(); */
/*         const uint16_t key_index = keycode - MTG_CMM; */
/*         if (mod_state & MOD_MASK_SHIFT) { */
/*           unregister_mods(mod_state); */
/*           tap_code16(mtgap_alt_keymap[1][key_index]); */
/*           register_mods(mod_state); */
/*         } else { */
/*           tap_code16(mtgap_alt_keymap[0][key_index]); */
/*         } */
/*       } */
/*       return false; */
/*     default: */
/*       return true; */
/*   } */
/* } */

#ifdef COMBO_ENABLE

const uint16_t PROGMEM r_quot_gui[] = {KC_R, KC_QUOT, COMBO_END};

enum combos {
    R_QUOT_GUI
};

combo_t key_combos[COMBO_COUNT] = {
    [R_QUOT_GUI] = COMBO_ACTION(r_quot_gui)
};

void process_combo_event(uint16_t combo_index, bool pressed) {
    switch(combo_index) {
    case R_QUOT_GUI:
        if (pressed) {
            set_oneshot_mods(MOD_LGUI);
        }
        break;
    }
}

#endif
