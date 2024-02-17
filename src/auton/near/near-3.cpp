#include "autonomous.h"
#include "parameters.h"
#include "my-timer.h"
#include "robot-config.h"
#include "GPS.h"

/**
 * Near 3: Elim: rush center, 1 goal, 3 over
 * 1. Get center triball
 * 2. Get corner triball
 * 3. Push triballs over barrier
 * 4. Push allowance triball into goal
*/

void near_3() {
  MyTimer autotimer;
  autotimer.reset();
 
  printf ("\n===== near_3: Start =====\n");

  //rush to intake center (first green) ball
  setIntakeSpeed(100);
  MyGps.gpsPIDMove(0, 1230, 1);
  this_thread::sleep_for(600);
  setIntakeSpeed(0);

  //go back to start and deposit first ball
  MyGps.gpsPIDMove(50, 350, 1);
  setIntakeSpeed(-100);
  this_thread::sleep_for(400);
  setIntakeSpeed(0);
  setIntakeSpeed(100);
  MyGps.gpsPIDMove(-100, 0, 1);
  this_thread::sleep_for(600);
  setIntakeSpeed(0);
  MyGps.gpsPIDMove(-600, 350, 1);
  setIntakeSpeed(-100);
  MyGps.gpsPIDMove(-600, 375, 1);
  this_thread::sleep_for(450);
  setIntakeSpeed(0);

  //get corner triball
  MyGps.gpsPIDMove(-600, 300, -1);
  PIDAngleRotateAbs(170);
  PIDPosCurveAbs(230, 500, 20);
  // setPistonFW(true);
  this_thread::sleep_for(400);
  PIDPosCurveAbs(300, 525, 30);
  // setPistonFW(false);

  //push balls across alley
  timerForward(100, 275);
  setIntakeSpeed(-100);
  this_thread::sleep_for(600); 
  setIntakeSpeed(0);
  // go to triangle
  MyGps.gpsPIDMove(-330, -30, -1);
  // PIDAngleRotateAbs(120);
  // timerForward(-65, 150);
  // setPistonBW(true);

  printf ("\n===== near_3: End: Elased=%.i =====\n", autotimer.getTime());
  
  Brain.Screen.setCursor(11, 1);
  Brain.Screen.print("AutonTimer: %d               ", autotimer.getTime());
}
