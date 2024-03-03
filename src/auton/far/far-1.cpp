#include "autonomous.h"
#include "parameters.h"
#include "my-timer.h"
#include "robot-config.h"
#include "GPS.h"

/**
 * Far 1: AWP: 6 balls
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


void far_1_notRush() {
  printf ("\nfar_1:\n");

  MyTimer autotimer;
  autotimer.reset();

  // Push alliance triball into goal
  MyGps.gpsPIDMove(500, 350, 1, 50);
  MyGps.gpsPIDMove(500, 590, 1, 25);
  setIntakeSpeed(-100);
  this_thread::sleep_for(600);
  setIntakeSpeed(0);
  
}



void far_1_5ball() {
  printf ("\nfar_1:\n");

  MyTimer autotimer;
  autotimer.reset();

  // # get first green ball
  setIntakeSpeed(100);
  MyGps.gpsPIDMove(0, 40, 1);
  this_thread::sleep_for(300);  
  setIntakeSpeed(0);

  // # push first, second green balls and alliance ball in
  MyGps.gpsPIDMove(0, -750, -1, 70);
  MyGps.gpsPIDMove(400, -1250, -1, 70);
  PIDAngleRotateAbs(-93);
  timerForward(-100, 400);
  timerForward(100, 100);
  PIDAngleRotateAbs(90);
  setIntakeSpeed(-100);
  PIDAngleRotateAbs(95);
  timerForward(100, 300);
  setIntakeSpeed(0);
  timerForward(-95, 250);

  return;

  //get third green ball
  setIntakeSpeed(100);
  // MyGps.gpsPIDMove(1175, -180, 1);
  MyGps.gpsPIDMove(1150, -130, 1);
  this_thread::sleep_for(300); 
  setIntakeSpeed(0);

  // return;

  // outtake ball toward goal
  PIDAngleRotateAbs(145); // TODO: adjust this angle to increase the reliability of the triball's target position
  this_thread::sleep_for(100); // TODO: try without this
  // MyGps.gpsPIDMove(-1300, 600, -1);
  MyGps.gpsPIDMove(1375, -600, 1);
  setIntakeSpeed(-75);
  this_thread::sleep_for(450);
  PIDAngleRotateAbs(150);
  timerForward(-100, 200);
  setIntakeSpeed(0);

  // drive to intake middle barrier triball
  setIntakeSpeed(100);
  MyGps.gpsPIDMove(1675, -275, 1, 80);
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


void far_1() {
  printf ("\nfar_1:\n");

  MyTimer autotimer;
  autotimer.reset();

  // # get first green ball
  setIntakeSpeed(100);
  MyGps.gpsPIDMove(0, 40, 1);
  this_thread::sleep_for(600);  
  setIntakeSpeed(0);

  // # push first, second green balls and alliance ball in
  // MyGps.gpsPIDMove(100, -850, -1, 35);
  MyGps.gpsPIDMove(100, -850, -1, 50);
  PIDAngleRotateAbs(-30, 4, 0.1, 35, 1.5);
  setPistonBW(true);
  this_thread::sleep_for(400);
  MyGps.gpsPIDMove(250, -1100, -1, 70);
  setPistonBW(false);
  return;
  this_thread::sleep_for(300);
  timerForward(-60, 150);
  PIDAngleRotateAbs(-75, 4, 0.1, 35, 1.5);
  timerForward(-100, 500);
  timerForward(80, 150);
  PIDAngleRotateAbs(97, 4, 0.1, 35, 1.5);
  setIntakeSpeed(-100);
  this_thread::sleep_for(400);
  timerForward(100, 350);
  setIntakeSpeed(0);
  timerForward(-100, 300);

  //get third green ball and drop it off at goal
  setIntakeSpeed(100);
  MyGps.gpsPIDMove(1150, -200, 1);
  this_thread::sleep_for(300);
  setIntakeSpeed(0);
  PIDAngleRotateAbs(145, 4, 0.1, 35, 1.5); // TODO: adjust this angle to increase the reliability of the triball's target position
  this_thread::sleep_for(100); // TODO: try without this
  // MyGps.gpsPIDMove(-1300, 600, -1);
  MyGps.gpsPIDMove(1200, -650, 1);
  setIntakeSpeed(-75);
  this_thread::sleep_for(400);
  PIDAngleRotateAbs(150, 4, 0.1, 35, 1.5);
  timerForward(-100, 100);
  setIntakeSpeed(0);

  // push in fourth and fifth green balls in
  setIntakeSpeed(100);
  MyGps.gpsPIDMove(1600, -275, 1, 80);
  this_thread::sleep_for(500);
  setIntakeSpeed(0);
  PIDAngleRotateAbs(180, 4, 0.1, 35, 1.5);
  setPistonFW(true);
  this_thread::sleep_for(100);
  setIntakeSpeed(-100); 
  timerForward(100, 700);

  printf ("\n===== far_1: End: Elased=%.i =====\n", autotimer.getTime());
  Brain.Screen.setCursor(11, 1);
  Brain.Screen.print("AutonTimer: %d               ", autotimer.getTime());

}




// P.S try PIDPosCurveAbs(5, 400, 100); lol