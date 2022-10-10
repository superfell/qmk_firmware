// Copyright 2022 Álvaro Cortés (@ACortesDev)
// SPDX-License-Identifier: GPL-2.0-or-later
#include "tap_dances.h"


void tap_dance_tap_hold_finished(qk_tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (state->pressed) {
        if (state->count == 1
#ifndef PERMISSIVE_HOLD
            && !state->interrupted
#endif
        ) {
            register_code16(tap_hold->hold);
            tap_hold->held = tap_hold->hold;
        } else {
            register_code16(tap_hold->tap);
            tap_hold->held = tap_hold->tap;
        }
    }
}

void tap_dance_tap_hold_reset(qk_tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (tap_hold->held) {
        unregister_code16(tap_hold->held);
        tap_hold->held = 0;
    }
}

#define ACTION_TAP_DANCE_TAP_HOLD(tap, hold) \
    { .fn = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset}, .user_data = (void *)&((tap_dance_tap_hold_t){tap, hold, 0}), }


qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_LSFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
    [TD_GUI_Q]     = ACTION_TAP_DANCE_TAP_HOLD(KC_Q, LCMD(KC_Q)),
    [TD_GUI_W]     = ACTION_TAP_DANCE_TAP_HOLD(KC_W, LCMD(KC_W)),
    [TD_GUI_A]     = ACTION_TAP_DANCE_TAP_HOLD(KC_A, LCMD(KC_A)),
    [TD_GUI_Z]     = ACTION_TAP_DANCE_TAP_HOLD(KC_Z, LCMD(KC_Z)),
    [TD_GUI_X]     = ACTION_TAP_DANCE_TAP_HOLD(KC_X, LCMD(KC_X)),
    [TD_GUI_C]     = ACTION_TAP_DANCE_TAP_HOLD(KC_C, LCMD(KC_C)),
    [TD_GUI_V]     = ACTION_TAP_DANCE_TAP_HOLD(KC_V, LCMD(KC_V)),
};
