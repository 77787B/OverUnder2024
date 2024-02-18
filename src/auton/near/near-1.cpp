#include "autonomous.h"
#include "parameters.h"
#include "my-timer.h"
#include "robot-config.h"
#include "GPS.h"

/**
 * Near 1: AWP: 1 goal, 2 over
 * 1. Get corner triball
 * 2. Push allowance triball into goal
 * 3. Push triballs over barrier
 * 4. Touch horizontal bar
*/

void near_1() {
  //for Norcal

  MyTimer autotimer;
  autotimer.reset();
 
  printf ("\n===== near_2: Start =====\n");

  //rush to intake center ball
  setIntakeSpeed(100);
  MyGps.gpsPIDMove(0, 300, 1);
  MyGps.gpsPIDMove(300, 1225, 1);
  //can make all the intakes 300 with new robot
  this_thread::sleep_for(600);
  setIntakeSpeed(0);
  MyGps.gpsPIDMove(275, 1100, -1);

  //drop off middle ball
  MyGps.gpsPIDMove(25, 345, 1);
  PIDAngleRotateAbs(-218);
  setIntakeSpeed(-80);
  this_thread::sleep_for(400);
  setIntakeSpeed(0);

  // Push alliance triball into goal
  //note: gps is very off on old robot, fix next few lines
  setIntakeSpeed(100);
  // PIDAngleRotateAbs(-145);
  MyGps.gpsPIDMove(-75, 215, 1);
  this_thread::sleep_for(600);
  setIntakeSpeed(0);
  MyGps.gpsPIDMove(-500, 500, 1, 50);
  MyGps.gpsPIDMove(-500, 615, 1, 25);
  setIntakeSpeed(-100);
  this_thread::sleep_for(400);
  setIntakeSpeed(0);

  //get corner triball
  MyGps.gpsPIDMove(-515, 530, -1, 100);
  PIDAngleRotateAbs(180);
  PIDPosCurveAbs(200, 480, 50);
  //setPistonFW(true);
  this_thread::sleep_for(400);
  PIDPosCurveAbs(275, 515, 50);
  this_thread::sleep_for(500);
  //setPistonFW(false);

  // Push triballs over alley and touch horizontal bar
  setIntakeSpeed(-100);
  MyGps.gpsPIDMove(690, -15, 1);
  this_thread::sleep_for(500);

  printf ("\n===== near_1: End: Elased=%.i =====\n", autotimer.getTime());

  Brain.Screen.setCursor(11, 1);
  Brain.Screen.print("AutonTimer: %d               ", autotimer.getTime());
}




void near_1__() {
  MyTimer autotimer;
  autotimer.reset();

  printf ("\n===== near_1: Start =====\n");

  setPistonRW(true);
  this_thread::sleep_for(500);
  setPistonTB(true);
  this_thread::sleep_for(500);
  PIDAngleRotateAbs(-125);
  this_thread::sleep_for(200);
  setPistonTB(false);
  setPistonRW(false);
  this_thread::sleep_for(100);

  // PIDAngleRotateAbs(90);
  // PIDPosCurveAbs(650, 400, 50);
  // timerForward(100, 200);
  // this_thread::sleep_for(500);

  // MyGps.gpsPIDMove(-75, -50, -1);
  PIDAngleRotateAbs(90);
  timerForward(-50, 230);
  setIntakeSpeed(-100);
  MyGps.gpsPIDMove(-600, -515, -1);

  this_thread::sleep_for(1000);
  setIntakeSpeed(0);

  printf ("\n===== near_1: End: Elased=%.i =====\n", autotimer.getTime());
}

void near_1_() {
  MyTimer autotimer;
  autotimer.reset();

  printf ("\n===== near_1: Start =====\n");

  setPistonRW(true);
  this_thread::sleep_for(500);
  setPistonTB(true);
  this_thread::sleep_for(500);
  PIDAngleRotateAbs(-125);
  this_thread::sleep_for(200);
  setPistonTB(false);
  setPistonRW(false);
  this_thread::sleep_for(100);

  PIDAngleRotateAbs(90);
  PIDPosCurveAbs(650, 400, 50);
  timerForward(55, 150);
  this_thread::sleep_for(500);

  MyGps.gpsPIDMove(-75, -50, -1);
  PIDAngleRotateAbs(45);
  setIntakeSpeed(-100);
  MyGps.gpsPIDMove(-715, -560, -1);

  this_thread::sleep_for(2000);
  setIntakeSpeed(0);

  printf ("\n===== near_1: End: Elased=%.i =====\n", autotimer.getTime());
}

void near_1_previous() {
  printf ("\nauton_near_awp_1_goal:\n");
  setPistonRW(true);
  this_thread::sleep_for(500);
  setPistonTB(true);
  this_thread::sleep_for(500);
  PIDAngleRotateAbs(-125);
  this_thread::sleep_for(200);
  setPistonTB(false);
  setPistonRW(false);
  this_thread::sleep_for(100);

  PIDAngleRotateAbs(90);
  PIDPosCurveAbs(700, 480, 50);  
  timerForward(100, 200); 
  this_thread::sleep_for(500);

  MyGps.gpsPIDMove(0, 0, -1);
  PIDAngleRotateAbs(45);
  setIntakeSpeed(-100);
  MyGps.gpsPIDMove(-650, -550, -1);

  this_thread::sleep_for(500);  
  setIntakeSpeed(0);
}


