#include "autonomous.h"
#include "parameters.h"
#include "my-timer.h"
#include "robot-config.h"
#include "GPS.h"

/**
 * For testing code
*/
void auton_near_1_t() {
  PIDPosCurveAbs(1400, 850, 50);
}

/**
 * Real auton near 1
*/
void auton_near_1() {
  PIDPosCurveAbs(1400, 850, 50);
  timerForward(80, 250);
  this_thread::sleep_for(200);
  timerForward(-20, 200); 

  PIDAngleRotateAbs(45);
  MyGps.gpsPIDMove(250, 350, -1);

  PIDAngleRotateAbs(-45);
  timerForward(20, 900); 
  
  setPistonTB(true);
  this_thread::sleep_for(800);
  PIDAngleRotateAbs(-135);
  this_thread::sleep_for(200);
  setPistonTB(false);
  timerForward(50, 150);  
  
  this_thread::sleep_for(200); 
  PIDAngleRotateAbs(-170);
  timerForward(50, 150); 
  MyGps.gpsPIDMove(-50, -275, -1);
}

/**
 * auton near 1: attempted approach
*/


