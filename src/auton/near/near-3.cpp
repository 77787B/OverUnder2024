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

  printf ("===== MyGps.gpsPIDMove: Get corner triball =====\n");
  timerForward(40, 200); 
  // setPistonTB(true);
  this_thread::sleep_for(400);
  PIDAngleRotateAbs(-100);
  // setPistonTB(false);
  PIDAngleRotateAbs(-15); 
  timerForward(35, 200); 
  PIDAngleRotateAbs(75); 

  /*** 4. Push triballs across alley ***/

  printf ("===== MyGps.gpsPIDMove: Push balls across alley=====\n");
  setIntakeSpeed(-100);
  MyGps.gpsPIDMove(-650, -25, -1);
  this_thread::sleep_for(400);
  setIntakeSpeed(0);

  // go to triangle
  MyGps.gpsPIDMove(415, 75, 1);
  PIDAngleRotateAbs(135);
  timerForward(100, 200);
  setPistonFW(true);

  printf ("\n===== near_3: End: Elased=%.i =====\n", autotimer.getTime());
  
  Brain.Screen.setCursor(11, 1);
  Brain.Screen.print("AutonTimer: %d               ", autotimer.getTime());
}
