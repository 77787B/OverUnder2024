#include "autonomous.h"
#include "parameters.h"
#include "my-timer.h"
#include "robot-config.h"
#include "GPS.h"

/**
 * Near 2: AWP: rush center, 1 goal, 2 over
 * 1. Get center triball
 * 2. Push alliance triball into goal
 * 3. Get corner triball
 * 4. Push triballs over alley
*/

void near_2(bool isRush) {
  // PIDPosForwardAbs(120);
  // PIDPosForwardAbs(120, 150);
  // setIntakeSpeed(-100);
  // this_thread::sleep_for(500);
  // return;

  MyTimer autotimer;
  autotimer.reset();
  printf ("\n===== near_2: Start =====\n");

  // ## Rush to intake center ball
  setIntakeSpeed(100);
  float forwardTarget = 1175;
  // float forwardTarget = 1215;
  // float forwardTarget = 1230;
  if (isRush == false) {
    forwardTarget = 900;
  }
  PIDPosForwardAbs(forwardTarget);
  this_thread::sleep_for(300);
  setIntakeSpeed(0);

  // ## Drop off center ball
  resetForwardPos();
  PIDPosForwardAbs(50 - forwardTarget);
  PIDAngleRotateAbs(115);
  setIntakeSpeed(-100);
  this_thread::sleep_for(400);

  // ## Intake alliance triball
  PIDAngleRotateAbs(220);
  setIntakeSpeed(100);
  PIDPosForwardAbs(200);
  this_thread::sleep_for(300);
  setIntakeSpeed(0);

  // ## Outtake alliance triball into goal
  PIDAngleRotateAbs(-60);
  PIDPosForwardAbs(575);
  PIDAngleRotateAbs(-18);
  PIDPosForwardAbs(120, 200);
  setIntakeSpeed(-100);
  this_thread::sleep_for(1000);
  setIntakeSpeed(0);

  // ## Get corner triball
  PIDPosForwardAbs(-75);
  PIDAngleRotateAbs(-50);
  // PIDPosForwardAbs(-325);
  PIDPosForwardAbs(-300);
  setPistonBLW(true);
  this_thread::sleep_for(100);

  PIDAngleRotateAbs(-80);
  setPistonBLW(false);
  this_thread::sleep_for(10);

  // ## Push triballs over alley and touch horizontal bar
  PIDAngleRotateAbs(110);
  setIntakeSpeed(-100);
  this_thread::sleep_for(100);
  setPistonFW(true);
  PIDPosForwardAbs(380);

  PIDAngleRotateAbs(76);
  setPistonFLW(false);
  this_thread::sleep_for(50);
  PIDPosForwardAbs(775);
  setPistonFW(false);
  this_thread::sleep_for(500);

  printf ("\n===== near_2: End: Elased=%.i =====\n", autotimer.getTime());
  Brain.Screen.setCursor(11, 1);
  Brain.Screen.print("AutonTimer: %d               ", autotimer.getTime());
}

void near_2_gps(bool isRush) {
/*
  MyTimer autotimer;
  autotimer.reset();
  printf ("\n===== near_2: Start =====\n");

  // ## Rush to intake center ball
  setIntakeSpeed(100);
  if (isRush) {
    MyGps.gpsPIDMove(0, 1200, 1);
  } else {
    MyGps.gpsPIDMove(0, 600, 1);
  }
  this_thread::sleep_for(300);
  setIntakeSpeed(0);

  // ## Drop off center ball
  MyGps.gpsPIDMove(-15, 200, -1, 100);
  PIDAngleRotateAbs(115);
  setIntakeSpeed(-100);
  this_thread::sleep_for(700);
  setIntakeSpeed(0);

  // ## Push alliance triball into goal
  setIntakeSpeed(60);
  MyGps.gpsPIDMove(-180, -45, 1, 20);
  this_thread::sleep_for(100);
  setIntakeSpeed(0);
  MyGps.gpsPIDMove(-615, 200, 1, 50);
  // MyGps.gpsPIDMove(-650, 305, 1, 20);
  // PIDAngleRotateAbs(-15);
  // timerForward(10, 325);
  // Use this if it keeps getting stuck at comps:
  PIDAngleRotateAbs(-15);
  timerForward(17, 475);
  this_thread::sleep_for(100);
  setIntakeSpeed(-100);
  this_thread::sleep_for(400);
  setIntakeSpeed(0);
  MyGps.gpsPIDMove(-645, 305, -1, 50);

  // ## Get corner triball
  setPistonBLW(true);
  MyGps.gpsPIDMove(-360, 20, -1, 80);
  PIDAngleRotateAbs(-110);
  setIntakeSpeed(-100);
  this_thread::sleep_for(100);
  setPistonBLW(false);
  setPistonFRW(true);

  // ## Push triballs over alley and touch horizontal bar
  MyGps.gpsPIDMove(-45, -100, 1, 40);
  MyGps.gpsPIDMove(715, 65, 1, 80);
  // this_thread::sleep_for(200);
  // setPistonFRW(false);

  printf ("\n===== near_2: End: Elased=%.i =====\n", autotimer.getTime());
  Brain.Screen.setCursor(11, 1);
  Brain.Screen.print("AutonTimer: %d               ", autotimer.getTime());
*/
}