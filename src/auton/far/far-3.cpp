#include "autonomous.h"
#include "parameters.h"
#include "my-timer.h"
#include "robot-config.h"
#include "GPS.h"

/**
 * Far 3: ? goal
 * //Center Rush
*/
void far_3() {

  MyTimer autotimer;
  autotimer.reset();

  //get center triball (1st green ball)
  setIntakeSpeed(100);
  MyGps.gpsPIDMove(0, 1250, 1);

  //go back to starting point and outtake 1st ball
  MyGps.gpsPIDMove(-75, -250, -1);
  PIDAngleRotateAbs(75);
  setIntakeSpeed(-100);
  this_thread::sleep_for(400);
  setIntakeSpeed(0);

  //get ball under pole (2nd green ball)
  // PIDAngleRotateAbs(-65);
  setIntakeSpeed(100);
  MyGps.gpsPIDMove(-900, 200, 1);
  this_thread::sleep_for(400);

  //push in first, second, and third (in triangle) and alliance balls
  MyGps.gpsPIDMove(50, -250, 1); 
  PIDAngleRotateAbs(75);
  setPistonFW(true);
  this_thread::sleep_for(400);
  MyGps.gpsPIDMove(350, -100, 1);
  PIDPosCurveAbs(300, 525, 30);
  PIDAngleRotateAbs(50);

  //to be edited
  timerForward(75, 250);
  PIDAngleRotateAbs(-87);
  timerForward(100, 400);
  timerForward(-100, 100);
  PIDAngleRotateAbs(87);
  setIntakeSpeed(-100);
  PIDAngleRotateAbs(95);
  timerForward(-100, 300);
  setIntakeSpeed(0);
  timerForward(95, 250);
  

  Brain.Screen.setCursor(11, 1);
  Brain.Screen.print("AutonTimer: %d               ", autotimer.getTime());
}