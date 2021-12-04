/*
Copyright 2019 sekigon-gonnoc

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

#ifndef __ASSEMBLER__
#include "config_common.h"
#include "apidef.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x0000
#define PRODUCT_ID      0x0000
#define DEVICE_VER      0x0001
#define MANUFACTURER    duiucq
#define PRODUCT         lily58-x

// BMP
#define BMP_BOOTPIN_AS_RESET
/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
#define LOCKING_RESYNC_ENABLE

// Key matrix
#define MATRIX_ROWS_DEFAULT 10
#define MATRIX_COLS_DEFAULT 6
#define THIS_DEVICE_ROWS 5
#define THIS_DEVICE_COLS 6
#define MATRIX_ROW_PINS {  8,  9, 10, 11, 12 }
#define MATRIX_COL_PINS { 18, 17, 16, 15, 14, 13 }
#define MATRIX_LAYOUT {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27}
#define DIODE_DIRECTION COL2ROW

// RGBLED
#define RGBLIGHT_SPLIT
#define G00 255 // Dummy for bin/qmk config generation
#define RGB_DI_PIN G00
#ifdef RGB_DI_PIN
  #define RGBLED_NUM_DEFAULT 58
  #define RGBLIGHT_HUE_STEP 8
  #define RGBLIGHT_SAT_STEP 8
  #define RGBLIGHT_VAL_STEP 8
  #define RGBLIGHT_LIMIT_VAL 255 /* The maximum brightness level */
  #define RGBLIGHT_SLEEP  /* If defined, the RGB lighting will be switched off when the host goes to sleep */
/*== all animations enable ==*/
  #define RGBLIGHT_ANIMATIONS
/*== or choose animations ==*/
  #define RGBLIGHT_EFFECT_BREATHING
  #define RGBLIGHT_EFFECT_RAINBOW_MOOD
  #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
  #define RGBLIGHT_EFFECT_SNAKE
  #define RGBLIGHT_EFFECT_KNIGHT
  #define RGBLIGHT_EFFECT_CHRISTMAS
  #define RGBLIGHT_EFFECT_STATIC_GRADIENT
  #define RGBLIGHT_EFFECT_RGB_TEST
  #define RGBLIGHT_EFFECT_ALTERNATING
/*== customize breathing effect ==*/
  /*==== (DEFAULT) use fixed table instead of exp() and sin() ====*/
  #define RGBLIGHT_BREATHE_TABLE_SIZE 256      // 256(default) or 128 or 64
  /*==== use exp() and sin() ====*/
  #define RGBLIGHT_EFFECT_BREATHE_CENTER 1.85  // 1 to 2.7
  #define RGBLIGHT_EFFECT_BREATHE_MAX    255   // 0 to 255
#endif

// MISC
#define SOFT_SERIAL_PIN D2
#define SERIAL_USE_MULTI_TRANSACTION

#define TAPPING_TERM_PER_KEY
#define PERMISSIVE_HOLD
#define PREVENT_STUCK_MODIFIERS
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_TERM 200

#define KEYMAP_PRIOR_LOCALE 0
#define KEYMAP_ASCII 0

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

#define DEBUG_ACTION

/*
 * Enable mass storage when the switch connected following pins is pushed on boot.
 * No warranty
*/
// #define ALLOW_MSC_ROW_PIN 7
// #define ALLOW_MSC_COL_PIN 20

#endif /*__ASSEMBLER__*/
