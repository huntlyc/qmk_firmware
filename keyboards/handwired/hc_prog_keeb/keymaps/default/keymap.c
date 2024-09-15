// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include <bitc_led.h>


enum custom_keycodes {
	GITSTATUS = SAFE_RANGE,
	HTOP,
};


enum layer_names {
	_BL,
	_LTWO,
	_LTHREE
};


// tap dance state type
typedef enum {
	TD_NONE,
	TD_UNKNOWN,
	TD_SINGLE_TAP,
	TD_SINGLE_HOLD,
	TD_DOUBLE_TAP
} td_state_t;

// td state def
typedef struct {
	bool is_press_action;
	td_state_t state;
} td_tap_t;

// td layer def
enum {
	CTRL_LAYR,
};

// fn defs
td_state_t cur_dance(tap_dance_state_t *state);
void ql_finished(tap_dance_state_t *state, void *user_data);
void ql_reset(tap_dance_state_t *state, void *user_data);

// returns the current state
td_state_t cur_dance(tap_dance_state_t *state){
	if(state->count == 1){
		if(!state->pressed){
			return TD_SINGLE_TAP;
		} else {
			return TD_SINGLE_HOLD;
		}
	} else if(state->count == 2){
		return TD_DOUBLE_TAP;
	}else {
		return TD_UNKNOWN;
	}
}


// init struct with defaults
static td_tap_t ql_tap_state = {
	.is_press_action = true,
	.state = TD_NONE
};


// once a tap dance is finished
void ql_finished(tap_dance_state_t *state, void *user_data){
	ql_tap_state.state = cur_dance(state);
	switch(ql_tap_state.state){
		case TD_SINGLE_TAP:
			if(layer_state_is(_LTWO)){
				layer_off(_LTWO);
			}else if(layer_state_is(_LTHREE)){
				layer_off(_LTHREE);
			}else{
				layer_on(_LTWO);
				set_bit_c_LED(LED_DIM);
			}
			break;
		case TD_SINGLE_HOLD:
			register_mods(MOD_BIT(KC_LCTL));
			break;
		case TD_DOUBLE_TAP:
			if(layer_state_is(_LTHREE)){
				layer_off(_LTHREE);
			}else if(layer_state_is(_LTWO)){
				layer_off(_LTWO);
			}else{
				layer_on(_LTHREE);
				set_bit_c_LED(LED_OFF);
			}
			break;
		default:
			break;
	}
}

// td reset
void ql_reset(tap_dance_state_t *state, void *user_data){
	switch(ql_tap_state.state){
		case TD_SINGLE_HOLD:
			unregister_mods(MOD_BIT(KC_LCTL));
			break;
		default:
			ql_tap_state.state = TD_NONE;
			break;
	}
}

// map td
tap_dance_action_t tap_dance_actions[] = {
	[CTRL_LAYR] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ql_finished, ql_reset)
};


bool process_record_user(uint16_t keycode, keyrecord_t *record){
	switch(keycode){
		case GITSTATUS:
			if(record->event.pressed){
				SEND_STRING("git status\n");
			}else{
				//released
			}
			break;
		case HTOP:
			if(record->event.pressed){
				SEND_STRING("htop\n");
			}else{
				//released
			}
			break;
	}
	return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * Keeb layout
     * ┌───┬───┬───┐
     * │ A │ B │ C │
     * └───┴───┴───┘
     */
    [_BL] = LAYOUT_ortho1x1(
        TD(CTRL_LAYR),    KC_C,    KC_V
    ),
    [_LTWO] = LAYOUT_ortho1x1(
        TD(CTRL_LAYR),    KC_X,    KC_D
    ),
    [_LTHREE] = LAYOUT_ortho1x1(
        TD(CTRL_LAYR),    GITSTATUS,    HTOP
    ),
};
