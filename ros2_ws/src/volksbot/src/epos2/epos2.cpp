#include "epos2.h"

EPOS2::EPOS2() : Node("epos2") {

	EPOS2::init("USB0");

}

EPOS2::EPOS2(const char* port) : Node("epos2") {

	EPOS2::init(port);

}

EPOS2::~EPOS2() {

	closeEPOSDevice();

}

bool EPOS2::isConnected() {

	return g_isConnected;

}

// in contrast to ROS, service callbacks return void and not bool
void EPOS2::callback(const std::shared_ptr<const volksbot::srv::Velocities::Request> vel, std::shared_ptr<volksbot::srv::Velocities::Response> response) {

	lastcommand = this->get_clock()->now();

	// get request values
	leftvel = vel->left;
	rightvel = vel->right;

	// set service response 
	response->success = true;
}


void EPOS2::Vcallback(const volksbot::msg::Vels::ConstSharedPtr vel ) {

	//RCLCPP_INFO(rclcpp::get_logger("Volksbot"), "Velocity Callback");
	lastcommand = this->get_clock()->now();
	leftvel = vel->left;
	rightvel = vel->right;

}

void EPOS2::CVcallback(const geometry_msgs::msg::Twist::ConstSharedPtr cmd_vel) {

	lastcommand = this->get_clock()->now();
	vx = cmd_vel->linear.x;
	vth = cmd_vel->angular.z;
	double linear = -cmd_vel->linear.x * 100.0;  // from m/s to cm/s
	double v_diff = cmd_vel->angular.z * 22.2;

	// 22.2 is half of baseline of the robot
	// for a 180° turn (= pi rad / sec) both wheels need to move half
	// of the circumference of the circle defined by the baseline
	// ,i.e. pi * 22.2
	//  double v_diff = cmd_vel->angular.z * 9.4468085;

	if ( linear > 0 ) {

		leftvel = (double) (linear - v_diff);
		rightvel = (double) (linear + v_diff);

	} else {

		leftvel = (double) (linear - v_diff);
		rightvel = (double) (linear  + v_diff);

	}

	if ( fabs(leftvel) > 100.0 ) {

		if ( leftvel > 0 ) leftvel = 100.0;
		else leftvel = -100.0;

	}

	if ( fabs(rightvel) > 100.0 ) {

		if ( rightvel > 0 ) rightvel = 100.0;
		else rightvel = -100.0;

	}

}

void* EPOS2::threadFunction(void* param) {

	EPOS2* ref = (EPOS2*) param;

	volksbot::msg::Ticks t;

	t.header.frame_id = "base_link";

	if ( VCS_ActivateProfileVelocityMode(ref->g_pKeyHandle, 0, &ref->g_pErrorCode) == 0 ||
		 VCS_ActivateProfileVelocityMode(ref->g_pKeyHandle, 1, &ref->g_pErrorCode) == 0 ) {

		RCLCPP_INFO(rclcpp::get_logger("Volksbot"), "Cannot Activate Velocity Mode in EPOS2 Device! (0x%x)", ref->g_pErrorCode);

	}

	while ( ref->isConnected() ) {

		rclcpp::Time current = ref->get_clock()->now();
		t.header.stamp = ref->get_clock()->now();

		int tics_left = 0;
		int tics_right = 0;

		if (current - ref->lastcommand < rclcpp::Duration::from_seconds(0.0505) ) { // 50.5 milliseconds

			if ( VCS_MoveWithVelocity(ref->g_pKeyHandle, 1, - ref->rightvel * MAX_RPM / 100.0, &ref->g_pErrorCode) == 0 ||
				 VCS_MoveWithVelocity(ref->g_pKeyHandle, 0, ref->leftvel * MAX_RPM / 100, &ref->g_pErrorCode) == 0 ) {

				RCLCPP_INFO(rclcpp::get_logger("Volksbot"), "Cannot Send Move Instruction to EPOS2 Device! (0x%x)", ref->g_pErrorCode);

			}

			if ( VCS_GetPositionIs(ref->g_pKeyHandle, 1, &tics_right, &ref->g_pErrorCode) == 0 ||
				 VCS_GetPositionIs(ref->g_pKeyHandle, 0, &tics_left, &ref->g_pErrorCode) == 0 ) {

				RCLCPP_INFO(rclcpp::get_logger("Volksbot"), "Cannot Get Position of EPOS2 Device! (0x%x)", ref->g_pErrorCode);
			}

		} else {

			if ( VCS_MoveWithVelocity(ref->g_pKeyHandle, 1, 0, &ref->g_pErrorCode) == 0 ||
				 VCS_MoveWithVelocity(ref->g_pKeyHandle, 0, 0, &ref->g_pErrorCode) == 0 ) {

				RCLCPP_INFO(rclcpp::get_logger("Volksbot"), "Cannot Send Move Instruction to EPOS2 Device! (0x%x)", ref->g_pErrorCode);

			}

		}

		t.left = tics_left;
		t.right = - tics_right;

		t.vx = ref->vx;
		t.vth = ref->vth;

		ref->pub_->publish(t);

		std::this_thread::sleep_for(std::chrono::milliseconds(50));

	}

	if ( VCS_HaltVelocityMovement(ref->g_pKeyHandle, 1, &ref->g_pErrorCode) == 0 ||
		 VCS_HaltVelocityMovement(ref->g_pKeyHandle, 0, &ref->g_pErrorCode) == 0) {

		RCLCPP_INFO(rclcpp::get_logger("Volksbot"), "Cannot Stop Velocity Mode in EPOS2 Device! (0x%x)", ref->g_pErrorCode);

	}

}

void EPOS2::init(const char* port) {

	leftvel = 0.0;
	rightvel = 0.0;
	vx = 0;
	vth = 0;

	g_pKeyHandle = 0;
	strcpy(g_DeviceName, "EPOS2");
	strcpy(g_ProtocolStackName, "MAXON SERIAL V2");
	strcpy(g_InterfaceName, "USB");
	strcpy(g_PortName, port);
	g_baudrate = 1000000;
	g_isConnected = false;

	if ( !openEPOSDevice() ) {

		RCLCPP_INFO(rclcpp::get_logger("Volksbot"), "Cannot Open EPOS2 Device! (0x%x)", g_pErrorCode);

	} else {

		if ( !prepareEPOSDevice(0) || !prepareEPOSDevice(1) ) { //R = 0, L = 1

			RCLCPP_INFO(rclcpp::get_logger("Volksbot"), "Error Preparing EPOS2 Device! (0x%x)", g_pErrorCode);

		} else {

			g_isConnected = true;

			// initilize publisher and subscribers
			pub_ = this->create_publisher<volksbot::msg::Ticks>("VMC", 20);
			sub_ = this->create_subscription<volksbot::msg::Vels>("Vel", rclcpp::QoS(100).reliable(), std::bind(&EPOS2::Vcallback, this, std::placeholders::_1));
			cmd_vel_sub_ = this->create_subscription<geometry_msgs::msg::Twist>("cmd_vel", rclcpp::QoS(10).reliable(), std::bind(&EPOS2::CVcallback, this, std::placeholders::_1));

			// placeholders are for setting the number of parameters in the binded function
			// services commonly have two parameters (Request, Response) 
			service_ = this->create_service<volksbot::srv::Velocities>("Controls", std::bind(&EPOS2::callback, this, std::placeholders::_1, std::placeholders::_2));

			pthread_create(&threadId, NULL, &EPOS2::threadFunction, this);

		}

	}

}

bool EPOS2::openEPOSDevice() {

	bool lResult = false;

	g_pKeyHandle = VCS_OpenDevice(g_DeviceName, g_ProtocolStackName, g_InterfaceName, g_PortName, &g_pErrorCode);

	if( g_pKeyHandle!=0 && g_pErrorCode == 0 ) {

		unsigned int lBaudrate = 0;
		unsigned int lTimeout = 0;

		if ( VCS_GetProtocolStackSettings(g_pKeyHandle, &lBaudrate, &lTimeout, &g_pErrorCode) != 0 ) {

			if ( VCS_SetProtocolStackSettings(g_pKeyHandle, g_baudrate, lTimeout, &g_pErrorCode) != 0 ) {

				if ( VCS_GetProtocolStackSettings(g_pKeyHandle, &lBaudrate, &lTimeout, &g_pErrorCode) != 0 ) {

					if ( g_baudrate == (int) lBaudrate ) {

						lResult = true;

					}

				}

			}

		}

	} else {

		g_pKeyHandle = 0;

	}

	return lResult;
}

bool EPOS2::prepareEPOSDevice(int g_usNodeId) {

	bool lResult = true;
	int oIsFault = 0;

	if ( VCS_GetFaultState(g_pKeyHandle, g_usNodeId, &oIsFault, &g_pErrorCode ) == 0 ) {

		RCLCPP_INFO(rclcpp::get_logger("Volksbot"), "GetFaultState");
		lResult = false;

	}

	if( lResult ) {

		if( oIsFault ) {

			if ( VCS_ClearFault(g_pKeyHandle, g_usNodeId, &g_pErrorCode) == 0) {

				RCLCPP_INFO(rclcpp::get_logger("Volksbot"), "ClearFault");
				lResult = false;

			}

		}

		if( lResult ) {

			int oIsEnabled = 0;

			if ( VCS_GetEnableState(g_pKeyHandle, g_usNodeId, &oIsEnabled, &g_pErrorCode) == 0 ) {

				RCLCPP_INFO(rclcpp::get_logger("Volksbot"), "GetEnableState");
				lResult = false;

			}

			if( lResult ) {

				if( !oIsEnabled ) {

					if( VCS_SetEnableState(g_pKeyHandle, g_usNodeId, &g_pErrorCode) == 0 ) {

						RCLCPP_INFO(rclcpp::get_logger("Volksbot"), "SetEnableState");
						lResult = false;

					}

				}

			}

		}

	}

	return lResult;
}

bool EPOS2::closeEPOSDevice() {

	int lResult = false;

	if ( VCS_CloseDevice(g_pKeyHandle, &g_pErrorCode) != 0 && g_pErrorCode == 0 ) {

		lResult = true;

	}

	return lResult;

}
