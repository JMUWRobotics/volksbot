#include <dirent.h>
#include <string.h>
#include <string>
#include <vector>
#include <cstdarg>
#include <sys/ioctl.h>
#include <sysexits.h>

#include "logitechf710.h"
#include "xboxONE.h"

/*
    TODOs:
    // create simple automatic game pad detection and selection
    // create autonomous rumble event handling (via Threading?)
    - integrate ROS2 (Services & Publishers) 
    
    => Integrate into Volksbot package
*/


// List of gamepads to be used
static inline Gamepad *const gamepads[] = { new LogitechF(), new XBoxOne() };

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

// Macro for ansi console coloring
#define COL(code, str)  "\x1b[" #code "m" str "\x1b[0m"


static constexpr char input_path[]    = "/dev/input/";
static constexpr char sysclass_path[] = "/sys/class/input/";


// get all connected joystick device names /dev/input/js*
std::vector<std::string> _get_input_js_names() {    
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

// get the input event handle of each joystick
std::vector<std::string> _get_event_file_names( const std::vector<std::string> js_names ) {
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

/**
 * @brief Select automatically one of the known joystick connected to the PC.ABS_DISTANCE
 * @brief Selects the first successful match
 * 
 * @return Gamepad* automatically selected gamepad or nullptr if none could be selected
 */
Gamepad* find_connected_gamepad() {
    const std::vector<std::string> js_names = _get_input_js_names();

    if( js_names.empty() ) {
        printf( COL(91, "! No Gamepad or Joystick could be detected !\n") );
        printf( COL(93, "Make sure the device is correctly connected!\nYou need to restart the Application!\n" ) );
        return nullptr;
    }

    const std::vector<std::string> js_event_names = _get_event_file_names( js_names );

    const int devices = js_names.size();
    printf("Number of joystick devices detected: " COL(95, "%d\n"), devices);
    
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

        printf( " - [" COL(95, "%d") "] " COL(95, "%4s") " - " COL(95, "%7s") " - " COL(95, "%s") "\n", i, js_name.c_str(), event_name.c_str(), device_name );

        if( selected_index != -1 )
            continue;

        // search for gamepad whose ID is contained or equal to the device name
        for( Gamepad* gp : gamepads ) {
            if (strstr(device_name, gp->evio_id_name()) != NULL) {
                selected_index = i;
                selected_device_name = std::string( device_name );
                
                gamepad = gp;
                gamepad->init( event_path.c_str() );
            }
        }
    }
    printf("\n");

    if( selected_index != -1 ) {
        printf( "Found a supported gamepad\n" );
        printf( "Selected Gamepad is: " COL(92,"%s") " as joystick device " COL(92,"%s") "\n", selected_device_name.c_str(), js_names.at(selected_index).c_str() );

        return gamepad;
    }

    printf( COL(91, "! None of the detected Gamepads or Joysticks are known !\n" ) );
    printf( "Please connect one of the following known joystick devices:\n" );

    for( Gamepad* gp : gamepads ) {
        printf( "  - " COL(94,"%s") "\n", gp->evio_id_name() );
    }

    printf( COL(93, "\nYou need to restart the Application!\n" ) );

    return nullptr;
}



int main(int argc, char* argv[]) {
    (void) argc;
    (void) argv;

    Gamepad* gp = find_connected_gamepad();

    if( gp == nullptr )
        return EX_IOERR;

    gp->print_evio();

    // printf( "\x1b[2J\x1b[H" );
    while (1) {
        gp->wait_for_event();
        
        gp->print_state();
        // gp->print_event();

        if( gp->get_state().buttons.A ) {
            gp->set_rumble( gp->get_state().throttle.left, gp->get_state().throttle.right );
        }
    }

    return EX_OK;
}
