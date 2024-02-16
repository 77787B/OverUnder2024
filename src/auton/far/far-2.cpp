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
  MyGps.gpsPIDMove(0, 40, 1);
  this_thread::sleep_for(600);  
  setIntakeSpeed(0);

  // # push first, second green balls and alliance ball in
  // MyGps.gpsPIDMove(-50, 775, 1);
  MyGps.gpsPIDMove(0, -780, -1);
  // TODO: open wings here 
  // simulate open wings
  this_thread::sleep_for(400);
  MyGps.gpsPIDMove(350, -1175, -1);
  PIDAngleRotateAbs(-65);
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
  // MyGps.gpsPIDMove(-1275, 195, -1);
  MyGps.gpsPIDMove(1175, -180, 1);
  this_thread::sleep_for(300);

  // outtake ball toward goal
  PIDAngleRotateAbs(145); // TODO: adjust this angle to increase the reliability of the triball's target position
  this_thread::sleep_for(100); // TODO: try without this
  // MyGps.gpsPIDMove(-1300, 600, -1);
  MyGps.gpsPIDMove(1375, -600, 1);
  setIntakeSpeed(-75);
  this_thread::sleep_for(400);
  PIDAngleRotateAbs(155);
  timerForward(-100, 200);
  setIntakeSpeed(0);

  // drive to intake middle barrier triball
  setIntakeSpeed(100);
  MyGps.gpsPIDMove(1650, -275, 1, 80);
  this_thread::sleep_for(500);

  // rotate to push tribals into goal
  // PIDAngleRotateAbs(180);
  PIDAngleRotateAbs(175);
  setPistonFW(true);
  this_thread::sleep_for(100);
  setIntakeSpeed(-100); 
  timerForward(100, 700);
  // timerForward(100, 200);
  // PIDAngleRotateAbs(190);
  // timerForward(-100, 200);

  printf ("\n===== near_3: End: Elased=%.i =====\n", autotimer.getTime());
  return;
}




// P.S try PIDPosCurveAbs(5, 400, 100); lol