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


void auton_left_1() { //AWP SAFETY
  MyTimer autotimer;
  autotimer.reset();
 
 

  
  PIDAngleRotateAbs(90);


  
  //Intake
  //Grab triball in matchload
  //TOUCH POLE

  


  Brain.Screen.setCursor(11, 1);
  Brain.Screen.print("AutonTimer: %d                            ", autotimer.getTime());
}


void auton_left_2() {

}

void auton_left_3()  { 

}

void auton_right_1() { //AWP SAFETY

  MyTimer autotimer;
  autotimer.reset();

  
   
  MyGps.gpsPIDMove(0, 1000);
  PIDAngleRotateAbs(-90);

  
  setIntakeSpeed(100);
  this_thread::sleep_for(600);
  setIntakeSpeed(0);
  
  PIDPosForwardAbs(100);
  PIDAngleRotateAbs(180);

  MyGps.gpsPIDMove(150, 1000);
/*
  MyGps.gpsPIDMove(-500, 800, -1);
  setIntakeSpeed(-100);
  this_thread::sleep_for(100);
  setIntakeSpeed(0);

  MyGps.gpsPIDMove(0, 1000, -1);
*/
  

  //MyGps.gpsPIDMove(-100, 1000, -1);
  /*
  setIntakeSpeed(-100);
  this_thread::sleep_for(500);
*/
  /*
  setIntakeSpeed(0);
  */
  
  
  //pushing triball
  
  /*
  setIntakeSpeed(0);

  MyGps.gpsPIDMove(0, 1000, -1);
  PIDAngleRotateAbs(90);
  //tune
  setIntakeSpeed(-100);
  this_thread::sleep_for(500);
  setIntakeSpeed(0);

  MyGps.gpsPIDMove(300, 1000, -1);
  setIntakeSpeed(100);
  this_thread::sleep_for(500);
  setIntakeSpeed(0);

//third triball
  MyGps.gpsPIDMove(-500, 700, -1);
  setIntakeSpeed(-100);
  this_thread::sleep_for(500);
  setIntakeSpeed(0);
  MyGps.gpsPIDMove(0, 1000, -1);

  setIntakeSpeed(100);
  this_thread::sleep_for(500);


  */
  //PIDAngleRotateAbs(45);


  
  //Intake
  //Grab triball in matchload
  //TOUCH POLE

  


  Brain.Screen.setCursor(11, 1);
  Brain.Screen.print("AutonTimer: %d                            ", autotimer.getTime());
  //PRELOAD

  //SIDE TRIBALL

  //MORE LATER
}

void auton_right_2() {
  
}

void auton_right_3() {

}




  

// #ifdef ROBOT1
void runAuton(int auton_choose) {
  
  setAutonMode();
  autonFlipper(true);
  autonInit();

 


  if (auton_choose == 1) auton_left_1(); 
 // else if (auton_choose == 2) auton_left_2();  
 // else if (auton_choose == 3) auton_left_3(); 
  else if (auton_choose == 2) auton_right_1(); 
 // else if (auton_choose == 5) auton_right_2(); 
 // else if (auton_choose == 6) auton_right_3();  

  
  
}
// #endif

