#include "autonomous.h"
#include "parameters.h"
#include "my-timer.h"
#include "robot-config.h"
#include "GPS.h"

/**
 * Far 4: 4 goal
*/
void far_4() {
  //pickup first ball
  MyGps.gpsPIDMove(600, -1170, -1, 70);
  setIntakeSpeed(70);
  PIDAngleRotateAbs(-35.0);
  timerForward(-40, 200);
  PIDAngleRotateAbs(-90.0);
  timerForward(-40, 250);
  setIntakeSpeed(30);

  ///push first ball
  MyGps.resetForwardPosGps();
  MyGps.gpsPIDMove(-820, 0, 1, 70, "heading");

  //second ball
  MyGps.gpsPIDMove(-780, 5, -1, 70, "heading");
  PIDAngleRotateAbs(90.0, 1.5);
  setIntakeSpeed(-100);
  PIDAngleRotateAbs(95.0, 1.3);
  this_thread::sleep_for(700);
  timerForward(-100, 250);

  //third ball
  this_thread::sleep_for(400);
  MyGps.gpsPIDMove(-550, 700, -1, 60);
  setIntakeSpeed(90);
  PIDAngleRotateAbs(-100.0, 2, 0.4, 35, 1.5);
  timerForward(-60, 450);
  setIntakeSpeed(30);
  MyGps.gpsPIDMove(-500, 520, -1, 70, "heading");

  PIDAngleRotateAbs(90.0, 2, 0.4, 35, 1.5);
  setIntakeSpeed(-100);
  this_thread::sleep_for(300);
  timerForward(-100, 600);
  timerForward(100, 300);

  //fourth ball
  /*
  MyGps.gpsPIDMove(-40, 900, 1, 70, "heading");
  setIntakeSpeed(100);
  MyGps.gpsPIDMove(-880, 1320, -1, 70, "heading");
  setIntakeSpeed(0);
  MyGps.gpsPIDMove(-300, 550, 1, 70, "heading");
  MyGps.gpsPIDMove(-600, 550, -1, 70, "heading");
  PIDAngleRotateAbs(90.0);
  setIntakeSpeed(-100);
  this_thread::sleep_for(500);
  timerForward(-100, 800);
  */
}
