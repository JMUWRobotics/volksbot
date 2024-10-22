#include "rclcpp/rclcpp.hpp"

// service
#include <volksbot/srv/velocities.hpp>

namespace volksbot {

  class kbcontrol {
    private:

      rclcpp::Node n;
      ros::ServiceClient client;
      volksbot::srv::velocities velocity;
      double speed;
      int kfd;

      void setVelocity(char c);

    public:
      kbcontrol();
      void run();
  };
}
