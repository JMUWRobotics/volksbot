#include "rclcpp/rclcpp.hpp"
#include <chrono>

// service
#define VB_NO_GEOMETRY
#include "volksface/volksbot.h"

#ifdef USE_LOGGING_KEYBOARD
    #undef USE_LOGGING
    #define USE_LOGGING USE_LOGGING_KEYBOARD
#endif

#define LOGGING_NAME "kbcontrol"
#include "volksface/logging.h"

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
