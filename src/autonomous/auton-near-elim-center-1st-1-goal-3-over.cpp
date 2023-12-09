#include "autonomous.h"
#include "parameters.h"
#include "my-timer.h"
#include "robot-config.h"
#include "GPS.h"

void auton_near_elim_center_1st_1_goal_3_over_() {
  printf ("\n===== auton_near_elim_center_1st_1_goal_3_over: Start =====\n");
  MyGps.gpsPIDMove(100, 100, 1);
}

void auton_near_elim_center_1st_1_goal_3_over() {
  printf ("\n===== auton_near_elim_center_1st_1_goal_3_over: Start =====\n");

  MyTimer autotimer;
  autotimer.reset();

  setPistonRW(true);
  this_thread::sleep_for(500);
  setPistonRW(false);

  setIntakeSpeed(100);
  MyGps.gpsPIDMove(0, -1250, -1);
  this_thread::sleep_for(500);
  setIntakeSpeed(0);

  MyGps.gpsPIDMove(0, -500, 1);
  PIDAngleRotateAbs(30);

  MyGps.gpsPIDMove(300, 50, 1);
  setPistonTB(true);
  PIDAngleRotateAbs(-100);
  this_thread::sleep_for(500);
  setPistonTB(false);

  PIDAngleRotateAbs(-240);
  MyGps.gpsPIDMove(-100, 50, -1);

  MyGps.gpsPIDMove(-580, 50, -1);

  setIntakeSpeed(-100);
  this_thread::sleep_for(2000);
  setIntakeSpeed(0);

  MyGps.gpsPIDMove(100, 50, 1);
  MyGps.gpsPIDMove(700, -300, 1);
  PIDAngleRotateAbs(165);
  
  timerForward(100, 200); 

  printf ("\n===== auton_near_elim_center_1st_1_goal_3_over: End: Elased=%.i =====\n", autotimer.getTime());
}
