#pragma once

#define MASTER_LEFT

#define TAPPING_FORCE_HOLD
#define TAPPING_TERM 200

#undef RGBLED_NUM
#define RGBLED_NUM 56
#define RGBLED_SPLIT {28, 28}
#define RGBLIGHT_SPLIT
#define RGBLIGHT_HUE_STEP 10
#define RGBLIGHT_SAT_STEP 17
#define RGBLIGHT_VAL_STEP 17
#define RGBLIGHT_LIMIT_VAL 120
//#define RGBLIGHT_ANIMATIONS

//#define RGBLIGHT_SLEEP

#ifdef OLED_FONT_H
#undef OLED_FONT_H
#define OLED_FONT_H "glcdfont_denonbu.c"
#endif
