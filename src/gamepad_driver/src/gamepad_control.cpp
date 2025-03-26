#include "logitechf710.h"
#include "xboxONE.h"

/*
    TODOs:
    - create simple automatic game pad detection and selection
    - create autonomous rumble event handling (via Threading?)
    - integrate ROS2 (Services & Publishers) 
    - create udev rules for static event input linking

    => Integrate into Volksbot package
*/


int main(int argc, char* argv[]) {
    (void) argc;
    (void) argv;

    constexpr const char* device = "/dev/input/event15";

    // LogitechF gp = LogitechF( device );
    XBoxOne gp = XBoxOne( device );
    gp.print_evio();

    printf( "\x1b[2J\x1b[H" );
    while (1) {
        gp.wait_for_event();
        // gp.publish_state();
        // gp.publish_event();
        
        gp.print_state();
        // gp.print_event();
        
        gp.set_rumble( gp.jss.throttle.left, gp.jss.throttle.right );

        // sleep(1);
    }

    return 0;
}
