#include "lily58_x.h"
#include <math.h>

#define JOYSTICK_X_PIN 3
#define JOYSTICK_Y_PIN 6
#define X_INVERT true
#define Y_INVERT true
#define DEADZONE 30
#define GAIN 0.05

int trackpad_origin[2] = {512, 512};

void trackpad_init(void) {
    BMPAPI->gpio.set_pin(2);
    BMPAPI->adc.config_vcc_channel(JOYSTICK_X_PIN, 3300, 0);
    trackpad_origin[0] = BMPAPI->app.get_vcc_percent();
    BMPAPI->adc.config_vcc_channel(JOYSTICK_Y_PIN, 3300, 0);
    trackpad_origin[1] = BMPAPI->app.get_vcc_percent();
}

int get_r(void) {
    BMPAPI->adc.config_vcc_channel(JOYSTICK_X_PIN, 1200, 700);
    int xSensVal =
        (trackpad_origin[0] - BMPAPI->app.get_vcc_percent()) * (X_INVERT ? -1 : 1);
    BMPAPI->adc.config_vcc_channel(JOYSTICK_Y_PIN, 1200, 700);
    int ySensVal =
        (trackpad_origin[1] - BMPAPI->app.get_vcc_percent()) * (Y_INVERT ? -1 : 1);
    int r = sqrt(pow(xSensVal, 2.0) + pow(ySensVal, 2.0));
    return r;
}

int get_theta(void) {
    BMPAPI->adc.config_vcc_channel(JOYSTICK_X_PIN, 1200, 700);
    int xSensVal =
        (trackpad_origin[0] - BMPAPI->app.get_vcc_percent()) * (X_INVERT ? -1 : 1);
    BMPAPI->adc.config_vcc_channel(JOYSTICK_Y_PIN, 1200, 700);
    int ySensVal =
        (trackpad_origin[1] - BMPAPI->app.get_vcc_percent()) * (Y_INVERT ? -1 : 1);
    return atan((double)ySensVal / (double)xSensVal) + (xSensVal > 0 ? 0 : M_PI);
}

report_mouse_t get_trackpad_report(void) {
    report_mouse_t mouseReport;
    BMPAPI->adc.config_vcc_channel(JOYSTICK_X_PIN, 1200, 700);
    int xSensVal = (trackpad_origin[0] - BMPAPI->app.get_vcc_percent()) *
                   (X_INVERT ? -1 : 1);
    BMPAPI->adc.config_vcc_channel(JOYSTICK_Y_PIN, 1200, 700);
    int ySensVal = (trackpad_origin[1] - BMPAPI->app.get_vcc_percent()) *
                   (Y_INVERT ? -1 : 1);
    int    r = sqrt(pow(xSensVal, 2.0) + pow(ySensVal, 2.0));
    double theta;
    if (ySensVal > 0)
        theta = acos((double)xSensVal / (double)r);
    else
        theta = -acos((double)xSensVal / (double)r) + 2 * M_PI;
    if (r > DEADZONE) {
        mouseReport.x = (r - DEADZONE) * cos(theta) * GAIN;
        mouseReport.y = (r - DEADZONE) * sin(theta) * GAIN;
    } else {
        mouseReport.x = 0;
        mouseReport.y = 0;
    }
    mouseReport.v       = 0;
    mouseReport.h       = 0;
    mouseReport.buttons = 0;
    return mouseReport;
}