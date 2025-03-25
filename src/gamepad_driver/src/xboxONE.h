#ifndef __XBOXONE_HPP__
#define __XBOXONE_HPP__

#include "gamepad.h"


#define XBOX_BUTTON_A        0x00
#define XBOX_BUTTON_B        0x01
#define XBOX_BUTTON_X        0x02
#define XBOX_BUTTON_Y        0x03
#define XBOX_BUTTON_LEFT     0x04
#define XBOX_BUTTON_RIGHT    0x05
#define XBOX_BUTTON_START    0x06
#define XBOX_BUTTON_MENU     0x07
#define XBOX_BUTTON_XBOX     0x08
#define XBOX_BUTTON_LSTICK   0x09
#define XBOX_BUTTON_RSTICK   0x0A

#define XBOX_AXIS_LSTICK_LEFTRIGHT  0x00
#define XBOX_AXIS_LSTICK_UPDOWN     0x01
#define XBOX_AXIS_THROTTLE_LEFT     0x02
#define XBOX_AXIS_RSTICK_LEFTRIGHT  0x03
#define XBOX_AXIS_RSTICK_UPDOWN     0x04
#define XBOX_AXIS_THROTTLE_RIGHT    0x05
#define XBOX_AXIS_HUD_LEFTRIGHT     0x06
#define XBOX_AXIS_HUD_UPDOWN        0x07

#define STICK_DEADZONE    1000

class XBoxOne : public Gamepad {
    public:
        XBoxOne(const char* fn) : Gamepad(fn) {};

        virtual void apply_event( const js_event event );
        virtual void receive_service() {};
};

#endif
