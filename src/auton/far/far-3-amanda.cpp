#include "autonomous.h"
#include "parameters.h"
#include "my-timer.h"
#include "robot-config.h"
#include "GPS.h"
#include "basic-functions.h"

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
FIND WAY TO SMACK BALL WITH WING WHILE GETTING MIDDLE BALL
DO THREADS TO DO MULTIPLE TASKS AT SAME TIME TO SAVE TIME

STUFF:
TIME NEEDED FOR ROBOT TO INTAKE BALL --> 200???
TURN ON/OFF INTAKE AFTER REACHING POSITION NEEDED!
CHANGE THIS SO THE ROBOT IS CONSISTENT IN GRABBING TRIBALL!!!
*/
  MyTimer autotimer;
  autotimer.reset();

  //BALL 1 - kick blue ball at start

  //BALL 2 - get ball in middle
  posForwardAbsWithHeading(90, 1400, 13);
  setIntakeSpeed(100);

  // posForwardAbsWithHeading(90, 1380, 13); //speed, distance, angle //DISTANCE - 1335
  // PIDAngleRotateAbs(13);


  // go back to red pole and spit out ball
  MyGps.gpsPIDMove(-200, -50, -1, 100);
  setIntakeSpeed(0);
  setIntakeSpeed(-100);
  PIDAngleRotateAbs(85);
  setIntakeSpeed(0);

  //BALL 3 - get ball under hang pole
  PIDAngleRotateAbs(-48);
  setIntakeSpeed(100);
  posForwardAbsWithHeading(90, 400, -50);
  posForwardAbsWithHeading(30, 850, -50);
  //move backwards to bar after grabbing triball
  PIDPosForwardAbs(-300);
  setIntakeSpeed(0);

  //BALL 4 - grab ball in corner with backwing
  setPistonBLW(true);
  posForwardAbsWithHeading(30, -450, -90);
  this_thread::sleep_for(300);
  setPistonBLW(false);
  setIntakeSpeed(0);

  //PUSH 3 BALLS INTO GOAL
  // posForwardAbsWithHeading(80, 1450, 5); //speed, distance, angle
  // this_thread::sleep_for(300);
  // MyGps.gpsPIDMove(440, 20, 1, 70);//move forward away from goal
  // PIDAngleRotateAbs(45);
  // this_thread::sleep_for(200);
  // setIntakeSpeed(-100);
  // MyGps.gpsPIDMove(670, 200, 1, 80);
  // MyGps.gpsPIDMove(440, 20, -1, 70);
  // setIntakeSpeed(0);
  // PIDAngleRotateAbs(-135);
  // MyGps.gpsPIDMove(670, 200, -1, 100);

  //BALL 5 - go to center and scoop
  // MyGps.gpsPIDMove();

  setPistonBW(false);

  Brain.Screen.setCursor(11, 1);
  Brain.Screen.print("AutonTimer: %d               ", autotimer.getTime());
}