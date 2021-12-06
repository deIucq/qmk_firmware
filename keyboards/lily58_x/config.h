/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#pragma once

/* USB Device descriptor parameter */
#define VENDOR_ID       0x04D8
#define PRODUCT_ID      0xEB2D
#define DEVICE_VER      0x0100
#define MANUFACTURER    liliums
#define PRODUCT         Lily58

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 10
#define MATRIX_COLS 6

// wiring of each half
#define MATRIX_ROW_PINS { C6, D7, E6, B4, B5 }
#define MATRIX_COL_PINS { F6, F7, B1, B3, B2, B6 }

#define SOFT_SERIAL_PIN D2
#define SERIAL_USE_MULTI_TRANSACTION

/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
//#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
//#define LOCKING_RESYNC_ENABLE

/* LED */
#define RGB_DI_PIN D3
#define RGBLED_NUM 58
#define RGBLED_SPLIT {29, 29}
#define RGBLIGHT_MAX_LAYERS 8
#define RGBLIGHT_HUE_STEP 10
#define RGBLIGHT_SAT_STEP 10
#define RGBLIGHT_VAL_STEP 20
#define RGBLIGHT_LIMIT_VAL 120
//#define RGBLIGHT_ANIMATIONS
//#define RGBLIGHT_SLEEP
#define RGBLIGHT_LAYERS
#define RGBLIGHT_MAX_LAYERS 8
#define LED_LAYOUT( \
	L00, L01, L02, L03, L04, L05,           R00, R01, R02, R03, R04, R05,  \
	L10, L11, L12, L13, L14, L15,           R10, R11, R12, R13, R14, R15,  \
	L20, L21, L22, L23, L24, L25,           R20, R21, R22, R23, R24, R25,  \
	L30, L31, L32, L33, L34, L35, L45, R40, R30, R31, R32, R33, R34, R35, \
	               L41, L42, L43, L44, R41, R42, R43, R44  \
) { \
    L05, L04, L03, L02, L01, L00, \
    L10, L11, L12, L13, L14, L15, \
    L25, L24, L23, L22, L21, L20, \
    L30, L31, L32, L33, L34, L35, \
    L45, L44, L43, L42, L41, \
    R00, R01, R02, R03, R04, R05, \
    R15, R14, R13, R12, R11, R10, \
    R20, R21, R22, R23, R24, R25, \
    R35, R34, R33, R32, R31, R30, \
    R40, R41, R42, R43, R44 \
}
#define RGBLIGHT_LED_MAP LED_LAYOUT( \
   0,  1,  2,  3,  4,  5,         34, 33, 32, 31, 30, 29, \
   6,  7,  8,  9, 10, 11,         40, 39, 38, 37, 36, 35, \
  12, 13, 14, 15, 16, 17,         46, 45, 44, 43, 42, 41, \
  18, 19, 20, 21, 22, 23, 24, 53, 52, 51, 50, 49, 48, 47, \
              25, 26, 27, 28, 57, 56, 55, 54)

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
// #define NO_DEBUG

/* disable print */
// #define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
//#define NO_ACTION_MACRO
//#define NO_ACTION_FUNCTION

#include "config_common.h"

#ifndef SOFT_SERIAL_PIN
#define SOFT_SERIAL_PIN D2
#define SERIAL_USE_MULTI_TRANSACTION
#endif

#if !defined(NO_ACTION_MACRO)
    #define NO_ACTION_MACRO
#endif
#if !defined(NO_ACTION_FUNCTION)
    #define NO_ACTION_FUNCTION
#endif

#define DIODE_DIRECTION COL2ROW

// Use the lily version to get the Lily58 logo instead of the qmk logo
#define OLED_FONT_H "lib/glcdfont_lily.c"
