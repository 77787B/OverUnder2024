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

void near_1() {

  MyTimer autotimer;
  autotimer.reset();
  printf ("\n===== near_1: Start =====\n");

  // Push alliance triball into goal
  MyGps.gpsPIDMove(-515, 400, 1, 50);
  MyGps.gpsPIDMove(-515, 580, 1, 25);
  setIntakeSpeed(-100);
  this_thread::sleep_for(600);
  setIntakeSpeed(0);

  //get corner triball
  // MyGps.gpsPIDMove(-530, 515, -1, 50);
  MyGps.gpsPIDMove(-515, 550, -1, 50);
  PIDAngleRotateAbs(185);
  PIDPosCurveAbs(150, 400, 20);
  setPistonFRW(true);
  this_thread::sleep_for(400);
  PIDPosCurveAbs(300, 600, 30);
  this_thread::sleep_for(500);

  // Push triballs over alley and touch horizontal bar
  setIntakeSpeed(-100);
  MyGps.gpsPIDMove(690, -85, 1);
  this_thread::sleep_for(1000);
  setPistonFRW(false);

  printf ("\n===== near_1: End: Elased=%.i =====\n", autotimer.getTime());

  Brain.Screen.setCursor(11, 1);
  Brain.Screen.print("AutonTimer: %d               ", autotimer.getTime());
}



void near_1_old() {

  MyTimer autotimer;
  autotimer.reset();
  printf ("\n===== near_1: Start =====\n");

  //rush to intake center ball
  setIntakeSpeed(100);
  MyGps.gpsPIDMove(0, 300, 1);
  MyGps.gpsPIDMove(300, 1225, 1);
  //can make all the intakes 300 with new robot
  this_thread::sleep_for(300);
  setIntakeSpeed(0);
  MyGps.gpsPIDMove(275, 1100, -1);

  //drop off middle ball
  MyGps.gpsPIDMove(25, 345, 1);
  PIDAngleRotateAbs(-218);
  setIntakeSpeed(-80);
  this_thread::sleep_for(400);
  setIntakeSpeed(0);

  // Push alliance triball into goal
  setIntakeSpeed(100);
  // PIDAngleRotateAbs(-145);
  MyGps.gpsPIDMove(-75, 215, 1);
  this_thread::sleep_for(300);
  setIntakeSpeed(0);
  MyGps.gpsPIDMove(-530, 500, 1, 60);
  MyGps.gpsPIDMove(-530, 635, 1, 45);
  setIntakeSpeed(-100);
  this_thread::sleep_for(400);
  setIntakeSpeed(0);

  //get corner triball
  PIDAngleRotateAbs(180);
  MyGps.gpsPIDMove(-530, 645, -1, 60);
  PIDPosCurveAbs(200, 430, 50);
  setPistonFW(true);
  this_thread::sleep_for(350);
  PIDPosCurveAbs(225, 515, 50);
  this_thread::sleep_for(400);
  setPistonFW(false);

  // Push triballs over alley and touch horizontal bar
  setIntakeSpeed(-100);
  MyGps.gpsPIDMove(675, -15, 1);
  this_thread::sleep_for(400);

  printf ("\n===== near_1: End: Elased=%.i =====\n", autotimer.getTime());
  Brain.Screen.setCursor(11, 1);
  Brain.Screen.print("AutonTimer: %d               ", autotimer.getTime());
}



void near_1_centerRush() {

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


