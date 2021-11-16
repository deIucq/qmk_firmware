#pragma once

#define MASTER_LEFT

#define TAPPING_FORCE_HOLD
#define TAPPING_TERM 200

#ifdef OLED_FONT_H
#undef OLED_FONT_H
#define OLED_FONT_H "glcdfont_denonbu.c"
#endif

#undef RGBLED_NUM
#define RGBLED_NUM 58
#define RGBLED_SPLIT {29, 29}
#define RGBLIGHT_MAX_LAYERS 8
#define RGBLIGHT_HUE_STEP 10
#define RGBLIGHT_SAT_STEP 17
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
