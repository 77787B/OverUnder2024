#include "autonomous.h"
#include "parameters.h"
#include "my-timer.h"
#include "robot-config.h"
#include "GPS.h"

/**
 * Near 1: AWP: 1 goal, 2 over
 * 1. Get corner triball
 * 2. Push allowance triball into goal
 * 3. Push triballs over barrier
 * 4. Touch horizontal bar
*/

void near_1() {

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
