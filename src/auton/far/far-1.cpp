#include "autonomous.h"
#include "parameters.h"
#include "my-timer.h"
#include "robot-config.h"
#include "GPS.h"

/**
 * Far 1: AWP: 1 goal
*/
void far_1() {

setIntakeSpeed(100);
  MyGps.gpsPIDMove(0, -40, -1);
  this_thread::sleep_for(850);  
  setIntakeSpeed(0);

  // push red ball in
  PIDPosCurveAbs(1365, 1850, 50);
  this_thread::sleep_for(200);
  timerForward(100, 450); 
  this_thread::sleep_for(250); 
  timerForward(-150, 135);  

  // push green ball in
  this_thread::sleep_for(300);  
  PIDAngleRotateAbs(100);
  this_thread::sleep_for(200); 
  setIntakeSpeed(-100);
  this_thread::sleep_for(1000); 
  setIntakeSpeed(0);
  PIDAngleRotateAbs(105);
  this_thread::sleep_for(200); 
  timerForward(-150, 400);
  this_thread::sleep_for(250); 
  timerForward(175, 135); 
  this_thread::sleep_for(250); 
  // go back to starting position
  MyGps.gpsPIDMove(-350, 650, -1);
  this_thread::sleep_for(250); 
  MyGps.gpsPIDMove(-350, 35, -1);
  
  MyTimer autotimer;
  autotimer.reset();

  Brain.Screen.setCursor(11, 1);
  Brain.Screen.print("AutonTimer: %d               ", autotimer.getTime());
}
