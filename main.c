// #pragma config(Sensor, in1,    sharp_1,        sensorAnalog)
// #pragma config(Sensor, in2,    sharp_2,        sensorAnalog)
// #pragma config(Sensor, in3,    sharp_3,        sensorAnalog)
// #pragma config(Sensor, in4,		 sharp_4,        sensorAnalog)
// #pragma config(Sensor, in5,    Analog_5,       sensorAnalog)
// #pragma config(Sensor, in6,    Analog_6,       sensorAnalog)
// #pragma config(Sensor, in7,    Analog_7,       sensorAnalog)
// #pragma config(Sensor, in8,    Analog_8,       sensorAnalog)
// #pragma config(Sensor, dgtl1,  line_ss_1,      sensorDigitalIn)
// #pragma config(Sensor, dgtl2,  line_ss_2,      sensorDigitalIn)
// #pragma config(Sensor, dgtl3,  line_ss_3,      sensorDigitalIn)
// #pragma config(Sensor, dgtl4,  line_ss_4,      sensorDigitalIn)
// #pragma config(Sensor, dgtl5,  encoder_1,      sensorQuadEncoder)
// #pragma config(Sensor, dgtl7,  encoder_2,      sensorQuadEncoder)
// #pragma config(Sensor, dgtl9,  north,          sensorDigitalIn)
// #pragma config(Sensor, dgtl10, east,           sensorDigitalIn)
// #pragma config(Sensor, dgtl11, south,          sensorDigitalIn)
// #pragma config(Sensor, dgtl12, west,           sensorDigitalIn)
// #pragma config(Motor,  port2,  rightMotor,     tmotorServoContinuousRotation, openLoop, reversed)
// #pragma config(Motor,  port3,  leftMotor,      tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port2,  leftMotor,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,  rightMotor,  tmotorVex393_MC29, openLoop)

#include "main.h"

const int MAX_BALLS = 3;
const int APPROACH_TIME = 5000;  // Time in milliseconds to approach the target area

task main()
{
  int ball_picked_count = 0;

  State current_state = IDLE;
  
  while (1)
  {
    switch (current_state)
    {
      /*
       * Initialization state, waiting for user signal to start
       * Possible state changes: APPROACHING_TARGET_AREA
       */ 
      case IDLE:
        if (/* user starts the robot */0)
        {
          current_state = APPROACHING_TARGET_AREA;
        }
        break;
      
      /*
       * Approaching state, moving towards the detected ball for a set amount of time
       * Possible state changes: SEARCHING
       */
      case APPROACHING_TARGET_AREA:
        if (/* moved a set time */0)
        {
          current_state = SEARCHING;
        }
        break;

      /*
       * Searching state, looking for the ball using IR sensors and spinning in place
       * Possible state changes: COLLECTING
       */
      case SEARCHING:
        // Some logic to spin robot
        if (classify_object() == 1)
        {
          current_state = COLLECTING;
        }
        break;
        
      /*
       * Collecting state, activating mechanism to collect the ball
       * Possible state changes: NAVIGATING_TO_DEPOSIT
       */
      case COLLECTING:
        collect_ball();
        current_state = NAVIGATING_TO_DEPOSIT;
        break;
        
      /*
       * Navigating back to deposit state (can possibly just crash into the back)
       * Possible state changes: DEPOSITING
       */
      case NAVIGATING_TO_DEPOSIT:
        // Navigate to deposit area
        // TODO: Implement navigation logic
        if (/* reached deposit area */0)
        {
          current_state = DEPOSITING;
        }
        break;
        
      /*
       * Depositing state, dropping the ball in the deposit area
       * Possible state changes: IDLE, APPROACHING_TARGET_AREA
       */
      case DEPOSITING:
        // Drop the ball
        deposit_ball();
        ball_picked_count++;

        if (ball_picked_count >= MAX_BALLS)
        {
          current_state = IDLE;  // Return to idle after depositing all balls
        }
        else
        {
          current_state = APPROACHING_TARGET_AREA;  // Move to next ball
        }
        break;
        
      default:
        current_state = IDLE;
        break;
    }
    
    wait1Msec(10);  // Small delay to prevent overwhelming the processor
  }
}
