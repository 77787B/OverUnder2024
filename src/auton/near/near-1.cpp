#include "autonomous.h"
#include "parameters.h"
#include "my-timer.h"
#include "robot-config.h"
#include "GPS.h"

/**
 * Near 1: AWP (safe): 1 goal, 1 over
 * 1. Get corner triball
 * 2. Push alliance triball into goal
 * 3. Push other triballs over alley
 * 4. Touch horizontal bar
*/

void near_1() {

  // ## Get corner triball out
  MyGps.gpsPIDMove(0, 75, 1);
  setPistonBW(true);
  this_thread::sleep_for(400);
  MyGps.gpsPIDMove(0, 0, -1, 60);
  setPistonBW(false);

  // ## Push alliance triball into goal
  MyGps.gpsPIDMove(75, 400, 1);
  PIDAngleRotateAbs(45);
  MyGps.gpsPIDMove(200, 555, 1, 40);
  setIntakeSpeed(-100);
  this_thread::sleep_for(500);
  setIntakeSpeed(0);

  // Push remaining triballs over alley and touch horizontal bar
  MyGps.gpsPIDMove(0, -50, -1);
  PIDAngleRotateAbs(145);
  setPistonFW(true);
  this_thread::sleep_for(300);
  setIntakeSpeed(-100);
  MyGps.gpsPIDMove(530, -800, 1);
  setPistonFW(false);
}

void near_1_oldVersionNoRush() {

  MyTimer autotimer;
  autotimer.reset();
  printf ("\n===== near_1: Start =====\n");

  // Push alliance triball into goal
  MyGps.gpsPIDMove(-515, 400, 1, 50);
  MyGps.gpsPIDMove(-515, 580, 1, 25);
  setIntakeSpeed(-100);
  this_thread::sleep_for(600);
  setIntakeSpeed(0);

  //get corner triball
  // MyGps.gpsPIDMove(-530, 515, -1, 50);
  MyGps.gpsPIDMove(-515, 550, -1, 50);
  PIDAngleRotateAbs(185);
  PIDPosCurveAbs(150, 400, 20);
  setPistonFRW(true);
  this_thread::sleep_for(400);
  PIDPosCurveAbs(300, 600, 30);
  this_thread::sleep_for(500);

  // Push triballs over alley and touch horizontal bar
  setIntakeSpeed(-100);
  MyGps.gpsPIDMove(690, -85, 1);
  this_thread::sleep_for(1000);
  setPistonFRW(false);

  printf ("\n===== near_1: End: Elased=%.i =====\n", autotimer.getTime());

  Brain.Screen.setCursor(11, 1);
  Brain.Screen.print("AutonTimer: %d               ", autotimer.getTime());
}


