#include "rclcpp/rclcpp.hpp"

#include <signal.h>
#include <termios.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include <sys/mman.h>

// motor controller APIs
#include "LayerClasses/CVmc.h"
#include "epos2/epos2.h"

// ROS specifics
#include "rclcpp/rclcpp.hpp"

#include "volksface/volksbot.h"
#include "volksface/ansi.h"

#include <chrono>
using namespace std::chrono_literals;
using namespace VB;

// #define MC_AUTO_DETECT

namespace controller {
	static constexpr auto TIME_PUB_PERIOD_TICKS = 50ms;

	#define LOGGER (rclcpp::get_logger("Motor_Controller"))

	// ROS publishers, subscribers, services and co.
	static rclcpp::Node::SharedPtr node;
	static rclcpp::Service<srv::VelCmd>::SharedPtr 		service_vel_cmd;
	static rclcpp::Subscription<msg::Rover>::SharedPtr 	subscriber_rover;
	static rclcpp::Subscription<msg::VelGP>::SharedPtr 	subscriber_vel_gp;
	static rclcpp::Subscription<msg__Twist>::SharedPtr 	subscriber_vel_twist;
	static rclcpp::Publisher<msg::MCTicks>::SharedPtr 	publisher_mc_ticks;
	static rclcpp::TimerBase::SharedPtr _timer_pub, _timer_fail_safe;
	static msg::MCTicks current_motor_ticks;

	// State variables
	static msg::Rover active_rover;
	static rclcpp::Time lastcommand;

	// motor controller drivers
	static VMC::CVmc 	mcd_vmc;
	static EPOS::EPOS2	mcd_epos;
	static mcd::I_MCD* 	active_motor_controller = nullptr;

	//----------------------------//
	// Motor Controller Functions //
	//----------------------------//
	
	// deprecated
	bool search_and_select_motor_controller() {
		#define PORT_NAME_VMC		"/dev/VMC"
		#define PORT_NAME_EPOS		"USB0"
		#define PORT_NAME_EPOS2L	"/dev/EPOS2L"
		#define PORT_NAME_EPOS2R	"/dev/EPOS2R"

		if( active_motor_controller != nullptr ) {
			printf( COL(FG_YELLOW, "Already connected to a motor controller\n") );
			return true;
		}

		// trying VMC
		printf( "Trying to connect to VMC\n" );
		if( mcd_vmc.connect( PORT_NAME_VMC ) ) {
			printf( COL(FG_GREEN, "Connected to VMC\n") );
			active_motor_controller = &mcd_vmc;
			return true;
		}

		// trying EPOS2
		printf( "\nTrying to connect to EPOS2\n" );
		if( mcd_epos.connect( PORT_NAME_EPOS ) ) {
			printf( COL(FG_GREEN, "Connected to EPOS2\n") );
			active_motor_controller = &mcd_epos;
			return true;
		}
		

		// trying EPOS2L
		printf( "\nTrying to connect to EPOS2L\n" );
		if( mcd_epos.connect( PORT_NAME_EPOS2L ) ) {
			printf( COL(FG_GREEN, "Connected to EPOS2L\n") );
			active_motor_controller = &mcd_epos;
			return true;
		}
		
		// trying EPOS2R
		printf( "\nTrying to connect to EPOS2R\n" );
		if( mcd_epos.connect( PORT_NAME_EPOS2R ) ) {
			printf( COL(FG_GREEN, "Connected to EPOS2R\n") );
			active_motor_controller = &mcd_epos;
			return true;
		}
		
		// FAILED to connect to any motor controller
		printf( COL(FG_RED, "\nFAILED! Could not connect to any motor controller\n") );
		return false; 
	}

	bool connect_via_rover( const msg::Rover& rover ) {
		if( active_motor_controller != nullptr ) {
			printf( COL(FG_YELLOW, "Already connected to a motor controller\n") );
			return false;
		}
		
		std::string mc_name = "";
		switch( (MCD::MCD)rover.motor_controller ) {
			case MCD::VMC:	 active_motor_controller = &mcd_vmc ; mc_name = "VMC"; break;
			case MCD::EPOS2: active_motor_controller = &mcd_epos; mc_name = "EPOS2"; break;

			case MCD::ERROR:
			default:
				printf( COL(FG_YELLOW, "Unrecognized motor controller id: %d\n"), rover.motor_controller );
				return false;
		}

		printf( "Trying to connect to %s\n", mc_name.c_str() );
		if( active_motor_controller->connect( rover.motor_controller_port.c_str() ) ) {
			active_motor_controller->reset_ticks();
			
			current_motor_ticks.cm_per_tick = 1.0 / mcd::util::tick_per_cm(
				active_motor_controller->ticks_per_revolution(),
				rover.wheel_diameter
			);

			printf( COL(FG_GREEN, "Connected to motor controller %s\n"), mc_name.c_str() );
			
			return true;
		} else {
			printf( COL(FG_RED, "Failed to connect to %s\n"), mc_name.c_str() );

			return false;
		}
	}

	void get_ticks() {
		if( active_motor_controller != nullptr ) {
			active_motor_controller->get_ticks( current_motor_ticks.left, current_motor_ticks.right );
		}
	}

	// set speeds, retrun true if successful, false otherwise
	bool set_speeds( double left, double right ) {
		if( !active_rover.is_valid || active_motor_controller == nullptr) {
			return false;
		}

		lastcommand = node->get_clock()->now();

		mcd::util::linear_twist( active_rover.wheel_base, left, right, current_motor_ticks.vx, current_motor_ticks.vth );

		active_motor_controller->set_speeds( left, right );

		return true;
	}

	//-----------//
	// Callbacks //
	//-----------//
	// in contrast to ROS, service callbacks return void and not bool
	void cb_vel_cmd( srv::VelCmd::Request::ConstSharedPtr vel, srv::VelCmd::Response::SharedPtr response ) {
		response->success = set_speeds( vel->left, vel->right );;
	}

	void cb_vel_gp( msg::VelGP::ConstSharedPtr vel ) {
		set_speeds( vel->left, vel->right );
	}

	void cb_vel_twist( msg__Twist::ConstSharedPtr cmd_vel ) {
		double linear = -cmd_vel->linear.x * 100.0;  // from m/s to cm/s
		double v_diff =  cmd_vel->angular.z * active_rover.wheel_base / 2;
		
		double leftvel  = linear - v_diff;
		double rightvel = linear + v_diff;
		
		leftvel  = copysign( fmin(fabs(leftvel) , 100), leftvel  );
		rightvel = copysign( fmin(fabs(rightvel), 100), rightvel );
		
		set_speeds( leftvel, rightvel );
	}

	void cb_rover( msg::Rover::ConstSharedPtr rover ) {
		if( *rover != active_rover ) {
			active_rover = *rover;

			if( active_motor_controller != nullptr ) {
				active_motor_controller->disconnect();
				active_motor_controller = nullptr;
			}
			
			if( active_rover.is_valid ) {
				connect_via_rover( active_rover );
			}
		}
	}

	//----------------//
	// Main Functions //	
	//----------------//
	void run() {
		RCLCPP_INFO(LOGGER, "Motor controller starting main loop!");
		RCLCPP_INFO(LOGGER, "waiting for Rover to be published\n" );
		rclcpp::spin(node);
	}

	void cleanup() {
		if( active_motor_controller != nullptr ) {
			active_motor_controller->disconnect();
			active_motor_controller = nullptr;
		}
		
		rclcpp::shutdown();
	}

	void setup(int argc, char* argv[]) {
		RCLCPP_INFO(LOGGER, "Ros init...\n");

		rclcpp::init(argc, argv);
		node = std::make_shared<rclcpp::Node>("mc_controller");

		current_motor_ticks.header.frame_id = "base_link";

		// must initialize time variable, otherwise will fail due to incompatible clocksources
		lastcommand = node->get_clock()->now();

		active_rover.is_valid = false;
		
		// Publishers, Subscribers & Services
		// ROS2 is "special", if we don't keep references to the created "create_xyz" pointer handles
		// the compiler will gracefully disregard these instruction, i.e. "optimize" them out since we "don't use them"
		// this then results in callbacks not being called and timers not working
		// Thank you ROS and CPP
		subscriber_rover = node->create_subscription<msg::Rover>( TOPIC_NAME_ROVER, rclcpp::QoS(10).reliable(), cb_rover );
		subscriber_vel_gp = node->create_subscription<msg::VelGP>( TOPIC_NAME_VEL_GP, rclcpp::QoS(100).reliable(), cb_vel_gp );
		subscriber_vel_twist = node->create_subscription<msg__Twist>( TOPIC_NAME_VEL_TWIST, rclcpp::QoS(10).reliable(), cb_vel_twist );
		service_vel_cmd = node->create_service<srv::VelCmd>( SERVICE_NAME_COMMAND, cb_vel_cmd );
		
		publisher_mc_ticks = node->create_publisher<msg::MCTicks>( TOPIC_NAME_TICKS, 20 );
		
		_timer_pub = node->create_wall_timer( TIME_PUB_PERIOD_TICKS, [](){
			if( active_rover.is_valid ) {
				current_motor_ticks.header.stamp = node->get_clock()->now();
				get_ticks();
				publisher_mc_ticks->publish( current_motor_ticks );
			}
		} );

		_timer_fail_safe = node->create_wall_timer( 50.5ms / 3, [](){
			if( node->get_clock()->now() - lastcommand >= 50.5ms ) {
				set_speeds( 0, 0 );
			}
		} );

		#ifdef MC_AUTO_DETECT
		while( !search_and_select_motor_controller() ) {
			rclcpp::sleep_for( 1s );
		}
		active_motor_controller->reset_ticks();
		#endif
	}
}


int main(int argc, char* argv[]) {
	// mlockall(MCL_CURRENT | MCL_FUTURE); // for now, keep commented or else it will terminate the program when creating a ros node
	signal(SIGINT, [](int sig){ (void)sig; controller::cleanup(); exit(0); });

	controller::setup(argc, argv);
	controller::run();
	controller::cleanup();

	return 0;
}