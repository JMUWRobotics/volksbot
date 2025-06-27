#include "rclcpp/rclcpp.hpp"
#include "stdio.h"

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <cmath>
#include "sys/time.h"

#include <unistd.h>
#include <fcntl.h>
#include <stdexcept>

#include "odometry/odometry.h"

using std::placeholders::_1;

#define M_TO_CM 100.0

//FILE *file;

namespace volksbot {

const static std::array<double, 36> global_covariance = { 0.01, 0, 		0, 		0, 			 0, 	0,
														  0, 	0.01, 	0, 		0, 			 0, 	0,
														  0, 	0, 		99999, 	0, 			 0, 	0,
														  0, 	0, 		0, 		0.174532925, 0, 	0,
														  0, 	0, 		0, 		0, 			 9999, 	0,
														  0, 	0, 		0, 		0, 			 0, 	99999 };


void Odometry::publish_odom( rclcpp::Time current_time, double dt, double dx, double dth ) {
	// since all odometry is 6DOF we'll need a quaternion created from yaw
	tf2::Quaternion odom_quat;
	odom_quat.setRPY(0, 0, -theta);
	
	odom.header.stamp = current_time;
	odom.pose.pose.position.x = x;
	odom.pose.pose.position.y = z;
	odom.pose.pose.orientation = tf2::toMsg( odom_quat ); //create Quaternion Msg from yaw

	// may be unecessary to set everytime
	odom.pose.covariance = global_covariance;

	double ax  = ( vx  - dx  / dt ) / dt;  // acceleration in   m / s^2
	// double ath = ( vth - dth / dt ) / dt;  // acceleration in rad / s^2
	
	if( dt > 0 && fabs(ax) < 5.0 ) {
		vx  = dx  / dt;
		vth = dth / dt;
		
		odom.twist.twist.linear.x  =  vx;
		odom.twist.twist.angular.z = -vth;
		
		odom.twist.covariance = global_covariance;
	} else {	// velocities cant be computed, use old values
		odom.twist.covariance.fill( 99999.9 );
	}

	publisher_odometry->publish(odom);
}

void Odometry::publish_transform( rclcpp::Time current_time ) {
	odom_trans.header.stamp = current_time;
	odom_trans.header.frame_id = odom.header.frame_id;
	odom_trans.child_frame_id  = odom.child_frame_id;

	odom_trans.transform.translation.x = odom.pose.pose.position.x;
	odom_trans.transform.translation.y = odom.pose.pose.position.y;
	odom_trans.transform.translation.z = odom.pose.pose.position.z;
	odom_trans.transform.rotation 	   = odom.pose.pose.orientation;
	
	odom_broadcaster_->sendTransform(odom_trans);
}


Odometry::Odometry(bool _publish_tf) : Node("odometry_node"), publish_tf(_publish_tf) {
	if(publish_tf) {
		RCLCPP_INFO(rclcpp::get_logger("Volksbot"), "With odometry tf");
	} else {
		RCLCPP_INFO(rclcpp::get_logger("Volksbot"), "Without odometry tf");
	}

	// create ROS2 subscriber and publisher
	publisher_odometry = this->create_publisher<nav_msgs::msg::Odometry>( VB::TOPIC_NAME_ODOMETRY, 100 );
	subscriber_ticks = this->create_subscription<VB::msg::MCTicks>( VB::TOPIC_NAME_TICKS, 20, std::bind( &Odometry::convertTicks2Odom, this, _1 ) );
	subscriber_rover = this->create_subscription<VB::msg::Rover>( VB::TOPIC_NAME_ROVER, 10, std::bind( &Odometry::set_rover, this, _1 ) );

	// create ROS2 broadcaster
	odom_broadcaster_ = std::make_shared<tf2_ros::TransformBroadcaster>(*this);  

	// initilize variables
	x = 0;
	z = 0;
	theta = 0;
	vx = 0;
	vth = 0;
	firstticks = true;
	active_rover.is_valid = false;
	
	// message frames
	odom.header.frame_id = "odom_combined";
	odom.child_frame_id  = "base_link";

	// create quaternion with yaw = 0
	tf2::Quaternion odom_quat;
	odom_quat.setRPY(0,0,0);

	// set the pose
	odom.pose.pose.position.x  = 0.0;
	odom.pose.pose.position.y  = 0.0;
	odom.pose.pose.position.z  = 0.0;
	odom.pose.pose.orientation = tf2::toMsg(odom_quat); //create Quaternion Msg
	odom.pose.covariance = global_covariance;

	//set the velocity
	odom.twist.twist.linear.x  = 0.0;
	odom.twist.twist.linear.y  = 0.0;
	odom.twist.twist.linear.z  = 0.0;
	odom.twist.twist.angular.x = 0.0;
	odom.twist.twist.angular.y = 0.0;
	odom.twist.twist.angular.z = 0.0;
	odom.twist.covariance = global_covariance;
}

Odometry::~Odometry() {
	//fclose(file);
}


void Odometry::set_rover( VB::msg::Rover::ConstSharedPtr rover ) {
	active_rover = *rover;
}

void Odometry::convertTicks2Odom( VB::msg::MCTicks::ConstSharedPtr cticks ) {
	if( !active_rover.is_valid ) {
		return;
	}

	if( firstticks ) {
		firstticks = false;
		last_ticks_left  = cticks->left;
		last_ticks_right = cticks->right;
		return;
	}
	

	// Core Odometry Implementation
	//-------------------------------

	// state constants
	const double M = cticks->cm_per_tick;       // cm / tick
	const double B = active_rover.wheel_base;   // cm

	// timing variable
	rclcpp::Time current = cticks->header.stamp; 
	rclcpp::Duration duration = current - last_time;
	
	// delta state
	double dt = duration.seconds();

	int dleft  = cticks->left  - last_ticks_left;   // delta ticks left
	int dright = cticks->right - last_ticks_right;  // delta ticks right
	
	double dth = M * ( dright - dleft ) / B;              // delta theta  in radian
	double dx  = M * ( dright + dleft ) / 2.0 / M_TO_CM;  // delta linear in m
	
	// position propagation
	theta += dth;
	x += cos(theta) * dx;
	z -= sin(theta) * dx;

	// store state
	last_time  = current;
	last_ticks_left  = cticks->left;
	last_ticks_right = cticks->right;
	

	// Odometry and Transform management
	//------------------------------------

	publish_odom( current, dt, dx, dth );

	if(publish_tf) {
		publish_transform( current );
	}

	// spin for ros message management
	rclcpp::spin_some( this->get_node_base_interface() );
}


// was ist das für eine Update Funktion
// die ergibt mit dem neuen ROS wenig Sinn und das Ganze sollte angepasst werden
void Odometry::update(int rate) {
	rclcpp::Rate loop_rate(rate);

	while (rclcpp::ok()) {
		if( !active_rover.is_valid ) {
			loop_rate.sleep();
			continue;
		}

		rclcpp::Time current = this->get_clock()->now();
		odom.header.stamp = current;

		publisher_odometry->publish(odom);
	
		if( publish_tf ) {
			odom_trans.header.stamp = current;
			odom_broadcaster_->sendTransform(odom_trans);
		}

		// TODO: Check if spin_some() is fine, else test with spin() or spin_all()
		// spin the callbacks from node (pointer to odometry node object)
		rclcpp::spin_some( this->get_node_base_interface() );
		loop_rate.sleep();
	}

}

}
