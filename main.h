#include "low_level_controls.h"

void loop();

// Return 0 for nothing, 1 for ball, 2 for robot
// Used for front facing IR sensors
int classify_object()
{
  return 0;
}

// Return 0 if no line detected, or an int corresponding to the index of one of the line detectors
// Used for down-facing line detector
int detect_line()
{
  return 0;
}

// Action to collect ball
void collect_ball()
{
  return;
}

// Action to drop ball in deposit area
void deposit_ball()
{
  return;
}

// Action to align to deposit area using compass
void align_to_deposit_area()
{
  return;
}

// Go back to starting point
void go_home()
{
  return;
}