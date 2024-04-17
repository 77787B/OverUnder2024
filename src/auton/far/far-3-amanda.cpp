#include "autonomous.h"
#include "parameters.h"
#include "my-timer.h"
#include "robot-config.h"
#include "GPS.h"
#include "basic-functions.h"

void far_3_amanda() {

/* POSITIONING:
CENTER (Any face) OF BLUE BALL --> BACK AGAINST BAR, BARELY TOUCHING ROBOT
ORANGE BOX --> EDGE OF POLE (LEFT SIDE)
BACK SLEDS --> EDGE AND RIGHT ON TOP OF BOX

ISSUES:
TRIBALL IS INTAKED TOO FAR --> IF THERE IS NO MORE RUBBERBAND.. ADD:
this_thread::sleep_for(SOMETHING) and setIntakeSpeed(0);
MOTOR 14
CHECK BACKWINGS
FRONT WINGS
FIND WAY TO SMACK BALL WITH WING WHILE GETTING MIDDLE BALL
DO THREADS TO DO MULTIPLE TASKS AT SAME TIME TO SAVE TIME

STUFF:
TIME NEEDED FOR ROBOT TO INTAKE BALL --> 200???
TURN ON/OFF INTAKE AFTER REACHING POSITION NEEDED!
CHANGE THIS SO THE ROBOT IS CONSISTENT IN GRABBING TRIBALL!!!
*/
  MyTimer autotimer;
  autotimer.reset();

  // posForwardAbsWithHeading(40, -600, -135);
  // this_thread::sleep_for(100000);
  //BALL 1 - get ball in middle
  setIntakeSpeed(100);
  posForwardAbsWithHeading(90, 1400, 14.5);
  PIDPosForwardAbs(1550);
  this_thread::sleep_for(200);

  // go back to red pole and spit out ball
  posForwardAbsWithHeading(-100, 170, 50);
  PIDPosForwardAbs(150);
  setIntakeSpeed(-100);
  PIDAngleRotateAbs(85);
  this_thread::sleep_for(200);

  //BALL 2 - get ball under hang pole
  setIntakeSpeed(100);
  PIDAngleRotateAbs(-55);
  // posForwardAbsWithHeading(80, 600, -55);
  // posForwardAbsWithHeading(30, 850, -30);
  PIDPosForwardAbs(880);
  this_thread::sleep_for(200);


  //move backwards to bar after grabbing triball
  PIDAngleRotateAbs(-45);
  setIntakeSpeed(0);

  //BALL 3 - grab ball in corner with backwing
  PIDPosForwardAbs(-930);
  PIDAngleRotateAbs(-75);
  setPistonBLW(true);
  // posForwardAbs(20, -);
  PIDPosForwardRel(-420);
  setPistonBLW(false);
  this_thread::sleep_for(100);

  //PUSH 3 BALLS INTO GOAL
  posForwardAbsWithHeading(20, -700, -145);
  timerForward(-100, 300);

  //BALL 4 - go to center and scoop
  PIDPosForwardRel(225);
  PIDAngleRotateAbs(-45);
  setPistonFW(true);
  posForwardAbsWithHeading(60, 850, 45);
  PIDAngleRotateAbs(135);
  setIntakeSpeed(-100);
  timerForward(100, 400);

  //ENDING POINT - 5TH BALL PUSHED INTO GOAL, GOING FOR 6TH ONE ON TOP LEFT CORNER OF HORIZONTAL POLE

  Brain.Screen.setCursor(11, 1);
  Brain.Screen.print("AutonTimer: %d               ", autotimer.getTime());
}