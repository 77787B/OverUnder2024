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

