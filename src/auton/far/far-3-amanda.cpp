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
 posForwardAbsWithHeading(90, 1400, 15);
 PIDPosForwardAbs(1550);
 this_thread::sleep_for(200);


 // go back to red pole and spit out ball
 posForwardAbsWithHeading(-100, 170, 18);
 PIDPosForwardAbs(170);
 setIntakeSpeed(-100);
 PIDAngleRotateAbs(70);
 this_thread::sleep_for(200);


 //BALL 2 - get ball under hang pole
 setIntakeSpeed(100);
 PIDAngleRotateAbs(-55);
 // posForwardAbsWithHeading(80, 600, -55);
 // posForwardAbsWithHeading(30, 850, -30);
 PIDPosForwardAbs(900);
 this_thread::sleep_for(200);

 //move backwards to bar after grabbing triball
 PIDAngleRotateAbs(-45);
 setIntakeSpeed(0);
 PIDPosForwardAbs(-920);

 //BALL 3 - grab ball in corner with backwing
 PIDAngleRotateAbs(-75);
 setPistonBLW(true);
PIDPosForwardRel(-420);//-400
this_thread::sleep_for(50);
setPistonBLW(false);

 //PUSH 3 BALLS INTO GOAL
 posForwardAbsWithHeading(20, -600, -145);
 setPistonBRW(true);//TEST
 this_thread::sleep_for(600);
 timerForward(-90, 350);


 //BALL 4 - go to center and scoop
 PIDPosForwardRel(200);
 setPistonBRW(false);
 PIDAngleRotateAbs(-45);
 setPistonFW(true);
 posForwardAbsWithHeading(55, 1050, 30);
 PIDAngleRotateAbs(135);
 setIntakeSpeed(-100);
 timerForward(100, 500);
 this_thread::sleep_for(200);


//  //BALL 5 - GRAB TRIBALL AT BAR, INTAKE AND STOP!
//  PIDPosForwardAbs(-50);
//  setIntakeSpeed(100);
//  PIDAngleRotateAbs(253);
//  posForwardAbsWithHeading(20, 500, 253);
//  setPistonFW(false);



 Brain.Screen.setCursor(11, 1);
 Brain.Screen.print("AutonTimer: %d               ", autotimer.getTime());
}
