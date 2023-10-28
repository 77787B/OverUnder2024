#include "autonomous.h"
#include "parameters.h"
#include "my-timer.h"
#include "robot-config.h"
#include "GPS.h"

void auton_far_1_t() { //AWP SAFETY
  printf ("\nauton_far_1_test:\n");
  setIntakeSpeed(-100);
  this_thread::sleep_for(1000); 
  setIntakeSpeed(0);
}


/**
 * Real one
*/
void auton_far_1() { //AWP SAFETY
  printf ("\nauton_scenario_1_far_1:\n");

  MyTimer autotimer;
  autotimer.reset();

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

}

/**
 * Backup
*/
void auton_far_1_backup() { //AWP SAFETY
  printf ("\nauton_scenario_1_far_1:\n");

  MyTimer autotimer;
  autotimer.reset();

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
  this_thread::sleep_for(700); 
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

}