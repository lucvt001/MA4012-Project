#include "low_level_controls.h"

// State machine states
typedef enum {
  IDLE,
  APPROACHING_TARGET_AREA,
  SEARCHING,
  COLLECTING,
  NAVIGATING_TO_DEPOSIT,
  DEPOSITING
} State;

// Return 0 for nothing, 1 for ball, 2 for robot
// Used for front facing IR sensors
int classify_object()
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