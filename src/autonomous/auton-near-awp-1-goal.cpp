#include "autonomous.h"
#include "parameters.h"
#include "my-timer.h"
#include "robot-config.h"
#include "GPS.h"

void auton_near_awp_1_goal_() {
  setPistonTB(true);
}

void auton_near_awp_1_goal() {
  printf ("\nauton_near_awp_1_goal:\n");
  setPistonRW(true);
  this_thread::sleep_for(500);
  setPistonTB(true);
  this_thread::sleep_for(500);
  PIDAngleRotateAbs(-125);
  this_thread::sleep_for(200);
  setPistonTB(false);
  setPistonRW(false);
  this_thread::sleep_for(100);

  PIDAngleRotateAbs(90);
  PIDPosCurveAbs(700, 480, 50);  
  timerForward(100, 200); 
  this_thread::sleep_for(500);

  MyGps.gpsPIDMove(0, 0, -1);
  PIDAngleRotateAbs(45);
  MyGps.gpsPIDMove(-700, -600, -1);
  PIDPosForwardRel(0);

  setIntakeSpeed(-100);
  this_thread::sleep_for(500);  
  setIntakeSpeed(0);
}
