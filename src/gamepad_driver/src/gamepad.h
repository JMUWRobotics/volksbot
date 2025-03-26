#ifndef __GAMEPAD_HPP__
#define __GAMEPAD_HPP__

#include "stdio.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdint.h>

#include <linux/input.h>

#define EV_TYPE_BUTTON EV_KEY
#define EV_TYPE_AXIS   EV_ABS
#define EV_TYPE_FF     EV_FF

#define AXIS_VALUE_MAX  32767
#define AXIS_VALUE_MIN -32767


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

        virtual void apply_event( const input_event event ) = 0;
        virtual void set_rumble( const uint16_t mag_strong, const uint16_t mag_weak );

        void publish_event();
        void publish_state();

        // Manly for debuging
        void print_state();
        void print_event();
        void print_evio();

        uint16_t    id;
        input_event jse;
        js_state    jss;
    protected:
        ff_effect effect;
        int fd_read, fd_write;
};


/**
 * @brief linearly map a value from [-32767; 32767] to [0; 32767]
 */
static inline uint16_t map_s16_to_u16( const int16_t val ) {
    return (axis_t)( ( ((float)val / 0x7fff)*0.5 + 0.5 ) * AXIS_VALUE_MAX );
}

static inline time_t time_ms() {
    timeval tv;

    gettimeofday( &tv, NULL );
    return tv.tv_sec*1000 + tv.tv_usec/1000;
}




#endif