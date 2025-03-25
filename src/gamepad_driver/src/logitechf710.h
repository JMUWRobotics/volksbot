#ifndef __LOGITECHF170_HPP__
#define __LOGITECHF170_HPP__

#include "gamepad.h"

#define LOGI_BUTTON_A        0x00
#define LOGI_BUTTON_B        0x01
#define LOGI_BUTTON_X        0x02
#define LOGI_BUTTON_Y        0x03
#define LOGI_BUTTON_LEFT     0x04
#define LOGI_BUTTON_RIGHT    0x05
#define LOGI_BUTTON_START    0x06
#define LOGI_BUTTON_LOGITECH 0x07
#define LOGI_BUTTON_BACK     0x0A
#define LOGI_BUTTON_LSTICK   0x0B
#define LOGI_BUTTON_RSTICK   0x0C

#define LOGI_AXIS_LSTICK_LEFTRIGHT  0x00
#define LOGI_AXIS_LSTICK_UPDOWN     0x01
#define LOGI_AXIS_THROTTLE_LEFT     0x02
#define LOGI_AXIS_RSTICK_LEFTRIGHT  0x03
#define LOGI_AXIS_RSTICK_UPDOWN     0x04
#define LOGI_AXIS_THROTTLE_RIGHT    0x05
#define LOGI_AXIS_HUD_LEFTRIGHT     0x06
#define LOGI_AXIS_HUD_UPDOWN        0x07

#define STICK_DEADZONE    1000

class LogitechF : public Gamepad {
    public:
        LogitechF(const char* fn) : Gamepad(fn) {};

        virtual void apply_event( const js_event event );
        virtual void receive_service() {};
};

#endif
