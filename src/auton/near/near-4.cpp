#include "autonomous.h"
#include "parameters.h"
#include "my-timer.h"
#include "robot-config.h"
#include "GPS.h"


/**
 * Near 4: Elim: rush center, 1 goal, 4 over
 * 1. Get center triball
 * 2. Disrupt the barrier middle triball // Push barrier middle triball over
 * 3. Get corner triball
 * 4. Push triballs over barrier
 * 5. Push alliance triball into goal
*/

void near_4_() {
  setIntakeSpeed(100);
}

void near_4() {
  MyTimer autotimer;
  autotimer.reset();
  
  printf ("\n===== near_4: Start =====\n");

  //rush to intake center (first green) ball
  setIntakeSpeed(100);
  MyGps.gpsPIDMove(0, 1230, 1);
  this_thread::sleep_for(600);
  setIntakeSpeed(0);

  //release first green ball and get second one
  MyGps.gpsPIDMove(0, 1145, 1);
  PIDAngleRotateAbs(190);
  timerForward(100, 200);
  setIntakeSpeed(-75);
  this_thread::sleep_for(450);
  setIntakeSpeed(0);
  PIDPosCurveAbs(150, 350, -50);
  // PIDAngleRotateAbs(10);
  setIntakeSpeed(100);
  MyGps.gpsPIDMove(300, 1300, 1);
  this_thread::sleep_for(600);

  //get corner triball
  MyGps.gpsPIDMove(-275, 275, -1);
  MyGps.gpsPIDMove(-600, 300, -1);
  PIDAngleRotateAbs(170);
  PIDPosCurveAbs(230, 500, 20);
  // setPistonFW(true);
  this_thread::sleep_for(400);
  PIDPosCurveAbs(300, 525, 30);
  // setPistonFW(false);

  //push balls across alley
  timerForward(100, 275);
  setIntakeSpeed(-100);
  this_thread::sleep_for(600); 
  setIntakeSpeed(0);
  // go to triangle
  MyGps.gpsPIDMove(-330, -30, -1);
  // PIDAngleRotateAbs(120);
  // timerForward(-65, 150);
  // setPistonBW(true);

  printf ("\n===== near_4: End: Elased=%.i =====\n", autotimer.getTime());
}
