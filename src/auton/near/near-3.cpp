#include "autonomous.h"
#include "parameters.h"
#include "my-timer.h"
#include "robot-config.h"
#include "GPS.h"

/**
 * Near 3: Elim: rush center, 1 goal, 3 over
 * 1. Get center triball
 * 2. Get corner triball
 * 3. Push triballs over barrier
 * 4. Push alliance triball into goal
*/

void near_3() {
  MyTimer autotimer;
  autotimer.reset();
 
  printf ("\n===== near_3: Start =====\n");

  //rush to intake center ball
  setIntakeSpeed(100);
  MyGps.gpsPIDMove(0, -1250, -1);
  // setPistonRW(false);
  this_thread::sleep_for(500);
  setIntakeSpeed(0);

  //push center barrier ball across 
  setPistonFW(true);
  PIDAngleRotateAbs(80);
  // timerForward(100, 300);
  MyGps.gpsPIDMove(-425, -1325, -1);
  setPistonFW(false);

  printf ("===== MyGps.gpsPIDMove: Move to near starting position =====\n");
  MyGps.gpsPIDMove(100, -100, 1);
  PIDAngleRotateAbs(35);

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

  //go to triangle
  MyGps.gpsPIDMove(-330, -30, -1);
  PIDAngleRotateAbs(110);
  timerForward(-65, 125);
  setPistonBW(true);

  printf ("\n===== near_3: End: Elased=%.i =====\n", autotimer.getTime());
  
  Brain.Screen.setCursor(11, 1);
  Brain.Screen.print("AutonTimer: %d               ", autotimer.getTime());
}

