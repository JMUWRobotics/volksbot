#ifndef __GAMEPAD_CPP__
#define __GAMEPAD_CPP__

#include "gamepad.h"

#include <linux/input.h>
#include <sys/ioctl.h>
#include <string.h>
#include <time.h>

#define MAX_UPDATE_RATE_FF_MS   100u

Gamepad::Gamepad(const char* filename)
: id(0), jse(), jss()
{
    fd_read  = open( filename, O_RDONLY | O_NONBLOCK );
    fd_write = open( filename, O_WRONLY );
    
    if ( fd_read < 0 || fd_write < 0 ) {
        printf("Gamepad %s not found!\n", filename);
        exit(0);
    }

    // Force feedback
    effect.id = -1;
    effect.type = FF_RUMBLE;

    effect.replay.length = MAX_UPDATE_RATE_FF_MS;
    effect.replay.delay = 0;
    
    effect.u.rumble.strong_magnitude = 0xFFFF;
    effect.u.rumble.weak_magnitude   = 0xFFFF;
    
    ioctl( fd_write, EVIOCSFF, &effect );

    input_event play;
    play.type = EV_FF;
    play.code = effect.id;
    play.value = 1;

    write( fd_write, &play, sizeof(play) );
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
        // Event separator -> Ignore
        if( js.type == EV_SYN )
            return;
        
        jse = js;
        id++;
        apply_event( jse );
    }
}

void Gamepad::publish_event() { }
void Gamepad::publish_state() { }


void Gamepad::set_rumble( const uint16_t mag_strong, const uint16_t mag_weak ) {
    static time_t t0=time_ms();
    
    if( time_ms() - t0 < MAX_UPDATE_RATE_FF_MS )
        return;
    
    t0 = time_ms();
    
    input_event ie;
    input_event play;
    input_event stop;
    
    /* Stop the effect */
    stop.type = EV_FF;
    stop.code = effect.id;
    stop.value = 0;

    write( fd_write, &stop, sizeof(stop) );
    
    /* Set Magnitude */
    effect.u.rumble.strong_magnitude = mag_strong;
    effect.u.rumble.weak_magnitude   = mag_weak;
    
    ioctl( fd_write, EVIOCSFF, &effect );

    /* Play the effect */
    play.type = EV_FF;
    play.code = effect.id;
    play.value = 1;

    write( fd_write, &play, sizeof(play) );
    
    /* Set Gain i.e. Strength of Rumble */
    // ie.type = EV_FF;
    // ie.code = FF_GAIN;
    // ie.value = magnitude;

    // write( fd_write, &ie, sizeof(input_event) );
}


void Gamepad::print_event() {
    printf( "ID: %d\n", id );
    printf( "time : \n");
    printf( "  sec: \x1b[94m%8ld\x1b[0m\n", jse.time.tv_sec   );
    printf( " µsec: \x1b[94m%8ld\x1b[0m\n", jse.time.tv_usec  );
    printf( "type : \x1b[94m%6x\x1b[0m\n", jse.type   );
    printf( "code : \x1b[94m%6x\x1b[0m\n", jse.code   );
    printf( "value: \x1b[94m%6d\x1b[0m\n", jse.value  );

    printf( "\x1b[7F" );
}

#define STR_BOOL(s, v) ( (v) ? "\x1b[42m " s " \x1b[0m" : "\x1b[41m " s " \x1b[0m" )
#define PERCENT(x) ( (int16_t)( 100.0 * (x) / 32767.0 ) )
void Gamepad::print_state() {
    printf( "ID: %d\n", id );
    printf( "Buttons: %s %s %s %s  %s %s %s  %s %s\n", 
        STR_BOOL( "A", jss.buttons.A ),
        STR_BOOL( "B", jss.buttons.B ),
        STR_BOOL( "X", jss.buttons.X ),
        STR_BOOL( "Y", jss.buttons.Y ),

        STR_BOOL( "start", jss.buttons.start ),
        STR_BOOL( "back" , jss.buttons.back  ),
        STR_BOOL( "home" , jss.buttons.home  ),

        STR_BOOL( "LB", jss.shoulder.left ),
        STR_BOOL( "RB", jss.shoulder.right )
    );
    printf( "HUD:     %s %s %s %s\n", 
        STR_BOOL( "UP"   , jss.hud.up    ),
        STR_BOOL( "DOWN" , jss.hud.down  ),
        STR_BOOL( "LEFT" , jss.hud.left  ),
        STR_BOOL( "RIGHT", jss.hud.right )
    );
    
    printf( "\n" );
    printf( "LT: \x1b[94m%6d\x1b[0m (\x1b[94m%3d\x1b[0m%%)\n", jss.throttle.left , PERCENT(jss.throttle.left) );
    printf( "RT: \x1b[94m%6d\x1b[0m (\x1b[94m%3d\x1b[0m%%)\n", jss.throttle.right, PERCENT(jss.throttle.right) );
    printf("\n");
    
    printf( "L Stick (left, up): %s \x1b[94m%6d\x1b[0m, \x1b[94m%6d\x1b[0m (\x1b[94m%4d\x1b[0m%%, \x1b[94m%4d\x1b[0m%%)\n", STR_BOOL("+", jss.thumb_stick_left.pressed ), jss.thumb_stick_left.left_right , jss.thumb_stick_left.up_down , PERCENT(jss.thumb_stick_left.left_right) , PERCENT(jss.thumb_stick_left.up_down)  );
    printf( "R Stick (left, up): %s \x1b[94m%6d\x1b[0m, \x1b[94m%6d\x1b[0m (\x1b[94m%4d\x1b[0m%%, \x1b[94m%4d\x1b[0m%%)\n", STR_BOOL("+", jss.thumb_stick_right.pressed), jss.thumb_stick_right.left_right, jss.thumb_stick_right.up_down, PERCENT(jss.thumb_stick_right.left_right), PERCENT(jss.thumb_stick_right.up_down) );

    printf( "\x1b[10F" );
}
void Gamepad::print_evio() {
    char name[256];
    ioctl( fd_write, EVIOCGNAME(sizeof(name)), name );
    printf( "\nDevice Name: \x1b[1;94m%s\x1b[0m\n", name );


    uint64_t evtype_b = 0;
    ioctl(fd_write, EVIOCGBIT(0, EV_MAX), &evtype_b);    
    printf("\nSupported event types:\n");
    for ( int yalv = 0; yalv < EV_MAX; yalv++ ) {
        if ((evtype_b >> yalv) & 1) {
            printf("  \x1b[0mEvent type 0x%02x  \x1b[94m", yalv);
            switch ( yalv ) {
                case EV_SYN : printf("(Synch Events)\n");        break;
                case EV_KEY : printf("(Keys or Buttons)\n");     break;
                case EV_REL : printf("(Relative Axes)\n");       break;
                case EV_ABS : printf("(Absolute Axes)\n");       break;
                case EV_MSC : printf("(Miscellaneous)\n");       break;
                case EV_LED : printf("(LEDs)\n");                break;
                case EV_SND : printf("(Sounds)\n");              break;
                case EV_REP : printf("(Repeat)\n");              break;
                case EV_FF  :
                case EV_FF_STATUS: printf("(Force Feedback)\n"); break;
                case EV_PWR: printf("(Power Management)\n");     break;
                default:
                printf("(Unknown: 0x%04hx)\n",
                    yalv);
                }
            }
    }
    printf("\x1b[0m");
    

    __uint128_t features = 0;
    ioctl( fd_write, EVIOCGBIT(EV_FF, sizeof(features)), &features );
    printf("\nSupported force feedback features:\n");
    for ( int yalv = 0; yalv < FF_MAX; yalv++ ) {
        if ((features >> yalv) & 1) {
            printf("  \x1b[0mForce Feedback Feature 0x%02x  \x1b[94m", yalv);
            switch ( yalv ) {
                case FF_CONSTANT   : printf("(FF_CONSTANT  )\n"); break; 
                case FF_PERIODIC   : printf("(FF_PERIODIC  )\n"); break;
                case FF_SQUARE     : printf("(FF_SQUARE    )\n"); break;
                case FF_TRIANGLE   : printf("(FF_TRIANGLE  )\n"); break;
                case FF_SINE       : printf("(FF_SINE      )\n"); break;
                case FF_SAW_UP     : printf("(FF_SAW_UP    )\n"); break;
                case FF_SAW_DOWN   : printf("(FF_SAW_DOWN  )\n"); break;
                case FF_CUSTOM     : printf("(FF_CUSTOM    )\n"); break;
                case FF_RAMP       : printf("(FF_RAMP      )\n"); break;
                case FF_SPRING     : printf("(FF_SPRING    )\n"); break;
                case FF_FRICTION   : printf("(FF_FRICTION  )\n"); break;
                case FF_DAMPER     : printf("(FF_DAMPER    )\n"); break;
                case FF_RUMBLE     : printf("(FF_RUMBLE    )\n"); break;
                case FF_INERTIA    : printf("(FF_INERTIA   )\n"); break;
                case FF_GAIN       : printf("(FF_GAIN      )\n"); break;
                case FF_AUTOCENTER : printf("(FF_AUTOCENTER)\n"); break;

                default: printf("(Unknown: 0x%04hx)\n", yalv ); 
            }
        }
    }
    printf("\x1b[0m");

    int eff_cnt = 0;
    ioctl( fd_write, EVIOCGEFFECTS, &eff_cnt );
    printf( "\nEffect count: \x1b[94m%d\x1b[0m\n", eff_cnt );
}


#endif