/* Copyright 2015-2017 Jack Humbert
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

#include "preonic.h"
#include "action_layer.h"

enum preonic_layers {
  _QWERTY,
  _COLEMAK,
  _DVORAK,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  LOWER,
  RAISE,
  BACKLIT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |  Esc |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | `    |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  | Menu |Lower | Enter|Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  {KC_ESC,                KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC},
  {KC_TAB,                KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL},
  {KC_GRV,                KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {MT(MOD_LSFT, KC_CAPS), KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, MT(MOD_RSFT, KC_ENTER) },
  {KC_LCTL,               KC_LGUI, KC_LALT, KC_APP,  LOWER,   MT(MOD_LSFT, KC_ENT),  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * |  Esc |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | `~   |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  '"  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  | Menu |Lower |Enter |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = {
  {KC_ESC,                KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC},
  {KC_TAB,                KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                  KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_DEL},
  {KC_GRV,                KC_A,    KC_R,    KC_S,    KC_T,    KC_D,                  KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT},
  {MT(MOD_LSFT, KC_CAPS), KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                  KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, MT(MOD_RSFT, KC_ENTER) },
  {KC_LCTL,               KC_LGUI, KC_LALT, KC_APP,  LOWER,   MT(MOD_LSFT, KC_ENT),  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * |  Esc |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | `    |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  | Menu |Lower |Enter |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = {
  {KC_ESC,                KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC},
  {KC_TAB,                KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,                  KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_DEL},
  {KC_GRV,                KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                  KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH},
  {MT(MOD_LSFT, KC_CAPS), KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,                  KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    MT(MOD_RSFT, KC_ENTER) },
  {KC_LCTL,               KC_LGUI, KC_LALT, KC_APP,  LOWER,   MT(MOD_LSFT, KC_ENT),  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |  Esc | pause| stop |prtscr|scroll|pause |      |   7  |   8  |   9  |   +  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  Tab |      |      |      |      |      |      |   4  |   5  |   6  |   -  | Mute |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  calc|      |      |      |      |      |      |   1  |   2  |   3  |   *  |  =   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|      |      |      |      |      |      |      |  0   |  .   |   /  | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | CTRL |  GUI | ALT  | Menu |      |      |      |      | Prev | Vol- | Vol+ | Next |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {KC_ESC,                KC_MPLY, KC_MSTP, KC_PSCR, KC_SLCK, KC_PAUS, _______, KC_7,    KC_8,    KC_9,    KC_PLUS, KC_BSPC},
  {KC_TAB,                _______, _______, _______, _______, _______, _______, KC_4,    KC_5,    KC_6,    KC_MINS, KC_MUTE},
  {KC_CALCULATOR,         _______, _______, _______, _______, _______, _______, KC_1,    KC_2,    KC_3,    KC_ASTR, KC_EQL },
  {MT(MOD_LSFT, KC_CAPS), _______, _______, _______, _______, _______, _______, _______, KC_0,    KC_DOT,  KC_SLSH, MT(MOD_RSFT, KC_ENTER)},
  {KC_LCTRL,              KC_LGUI, KC_LALT, KC_APP,  _______, _______, _______, _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |  F12 |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  |  F11 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  Tab | Ins  |      |      |      |      |      |   _  |      |      |   -  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  <   |   [  |   {  |   (  |      |      |   )  |   }  |   ]  |   >  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|      |      |      |      |      |      |      |      |      |      | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | alt  | Menu |      |      |      |      | Home | PgDn | PgUp | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {KC_F12,                 KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11},
  {KC_TAB,                 KC_INS,  _______, _______, _______, _______, _______, KC_UNDS, _______, _______, KC_MINS, KC_DEL},
  {_______,                KC_LABK, KC_LBRC, KC_LCBR, KC_LPRN, _______, _______, KC_RPRN, KC_RCBR, KC_RBRC, KC_RABK, KC_BSLS},
  {MT(MOD_LSFT, KC_CAPS),  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, MT(MOD_RSFT, KC_ENTER)},
  {KC_LCTRL,               KC_LGUI, KC_LALT, KC_APP,  _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END}
},

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|AudOff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12},
  {_______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL},
  {_______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK, DVORAK,  _______, _______},
  {_______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
}


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
          }
          return false;
          break;
        case COLEMAK:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_COLEMAK);
          }
          return false;
          break;
        case DVORAK:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_DVORAK);
          }
          return false;
          break;
        case LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case BACKLIT:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
          } else {
            unregister_code(KC_RSFT);
          }
          return false;
          break;
      }
    return true;
}