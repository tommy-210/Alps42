// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include "keymap_italian.h"

#include QMK_KEYBOARD_H
// Helpful defines
#define GRAVE_MODS  (MOD_BIT(KC_LSFT)|MOD_BIT(KC_RSFT)|MOD_BIT(KC_LGUI)|MOD_BIT(KC_RGUI)|MOD_BIT(KC_LALT)|MOD_BIT(KC_RALT))

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    *  You can use _______ in place for KC_TRNS (transparent)   *
    *  Or you can use XXXXXXX for KC_NO (NOOP)                  *
    * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

// Each layer gets a name for readability.
// The underscores don't mean anything - you can
// have a layer called STUFF or any other name.
// Layer names don't all need to be of the same
// length, and you can also skip them entirely
// and just use numbers.
enum layer_names {
    _BL,
    _ML,
    _AL,
    _FL,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │Tab│ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │Bsp│
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Ctl│ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ò │ à │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Sft│ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ - │Esc│
      * └───┴───┴───┼───┼───┼───┤       ├───┼───┼───┼───┴───┴───┘
      *             │GUI│Spc│-1-│       │-2-│Ent│Alt│
      *             └───┴───┴───┘       └───┴───┴───┘
      */
    // Base layer with alphabetic
    [_BL] = LAYOUT(
         KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
        KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,             KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
        KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,             KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ESC,
        _______, _______, _______, KC_LGUI,  KC_SPC, MO(_ML),          MO(_AL),  KC_ENT, KC_RALT, _______, _______, _______
    ),
    // Motion layer with arrow, numbers
    [_ML] = LAYOUT(
         KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,             KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
        KC_LCTL, KC_CAPS, _______, _______, _______, _______,          KC_LEFT,   KC_UP, KC_DOWN,KC_RIGHT, _______, _______,
        KC_LSFT, KC_LALT, _______, _______, _______, _______,          _______, _______, _______, _______, _______,  KC_ESC,
        _______, _______, _______, KC_LGUI,  KC_SPC, MO(_ML),          MO(_FL),  KC_ENT, KC_RALT, _______, _______, _______
    ),
    [_AL] = LAYOUT(
        KC_TAB,  KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,          KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRM, KC_RPRN, KC_BSPC,
        KC_LCTL, KC_CAPS, _______, _______, _______, _______,          KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV,
        KC_LSFT, KC_LALT, _______, _______, _______, _______,          KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
        _______, _______, _______, KC_LGUI,  KC_SPC, MO(_FL),          MO(_AL),  KC_ENT, KC_RALT, _______, _______, _______
    ),
    [_FL] = LAYOUT(
         QK_RBT, DB_TOGG, _______, KC_BRID, KC_BRIU, _______,          _______, _______, _______, _______, _______, _______,
        QK_BOOT, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______,          MS_LEFT,   MS_UP, MS_DOWN,MS_RIGHT, _______, _______,
        GU_TOGG, _______, _______, _______, _______, _______,          _______, MS_BTN1, MS_BTN2, MS_BTN3, _______, _______,
        _______, _______, _______, KC_LGUI,  KC_SPC, MO(_ML),          MO(_AL),  KC_ENT, KC_RALT, _______, _______, _______
    ),
};
