#include "autonomous.h"
#include "parameters.h"
#include "my-timer.h"
#include "robot-config.h"
#include "GPS.h"

/**
 * Near 2: Elim: rush center, 0 goal, 4 over
 * 1. Get center triball
 * 2. Get corner triball
 * 3. Push triballs over barrier
 * 4. 
*/


void near_2_original() {
  MyTimer autotimer;
  autotimer.reset();
 
  printf ("\n===== near_2: Start =====\n");

  //rush to intake center ball
  setIntakeSpeed(100);
  MyGps.gpsPIDMove(0, 1180, 1);
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
  timerForward(100, 325);
  setIntakeSpeed(-100);
  this_thread::sleep_for(800); 
  setIntakeSpeed(0);
  // //go to triangle
  // MyGps.gpsPIDMove(-330, -30, -1);
  // PIDAngleRotateAbs(110);
  // timerForward(-65, 125);
  // setPistonBW(true);

  printf ("\n===== near_2: End: Elased=%.i =====\n", autotimer.getTime());
  
  Brain.Screen.setCursor(11, 1);
  Brain.Screen.print("AutonTimer: %d               ", autotimer.getTime());
}

void near_2_() {
  // PIDAngleRotateAbs(180, 0.75, 0.05, 0.3, 0.8);
  PIDAngleRotateAbs(180, 4, 0.1, 35, 1.5); // trying with PID used in gpsPIDMove
}

void near_2() {

  MyTimer autotimer;
  autotimer.reset();
  printf ("\n===== near_2: Start =====\n");

  // ## Rush to intake center ball
  setIntakeSpeed(100);
  MyGps.gpsPIDMove(0, 1200, 1, 100);
  this_thread::sleep_for(300);
  setIntakeSpeed(0);

  // ## drop off center ball
  MyGps.gpsPIDMove(-15, 200, -1, 100);
  PIDAngleRotateAbs(115);
  setIntakeSpeed(-80);
  this_thread::sleep_for(400);
  setIntakeSpeed(0);

  // ## Push alliance triball into goal
  setIntakeSpeed(100);
  // PIDAngleRotateAbs(-145);
  MyGps.gpsPIDMove(-180, -120, 1, 20);
  this_thread::sleep_for(400);
  setIntakeSpeed(0);
  // MyGps.gpsPIDMove(0, 0, -1, 20);
  // MyGps.gpsPIDMove(-600, 215, 1, 50);
  MyGps.gpsPIDMove(-600, 150, 1, 50);
  // MyGps.gpsPIDMove(-625, 361, 1, 25); // works on near side of blue goal's left side
  // MyGps.gpsPIDMove(-625, 265, 1, 50);
  // MyGps.gpsPIDMove(-640, 270, 1, 50);
  MyGps.gpsPIDMove(-645, 275, 1, 50);
  setIntakeSpeed(-100);
  this_thread::sleep_for(500);
  setIntakeSpeed(0);

  // ## get corner triball
  // MyGps.gpsPIDMove(-640, 295, -1, 50);
  MyGps.gpsPIDMove(-600, 175, -1, 25);
  // PIDAngleRotateAbs(150); // very unstable rotation
  PIDAngleRotateAbs(150, 4, 0.1, 35, 1.5); // trying with PID used in gpsPIDMove
  this_thread::sleep_for(100);
  PIDPosCurveAbs(200, 450, 50);  // works on near side of blue goal's left side
  setPistonFRW(true);
  this_thread::sleep_for(500);

  PIDPosCurveAbs(275, 515, 50);
  // PIDPosCurveAbs(290, 515, 50);
  // this_thread::sleep_for(500);

  // ## Push triballs over alley and touch horizontal bar
  setIntakeSpeed(-100);
  // MyGps.gpsPIDMove(690, 100, 1);
  // MyGps.gpsPIDMove(745, 125, 1); // works on near side of blue goal's left side
  MyGps.gpsPIDMove(766, 170, 1); // works on near side of blue goal's left side
  setPistonFW(false);
  this_thread::sleep_for(500);

  // //go to triangle
  // MyGps.gpsPIDMove(-330, -80, -1);
  // PIDAngleRotateAbs(110);
  // timerForward(-65, 125);
  // setPistonBW(true);

  printf ("\n===== near_2: End: Elased=%.i =====\n", autotimer.getTime());
  Brain.Screen.setCursor(11, 1);
  Brain.Screen.print("AutonTimer: %d               ", autotimer.getTime());
}

void near_2_rushV2() {

  MyTimer autotimer;
  autotimer.reset();
  printf ("\n===== near_2: Start =====\n");

  //rush to intake center ball
  setIntakeSpeed(100);
  MyGps.gpsPIDMove(300, 1175, 1);
  //can make all the intakes 300 with new robot
  this_thread::sleep_for(600);
  setIntakeSpeed(0);
  MyGps.gpsPIDMove(275, 1050, -1);

  //drop off middle ball
  MyGps.gpsPIDMove(25, 295, 1);
  PIDAngleRotateAbs(-218);
  setIntakeSpeed(-80);
  this_thread::sleep_for(400);
  setIntakeSpeed(0);

  // Push alliance triball into goal
  //note: gps is very off on old robot, fix next few lines
  setIntakeSpeed(100);
  // PIDAngleRotateAbs(-145);
  MyGps.gpsPIDMove(-75, 165, 1);
  this_thread::sleep_for(600);
  setIntakeSpeed(0);
  MyGps.gpsPIDMove(-500, 450, 1, 50);
  MyGps.gpsPIDMove(-500, 565, 1, 25);
  setIntakeSpeed(-100);
  this_thread::sleep_for(400);
  setIntakeSpeed(0);

  //get corner triball
  MyGps.gpsPIDMove(-515, 480, -1, 100);
  PIDAngleRotateAbs(180);
  PIDPosCurveAbs(200, 480, 50);
  //setPistonFW(true);
  this_thread::sleep_for(400);
  PIDPosCurveAbs(275, 515, 50);
  this_thread::sleep_for(500);
  //setPistonFW(false);

  // Push triballs over alley and touch horizontal bar
  setIntakeSpeed(-100);
  MyGps.gpsPIDMove(690, -65, 1);
  this_thread::sleep_for(500);

  //go to triangle
  MyGps.gpsPIDMove(-330, -80, -1);
  PIDAngleRotateAbs(110);
  timerForward(-65, 125);
  setPistonBW(true);

  printf ("\n===== near_2: End: Elased=%.i =====\n", autotimer.getTime());
  Brain.Screen.setCursor(11, 1);
  Brain.Screen.print("AutonTimer: %d               ", autotimer.getTime());
}


