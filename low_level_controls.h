#pragma config(Motor, port2, rMotor, tmotorServoContinuousRotation, openLoop, reversed)

// Translate back/forth
// dir is 1 (forward) or -1 (backward)
// speed is 0 to 3 (inclusive)
void move(int speed, int dir)
{
  return;
}

// Rotate left/rigth
// dir is 1 (right) or -1 (left)
// speed is 0 to 3 (inclusive)
void rotate(int speed, int dir)
{
  return;
}

// Return an int corresponding to the index of one of the 8 directions
int read_compass()
{
  return 1;
}

// Return true if collected, false otherwise
bool is_ball_collected()
{
  return true;
}

// Reset all variables to null/default state
void reset_all_variables()
{
  return;
}