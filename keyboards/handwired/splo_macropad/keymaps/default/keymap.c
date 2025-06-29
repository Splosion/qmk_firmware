// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "sendstring_uk.h" //uk keylayout


enum custom_keycodes {
	M_USER1 = SAFE_RANGE, //https://docs.qmk.fm/custom_quantum_functions#defining-a-new-keycode
	M_USER2,
    M_ADMIN,
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┐
     * │ 7 │ 8 │ 9 │ / │
     * ├───┼───┼───┼───┤
     * │ 4 │ 5 │ 6 │ * │
     * ├───┼───┼───┼───┤
     * │ 1 │ 2 │ 3 │ - │
     * └───┴───┴───┴───┘
     */
    [0] = LAYOUT(
        KC_F13,   KC_F14,   KC_F15,   KC_F16,
        KC_F17,   KC_F18,   KC_F19,   KC_F20,
        MO(1),   MO(2),   KC_SPC,   KC_ENT
    ),
	[1] = LAYOUT(
		M_USER1,  M_USER2,  M_ADMIN,   DM_PLY1,
        KC_F21,   KC_F22,   KC_F23,   DM_REC1,
        KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS
	),
	[2] = LAYOUT(
		KC_F21,   KC_F22,   KC_F23,   KC_F24,
        KC_F17,   KC_F18,   KC_F19,   KC_F20,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
	)
};

uint32_t anti_afk_callback(uint32_t trigger_time, void *cb_arg) {
    /* do something */
    SEND_STRING(SS_TAP(X_LCTL));
    return 120000;
}

void keyboard_post_init_user(void) {
	defer_exec(1,anti_afk_callback,NULL);
}



//https://docs.qmk.fm/feature_macros
bool process_record_user(uint16_t keycode, keyrecord_t * record) {
  switch (keycode) {
	case M_ADMIN:
	if (record->event.pressed) //keydown only
	{
	SEND_STRING(".\\administrator");
	}
	break;
	case M_USER1:
	if (record->event.pressed) //keydown only
	{
	SEND_STRING("chris.ramsdale");
	}
	break;
	case M_USER2:
	if (record->event.pressed) //keydown only
	{
	SEND_STRING("@coverwise.com");
	}
	break;
  }

  return true;
}