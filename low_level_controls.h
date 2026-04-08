// Translate back/forth
// dir is 1 (forward) or -1 (backward)
// speed is pwm value
void move(int speed, int dir)
{
  motor[leftMotor] = dir * speed;
  motor[rightMotor] = dir * (speed + 2);
}

// Rotate left/rigth
// dir is 1 (right) or -1 (left)
// speed is pwm value
void rotate(int speed, int dir)
{
  motor[leftMotor] = dir * speed;
  motor[rightMotor] = -dir * (speed + 2);
}

// Return 8-bit bitmask representing line detection zones
// Bit 0: Front, Bit 1: Front-Right, Bit 2: Right, Bit 3: Back-Right
// Bit 4: Back, Bit 5: Back-Left, Bit 6: Left, Bit 7: Front-Left
// Used for down-facing line detector
int detect_line()
{
  // return (SensorValue(line_ss_1) << 7) |  // Front-Left corner
  //        (SensorValue(line_ss_2) << 1) |  // Front-Right corner
  //        (SensorValue(line_ss_3) << 3) |  // Back-Right corner
  //        (SensorValue(line_ss_4) << 5);   // Back-Left corner
  return 0;
}

int is_ball_detected()
{
  int threshold = 500;
  int result = 0;
  int reading1 = SensorValue(distanceSensor1);
  int reading2 = SensorValue(distanceSensor2);

  if (reading1 > threshold && reading2 < threshold)
    result = -1; // Ball detected by distanceSensor1
  else if (reading1 < threshold && reading2 > threshold)
    result = 1; // Ball detected by distanceSensor2

  return result;
}

bool are_both_distance_sensors_positive()
{
  int threshold = 300;
  int reading1 = SensorValue(distanceSensor1);
  int reading2 = SensorValue(distanceSensor2);
  return reading1 > threshold && reading2 > threshold;  // Threshold value for ball collection confirmation
}

// Return true if collected, false otherwise
bool is_ball_collected()
{
  return true;
}

// Reset all variables to null/default state
void reset_all_variables()
{
}
