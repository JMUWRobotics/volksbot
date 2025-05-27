/////////////////////////////////////////////////////////////////////////////
// @file    gamepad.h
// @brief   Gamepad interface to implement gamepad and joystick event in- and outputs
// @author  Nico Schubert
// @date    31.03.2025
/////////////////////////////////////////////////////////////////////////////


#ifndef __GAMEPAD_HPP__
#define __GAMEPAD_HPP__

#include "stdio.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdint.h>

#include <string>
#include <linux/input.h>
#include <pthread.h>

#define EV_TYPE_BUTTON EV_KEY
#define EV_TYPE_AXIS   EV_ABS
#define EV_TYPE_FF     EV_FF

#define AXIS_VALUE_MAX  32767
#define AXIS_VALUE_MIN -32767

#define MAX_UPDATE_RATE_FF_MS   100u

typedef bool    button_t;
typedef int16_t axis_t;

struct thumb_stick_t {
    axis_t   left_right;
    axis_t   up_down;
    button_t pressed;
};

struct gp_state {
    struct { button_t A, B, X, Y, back, start, home; } buttons;
    struct { button_t left, right; } shoulder;
    struct { axis_t left, right; } throttle;
    struct { axis_t left_right, up_down; } hud; // >0 == left or up, <0 == right or down, 0 == none
    thumb_stick_t thumb_stick_left;
    thumb_stick_t thumb_stick_right;
};

enum gp_index {
    // buttons
    A     = offsetof( gp_state, buttons.A ),
    B     = offsetof( gp_state, buttons.B ),
    X     = offsetof( gp_state, buttons.X ),
    Y     = offsetof( gp_state, buttons.Y ),
    BACK  = offsetof( gp_state, buttons.back ),
    START = offsetof( gp_state, buttons.start ),
    HOME  = offsetof( gp_state, buttons.home ),
    
    // shoulder
    LB = offsetof( gp_state, shoulder.left ),
    RB = offsetof( gp_state, shoulder.right ),
    
    // throttle
    LT = offsetof( gp_state, throttle.left ),
    RT = offsetof( gp_state, throttle.right ),

    // hud
    HUD_LEFT_RIGHT = offsetof( gp_state, hud.left_right ),
    HUD_UP_DOWN    = offsetof( gp_state, hud.up_down ),

    // thumb sticks
    THUMB_L_LEFT_RIGHT = offsetof( gp_state, thumb_stick_left.left_right ),
    THUMB_L_UP_DOWN    = offsetof( gp_state, thumb_stick_left.up_down ),
    THUMB_L_PRESSED    = offsetof( gp_state, thumb_stick_left.pressed ),
    
    THUMB_R_LEFT_RIGHT = offsetof( gp_state, thumb_stick_right.left_right ),
    THUMB_R_UP_DOWN    = offsetof( gp_state, thumb_stick_right.up_down ),
    THUMB_R_PRESSED    = offsetof( gp_state, thumb_stick_right.pressed ),

    INVALID = 0xff
};

struct gp_event_t {
    bool is_axis;
    gp_index code;
    union {
        axis_t axis;
        button_t btn;
    } value;
};


class Gamepad {
    public:
        virtual const char* evio_id_name() const { return "NULL"; }

        Gamepad();
        ~Gamepad();

        /**
         * @brief Connect this Gamepad to an event handle 
         * 
         * @param filename file name of the input event file handle to be connected to
         *                 (must be an input event in `/dev/input/`)
         */
        void connect( const char* filename );

        /**
         * @brief disconnect from any previously connected event handles
         */
        void disconnect();

        /**
         * @brief returns true iff a valid data connection to the gamepad device is present.
         * 
         * @return true if gamepad device is still connected to the pc
         * @return false if gamepad device has no connection to the pc 
         */
        bool has_connection() const;
        
        /**
         * @brief maps a given input event to the general gamepad state.
         *        Must be implemented by every inherited implementation. 
         * @param event input event to be applied/mapped onto its gamepad state
         */
        void apply_event( const gp_event_t event );

        /**
         * @brief busy waits for incoming events and applies them after reception
         * @note  will not block when disconnected
         */
        void wait_for_event();

        /**
         * @brief Set the strength of rumble effect of the gamepad.
         * @note  Has no effect on gamepads that dont have rumble capabilities  
         * 
         * @param mag_strong [min:0x0000-max:0xffff] magnitude of the strong rumble effect
         * @param mag_weak   [min:0x0000-max:0xffff] magnitude of the weak rumble effect
         */
        void set_rumble( const uint16_t mag_strong, const uint16_t mag_weak );
        
        ff_rumble_effect get_rumble() const { return effect.u.rumble; };
        
        bool has_rumble() const;

        std::string get_serial_number() const { return device_serial_number; }
        std::string get_name()          const { return name; }
        uint32_t    get_last_event_id() const { return id; }
        gp_event_t  get_last_event()    const { return gp_e; }
        gp_state    get_state()         const { return gp_s; }
        
        virtual axis_t get_default_deadzone() const = 0;
        axis_t get_deadzone() const { return deadzone; }
        void set_deadzone( const axis_t deadzone ) { this->deadzone = deadzone; }
    
        // for debuging
        void print_state() const;
        void print_event() const;
        void print_evio()  const;
        
    protected:
        /**
         * @brief handles and writes the rumble effect to the event file handle.
         *        Can be overriden if base implementation does not work for a gamepad implementation.
         */
        virtual void handle_rumble();

        /**
         * @brief map as generic joystick input events to a gamepad event
         * 
         * @param event generic linux input event 
         * @return gp_event_t abstract gamepad event
         */
        virtual gp_event_t map_event( const input_event event ) = 0;

        // state variables
        uint32_t    id;     /* rolling input event id */
        input_event gp_ie;  /* last input event */
        gp_state    gp_s;   /* current gamepad state */
        gp_event_t  gp_e;   /* last gamepad event */
    
        ff_effect effect;   /* force feed back effect  */

        axis_t deadzone = -1;

        // device variables
        int fd_rw;          /* event file descriptor */
        
        std::string device_serial_number; /* USB Serial number - to ID individual gamepads */
        std::string name;                 /* Gamepad Name */

    private:
        // Threading utilities for the rumble effect management
        friend void* rumble_function(void*);
        pthread_mutex_t mux_rumble = PTHREAD_MUTEX_INITIALIZER;
        pthread_t thread_rumble;
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