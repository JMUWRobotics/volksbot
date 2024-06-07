#include <ros/ros.h>
#include "stdio.h"
#include "CVmc.h"

#include <signal.h>
#include <termios.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <cmath>
#include "sys/time.h"

#define KEYCODE_R 0x43 
#define KEYCODE_L 0x44
#define KEYCODE_U 0x41
#define KEYCODE_D 0x42
#define KEYCODE_Q 0x71
#define KEYCODE_A 0x61
#define KEYCODE_Y 0x79

#include <unistd.h>
#include <fcntl.h>
#include <stdexcept>


#include <sys/mman.h>



#include "epos2/epos2.h"


//VMC::CVmc *vmc;

void quit(int sig) {

	exit(0);

}

int main(int argc, char* argv[]) {

	mlockall(MCL_CURRENT | MCL_FUTURE);

	printf("Ros init...\n");

	ros::init(argc, argv, "VMC_Module");
	ros::NodeHandle n;

	std::string controller;
	std::string device;
	n.param<std::string>("/devices/controller", controller, "VMC");
	n.param<std::string>("/devices/volksbot", device, "/dev/ttyS5");

	VMC::CVmc *vmc;
	EPOS2* epos;

	if ( controller == "VMC" ) {

		printf("Using VMC as Motor Controler\n");

		vmc = new VMC::CVmc(device.c_str());

		if( !vmc->isConnected() ) {

			printf("Could not connect\n");
			delete vmc;
			return 1;

		}

	} else if ( controller == "EPOS2" ) {

		printf("Using EPOS2 as Motor Controller\n");

		epos = new EPOS2(device.c_str());

		if( !epos->isConnected() ) {

			printf("Could not connect\n");
			delete epos;
			return 1;

		}

	}


	signal(SIGINT,quit);
	ros::spin();

	if ( controller == "VMC" ) {

		delete vmc;

	} else if ( controller == "EPOS2" ) {

		delete epos;

	}

	return 0;

}
