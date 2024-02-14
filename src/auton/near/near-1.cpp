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

  // Push alliance triball into goal
  MyGps.gpsPIDMove(-500, 350 , 1, 50);
  MyGps.gpsPIDMove(-500, 575 , 1, 25);
  setIntakeSpeed(-100);
  this_thread::sleep_for(500);
  setIntakeSpeed(0);
  MyGps.gpsPIDMove(-500, 450 , -1, 25);
  PIDAngleRotateAbs(180);

  // Get corner triball
  setPistonFW(true);
  PIDPosCurveAbs(300, 600, 25);
  setPistonFW(false);
  this_thread::sleep_for(500);
  timerForward(-50, 200);
  PIDAngleRotateAbs(145);
  PIDPosCurveAbs(300, 500, 50);
  PIDAngleRotateAbs(90);

  // Push triballs over alley and touch horizontal bar
  setIntakeSpeed(-100);
  MyGps.gpsPIDMove(600, -150, 1);
  this_thread::sleep_for(1000);

  printf ("\n===== near_1: End: Elased=%.i =====\n", autotimer.getTime());

  Brain.Screen.setCursor(11, 1);
  Brain.Screen.print("AutonTimer: %d               ", autotimer.getTime());
}

void near_1_amy() {

  MyTimer autotimer;
  autotimer.reset();
  printf ("\n===== near_1: Start =====\n");

  MyGps.gpsPIDMove(0, -50, -1);
  setPistonFW(true);
  PIDPosCurveAbs(100, 250, 50);
  setPistonFW(false);
  MyGps.gpsPIDMove(-700, 900, 1);
  setIntakeSpeed(-100);

  printf ("\n===== near_1: End: Elased=%.i =====\n", autotimer.getTime());

  Brain.Screen.setCursor(11, 1);
  Brain.Screen.print("AutonTimer: %d               ", autotimer.getTime());
}

void near_1_ac() {
  MyTimer autotimer;
  autotimer.reset();

  printf ("\n===== near_1: Start =====\n");

  MyGps.gpsPIDMove(0, -50, -1);
  setPistonFW(true);
  PIDPosCurveAbs(100, 250, 50);
  setPistonFW(false);

  // // setPistonRW(true);
  // this_thread::sleep_for(500);
  // // setPistonTB(true);
  // this_thread::sleep_for(500);
  // PIDAngleRotateAbs(-125);
  // this_thread::sleep_for(200);
  // // setPistonTB(false);
  // // setPistonRW(false);
  // this_thread::sleep_for(100);

  // // PIDAngleRotateAbs(90);
  // // PIDPosCurveAbs(650, 400, 50);
  // // timerForward(100, 200);
  // // this_thread::sleep_for(500);

  // // MyGps.gpsPIDMove(-75, -50, -1);
  // PIDAngleRotateAbs(90);
  // timerForward(-50, 230);
  // setIntakeSpeed(-100);
  // MyGps.gpsPIDMove(-600, -515, -1);

  // this_thread::sleep_for(1000);
  // setIntakeSpeed(0);

  printf ("\n===== near_1: End: Elased=%.i =====\n", autotimer.getTime());

  Brain.Screen.setCursor(11, 1);
  Brain.Screen.print("AutonTimer: %d               ", autotimer.getTime());
}
