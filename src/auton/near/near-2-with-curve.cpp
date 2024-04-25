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

void near_2_with_curve(bool isRush) {
  MyTimer autotimer;
  autotimer.reset();
  printf ("\n===== near_2: Start =====\n");

  // ## Rush to intake center ball
  setIntakeSpeed(100);
  float forwardTarget = 1185;
  // float forwardTarget = 1215;
  if (isRush == false) {
    forwardTarget = 800;
  }
  PIDPosForwardAbs(forwardTarget);
  this_thread::sleep_for(300);
  setIntakeSpeed(0);

  // ## Drop off center ball
  resetForwardPos();
  PIDPosForwardAbs(50 - forwardTarget);
  PIDAngleRotateAbs(115);
  // setIntakeSpeed(-80);
  // this_thread::sleep_for(200);
  setIntakeSpeed(-100);
  this_thread::sleep_for(400);

  // ## Intake alliance triball
  PIDAngleRotateAbs(220);
  // PIDAngleRotateAbs(215);
  setIntakeSpeed(100);
  PIDPosForwardAbs(200);
  this_thread::sleep_for(300);
  setIntakeSpeed(0);

  // ## Outtake alliance triball into goal
  PIDAngleRotateAbs(-60);
  PIDPosForwardAbs(575);
  PIDAngleRotateAbs(-18);
  // PIDPosForwardAbs(120, 150);
  PIDPosForwardAbs(120, 100, 200);
  setIntakeSpeed(-100);
  this_thread::sleep_for(1000);
  setIntakeSpeed(0);

  // ## Get corner triball
  PIDPosForwardAbs(-75);
  PIDAngleRotateAbs(-50);
  PIDPosForwardAbs(-340); //
  setPistonBLW(true);
  this_thread::sleep_for(100);

  PIDAngleRotateAbs(-80); // angle too SMALL could have triball landed too close to corner barrier
  // PIDAngleRotateAbs(-110); // angle too HIGH could have the triball go outside of alley
  // PIDAngleRotateAbs(-150);
  setPistonBLW(false);
  this_thread::sleep_for(10);
  PIDAngleRotateAbs(-50);
  PIDPosForwardAbs(100);

  // ## Push triballs over alley and touch horizontal bar
  PIDAngleRotateAbs(120);
  // PIDAngleRotateAbs(100);
  setIntakeSpeed(-100);
  // PIDPosForwardAbs(100);
  this_thread::sleep_for(100);
  setPistonFW(true);
  this_thread::sleep_for(100);
  // PIDPosForwardAbs(100);
  // PIDPosForwardAbs(370);
  // PIDPosForwardAbs(380);
  PIDPosCurveAbs(450, 750, 25);
  // PIDPosCurveAbs(400, 700, 50);
  // PIDPosCurveAbs(650, 850, 50);

  PIDAngleRotateAbs(76);
  setPistonFLW(false);
  this_thread::sleep_for(50);
  // PIDPosForwardAbs(835);
  // PIDPosForwardAbs(800);
  // PIDPosForwardAbs(780);
  PIDPosForwardAbs(700);
  setPistonFW(false);
  this_thread::sleep_for(500);

  printf ("\n===== near_2: End: Elased=%.i =====\n", autotimer.getTime());
  Brain.Screen.setCursor(11, 1);
  Brain.Screen.print("AutonTimer: %d               ", autotimer.getTime());
}
