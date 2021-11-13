#include QMK_KEYBOARD_H

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

enum layer_number {
    _DEFAULT = 0,
    _LOWER,
    _RAISE,
    _GAMING,
    _RGB,
};
enum custom_keycodes {
    MACRO0 = SAFE_RANGE
};
enum {
  TD_GAMING_RGB,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DEFAULT] = LAYOUT(
        KC_GESC,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,       KC_7,    KC_8,    KC_9,    KC_0,    KC_EQUAL,  \
        KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,       KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,   \
        KC_LCTRL, KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,       KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,   \
        KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,       KC_LBRC, KC_RBRC, KC_N,       KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLASH, \
                                   KC_LALT, KC_LGUI, MO(_LOWER), KC_SPC,  KC_ENT,  MO(_RAISE), KC_BSPC, TD(TD_GAMING_RGB) \
    ),
    [_LOWER] = LAYOUT(
        KC_F1,    KC_F2,  KC_F3,   KC_F4,   KC_F5,   KC_F6,                   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11, KC_F12, \
        KC_TAB,   KC_NO,  KC_BTN1, KC_MS_U, KC_BTN2, KC_NO,                   KC_NO,  KC_HOME, KC_UP,   KC_END,  KC_NO,  KC_NO,  \
        KC_LCTRL, KC_NO,  KC_MS_L, KC_MS_D, KC_MS_R, KC_NO,                   KC_NO,  KC_LEFT, KC_DOWN, KC_RGHT, KC_NO,  KC_NO,  \
        KC_LSFT,  KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_PGUP, KC_PGDN, MACRO0, KC_MPLY, KC_MPRV, KC_MNXT, KC_NO,  KC_NO,  \
                                   KC_LALT, KC_LGUI, KC_NO, KC_SPC,  KC_ENT,  KC_NO,  KC_NO,   KC_NO                             \
    ),
    [_RAISE] = LAYOUT(
        KC_F1,    KC_F2,  KC_F3,   KC_F4,   KC_F5,   KC_F6,                   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11, KC_F12, \
        KC_TAB,   KC_NO,  KC_BTN1, KC_MS_U, KC_BTN2, KC_NO,                   KC_NO,  KC_HOME, KC_UP,   KC_END,  KC_NO,  KC_NO,  \
        KC_LCTRL, KC_NO,  KC_MS_L, KC_MS_D, KC_MS_R, KC_NO,                   KC_NO,  KC_LEFT, KC_DOWN, KC_RGHT, KC_NO,  KC_NO,  \
        KC_LSFT,  KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_PGUP, KC_PGDN, MACRO0, KC_MPLY, KC_MPRV, KC_MNXT, KC_NO,  KC_NO,  \
                                   KC_LALT, KC_LGUI, KC_NO, KC_SPC,  KC_ENT,  KC_NO,  KC_NO,   KC_NO                             \
    ),
    [_GAMING] = LAYOUT(
        KC_ESC,  KC_5,     KC_1,   KC_2,    KC_3,    KC_4,                      KC_6,        KC_7,    KC_8,    KC_9,    KC_0,     KC_EQUAL,  \
        KC_6,    KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,                      KC_Y,        KC_U,    KC_I,    KC_O,    KC_P,     KC_MINS,   \
        KC_7,    KC_LSFT,  KC_A,   KC_S,    KC_D,    KC_F,                      KC_H,        KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,   \
        KC_8,    KC_LCTRL, KC_Z,   KC_X,    KC_C,    KC_V,     KC_G,   KC_PGDN, KC_N,        KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_BSLASH, \
                                   KC_T,    KC_B,    KC_LALT,  KC_SPC, KC_ENT,  TG(_GAMING), KC_BSPC, KC_NO \
    ),
    [_RGB] = LAYOUT( \
        RGB_M_P, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,               KC_NO, KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO, \
        KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,               KC_NO, KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO, \
        KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,               KC_NO, KC_NO,    RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, \
        KC_LSFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,    RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD,\
                                    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TG(_RGB), KC_NO,   KC_NO \
    ),
};

void dance_GAMING_RGB(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    layer_clear();
    layer_on(_GAMING);
    reset_tap_dance(state);
  }else{
    layer_clear();
    layer_on(_RGB);
    reset_tap_dance(state);
  }
}
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_GAMING_RGB] = ACTION_TAP_DANCE_FN(dance_GAMING_RGB),
};

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);
void set_timelog(void);
const char *read_timelog(void);
//void count_up(void);
//const char *read_countlog(void);
const char *read_rgb_info(void);

void oled_task_user(void) {
  if (is_keyboard_master()) {
    oled_write_ln(read_layer_state(), false);
    //oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    set_timelog();
    oled_write_ln(read_timelog(), false);
    //oled_write_ln(read_countlog(),false);
    oled_write_ln(read_rgb_info(),false);
    } else {
    oled_write(read_logo(), false);
  }
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    //count_up();
    #ifdef OLED_ENABLE
      set_keylog(keycode, record);
    #endif
    // set_timelog();
    switch (keycode){
    case MACRO0:
        SEND_STRING(SS_LALT("M"));
        break;
    default:
        break;
    }
  }
  return true;
}
