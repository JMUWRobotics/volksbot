#include "rclcpp/rclcpp.hpp"

#include <signal.h>
#include <termios.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

// #include <fcntl.h>
// #include <stdexcept>
#include <sys/mman.h>

// motor controller APIs
#include "LayerClasses/CVmc.h"
#include "epos2/epos2.h"

// ROS specifics
#include "rclcpp/rclcpp.hpp"
#include <std_srvs/srv/empty.hpp>
#include <std_msgs/msg/string.hpp>
#include <geometry_msgs/msg/twist.hpp>

#include "volksface/msg/ticks.hpp"
#include "volksface/srv/velocities.hpp"
#include "volksface/msg/vel.hpp"

#include <chrono>
using namespace std::chrono_literals;

#define WHEEL_DIAMETER_IRMA	26.0	// cm
#define WHEEL_DIAMETER_UTE	26.0	// cm
#define WHEEL_BASE_IRMA 	44.4	// cm
#define WHEEL_BASE_UTE		44.4	// cm

#define PORT_NAME_VMC		"/dev/VMC"
#define PORT_NAME_EPOS		"USB0"
#define PORT_NAME_EPOS2L	"/dev/EPOS2L"
#define PORT_NAME_EPOS2R	"/dev/EPOS2R"

namespace controller {
	static constexpr auto TOPIC_NAME_TICKS   = "VMC";
	static constexpr auto TOPIC_NAME_VEL     = "Vel";
	static constexpr auto TOPIC_NAME_TWIST   = "cmd_vel";
	static constexpr auto TOPIC_NAME_CONTROL = "Controls";
	static constexpr auto TIME_PUB_PERIOD_TICKS = 50ms;

	#define LOGGER (rclcpp::get_logger("Motor_Controller"))

	using Vel 		 = volksface::msg::Vel;
	using Ticks 	 = volksface::msg::Ticks;
	using Velocities = volksface::srv::Velocities;
	using Twist      = geometry_msgs::msg::Twist;

	// ros publisher, subscribers, services and co.
	static rclcpp::Node::SharedPtr node;
	static rclcpp::Service<Velocities>::SharedPtr service;
	static rclcpp::Subscription<Vel>::SharedPtr subscriber_vel;
	static rclcpp::Subscription<Twist>::SharedPtr subscriber_cmd_vel;
	static rclcpp::Publisher<Ticks>::SharedPtr publisher;
	static rclcpp::TimerBase::SharedPtr _timer_pub, _timer_fail_safe;
	static Ticks current_motor_ticks;

	static rclcpp::Time lastcommand;
	static double last_vel_left=0, last_vel_right=0;

	// motor controller drivers
	static VMC::CVmc 	mcd_vmc;
	static EPOS::EPOS2	mcd_epos;
	static mcd::I_MCD* 	active_motor_controller = nullptr;

	//----------------------------//
	// Motor Controller Functions //
	//----------------------------//
	bool search_and_select_motor_controller() {
		if( active_motor_controller != nullptr ) {
			printf( "\x1b[33mAlready connected to a motor controller\x1b[0m\n" );
			return true;
		}

		// trying VMC
		printf( "Trying to connect to VMC\n" );
		if( mcd_vmc.connect( PORT_NAME_VMC ) ) {
			printf( "\x1b[32mConnected to VMC\x1b[0m\n" );
			active_motor_controller = &mcd_vmc;
			return true;
		}

		// trying EPOS2
		printf( "\nTrying to connect to EPOS2\n" );
		if( mcd_epos.connect( PORT_NAME_EPOS ) ) {
			printf( "\x1b[32mConnected to EPOS2\x1b[0m\n" );
			active_motor_controller = &mcd_epos;
			return true;
		}
		

		// trying EPOS2L
		printf( "\nTrying to connect to EPOS2L\n" );
		if( mcd_epos.connect( PORT_NAME_EPOS2L ) ) {
			printf( "\x1b[32mConnected to EPOS2L\x1b[0m\n" );
			active_motor_controller = &mcd_epos;
			return true;
		}
		
		// trying EPOS2R
		printf( "\nTrying to connect to EPOS2R\n" );
		if( mcd_epos.connect( PORT_NAME_EPOS2R ) ) {
			printf( "\x1b[32mConnected to EPOS2R\x1b[0m\n" );
			active_motor_controller = &mcd_epos;
			return true;
		}
		
		// FAILED to connect to any motor controller
		printf( "\n\x1b[31mFAILED! Could not connect to any motor controller\x1b[0m\n" );
		return false; 
	}

	void get_ticks( Ticks& ticks ) {
		if( active_motor_controller != nullptr ) {
			active_motor_controller->get_ticks( ticks.left, ticks.right );			
		}
	}

	void set_speeds( double left, double right ) {
		lastcommand = node->get_clock()->now();

		mcd::util::linear_twist( WHEEL_BASE_IRMA, left, right, current_motor_ticks.vx, current_motor_ticks.vth );

		if( active_motor_controller != nullptr ) {
			last_vel_left = left;
			last_vel_right = right;
			active_motor_controller->set_speeds( left, right );
		}
	}

	//-----------//
	// Callbacks //
	//-----------//
	// in contrast to ROS, service callbacks return void and not bool
	void callback( const Velocities::Request::ConstSharedPtr vel, Velocities::Response::SharedPtr response ) {
		response->success = true;

		set_speeds( vel->left, vel->right );
	}

	void Vcallback( const Vel::ConstSharedPtr vel ) {
		set_speeds( vel->left, vel->right );
	}

	void CVcallback( const Twist::ConstSharedPtr cmd_vel ) {
		double linear = -cmd_vel->linear.x * 100.0;  // from m/s to cm/s
		double v_diff =  cmd_vel->angular.z * WHEEL_BASE_IRMA / 2;
		
		double leftvel  = linear - v_diff;
		double rightvel = linear + v_diff;
		
		leftvel  = copysign( fmin(fabs(leftvel) , 100), leftvel  );
		rightvel = copysign( fmin(fabs(rightvel), 100), rightvel );
		
		set_speeds( leftvel, rightvel );
	}

	//----------------//
	// Main Functions //	
	//----------------//
	void run() {
		RCLCPP_INFO(LOGGER, "Motor controller starting main loop!");
		rclcpp::spin(node);
	}

	void cleanup() {
		if( active_motor_controller != nullptr ) {
			active_motor_controller->disconnect();
		}
		
		rclcpp::shutdown();
	}

	void setup(int argc, char* argv[]) {
		printf("Ros init...\n");

		rclcpp::init(argc, argv);
		node = std::make_shared<rclcpp::Node>("mc_controller");

		current_motor_ticks.header.frame_id = "base_link";

		// must initialize time variable, otherwise will fail due to incompatible clocksources
		lastcommand = node->get_clock()->now();
		
		// Publishers, Subscribers & Services
		// ROS2 is "special", if we don't keep references to the created "create_xyz" pointer handles
		// the compiler will gracefully disregard these instruction, i.e. "optimize" them out since we "don't use them"
		// this then results in callbacks not being called and timers not working
		// Thank you ROS and CPP
		subscriber_vel = node->create_subscription<Vel>( TOPIC_NAME_VEL, rclcpp::QoS(100).reliable(), Vcallback );
		subscriber_cmd_vel = node->create_subscription<Twist>( TOPIC_NAME_TWIST, rclcpp::QoS(10).reliable(), CVcallback );
		service = node->create_service<Velocities>( TOPIC_NAME_CONTROL, callback );
		
		publisher = node->create_publisher<Ticks>( TOPIC_NAME_TICKS, 20 );
		
		_timer_pub = node->create_wall_timer( TIME_PUB_PERIOD_TICKS, [](){
			current_motor_ticks.header.stamp = node->get_clock()->now();
			get_ticks( current_motor_ticks );
			publisher->publish( current_motor_ticks );
		} );

		_timer_fail_safe = node->create_wall_timer( 50.5ms / 3, [](){
			if( node->get_clock()->now() - lastcommand >= 50.5ms ) {
				set_speeds( 0, 0 );
			}
		} );

		while( !search_and_select_motor_controller() ) {
			rclcpp::sleep_for( 1s );
		}

		active_motor_controller->reset_ticks();
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


