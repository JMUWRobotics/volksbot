#ifndef __XBOXONE_CPP__
#define __XBOXONE_CPP__

#include "xboxONE.h"

void XBoxOne::apply_event( const input_event event ) {
    gpe = event;

    switch ( event.type ) {
        case EV_TYPE_BUTTON:
        {
            button_t btn = (button_t) event.value;
            switch ( event.code ) {
                case XBOX_BUTTON_A     : gps.buttons.A      = btn; break;
                case XBOX_BUTTON_B     : gps.buttons.B      = btn; break;
                case XBOX_BUTTON_X     : gps.buttons.X      = btn; break;
                case XBOX_BUTTON_Y     : gps.buttons.Y      = btn; break;

                case XBOX_BUTTON_LEFT  : gps.shoulder.left  = btn; break;
                case XBOX_BUTTON_RIGHT : gps.shoulder.right = btn; break;
                
                case XBOX_BUTTON_MENU  : gps.buttons.back   = btn; break;
                case XBOX_BUTTON_START : gps.buttons.start  = btn; break;
                case XBOX_BUTTON_XBOX  : gps.buttons.home   = btn; break;

                case XBOX_BUTTON_LSTICK: gps.thumb_stick_left.pressed  = btn; break;
                case XBOX_BUTTON_RSTICK: gps.thumb_stick_right.pressed = btn; break;
                
                default: break;
            }
            break;
        }
        
        case EV_TYPE_AXIS:
        {
            axis_t val = (axis_t) ( event.value < AXIS_VALUE_MIN ? AXIS_VALUE_MIN : event.value );
            switch ( event.code ) {
                case XBOX_AXIS_LSTICK_LEFTRIGHT: gps.thumb_stick_left.left_right  = -val; break;
                case XBOX_AXIS_LSTICK_UPDOWN   : gps.thumb_stick_left.up_down     = -val; break;
                case XBOX_AXIS_RSTICK_LEFTRIGHT: gps.thumb_stick_right.left_right = -val; break;
                case XBOX_AXIS_RSTICK_UPDOWN   : gps.thumb_stick_right.up_down    = -val; break;
                
                case XBOX_AXIS_THROTTLE_LEFT   : gps.throttle.left  = (axis_t) ( val / (float)MAX_THROTTLE_VALUE * AXIS_VALUE_MAX ); break;
                case XBOX_AXIS_THROTTLE_RIGHT  : gps.throttle.right = (axis_t) ( val / (float)MAX_THROTTLE_VALUE * AXIS_VALUE_MAX ); break;
                
                case XBOX_AXIS_HUD_LEFTRIGHT:
                    gps.hud.left  = val < 0;
                    gps.hud.right = val > 0;
                    break;
                case XBOX_AXIS_HUD_UPDOWN:
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