#ifndef __XBOXONE_CPP__
#define __XBOXONE_CPP__

#include "xboxONE.h"

void XBoxOne::apply_event( const input_event event ) {
    switch ( event.type ) {
        case EV_TYPE_BUTTON:
        {
            button_t btn = (button_t) event.value;
            switch ( event.code ) {
                case XBOX_BUTTON_A     : jss.buttons.A      = btn; break;
                case XBOX_BUTTON_B     : jss.buttons.B      = btn; break;
                case XBOX_BUTTON_X     : jss.buttons.X      = btn; break;
                case XBOX_BUTTON_Y     : jss.buttons.Y      = btn; break;

                case XBOX_BUTTON_LEFT  : jss.shoulder.left  = btn; break;
                case XBOX_BUTTON_RIGHT : jss.shoulder.right = btn; break;
                
                case XBOX_BUTTON_MENU  : jss.buttons.back   = btn; break;
                case XBOX_BUTTON_START : jss.buttons.start  = btn; break;
                case XBOX_BUTTON_XBOX  : jss.buttons.home   = btn; break;

                case XBOX_BUTTON_LSTICK: jss.thumb_stick_left.pressed  = btn; break;
                case XBOX_BUTTON_RSTICK: jss.thumb_stick_right.pressed = btn; break;
                
                default: break;
            }
            break;
        }
        
        case EV_TYPE_AXIS:
        {
            axis_t val = (axis_t) ( event.value < AXIS_VALUE_MIN ? AXIS_VALUE_MIN : event.value );
            switch ( event.code ) {
                case XBOX_AXIS_LSTICK_LEFTRIGHT: jss.thumb_stick_left.left_right  = -val; break;
                case XBOX_AXIS_LSTICK_UPDOWN   : jss.thumb_stick_left.up_down     = -val; break;
                case XBOX_AXIS_RSTICK_LEFTRIGHT: jss.thumb_stick_right.left_right = -val; break;
                case XBOX_AXIS_RSTICK_UPDOWN   : jss.thumb_stick_right.up_down    = -val; break;
                
                case XBOX_AXIS_THROTTLE_LEFT   : jss.throttle.left  = (axis_t) ( val / (float)MAX_THROTTLE_VALUE * AXIS_VALUE_MAX ); break;
                case XBOX_AXIS_THROTTLE_RIGHT  : jss.throttle.right = (axis_t) ( val / (float)MAX_THROTTLE_VALUE * AXIS_VALUE_MAX ); break;
                
                case XBOX_AXIS_HUD_LEFTRIGHT:
                    jss.hud.left  = val < 0;
                    jss.hud.right = val > 0;
                    break;
                case XBOX_AXIS_HUD_UPDOWN:
                    jss.hud.up   = val < 0;
                    jss.hud.down = val > 0;
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