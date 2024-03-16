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

  // ## Rush to intake center triball
  setIntakeSpeed(100);
  MyGps.gpsPIDMove(0, 1250, 1, 100);
  this_thread::sleep_for(300);
  setIntakeSpeed(0);

  // ## Drop off center triball
  MyGps.gpsPIDMove(-15, 200, -1, 100);
  PIDAngleRotateAbs(115);
  setIntakeSpeed(-100);
  this_thread::sleep_for(500);
  setIntakeSpeed(0);

  // ## Get barrier middle triball
  // MyGps.gpsPIDMove(325, 1150, 1, 100); // end up (339, 1135)
  // MyGps.gpsPIDMove(300, 1200, 1, 100); // end up (339, 1135)
  MyGps.gpsPIDMove(365, 1215, 1, 100); // end up (339, 1135)
  // MyGps.gpsPIDMove(345, 1175, 1, 100); // end up (339, 1135)
  // PIDAngleRotateAbs(75);
  PIDAngleRotateAbs(110);
  setPistonBW(true);
  this_thread::sleep_for(50);
  MyGps.gpsPIDMove(375, 1100, 1, 20);
  this_thread::sleep_for(50);

  // MyGps.gpsPIDMove(375, 1100, 1, 20);
  // MyGps.gpsPIDMove(380, 1100, 1, 20);
  // MyGps.gpsPIDMove(345, 1130, 1, 20);

  PIDAngleRotateAbs(165);
  this_thread::sleep_for(10);
  PIDAngleRotateAbs(175);
  this_thread::sleep_for(10);
  PIDAngleRotateAbs(185);
  this_thread::sleep_for(10);

  // MyGps.gpsPIDMove(-206, -7, 1, 100);
  MyGps.gpsPIDMove(-225, -75, 1, 100);
  // ## Get corner triball
  setPistonBW(false);
  setPistonFRW(true);
  this_thread::sleep_for(400);
  PIDAngleRotateAbs(110);
  this_thread::sleep_for(400);
  
  // // ## Push all triballs over alley
  MyGps.gpsPIDMove(50, -150, 1, 50);
  setIntakeSpeed(-100);
  MyGps.gpsPIDMove(690, -100, 1, 100); // If the robot slides when getting alliance tribal, use this.
  printElased(autotimer);
  return;

}