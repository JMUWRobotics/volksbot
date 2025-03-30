#ifndef __XBOXONE_HPP__
#define __XBOXONE_HPP__

#include "gamepad.h"


#define XBOX_BUTTON_A        BTN_A
#define XBOX_BUTTON_B        BTN_B
#define XBOX_BUTTON_X        BTN_X
#define XBOX_BUTTON_Y        BTN_Y
#define XBOX_BUTTON_LEFT     BTN_TL
#define XBOX_BUTTON_RIGHT    BTN_TR
#define XBOX_BUTTON_START    BTN_SELECT
#define XBOX_BUTTON_MENU     BTN_START
#define XBOX_BUTTON_XBOX     BTN_MODE
#define XBOX_BUTTON_LSTICK   BTN_THUMBL
#define XBOX_BUTTON_RSTICK   BTN_THUMBR

#define XBOX_AXIS_LSTICK_LEFTRIGHT  ABS_X
#define XBOX_AXIS_LSTICK_UPDOWN     ABS_Y
#define XBOX_AXIS_THROTTLE_LEFT     ABS_Z
#define XBOX_AXIS_RSTICK_LEFTRIGHT  ABS_RX
#define XBOX_AXIS_RSTICK_UPDOWN     ABS_RY
#define XBOX_AXIS_THROTTLE_RIGHT    ABS_RZ
#define XBOX_AXIS_HUD_LEFTRIGHT     ABS_HAT0X
#define XBOX_AXIS_HUD_UPDOWN        ABS_HAT0Y

#define MAX_THROTTLE_VALUE  1023

class XBoxOne : public Gamepad {
    public:
        const char* evio_id_name() override { return "Microsoft X-Box One"; }

        void apply_event( const input_event event ) override;
};

#endif
