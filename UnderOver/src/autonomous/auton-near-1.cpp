#include "autonomous.h"
#include "parameters.h"
#include "my-timer.h"
#include "robot-config.h"
#include "GPS.h"

void auton_near_1() {
  printf ("\nauton_scenario_2_near_1:\n");
  setPistonTB(true);
  this_thread::sleep_for(500);
  PIDAngleRotateAbs(-125);
  this_thread::sleep_for(200);
  setPistonTB(false);
  this_thread::sleep_for(100);
  PIDAngleRotateAbs(-108);
  timerForward(50, 300); 
  this_thread::sleep_for(100);
  MyGps.gpsPIDMove(-660, -555);
} 

void auton_near_1_current() {
  PIDAngleRotateAbs(-45);
  timerForward(20, 350);
  setPistonTB(true);
  this_thread::sleep_for(500);
  PIDAngleRotateAbs(-175);
  this_thread::sleep_for(200);
  setPistonTB(false);
  MyGps.gpsPIDMove(-80, -880);
} 

void auton_near_1_original() {
  // push in first ball
  PIDPosCurveAbs(1400, 850, 50);
  timerForward(80, 250);
  this_thread::sleep_for(200);
  timerForward(-20, 200); 

  // go to triangle
  PIDAngleRotateAbs(45);
  MyGps.gpsPIDMove(250, 350, -1);
  PIDAngleRotateAbs(-45);
  timerForward(20, 900); 
  
  // get second ball out
  setPistonTB(true);
  this_thread::sleep_for(800);
  PIDAngleRotateAbs(-135);
  this_thread::sleep_for(200);
  setPistonTB(false);
  
  // turn around push second ball and go to bar
  this_thread::sleep_for(200); 
  PIDAngleRotateAbs(-170);
  timerForward(50, 150); 
  MyGps.gpsPIDMove(-50, -275, -1);

}

/**
 * auton near 1: attempted approach
*/


