// =====================================================================================
// 
//       Filename:  calibration.cc
// 
//    Description:  ROS node to publish coordinate transformations between the various robot's coordinate frames
// 
//        Version:  1.0
//        Created:  05/11/2010 07:41:48 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Jan Elseberg (), jelseber@uos.de
//        Company:  Universitaet Osnabrueck
//
//        -----------------------
//        Updated to ROS2
//
//        Author: Maximilian Gmoehling 
//        Company: Universitaet Wuerzburg
//        Date: 2025-03-31
// 
// =====================================================================================
#include "rclcpp/rclcpp.hpp"
#include <tf2_ros/transform_broadcaster.h>
#include <geometry_msgs/msg/transform_stamped.hpp>
#include <tf2/LinearMath/Quaternion.h>

int main(int argc, char** argv){
  rclcpp::init(argc, argv);

  //shared pointer to node
  auto node = rclcpp::Node::make_shared("volksbot_calibration"); 

  // 50Hz loop frequency
  rclcpp::Rate r(50); 

  // create broadcaster for node
  auto broadcaster_ = std::make_shared<tf2_ros::TransformBroadcaster>(node);

  //checks if ROS2 is still running
  while(rclcpp::ok()){ 
    geometry_msgs::msg::TransformStamped transformStamped;
    
    // set header
    transformStamped.header.stamp = node->get_clock()->now();
    transformStamped.header.frame_id = "base_link";
    transformStamped.child_frame_id = "front_laser";

    // 24 cm to the top and 12 to the front
    transformStamped.transform.translation.x = 0.12;
    transformStamped.transform.translation.y = 0.0;
    transformStamped.transform.translation.z = 0.24;

    // identity quaternion
    transformStamped.transform.rotation.x = 0.0;
    transformStamped.transform.rotation.y = 0.0;
    transformStamped.transform.rotation.z = 0.0;
    transformStamped.transform.rotation.w = 1.0;

    broadcaster_->sendTransform(transformStamped);
    r.sleep();
  }
}

