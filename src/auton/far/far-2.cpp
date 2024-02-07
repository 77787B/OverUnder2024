#include "autonomous.h"
#include "parameters.h"
#include "my-timer.h"
#include "robot-config.h"
#include "GPS.h"

/**
 * Far 2: AWP: 6 balls
 * 
 * Route:
 * 1. Get triball-under-bar
 * 1.1. Drive slowly to corner triball so our alliance ball follows a stable path
 * 2. Get corner triball
 * 3. Push in alliance triball and corner triball
 * 3.1. Rotate and push in triball-under-bar
 * 4. Get barrier-triball-on-right 
 * 4.1. Outtake it toward goal
 * 5. Get middle-barrier-triball
 * 6. Push all 3 triballs into goal
*/

void far_2_() {
  PIDAngleRotateAbs(180);

  //get first green ball
  // setIntakeSpeed(100);
  // MyGps.gpsPIDMove(0, -40, -1);
  // this_thread::sleep_for(600);  
  // setIntakeSpeed(0);

  // //push first, second green balls and alliance ball in
  // MyGps.gpsPIDMove(0, 800, 1);
}

void far_2() {
  printf ("\nfar_2:\n");

  MyTimer autotimer;
  autotimer.reset();

  // # get first green ball
  setIntakeSpeed(100);
  MyGps.gpsPIDMove(0, -40, -1);
  // MyGps.gpsPIDMove(0, 0, -1);
  this_thread::sleep_for(600);  
  setIntakeSpeed(0);

  // # push first, second green balls and alliance ball in
  // MyGps.gpsPIDMove(-50, 775, 1);
  // MyGps.gpsPIDMove(-50, 715, 1, 40);
  MyGps.gpsPIDMove(0, 715, 1, 40);
  PIDPosCurveAbs(125, 500, 25);

  // ## get corner tribal
  // TODO: open wings here
  this_thread::sleep_for(500); // simulate open wings

  //
  PIDPosCurveAbs(350, 560, 35);
  timerForward(100, 250);

  // back off the goal a bit to rotate
  MyGps.gpsPIDMove(-600, 1200, -1);
  PIDAngleRotateAbs(90);
  setIntakeSpeed(-100);
  this_thread::sleep_for(500);
  timerForward(-100, 300);
  
  // back off the goal a bit to rotate
  MyGps.gpsPIDMove(-600, 1200, 1);

  // drive to intake barrier right triball
  setIntakeSpeed(100);
  MyGps.gpsPIDMove(-1100, 50, -1);
  this_thread::sleep_for(500);

  // outtake ball toward goal
  PIDAngleRotateAbs(145); // TODO: adjust this angle to increase the reliability of the triball's target position
  this_thread::sleep_for(100); // TODO: try without this
  setIntakeSpeed(-100);
  MyGps.gpsPIDMove(-1250, 300, -1);

  // drive to intake middle barrier triball
  setIntakeSpeed(100);
  MyGps.gpsPIDMove(-1580, 25, -1);
  // PIDPosCurveAbs(560, 340, -35);
  this_thread::sleep_for(500);

  // rotate to push tribals into goal
  PIDAngleRotateAbs(180);
  setPistonRW(true);
  setPistonLW(true);
  this_thread::sleep_for(100);
  timerForward(-100, 500);

  printf ("\n===== near_3: End: Elased=%.i =====\n", autotimer.getTime());
  return;
}

