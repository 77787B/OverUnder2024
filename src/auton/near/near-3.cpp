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
  printf ("\n===== near_3: Start =====\n");

  //push alliance ball towards goal
  setPistonRW(true);

  //intake middle (first) ball
  setIntakeSpeed(100);
  MyGps.gpsPIDMove(0, -1250, -1);
  this_thread::sleep_for(600);
  setIntakeSpeed(0);

  //push center (second) ball across 
  PIDAngleRotateAbs(80);
  MyGps.gpsPIDMove(-425, -1325, -1);

  //go to red triangle bar
  MyGps.gpsPIDMove(0, 0, 1);
  PIDAngleRotateAbs(30);
  MyGps.gpsPIDMove(300, 50, 1);

  //get (third) ball out of triangle
  setPistonTB(true);
  PIDAngleRotateAbs(-100);
  this_thread::sleep_for(500);
  setPistonTB(false);

  //push third ball across alley
  PIDAngleRotateAbs(-240);
  MyGps.gpsPIDMove(-100, 50, -1);
  MyGps.gpsPIDMove(-580, 50, -1);

  //outtake first ball across alley
  setIntakeSpeed(-100);
  this_thread::sleep_for(800);
  setIntakeSpeed(0);

  //push alliance triball into goal
  MyGps.gpsPIDMove(100, 50, 1);
  MyGps.gpsPIDMove(700, -300, 1);
  
  //get into position for match start
  PIDAngleRotateAbs(165);
  timerForward(100, 200); 
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
