#include "lily58_x.h"
#include "analog.h"
#include <math.h>

#define JOYSTICK_X_PIN F4
#define JOYSTICK_Y_PIN F5
#define X_INVERT true
#define Y_INVERT true
#define DEADZONE 30
#define GAIN 0.05

int trackpad_origin[2] = {512, 512};

void set_trackpad_origin(void){
    trackpad_origin[0] = analogReadPin(JOYSTICK_X_PIN);
    trackpad_origin[1] = analogReadPin(JOYSTICK_Y_PIN);
}

int get_r(void){
    int xSensVal = (trackpad_origin[0] - analogReadPin(JOYSTICK_X_PIN)) * (X_INVERT ? -1 : 1);
    int ySensVal = (trackpad_origin[1] - analogReadPin(JOYSTICK_Y_PIN)) * (Y_INVERT ? -1 : 1);
    int r = sqrt(pow(xSensVal,2.0) + pow(ySensVal,2.0));
    return r;
}
int get_theta(void){
    int xSensVal = (trackpad_origin[0] - analogReadPin(JOYSTICK_X_PIN)) * (X_INVERT ? -1 : 1);
    int ySensVal = (trackpad_origin[1] - analogReadPin(JOYSTICK_Y_PIN)) * (Y_INVERT ? -1 : 1);
    int r = sqrt(pow(xSensVal,2.0) + pow(ySensVal,2.0));
    double theta;
    if (ySensVal > 0)
        theta = acos((double)xSensVal / (double)r);
    else
        theta = - acos((double)xSensVal / (double)r) + 2 * M_PI;
    return (theta / 2.0 / M_PI) * 360;
}

report_mouse_t get_trackpad_report(void){
    report_mouse_t mouseReport;
    int xSensVal = (trackpad_origin[0] - analogReadPin(JOYSTICK_X_PIN)) * (X_INVERT ? -1 : 1);
    int ySensVal = (trackpad_origin[1] - analogReadPin(JOYSTICK_Y_PIN)) * (Y_INVERT ? -1 : 1);
    int r = sqrt(pow(xSensVal,2.0) + pow(ySensVal,2.0));
    double theta;
    if (ySensVal > 0)
        theta = acos((double)xSensVal / (double)r);
    else
        theta = - acos((double)xSensVal / (double)r) + 2 * M_PI;
    if(r > DEADZONE){
        mouseReport.x = (r - DEADZONE) * cos(theta) * GAIN;
        mouseReport.y = (r - DEADZONE) * sin(theta) * GAIN;
    }else{
        mouseReport.x = 0;
        mouseReport.y = 0;
    }
    mouseReport.v = 0;
    mouseReport.h = 0;
    mouseReport.buttons = 0;
    return mouseReport;
}
