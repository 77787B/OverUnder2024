#include "autonomous.h"
#include "parameters.h"
#include "my-timer.h"
#include "robot-config.h"
#include "GPS.h"

void far_3_amanda() {

/* POSITIONING:
CENTER (Any face) OF BLUE BALL --> TIP OF FRONT WING (3rd hole)
ORANGE BOX --> EDGE OF POLE (LEFT SIDE)
BACK SLEDS --> EDGE AND RIGHT ON TOP OF BOX

ISSUES:
TRIBALL IS INTAKED TOO FAR --> IF THERE IS NO MORE RUBBERBAND.. ADD:
this_thread::sleep_for(SOMETHING) and setIntakeSpeed(0);
MOTOR 14
FRONT WINGS
*/
  MyTimer autotimer;
  autotimer.reset();

  //kick blue ball at start
  setPistonFW(true);
  this_thread::sleep_for(400); //FIX NUMBER ACCORDINGLY, AIR IS LEAKING!!
  setPistonFW(false);
  //get first ball in middle
  setIntakeSpeed(100);
  MyGps.gpsPIDMove(0, 1570, 1, 100); //STRAIGHT line for middle ball
  this_thread::sleep_for(400); //gives time for robot to intake ball
  //go back to red pole
  MyGps.gpsPIDMove(0, 50, -1, 100);
  setIntakeSpeed(-100);
  PIDAngleRotateAbs(65);
  this_thread::sleep_for(200);
  //get second ball under hang pole
  PIDAngleRotateAbs(290);
  setIntakeSpeed(100);
  MyGps.gpsPIDMove(-800, 550, 1, 100);
  setIntakeSpeed(0);
  this_thread::sleep_for(200);//300
  //move backwards to bar after grabbing triball
  MyGps.gpsPIDMove(-30, -25, -1, 90);
  PIDAngleRotateAbs(-90);
  //grab triball in corner with backwing
  setPistonBW(true);
  MyGps.gpsPIDMove(-10, -25, -1, 80);
  setPistonBLW(false);
  PIDAngleRotateAbs(65);
  setIntakeSpeed(-100);
  this_thread::sleep_for(400);

  // PIDPosCurveAbs(750, 900, 90);
  // PIDAngleRotateAbs(180);
  // setIntakeSpeed(0);

  Brain.Screen.print("AutonTimer: %d               ", autotimer.getTime());
  return;
}