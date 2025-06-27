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

//FILE *file;

namespace volksbot {
// -461.817 ticks to cm
//const double Odometry::M  = -1.0/461.817;
// 44.4 cm is the wheel base
//const double Odometry::B = 44.4;

const double Odometry::covariance[36] = { 0.01, 0, 0, 0, 0, 0,
                                          0, 0.01, 0, 0, 0, 0,
                                          0, 0, 99999, 0, 0, 0,
                                          0, 0, 0, 0.174532925, 0, 0,
                                          0, 0, 0, 0, 9999, 0,
                                          0, 0, 0, 0, 0, 99999};
rclcpp::Time old;

Odometry::Odometry(bool _publish_tf) : Node("odometry_node"), publish_tf(_publish_tf) {
  
  //file = fopen("/tmp/ist.txt", "w");

  if(publish_tf) {
    RCLCPP_INFO(rclcpp::get_logger("Volksbot"), "With odometry tf");
  } else {
    RCLCPP_INFO(rclcpp::get_logger("Volksbot"), "Without odometry tf");
  }

  // create ROS2 subscriber and publisher
  publisher_ = this->create_publisher<nav_msgs::msg::Odometry>("odom", 100);
  subscriber_ = this->create_subscription<volksface::msg::Ticks>("VMC", 20, std::bind(&Odometry::convertTicks2Odom, this, _1));
  
  // create ROS2 broadcaster
  odom_broadcaster_ = std::make_shared<tf2_ros::TransformBroadcaster>(*this);  

  // initilize variables
  x = 0;
  z = 0;
  theta = 0;
  lastvx = 0;
  lastvth = 0;
  firstticks = true;
  
  // message frames
  odom.header.frame_id = "odom_combined";
  odom.child_frame_id = "base_link";

  // create quaternion with yaw = 0
  tf2::Quaternion odom_quat;
  odom_quat.setRPY(0,0,0);

  // set the pose
  odom.pose.pose.position.x = 0.0;
  odom.pose.pose.position.y = 0.0;
  odom.pose.pose.position.z = 0.0;
  odom.pose.pose.orientation = tf2::toMsg(odom_quat); //create Quaternion Msg
  for (int i = 0; i < 36; i++)
    odom.pose.covariance[i] = covariance[i];

  //set the velocity
  odom.twist.twist.linear.x = 0;
  odom.twist.twist.linear.y = 0;
  odom.twist.twist.linear.z = 0;
  odom.twist.twist.angular.x = 0;
  odom.twist.twist.angular.y = 0;
  odom.twist.twist.angular.z = 0;
  for (int i = 0; i < 36; i++)
    odom.twist.covariance[i] = covariance[i];

  //declare and receive ROS2 parameters 
  this->declare_parameter("wheel_base", 44.4);
  this->declare_parameter("ticks_per_cm", -461.817);

  this->get_parameter("wheel_base", B);
  this->get_parameter("ticks_per_cm", M);
  M = 1.0 / M;
}

Odometry::~Odometry() {
//fclose(file);
}

void Odometry::convertTicks2Odom(const volksface::msg::Ticks::ConstSharedPtr& cticks)
{
  if (firstticks) {
    oldlticks = cticks->left;
    oldrticks = cticks->right;
//    oldticks = *cticks;
    firstticks = false;
    return;
  }

  rclcpp::Time current = cticks->header.stamp; 

//  int left = cticks->left - oldticks.left;
//  int right = cticks->right - oldticks.right;
//  long difftime = cticks->timestamp - oldticks.timestamp;
//  oldticks = *cticks;

  int left = cticks->left - oldlticks;
  int right = cticks->right - oldrticks;
  oldlticks = cticks->left;
  oldrticks = cticks->right;
  
  rclcpp::Duration dt = current - old;
  old  = current;


  double ddt = dt.seconds();

  /////////////////
  //double vl = M*left / ddt;
  //double vr = M*right / ddt;
  //fprintf(file, "%f %f %f   %f %d %d \n", current.toSec(), vl*-0.01, vr*-0.01,  ddt, cticks->left, cticks->right );



  double vth = (M*right - M*left) / B;                  // delta theta in radian
  double vx  = ((M*right + M*left)/2.0)/100.0;                // delta x in m
  
  theta += vth;

  x += ((M*right + M*left)/2.0) * cos(theta);
  z -= ((M*right + M*left)/2.0) * sin(theta);

  //since all odometry is 6DOF we'll need a quaternion created from yaw
  tf2::Quaternion odom_quat;
  odom_quat.setRPY(0, 0, -theta);
  
  //next, we'll publish the odometry message over ROS
  //odom.header.stamp = cticks->timestamp;
  odom.header.stamp= current;// no timestamp data TODO
  //set the position
  odom.pose.pose.position.x = x/100.0;
  odom.pose.pose.position.y = z/100.0;
  odom.pose.pose.position.z = 0.0;
  odom.pose.pose.orientation = tf2::toMsg(odom_quat); //create Quaternion Msg from yaw

  for (int i = 0; i < 36; i++)
    odom.pose.covariance[i] = covariance[i];

  double ax = (lastvx-(vx/ddt))/ddt;   // acceleration in cm/s^2
  //double ath = (lastvth-(vth/ddt))/ddt;  // acceleration in rad/s^2
  ax *= 0.01;   // m/s^2
  
  if (ddt > 0 && fabs(ax) < 5.0) {
    lastvx = vx/ddt;
    lastvth = vth/ddt;
    odom.twist.twist.linear.x = vx/ddt;
    odom.twist.twist.linear.y = 0;
    odom.twist.twist.angular.z = -vth/ddt;
    for (int i = 0; i < 36; i++)
      odom.twist.covariance[i] = covariance[i];
  } else {    /// velocities cant be computed, use old values
    for (int i = 0; i < 36; i++)
      odom.twist.covariance[i] = 99999.9; 
  }

  // send odometry message
  publisher_->publish(odom);

  if(publish_tf) {
    rclcpp::Time current_time = this->get_clock()->now();
    odom_trans.header.stamp = current_time;// no timestamp data TODO
    odom_trans.header.frame_id = "odom_combined";
    odom_trans.child_frame_id = "base_link";
  
    odom_trans.transform.translation.x = odom.pose.pose.position.x;
    odom_trans.transform.translation.y = odom.pose.pose.position.y;
    odom_trans.transform.translation.z = odom.pose.pose.position.z;
    odom_trans.transform.rotation = tf2::toMsg(odom_quat);
   
    odom_broadcaster_->sendTransform(odom_trans);
  }

  rclcpp::spin_some( this->get_node_base_interface() );
  //send the transform
}

void Odometry::update(int rate) {
  rclcpp::Rate loop_rate(rate);

  while (rclcpp::ok()) {
    rclcpp::Time current = this->get_clock()->now();
    odom.header.stamp = current;

    publisher_->publish(odom);
  
    if(publish_tf) {
      odom_trans.header.stamp = current;
      odom_broadcaster_->sendTransform(odom_trans);
    }
    //TODO: Check if spin_some() is fine, else test with spin() or spin_all()
    // spin the callbacks from node (pointer to odometry node object)
    rclcpp::spin_some( this->get_node_base_interface() );
    loop_rate.sleep();
  }

}

}
