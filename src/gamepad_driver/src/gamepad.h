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
    axis_t   up_down;
    axis_t   left_right;
    button_t pressed;
};

struct gp_state {
    struct { button_t A, B, X, Y, back, start, home; } buttons;
    struct { button_t up, down, left, right; } hud;
    struct { button_t left, right; } shoulder;
    struct { axis_t   left, right; } throttle;
    thumb_stick_t thumb_stick_left;
    thumb_stick_t thumb_stick_right;
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
         * @brief busy waits for incoming events and applies them after reception
         * @note  will not block when disconnected
         */
        void wait_for_event();

        /**
         * @brief maps a given input event to the general gamepad state.
         *        Must be implemented by every inherited implementation. 
         * @param event input event to be applied/mapped onto its gamepad state
         */
        virtual void apply_event( const input_event event ) = 0;

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
        uint32_t    get_last_event_id() const { return id;  }
        input_event get_last_event()    const { return gpe; }
        gp_state    get_state()         const { return gps; }
    
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

        // state variables
        uint32_t    id;     /* rolling input event id */
        input_event gpe;    /* last gamepad event */
        gp_state    gps;    /* current gamepad state */
    
        ff_effect effect;   /* force feed back effect  */

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