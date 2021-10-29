/* Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 * Copyright 2019 Sunjun Kim
 * Copyright 2020 Ploopy Corporation
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

// safe range starts at `PLOOPY_SAFE_RANGE` instead.

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT( KC_BTN1, DRAG_SCROLL, KC_BTN2, KC_BTN3, DRAG_SCROLL ),
    [1] = LAYOUT( _______, _______, _______, _______, _______ ),
    [2] = LAYOUT( _______, _______, _______, _______, _______ ),
    [3] = LAYOUT( _______, _______, _______, _______, _______ ),
    [4] = LAYOUT( _______, _______, _______, _______, _______ ),
    [5] = LAYOUT( _______, _______, _______, _______, _______ ),
    [6] = LAYOUT( _______, _______, _______, _______, _______ ),
    [7] = LAYOUT( _______, _______, _______, _______, _______ )
};
// clang-format on

// dpi toggle on drag
static uint8_t button_tracker = 0;

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    // static bool dragging = false;

    switch (keycode) {
        case KC_BTN1: {
            if (record->event.pressed) {
                button_tracker++;
            } else {
                button_tracker--;
            }
        }
        case KC_BTN2: {
            if (record->event.pressed) {
                button_tracker++;
            } else {
                button_tracker--;
            }
        }
        case KC_BTN3: {
            if (record->event.pressed) {
                button_tracker++;
            } else {
                button_tracker--;
            }
        } break;
    }

    if (button_tracker > 0) {
        pmw_set_cpi(dpi_array[0]);
    } else {
        // pmw_set_cpi(dpi_array[keyboard_config.dpi_config]);
        pmw_set_cpi(dpi_array[1]);
    }
    return true;
}

// do nothing with wheel
void process_wheel_user(report_mouse_t* mouse_report, int16_t h, int16_t v) {}
