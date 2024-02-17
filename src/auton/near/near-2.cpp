#include "autonomous.h"
#include "parameters.h"
#include "my-timer.h"
#include "robot-config.h"
#include "GPS.h"

/**
 * Near 2: Elim: rush center, 0 goal, 4 over
 * 1. Get center triball
 * 2. Get corner triball
 * 3. Push triballs over barrier
 * 4. 
*/

void near_2() {
  MyTimer autotimer;
  autotimer.reset();
 
  printf ("\n===== near_2: Start =====\n");

  //rush to intake center ball
  setIntakeSpeed(100);
  MyGps.gpsPIDMove(0, 1200, 1);
  this_thread::sleep_for(600);
  setIntakeSpeed(0);

  printf ("===== MyGps.gpsPIDMove: Move to near starting position =====\n");
  MyGps.gpsPIDMove(-275, 275, -1);
  MyGps.gpsPIDMove(-600, 300, -1);
  PIDAngleRotateAbs(170);
  printf ("===== MyGps.gpsPIDMove: Get corner tribal =====\n");
  PIDPosCurveAbs(230, 500, 20);
  setPistonFW(true);
  this_thread::sleep_for(400);
  PIDPosCurveAbs(300, 525, 30);
  setPistonFW(false);
  printf ("===== MyGps.gpsPIDMove: Push balls across alley=====\n");
  timerForward(100, 275);
  setIntakeSpeed(-100);
  this_thread::sleep_for(800); 
  setIntakeSpeed(0);
  //go to triangle
  MyGps.gpsPIDMove(-330, -30, -1);
  PIDAngleRotateAbs(110);
  timerForward(-65, 125);
  setPistonBW(true);

  printf ("\n===== near_2: End: Elased=%.i =====\n", autotimer.getTime());
  
  Brain.Screen.setCursor(11, 1);
  Brain.Screen.print("AutonTimer: %d               ", autotimer.getTime());
}

void near_2_dif_ending() {
  MyTimer autotimer;
  autotimer.reset();
 
  printf ("\n===== near_2: Start =====\n");

  //rush to intake center ball
  setIntakeSpeed(100);
  MyGps.gpsPIDMove(0, 1200, 1);
  this_thread::sleep_for(600);
  setIntakeSpeed(0);

  printf ("===== MyGps.gpsPIDMove: Move to near starting position =====\n");
  MyGps.gpsPIDMove(-275, 275, -1);
  MyGps.gpsPIDMove(-600, 300, -1);
  PIDAngleRotateAbs(170);
  printf ("===== MyGps.gpsPIDMove: Get corner tribal =====\n");
  PIDPosCurveAbs(230, 500, 20);
  setPistonFW(true);
  this_thread::sleep_for(400);
  PIDPosCurveAbs(300, 525, 30);
  setPistonFW(false);
  printf ("===== MyGps.gpsPIDMove: Push balls across alley=====\n");
  timerForward(100, 350);
  setIntakeSpeed(-100);
  this_thread::sleep_for(800); 
  setIntakeSpeed(0);

  // go to triangle
  // MyGps.gpsPIDMove(-330, -30, -1);
  // PIDAngleRotateAbs(120);
  // timerForward(-65, 150);
  // setPistonBW(true);

  printf ("\n===== near_2: End: Elased=%.i =====\n", autotimer.getTime());
  
  Brain.Screen.setCursor(11, 1);
  Brain.Screen.print("AutonTimer: %d               ", autotimer.getTime());
}