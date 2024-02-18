#include "autonomous.h"
#include "parameters.h"
#include "my-timer.h"
#include "robot-config.h"
#include "GPS.h"

/**
 * Near 1: AWP: 1 goal, 2 over
 * 1. Push allowance triball into goal
 * 2. Get corner triball
 * 3. Push triballs over barrier
 * 4. Touch horizontal bar
*/

void near_1() {

  MyTimer autotimer;
  autotimer.reset();
  printf ("\n===== near_1: Start =====\n");

  //rush to intake center ball
  setIntakeSpeed(100);
  MyGps.gpsPIDMove(0, 300, 1);
  MyGps.gpsPIDMove(300, 1225, 1);
  //can make all the intakes 300 with new robot
  this_thread::sleep_for(600);
  setIntakeSpeed(0);
  MyGps.gpsPIDMove(275, 1100, -1);

  //drop off middle ball
  MyGps.gpsPIDMove(25, 345, 1);
  PIDAngleRotateAbs(-218);
  setIntakeSpeed(-80);
  this_thread::sleep_for(400);
  setIntakeSpeed(0);

  // Push alliance triball into goal
  //note: gps is very off on old robot, fix next few lines
  setIntakeSpeed(100);
  // PIDAngleRotateAbs(-145);
  MyGps.gpsPIDMove(-75, 215, 1);
  this_thread::sleep_for(600);
  setIntakeSpeed(0);
  MyGps.gpsPIDMove(-500, 500, 1, 50);
  MyGps.gpsPIDMove(-500, 615, 1, 25);
  setIntakeSpeed(-100);
  this_thread::sleep_for(400);
  setIntakeSpeed(0);

  //get corner triball
  MyGps.gpsPIDMove(-515, 530, -1, 100);
  PIDAngleRotateAbs(180);
  PIDPosCurveAbs(200, 480, 50);
  //setPistonFW(true);
  this_thread::sleep_for(400);
  PIDPosCurveAbs(275, 515, 50);
  this_thread::sleep_for(500);
  //setPistonFW(false);

  // Push triballs over alley and touch horizontal bar
  setIntakeSpeed(-100);
  MyGps.gpsPIDMove(690, -15, 1);
  this_thread::sleep_for(500);

  printf ("\n===== near_1: End: Elased=%.i =====\n", autotimer.getTime());
  Brain.Screen.setCursor(11, 1);
  Brain.Screen.print("AutonTimer: %d               ", autotimer.getTime());
}


void near_1_comp() {

  MyTimer autotimer;
  autotimer.reset();
  printf ("\n===== near_1: Start =====\n");

  // Push alliance triball into goal
  MyGps.gpsPIDMove(-500, 350, 1, 50);
  MyGps.gpsPIDMove(-500, 570, 1, 25);
  setIntakeSpeed(-100);
  this_thread::sleep_for(600);
  setIntakeSpeed(0);

  //get corner triball
  MyGps.gpsPIDMove(-515, 530, -1, 100);
  PIDAngleRotateAbs(180);
  PIDPosCurveAbs(200, 480, 18);
  setPistonFW(true);
  this_thread::sleep_for(400);
  PIDPosCurveAbs(270, 515, 45);
  this_thread::sleep_for(500);
  setPistonFW(false);

  // Push triballs over alley and touch horizontal bar
  setIntakeSpeed(-100);
  MyGps.gpsPIDMove(690, -85, 1);
  this_thread::sleep_for(1000);

  printf ("\n===== near_1: End: Elased=%.i =====\n", autotimer.getTime());

  Brain.Screen.setCursor(11, 1);
  Brain.Screen.print("AutonTimer: %d               ", autotimer.getTime());
}


