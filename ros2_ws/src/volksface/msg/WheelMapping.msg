# WheelMapping.msg
# Mapping matrix from input wheel speeds (left, right) to physical wheel speed directions
# wheel_out = M * speed_in
# M is a 2x2 matrix: [ [m00, m01], [m10, m11] ]

float32[4] matrix  # row-major order: [ m00, m01, m10, m11 ]