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
  posForwardAbsWithHeading(90, 450, -50);
  posForwardAbsWithHeading(30, 850, -50);
  //move backwards to bar after grabbing triball
  PIDPosForwardAbs(-350);
  setIntakeSpeed(0);

  //BALL 4 - grab ball in corner with backwing
  setPistonBLW(true);
  posForwardAbsWithHeading(30, -450, -90);
  this_thread::sleep_for(300);
  setPistonBLW(false);
  setIntakeSpeed(0);

  //PUSH 3 BALLS INTO GOAL - FIX THIS
  PIDAngleRotateAbs(-105);
  this_thread::sleep_for(200);
  timerForward(-80, 400);
  timerForward(60, 400);
  PIDAngleRotateAbs(-120);
  this_thread::sleep_for(200);
  timerForward(-100, 500);
  //ADD A CURVE HERE INSTEAD OF THE TURN BACK TURN? - IF ANDREW SAYS IS GOOD
  // PIDPosCurveAbs(200, 400, -70);//CURVE ISNT WORKING PROPERLY
  // MyGps.gpsPIDCurve(700, 60, -133, 10);//x, y, heading, duration


  //STUFF AFTER PUSHING BALLS (OUTTAKE INTAKE TRIBALL AND PUSH IN FROM FRONT) - FIX THIS
  // timerForward(60, 500);
  // PIDAngleRotateAbs(55);
  // setIntakeSpeed(-100);
  // this_thread::sleep_for(400);
  // timerForward(100, 400);
  


  //BALL 5 - go to center and scoop


  setPistonBW(false);

  Brain.Screen.setCursor(11, 1);
  Brain.Screen.print("AutonTimer: %d               ", autotimer.getTime());
}