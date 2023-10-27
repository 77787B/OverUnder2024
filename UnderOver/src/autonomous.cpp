#include "autonomous.h"
#include "parameters.h"
#include "my-timer.h"
#include "robot-config.h"
#include "GPS.h"






void autonInit(void) {
  setPistonTB(false);
  resetHeading();
  resetForwardPos();
  MyGps.resetForwardPosGps();
}

/**
 * Real one
*/
void auton_far_1() { //AWP SAFETY   Amy
  printf ("\nauton_scenario_1_far_1:\n");

  MyTimer autotimer;
  autotimer.reset();

  setIntakeSpeed(100);
  MyGps.gpsPIDMove(0, -40, -1);
  this_thread::sleep_for(850);  
  setIntakeSpeed(0);

  // push red ball in
  PIDPosCurveAbs(1365, 1850, 50);
  this_thread::sleep_for(200);
  timerForward(100, 450); 
  this_thread::sleep_for(250); 
  timerForward(-150, 135);  

  // push green ball in
  this_thread::sleep_for(300);  
  PIDAngleRotateAbs(100);
  this_thread::sleep_for(200); 
  setIntakeSpeed(-100);
  this_thread::sleep_for(700); 
  setIntakeSpeed(0);
  PIDAngleRotateAbs(105);
  this_thread::sleep_for(200); 
  timerForward(-150, 400);
  this_thread::sleep_for(250); 
  timerForward(175, 135); 
  this_thread::sleep_for(250); 
  // go back to starting position
  MyGps.gpsPIDMove(-350, 650, -1);
  this_thread::sleep_for(250); 
  MyGps.gpsPIDMove(-350, 35, -1);

}

/**
 * Backup
*/
void auton_far_1_backup() { //AWP SAFETY  Amy
  printf ("\nauton_scenario_1_far_1:\n");

  MyTimer autotimer;
  autotimer.reset();

  setIntakeSpeed(100);
  MyGps.gpsPIDMove(0, -40, -1);
  this_thread::sleep_for(850);  
  setIntakeSpeed(0);

  // push red ball in
  PIDPosCurveAbs(1365, 1850, 50);
  this_thread::sleep_for(200);
  timerForward(100, 450); 
  this_thread::sleep_for(250); 
  timerForward(-150, 135);  

  // push green ball in
  this_thread::sleep_for(300);  
  PIDAngleRotateAbs(100);
  this_thread::sleep_for(200); 
  setIntakeSpeed(-100);
  this_thread::sleep_for(700); 
  setIntakeSpeed(0);
  PIDAngleRotateAbs(105);
  this_thread::sleep_for(200); 
  timerForward(-150, 400);
  this_thread::sleep_for(250); 
  timerForward(175, 135); 
  this_thread::sleep_for(250); 
  // go back to starting position
  MyGps.gpsPIDMove(-350, 650, -1);
  this_thread::sleep_for(250); 
  MyGps.gpsPIDMove(-350, 35, -1);
}



/**
 * Real auton near 1   Amy
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
 * auton near 1: attempted approach  Amy
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

  printf ("auton_near_1: elapsed=%d\n", autotimer.getTime());
}

/**
 * NOT USED: intake first  Amy
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

  printf ("auton_near_1: elapsed=%d\n", autotimer.getTime());
}

  void auton_near_1_fz()  {

  setPistonTB(true);
  this_thread::sleep_for(100);
  PIDAngleRotateAbs(-60, 2.5, 0.1, 3);
  setPistonTB(false);
  this_thread::sleep_for(100);
  PIDAngleRotateAbs(-102.5, 1.2, 0.1, 3);

  MyGps.gpsPIDMove(450, -50, -1);
  MyGps.gpsPIDMove(600, -130, -1);


  setIntakeSpeed(-100);
  this_thread::sleep_for(500);
  setIntakeSpeed(0);
  this_thread::sleep_for(100);

  timerForward(-100, 300);
  this_thread::sleep_for(300);
  //PIDPosCurveRel(700, 900);
  MyGps.gpsPIDMove(-330, -300, 1);
  this_thread::sleep_for(100);
  MyGps.gpsPIDMove(-660, -595, 1, 80);
}

// #ifdef ROBOT1
void runAuton(int auton_choose) {
  
  setAutonMode();
  autonFlipper(true);
  autonInit();

  if (auton_choose == 1) auton_far_1(); 
  else if (auton_choose == 2) auton_near_1();
  //else if (auton_choose == 3) auton_far_2();
  //else if (auton_choose == 2) auton_near_2();
  // else if (auton_choose == 5) 
  // else if (auton_choose == 6) 

  
  
}
// #endif

