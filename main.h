#include "low_level_controls.h"

// State machine states
typedef enum {
  IDLE,
  APPROACHING_TARGET_AREA,
  SEARCHING,
  COLLECTING,
  NAVIGATING_TO_DEPOSIT,
  DEPOSITING,
  RECOVERY_FROM_BOUNDARY
} State;

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

/*
  * Return angles between -180 and 180
  * 0 is north, 90 is east, -90 is west, 180 or -180 is south
  * Increment of 45 degrees for each of the 8 compass directions
  */
int get_current_heading()
{
  bool north = (SensorValue(northPin) == 0);
  bool south = (SensorValue(southPin) == 0);
  bool east = (SensorValue(eastPin) == 0);
  bool west = (SensorValue(westPin) == 0);

  // Implementation for determining heading based on sensor values
  if (north && !east && !south && !west) {
    return 0; // North
  } else if (north && east && !south && !west) {
    return 45; // Northeast
  } else if (!north && east && !south && !west) {
    return 90; // East
  } else if (!north && east && south && !west) {
    return 135; // Southeast
  } else if (!north && !east && south && !west) {
    return 180; // South
  } else if (!north && !east && south && west) {
    return -135; // Southwest
  } else if (!north && !east && !south && west) {
    return -90; // West
  } else if (north && !east && !south && west) {
    return -45; // Northwest
  } else {
    return 0; // Default to North if no valid combination is detected
  }
}