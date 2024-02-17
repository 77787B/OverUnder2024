#include "autonomous.h"
#include "parameters.h"
#include "my-timer.h"
#include "robot-config.h"
#include "GPS.h"

/**
 * Far 3: ? goal
 * //
*/
void far_3_() {

  MyTimer autotimer;
  autotimer.reset();

  
  Brain.Screen.setCursor(11, 1);
  Brain.Screen.print("AutonTimer: %d               ", autotimer.getTime());
}

void far_3() {
  printf ("\nfar_1:\n");

  MyTimer autotimer;
  autotimer.reset();

  // # get first green ball
  setIntakeSpeed(100);
  MyGps.gpsPIDMove(0, 40, 1);
  this_thread::sleep_for(600);  
  setIntakeSpeed(0);

  // # push first, second green balls and alliance ball in
  MyGps.gpsPIDMove(100, -800, -1, 70);
  PIDAngleRotateAbs(-40);
  setPistonBW(true);
  this_thread::sleep_for(400);
  MyGps.gpsPIDMove(275, -1100, -1, 70);
  return;

  PIDAngleRotateAbs(-65);
  setPistonBW(false);
  timerForward(-75, 250);
  PIDAngleRotateAbs(-87);
  timerForward(-100, 400);
  timerForward(100, 100);
  PIDAngleRotateAbs(87);
  setIntakeSpeed(-100);
  PIDAngleRotateAbs(95);
  timerForward(100, 300);
  setIntakeSpeed(0);
  timerForward(-95, 250);

  //get third green ball
  setIntakeSpeed(100);
  // MyGps.gpsPIDMove(1175, -180, 1);
  MyGps.gpsPIDMove(1150, -150, 1);
  this_thread::sleep_for(300);
  setIntakeSpeed(0);

  // outtake ball toward goal
  PIDAngleRotateAbs(145); // TODO: adjust this angle to increase the reliability of the triball's target position
  this_thread::sleep_for(100); // TODO: try without this
  // MyGps.gpsPIDMove(-1300, 600, -1);
  MyGps.gpsPIDMove(1375, -600, 1);
  setIntakeSpeed(-75);
  this_thread::sleep_for(400);
  PIDAngleRotateAbs(150);
  timerForward(-100, 200);
  setIntakeSpeed(0);

  // drive to intake middle barrier triball
  setIntakeSpeed(100);
  MyGps.gpsPIDMove(1650, -275, 1, 80);
  this_thread::sleep_for(500);
  setIntakeSpeed(0);

  // rotate to push tribals into goal
  PIDAngleRotateAbs(175);
  setPistonFW(true);
  this_thread::sleep_for(100);
  setIntakeSpeed(-100); 
  timerForward(100, 700);
  // timerForward(100, 200);
  // PIDAngleRotateAbs(190);
  // timerForward(-100, 200);

  printf ("\n===== far_1: End: Elased=%.i =====\n", autotimer.getTime());
  return;
}




// P.S try PIDPosCurveAbs(5, 400, 100); lol