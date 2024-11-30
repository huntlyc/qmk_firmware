// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#define _BASE  0
#define _LOWER 1
#define _RAISE 2
#define _CTRL  3

#define RAISE MO(_RAISE)
#define CTRL  TG(_CTRL)
#define LOWER MO(_LOWER)


// Left-hand home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LSFT_T(KC_D)
#define HOME_F LCTL_T(KC_F)

// Right-hand home row mods
#define HOME_J RCTL_T(KC_J)
#define HOME_K RSFT_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_SCLN RGUI_T(KC_SCLN)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * // Rough aprox layout, bottom rows curved
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │ = │ 1 │ 2 │ 3 │ 4 │ 5 │       │ 6 │ 7 │ 8 │ 9 │ 0 │ - │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Tab│ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │ # │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Esc│ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ; │ ' │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Sft│ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ / │Sft│
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *
      *      ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      *      │ ` │ \ │Bsp│Del│LWR│       │RSE│Ent│Spc│ [ │ ] │
      *      └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *                  ┌───┐               ┌───┐
      *                  │Win│               │Ctl│
      *                  └───┘               └───┘
      *
      *
      *
      *LAYOUT_cosmos_dactyl_5x6
      */
    [_BASE] = LAYOUT_cosmos_dactyl_5x6(
        KC_EQL,  KC_1, KC_2, KC_3, KC_4, KC_5,                          KC_6, KC_7, KC_8,    KC_9,   KC_0,    KC_MINS,
        KC_TAB,  KC_Q, KC_W, KC_E, KC_R, KC_T,                          KC_Y, KC_U, KC_I,    KC_O,   KC_P,    KC_NUHS,
        KC_ESC,  HOME_A, HOME_S, HOME_D, HOME_F, KC_G,                          KC_H, KC_J, KC_K,    KC_L,   KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B,                          KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
                    KC_GRV, KC_NUBS, KC_DEL, LOWER,            RAISE, KC_ENT, KC_LBRC, KC_RBRC,
                                            KC_BSPC, KC_LCMD,   KC_SPC, KC_RCTL
    ),
    [_LOWER] = LAYOUT_cosmos_dactyl_5x6(
        _______,  _______, _______, _______, KC_END, _______,                          KC_HOME, _______, _______,    _______,   _______,    _______,
        _______,  _______, _______, _______, _______, _______,                          _______, KC_PGUP, _______,    _______,   _______,    _______,
        _______,  _______, _______, KC_PGDN, _______, _______,                          KC_LEFT, KC_DOWN, KC_UP,    KC_RIGHT,   _______, CTRL,
        _______, _______, _______, _______, _______, _______,                          _______, _______, _______, _______, _______, _______,
                    _______, _______, _______, _______,                   KC_BSPC, KC_DEL, _______, _______,
                                            _______, _______,           _______,  _______
    ),
    [_RAISE] = LAYOUT_cosmos_dactyl_5x6(
        _______,  _______, _______, _______, _______, _______,                          _______, _______, _______,    _______,   _______,    _______,
        _______,  _______, _______, MS_BTN1, MS_BTN2, _______,                          _______, _______, _______,    _______,   _______,    _______,
        _______,  _______, _______, _______, _______, _______,                          MS_LEFT, MS_DOWN, MS_UP,    MS_RGHT,   _______, _______,
        _______, _______, _______, _______, _______, _______,                          _______, _______, _______, _______, _______, _______,
                    _______, _______, _______, _______,                   _______, _______, _______, _______,
                                            _______, _______,           _______,  _______
    ),
    [_CTRL] = LAYOUT_cosmos_dactyl_5x6(
        _______,  _______, _______, _______, _______, _______,                          _______, _______, _______,    _______,   _______,    _______,
        _______,  _______, _______, _______, _______, _______,                          _______, _______, _______,    _______,   _______,    _______,
        KC_ESC,  HOME_A, HOME_S, HOME_D, HOME_F, KC_G,                                  _______, _______, _______,    _______,   _______,    _______,
        _______, _______, _______, _______, _______, _______,                          _______, _______, _______, _______, _______, _______,
                    _______, _______, _______, _______,                   _______, _______, _______, _______,
                                            _______, KC_LCTL,           _______,  _______
    ),


};


//yyyuuuuuiiiooo111w111wwww///wwwqqq66556666666666111wwwwwnnnw[]\`¬```\\\`\wwwqqqww
