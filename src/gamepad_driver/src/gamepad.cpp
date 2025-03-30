#ifndef __GAMEPAD_CPP__
#define __GAMEPAD_CPP__

#include "gamepad.h"

#include <linux/input.h>
#include <sys/ioctl.h>
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


void* rumble_function(void* arg);

Gamepad::Gamepad() : id(0), gpe(), gps(), fd_read(-1), fd_write(-1) {}

void Gamepad::init( const char* filename ) {
    if( !(fd_read == -1 && fd_write == -1) ) {
        printf( COL(93, "Gamepad is already initialized!\n") );
        return;
    }

    fd_read  = open( filename, O_RDONLY | O_NONBLOCK );
    fd_write = open( filename, O_WRONLY );
    
    if ( fd_read < 0 || fd_write < 0 ) {
        printf( COL(91, "Gamepad %s not found!\n"), filename);
        exit(0);
    }

    // setup force feedback
    effect.id = -1;
    effect.type = FF_RUMBLE;

    effect.replay.length = MAX_UPDATE_RATE_FF_MS;
    effect.replay.delay = 0;

    int ret = pthread_create( &thread_rumble, NULL, &rumble_function, this );

    if( ret ) {
        printf( COL(93, "Failed to initiate backend rumble thread! Rumbling of the gamepad will now not work!\n" ) );
        printf( COL(93, "Try to restart the Application if rumbling of the gamepad is required." ) );
    }

    pthread_detach( thread_rumble );
}

Gamepad::~Gamepad() {
    input_event stop;

    /* Stop the effect */
    stop.type = EV_FF;
    stop.code = effect.id;
    stop.value = 0;

    write( fd_write, &stop, sizeof(stop) );

    close(fd_read);
    close(fd_write);
}


void Gamepad::wait_for_event() {
    input_event js;

    if( read(fd_read, &js, sizeof(input_event) ) == sizeof(input_event) ) {   
        // EV_SYN: Event separator -> Ignore
        if( js.type == EV_SYN )
            return;
        
        id++;
        apply_event( js );
    }
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

void Gamepad::set_rumble( const uint16_t mag_strong, const uint16_t mag_weak ) {
    LOCK( &mux_rumble );
    effect.u.rumble.strong_magnitude = mag_strong;
    effect.u.rumble.weak_magnitude   = mag_weak;
    UNLOCK( &mux_rumble );
}

void Gamepad::handle_rumble() {
    input_event ie;
    ie.type = EV_FF;
    ie.code = effect.id;
    
    /* not required since rumble_function will only callback this handler when the previous effect is over */
    /* Stop the effect */
    // ie.value = 0;
    // write( fd_write, &ie, sizeof(ie) );

    /* Setting the effect */
    ioctl( fd_write, EVIOCSFF, &effect );

    /* Play the effect */
    ie.value = 1;
    write( fd_write, &ie, sizeof(ie) );
}


void Gamepad::print_event() {
    printf( "ID: " COL(94, "%d") "\n", id );
    printf( "time : \n");
    printf( "  sec: " COL(94, "%8ld") "\n", gpe.time.tv_sec   );
    printf( " µsec: " COL(94, "%8ld") "\n", gpe.time.tv_usec  );
    printf( "type : " COL(94, "%6x" ) "\n", gpe.type   );
    printf( "code : " COL(94, "%6x" ) "\n", gpe.code   );
    printf( "value: " COL(94, "%6d" ) "\n", gpe.value  );

    printf( "\x1b[7F" );
}

#define STR_BOOL(s, v) ( (v) ? COL(42, " " s " ") : COL(41,  " " s " ") )
#define PERCENT(x) ( (int16_t)( 100.0 * (x) / 32767.0 ) )
void Gamepad::print_state() {
    printf( "ID: " COL(94, "%d") "\n", id );
    printf( "Buttons: %s %s %s %s  %s %s %s  %s %s\n", 
        STR_BOOL( "A", gps.buttons.A ),
        STR_BOOL( "B", gps.buttons.B ),
        STR_BOOL( "X", gps.buttons.X ),
        STR_BOOL( "Y", gps.buttons.Y ),

        STR_BOOL( "start", gps.buttons.start ),
        STR_BOOL( "back" , gps.buttons.back  ),
        STR_BOOL( "home" , gps.buttons.home  ),

        STR_BOOL( "LB", gps.shoulder.left ),
        STR_BOOL( "RB", gps.shoulder.right )
    );
    printf( "HUD:     %s %s %s %s\n", 
        STR_BOOL( "UP"   , gps.hud.up    ),
        STR_BOOL( "DOWN" , gps.hud.down  ),
        STR_BOOL( "LEFT" , gps.hud.left  ),
        STR_BOOL( "RIGHT", gps.hud.right )
    );
    
    printf( "\n" );
    printf( "LT: " COL(94, "%6d") " (" COL(94, "%3d") "%%)\n", gps.throttle.left , PERCENT(gps.throttle.left) );
    printf( "RT: " COL(94, "%6d") " (" COL(94, "%3d") "%%)\n", gps.throttle.right, PERCENT(gps.throttle.right) );
    printf("\n");
    
    printf( "L Stick (left, up): %s " COL(94, "%6d") ", " COL(94, "%6d") " ( " COL(94, "%4d") "%%, " COL(94, "%4d") "%%)\n",
        STR_BOOL("btn", gps.thumb_stick_left.pressed ),
        gps.thumb_stick_left.left_right ,
        gps.thumb_stick_left.up_down ,
        PERCENT(gps.thumb_stick_left.left_right) ,
        PERCENT(gps.thumb_stick_left.up_down) 
    );
    printf( "R Stick (left, up): %s " COL(94, "%6d") ", " COL(94, "%6d") " ( " COL(94, "%4d") "%%, " COL(94, "%4d") "%%)\n",
        STR_BOOL("btn", gps.thumb_stick_right.pressed),
        gps.thumb_stick_right.left_right,
        gps.thumb_stick_right.up_down,
        PERCENT(gps.thumb_stick_right.left_right),
        PERCENT(gps.thumb_stick_right.up_down)
    );

    printf( "\nRumble: strong: " COL(94, "%6d") " (" COL(94, "%3d") "%%), weak: " COL(94, "%6d") " (" COL(94, "%3d") "%%)\n",
        effect.u.rumble.strong_magnitude, PERCENT(effect.u.rumble.strong_magnitude), 
        effect.u.rumble.weak_magnitude, PERCENT(effect.u.rumble.weak_magnitude)
    );

    printf( "\x1b[11F" );
}
void Gamepad::print_evio() {
    char name[256];
    ioctl( fd_write, EVIOCGNAME(sizeof(name)), name );
    printf( "\nDevice Name: " COL(1;94, "%s") "\n", name );


    uint64_t evtype_b = 0;
    ioctl(fd_write, EVIOCGBIT(0, EV_MAX), &evtype_b);    
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
    ioctl( fd_write, EVIOCGBIT(EV_FF, sizeof(features)), &features );
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
    ioctl( fd_write, EVIOCGEFFECTS, &eff_cnt );
    printf( "\nEffect count: " COL(94, "%d\n"), eff_cnt );
}


#endif