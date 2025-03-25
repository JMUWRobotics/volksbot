#include "logitechf710.h"
#include "xboxONE.h"


#include <string.h>

int main(int argc, char* argv[]) {
    (void) argc;
    (void) argv;

    // LogitechF gp = LogitechF("/dev/input/js0");
    XBoxOne gp = XBoxOne("/dev/input/js0");

    printf( "\x1b[2J\x1b[H" );
    while (1) {
        gp.wait_for_event();
        // gp.publish_state();
        // gp.publish_event();
        gp.print_state();
        // sleep(1);
    }

    return 0;
}
