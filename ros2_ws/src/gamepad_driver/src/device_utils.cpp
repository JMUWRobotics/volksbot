/////////////////////////////////////////////////////////////////////////////
// @file    device_utils.cpp
// @brief   helper function for managing device look ups etc.
// @author  Nico Schubert
// @date    10.11.2025
/////////////////////////////////////////////////////////////////////////////


#ifndef __DEVICE_UTILS_H__
#define __DEVICE_UTILS_H__

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------

#include "device_utils.h"

#include <dirent.h>
#include <sys/ioctl.h>

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include <fcntl.h>

#include <string.h>
#include <string>


#include "logitechf710.h"
#include "xboxONE.h"


//-----------------------------------------------------------------------------
// Macros & Constexprs
//-----------------------------------------------------------------------------

//--------------//
// User defined //
//--------------//
// List of gamepads to be used
static inline LogitechF __gp_logitech_f;
static inline XBoxOne   __gp_xbox_one;
static inline Gamepad *const gamepads[] = { &__gp_logitech_f, &__gp_xbox_one };

// #define USE_DEBUG

//------------//
// Predefined //
//------------//

static constexpr char input_path[]    = "/dev/input/";
static constexpr char sysclass_path[] = "/sys/class/input/";

// number of gamepads in the list 
static constexpr uint gamepad_count = sizeof(gamepads) / sizeof(*gamepads);



template<typename... Args>
static inline int read_evio(const char* filename, unsigned long int request, Args... args) {
    int fd = open( filename, O_RDONLY );
    
    int ret = ioctl(fd, request, args...);
    
    close(fd);
    return ret;
}

#define read_evio_name( filename, out_name ) read_evio( filename, EVIOCGNAME(sizeof(out_name)), out_name )


//-----------------------------------------------------------------------------
// Util functions
//-----------------------------------------------------------------------------


namespace device_util {
    std::vector<std::string> get_input_js_names() {
        std::vector<std::string> js_names;

        dirent* dp;
        DIR* d_input = opendir( input_path );
        while( true ) {
            dp = readdir( d_input );
            if( dp == NULL )
                break;

            if( dp->d_type != DT_CHR )
                continue;
            
            if( strncmp(dp->d_name, "js", 2 ) == 0 ) {
                js_names.push_back( std::string(dp->d_name) );
            }
        }
        closedir( d_input );

        return js_names;
    }

    std::vector<std::string> get_event_file_names( const std::vector<std::string> js_names ) {
        std::vector<std::string> js_event_names;
        
        dirent* dp;
        for( const std::string& js_name : js_names ){
            std::string sys_device_path = std::string( sysclass_path ) + js_name + "/device/";
            
            DIR* d_sys_dev_p = opendir( sys_device_path.c_str() );
            while( true ) {
                dp = readdir( d_sys_dev_p );
                if( dp == NULL )
                    break;
                
                if( dp->d_type == DT_DIR ) {
                    if( strncmp(dp->d_name, "event", 5 ) == 0 ) {
                        js_event_names.push_back( std::string(dp->d_name) );
                        break;
                    }
                }
            }
            closedir( d_sys_dev_p );
        }

        return js_event_names;
    }

    Gamepad* select_and_connect_gamepad( const bool is_in_search_loop ) {
        const std::vector<std::string> js_names = get_input_js_names();

        if( js_names.empty() ) {
            LOG_LN_WARN( COL(FG_BRIGHT_RED, "! No Gamepad or Joystick could be detected !") );
            LOG_LN_WARN( COL(FG_BRIGHT_YELLOW, "Make sure the device is correctly connected!" ) );
            if( !is_in_search_loop ) {
                LOG_LN_WARN( COL(FG_BRIGHT_YELLOW, "You need to restart the Application!" ) );
            }
            return nullptr;
        }

        const std::vector<std::string> js_event_names = get_event_file_names( js_names );

        const int devices = js_names.size();
        LOG_LN_INFO("Number of joystick devices detected: " COL(FG_BRIGHT_MAGENTA, "%d"), devices);
        
        // find first known gamepad
        Gamepad* gamepad;
        int  selected_index = -1;
        std::string selected_device_name;
        for( int i=0; i < devices; i++ ) {
            const std::string& js_name    = js_names.at(i);
            const std::string& event_name = js_event_names.at(i);
            
            std::string event_path = std::string( input_path ) + event_name;
            
            char device_name[256];
            read_evio_name( event_path.c_str(), device_name );

            LOG_LN_INFO( " - [" COL(FG_BRIGHT_MAGENTA, "%d") "] " COL(FG_BRIGHT_MAGENTA, "%4s") " - " COL(FG_BRIGHT_MAGENTA, "%7s") " - " COL(FG_BRIGHT_MAGENTA, "%s"),
                    i, js_name.c_str(), event_name.c_str(), device_name );

            if( selected_index != -1 )
                continue;

            // search for gamepad whose ID is contained or equal to the device name
            for( Gamepad* gp : gamepads ) {
                if (strstr(device_name, gp->evio_id_name()) != NULL) {
                    selected_index = i;
                    selected_device_name = std::string( device_name );
                    
                    gamepad = gp;
                    gamepad->connect( event_path.c_str() );
                }
            }
        }
        LOG_ANSI("\n");

        if( selected_index != -1 ) {
            LOG_LN_INFO( "Found a supported gamepad" );
            LOG_LN_INFO( "Selected Gamepad is: " COL(FG_BRIGHT_GREEN,"%s") " as joystick device " COL(FG_BRIGHT_GREEN,"%s"), 
                         selected_device_name.c_str(), js_names.at(selected_index).c_str() );

            return gamepad;
        }

        LOG_LN_WARN( COL(FG_BRIGHT_RED, "! None of the detected Gamepads or Joysticks are known !" ) );
        LOG_LN_WARN( "Please connect one of the following known joystick devices:" );

        for( Gamepad* gp : gamepads ) {
            LOG_LN_WARN( "  - " COL(FG_BRIGHT_BLUE,"%s"), gp->evio_id_name() );
        }

        if( !is_in_search_loop ) {
            LOG_LN_WARN( COL(FG_BRIGHT_YELLOW, "You need to restart the Application!" ) );
        }

        return nullptr;
    }
    
    bool try_reconnect( Gamepad* gamepad ) {
        const std::string serial_number = gamepad->get_serial_number();

        const std::vector<std::string> js_names = get_input_js_names();
        const std::vector<std::string> js_event_names = get_event_file_names( js_names );

        // search for gamepad device of matching serial number
        for( const std::string& event_name : js_event_names ) {
            const std::string event_path = std::string( input_path ) + event_name;
            
            std::string serial;
            if( get_usb_serial_of_input_event( event_path, serial ) ) {
                if( serial_number.compare( serial ) == 0 ) {
                    gamepad->disconnect();
                    gamepad->connect( event_path.c_str() );
                    return true;
                }
            }
        }

        return false;
    }


    bool resolve_link( const std::string path, std::string& resolved ) {
        char resolved_path[PATH_MAX];
        
        char* res_ptr = realpath( path.c_str(), resolved_path );
        if( res_ptr != resolved_path ) {
            return false;
        }
    
        resolved = std::string( resolved_path );

        return true;
    }
    
    bool get_usb_device_path( const std::string input_event_path, std::string& usb_path ) {
        // input_event_path must be of form `/dev/input/event*`
        if( !(input_event_path.compare( input_path ) > 0) )
            return false;

        // extracts the `eventN` part of the `/dev/input/eventN` filename
        std::string event_name = input_event_path.substr( strlen(input_path), input_event_path.length() - strlen(input_path) );
        
        // sys_path is now something like this: `/sys/class/input/event15`
        std::string sys_path = sysclass_path + event_name;
    
        // the resolved path should now look something like this:
        // `/sys/devices/pci0000:00/0000:00:08.1/0000:04:00.4/usb3/3-2/3-2:1.0/input/input68/event15`
        std::string resolved_path;
        if( !resolve_link( sys_path, resolved_path ) )
            return false;
        
        // the interesting usb part is only `/sys/devices/pci0000:00/0000:00:08.1/0000:04:00.4/usb3/3-2/`
        // therefor we have to step up four times with `..` and resolve it again (to be more clean)
        if( !resolve_link( resolved_path + "/../../../../", usb_path ) )
            return false;
    
        LOG_LN_DEBUG( "event_name:    " COL(FG_BRIGHT_BLUE, "%s"), event_name.c_str()    );
        LOG_LN_DEBUG( "sys_path:      " COL(FG_BRIGHT_BLUE, "%s"), sys_path.c_str()      );
        LOG_LN_DEBUG( "resolved_path: " COL(FG_BRIGHT_BLUE, "%s"), resolved_path.c_str() );
        LOG_LN_DEBUG( "usb_path:      " COL(FG_BRIGHT_BLUE, "%s"), usb_path.c_str()      );
    
        return true;
    }
    
    bool get_usb_device_serial_number( const std::string usb_device_path, std::string& serial_number ) {
        LOG_LN_DEBUG( "usb_dev_path:  " COL(FG_BRIGHT_BLUE, "%s"), usb_device_path.c_str() );

        FILE* fp = fopen( (usb_device_path + "/serial").c_str(), "r" );
    
        if( fp == NULL )
            return false;
    
        char* line = nullptr;
        size_t len;
        ssize_t read = getline( &line, &len, fp );
    
        fclose(fp);
    
        if( read == -1l )
            return false;
    
        if( !line )
            return false;
    
        serial_number = std::string( line );
        free(line);

        return true;
    }

    bool get_usb_serial_of_input_event( const std::string input_event_path, std::string& serial_number ) {
        std::string usb_device_path;

        if( !get_usb_device_path( input_event_path, usb_device_path ) )
            return false;
        
        if( !get_usb_device_serial_number( usb_device_path, serial_number ) )
            return false;
                
        return true;
    }
}





#endif