# MA4012 Ball Picking Robot Project

## Overview
An autonomous robot system designed to detect, collect, and deposit balls into designated areas. The robot uses IR sensors for object detection, line detectors for navigation, and a compass for orientation.

## Project Structure
- `main.c` - Main program entry point and loop
- `main.h` - High-level control functions (object detection, ball handling)
- `low_level_controls.h` - Low-level motor and sensor controls

## Features
- **Object Detection**: IR sensors to classify objects (ball vs robot)
- **Line Following**: Down-facing sensors for boundary detection and alignment
- **Ball Collection**: Automated ball pickup mechanism
- **Ball Deposit**: Drops collected balls in designated areas
- **Navigation**: Compass-based orientation and movement control

## Key Functions

### Movement & Navigation
- `move(speed, dir)` - Move forward/backward at specified speed (0-3)
- `rotate(speed, dir)` - Rotate left/right at specified speed (0-3)
- `read_compass()` - Returns current heading (1 of 8 directions)

### Object & Line Detection
- `classify_object()` - Detects objects (0: nothing, 1: ball, 2: robot)
- `detect_line()` - Detects boundary lines with index position

### Ball Handling
- `collect_ball()` - Activates ball collection mechanism
- `deposit_ball()` - Releases ball into deposit area
- `is_ball_collected()` - Checks if ball is currently held

### Utilities
- `reset_all_variables()` - Resets system to default state

## Getting Started
1. Configure motor and sensor ports in the header files
2. Implement the function bodies for each control method
3. Add main logic in the `loop()` function in `main.c`
4. Use the limit switch to start the robot.

## Development Guidelines
- Each team member can work on different functions to minimize merge conflicts
- Test individual functions before integrating
- Document any changes to function signatures or behavior

## Hardware Requirements
- VEX Robotics motors and sensors
- IR sensors for object detection
- Line detectors
- Compass/gyroscope sensor
- Ball collection mechanism
- Limit switch for start trigger

## Contributors
MA4012 Team

---
*Last updated: January 2026*