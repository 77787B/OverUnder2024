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
  MyGps.gpsPIDMove(0, 75, 1);
  setPistonBW(true);
  this_thread::sleep_for(400);
  MyGps.gpsPIDMove(0, 0, -1, 60);
  setPistonBW(false);
  MyGps.gpsPIDMove(75, 400, 1);
  PIDAngleRotateAbs(45);
  MyGps.gpsPIDMove(200, 555, 1, 40);
  setIntakeSpeed(-100);
  this_thread::sleep_for(500);
  setIntakeSpeed(0);
  MyGps.gpsPIDMove(0, -50, -1);
  PIDAngleRotateAbs(145);
  setPistonFW(true);
  this_thread::sleep_for(300);
  setIntakeSpeed(-100);
  MyGps.gpsPIDMove(530, -800, 1);
  setPistonFW(false);
}


void near_1_realAsAboveIsInCase() {
  MyTimer autotimer;
  autotimer.reset();
  printf ("\n===== near_1: Start =====\n");

  // ## Rush to intake center ball
  setIntakeSpeed(100);
  MyGps.gpsPIDMove(0, 1200, 1, 100);
  this_thread::sleep_for(300);
  setIntakeSpeed(0);

  // ## drop off center ball
  MyGps.gpsPIDMove(-15, 200, -1, 100);
  PIDAngleRotateAbs(115, 4, 0.1, 35, 1.5);
  setIntakeSpeed(-80);
  this_thread::sleep_for(400);
  setIntakeSpeed(0);

  // ## Push alliance triball into goal
  setIntakeSpeed(100);
  // PIDAngleRotateAbs(-145);
  MyGps.gpsPIDMove(-180, -120, 1, 20);
  this_thread::sleep_for(400);
  setIntakeSpeed(0);
  MyGps.gpsPIDMove(-600, 150, 1, 50);
  MyGps.gpsPIDMove(-645, 275, 1, 50);
  timerForward(30, 150); //probably only need on old robot
  setIntakeSpeed(-100);
  this_thread::sleep_for(500);
  setIntakeSpeed(0);

  // ## get corner triball
  MyGps.gpsPIDMove(-600, 175, -1, 25);
  // PIDAngleRotateAbs(150); // very unstable rotation
  PIDAngleRotateAbs(150, 4, 0.1, 35, 1.5);
  this_thread::sleep_for(100);
  PIDPosCurveAbs(200, 450, 50);
  setPistonFRW(true);
  this_thread::sleep_for(500);

  PIDPosCurveAbs(275, 515, 50);

  // ## Push triballs over alley and touch horizontal bar
  setIntakeSpeed(-100);
  MyGps.gpsPIDMove(765, 170, 1);
  setPistonFW(false);
  this_thread::sleep_for(500);

  // //go to triangle
  // MyGps.gpsPIDMove(-330, -80, -1);
  // PIDAngleRotateAbs(110);
  // timerForward(-65, 125);
  // setPistonBW(true);

  printf ("\n===== near_1: End: Elased=%.i =====\n", autotimer.getTime());
  Brain.Screen.setCursor(11, 1);
  Brain.Screen.print("AutonTimer: %d               ", autotimer.getTime());
}


void near_1_oldVersionNoRush() {

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


