// Copyright 2022 Álvaro Cortés (@ACortesDev)
// SPDX-License-Identifier: GPL-2.0-or-later
#include "layers.h"
#include "keycodes.h"
#include "tap_dances.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    qk_tap_dance_action_t *action;
    /* Macros */
    switch (keycode) {
        case VSCTERM:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("`")); // Ctrl + ` (to toggle vscode terminal)
            }
            return false;
        case CHNLANG:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_LSFT("n"))); // Ctrl + Shift + N (to change keyboard layout)
            }
            return false;
        // tap dance
        case TD(TD_GUI_Q):  // list all tap dance keycodes with tap-hold configurations
        case TD(TD_GUI_W):  // list all tap dance keycodes with tap-hold configurations
        case TD(TD_GUI_A):  // list all tap dance keycodes with tap-hold configurations
        case TD(TD_GUI_Z):  // list all tap dance keycodes with tap-hold configurations
        case TD(TD_GUI_X):  // list all tap dance keycodes with tap-hold configurations
        case TD(TD_GUI_C):  // list all tap dance keycodes with tap-hold configurations
        case TD(TD_GUI_V):  // list all tap dance keycodes with tap-hold configurations
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
    }
    return true;
}
