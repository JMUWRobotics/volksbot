/////////////////////////////////////////////////////////////////////////////
// @file    xboxONE.h
// @brief   Implementation of Gamepad interface for the Microsoft X-Box ONE gamepad
// @author  Nico Schubert
// @date    30.03.2025
/////////////////////////////////////////////////////////////////////////////


#ifndef __XBOXONE_CPP__
#define __XBOXONE_CPP__

#include "xboxONE.h"

#define ABS(x)  ( (x) < 0 ? -(x) : (x) )
#define DEADZONE(dz, val) ( ABS(val) <= (dz) ? 0 : (val) )  

gp_event_t XBoxOne::map_event( const input_event event ) {
    gp_ie = event;

    gp_event_t ev { false, gp_index::INVALID, {false} };
    switch ( event.type ) {
        case EV_TYPE_BUTTON:
        {
            ev.is_axis = false;
            ev.value.btn = (button_t) event.value;
            switch ( event.code ) {
                case XBOX_BUTTON_A     : ev.code = gp_index::A; break;
                case XBOX_BUTTON_B     : ev.code = gp_index::B; break;
                case XBOX_BUTTON_X     : ev.code = gp_index::X; break;
                case XBOX_BUTTON_Y     : ev.code = gp_index::Y; break;

                case XBOX_BUTTON_LEFT  : ev.code = gp_index::LB; break;
                case XBOX_BUTTON_RIGHT : ev.code = gp_index::RB; break;
                
                case XBOX_BUTTON_MENU  : ev.code = gp_index::BACK; break;
                case XBOX_BUTTON_START : ev.code = gp_index::START; break;
                case XBOX_BUTTON_XBOX  : ev.code = gp_index::HOME; break;

                case XBOX_BUTTON_LSTICK: ev.code = gp_index::THUMB_L_PRESSED; break;
                case XBOX_BUTTON_RSTICK: ev.code = gp_index::THUMB_R_PRESSED; break;

                default: break;
            }
            break;
        }
        
        case EV_TYPE_AXIS:
        {
            ev.is_axis = true;
            axis_t val = (axis_t) ( event.value < AXIS_VALUE_MIN ? AXIS_VALUE_MIN : event.value );
            switch ( event.code ) {
                case XBOX_AXIS_LSTICK_LEFTRIGHT: ev.code = gp_index::THUMB_L_LEFT_RIGHT; ev.value.axis = DEADZONE( deadzone, -val ); break;
                case XBOX_AXIS_LSTICK_UPDOWN   : ev.code = gp_index::THUMB_L_UP_DOWN   ; ev.value.axis = DEADZONE( deadzone, -val ); break;
                case XBOX_AXIS_RSTICK_LEFTRIGHT: ev.code = gp_index::THUMB_R_LEFT_RIGHT; ev.value.axis = DEADZONE( deadzone, -val ); break;
                case XBOX_AXIS_RSTICK_UPDOWN   : ev.code = gp_index::THUMB_R_UP_DOWN   ; ev.value.axis = DEADZONE( deadzone, -val ); break;
                
                case XBOX_AXIS_THROTTLE_LEFT   : ev.code = gp_index::LT; ev.value.axis = (axis_t) ( val / (float)XBOX_MAX_THROTTLE_VALUE * AXIS_VALUE_MAX ); break;
                case XBOX_AXIS_THROTTLE_RIGHT  : ev.code = gp_index::RT; ev.value.axis = (axis_t) ( val / (float)XBOX_MAX_THROTTLE_VALUE * AXIS_VALUE_MAX ); break;
                
                case XBOX_AXIS_HUD_LEFTRIGHT: ev.code = gp_index::HUD_LEFT_RIGHT; ev.value.axis = -val; break;
                case XBOX_AXIS_HUD_UPDOWN   : ev.code = gp_index::HUD_UP_DOWN   ; ev.value.axis = -val; break;
                        
                default: break;
            }
            break;
        }
                    
        default: break;
    }

    return ev;
}

#endif