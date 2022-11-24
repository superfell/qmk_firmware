#include QMK_KEYBOARD_H

#include "layers.h"
#include "keycodes.h"
#include "process_records.h"

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

/* Tap-Hold keycodes */
#define KC_LOWER LT(_LOWER, KC_ENT) /* Tap for Enter, Hold for LOWER layer */
#define KC_RAISE LT(_RAISE, KC_SPC) /* Tap for Space, Hold for RAISE layer */

#define ONE_GRV LT(1,KC_GRAVE)
#define CTL_Z LCTL_T(KC_Z)
#define ALT_SHFT LALT(KC_LSFT)
#define ALT_MENU LALT_T(KC_MENU)
#define LG_QUOT LGUI_T(KC_QUOT)
#define CTL_ESC LCTL_T(KC_ESC)
#define CTL_SLS LCTL_T(KC_SLSH)
#define LT2_COL LT(_RAISE, KC_SCLN)

#define TD_Q TD(TD_GUI_Q)
#define TD_W TD(TD_GUI_W)
#define TD_A TD(TD_GUI_A)
#define TD_Z TD(TD_GUI_Z)
#define TD_X TD(TD_GUI_X)
#define TD_C TD(TD_GUI_C)
#define TD_V TD(TD_GUI_V)
#define TD_MINS TD(TD_CTL_MINUS)

/* Tap Dance keycodes */
#if defined(TAP_DANCE_ENABLE)
    #include "tap_dances.h"
    #define KC_T_SFT T_SFT /* Single tap for Shift, Double tap for CAPS Lock */
#else
    #define KC_T_SFT KC_LSFT
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.       ,-----------------------------------------------------.
         KC_TAB,    TD_Q,    KC_W,    KC_F,    KC_P,    KC_B,            KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN, KC_BSLS,
    //|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|
        KC_BSPC,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,            KC_M,    KC_N,    KC_E,    KC_I,    KC_O, KC_QUOT,
    //|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|
          T_SFT,    TD_Z,    TD_X,    TD_C,    KC_D,    TD_V,            KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH,  KC_ESC,
    //|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|
                                   KC_RAISE,KC_LALT, KC_LCTL,       T_SFT , KC_LOWER,  KC_LGUI
    //                            `-------------------------'       `--------------------------'
    ),

    [_LOWER] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.       ,-----------------------------------------------------.
        _______,    KC_0,    KC_1,    KC_2,    KC_3, KC_MINS,         KC_PGUP, KC_HOME,   KC_UP,  KC_END,  KC_ESC, _______,
    //|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|
        _______, KC_SLSH,    KC_4,    KC_5,    KC_6, KC_PLUS,         KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT,  KC_DEL, _______,
    //|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|
        _______, KC_ASTR,    KC_7,    KC_8,    KC_9,  KC_EQL,         XXXXXXX, LALT(KC_LEFT), XXXXXXX, LALT(KC_RGHT), XXXXXXX, _______,
    //|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|
                       LT(_ADJUST, KC_SPC), _______, _______,         _______, _______, _______
    //                            `-------------------------'       `--------------------------'
    ),

    [_RAISE] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.       ,-----------------------------------------------------.
        _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,         KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_F11,
    //|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|
        _______,_______, _______, LSFT(KC_QUOT),LSFT(KC_SCLN), KC_F5, KC_GRV, TD_MINS,  KC_EQL, KC_LBRC, KC_RBRC,  KC_F12,
    //|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|
        _______,_______, _______,  KC_QUOT, KC_SCLN, KC_F6,          KC_TILD, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, _______,
    //|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|
                                   _______, _______, _______,         _______,LT(_ADJUST, KC_ENT), _______
    //                            `-------------------------'       `--------------------------'
    ),

    [_ADJUST] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.       ,-----------------------------------------------------.
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,           KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    //|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|
        XXXXXXX, XXXXXXX, VSCTERM, KC_PSCR, CHNLANG, XXXXXXX,         XXXXXXX,RGB_RMOD, RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD,
    //|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
    //|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|
                                   XXXXXXX, XXXXXXX, _______,         _______, XXXXXXX, XXXXXXX
    //                            `-------------------------'       `--------------------------'
    )
};


void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  //debug_enable=true;
  //debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}