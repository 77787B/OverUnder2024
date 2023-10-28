#include "autonomous.h"
#include "parameters.h"
#include "my-timer.h"
#include "robot-config.h"
#include "GPS.h"

void auton_far_4balls() {
  //pickup first ball
  setIntakeSpeed(90);
  MyGps.gpsPIDMove(595, -1160, -1, 70);
  PIDAngleRotateAbs(-35.0);
  timerForward(-40, 200);
  PIDAngleRotateAbs(-90.0);
  timerForward(-40, 400);
  setIntakeSpeed(20);

  ///push first ball
  MyGps.resetForwardPosGps();
  MyGps.gpsPIDMove(-820, 0, 1, 70, "heading");

  //second ball
  timerForward(-50, 200);
  PIDAngleRotateAbs(90.0);
  setIntakeSpeed(-100);
  this_thread::sleep_for(600);
  timerForward(-100, 400);

  //third ball
   setIntakeSpeed(100);
   MyGps.gpsPIDMove(-500, 800, -1, 60);
  PIDAngleRotateAbs(-90.0, 2, 0.4, 35, 1.5);
  timerForward(-40, 400);
   setIntakeSpeed(20);
   MyGps.gpsPIDMove(-500, 520, -1, 70, "heading");

  PIDAngleRotateAbs(90.0, 2, 0.4, 35, 1.5);
  setIntakeSpeed(-100);
  this_thread::sleep_for(500);
  timerForward(-100, 800);
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
