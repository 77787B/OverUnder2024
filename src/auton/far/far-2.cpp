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

  setPistonFRW(true);
  this_thread::sleep_for(400);
  setPistonFRW(false);

  //get center triball (1st green ball)
  setIntakeSpeed(100);
  MyGps.gpsPIDMove(-0, 1300, 1);
  this_thread::sleep_for(300);
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
  this_thread::sleep_for(300);
  setIntakeSpeed(0);

  //push in first, second, and third (in triangle) and alliance balls
  // MyGps.gpsPIDMove(75, -100, -1); 
  // PIDAngleRotateAbs(80);
  // setPistonFRW(true);
  // this_thread::sleep_for(400);
  // timerForward(100, 200);
  // PIDPosCurveAbs(400, 750, 30);
  // setPistonFRW(false);
  // timerForward(100, 200);
  // PIDAngleRotateAbs(30);
  // timerForward(100, 300);
  // timerForward(-100, 150);
  // setIntakeSpeed(-100);
  // this_thread::sleep_for(450);
  // PIDAngleRotateAbs(25);
  // timerForward(100, 350);
  // setIntakeSpeed(0);
  // timerForward(-100, 200);
  MyGps.gpsPIDMove(150, -100, -1); 
  PIDAngleRotateAbs(-135);
  setPistonBW(true);
  MyGps.gpsPIDMove(500, 200, -1, 70);
  setPistonBW(false);
  PIDAngleRotateAbs(-120);
  timerForward(-80, 200);
  PIDAngleRotateAbs(-140);
  timerForward(-100, 300);
  timerForward(100, 150);
  MyGps.gpsPIDMove(650, 450, 1);
  PIDAngleRotateAbs(30);
  setIntakeSpeed(-100);
  this_thread::sleep_for(450);
  setIntakeSpeed(0);
  timerForward(-100, 200);

  return;

  //get fourth green ball and drop it off next to goal
  setIntakeSpeed(100);
  MyGps.gpsPIDMove(-430, 1200, 1);
  this_thread::sleep_for(400);
  // timerForward(-100, 100);
  MyGps.gpsPIDMove(75, 1300, 1);
  PIDAngleRotateAbs(90);
  setIntakeSpeed(-80);
  this_thread::sleep_for(400);
  setIntakeSpeed(0);

  //get fifth green ball and push in 4th and 5th green balls
  timerForward(-100, 200);
  setIntakeSpeed(100);
  MyGps.gpsPIDMove(-275, 1750, 1);
  this_thread::sleep_for(400);
  setIntakeSpeed(0);
  MyGps.gpsPIDMove(0, 1600, -1);
  PIDAngleRotateAbs(100);
  setIntakeSpeed(-100);
  setPistonFRW(true);
  setPistonFLW(true);
  this_thread::sleep_for(400);
  timerForward(100, 300);
  setIntakeSpeed(0);
  setPistonFRW(false);
  setPistonFLW(false);
  timerForward(-100, 300);

  Brain.Screen.setCursor(11, 1);
  Brain.Screen.print("AutonTimer: %d               ", autotimer.getTime());
  printf ("\n===== far_1: End: Elased=%.i =====\n", autotimer.getTime());
}
