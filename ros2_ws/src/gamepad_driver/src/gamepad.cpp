/////////////////////////////////////////////////////////////////////////////
// @file    gamepad.cpp
// @brief   implementation of gamepad and joystick event in- and outputs
// @author  Nico Schubert
// @date    31.03.2025
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

// Macro for ansi console coloring
#define COL(code, str)  "\x1b[" #code "m" str "\x1b[0m"


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
        printf( COL(93, "Gamepad is already connected!\n") );
        return;
    }

    fd_rw = open( filename, O_RDWR | O_NONBLOCK );
    
    if( fd_rw < 0 ) {
        fd_rw = -1;
        printf( COL(91, "Gamepad %s not found!\n"), filename);
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
            printf( COL(93, "Failed to initiate backend rumble thread! Rumbling of the gamepad will now not work!\n" ) );
            printf( COL(93, "Try to restart the Application if rumbling of the gamepad is required." ) );
        } else {
            pthread_detach( thread_rumble );
        }
    }
}

void Gamepad::disconnect() {
    if( fd_rw == -1 ) {
        printf( COL(93, "Gamepad is already disconnected!\n") );
        return;
    }

    input_event stop;

    /* Stop the effect */
    stop.type = EV_FF;
    stop.code = effect.id;
    stop.value = 0;

    write( fd_rw, &stop, sizeof(stop) );

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
    write( fd_rw, &ie, sizeof(ie) );
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
    printf( "INPUT EVENT --------------------------\n" );
    printf( "ID: " COL(94, "%d") "\n", id );
    printf( "time : \n");
    printf( "  sec: " COL(94, "%8ld") "\n", gp_ie.time.tv_sec   );
    printf( " µsec: " COL(94, "%8ld") "\n", gp_ie.time.tv_usec  );
    printf( "type : " COL(94, "%6x" ) "\n", gp_ie.type   );
    printf( "code : " COL(94, "%6x" ) "\n", gp_ie.code   );
    printf( "value: " COL(94, "%6d" ) "\n", gp_ie.value  );

    printf( "\nGAMEPAD EVENT ------------------------\n" );
    printf( "       is_axis: " COL(94, "%5s") "\n", gp_e.is_axis ? "true" : "false" );
    printf( "       code-id: " COL(94, "%2d") "\n", gp_e.code );
    printf( "          code: " COL(94, "%-20s") "\n", gp_e.code==gp_index::INVALID ? "INVALID" : gp_index_LUT[ gp_e.code ] );
    printf( "value (axis)  : " COL(94, "%6d") "\n", gp_e.value.axis );
    printf( "value (button): " COL(94, "%5s") "\n", gp_e.value.btn ? "true" : "false" );

    printf( "\x1b[15F" );
}

#define STR_BOOL(s, v) ( (v) ? COL(42, " " s " ") : COL(41,  " " s " ") )
#define PERCENT(x) ( (int16_t)( 100.0 * (x) / (float)(AXIS_VALUE_MAX) ) )
void Gamepad::print_state() const {
    printf( "ID: " COL(94, "%d") "\n", id );
    printf( "Buttons: %s %s %s %s  %s %s %s  %s %s\n", 
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
    printf( "HUD:\n" );
    printf( "LEFT_RIGHT: %s\n",  gp_s.hud.left_right == 0 ? "       " : ( gp_s.hud.left_right > 0 ? COL(42, " LEFT ") : COL(42, " RIGHT ") ) );
    printf( "UP_DOWN:     %s\n", gp_s.hud.up_down    == 0 ? "       " : ( gp_s.hud.up_down    > 0 ? COL(42, "  UP  ") : COL(42, " DOWN ")  ) );
    
    printf( "\n" );
    printf( "LT: " COL(94, "%6d") " (" COL(94, "%3d") "%%)\n", gp_s.throttle.left , PERCENT(gp_s.throttle.left) );
    printf( "RT: " COL(94, "%6d") " (" COL(94, "%3d") "%%)\n", gp_s.throttle.right, PERCENT(gp_s.throttle.right) );
    printf("\n");
    
    printf( "L Stick (left, up): %s " COL(94, "%6d") ", " COL(94, "%6d") " ( " COL(94, "%4d") "%%, " COL(94, "%4d") "%%)\n",
        STR_BOOL("btn", gp_s.thumb_stick_left.pressed ),
        gp_s.thumb_stick_left.left_right ,
        gp_s.thumb_stick_left.up_down ,
        PERCENT(gp_s.thumb_stick_left.left_right) ,
        PERCENT(gp_s.thumb_stick_left.up_down) 
    );
    printf( "R Stick (left, up): %s " COL(94, "%6d") ", " COL(94, "%6d") " ( " COL(94, "%4d") "%%, " COL(94, "%4d") "%%)\n",
        STR_BOOL("btn", gp_s.thumb_stick_right.pressed),
        gp_s.thumb_stick_right.left_right,
        gp_s.thumb_stick_right.up_down,
        PERCENT(gp_s.thumb_stick_right.left_right),
        PERCENT(gp_s.thumb_stick_right.up_down)
    );

    printf( "\nRumble: strong: " COL(94, "%6d") " (" COL(94, "%3d") "%%), weak: " COL(94, "%6d") " (" COL(94, "%3d") "%%)\n",
        effect.u.rumble.strong_magnitude, PERCENT(0.5*effect.u.rumble.strong_magnitude), 
        effect.u.rumble.weak_magnitude, PERCENT(0.5*effect.u.rumble.weak_magnitude)
    );

    printf( "\x1b[13F" );
}
void Gamepad::print_evio() const {
    if( !has_connection() ) {
        return;
    }

    printf( COL(1, "\nSerial Number: ") COL(1;94, "%s") "\n", device_serial_number.c_str() );

    char buff[512];
    ioctl( fd_rw, EVIOCGNAME(sizeof(buff)), buff );
    printf( "Device Name: " COL(1;94, "%s") "\n", buff );

    ioctl( fd_rw, EVIOCGPHYS(sizeof(buff)), buff );
    printf( "Physical Path: " COL(94, "%s") "\n", buff );

    ioctl( fd_rw, EVIOCGUNIQ(sizeof(buff)), buff );
    printf( "Unique ID: " COL(94, "%s") "\n", buff );

    ioctl( fd_rw, EVIOCGPROP(sizeof(buff)), buff );
    printf( "Device Properties: " COL(94, "%s") "\n", buff );

    input_id id;
    ioctl( fd_rw, EVIOCGID, &id );
    printf("\nID:\n");
    printf("bustype: " COL(94, "0x%4x") "\n", id.bustype);
    printf("vendor : " COL(94, "0x%4x") "\n", id.vendor );
    printf("product: " COL(94, "0x%4x") "\n", id.product);
    printf("version: " COL(94, "0x%4x") "\n", id.version);


    uint64_t evtype_b = 0;
    ioctl(fd_rw, EVIOCGBIT(0, EV_MAX), &evtype_b);  
    printf("\nSupported event types:\n");
    for ( int yalv = 0; yalv < EV_MAX; yalv++ ) {
        if ((evtype_b >> yalv) & 1) {
            printf("  Event type 0x%02x  ", yalv);
            switch ( yalv ) {
                case EV_SYN : printf( COL(94, "(Synch Events)\n") );        break;
                case EV_KEY : printf( COL(94, "(Keys or Buttons)\n") );     break;
                case EV_REL : printf( COL(94, "(Relative Axes)\n") );       break;
                case EV_ABS : printf( COL(94, "(Absolute Axes)\n") );       break;
                case EV_MSC : printf( COL(94, "(Miscellaneous)\n") );       break;
                case EV_LED : printf( COL(94, "(LEDs)\n") );                break;
                case EV_SND : printf( COL(94, "(Sounds)\n") );              break;
                case EV_REP : printf( COL(94, "(Repeat)\n") );              break;
                case EV_FF  :
                case EV_FF_STATUS: printf( COL(94, "(Force Feedback)\n") ); break;
                case EV_PWR: printf( COL(94, "(Power Management)\n") );     break;
                default:
                printf( COL(94, "(Unknown: 0x%04hx)\n"), yalv);
            }
        }
    }
    

    __uint128_t features = 0;
    ioctl( fd_rw, EVIOCGBIT(EV_FF, sizeof(features)), &features );
    printf("\nSupported force feedback features:\n");
    for ( int yalv = 0; yalv < FF_MAX; yalv++ ) {
        if ((features >> yalv) & 1) {
            printf("  Force Feedback Feature 0x%02x  ", yalv);
            switch ( yalv ) {
                case FF_CONSTANT   : printf( COL(94, "(FF_CONSTANT  )\n") ); break; 
                case FF_PERIODIC   : printf( COL(94, "(FF_PERIODIC  )\n") ); break;
                case FF_SQUARE     : printf( COL(94, "(FF_SQUARE    )\n") ); break;
                case FF_TRIANGLE   : printf( COL(94, "(FF_TRIANGLE  )\n") ); break;
                case FF_SINE       : printf( COL(94, "(FF_SINE      )\n") ); break;
                case FF_SAW_UP     : printf( COL(94, "(FF_SAW_UP    )\n") ); break;
                case FF_SAW_DOWN   : printf( COL(94, "(FF_SAW_DOWN  )\n") ); break;
                case FF_CUSTOM     : printf( COL(94, "(FF_CUSTOM    )\n") ); break;
                case FF_RAMP       : printf( COL(94, "(FF_RAMP      )\n") ); break;
                case FF_SPRING     : printf( COL(94, "(FF_SPRING    )\n") ); break;
                case FF_FRICTION   : printf( COL(94, "(FF_FRICTION  )\n") ); break;
                case FF_DAMPER     : printf( COL(94, "(FF_DAMPER    )\n") ); break;
                case FF_RUMBLE     : printf( COL(94, "(FF_RUMBLE    )\n") ); break;
                case FF_INERTIA    : printf( COL(94, "(FF_INERTIA   )\n") ); break;
                case FF_GAIN       : printf( COL(94, "(FF_GAIN      )\n") ); break;
                case FF_AUTOCENTER : printf( COL(94, "(FF_AUTOCENTER)\n") ); break;

                default: printf( COL(94, "(Unknown: 0x%04hx)\n"), yalv ); 
            }
        }
    }

    int eff_cnt = 0;
    ioctl( fd_rw, EVIOCGEFFECTS, &eff_cnt );
    printf( "\nEffect count: " COL(94, "%d") "\n", eff_cnt );
}


#endif