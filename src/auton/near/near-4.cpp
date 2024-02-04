#include "autonomous.h"
#include "parameters.h"
#include "my-timer.h"
#include "robot-config.h"
#include "GPS.h"

void near_4_() {
  setIntakeSpeed(100);
}

/**
 * Near 4: Elim: rush center, 1 goal, 4 over
 * 1. Get center triball
 * 2. Disrupt the barrier middle triball // Push barrier middle triball over
 * 3. Get corner triball
 * 4. Push triballs over barrier
 * 5. Push allowance triball into goal
*/
void near_4() {
  MyTimer autotimer;
  autotimer.reset();
  
  printf ("\n===== near_4: Start =====\n");

  /*** 1. Get center triball ****/

  // push alliance ball towards goal
  // setPistonRW(true);

  //rush to intake center ball
  setIntakeSpeed(100);
  MyGps.gpsPIDMove(0, -1250, -1);
  // setPistonRW(false);
  this_thread::sleep_for(500);
  setIntakeSpeed(0);

  //push center barrier ball across 
  setPistonRW(true);
  PIDAngleRotateAbs(80);
  // timerForward(100, 300);
  MyGps.gpsPIDMove(-425, -1325, -1);
  setPistonRW(false);

  printf ("===== MyGps.gpsPIDMove: Move to near starting position =====\n");
  MyGps.gpsPIDMove(100, -100, 1);
  PIDAngleRotateAbs(35);

  printf ("===== MyGps.gpsPIDMove: Get corner tribal =====\n");
  timerForward(40, 200); 
  setPistonTB(true);
  this_thread::sleep_for(400);
  PIDAngleRotateAbs(-100);
  setPistonTB(false);
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
  setPistonLW(true);
  setPistonRW(true);

  printf ("\n===== near_4: End: Elased=%.i =====\n", autotimer.getTime());
}
