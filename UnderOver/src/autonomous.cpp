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


void auton_far_1() { //AWP SAFETY


  MyTimer autotimer;
  autotimer.reset();

  MyGps.gpsPIDMove(0, 650, 1);
  this_thread::sleep_for(100); 
  timerForward(60, 400);
  

  MyGps.gpsPIDMove(0, 0, -1);
  this_thread::sleep_for(500); 


  PIDAngleRotateAbs(60);
  this_thread::sleep_for(100); 
  timerForward(-70, 375);
}

void auton_far_2(){
  MyTimer autotimer;
  autotimer.reset();

  
  Brain.Screen.setCursor(11, 1);
  Brain.Screen.print("AutonTimer: %d                            ", autotimer.getTime());
}


void auton_far_3() {
  MyTimer autotimer;
  autotimer.reset();


  Brain.Screen.setCursor(8, 1);
  Brain.Screen.print("Auton Time: %.1f                 ", autotimer.getTime());
}

void auton_far_4(){ //

}



void auton_near_1() { //AWP SAFETY

  MyTimer autotimer;
  autotimer.reset();
  setIntakeSpeed(100);
  setCataStatus(5);
  softStartTimerForward(0, 80, 200);
  posForwardAbsWithHeading(80, 1000, 0);
  PIDPosForwardAbs(1180);
  PIDPosForwardAbs(670);
  PIDAngleRotateAbs(-135, 2.5, 0.03, 5, 1.5);
  // this_thread::sleep_for(50);
  setCataStatus(2);
  this_thread::sleep_for(300);

  setIntakeSpeed(0);
  PIDAngleRotateAbs(-150);
  setCataStatus(5);
  PIDPosForwardAbs(830);
  // setPistonHook(1);
  voltageForward(15);
  this_thread::sleep_for(400);

  resetForwardPos();
  PIDPosForwardAbs(-500);
  this_thread::sleep_for(100);
  resetForwardPos();
  PIDPosCurveAbs(1, 800);
  // setPistonHook(0);
  setIntakeSpeed(-100);
  PIDPosForwardAbs(800);
  setIntakeSpeed(0);

  Brain.Screen.setCursor(8, 1);
  Brain.Screen.print("Auton Time: %.1f                 ", autotimer.getTime());
}


void auton_near_2() {
  MyTimer autotimer;
  autotimer.reset();

  Brain.Screen.setCursor(11, 1);
  Brain.Screen.print("AutonTimer: %d                            ", autotimer.getTime());
}

void auton_near_3() {
  MyTimer autotimer;
  autotimer.reset();

  
  Brain.Screen.setCursor(11, 1);
  Brain.Screen.print("AutonTimer: %d                            ", autotimer.getTime());
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


// score means socring triballs into goal


  if (auton_choose == 1) auton_far_1(); //saftey Score
  else if (auton_choose == 2) auton_near_1(); //saftey
  else if (auton_choose == 3) auton_far_2(); //AWP score
  else if (auton_choose == 4) auton_near_2(); //AWP
  else if (auton_choose == 5) auton_far_3(); //elim score
  else if (auton_choose == 6) auton_near_3(); //elim
  
  
}
// #endif

