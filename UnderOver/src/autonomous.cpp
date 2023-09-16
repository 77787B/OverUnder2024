#include "autonomous.h"
#include "parameters.h"
#include "my-timer.h"
#include "robot-config.h"
#include "GPS.h"





void autonInit(void) {
  setPistonE(false);
  resetHeading();
  resetForwardPos();
  MyGps.resetForwardPosGps();
}


void auton_far_1() { //AWP SAFETY
  MyTimer autotimer;
  autotimer.reset();
 
  
  //pos forward
  MyGps.gpsPIDMove(0, -1100, -1);
  PIDAngleRotateAbs(90);

  setIntakeSpeed(-100);
  this_thread::sleep_for(500);

  setIntakeSpeed(0);

  posForwardAbsWithHeading(90, -200, 90);


  MyGps.gpsPIDMove(0, -1100);
  PIDAngleRotateAbs(0);

  MyGps.gpsPIDMove(0, 200, 1);
  PIDAngleRotateAbs(90);

  MyGps.gpsPIDMove(600, 200, 1);
  setCataStatus(5);

  





  Brain.Screen.setCursor(11, 1);
  Brain.Screen.print("AutonTimer: %d                            ", autotimer.getTime());
}

void auton_far_2(){
  MyTimer autotimer;
  autotimer.reset();


 
//first ball
  MyGps.gpsPIDMove(0, -1100, -1);
  PIDAngleRotateAbs(90);

  setIntakeSpeed(-100);
  this_thread::sleep_for(600);
  setIntakeSpeed(0);

  posForwardAbsWithHeading(90, -200, 90);


  MyGps.gpsPIDMove(0, -1100);
  PIDAngleRotateAbs(0);



  // setIntakeSpeed(100);
  // MyGps.gpsPIDMove(0, -1400);
  // this_thread::sleep_for(300);
  // setIntakeSpeed(0);

  // MyGps.gpsPIDMove(0, -1000);
  // PIDAngleRotateAbs(90);

  






  Brain.Screen.setCursor(11, 1);
  Brain.Screen.print("AutonTimer: %d                            ", autotimer.getTime());


}


void auton_far_3() {

 
}



void auton_near_1() { //AWP SAFETY

  MyTimer autotimer;
  autotimer.reset();

  

  Brain.Screen.setCursor(11, 1);
  Brain.Screen.print("AutonTimer: %d                            ", autotimer.getTime());
}

void auton_near_2() {
  MyTimer autotimer;
  autotimer.reset();

  

  Brain.Screen.setCursor(11, 1);
  Brain.Screen.print("AutonTimer: %d                            ", autotimer.getTime());
}

void auton_near_3() {

}




  

// #ifdef ROBOT1
void runAuton(int auton_choose) {
  
  setAutonMode();
  autonFlipper(true);
  autonInit();





  if (auton_choose == 1) auton_far_1(); 
  else if (auton_choose == 2) auton_near_1();
  else if (auton_choose == 3) auton_far_2();
  else if (auton_choose == 2) auton_near_2();
  // else if (auton_choose == 5) 
  // else if (auton_choose == 6) 

  
  
}
// #endif

