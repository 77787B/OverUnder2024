#include "autonomous.h"
#include "parameters.h"
#include "my-timer.h"
#include "robot-config.h"
#include "GPS.h"

/**
 * For testing code
*/
void auton_near_1_test() {
  // PIDPosCurveAbs(1200, 700, 50);
  // timerForward(80, 350); 
  // timerForward(20, 400); 
  setPistonA(true);

  // PIDPosForwardAbs(150);
  // setPistonA(true);
  // this_thread::sleep_for(1000); 

  // PIDAngleRotateAbs(-90, 0.9, 0.1, 3, 2.5);
  // setPistonA(false);
}

/**
 * Real auton near 1
*/
void auton_near_1() {
  PIDPosCurveAbs(1200, 700, 50);
  timerForward(80, 350); 

  // PIDAngleRotateAbs(45, 0.9, 0.1, 3, 2.5);
  PIDAngleRotateAbs(45);
  MyGps.gpsPIDMove(250, 350, -1);

  PIDAngleRotateAbs(-45);
  timerForward(20, 450); 
  
  setPistonA(true);
  this_thread::sleep_for(500);
  PIDAngleRotateAbs(-135);
  setPistonA(false);

  this_thread::sleep_for(500); 
  PIDAngleRotateAbs(-180);
  timerForward(20, 300); 
  MyGps.gpsPIDMove(100, -290, -1);
}

/**
 * auton near 1: attempted approach
*/
void auton_near_1_intake_front() {
  printf ("auton_near_1:\n");

  MyTimer autotimer;
  autotimer.reset();

  MyGps.gpsPIDMove(550, -600, -1);
  PIDAngleRotateAbs(-10, 0.9, 0.1, 3, 2.5);
  // this_thread::sleep_for(2000); 
  setIntakeSpeed(-100);
  this_thread::sleep_for(500);  
  setIntakeSpeed(0);

  timerForward(50, 150);
  this_thread::sleep_for(500); 
  PIDAngleRotateAbs(-170, 0.9, 0.1, 3, 2.5);
  timerForward(100, 100); 
  // timerForward(-100, 500); 

  // MyGps.gpsPIDMove(150, -150, 1);
  // printf ("auton_near_1: before rotate\n");
  // PIDAngleRotateA2s(45, 0.9, 0.1, 3, 2.5);
  // printf ("auton_near_1: after rotate\n");

  // // posForwardAbs(10, 10);
  // PIDPosForwardAbs(150);
  // setPistonA(true);
  // this_thread::sleep_for(1000); 

  // PIDAngleRotateAbs(-80, 0.9, 0.1, 3, 2.5);
  // setPistonA(false);

  // PIDAngleRotateAbs(90, 0.9, 0.1, 3, 2.5);
  // MyGps.gpsPIDMove(-700, 0, -1);

  printf ("auton_near_1: elapsed=%d\n", autotimer.getTime());
}

/**
 * NOT USED: intake first
*/
void auton_near_1_intake_first() {
  printf ("auton_near_1:\n");

  MyTimer autotimer;
  autotimer.reset();

  MyGps.gpsPIDMove(550, -600, -1);
  PIDAngleRotateAbs(-10, 0.9, 0.1, 3, 2.5);
  // this_thread::sleep_for(2000); 
  setIntakeSpeed(-100);
  this_thread::sleep_for(500);  
  setIntakeSpeed(0);

  timerForward(50, 150);
  this_thread::sleep_for(500); 
  PIDAngleRotateAbs(-170, 0.9, 0.1, 3, 2.5);
  timerForward(100, 100); 
  // timerForward(-100, 500); 

  // MyGps.gpsPIDMove(150, -150, 1);
  // printf ("auton_near_1: before rotate\n");
  // PIDAngleRotateA2s(45, 0.9, 0.1, 3, 2.5);
  // printf ("auton_near_1: after rotate\n");

  // // posForwardAbs(10, 10);
  // PIDPosForwardAbs(150);
  // setPistonA(true);
  // this_thread::sleep_for(1000); 

  // PIDAngleRotateAbs(-80, 0.9, 0.1, 3, 2.5);
  // setPistonA(false);

  // PIDAngleRotateAbs(90, 0.9, 0.1, 3, 2.5);
  // MyGps.gpsPIDMove(-700, 0, -1);

  printf ("auton_near_1: elapsed=%d\n", autotimer.getTime());
}
