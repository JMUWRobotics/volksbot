#include "logitechf710.h"

// service
#include "volksbot/velocities.h"
#include "volksbot/vels.h"

#include "std_srvs/Empty.h"
#include <math.h>

void LogitechF::handleButton(uint8_t number, bool pressed, uint32_t time) {
  std_srvs::Empty e;
  switch(number) {
    case BUTTON_A:
      ros::service::call("startMeasuring",e);
      break;
    case BUTTON_B:
      ros::service::call("stopMeasuring",e);
      break;
    case BUTTON_X: 
      ros::service::call("setSingle",e);
      //ros::service::call("Shutdown",e);
      break;
    case BUTTON_Y:
      ros::service::call("setContinuous",e);
      break;
    case BUTTON_LEFT:
      if (pressed) {
      speed = fmax(0.0, speed-10.0);
      sendSpeed();
      }
      break;
    case BUTTON_RIGHT:
      if (pressed) {
      ROS_ERROR("FASTER");
      speed = fmin(100.0, speed+10.0);
      sendSpeed();
      }
      break;
    case START:
      if(pressed) {
        ROS_ERROR("START THERMO SCAN");
        ros::service::call("startImageScan",e);
      }
      break;
    case LOGITECH:
      break;
    case BACK:
      break;
    default:
      break;
  }
}

void LogitechF::handleAxis(uint8_t number, int16_t value, uint32_t time) {
  switch(number) {
    case LSTICK_LEFTRIGHT:
      break;
    case LSTICK_UPDOWN:
      if (fabs(value) > STICK_MIN_ACTIVITY) {
        rightvel = ((double)value)/(double)JS_MAX_VALUE;
      } else {
        rightvel = 0;
      }
      sendSpeed();
      break;
    case RSTICK_LEFTRIGHT:
      break;
    case RSTICK_UPDOWN:
      if (fabs(value) > STICK_MIN_ACTIVITY) {
        leftvel = ((double)value)/(double)JS_MAX_VALUE;
      } else {
        leftvel = 0;
      }
      sendSpeed();
      break;
    case THROTTLE_LEFT:
      break;
    case THROTTLE_RIGHT:
      break;
    case HUD_UPDOWN: 
      /*
      if (value > 0) { // down
        leftvel = speed; 
        rightvel = speed; 
      } else if (value < 0) {  //up
        leftvel = -speed; 
        rightvel = -speed; 
      } else {
        leftvel = 0; 
        rightvel = 0; 
      }
      sendSpeed();*/
      break;
    case HUD_LEFTRIGHT:
      /*
      if (value > 0) { // right
        leftvel = speed; 
        rightvel = -speed; 
      } else if (value < 0) {  //left
        leftvel = -speed; 
        rightvel = speed; 
      } else {
        leftvel = 0; 
        rightvel = 0; 
      }
      sendSpeed();
      */
      break;
    default:
      break;
  }
}


void LogitechF::sendSpeed() {
  volksbot::vels velocity;
  velocity.left = leftvel * speed;
  velocity.right = rightvel * speed;
  //ROS_INFO("%f %f SPEED %f \n", leftvel, rightvel, speed);
  publisher.publish(velocity);
}
