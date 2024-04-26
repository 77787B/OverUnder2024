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

void near_2(bool isRush) {
  MyTimer autotimer;
  autotimer.reset();
  printf ("\n===== near_2: Start =====\n");

  // ## Rush to intake center ball
  setIntakeSpeed(100);
  float forwardTarget = 1215;
  // float forwardTarget = 1215;
  // float forwardTarget = 1230;
  if (isRush == false) {
    forwardTarget = 900;
  } 
  PIDPosForwardAbs(forwardTarget);
  this_thread::sleep_for(300);
  setIntakeSpeed(0);

  // ## Drop off center ball
  PIDAngleRotateAbs(-2);
  resetForwardPos();
  PIDPosForwardAbs(30 - forwardTarget);
  PIDAngleRotateAbs(110);
  setIntakeSpeed(-100);
  this_thread::sleep_for(400);

  // ## Intake alliance triball
  PIDAngleRotateAbs(233);
  setIntakeSpeed(100);
  PIDPosForwardAbs(175);
  this_thread::sleep_for(300);
  setIntakeSpeed(0);

  // ## Outtake alliance triball into goal
  PIDAngleRotateAbs(-60);
  PIDPosForwardAbs(570, 100, 700);
  PIDAngleRotateAbs(-15);
  PIDPosForwardAbs(140, 100, 300);
  setIntakeSpeed(-100);
  this_thread::sleep_for(500);
  // setIntakeSpeed(0);
  // this_thread::sleep_for(100);

  // ## Get corner triball
  PIDPosForwardAbs(-45);
  PIDAngleRotateAbs(-63);
  setPistonBLW(true);
  this_thread::sleep_for(100);
  PIDPosForwardAbs(-260, 100, 400);
  // PIDAngleRotateAbs(-85);
  setPistonBLW(false);
  this_thread::sleep_for(100);

  // ## Push triballs over alley and touch horizontal bar
  // Back up a bit before rotate to prevent hitting the corner triball back into corner
  resetForwardPos();
  PIDPosForwardAbs(200);
  PIDAngleRotateAbs(120);
  setIntakeSpeed(-100);
  setPistonFW(true);
  this_thread::sleep_for(100);

  // PIDPosForwardAbs(400, 100, 700);
  PIDPosCurveAbs(450, 750, 25); // use curve is safer then move forward.
  // PIDPosCurveAbs(400, 700, 25);
  // PIDPosCurveAbs(650, 850, 25);
  PIDAngleRotateAbs(76);
  setPistonFLW(false);
  this_thread::sleep_for(50);
  PIDPosForwardAbs(715);
  setPistonFW(false);
  // this_thread::sleep_for(500);

  printf ("\n===== near_2: End: Elased=%.i =====\n", autotimer.getTime());
  Brain.Screen.setCursor(11, 1);
  Brain.Screen.print("AutonTimer: %d               ", autotimer.getTime());
}
