#include "skill.h"
#include "parameters.h"
#include "my-timer.h"
#include "robot-config.h"
#include "GPS.h"
#include "basic-functions.h"



void skillInit() {

  MyGps.resetForwardPosGps();
}


void skill(){
  MyTimer autotimer;
  autotimer.reset();

//inital catapult fire
  MyGps.gpsPIDMove(0, -500);
  PIDAngleRotateAbs(55);
  setPistonBW(true);
  setCatapultSpeed(70);
  this_thread::sleep_for(5);  //35000
  setCatapultSpeed(0);
  setPistonBW(false);
  
  //PIDAngleRotateAbs(-45);
  timerForward(-70, 500);
  PIDPosForwardRel(100);
  //PIDAngleRotateAbs(-35);
  posForwardAbsWithHeading(80, 400, 0);
  setPistonFW(true);
  

  //gps reset????



  Brain.Screen.setCursor(11, 1);
  Brain.Screen.print("AutonTimer: %d               ", autotimer.getTime());
}
void runSkill(){
    skillInit();
    skill();
}