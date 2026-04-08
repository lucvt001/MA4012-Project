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
void start_ball_collector()
{
  motor[collectorServo] = 200;
}

void stop_ball_collector()
{
  motor[collectorServo] = 0;
}

// Action to drop ball in deposit area
void open_ball_release()
{
  motor[releaseServo] = 127;
  wait1Msec(150); // Wait for the ball to be released before stopping the release mechanism
  motor[releaseServo] = 0;
}

void close_ball_release()
{
  motor[releaseServo] = -127;
  wait1Msec(150); // Wait for the release mechanism to reset before stopping it
  motor[releaseServo] = 0;
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