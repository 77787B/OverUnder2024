#include "autonomous.h"
#include "parameters.h"
#include "my-timer.h"
#include "robot-config.h"
#include "GPS.h"

void auton_near_elim_1_goal_3_over_() {
  printf ("\auton_near_elim_1_goal_3_over: Start \n");
  MyGps.gpsPIDMove(100, 100, 1);
}

void auton_near_elim_1_goal_3_over() {
  printf ("\n===== auton_near_elim_1_goal_3_over: Start =====\n");

  MyTimer autotimer;
  autotimer.reset();

  setPistonRW(true);
  // this_thread::sleep_for(500);
  setPistonTB(true);
  this_thread::sleep_for(500);
  PIDAngleRotateAbs(-125);
  // this_thread::sleep_for(200);
  setPistonTB(false);
  setPistonRW(false);
  // this_thread::sleep_for(100);

  printf ("===== MyGps.gpsPIDMove: Rotate to align to allowance triball =====\n");
  PIDAngleRotateAbs(-38);

  printf ("===== MyGps.gpsPIDMove: Move to center ball =====\n");
  MyGps.gpsPIDMove(425, -1150, -1);
  printf ("===== PIDAngleRotateAbs: Rotate to line up horizontally to the ball =====\n");
  PIDAngleRotateAbs(-45);

  setIntakeSpeed(100);
  printf ("===== MyGps.gpsPIDMove: Intake =====\n");
  MyGps.gpsPIDMove(480, -1215, -1, 50);
  this_thread::sleep_for(300);  
  setIntakeSpeed(0);

  printf ("===== MyGps.gpsPIDMove: Back to corner =====\n");
  MyGps.gpsPIDMove(0, 0, 1);

  printf ("===== PIDAngleRotateAbs: Rotate to face hang bar backware =====\n");
  PIDAngleRotateAbs(45);

  printf ("===== MyGps.gpsPIDMove: Back to corner =====\n");
  MyGps.gpsPIDMove(-700, -600, -1);
  setIntakeSpeed(-100);
  this_thread::sleep_for(500);  
  setIntakeSpeed(0);

  printf ("===== MyGps.gpsPIDMove: Push allowance triball =====\n");
  MyGps.gpsPIDMove(0, 0, 1);
  PIDAngleRotateAbs(90);
  
  printf ("===== MyGps.gpsPIDMove: Push allowance triball: curve =====\n");
  PIDPosCurveAbs(750, 480, 50);

  printf ("===== MyGps.gpsPIDMove: Push allowance triball: push =====\n");
  timerForward(100, 200); 

  printf ("===== MyGps.gpsPIDMove: Position for manual drive =====\n");
  PIDAngleRotateAbs(-145);

  printf ("\n===== auton_near_elim_1_goal_3_over: End: Elased=%.i =====\n", autotimer.getTime());
}
