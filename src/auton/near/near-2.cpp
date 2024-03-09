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
  MyGps.gpsPIDMove(-180, -100, 1, 20);
  // this_thread::sleep_for(100);
  setIntakeSpeed(0);
  MyGps.gpsPIDMove(-600, 200, 1, 50);
  MyGps.gpsPIDMove(-645, 390, 1, 20);
  setIntakeSpeed(-100);
  this_thread::sleep_for(500);
  setIntakeSpeed(0);

  // ## Get corner triball
  MyGps.gpsPIDMove(-600, 175, -1);
  PIDAngleRotateAbs(-45);
  setPistonBW(true);
  this_thread::sleep_for(100);
  MyGps.gpsPIDMove(-300, -118, -1, 50);
  setPistonBW(false);
  this_thread::sleep_for(100);
  PIDAngleRotateAbs(85);
  setPistonFRW(true);
  MyGps.gpsPIDMove(-65, -135, 1, 40);

  // ## Push triballs over alley and touch horizontal bar
  setIntakeSpeed(-100);
  MyGps.gpsPIDMove(615, 0, 1, 100);
  // setPistonFRW(false);
  // this_thread::sleep_for(200);

  printf ("\n===== near_2: End: Elased=%.i =====\n", autotimer.getTime());
  Brain.Screen.setCursor(11, 1);
  Brain.Screen.print("AutonTimer: %d               ", autotimer.getTime());
}

