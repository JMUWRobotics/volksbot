/////////////////////////////////////////////////////////////////////////////
// @file    logitechf710.h
// @brief   Implementation of Gamepad interface for the logitech F710 gamepad
// @author  Nico Schubert
// @date    31.03.2025
/////////////////////////////////////////////////////////////////////////////


#ifndef __LOGITECHF170_HPP__
#define __LOGITECHF170_HPP__

#include "gamepad.h"


#define LOGI_BUTTON_A        BTN_A
#define LOGI_BUTTON_B        BTN_B
#define LOGI_BUTTON_X        BTN_X
#define LOGI_BUTTON_Y        BTN_Y
#define LOGI_BUTTON_LEFT     BTN_TL
#define LOGI_BUTTON_RIGHT    BTN_TR
#define LOGI_BUTTON_START    BTN_START
#define LOGI_BUTTON_BACK     BTN_SELECT
#define LOGI_BUTTON_LOGITECH BTN_MODE
#define LOGI_BUTTON_LSTICK   BTN_THUMBL
#define LOGI_BUTTON_RSTICK   BTN_THUMBR

#define LOGI_AXIS_LSTICK_LEFTRIGHT  ABS_X
#define LOGI_AXIS_LSTICK_UPDOWN     ABS_Y
#define LOGI_AXIS_THROTTLE_LEFT     ABS_Z
#define LOGI_AXIS_RSTICK_LEFTRIGHT  ABS_RX
#define LOGI_AXIS_RSTICK_UPDOWN     ABS_RY
#define LOGI_AXIS_THROTTLE_RIGHT    ABS_RZ
#define LOGI_AXIS_HUD_LEFTRIGHT     ABS_HAT0X
#define LOGI_AXIS_HUD_UPDOWN        ABS_HAT0Y

#define LOGI_MAX_THROTTLE_VALUE  255

class LogitechF : public Gamepad {
    public:
        const char* evio_id_name() const override { return "Logitech Gamepad F710"; }
        axis_t get_default_deadzone() const override { return 1000; }

        gp_event_t map_event( const input_event event ) override;
};

#endif
