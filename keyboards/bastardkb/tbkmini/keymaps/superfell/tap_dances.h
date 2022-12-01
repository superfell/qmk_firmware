// Copyright 2022 Álvaro Cortés (@ACortesDev)
// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once

#include QMK_KEYBOARD_H

typedef struct {
    uint16_t tap;
    uint16_t hold;
    uint16_t held;
} tap_dance_tap_hold_t;

enum custom_tapdances{
    TD_LSFT_CAPS = 0,
    TD_GUI_Q,
    TD_GUI_W,
    TD_GUI_A,
    TD_GUI_Z,
    TD_GUI_X,
    TD_GUI_C,
    TD_GUI_V,
    TD_CTL_MINUS
};

#define T_SFT TD(TD_LSFT_CAPS) /* Tap for Shift, double tap for CAPSLOCK */
