#include "autonomous.h"
#include "parameters.h"
#include "my-timer.h"
#include "robot-config.h"
#include "GPS.h"

void auton_near_2() {
  // push in first ball
  PIDPosCurveAbs(1400, 900, 50);
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
//   timerForward(50, 150); 
  MyGps.gpsPIDMove(0, -375, 1);

}
