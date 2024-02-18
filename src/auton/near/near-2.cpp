#include "autonomous.h"
#include "parameters.h"
#include "my-timer.h"
#include "robot-config.h"
#include "GPS.h"

/**
 * Near 2: Elim: 1 goal, 3 over (2-3 seconds before going to center)
 * 1. Get corner triball
 * 2. Get center triball
 * 3. Push triballs over barrier
 * 4. Push allowance triball into goal
*/

/**
 * Same starting position as AWP (more likely for corner tribail to go across)
*/

void near_2() {

  MyTimer autotimer;
  autotimer.reset();
  printf ("\n===== near_2: Start =====\n");

  //rush to intake center ball
  setIntakeSpeed(100);
  MyGps.gpsPIDMove(300, 1175, 1);
  //can make all the intakes 300 with new robot
  this_thread::sleep_for(600);
  setIntakeSpeed(0);
  MyGps.gpsPIDMove(275, 1050, -1);

  //drop off middle ball
  MyGps.gpsPIDMove(25, 295, 1);
  PIDAngleRotateAbs(-218);
  setIntakeSpeed(-80);
  this_thread::sleep_for(400);
  setIntakeSpeed(0);

  // Push alliance triball into goal
  //note: gps is very off on old robot, fix next few lines
  setIntakeSpeed(100);
  // PIDAngleRotateAbs(-145);
  MyGps.gpsPIDMove(-75, 165, 1);
  this_thread::sleep_for(600);
  setIntakeSpeed(0);
  MyGps.gpsPIDMove(-500, 450, 1, 50);
  MyGps.gpsPIDMove(-500, 565, 1, 25);
  setIntakeSpeed(-100);
  this_thread::sleep_for(400);
  setIntakeSpeed(0);

  //get corner triball
  MyGps.gpsPIDMove(-515, 480, -1, 100);
  PIDAngleRotateAbs(180);
  PIDPosCurveAbs(200, 480, 50);
  //setPistonFW(true);
  this_thread::sleep_for(400);
  PIDPosCurveAbs(275, 515, 50);
  this_thread::sleep_for(500);
  //setPistonFW(false);

  // Push triballs over alley and touch horizontal bar
  setIntakeSpeed(-100);
  MyGps.gpsPIDMove(690, -65, 1);
  this_thread::sleep_for(500);

  printf ("\n===== near_1: End: Elased=%.i =====\n", autotimer.getTime());
  Brain.Screen.setCursor(11, 1);
  Brain.Screen.print("AutonTimer: %d               ", autotimer.getTime());
}


void near_2_og() {
  MyTimer autotimer;
  autotimer.reset();
 
  printf ("\n===== near_2: Start =====\n");

  //rush to intake center ball
  setIntakeSpeed(100);
  MyGps.gpsPIDMove(0, 1200, 1);
  this_thread::sleep_for(600);
  setIntakeSpeed(0);

  printf ("===== MyGps.gpsPIDMove: Move to near starting position =====\n");
  MyGps.gpsPIDMove(-275, 275, -1);
  MyGps.gpsPIDMove(-600, 300, -1);
  PIDAngleRotateAbs(170);
  printf ("===== MyGps.gpsPIDMove: Get corner tribal =====\n");
  PIDPosCurveAbs(230, 500, 20);
  // setPistonFW(true);
  this_thread::sleep_for(400);
  PIDPosCurveAbs(300, 525, 30);
  // setPistonFW(false);
  printf ("===== MyGps.gpsPIDMove: Push balls across alley=====\n");
  timerForward(100, 275);
  setIntakeSpeed(-100);
  this_thread::sleep_for(800); 
  setIntakeSpeed(0);
  //go to triangle
  MyGps.gpsPIDMove(-330, -30, -1);
  PIDAngleRotateAbs(110);
  timerForward(-65, 125);
  // setPistonBW(true);

  printf ("\n===== near_2: End: Elased=%.i =====\n", autotimer.getTime());
  
  Brain.Screen.setCursor(11, 1);
  Brain.Screen.print("AutonTimer: %d               ", autotimer.getTime());
}


void near_2_() {
  MyTimer autotimer;
  autotimer.reset();

  printf ("\n===== near_2: Start =====\n");

  setPistonRW(true);
  setPistonTB(true);
  this_thread::sleep_for(500);
  PIDAngleRotateAbs(-125);
  setPistonTB(false);
  setPistonRW(false);

  // printf ("===== MyGps.gpsPIDMove: Rotate to align to alliance triball =====\n");
  // PIDAngleRotateAbs(-38);

  printf ("===== MyGps.gpsPIDMove: Move to center ball =====\n");
  setIntakeSpeed(100);
  MyGps.gpsPIDMove(500, -1150, -1);
  this_thread::sleep_for(400);
  setIntakeSpeed(0);

  printf ("===== MyGps.gpsPIDMove: Back to corner =====\n");
  MyGps.gpsPIDMove(-125, 50, 1);

  printf ("===== PIDAngleRotateAbs: Rotate to face back to hang bar =====\n");
  PIDAngleRotateAbs(45);

  printf ("===== MyGps.gpsPIDMove: Push balls across alley =====\n");
  setIntakeSpeed(-100);
  MyGps.gpsPIDMove(-695, -575, -1);
  this_thread::sleep_for(500);
  setIntakeSpeed(0);

  printf ("===== MyGps.gpsPIDMove: Push alliance triball: back to near starting position =====\n");
  MyGps.gpsPIDMove(50, 50, 1);
  PIDAngleRotateAbs(90);
  
  printf ("===== MyGps.gpsPIDMove: Push alliance triball: curve =====\n");
  PIDPosCurveAbs(760, 520, 50);

  printf ("===== MyGps.gpsPIDMove: Push alliance triball: push =====\n");
  timerForward(100, 300); 

  printf ("===== MyGps.gpsPIDMove: Position for manual drive =====\n");
  PIDAngleRotateAbs(-145);

  printf ("\n===== near_2: End: Elased=%.i =====\n", autotimer.getTime());
}

/**
 * Initial setup position differnt from AWP
*/
void near_2_different_from_AWP() {
  MyTimer autotimer;
  autotimer.reset();

  printf ("\n===== near_2: Start =====\n");

  setPistonRW(true);
  // this_thread::sleep_for(500);
  setPistonTB(true);
  this_thread::sleep_for(500);
  PIDAngleRotateAbs(-125);
  // this_thread::sleep_for(200);
  setPistonTB(false);
  setPistonRW(false);
  // this_thread::sleep_for(100);

  printf ("===== MyGps.gpsPIDMove: Rotate to align to alliance triball =====\n");
  // PIDAngleRotateAbs(-38);

  printf ("===== MyGps.gpsPIDMove: Move to center ball =====\n");
  setIntakeSpeed(100);
  // MyGps.gpsPIDMove(550, -1165, -1); // crossed a line a bit
  MyGps.gpsPIDMove(550, -1100, -1);
  this_thread::sleep_for(400);
  setIntakeSpeed(0);

  printf ("===== MyGps.gpsPIDMove: Back to corner =====\n");
  MyGps.gpsPIDMove(-75, 50, 1);

  printf ("===== PIDAngleRotateAbs: Rotate to face hang bar backware =====\n");
  PIDAngleRotateAbs(45);

  printf ("===== MyGps.gpsPIDMove: Push balls across alley =====\n");
  setIntakeSpeed(-100);
  MyGps.gpsPIDMove(-645, -610, -1);
  this_thread::sleep_for(500);
  setIntakeSpeed(0);

  printf ("===== MyGps.gpsPIDMove: Push alliance triball =====\n");
  MyGps.gpsPIDMove(0, 0, 1);
  PIDAngleRotateAbs(90);
  
  printf ("===== MyGps.gpsPIDMove: Push alliance triball: curve =====\n");
  PIDPosCurveAbs(760, 520, 50);

  printf ("===== MyGps.gpsPIDMove: Push alliance triball: push =====\n");
  timerForward(100, 300); 

  printf ("===== MyGps.gpsPIDMove: Position for manual drive =====\n");
  PIDAngleRotateAbs(-145);

  printf ("\n===== near_2: End: Elased=%.i =====\n", autotimer.getTime());
}

void near_2_previous() {
  MyTimer autotimer;
  autotimer.reset();

  printf ("\n===== near_2: Start =====\n");

  setPistonRW(true);
  setPistonTB(true);
  this_thread::sleep_for(500);
  PIDAngleRotateAbs(-125);
  setPistonTB(false);
  setPistonRW(false);

  printf ("===== MyGps.gpsPIDMove: Rotate to align to alliance triball =====\n");
  PIDAngleRotateAbs(-38);

  printf ("===== MyGps.gpsPIDMove: Move to center ball =====\n");
  MyGps.gpsPIDMove(425, -1150, -1);
  printf ("===== PIDAngleRotateAbs: Rotate to line up horizontally to the ball =====\n");
  PIDAngleRotateAbs(-45);

  setIntakeSpeed(100);
  printf ("===== MyGps.gpsPIDMove: Intake =====\n");
  MyGps.gpsPIDMove(480, -1245, -1, 50);
  this_thread::sleep_for(500);  
  setIntakeSpeed(0);

  printf ("===== MyGps.gpsPIDMove: Back to corner =====\n");
  MyGps.gpsPIDMove(0, 0, 1);

  printf ("===== PIDAngleRotateAbs: Rotate to face hang bar backware =====\n");
  PIDAngleRotateAbs(45);

  printf ("===== MyGps.gpsPIDMove: Back to corner =====\n");
  setIntakeSpeed(-100);
  MyGps.gpsPIDMove(-700, -600, -1);
  setIntakeSpeed(0);

  printf ("===== MyGps.gpsPIDMove: Push alliance triball =====\n");
  MyGps.gpsPIDMove(0, 100, 1);
  PIDAngleRotateAbs(90);
  
  printf ("===== MyGps.gpsPIDMove: Push alliance triball: curve =====\n");
  PIDPosCurveAbs(750, 530, 50);

  printf ("===== MyGps.gpsPIDMove: Push alliance triball: push =====\n");
  timerForward(100, 200); 

  printf ("===== MyGps.gpsPIDMove: Position for manual drive =====\n");
  PIDAngleRotateAbs(-145);

  printf ("\n===== near_2: End: Elased=%.i =====\n", autotimer.getTime());
}
