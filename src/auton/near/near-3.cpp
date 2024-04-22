#include "autonomous.h"
#include "parameters.h"
#include "my-timer.h"
#include "robot-config.h"
#include "GPS.h"

/**
 * Near 3: Elim: rush center, 1 goal, 3 over
 * 1. Get center triball
 * 2. Get barrier middle triball
 * 3. Get corner triball // no time to get this
 * 4. Push triballs over barrier
*/

void near_3() {
  MyTimer autotimer;
  autotimer.reset();
  printf ("\n===== near_3: Start =====\n");

  // ## Rush to intake center ball
  setIntakeSpeed(100);
  PIDPosForwardAbs(1215);

  // ## Push center triball over barrier
  resetForwardPos();
  PIDPosForwardAbs(-100);
  PIDAngleRotateAbs(75);
  
  PIDPosForwardAbs(200);
  setIntakeSpeed(-100);
  this_thread::sleep_for(200);
  setIntakeSpeed(-50);
  this_thread::sleep_for(200);
  setIntakeSpeed(-100);
  this_thread::sleep_for(100);
  resetForwardPos();
  PIDPosForwardAbs(150);
  setPistonBLW(true); // prepare for next step
  this_thread::sleep_for(100);
  setIntakeSpeed(0);

  // ## capture barrier middle triball
  PIDAngleRotateAbs(135);
  this_thread::sleep_for(500);
  PIDPosForwardAbs(-50);
  PIDAngleRotateAbs(180, 30);

  // ## barrier middle triball - prepare safe drop off
  PIDPosForwardAbs(150, 30);
  this_thread::sleep_for(10);
  PIDAngleRotateAbs(195, 20);
  this_thread::sleep_for(10);
  PIDAngleRotateAbs(211, 20);

  // ## Drop off barrier middle triball
  PIDPosForwardAbs(1250);
  setPistonBLW(false);
  this_thread::sleep_for(100);

  // ## Get corner triball
  PIDAngleRotateAbs(45);
  this_thread::sleep_for(100);
  PIDAngleRotateAbs(-35);
  PIDPosForwardAbs(-75);

  setPistonBW(true);
  this_thread::sleep_for(200);
  PIDAngleRotateAbs(-90);
  PIDPosForwardAbs(-480);
  setPistonBW(false);
  this_thread::sleep_for(100);

  // ## Push triballs over alley and touch horizontal bar
  PIDAngleRotateAbs(110);
  setPistonFW(true);
  setIntakeSpeed(-50);
  PIDPosForwardAbs(100);
  setPistonFLW(false);
  PIDAngleRotateAbs(75);
  PIDPosForwardAbs(590);

  printf ("\n===== near_3: End: Elased=%.i =====\n", autotimer.getTime());
  Brain.Screen.setCursor(11, 1);
  Brain.Screen.print("AutonTimer: %d               ", autotimer.getTime());
}