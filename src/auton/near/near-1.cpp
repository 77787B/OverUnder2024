#include "autonomous.h"
#include "parameters.h"
#include "my-timer.h"
#include "robot-config.h"
#include "GPS.h"

/**
 * Near 1: AWP: 1 goal, 2 over
 * 1. Push allowance triball into goal
 * 2. Get corner triball
 * 3. Push triballs over barrier
 * 4. Touch horizontal bar
*/

void near_1_comp() {

  MyTimer autotimer;
  autotimer.reset();
  printf ("\n===== near_1: Start =====\n");

  // Push alliance triball into goal
  MyGps.gpsPIDMove(-500, 350, 1, 50);
  MyGps.gpsPIDMove(-500, 570, 1, 25);
  setIntakeSpeed(-100);
  this_thread::sleep_for(600);
  setIntakeSpeed(0);

  //get corner triball
  MyGps.gpsPIDMove(-515, 530, -1, 100);
  PIDAngleRotateAbs(180);
  PIDPosCurveAbs(200, 480, 18);
  setPistonFW(true);
  this_thread::sleep_for(400);
  PIDPosCurveAbs(270, 515, 45);
  this_thread::sleep_for(500);
  setPistonFW(false);

  // Push triballs over alley and touch horizontal bar
  setIntakeSpeed(-100);
  MyGps.gpsPIDMove(690, -85, 1);
  this_thread::sleep_for(1000);

  printf ("\n===== near_1: End: Elased=%.i =====\n", autotimer.getTime());

  Brain.Screen.setCursor(11, 1);
  Brain.Screen.print("AutonTimer: %d               ", autotimer.getTime());
}



void near_1() {
  MyTimer autotimer;
  autotimer.reset();
 
  printf ("\n===== near_2: Start =====\n");

  //rush to intake center ball
  setIntakeSpeed(100);
  MyGps.gpsPIDMove(0, 300, 1);
  MyGps.gpsPIDMove(250, 1275, 1);
  this_thread::sleep_for(300);
  setIntakeSpeed(0);

  //going back and getting the alliance triball
  MyGps.gpsPIDMove(0, 0, 1);
  setIntakeSpeed(-80);
  this_thread::sleep_for(400);
  setIntakeSpeed(0);
  MyGps.gpsPIDMove(0, 75, -1);
  setIntakeSpeed(100);
  PIDAngleRotateAbs(-145);
  MyGps.gpsPIDMove(-100, 0, 1);

  // Push alliance triball into goal
  MyGps.gpsPIDMove(-500, 350, 1, 50);
  MyGps.gpsPIDMove(-500, 570, 1, 25);
  setIntakeSpeed(-100);
  this_thread::sleep_for(600);
  setIntakeSpeed(0);

  return;

  //get corner triball
  MyGps.gpsPIDMove(-515, 530, -1, 100);
  PIDAngleRotateAbs(180);
  PIDPosCurveAbs(200, 480, 18);
  setPistonFW(true);
  this_thread::sleep_for(400);
  PIDPosCurveAbs(275, 515, 45);
  this_thread::sleep_for(500);
  setPistonFW(false);

  // Push triballs over alley and touch horizontal bar
  setIntakeSpeed(-100);
  MyGps.gpsPIDMove(690, -85, 1);
  this_thread::sleep_for(1000);

  printf ("\n===== near_1: End: Elased=%.i =====\n", autotimer.getTime());

  Brain.Screen.setCursor(11, 1);
  Brain.Screen.print("AutonTimer: %d               ", autotimer.getTime());
}




void near_1_probWontUse() {
  MyTimer autotimer;
  autotimer.reset();
 
  printf ("\n===== near_1: Start =====\n");

  //push alliance ball in
  MyGps.gpsPIDMove(-545, 315, 1, 50);
  // PIDAngleRotateAbs()
  MyGps.gpsPIDMove(-615, 375, 1, 25);
  setIntakeSpeed(-100);
  this_thread::sleep_for(600);
  setIntakeSpeed(0);

  //rush to intake center ball
  MyGps.gpsPIDMove(0, 0, -1);
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

  printf ("\n===== near_2: End: Elased=%.i =====\n", autotimer.getTime());
  
  Brain.Screen.setCursor(11, 1);
  Brain.Screen.print("AutonTimer: %d               ", autotimer.getTime());
}

