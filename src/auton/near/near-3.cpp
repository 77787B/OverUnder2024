#include "autonomous.h"
#include "parameters.h"
#include "my-timer.h"
#include "robot-config.h"
#include "GPS.h"

void printElased(MyTimer autotimer) {
  printf ("\n===== near_3: End: Elased=%.i =====\n", autotimer.getTime());
  Brain.Screen.setCursor(11, 1);
  Brain.Screen.print("AutonTimer: %d               ", autotimer.getTime());
}

/**
 * Near 3: Elim: rush center, 1 goal, 3 over
 * 1. Get center triball
 * 2. Get middle barrier triball
 * 3. Get corner triball
 * 3. Push triballs over barrier
 * 4. Push alliance triball into goal
*/

void near_3_() {
  MyTimer autotimer;
  autotimer.reset();
 
  printf ("\n===== near_3: Start =====\n");

  MyGps.gpsPIDMove(0, 200, 1, 50);
  setPistonBW(true);
  this_thread::sleep_for(100);
  PIDAngleRotateAbs(90);
  MyGps.gpsPIDMove(610, 266, 1, 50);
  MyGps.gpsPIDMove(670, -156, 1, 50);
  // MyGps.gpsPIDMove(1035, -356, 1, 50);
  MyGps.gpsPIDMove(1090, -240, 1, 50);


  printf ("\n===== near_3: End: Elased=%.i =====\n", autotimer.getTime());
  Brain.Screen.setCursor(11, 1);
  Brain.Screen.print("AutonTimer: %d               ", autotimer.getTime());
}

void near_3() {
  MyTimer autotimer;
  autotimer.reset();
  printf ("\n===== near_3: Start =====\n");

  // ## Rush to intake center ball
  setIntakeSpeed(100);
  MyGps.gpsPIDMove(0, 1200, 1, 100);
  this_thread::sleep_for(300);
  setIntakeSpeed(0);

  // ## Get middle barrier triball
  // ### It's very hard to keep the triball stable and not rotate away
  MyGps.gpsPIDMove(250, 1250, 1, 50);
  setPistonBW(true);
  this_thread::sleep_for(50);
  MyGps.gpsPIDMove(375, 1100, 1, 20);
  this_thread::sleep_for(1000);

  // ## Drop off middle barrier triball
  MyGps.gpsPIDMove(300, 1185, -1, 20);
  // this_thread::sleep_for(1000);
  PIDAngleRotateAbs(175);
  this_thread::sleep_for(1000);
  MyGps.gpsPIDMove(150, 800, 1, 20);
  MyGps.gpsPIDMove(-51, 181, 1, 30);
  this_thread::sleep_for(1000);
  MyGps.gpsPIDMove(100, -150, 1, 30);
  this_thread::sleep_for(1000);
  setPistonBW(false);
  this_thread::sleep_for(50);

  // ## Get corner triball
  MyGps.gpsPIDMove(-400, 50, -1, 50);
  PIDAngleRotateAbs(-45);
  setPistonBW(true);
  this_thread::sleep_for(50);
  MyGps.gpsPIDMove(-140, -186, -1, 50);
  setPistonBW(false);

  // ## Push all triballs over alley

  // might need to move back to produce more stable results
  // MyGps.gpsPIDMove(-350, 86, -1, 50);
  // PIDAngleRotateAbs(45);

  PIDAngleRotateAbs(90);
  setPistonFW(true);
  this_thread::sleep_for(50);
  MyGps.gpsPIDMove(86, -183, 1, 50);
  PIDAngleRotateAbs(75);
  setIntakeSpeed(-100);
  this_thread::sleep_for(50);
  MyGps.gpsPIDMove(758, 0, 1);
  this_thread::sleep_for(100);

  printElased(autotimer);
}
