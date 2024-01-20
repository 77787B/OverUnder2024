#include "autonomous.h"
#include "parameters.h"
#include "my-timer.h"
#include "robot-config.h"
#include "GPS.h"

/**
 * Far 2: ? goal
*/
void far_2() {
  printf ("\nfar_2:\n");

  MyTimer autotimer;
  autotimer.reset();

  setIntakeSpeed(75);
  MyGps.gpsPIDMove(0, -40, -1);
  this_thread::sleep_for(600);  
  setIntakeSpeed(0);

  // push red ball in
  PIDPosCurveAbs(1235, 1740, 50);  
  this_thread::sleep_for(100);
  timerForward(100, 450); 
  this_thread::sleep_for(100); 
  timerForward(-150, 135);  

  // push green ball in (the one under the red pole)
  this_thread::sleep_for(100);  
  PIDAngleRotateAbs(100);
  this_thread::sleep_for(100); 
  setIntakeSpeed(-100);
  this_thread::sleep_for(750); 
  setIntakeSpeed(0);
  PIDAngleRotateAbs(105);
  timerForward(-150, 400);
  PIDAngleRotateAbs(105);
  timerForward(175, 135); 
  this_thread::sleep_for(100); 

  // get the second green ball
  PIDAngleRotateAbs(35); 
  setIntakeSpeed(70);
  MyGps.gpsPIDMove(-1275, 75, -1); 
  this_thread::sleep_for(500);  
  setIntakeSpeed(0); 

  //push ball in goal
  MyGps.gpsPIDMove(-1525, 575, -1);
  setIntakeSpeed(-100);
  this_thread::sleep_for(750);
  setIntakeSpeed(0);
  timerForward(-150, 400);
  this_thread::sleep_for(100);
  MyGps.gpsPIDMove(-1450, 500, 1);

  Brain.Screen.setCursor(11, 1);
  Brain.Screen.print("AutonTimer: %d               ", autotimer.getTime());
}

