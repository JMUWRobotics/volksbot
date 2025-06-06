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
#include <math.h>
using namespace std::chrono_literals;


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

	static rclcpp::Node::SharedPtr node;
	static rclcpp::Service<Velocities>::SharedPtr service;
	static rclcpp::Subscription<Vel>::SharedPtr subscriber_vel;
	static rclcpp::Subscription<Twist>::SharedPtr subscriber_cmd_vel;
	static rclcpp::Publisher<Ticks>::SharedPtr publisher;
	static rclcpp::TimerBase::SharedPtr _pub_timer;
	static Ticks current_motor_ticks;

	static rclcpp::Time lastcommand;

	// Motor-Controller interfaced - lightweight interface to the underlying motor controllers, currently only VMC and EPOS2 
	struct mc_interface {
		enum mc_type : int {
			NONE = 0,
			VMC  = 1,
			EPOS = 2
		};

		struct model_t {
			const char* device_path;
			const double wheel_base_cm;
			const double ticks_per_cm;
		};

		static constexpr model_t model_NONE  = { "", 44.4, -461.817 };
		static constexpr model_t model_VMC   = { "/dev/VMC",  44.4, -461.817 };
		static constexpr model_t model_EPOS2 = { "/dev/volksbot", 44.4, -1811.9178 };
		static constexpr model_t models[] = { model_NONE, model_VMC, model_EPOS2 };
		
		union motor_t {
			void* none;
			VMC::CVmc* vmc;
			EPOS2* epos;
		} motor_ptr = { nullptr };
		mc_type mc_in_use = NONE;

		bool search_and_select_motor_controller() {
			if( mc_in_use != NONE ) {
				printf( "\x1b[33mAlready connected to a motor controller\x1b[0m\n" );
				return true;
			}

			// trying VMC
			printf( "Trying to connect to VMC\n" );
			motor_ptr.vmc = new VMC::CVmc( model_VMC.device_path );

			if( motor_ptr.vmc->isConnected() ) {
				printf( "\x1b[32mConnected to VMC\x1b[0m\n" );
				mc_in_use = VMC;
				return true;
			}
			delete motor_ptr.vmc;

			// trying EPOS2
			printf( "\nTrying to connect to EPOS2\n" );
			motor_ptr.epos = new EPOS2( model_EPOS2.device_path );

			if( motor_ptr.epos->isConnected() ) {
				printf( "\x1b[32mConnected to EPOS2\x1b[0m\n" );
				mc_in_use = EPOS;
				return true;
			}
			delete motor_ptr.epos;
			
			// FAILED to connect to any motor controller
			printf( "\n\x1b[31mFAILED! Could not connect to any motor controller\x1b[0m\n" );
			mc_in_use = NONE;
			return false; 
		}

		void cleanup() {
			switch( mc_in_use ) {
				case VMC:  if( motor_ptr.vmc  != nullptr ) delete motor_ptr.vmc; break;
				case EPOS: if( motor_ptr.epos != nullptr ) delete motor_ptr.epos; break;
				case NONE: break;
				default:   break;
			}
		}

		void set_speeds( const double vel_left, const double vel_right ) {
			lastcommand = node->get_clock()->now();

			switch( mc_in_use ) {
				case VMC:	motor_ptr.vmc->setMotors( vel_left, vel_right ); break;
				case EPOS: 	break;
				case NONE: 	break;
				default: 	break;
			}	
		}

		void reset_ticks() {
			switch( mc_in_use ) {
				case VMC:	motor_ptr.vmc->resetMotorTicks(); break;
				case EPOS: 	break;
				case NONE: 	break;
				default: 	break;
			}	
		}
		
		void get_ticks( Ticks& ticks ) {
			switch( mc_in_use ) {
				case VMC:	
					ticks.left  = motor_ptr.vmc->getMotorValueLeft(  VMC::CVmc::MOTOR_TICKS_ABSOLUTE );
					ticks.right = motor_ptr.vmc->getMotorValueRight( VMC::CVmc::MOTOR_TICKS_ABSOLUTE );
					break;
				case EPOS: 	break;
				case NONE: 	break;
				default: 	break;
			}
		}
	};
	static mc_interface mci;


	//-----------//
	// Callbacks //
	//-----------//
	// in contrast to ROS, service callbacks return void and not bool
	void callback( const Velocities::Request::ConstSharedPtr vel, Velocities::Response::SharedPtr response ) {
		mci.set_speeds( -vel->right, -vel->left );

		response->success = true;
	}

	void Vcallback( const Vel::ConstSharedPtr vel ) {
		mci.set_speeds( -vel->right, -vel->left );
	}

	void CVcallback( const Twist::ConstSharedPtr cmd_vel ) {
		//lastcommand = node->get_clock()->now();
		double vx = cmd_vel->linear.x;
		double vth = cmd_vel->angular.z;
		double linear = -cmd_vel->linear.x * 100.0;  // from m/s to cm/s
		double v_diff =  cmd_vel->angular.z * mc_interface::models[mci.mc_in_use].wheel_base_cm / 2;  // 22.2 is half of baseline of the robot
		// for a 180° turn (= pi rad / sec) both wheels need to move half
		// of the circumference of the circle defined by the baseline
		// ,i.e. pi * 22.2
		//  double v_diff = cmd_vel->angular.z * 9.4468085;

		double leftvel  = linear - v_diff;
		double rightvel = linear + v_diff;
		
		leftvel  = copysign( fmin(fabs(leftvel) , 100), leftvel  );
		rightvel = copysign( fmin(fabs(rightvel), 100), rightvel );
		
		mci.set_speeds( -rightvel, -leftvel );
		current_motor_ticks.vx = vx;
		current_motor_ticks.vth = vth;
	}

	//----------------//
	// Main Functions //	
	//----------------//
	void run() {
		RCLCPP_INFO(LOGGER, "Motor controller starting main loop!");
		rclcpp::spin(node);
	}

	void cleanup() {
		mci.cleanup();
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
		_pub_timer = node->create_wall_timer( TIME_PUB_PERIOD_TICKS, [](){
			current_motor_ticks.header.stamp = node->get_clock()->now();
			mci.get_ticks( current_motor_ticks );
			publisher->publish( current_motor_ticks );
		} );

		while( !mci.search_and_select_motor_controller() ) {
			rclcpp::sleep_for( 1s );
		}

		mci.reset_ticks();
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


