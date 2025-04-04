# same byte layout as the gp_state struct

# Buttons
bool btn_a
bool btn_b
bool btn_x
bool btn_y
bool btn_back
bool btn_start
bool btn_home

# Shoulder Buttons
bool btn_lb
bool btn_rb

# Throttle
int16 lt
int16 rt

# HUD Buttons
# >0 == left or up, <0 == right or down, 0 == none
int16 hud_left_right
int16 hud_up_down

# Thumb Sticks
GpThumbStick thumb_left
GpThumbStick thumb_right