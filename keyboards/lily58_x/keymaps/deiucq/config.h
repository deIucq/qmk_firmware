#pragma once

#define MASTER_LEFT

#define TAPPING_FORCE_HOLD
#define TAPPING_TERM 200

#ifdef OLED_FONT_H
#undef OLED_FONT_H
#define OLED_FONT_H "glcdfont_custom.c"
#endif
