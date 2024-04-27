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




//BALL 1 - get ball in middle
setIntakeSpeed(100);
// posForwardAbsWithHeading(90, 1400, 15); - SLOWER CODE FOR GRABBING, UPDATED TO 100 SPEED
posForwardAbsWithHeading(100, 1295, 5);
PIDPosForwardAbs(1550);
this_thread::sleep_for(100);
// go back to red pole and spit out ball
MyGps.gpsPIDMove(-200, 150, -1, 100);
setIntakeSpeed(-100);
PIDAngleRotateAbs(70);
this_thread::sleep_for(100);




//BALL 2 - get ball under hang pole
setIntakeSpeed(100);
PIDAngleRotateAbs(-50);
PIDPosForwardAbs(800);
this_thread::sleep_for(100);
//move backwards to bar after grabbing triball
PIDAngleRotateAbs(-45);
setIntakeSpeed(0);
PIDPosForwardAbs(-900);//-920




//BALL 3 - grab ball in corner with backwing
PIDAngleRotateAbs(-75);
setPistonBLW(true);
PIDPosForwardRel(-370);//-400
PIDAngleRotateAbs(-75);
setPistonBLW(false);


//PUSH 3 BALLS INTO GOAL
setPistonBRW(true);
posForwardAbsWithHeading(20, -250, -125);//?, ?, -130
timerForward(-100, 350);
this_thread::sleep_for(50);
timerForward(40, 200);//125
setPistonBRW(false);
this_thread::sleep_for(50);
// PIDAngleRotateAbs(-35);//TEST
PIDAngleRotateAbs(60);
setIntakeSpeed(-100);
setPistonFW(true);
timerForward(100, 400);
this_thread::sleep_for(100);//200
setIntakeSpeed(0);
setPistonFW(false);
//BALL 4 - left triball at black pole
PIDPosForwardRel(-200);
setPistonBRW(false);
PIDAngleRotateAbs(-45);
setIntakeSpeed(100);
posForwardAbsWithHeading(75, 1100, -20);//-360
PIDPosForwardAbs(1100);
this_thread::sleep_for(100);


setIntakeSpeed(0);
PIDAngleRotateAbs(30);
posForwardRelWithHeading(100, 300, 45);
PIDAngleRotateAbs(135);
setPistonFW(true);


setIntakeSpeed(-100);


//posForwardRelWithHeading(70, 1000, 135);
timerForward(100, 400);
// setIntakeSpeed(-100);
// PIDPosForwardRel(300);
Brain.Screen.setCursor(11, 1);
Brain.Screen.print("AutonTimer: %d               ", autotimer.getTime());


}