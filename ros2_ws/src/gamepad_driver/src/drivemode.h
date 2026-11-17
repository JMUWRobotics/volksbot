#ifndef __DRIVEMODE_H__
#define __DRIVEMODE_H__

enum drive_mode_t { STICK_DRIVE, PADDLE_DRIVE, TANK_DRIVE, COUNT };
static constexpr const char* drive_mode_str[drive_mode_t::COUNT+1] = { "STICK_DRIVE", "PADDLE_DRIVE", "TANK_DRIVE", "ERROR" };

#endif