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
