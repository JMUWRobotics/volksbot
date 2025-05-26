#include "rclcpp/rclcpp.hpp"
#include <chrono>

// service
#include "volksbot_interfaces/srv/velocities.hpp"

namespace volksbot {

  // enable shared pointer to this class
  class kbcontrol : public rclcpp::Node, public std::enable_shared_from_this<kbcontrol> {
    private:

      // declare client and request pointer 
      rclcpp::Client<volksbot_interfaces::srv::Velocities>::SharedPtr client_;
      std::shared_ptr<volksbot_interfaces::srv::Velocities::Request> velocity_;

      double speed_;
      int kfd_;

      void setVelocity(char c);

    public:
      kbcontrol();
      void run();
  };
}
