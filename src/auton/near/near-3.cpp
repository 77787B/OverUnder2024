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
 * 4. Push allowance triball into goal
*/
void near_3() {
  MyTimer autotimer;
  autotimer.reset();
  
  printf ("\n===== near_3: Start =====\n");

  // // push alliance ball towards goal
  // setPistonRW(true);

  //rush to intake center ball
  setIntakeSpeed(100);
  MyGps.gpsPIDMove(-30, -1250, -1);
  this_thread::sleep_for(600);
  setIntakeSpeed(0);
  // setPistonRW(false);

  printf ("===== MyGps.gpsPIDMove: Move to near starting position =====\n");
  MyGps.gpsPIDMove(275, 0, 1);
  PIDAngleRotateAbs(25);
  printf ("===== MyGps.gpsPIDMove: Get corner tribal =====\n");
  timerForward(40, 100);
  setPistonTB(true);
  this_thread::sleep_for(400);

  PIDAngleRotateAbs(-125);
  setPistonTB(false);

  printf ("===== MyGps.gpsPIDMove: Push balls across alley=====\n");
  PIDAngleRotateAbs(-60);
  timerForward(60, 300);
  setIntakeSpeed(-100);
  MyGps.gpsPIDMove(-330, 50, -1);
  this_thread::sleep_for(600); 
  setIntakeSpeed(0);

  // go to triangle
  MyGps.gpsPIDMove(415, 200, 1);
  PIDAngleRotateAbs(125);
  timerForward(65, 200);
  setPistonLW(true);
  setPistonRW(true);

  printf ("\n===== near_3: End: Elased=%.i =====\n", autotimer.getTime());
}

void near_3_previous() {
  printf ("\n===== near_3: Start =====\n");

  MyTimer autotimer;
  autotimer.reset();

  setPistonRW(true);
  this_thread::sleep_for(500);
  setPistonRW(false);

  setIntakeSpeed(100);
  MyGps.gpsPIDMove(0, -1250, -1);
  this_thread::sleep_for(500);
  setIntakeSpeed(0);

  MyGps.gpsPIDMove(0, 0, 1);
  PIDAngleRotateAbs(30);

  MyGps.gpsPIDMove(300, 50, 1);
  setPistonTB(true);
  PIDAngleRotateAbs(-100);
  this_thread::sleep_for(500);
  setPistonTB(false);

  PIDAngleRotateAbs(-240);
  MyGps.gpsPIDMove(-100, 50, -1);

  MyGps.gpsPIDMove(-580, 50, -1);

  setIntakeSpeed(-100);
  this_thread::sleep_for(2000);
  setIntakeSpeed(0);

  MyGps.gpsPIDMove(100, 50, 1);
  MyGps.gpsPIDMove(700, -300, 1);
  PIDAngleRotateAbs(165);
  
  timerForward(100, 200); 

  printf ("\n===== near_3: End: Elased=%.i =====\n", autotimer.getTime());
}
