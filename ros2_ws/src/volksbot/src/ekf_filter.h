#ifndef __EKF_FILTER_H__
#define __EKF_FILTER_H__

#include "my_robot_pose_ekf/odom_estimation.h"
#include <nav_msgs/msg/odometry.hpp>
#include <sensor_msgs/msg/imu.hpp>
#include <geometry_msgs/msg/pose_stamped.hpp>
#include <geometry_msgs/msg/pose_with_covariance_stamped.hpp>

#include <tf/tf.h>    
#include "tf2_ros/buffer.h"
#include "tf2_ros/transform_listener.h"

class ekffilter {
  public:

  ekffilter(tf2_ros::TransformListener *l):
     odom_covariance_(6),
      imu_covariance_(3)
  {
    listener = l;
  }

  /// callback function for odo data
  void addOdom(const nav_msgs::msg::Odometry& odom);
  
  /// callback function for imu data
  void addImu(const sensor_msgs::msg::Imu& imu);


  private:

  void updateHistory();

  // ekf filter
  estimation::OdomEstimation my_filter_;

  // estimated robot pose message to send
//  geometry_msgs::msg::PoseWithCovarianceStamped  output_;

  tf2_ros::TransformListener *listener;

  rclcpp::Time odom_stamp_, imu_stamp_, filter_stamp_;
  tf::Transform odom_meas_, imu_meas_;
  tf2::StampedTransform base_imu_offset;
  MatrixWrapper::SymmetricMatrix odom_covariance_, imu_covariance_;

  tf::Quaternion q;
  tf::Quaternion orientation;

};

#endif
