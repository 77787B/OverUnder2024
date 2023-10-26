#include "autonomous.h"
#include "parameters.h"
#include "my-timer.h"
#include "robot-config.h"
#include "GPS.h"

void auton_far_1() { //AWP SAFETY
  printf ("\nauton_scenario_1_far_1:\n");

  MyTimer autotimer;
  autotimer.reset();

  setIntakeSpeed(100);
  MyGps.gpsPIDMove(0, -40, -1);
  this_thread::sleep_for(800);  
  setIntakeSpeed(0);

  // push red ball in
  PIDPosCurveAbs(1330, 1835, 50);
  this_thread::sleep_for(300); 
  timerForward(175, 200); 
  this_thread::sleep_for(1000); 
  timerForward(-150, 100);  
  this_thread::sleep_for(500);

  // push green ball in
  this_thread::sleep_for(500);  
  PIDAngleRotateAbs(90);
  this_thread::sleep_for(200); 
  setIntakeSpeed(-100);
  this_thread::sleep_for(400); 
  setIntakeSpeed(0);
  timerForward(-150, 500);
  this_thread::sleep_for(500); 
  timerForward(175, 100); 
  this_thread::sleep_for(500); 
  // go back to starting position
  MyGps.gpsPIDMove(-250, 650, -1);
  this_thread::sleep_for(500); 
  MyGps.gpsPIDMove(-250, 25, -1);

}

void auton_far_1_test() { //AWP SAFETY
  printf ("\nauton_scenario_1_far_1:\n");

  MyTimer autotimer;
  autotimer.reset();

  /***** 1: Push tribal into goal *****/
  
  // 1.1
  MyGps.gpsPIDMove(0, 650, 1);
  this_thread::sleep_for(100); 
  timerForward(60, 400);
  
  // /***** 2: Move back to bar *****/

  // // 2.1
  MyGps.gpsPIDMove(0, 0, -1);
  this_thread::sleep_for(500); 

  // // 2.2
  PIDAngleRotateAbs(60);
  this_thread::sleep_for(100); 
  timerForward(-70, 375);
}
