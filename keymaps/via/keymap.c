#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT(
		KC_ESC , KC_1   , KC_2   , KC_3   , KC_4 , KC_5  ,
		KC_DEL , KC_Q   , KC_W   , KC_E   , KC_R , KC_T  ,
		KC_TAB , KC_A   , KC_S   , KC_D   , KC_F , KC_G  , KC_MUTE,
		KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V , KC_B  , BL_TOGG,
		KC_LCTL, KC_LALT, KC_SLSH, KC_LALT, KC_M , MO(1) , KC_SPC
        ),

	[1] = LAYOUT(
		KC_ESC , KC_1   , KC_2   , KC_3   , KC_4 , KC_5  ,
		KC_DEL , KC_Q   , KC_W   , KC_E   , KC_R , KC_T  ,
		KC_TAB , KC_A   , KC_S   , KC_D   , KC_F , KC_G  , KC_MUTE,
		KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V , KC_B  , KC_MUTE,
		KC_LCTL, KC_LALT, KC_SLSH, KC_LALT, KC_M , KC_SPC, KC_SPC
        ),

	[2] = LAYOUT(
		KC_ESC , KC_1   , KC_2   , KC_3   , KC_4 , KC_5  ,
		KC_DEL , KC_Q   , KC_W   , KC_E   , KC_R , KC_T  ,
		KC_TAB , KC_A   , KC_S   , KC_D   , KC_F , KC_G  , KC_MUTE,
		KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V , KC_B  , KC_MUTE,
		KC_LCTL, KC_LALT, KC_SLSH, KC_LALT, KC_M , KC_SPC, KC_SPC
        ),

};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    return false;
}
