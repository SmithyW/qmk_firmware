#include QMK_KEYBOARD_H

// Ebene 1 + Ebene 2 gleichzeitig -> Ebene 3 (LED)
layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, 1, 2, 3);
}

// Linker Encoder: Ebene 1 = Lautstaerke, sonst PgUp/PgDn. Rechter Encoder ohne Funktion.
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (get_highest_layer(layer_state) == 1) {
            tap_code(clockwise ? KC_VOLU : KC_VOLD);
        } else {
            tap_code(clockwise ? KC_PGDN : KC_PGUP);
        }
    }
    return false;
}
