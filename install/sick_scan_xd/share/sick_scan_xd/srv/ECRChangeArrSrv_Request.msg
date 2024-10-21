# Definition of ROS service ECRChangeArr for sick_scan_xd
# Request status change of monitoring fields on event
# Example call (ROS1):
# rosservice call /sick_tim_7xx/ECRChangeArr "{active: 1}"
# 

# 
# Request (input)
# 

bool active # start/stop monitoring for status change events

