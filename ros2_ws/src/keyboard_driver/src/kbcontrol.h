#include "rclcpp/rclcpp.hpp"
#include <chrono>

// service
#define VB_NO_GEOMETRY
#include "volksface/volksbot.h"

namespace volksbot {
  using namespace VB;

  // enable shared pointer to this class
  class kbcontrol : public rclcpp::Node, public std::enable_shared_from_this<kbcontrol> {
    private:

      // declare client and request pointer 
      rclcpp::Client<srv::VelCmd>::SharedPtr client_;
      std::shared_ptr<srv::VelCmd::Request> velocity_;

      double speed_;
      int kfd_;

      void setVelocity(char c);

    public:
      kbcontrol();
      void run();
  };
}
