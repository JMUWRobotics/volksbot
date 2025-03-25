#ifndef __LOGITECHF710_CPP__
#define __LOGITECHF710_CPP__

#include "logitechf710.h"

void LogitechF::apply_event( const js_event event ) {
    switch ( event.type ) {
        case BUTTON_TYPE:
        {
            button_t btn = (button_t) event.value;
            switch ( event.number ) {
                case LOGI_BUTTON_A       : jss.buttons.A      = btn; break;
                case LOGI_BUTTON_B       : jss.buttons.B      = btn; break;
                case LOGI_BUTTON_X       : jss.buttons.X      = btn; break;
                case LOGI_BUTTON_Y       : jss.buttons.Y      = btn; break;

                case LOGI_BUTTON_LEFT    : jss.shoulder.left  = btn; break;
                case LOGI_BUTTON_RIGHT   : jss.shoulder.right = btn; break;
                
                case LOGI_BUTTON_BACK    : jss.buttons.back   = btn; break;
                case LOGI_BUTTON_START   : jss.buttons.start  = btn; break;
                case LOGI_BUTTON_LOGITECH: jss.buttons.home   = btn; break;

                case LOGI_BUTTON_LSTICK: jss.thumb_stick_left.pressed  = btn; break;
                case LOGI_BUTTON_RSTICK: jss.thumb_stick_right.pressed = btn; break;

                default: break;
            }
            break;
        }
        
        case AXIS_TYPE:
        {
            axis_t val = (axis_t) event.value;
            switch ( event.number ) {
                case LOGI_AXIS_LSTICK_LEFTRIGHT: jss.thumb_stick_left.left_right  = -val; break;
                case LOGI_AXIS_LSTICK_UPDOWN   : jss.thumb_stick_left.up_down     = -val; break;
                case LOGI_AXIS_RSTICK_LEFTRIGHT: jss.thumb_stick_right.left_right = -val; break;
                case LOGI_AXIS_RSTICK_UPDOWN   : jss.thumb_stick_right.up_down    = -val; break;
                
                case LOGI_AXIS_THROTTLE_LEFT   : jss.throttle.left  = (axis_t) map_s16_to_u16( val ); break;
                case LOGI_AXIS_THROTTLE_RIGHT  : jss.throttle.right = (axis_t) map_s16_to_u16( val ); break;
                
                case LOGI_AXIS_HUD_LEFTRIGHT:
                    jss.hud.left  = val < 0;
                    jss.hud.right = val > 0;
                    break;
                case LOGI_AXIS_HUD_UPDOWN:
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