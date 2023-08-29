// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum custom_keycodes {
  LPAR,
  RPAR
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT(
        QK_GESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, LPAR, RPAR, KC_BSPC, KC_7, KC_8, KC_9, 
		KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_4, KC_5, KC_6,
		KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH ,KC_RSFT,   KC_UP,        KC_1, KC_2, KC_3, 
		KC_LCTL,KC_LALT, KC_LCMD,KC_HOME,KC_END, MO(1), KC_SPC, KC_MINS, KC_EQL, KC_BSLS,KC_LEFT, KC_DOWN, KC_RIGHT, KC_DEL, KC_0
    ),
    [1] = LAYOUT(
        QK_GESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, LPAR, RPAR, KC_BSPC, KC_7, KC_8, KC_9, 
		KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_4, KC_5, KC_6,
		KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH ,KC_RSFT,   RGB_SAI,        KC_1, KC_2, KC_3, 
		KC_LCTL,KC_LALT, KC_LCMD,KC_HOME,KC_END, KC_END, KC_SPC, KC_MINS, KC_EQL, KC_BSLS,RGB_HUI, RGB_SAD, RGB_HUD, KC_DEL, KC_0
    )

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  switch(keycode) {
  
   	case LPAR: 
	if (record->event.pressed) {
		 if (get_mods() & MOD_MASK_SHIFT) {
		  SEND_STRING("{");
		  return false;
        } else {
		  SEND_STRING("(");
		  return false;
        }
	}
	break;
	case RPAR: 
	if (record->event.pressed) {
		 if (get_mods() & MOD_MASK_SHIFT) {
		 SEND_STRING("}");
		 return false;
        } else {
		  SEND_STRING(")");
		  return false;
        }
	}
	break;

  }
  return true;

}
