/////////////////////////////////////////////////////////////////////////////
// @file    gamepad.cpp
// @brief   implementation of gamepad and joystick event in- and outputs
// @author  Nico Schubert
// @date    10.11.2025
/////////////////////////////////////////////////////////////////////////////


#ifndef __GAMEPAD_CPP__
#define __GAMEPAD_CPP__

#include "gamepad.h"
#include "device_utils.h"

#include <linux/input.h>
#include <dirent.h>

#include <sys/ioctl.h>
#include <sys/stat.h>
#include <string.h>
#include <time.h>
#include <pthread.h>

// Use of mutex has not been evaluated as noticeable and necessary
// #define USE_MUTEX

#ifdef USE_MUTEX
    #define   LOCK(mux) pthread_mutex_lock(mux)
    #define UNLOCK(mux) pthread_mutex_unlock(mux)
#else
    #define   LOCK(mux)
    #define UNLOCK(mux)
#endif


//-----------------------------------------------------------------------------
// Gamepad Implementation
//-----------------------------------------------------------------------------

Gamepad::Gamepad() : id(0), gp_ie(), gp_s(), gp_e(), fd_rw(-1) {}

Gamepad::~Gamepad() {
    disconnect();
}


void* rumble_function(void* arg) {
    Gamepad* gp = (Gamepad*) arg;

    while( true ) {
        if( gp->effect.u.rumble.strong_magnitude > 0 ||
            gp->effect.u.rumble.weak_magnitude   > 0    
        ) {
            LOCK( &gp->mux_rumble );
            gp->handle_rumble();
            UNLOCK( &gp->mux_rumble );
        }

        usleep( 1000 * MAX_UPDATE_RATE_FF_MS );
    }
}

void Gamepad::connect( const char* filename ) {
    if( fd_rw != -1 ) {
        LOG_LN_WARN( COL(FG_BRIGHT_YELLOW, "Gamepad is already connected!") );
        return;
    }

    fd_rw = open( filename, O_RDWR | O_NONBLOCK );
    
    if( fd_rw < 0 ) {
        fd_rw = -1;
        LOG_LN_ERROR( COL(FG_BRIGHT_RED, "Gamepad %s not found!"), filename);
        return;
    }

    // setup name and serial number of device
    device_serial_number = "";
    device_util::get_usb_serial_of_input_event( filename, device_serial_number );
    
    char buff[512];
    ioctl( fd_rw, EVIOCGNAME(sizeof(buff)), buff );
    name = std::string( buff );
    
    deadzone = get_default_deadzone();

    // setup force feedback - rumble
    effect.id = -1;
    effect.type = FF_RUMBLE;

    effect.replay.length = MAX_UPDATE_RATE_FF_MS;
    effect.replay.delay = 0;

    if( has_rumble() ) {
        int ret = pthread_create( &thread_rumble, NULL, &rumble_function, this );
    
        if( ret ) {
            LOG_LN_WARN( COL(FG_BRIGHT_YELLOW, "Failed to initiate backend rumble thread! Rumbling of the gamepad will now not work!" ) );
            LOG_LN_WARN( COL(FG_BRIGHT_YELLOW, "Try to restart the Application if rumbling of the gamepad is required." ) );
        } else {
            pthread_detach( thread_rumble );
        }
    }
}

void Gamepad::disconnect() {
    if( fd_rw == -1 ) {
        LOG_LN_WARN( COL(FG_BRIGHT_YELLOW, "Gamepad is already disconnected!") );
        return;
    }

    input_event stop;

    /* Stop the effect */
    stop.type = EV_FF;
    stop.code = effect.id;
    stop.value = 0;

    if( write( fd_rw, &stop, sizeof(stop) ) != sizeof(stop) ) {
        LOG_LN_DEBUG( COL(FG_YELLOW, "could not write stop rumble effect to gamepad") );
    }

    close( fd_rw );
    fd_rw = -1;
}

bool Gamepad::has_connection() const {
    if( fd_rw == -1 ) {
        return false;
    }
    
    struct stat s;

    fstat(fd_rw, &s);
    if( s.st_nlink < 1 ){
        return false;
    }
    
    return true;
}


void Gamepad::apply_event( const gp_event_t event ) {
    gp_e = event;

    uint8_t* byte_ptr = (uint8_t*) &gp_s;
    
    byte_ptr[ event.code ] = event.value.btn;

    if( event.is_axis ) {
        byte_ptr[ event.code+1 ] = (uint8_t)( (uint16_t)event.value.axis >> 8 );
    }
}


void Gamepad::wait_for_event() {
    input_event js;

    if( read(fd_rw, &js, sizeof(input_event) ) == sizeof(input_event) ) {   
        // EV_SYN: Event separator -> Ignore
        if( js.type == EV_SYN )
            return;
        
        id++;
        apply_event( map_event( js ) );
    }
}


void Gamepad::set_rumble( const uint16_t mag_strong, const uint16_t mag_weak ) {
    LOCK( &mux_rumble );
    effect.u.rumble.strong_magnitude = mag_strong;
    effect.u.rumble.weak_magnitude   = mag_weak;
    UNLOCK( &mux_rumble );
}

bool Gamepad::has_rumble() const {
    uint64_t evtype_b = 0;
    ioctl(fd_rw, EVIOCGBIT(0, EV_MAX), &evtype_b);

    return bool(evtype_b & (1 << EV_FF));
}


void Gamepad::handle_rumble() {
    input_event ie;
    ie.type = EV_FF;
    ie.code = effect.id;
    
    /* not required since rumble_function will only callback this handler when the previous effect is over */
    /* Stop the effect */
    // ie.value = 0;
    // write( fd_rw, &ie, sizeof(ie) );

    /* Setting the effect */
    ioctl( fd_rw, EVIOCSFF, &effect );

    /* Play the effect */
    ie.value = 1;
    if( write( fd_rw, &ie, sizeof(ie) ) != sizeof(ie) ) {
        LOG_LN_DEBUG( COL(FG_YELLOW, "could not write rumble successfully to gamepad") );
    }
}


static constexpr char gp_index_LUT[][20] = {
    // buttons
    "A", "B", "X", "Y", "BACK", "START", "HOME",
    
    // shoulder
    "LB", "RB", "",
    
    // throttle
    "LT", "", "RT", "",

    // hud
    "HUD_LEFT_RIGHT", "", "HUD_UP_DOWN", "",

    // thumb sticks
    "THUMB_L_LEFT_RIGHT", "", "THUMB_L_UP_DOWN", "", "THUMB_L_PRESSED", "",
    "THUMB_R_LEFT_RIGHT", "", "THUMB_R_UP_DOWN", "", "THUMB_R_PRESSED", ""
};
void Gamepad::print_event() const {
    static uint32_t last_id = id+1;

    if( last_id == id ) {
        return;
    }

    last_id = id;

    LOG_LN_DEBUG( "INPUT EVENT --------------------------" );
    LOG_LN_DEBUG( "ID: " COL(FG_BRIGHT_BLUE, "%d"), id );
    LOG_LN_DEBUG( "time : ");
    LOG_LN_DEBUG( "  sec: " COL(FG_BRIGHT_BLUE, "%8ld"), gp_ie.time.tv_sec   );
    LOG_LN_DEBUG( " µsec: " COL(FG_BRIGHT_BLUE, "%8ld"), gp_ie.time.tv_usec  );
    LOG_LN_DEBUG( "type : " COL(FG_BRIGHT_BLUE, "%6x" ), gp_ie.type   );
    LOG_LN_DEBUG( "code : " COL(FG_BRIGHT_BLUE, "%6x" ), gp_ie.code   );
    LOG_LN_DEBUG( "value: " COL(FG_BRIGHT_BLUE, "%6d" ), gp_ie.value  );
    LOG_ANSI( "\n" );
    LOG_LN_DEBUG( "GAMEPAD EVENT ------------------------" );
    LOG_LN_DEBUG( "       is_axis: " COL(FG_BRIGHT_BLUE, "%5s"), gp_e.is_axis ? "true" : "false" );
    LOG_LN_DEBUG( "       code-id: " COL(FG_BRIGHT_BLUE, "%2d"), gp_e.code );
    LOG_LN_DEBUG( "          code: " COL(FG_BRIGHT_BLUE, "%-20s"), gp_e.code==gp_index::INVALID ? "INVALID" : gp_index_LUT[ gp_e.code ] );
    LOG_LN_DEBUG( "value (axis)  : " COL(FG_BRIGHT_BLUE, "%6d"), gp_e.value.axis );
    LOG_LN_DEBUG( "value (button): " COL(FG_BRIGHT_BLUE, "%5s"), gp_e.value.btn ? "true" : "false" );

    LOG_ANSI( SCO );
    LOG_ANSI( CPL(15) );
}

#define STR_BOOL(s, v) ( (v) ? COL(BG_GREEN, " " s " ") : COL(BG_RED,  " " s " ") )
#define PERCENT(x) ( (int16_t)( 100.0 * (x) / (float)(AXIS_VALUE_MAX) ) )
void Gamepad::print_state() const {
    static uint32_t last_id = id+1;

    if( last_id == id ) {
        return;
    }
    
    last_id = id;
    
    LOG_LN_DEBUG( "ID: " COL(FG_BRIGHT_BLUE, "%d"), id );
    LOG_LN_DEBUG( "Buttons: %s %s %s %s  %s %s %s  %s %s", 
        STR_BOOL( "A", gp_s.buttons.A ),
        STR_BOOL( "B", gp_s.buttons.B ),
        STR_BOOL( "X", gp_s.buttons.X ),
        STR_BOOL( "Y", gp_s.buttons.Y ),

        STR_BOOL( "start", gp_s.buttons.start ),
        STR_BOOL( "back" , gp_s.buttons.back  ),
        STR_BOOL( "home" , gp_s.buttons.home  ),

        STR_BOOL( "LB", gp_s.shoulder.left ),
        STR_BOOL( "RB", gp_s.shoulder.right )
    );
    LOG_LN_DEBUG( "HUD:" );
    LOG_LN_DEBUG( "LEFT_RIGHT: %s", gp_s.hud.left_right == 0 ? COL(BG_GRAY, "      ") : ( gp_s.hud.left_right > 0 ? COL(BG_GREEN, " LEFT ") : COL(BG_GREEN, " RIGHT ") ) );
    LOG_LN_DEBUG( "UP_DOWN:    %s", gp_s.hud.up_down    == 0 ? COL(BG_GRAY, "      ") : ( gp_s.hud.up_down    > 0 ? COL(BG_GREEN, "  UP  ") : COL(BG_GREEN, " DOWN ")  ) );
    
    LOG_ANSI( "\n" );
    LOG_LN_DEBUG( "LT: " COL(FG_BRIGHT_BLUE, "%6d") " (" COL(FG_BRIGHT_BLUE, "%3d") "%%)", gp_s.throttle.left , PERCENT(gp_s.throttle.left) );
    LOG_LN_DEBUG( "RT: " COL(FG_BRIGHT_BLUE, "%6d") " (" COL(FG_BRIGHT_BLUE, "%3d") "%%)", gp_s.throttle.right, PERCENT(gp_s.throttle.right) );
    LOG_ANSI( "\n" );
    
    LOG_LN_DEBUG( "L Stick (left, up): %s " COL(FG_BRIGHT_BLUE, "%6d") ", " COL(FG_BRIGHT_BLUE, "%6d") " ( " COL(FG_BRIGHT_BLUE, "%4d") "%%, " COL(FG_BRIGHT_BLUE, "%4d") "%%)",
        STR_BOOL("btn", gp_s.thumb_stick_left.pressed ),
        gp_s.thumb_stick_left.left_right ,
        gp_s.thumb_stick_left.up_down ,
        PERCENT(gp_s.thumb_stick_left.left_right) ,
        PERCENT(gp_s.thumb_stick_left.up_down) 
    );
    LOG_LN_DEBUG( "R Stick (left, up): %s " COL(FG_BRIGHT_BLUE, "%6d") ", " COL(FG_BRIGHT_BLUE, "%6d") " ( " COL(FG_BRIGHT_BLUE, "%4d") "%%, " COL(FG_BRIGHT_BLUE, "%4d") "%%)",
        STR_BOOL("btn", gp_s.thumb_stick_right.pressed),
        gp_s.thumb_stick_right.left_right,
        gp_s.thumb_stick_right.up_down,
        PERCENT(gp_s.thumb_stick_right.left_right),
        PERCENT(gp_s.thumb_stick_right.up_down)
    );

    LOG_ANSI( "\n" );
    LOG_LN_DEBUG( "Rumble: strong: " COL(FG_BRIGHT_BLUE, "%6d") " (" COL(FG_BRIGHT_BLUE, "%3d") "%%), weak: " COL(FG_BRIGHT_BLUE, "%6d") " (" COL(FG_BRIGHT_BLUE, "%3d") "%%)",
        effect.u.rumble.strong_magnitude, PERCENT(0.5*effect.u.rumble.strong_magnitude), 
        effect.u.rumble.weak_magnitude, PERCENT(0.5*effect.u.rumble.weak_magnitude)
    );

    LOG_ANSI( SCO );
    LOG_ANSI( CPL(13) );
}
void Gamepad::print_evio() const {
    if( !has_connection() ) {
        LOG_LN_WARN( COL(FG_BRIGHT_RED, "can not print evio data without a connected gamepad") );
        return;
    }

    LOG_ANSI( "\n" );
    LOG_LN_DEBUG( COL(BOLD, "Serial Number: ") COL(BOLD;FG_BRIGHT_BLUE, "%s"), device_serial_number.c_str() );

    char buff[512];
    ioctl( fd_rw, EVIOCGNAME(sizeof(buff)), buff );
    LOG_LN_DEBUG( "Device Name: " COL(BOLD;FG_BRIGHT_BLUE, "%s"), buff );

    ioctl( fd_rw, EVIOCGPHYS(sizeof(buff)), buff );
    LOG_LN_DEBUG( "Physical Path: " COL(FG_BRIGHT_BLUE, "%s"), buff );

    ioctl( fd_rw, EVIOCGUNIQ(sizeof(buff)), buff );
    LOG_LN_DEBUG( "Unique ID: " COL(FG_BRIGHT_BLUE, "%s"), buff );

    ioctl( fd_rw, EVIOCGPROP(sizeof(buff)), buff );
    LOG_LN_DEBUG( "Device Properties: " COL(FG_BRIGHT_BLUE, "%s"), buff );

    input_id id;
    ioctl( fd_rw, EVIOCGID, &id );
    LOG_ANSI( "\n" );
    LOG_LN_DEBUG("ID:");
    LOG_LN_DEBUG("bustype: " COL(FG_BRIGHT_BLUE, "0x%4x"), id.bustype);
    LOG_LN_DEBUG("vendor : " COL(FG_BRIGHT_BLUE, "0x%4x"), id.vendor );
    LOG_LN_DEBUG("product: " COL(FG_BRIGHT_BLUE, "0x%4x"), id.product);
    LOG_LN_DEBUG("version: " COL(FG_BRIGHT_BLUE, "0x%4x"), id.version);


    uint64_t evtype_b = 0;
    ioctl(fd_rw, EVIOCGBIT(0, EV_MAX), &evtype_b);  
    LOG_ANSI( "\n" );
    LOG_LN_DEBUG("Supported event types:");
    for ( int yalv = 0; yalv < EV_MAX; yalv++ ) {
        if ((evtype_b >> yalv) & 1) {
            LOG_DEBUG("  Event type 0x%02x  ", yalv);
            switch ( yalv ) {
                case EV_SYN : LOG_LN_DEBUG( COL(FG_BRIGHT_BLUE, "(Synch Events)") );        break;
                case EV_KEY : LOG_LN_DEBUG( COL(FG_BRIGHT_BLUE, "(Keys or Buttons)") );     break;
                case EV_REL : LOG_LN_DEBUG( COL(FG_BRIGHT_BLUE, "(Relative Axes)") );       break;
                case EV_ABS : LOG_LN_DEBUG( COL(FG_BRIGHT_BLUE, "(Absolute Axes)") );       break;
                case EV_MSC : LOG_LN_DEBUG( COL(FG_BRIGHT_BLUE, "(Miscellaneous)") );       break;
                case EV_LED : LOG_LN_DEBUG( COL(FG_BRIGHT_BLUE, "(LEDs)") );                break;
                case EV_SND : LOG_LN_DEBUG( COL(FG_BRIGHT_BLUE, "(Sounds)") );              break;
                case EV_REP : LOG_LN_DEBUG( COL(FG_BRIGHT_BLUE, "(Repeat)") );              break;
                case EV_FF  :
                case EV_FF_STATUS: LOG_LN_DEBUG( COL(FG_BRIGHT_BLUE, "(Force Feedback)") ); break;
                case EV_PWR: LOG_LN_DEBUG( COL(FG_BRIGHT_BLUE, "(Power Management)") );     break;
                default:
                LOG_LN_DEBUG( COL(FG_BRIGHT_BLUE, "(Unknown: 0x%04hx)"), yalv);
            }
        }
    }
    

    __uint128_t features = 0;
    ioctl( fd_rw, EVIOCGBIT(EV_FF, sizeof(features)), &features );
    LOG_ANSI( "\n" );
    LOG_LN_DEBUG("Supported force feedback features:");
    for ( int yalv = 0; yalv < FF_MAX; yalv++ ) {
        if ((features >> yalv) & 1) {
            LOG_DEBUG("  Force Feedback Feature 0x%02x  ", yalv);
            switch ( yalv ) {
                case FF_CONSTANT   : LOG_LN_DEBUG( COL(FG_BRIGHT_BLUE, "(FF_CONSTANT  )") ); break; 
                case FF_PERIODIC   : LOG_LN_DEBUG( COL(FG_BRIGHT_BLUE, "(FF_PERIODIC  )") ); break;
                case FF_SQUARE     : LOG_LN_DEBUG( COL(FG_BRIGHT_BLUE, "(FF_SQUARE    )") ); break;
                case FF_TRIANGLE   : LOG_LN_DEBUG( COL(FG_BRIGHT_BLUE, "(FF_TRIANGLE  )") ); break;
                case FF_SINE       : LOG_LN_DEBUG( COL(FG_BRIGHT_BLUE, "(FF_SINE      )") ); break;
                case FF_SAW_UP     : LOG_LN_DEBUG( COL(FG_BRIGHT_BLUE, "(FF_SAW_UP    )") ); break;
                case FF_SAW_DOWN   : LOG_LN_DEBUG( COL(FG_BRIGHT_BLUE, "(FF_SAW_DOWN  )") ); break;
                case FF_CUSTOM     : LOG_LN_DEBUG( COL(FG_BRIGHT_BLUE, "(FF_CUSTOM    )") ); break;
                case FF_RAMP       : LOG_LN_DEBUG( COL(FG_BRIGHT_BLUE, "(FF_RAMP      )") ); break;
                case FF_SPRING     : LOG_LN_DEBUG( COL(FG_BRIGHT_BLUE, "(FF_SPRING    )") ); break;
                case FF_FRICTION   : LOG_LN_DEBUG( COL(FG_BRIGHT_BLUE, "(FF_FRICTION  )") ); break;
                case FF_DAMPER     : LOG_LN_DEBUG( COL(FG_BRIGHT_BLUE, "(FF_DAMPER    )") ); break;
                case FF_RUMBLE     : LOG_LN_DEBUG( COL(FG_BRIGHT_BLUE, "(FF_RUMBLE    )") ); break;
                case FF_INERTIA    : LOG_LN_DEBUG( COL(FG_BRIGHT_BLUE, "(FF_INERTIA   )") ); break;
                case FF_GAIN       : LOG_LN_DEBUG( COL(FG_BRIGHT_BLUE, "(FF_GAIN      )") ); break;
                case FF_AUTOCENTER : LOG_LN_DEBUG( COL(FG_BRIGHT_BLUE, "(FF_AUTOCENTER)") ); break;

                default: LOG_LN_DEBUG( COL(FG_BRIGHT_BLUE, "(Unknown: 0x%04hx)"), yalv ); 
            }
        }
    }

    int eff_cnt = 0;
    ioctl( fd_rw, EVIOCGEFFECTS, &eff_cnt );
    LOG_ANSI( "\n" );
    LOG_LN_DEBUG( "Effect count: " COL(FG_BRIGHT_BLUE, "%d"), eff_cnt );
}


#endif