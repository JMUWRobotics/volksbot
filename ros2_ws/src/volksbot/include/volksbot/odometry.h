#ifndef ODOMETRY_HH
#define ODOMETRY_HH
#include "rclcpp/rclcpp.hpp"

// msgs
#include <geometry_msgs/msg/transform_stamped.hpp>
#include "nav_msgs/msg/odometry.hpp"

// custom msgs
#include <volksbot/msg/ticks.hpp>
#include <volksbot/msg/pose2d.hpp>


#include <tf2_ros/transform_broadcaster.h>
#include <tf2/LinearMath/Quaternion.h>

using std::placeholders::_1;

namespace volksbot {

  class Odometry : public rclcpp::Node{

    public:

      Odometry() : Odometry(false) { };

      Odometry(bool _publish_tf);
      ~Odometry();

      void setTicks(double m) {
        M = 1.0 / m;
      }

      void setWheelBase(double b) {
        B = b;
      }

      void convertTicks2Odom(const volksbot::msg::Ticks::ConstSharedPtr& cticks);

      const nav_msgs::msg::Odometry& getCurrentOdom() {
        return odom;
      }

      void update(int ms);

    private:

      // Declaration of Publisher and Subscriber
      rclcpp::Publisher<nav_msgs::msg::Odometry>::SharedPtr publisher_;
      rclcpp::Subscription<volksbot::msg::Ticks>::SharedPtr subscriber_;

      std::shared_ptr<tf2_ros::TransformBroadcaster> odom_broadcaster_;
      bool firstticks;
      bool publish_tf = false;
      double x,z,theta;

      double lastvx, lastvth;

      int oldlticks, oldrticks;

      // -461.817 ticks to cm
      double M;
      // 44.4 cm is the wheel base
      double B;

      static const double covariance[36];

      nav_msgs::msg::Odometry odom;
      
      geometry_msgs::msg::Quaternion odom_quat; //quaternion rotation
  
      geometry_msgs::msg::TransformStamped odom_trans;
  };
}

#endif
