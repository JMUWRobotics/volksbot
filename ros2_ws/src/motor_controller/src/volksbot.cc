#include "rclcpp/rclcpp.hpp"
#include "stdio.h"

#include <signal.h>
#include <termios.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <cmath>
#include "sys/time.h"

#include <unistd.h>
#include <fcntl.h>
#include <stdexcept>


#include <sys/mman.h>


#include "CVmc.h"
#include "epos2/epos2.h"


//VMC::CVmc *vmc;

void quit(int sig) {
	exit(0);
}

int main(int argc, char* argv[]) {
	mlockall(MCL_CURRENT | MCL_FUTURE);

	printf("Ros init...\n");

	rclcpp::init(argc, argv);
	auto node = std::make_shared<rclcpp::Node>("VMC_Module");

	std::string controller;
	std::string device;
	
	// declare parameters
	controller = node->declare_parameter<std::string>("devices/controller", "VMC");
	device = node->declare_parameter<std::string>("/devices/volksbot", "/dev/ttyUSB1");

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
	rclcpp::spin(node);

	if ( controller == "VMC" ) {

		delete vmc;

	} else if ( controller == "EPOS2" ) {

		delete epos;

	}

	return 0;

}
