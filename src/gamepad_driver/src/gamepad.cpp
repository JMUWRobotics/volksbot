#ifndef __GAMEPAD_CPP__
#define __GAMEPAD_CPP__

#include "gamepad.h"


Gamepad::Gamepad(const char* filename)
: id(0), jse(), jss()
{
    fd = open(filename, O_RDONLY | O_NONBLOCK);
    
    if(fd < 0) {
        printf("Joystick %s not found!\n", filename);
        exit(0);
    }
}

Gamepad::~Gamepad() {
    close(fd);
}


void Gamepad::wait_for_event() {
    if ( read(fd, &jse, sizeof(js_event)) == sizeof(js_event) ) {
        id++;
        apply_event( jse );
    }
}

void Gamepad::print_event() {
    printf( "ID: %d\n", id );
    printf( "time  : \x1b[34m%8d\x1b[0m\n", jse.time   );
    printf( "type  : \x1b[34m%6x\x1b[0m\n", jse.type   );
    printf( "number: \x1b[34m%6x\x1b[0m\n", jse.number );
    printf( "value : \x1b[34m%6d\x1b[0m\n", jse.value  );

    printf( "\x1b[5F" );
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
    printf( "LT: \x1b[34m%6d\x1b[0m (\x1b[34m%3d\x1b[0m%%)\n", jss.throttle.left , PERCENT(jss.throttle.left) );
    printf( "RT: \x1b[34m%6d\x1b[0m (\x1b[34m%3d\x1b[0m%%)\n", jss.throttle.right, PERCENT(jss.throttle.right) );
    printf("\n");
    
    printf( "L Stick (left, up): %s \x1b[34m%6d\x1b[0m, \x1b[34m%6d\x1b[0m (\x1b[34m%4d\x1b[0m%%, \x1b[34m%4d\x1b[0m%%)\n", STR_BOOL("+", jss.thumb_stick_left.pressed ), jss.thumb_stick_left.left_right , jss.thumb_stick_left.up_down , PERCENT(jss.thumb_stick_left.left_right) , PERCENT(jss.thumb_stick_left.up_down)  );
    printf( "R Stick (left, up): %s \x1b[34m%6d\x1b[0m, \x1b[34m%6d\x1b[0m (\x1b[34m%4d\x1b[0m%%, \x1b[34m%4d\x1b[0m%%)\n", STR_BOOL("+", jss.thumb_stick_right.pressed), jss.thumb_stick_right.left_right, jss.thumb_stick_right.up_down, PERCENT(jss.thumb_stick_right.left_right), PERCENT(jss.thumb_stick_right.up_down) );

    printf( "\x1b[10F" );
}

void Gamepad::publish_event() { }
void Gamepad::publish_state() { }


#endif