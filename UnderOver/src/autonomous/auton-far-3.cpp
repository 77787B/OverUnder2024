#include "autonomous.h"
#include "parameters.h"
#include "my-timer.h"
#include "robot-config.h"
#include "GPS.h"


void auton_far_3() {
  printf ("\nauton_scenario_5_far_3:\n");

  MyTimer autotimer;
  autotimer.reset();

  setIntakeSpeed(75);
  MyGps.gpsPIDMove(0, -40, -1);
  this_thread::sleep_for(600);  
  setIntakeSpeed(0);

  // push red ball in
  PIDPosCurveAbs(1200, 1675, 57);
  this_thread::sleep_for(100);
  timerForward(100, 450); 
  this_thread::sleep_for(100); 
  timerForward(-150, 135);  

  // push green ball in (the one under the red pole)
  this_thread::sleep_for(200);  
  PIDAngleRotateAbs(100);
  this_thread::sleep_for(100); 
  setIntakeSpeed(-100);
  this_thread::sleep_for(650); 
  setIntakeSpeed(0);
  PIDAngleRotateAbs(105);
  timerForward(-150, 400);
  PIDAngleRotateAbs(105);
  timerForward(175, 135); 
  this_thread::sleep_for(100); 

  // get the second green ball
  PIDAngleRotateAbs(35); 
  // MyGps.gpsPIDMove(-1100, 300, -1); 
  setIntakeSpeed(70);
  MyGps.gpsPIDMove(-1325, 25, -1); 
  this_thread::sleep_for(500);  
  setIntakeSpeed(0); 

  //push ball in goal
  MyGps.gpsPIDMove(-1500, 575, -1);
  setIntakeSpeed(-100);
  this_thread::sleep_for(650);
  setIntakeSpeed(0);
  timerForward(-150, 400);
  this_thread::sleep_for(100);
  timerForward(150, 200);

  Brain.Screen.setCursor(11, 1);
  Brain.Screen.print("AutonTimer: %d               ", autotimer.getTime());
}


void auton_far_3_3rd_ball() {
  MyTimer autotimer;
  autotimer.reset();

  PIDAngleRotateAbs(-65); 
  MyGps.gpsPIDMove(1000, -500, -1); 
  setIntakeSpeed(100);
  MyGps.gpsPIDMove(1200, -500, -1); 
  this_thread::sleep_for(600);  
  setIntakeSpeed(0); 

  MyGps.gpsPIDMove(700, -900, -1);
  PIDAngleRotateAbs(90);
  setIntakeSpeed(-100);
  this_thread::sleep_for(600);
  setIntakeSpeed(0);
  timerForward(-60, 400);

  //push ball in goal

  Brain.Screen.setCursor(11, 1);
  Brain.Screen.print("AutonTimer: %d               ", autotimer.getTime());
}