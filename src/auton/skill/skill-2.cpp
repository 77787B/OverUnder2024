#include "skill.h"
#include "parameters.h"
#include "my-timer.h"
#include "robot-config.h"
#include "GPS.h"
#include "basic-functions.h"

//driver

void skill_2(){
  MyTimer autotimer;
  autotimer.reset();

  MyGps.gpsPIDMove(-315, -310, -1, 50);
  PIDAngleRotateAbs(116);
  setPistonBW(true);
  setIntakeSpeed(-100);
  this_thread::sleep_for(100);
  setCatapultSpeed(75);
  this_thread::sleep_for(25000); // TODO: use this for real run
  // this_thread::sleep_for(2000);
  setCatapultSpeed(0);
  setPistonBW(false);
  setIntakeSpeed(0);

  printf ("\n===== skill_driver: End: Elased=%.i =====\n", autotimer.getTime());
  Brain.Screen.print("AutonTimer: %d               ", autotimer.getTime());
}
