#include "autonomous.h"
#include "parameters.h"
#include "my-timer.h"
#include "robot-config.h"
#include "GPS.h"

/**
 * Near 2: AWP: rush center, 1 goal, 2 over
 * 1. Get center triball
 * 2. Push alliance triball into goal
 * 3. Get corner triball
 * 4. Push triballs over alley
*/

void near_2() {
  MyTimer autotimer;
  autotimer.reset();
  printf ("\n===== near_2: Start =====\n");

  // ## Rush to intake center ball
  setIntakeSpeed(100);
  MyGps.gpsPIDMove(0, 1250, 1, 100);
  this_thread::sleep_for(300);
  setIntakeSpeed(0);

  // ## Drop off center ball
  MyGps.gpsPIDMove(-15, 200, -1, 100);
  PIDAngleRotateAbs(115);
  setIntakeSpeed(-80);
  this_thread::sleep_for(400);
  setIntakeSpeed(0);

  // ## Push alliance triball into goal
  setIntakeSpeed(100);
  // PIDAngleRotateAbs(-145);
  MyGps.gpsPIDMove(-180, -100, 1, 20);
  this_thread::sleep_for(300);
  setIntakeSpeed(0);
  MyGps.gpsPIDMove(-600, 150, 1, 100);
  MyGps.gpsPIDMove(-645, 275, 1, 50);
  setIntakeSpeed(-100);
  this_thread::sleep_for(400);
  setIntakeSpeed(0);

  // ## Get corner triball
  MyGps.gpsPIDMove(-600, 175, -1, 100);
  PIDAngleRotateAbs(-60);
  setPistonBW(true);
  this_thread::sleep_for(200);
  MyGps.gpsPIDMove(100, -75, -1, 40);
  setPistonBW(false);
  PIDAngleRotateAbs(75);
  setPistonFW(true);
  // PIDAngleRotateAbs(150);
  // this_thread::sleep_for(100);
  // PIDPosCurveAbs(200, 450, 50);
  // setPistonFRW(true);
  // this_thread::sleep_for(500);
  // PIDPosCurveAbs(275, 515, 50);

  // ## Push triballs over alley and touch horizontal bar
  setIntakeSpeed(-100);
  MyGps.gpsPIDMove(765, 170, 1);
  setPistonFW(false);
  this_thread::sleep_for(200);

  // //go to triangle
  // MyGps.gpsPIDMove(-330, -80, -1);
  // PIDAngleRotateAbs(110);
  // timerForward(-65, 125);
  // setPistonBW(true);

  printf ("\n===== near_2: End: Elased=%.i =====\n", autotimer.getTime());
  Brain.Screen.setCursor(11, 1);
  Brain.Screen.print("AutonTimer: %d               ", autotimer.getTime());
}

