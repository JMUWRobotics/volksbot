/////////////////////////////////////////////////////////////////////////////
// @file    logitechf710.h
// @brief   Implementation of Gamepad interface for the logitech F710 gamepad
// @author  Nico Schubert
// @date    30.03.2025
/////////////////////////////////////////////////////////////////////////////


#ifndef __LOGITECHF710_CPP__
#define __LOGITECHF710_CPP__

#include "logitechf710.h"

void LogitechF::apply_event( const input_event event ) {
    gpe = event;

    switch ( event.type ) {
        case EV_TYPE_BUTTON:
        {
            button_t btn = (button_t) event.value;
            switch ( event.code ) {
                case LOGI_BUTTON_A       : gps.buttons.A      = btn; break;
                case LOGI_BUTTON_B       : gps.buttons.B      = btn; break;
                case LOGI_BUTTON_X       : gps.buttons.X      = btn; break;
                case LOGI_BUTTON_Y       : gps.buttons.Y      = btn; break;

                case LOGI_BUTTON_LEFT    : gps.shoulder.left  = btn; break;
                case LOGI_BUTTON_RIGHT   : gps.shoulder.right = btn; break;
                
                case LOGI_BUTTON_BACK    : gps.buttons.back   = btn; break;
                case LOGI_BUTTON_START   : gps.buttons.start  = btn; break;
                case LOGI_BUTTON_LOGITECH: gps.buttons.home   = btn; break;

                case LOGI_BUTTON_LSTICK: gps.thumb_stick_left.pressed  = btn; break;
                case LOGI_BUTTON_RSTICK: gps.thumb_stick_right.pressed = btn; break;

                default: break;
            }
            break;
        }
        
        case EV_TYPE_AXIS:
        {
            axis_t val = (axis_t) ( event.value < AXIS_VALUE_MIN ? AXIS_VALUE_MIN : event.value );
            switch ( event.code ) {
                case LOGI_AXIS_LSTICK_LEFTRIGHT: gps.thumb_stick_left.left_right  = -val; break;
                case LOGI_AXIS_LSTICK_UPDOWN   : gps.thumb_stick_left.up_down     = -val; break;
                case LOGI_AXIS_RSTICK_LEFTRIGHT: gps.thumb_stick_right.left_right = -val; break;
                case LOGI_AXIS_RSTICK_UPDOWN   : gps.thumb_stick_right.up_down    = -val; break;
                
                case LOGI_AXIS_THROTTLE_LEFT   : gps.throttle.left  = (axis_t) ( val / (float)MAX_THROTTLE_VALUE * AXIS_VALUE_MAX ); break;
                case LOGI_AXIS_THROTTLE_RIGHT  : gps.throttle.right = (axis_t) ( val / (float)MAX_THROTTLE_VALUE * AXIS_VALUE_MAX ); break;
                
                case LOGI_AXIS_HUD_LEFTRIGHT:
                    gps.hud.left  = val < 0;
                    gps.hud.right = val > 0;
                    break;
                case LOGI_AXIS_HUD_UPDOWN:
                    gps.hud.up   = val < 0;
                    gps.hud.down = val > 0;
                    break;
                        
                default:
                    break;
            }
            break;
        }
                    
        default:
            break;
    }
}

#endif