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
 * 2. Push barrier middle tribal over
 * 2. Get corner triball
 * 3. Push triballs over barrier
 * 4. Push allowance triball into goal
*/
void near_4() {
  MyTimer autotimer;
  autotimer.reset();
  
  printf ("\n===== near_4: Start =====\n");

  // push alliance ball towards goal
  setPistonRW(true);

  //rush to intake center ball
  setIntakeSpeed(100);
  MyGps.gpsPIDMove(0, -1250, -1);
  this_thread::sleep_for(600);
  setIntakeSpeed(0);

  //push center barrier ball across 
  PIDAngleRotateAbs(80);
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

  printf ("===== MyGps.gpsPIDMove: Push balls across alley=====\n");
  setIntakeSpeed(-100);
  MyGps.gpsPIDMove(-650, -25, -1);
  this_thread::sleep_for(400);
  setIntakeSpeed(0);

  printf ("===== MyGps.gpsPIDMove: Push alliance tribal to goal =====\n");
  MyGps.gpsPIDMove(-100, 10, 1);

  printf ("===== MyGps.gpsPIDMove: Push alliance triball: curve =====\n");
  // PIDPosCurveAbs(1125, 600, 50);
  // PIDAngleRotateAbs(145);
  MyGps.gpsPIDMove(100, 50, 1);
  MyGps.gpsPIDMove(700, -300, 1);

  printf ("===== MyGps.gpsPIDMove: Push alliance triball: push =====\n");
  printf ("\n===== near_4: Before Push: Elased=%.i =====\n", autotimer.getTime());
  timerForward(100, 250); 

  printf ("\n===== near_4: End: Elased=%.i =====\n", autotimer.getTime());
}
