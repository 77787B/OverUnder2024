#include "autonomous.h"
#include "parameters.h"
#include "my-timer.h"
#include "robot-config.h"
#include "GPS.h"

/**
 * Far 2: ? goal
 * //Center Rush
*/
void far_2() {

  MyTimer autotimer;
  autotimer.reset();

  setPistonFW(true);
  this_thread::sleep_for(400);
  setPistonFW(false);

  //get center triball (1st green ball)
  setIntakeSpeed(100);
  MyGps.gpsPIDMove(-50, 1300, 1);
  this_thread::sleep_for(600);
  setIntakeSpeed(0);

  //go back to starting point and outtake 1st ball
  MyGps.gpsPIDMove(0, -100, -1);
  PIDAngleRotateAbs(75);
  setIntakeSpeed(-75);
  this_thread::sleep_for(550);
  setIntakeSpeed(0);

  //get ball under pole (2nd green ball)
  // PIDAngleRotateAbs(-65);
  setIntakeSpeed(100);
  MyGps.gpsPIDMove(-715, 75, 1);
  this_thread::sleep_for(400);

  //push in first, second, and third (in triangle) and alliance balls
  MyGps.gpsPIDMove(75, -100, -1); 
  PIDAngleRotateAbs(75);
  setPistonFW(true);
  this_thread::sleep_for(400);
  timerForward(100, 200);
  // MyGps.gpsPIDMove(200, -100, 1);
  PIDPosCurveAbs(400, 750, 30);
  setPistonFW(false);
  timerForward(100, 200);
  PIDAngleRotateAbs(20);
  timerForward(100, 500);
  timerForward(-100, 150);
  PIDAngleRotateAbs(15);
  setIntakeSpeed(-100);
  this_thread::sleep_for(450);
  timerForward(100, 350);
  setIntakeSpeed(0);
  timerForward(-100, 200);

  //get fourth green ball and drop it off next to goal
  setIntakeSpeed(100);
  this_thread::sleep_for(400);
  MyGps.gpsPIDMove(-475, 475, 1);
  timerForward(-100, 200);
  MyGps.gpsPIDMove(75, 850, -1);
  PIDAngleRotateAbs(90);
  setIntakeSpeed(-75);
  this_thread::sleep_for(400);
  setIntakeSpeed(0);

  return;
  //get fifth green ball and push in 4th and 5th green balls
  setIntakeSpeed(100);
  MyGps.gpsPIDMove(-400, 1300, 1);
  this_thread::sleep_for(400);
  setIntakeSpeed(0);
  MyGps.gpsPIDMove(50, 1100, -1);
  PIDAngleRotateAbs(100);
  setIntakeSpeed(-100);
  setPistonFW(true);
  this_thread::sleep_for(400);
  timerForward(100, 300);
  setIntakeSpeed(0);
  setPistonFW(false);
  timerForward(-100, 300);
  Brain.Screen.setCursor(11, 1);
  Brain.Screen.print("AutonTimer: %d               ", autotimer.getTime());
}
