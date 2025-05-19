#include "rclcpp/rclcpp.hpp"
#include <chrono>

// service
#include <volksbot/srv/velocities.hpp>

namespace volksbot {

  class kbcontrol : public rclcpp::Node, public std::enable_shared_from_this<kbcontrol> {
    private:

      // declare client and request pointer 
      rclcpp::Client<volksbot::srv::Velocities>::SharedPtr client_;
      std::shared_ptr<volksbot::srv::Velocities::Request> velocity_;

      double speed_;
      int kfd_;

      void setVelocity(char c);

    public:
      kbcontrol();
      void run();
  };
}
