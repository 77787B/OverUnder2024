#include "autonomous.h"
#include "parameters.h"
#include "my-timer.h"
#include "robot-config.h"
#include "GPS.h"

void auton_near_awp_only_() {
  PIDAngleRotateAbs(-125);
}

void auton_near_awp_only() {
  printf ("\n::auton_near_awp_only::\n");
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
