#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _BETA 3
#define _GAMMA 4

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)
#define BETA MO(_BETA)
#define GAMMA MO(_GAMMA)


enum custom_keycodes {
	M_USER1 = SAFE_RANGE, //https://docs.qmk.fm/custom_quantum_functions#defining-a-new-keycode
	M_USER2,
    M_ADMIN,
	M_PIN,
	M_BIT,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_5x6(
        KC_ESC , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                         KC_6  , KC_7  , KC_8  , KC_9  , KC_0  , KC_BSPC,
        KC_TAB , KC_Q,   KC_W,   KC_F,   KC_P,   KC_B ,                          KC_J,   KC_L,   KC_U,   KC_Y,   KC_SCLN, KC_EQUAL,
        KC_LSFT, KC_A,   KC_R,   KC_S,   KC_T,   KC_G  ,                         KC_M,    KC_N,     KC_E,       KC_I,    KC_O,    KC_QUOT,
        KC_LCTL, KC_Z,   KC_X,   KC_C,   KC_D,   KC_V  ,                         KC_NUBS, KC_K,     KC_H,       KC_COMM, KC_DOT,  KC_SLSH,
                         KC_LBRC,KC_RBRC,                                                       KC_MINS, KC_NUHS,
                                         RAISE,KC_SPC,                        KC_ENT, GAMMA,
                                         KC_TAB,KC_HOME,                         KC_END,  KC_DEL,
                                         LOWER, KC_GRV,                        KC_LGUI, BETA
    ),
    [_LOWER] = LAYOUT_5x6(
        KC_TILD,KC_EXLM, KC_AT ,KC_HASH,KC_DLR ,KC_PERC,                        KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_DEL,
        _______, KC_F13,  KC_F14, KC_F15, KC_F16, KC_MUTE,                        KC_RBRC, KC_P7 , KC_P8 , KC_P9 ,_______,KC_PLUS,
        KC_GRV,  KC_F17,  KC_F18, KC_F19, KC_F20, KC_VOLU,                        KC_RPRN, KC_P4 , KC_P5 , KC_P6 ,KC_MINS,KC_PIPE,
        _______, KC_F21,  KC_F22, KC_F23, KC_F24, KC_VOLD,                        _______, KC_P1 , KC_P2 , KC_P3 ,KC_EQL ,KC_UNDS,
                                                _______,_______,            _______, _______,
                                                _______,_______,            _______,_______,
                                                _______,_______,            _______,_______,
                                                _______,G(KC_L),            _______,_______

    ),
    [_RAISE] = LAYOUT_5x6(
        KC_F12 ,   KC_F1 ,    KC_F2 ,    KC_F3 ,  KC_F4 ,  KC_F5 ,                         KC_F6 , KC_F7 , KC_F8 , KC_F9 , KC_F10 ,KC_F11 ,
        DM_PLY1,   DM_REC1,   KC_MPRV,   KC_UP,   KC_MNXT, KC_MPLY,                        KC_RBRC,_______,KC_NUM, KC_INS ,KC_SCRL,KC_MUTE,
        KC_GRV,    LSA(KC_F), KC_LEFT,   KC_DOWN, KC_RGHT, KC_VOLU,                        KC_RPRN,KC_MPRV,KC_MPLY,KC_MNXT,_______,KC_VOLU,
        LSA(KC_R), LSA(KC_S), LSA(KC_T), _______, _______, KC_VOLD,                        _______,_______,_______,_______,_______,KC_VOLD,
                                                  _______,_______,            _______ ,_______,
                                                  _______,_______,            _______,_______,
                                                  _______,_______,            _______,_______,
                                                  _______,_______,            _______,_______
    ),
	[_BETA] = LAYOUT_5x6(
        KC_TILD, KC_EXLM, KC_AT , KC_HASH,KC_DLR ,KC_PERC,                        KC_CIRC, KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_DEL,
        _______, KC_F13,  KC_F14, KC_F15, KC_F16, KC_MUTE,                        KC_RBRC, KC_P7 , KC_P8 , KC_P9 , _______,KC_PLUS,
        KC_GRV,  KC_F17,  KC_F18, KC_F19, KC_F20, KC_VOLU,                        KC_RPRN, KC_P4 , KC_P5 , KC_P6 , KC_MINS,KC_PIPE,
        _______, KC_F21,  KC_F22, KC_F23, KC_F24, KC_VOLD,                        _______, KC_P1 , KC_P2 , KC_P3 , KC_EQL ,KC_UNDS,
                                                _______,_______,            _______, _______,
                                                _______,_______,            _______,_______,
                                                _______,_______,            _______,_______,
                                                _______,_______,            _______,_______

    ),

    [_GAMMA] = LAYOUT_5x6(
        KC_F12 , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,                        KC_F6  , KC_F7 ,    KC_F8 ,    KC_F9 ,    KC_F10 , KC_F11 ,
        _______,_______,_______,_______,_______,KC_LBRC,                        XXXXXXX, LSA(KC_U), LSA(KC_F), _______,   A(KC_X), A(KC_EQUAL),
        _______,KC_LEFT,KC_UP  ,KC_DOWN,KC_RGHT,KC_LPRN,                        XXXXXXX, LSA(KC_R), LSA(KC_S), LSA(KC_T), A(KC_Y), A(KC_QUOT),
        _______,_______,_______,_______,_______,_______,                        KC_MINS, _______,   _______,   _______,   XXXXXXX, KC_NUHS,
                                                  _______,_______,            _______ ,_______,
                                                  _______,_______,            _______,_______,
                                                  _______,_______,            _______,_______,
                                                  _______,_______,            _______,_______
    )
};


//I have the below code in other devices so it doesn't need to exist here

// uint32_t rand_return(void) {
	// uint32_t upper_bound = 150000; //2min 30sec
	// uint32_t lower_bound = 90000; //1min 30sec
	// uint32_t value = rand() % (upper_bound - lower_bound + 1)
                    // + lower_bound;
	// return value;
	
// }

// uint32_t anti_afk_callback(uint32_t trigger_time, void *cb_arg) {
    // /* do something */
	// SEND_STRING(SS_TAP(X_LCTL));
	
    // return rand_return();
// }

// void keyboard_post_init_user(void) {
	// defer_exec(1,anti_afk_callback,NULL);
// }


//https://docs.qmk.fm/feature_macros
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
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
	case M_PIN:
	if(record->event.pressed) //keydown only
	{
		SEND_STRING("91298");
	}
	break;
	case M_BIT:
	if(record->event.pressed) //keydown only
	{
		SEND_STRING("892191");
	}
	break;
  }
  return true;
}