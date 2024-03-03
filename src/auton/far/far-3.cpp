#include "autonomous.h"
#include "parameters.h"
#include "my-timer.h"
#include "robot-config.h"
#include "GPS.h"

/**
 * Far 3: AWP: 5 balls
 * 
 * Route:
 * 1. Get alley triball
 * 1.1. Drive slowly to corner triball so our alliance ball follows a stable path
 * 2. Get corner triball
 * 3. Push in alliance triball and corner triball
 * 3.1. Rotate and push in triball-under-bar
 * 4. Get barrier-triball-on-right 
 * 4.1. Outtake it toward goal
 * 5. Get middle-barrier-triball
 * 6. Push all 3 triballs into goal
*/

void far_3() {
  printf ("\nfar_4:\n");

  MyTimer autotimer;
  autotimer.reset();

  // # get alley triball
  setIntakeSpeed(100);
  MyGps.gpsPIDMove(0, 40, 1);
  this_thread::sleep_for(300);  
  setIntakeSpeed(0);

  // * 2. Get corner triball

  // # push first, second tiballs and alliance tiball into goal
  // MyGps.gpsPIDMove(0, -780, -1, 70);
  MyGps.gpsPIDMove(275, -1100, -1, 70);
  PIDAngleRotateAbs(-65, 4, 0.1, 35, 1.5);
  // setPistonBW(false); // TOTO: skip getting corner triball for now
  timerForward(-75, 250);
  PIDAngleRotateAbs(-87, 4, 0.1, 35, 1.5);
  timerForward(-100, 400);
  timerForward(100, 100);
  PIDAngleRotateAbs(87, 4, 0.1, 35, 1.5);
  setIntakeSpeed(-100);
  PIDAngleRotateAbs(95, 4, 0.1, 35, 1.5);
  timerForward(100, 300);
  setIntakeSpeed(0);
  timerForward(-95, 250);

  //get third green ball
  setIntakeSpeed(100);
  // MyGps.gpsPIDMove(1175, -180, 1);
  MyGps.gpsPIDMove(1150, -175, 1);
  this_thread::sleep_for(300);
  setIntakeSpeed(0);

  // outtake ball toward goal
  PIDAngleRotateAbs(145, 4, 0.1, 35, 1.5); // TODO: adjust this angle to increase the reliability of the triball's target position
  this_thread::sleep_for(100); // TODO: try without this
  // MyGps.gpsPIDMove(-1300, 600, -1);
  MyGps.gpsPIDMove(1375, -600, 1);
  setIntakeSpeed(-75);
  this_thread::sleep_for(400);
  PIDAngleRotateAbs(150, 4, 0.1, 35, 1.5);
  timerForward(-100, 200);
  setIntakeSpeed(0);

  // drive to intake middle barrier triball
  setIntakeSpeed(100);
  MyGps.gpsPIDMove(1675, -275, 1, 80);
  this_thread::sleep_for(500);
  setIntakeSpeed(0);

  // rotate to push tribals into goal
  PIDAngleRotateAbs(175, 4, 0.1, 35, 1.5);
  setPistonFW(true);
  this_thread::sleep_for(100);
  setIntakeSpeed(-100); 
  timerForward(100, 700);
  // timerForward(100, 200);
  // PIDAngleRotateAbs(190);
  // timerForward(-100, 200);

  printf ("\n===== far_4: End: Elased=%.i =====\n", autotimer.getTime());
  return;
}
