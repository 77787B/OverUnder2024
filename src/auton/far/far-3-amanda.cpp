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
  posForwardAbsWithHeading(90, 1350, 13);//middle term 1305
  posForwardAbsWithHeading(50, 1450, 13);//middle term 1450 
  setIntakeSpeed(100);

  // posForwardAbsWithHeading(90, 1380, 13); //speed, distance, angle //DISTANCE - 1335
  // PIDAngleRotateAbs(13);


  // go back to red pole and spit out ball
  MyGps.gpsPIDMove(-200, -50, -1, 100);
  setIntakeSpeed(0);
  setIntakeSpeed(-100);
  PIDAngleRotateAbs(85);

  //BALL 3 - get ball under hang pole
  setIntakeSpeed(100);
  PIDAngleRotateAbs(-48);
  posForwardAbsWithHeading(90, 420, -50);
  posForwardAbsWithHeading(30, 1000, -50);
  //move backwards to bar after grabbing triball
  PIDPosForwardAbs(-250);
  setIntakeSpeed(0);

  //BALL 4 - grab ball in corner with backwing - NEED CHANGES TO THE CURVE AND EVERYTHING AFTER THE CURVE AFTER DROPPING THE BACKWING, TRY ADDING A FAST AND SLOW TIMERFORWARD
  setPistonBLW(true);
  posForwardAbsWithHeading(15, -475, -90);
  this_thread::sleep_for(300);
  setPistonBLW(false);


  posForwardAbsWithHeading(15, -525, -90);



  setIntakeSpeed(0);
  //PUSH 3 BALLS INTO GOAL
  PIDAngleRotateAbs(-90);
  posForwardAbsWithHeading(50, -300, 120);
  PIDAngleRotateAbs(-135);
  timerForward(60, 100);
  timerForward(-70, 400);
  //PUSH IN BALL (FROM INTAKE) INTO GOAL FROM FRONT
  timerForward(50, 100);
  PIDAngleRotateAbs(55);
  setIntakeSpeed(-100);
  timerForward(50, 250);
  timerForward(80, 300);
  PIDAngleRotateAbs(-135);
  timerForward(-80, 350);

  //BALL 5 - go to center and scoop
  timerForward(-100, 300);
  PIDAngleRotateAbs(-30);
  setIntakeSpeed(100);
  posForwardAbsWithHeading(80, 450, -30);
  posForwardAbsWithHeading(50, 700, -30);
  // setPistonFW(true);
  // PIDAngleRotateAbs(80);
  // setIntakeSpeed(0);
  // posForwardAbsWithHeading(70, 800, 250);
  // this_thread::sleep_for(400);
  // setPistonFW(false);

  Brain.Screen.setCursor(11, 1);
  Brain.Screen.print("AutonTimer: %d               ", autotimer.getTime());
}