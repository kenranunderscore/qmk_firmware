#include "kenranunderscore.h"

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, SYMBOL, NUM_NAV, ADJUST);
}

#ifdef COMBO_ENABLE

const uint16_t PROGMEM dot_comma_gui[] = {KC_DOT, KC_COMMA, COMBO_END};

enum combos {
    DOT_COMMA_GUI
};

combo_t key_combos[COMBO_COUNT] = {
    [DOT_COMMA_GUI] = COMBO_ACTION(dot_comma_gui)
};

void process_combo_event(uint16_t combo_index, bool pressed) {
    switch(combo_index) {
    case DOT_COMMA_GUI:
        if (pressed) {
            register_code(KC_LGUI);
        } else {
            unregister_code(KC_LGUI);
        }
        break;
    }
}

#endif
