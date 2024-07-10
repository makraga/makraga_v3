#include QMK_KEYBOARD_H

enum layer_number {
  _BASE = 0,
  _NUMP,
  _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT(
		KC_ESC , KC_1   , KC_2   , KC_3   , KC_4 , KC_5  ,
		KC_DEL , KC_Q   , KC_W   , KC_E   , KC_R , KC_T  ,
		KC_TAB , KC_A   , KC_S   , KC_D   , KC_F , KC_G  , KC_MUTE,
		KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V , KC_B  , KC_MUTE,
		KC_LCTL, KC_LALT, KC_SLSH, KC_LALT, KC_M , MO(1) , KC_SPC,
        ),

	[_NUMP] = LAYOUT(
		KC_ESC , KC_1   , KC_2   , KC_3   , KC_4 , KC_5  ,
		KC_DEL , KC_Q   , KC_W   , KC_E   , KC_R , KC_T  ,
		KC_TAB , KC_A   , KC_S   , KC_D   , KC_F , KC_G  , KC_MUTE,
		KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V , KC_B  , KC_MUTE,
		KC_LCTL, KC_LALT, KC_SLSH, KC_LALT, KC_M , MO(1) , KC_SPC,
        ),

	[_ADJUST] = LAYOUT(
		KC_ESC , KC_1   , KC_2   , KC_3   , KC_4 , KC_5  ,
		KC_DEL , KC_Q   , KC_W   , KC_E   , KC_R , KC_T  ,
		KC_TAB , KC_A   , KC_S   , KC_D   , KC_F , KC_G  , KC_MUTE,
		KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V , KC_B  , KC_MUTE,
		KC_LCTL, KC_LALT, KC_SLSH, KC_LALT, KC_M , MO(1) , KC_SPC,
        ),

};


#ifdef OLED_ENABLE

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
    }

    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_logo();  // Renders a static logo
    }
    return false;
}
#endif

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    return false;
}
    // If you return true, this will allow the keyboard level code to run, as well.
    //Returning false will override the keyboard level code. Depending on how the keyboard level function is set up.
}
