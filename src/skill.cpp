#include "skill.h"
#include "parameters.h"
#include "my-timer.h"
#include "robot-config.h"
#include "GPS.h"
#include "basic-functions.h"


void skill(){
  MyTimer autotimer;
  autotimer.reset();

  //push in alliance triballs
  MyGps.gpsPIDMove(-315, -400, -1, 50);
  PIDAngleRotateAbs(0);
  timerForward(-100, 300);

  //catapult balls to other side
  MyGps.gpsPIDMove(-280, -530, 1, 40);
  PIDAngleRotateAbs(120);
  //timerForward(-30, 250);
  setPistonBW(true);
  setCatapultSpeed(70);
  //this_thread::sleep_for(21000);
  this_thread::sleep_for(1000);2
  setCatapultSpeed(0);
  setPistonBW(false);
  

  return;
  
  MyGps.gpsPIDMove(1100, -600, 1);
  PIDAngleRotateAbs


  Brain.Screen.setCursor(11, 1);
  Brain.Screen.print("AutonTimer: %d               ", autotimer.getTime());
}


void runSkill(){
    skill();
}




void scrappedSkills(){
    //push in alliance triballs
  MyGps.gpsPIDMove(275, 325, 1, 100);
  MyGps.gpsPIDMove(275, 375, 1, 100);
  timerForward(80, 275);
  MyGps.gpsPIDMove(275, 430, -1, 100);
  setIntakeSpeed(-100);
  this_thread::sleep_for(400);
  setIntakeSpeed(0);

  //catapult balls to other side
  MyGps.gpsPIDMove(275, 325, -1, 100);
  PIDAngleRotateAbs(-55);
  setPistonBW(true);
  setCatapultSpeed(70);
  // this_thread::sleep_for(28000);
  this_thread::sleep_for(1000);
  setCatapultSpeed(0);
  setPistonBW(false);

}