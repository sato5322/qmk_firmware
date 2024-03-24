// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │ A │ B │ C │ D │ E │ F │ G │ H │ I │ J │ K │ L │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │ A │ B │ C │ D │ E │ F │ G │ H │ I │ J │ K │ L │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │ A │ B │ C │ D │ E │ F │ G │ H │ I │ J │ K │ L │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │ A │ B │ C │ D │ E │ F │ G │ H │ I │ J │ K │ L │
     * └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘
     */
    [0] = LAYOUT(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_MINS,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLASH,   KC_RSFT,
        KC_ESC,  KC_LALT, KC_LALT, KC_LGUI, KC_SPC,  KC_F,    KC_G,    KC_ENT,  KC_RGUI, KC_J,    KC_K,    KC_L
    )

    
};




#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] =   { ENCODER_CCW_CW(KC_P, KC_P), ENCODER_CCW_CW(KC_P, KC_P)  }
    //                  Encoder 1                                     Encoder 2
};
#endif



//for Keyboard Quantizer Utility.app

#ifdef VIA_ENABLE
#include "via.h"
void via_custom_value_command_kb(uint8_t *data, uint8_t length) {
    uint8_t command_id = data[0];
    uint8_t *command_data = &(data[1]);

    if (command_id == id_set_keyboard_value && command_data[0] == 0x99) {
        // Set default layer
        if (command_data[1] < DYNAMIC_KEYMAP_LAYER_COUNT)
        {
            default_layer_set(1 << command_data[1]);
        }
    }
    else if (command_id == id_get_keyboard_value && command_data[0] == 0x99) {
        // Return device id
        // TODO: Save and read device id from eeprom
        const uint8_t device_id = 0;
        command_data[1] = device_id;
    }
}
#endif