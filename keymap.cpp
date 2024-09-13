/* Copyright 2023 Brian Low
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum layers {
    _BASE,
    _FIRST
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  =   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | CTL  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |  MO  | ENTR |
 * |------+------+------+------+------+------|  Mute |    | Pause |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |  ;   |
 * `-----------------------------------------/         /   \      \-----------------------------------------'
 *            | LBRC | RBRC | LEFT |RIGHT | /BACKSAPCE/     \Space \  | DOWN |  UP  | SHIFT | QUOTE |
 *            |      |      |      |      |/         /       \      \ |      |      |       |       |
 *            `-------------------------------------'         '------''-----------------------------'
 */

[_BASE] = LAYOUT(

    KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,          KC_5,                       KC_6,     KC_7,           KC_8,    KC_9,    KC_0,    KC_MINUS,
    KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,          KC_T,                       KC_Y,     KC_U,           KC_I,    KC_O,    KC_P,    KC_EQUAL,
    KC_LCTL,  KC_A,   KC_S,    KC_D,    LSFT_T(KC_F),  KC_G,                       KC_H,     RSFT_T(KC_J),   KC_K,    KC_L,    MO(_FIRST), KC_ENTER,
    KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,      KC_MUTE,     KC_MPLY,  KC_N,     KC_M,           KC_COMM, KC_DOT,  KC_SLSH, KC_SEMICOLON,

            KC_LBRC, KC_RBRC, KC_LEFT, KC_RIGHT, KC_BACKSPACE,     KC_SPC,   KC_DOWN,  KC_UP,   KC_RIGHT_SHIFT, KC_QUOTE
),

/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  |  F10 | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |  -   |  {   |   }  |  =   |                    |  _   |  |   |  \   |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |  &   |  (   |   )  |  +   |-------.    ,-------|      |  "   |  '   |      |      |      |
 * |------+------+------+------+------+------|  Mute |    | Pause |------+------+------+------+------+------|
 * |LShift| LALT |      |  [   |   ]  |      |-------|    |-------|      |  <   |  >   |      |      |      |
 * `-----------------------------------------/         /   \      \-----------------------------------------'
 *            |      |      |      |      | /BACKSAPCE/     \Space \  | PAGE | PAGE |       |       |
 *            |      |      |      |      |/         /       \      \ | DOWN | DOWN |       |       |
 *            `-------------------------------------'         '------''-----------------------------'
 */

[_FIRST] = LAYOUT(

    KC_ESC,   KC_F2,     KC_F3,      KC_F4,     KC_F5,        KC_F6,                        KC_F7,             KC_F8,       KC_F9,      KC_F10,     KC_F11,     KC_F12,
    XXXXXXX,  XXXXXXX,   KC_MINUS,   KC_LCBR,   KC_RCBR,      KC_EQUAL,                     KC_UNDERSCORE,     KC_PIPE,     KC_BSLS,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    XXXXXXX,  XXXXXXX,   KC_AMPR,    KC_LPRN,   KC_RPRN,      KC_PLUS,                      XXXXXXX,           KC_DQUO,     KC_QUOT,    XXXXXXX,    _______,    XXXXXXX,
    KC_LSFT,  KC_LALT,   XXXXXXX,    KC_LBRC,   KC_RBRC,      XXXXXXX,  KC_MUTE,  KC_MPLY,  XXXXXXX,           KC_LABK,     KC_RABK,    XXXXXXX,    XXXXXXX,    XXXXXXX,

                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BACKSPACE,                       KC_SPC,   KC_DOWN,  KC_UP,   XXXXXXX, XXXXXXX
)

};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    [_FIRST] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
};
#endif