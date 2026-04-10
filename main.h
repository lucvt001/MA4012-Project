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
  motor[collectorServo] = 300;
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
    return -1; // Default to North if no valid combination is detected
  }
}

// Translate back/forth
// dir is 1 (forward) or -1 (backward)
// speed is pwm value
void move(int speed, int dir)
{
  motor[leftMotor] = dir * speed;
  motor[rightMotor] = dir * (speed + 4);
}

// Rotate left/rigth
// dir is 1 (right) or -1 (left)
// speed is pwm value
void rotate(int speed, int dir)
{
  motor[leftMotor] = dir * speed;
  motor[rightMotor] = -dir * (speed);
}

int is_ball_detected()
{
  int threshold = 500;
  int result = 0;
  int reading1 = SensorValue(distanceSensorLeft);
  int reading2 = SensorValue(distanceSensorRight);

  if (reading1 > threshold && reading2 < threshold)
    result = -1; // Ball detected by distanceSensorLeft
  else if (reading1 < threshold && reading2 > threshold)
    result = 1; // Ball detected by distanceSensorRight

  return result;
}