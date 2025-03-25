#ifndef __GAMEPAD_HPP__
#define __GAMEPAD_HPP__

#include "stdio.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdint.h>

#define BUTTON_TYPE 1 
#define AXIS_TYPE   2

#define AXIS_VALUE_MAX  32767
#define AXIS_VALUE_MIN -32767


struct js_event {
    uint32_t time;     /* event timestamp in milliseconds */
    int16_t  value;    /* value */
    uint8_t  type;     /* event type */
    uint8_t  number;   /* axis/button number */
};

typedef bool    button_t;
typedef int16_t axis_t;

struct thumb_stick_t {
    axis_t   up_down;
    axis_t   left_right;
    button_t pressed;
};

struct js_state {
    struct { button_t A, B, X, Y, back, start, home; } buttons;
    struct { button_t up, down, left, right; } hud;
    struct { button_t left, right; } shoulder;
    struct { axis_t   left, right; } throttle;
    thumb_stick_t thumb_stick_left;
    thumb_stick_t thumb_stick_right;
};


class Gamepad {
    public:
        Gamepad(const char* filename);
        ~Gamepad();
        
        void wait_for_event();

        virtual void apply_event( const js_event event ) = 0;
        virtual void receive_service() = 0;

        void publish_event();
        void publish_state();

        void print_state();
        void print_event();
        
    protected:
        uint16_t id;
        js_event jse;
        js_state jss;
        int fd;
};


/**
 * @brief linearly map a value from [-32767; 32767] to [0; 32767]
 */
static inline uint16_t map_s16_to_u16( const int16_t val ) {
    return (axis_t)( ( ((float)val / 0x7fff)*0.5 + 0.5 ) * AXIS_VALUE_MAX );
}




#endif