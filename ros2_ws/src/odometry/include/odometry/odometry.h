#ifndef ODOMETRY_HH
#define ODOMETRY_HH
#include "rclcpp/rclcpp.hpp"

// msgs
#include <geometry_msgs/msg/transform_stamped.hpp>
#include "nav_msgs/msg/odometry.hpp"

#ifdef USE_LOGGING_ODOMETRY
    #undef USE_LOGGING
    #define USE_LOGGING USE_LOGGING_ODOMETRY
#endif

#define LOGGING_NAME "odometry"
#include "volksface/logging.h"

#include "volksface/volksbot.h"

#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>
#include <tf2_ros/transform_broadcaster.h>
#include <tf2/LinearMath/Quaternion.h>

using std::placeholders::_1;

namespace volksbot {
	class Odometry : public rclcpp::Node {
	public:

		Odometry() : Odometry(false) { };

		Odometry(bool _publish_tf);
		~Odometry();

		void set_rover( VB::msg::Rover::ConstSharedPtr rover );

		const nav_msgs::msg::Odometry& getCurrentOdom() {
			return odom;
		}

		void update(int ms);

	private:
		void convertTicks2Odom( VB::msg::MCTicks::ConstSharedPtr cticks );

		void publish_odom( rclcpp::Time current_time, double dt, double dx, double dth );
		void publish_transform( rclcpp::Time current_time );

		// Declaration of Publisher and Subscriber
		rclcpp::Publisher<nav_msgs::msg::Odometry>::SharedPtr publisher_odometry;
		rclcpp::Subscription<VB::msg::MCTicks>::SharedPtr subscriber_ticks;
		rclcpp::Subscription<VB::msg::Rover>::SharedPtr subscriber_rover;

		std::shared_ptr<tf2_ros::TransformBroadcaster> odom_broadcaster_;
		bool firstticks = true;
		bool publish_tf = false;

		// current state
		double x, z, theta;
		double vx, vth;

		// last state
		rclcpp::Time last_time;
		int last_ticks_left, last_ticks_right;

		// message objects
		VB::msg::Rover active_rover;
		nav_msgs::msg::Odometry odom;
		geometry_msgs::msg::TransformStamped odom_trans;
	};
}

#endif
