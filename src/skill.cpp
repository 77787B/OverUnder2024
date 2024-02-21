#include "skill.h"
#include "parameters.h"
#include "my-timer.h"
#include "robot-config.h"
#include "GPS.h"
#include "basic-functions.h"


void skill(){
  MyTimer autotimer;
  autotimer.reset();

  //Note: must use back wings, so change config for front and back to use curve

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
  this_thread::sleep_for(1000);
  setCatapultSpeed(0);
  setPistonBW(false);

  return;
  
  //push middle balls to alley
  MyGps.gpsPIDMove(1100, -600, 1);
  setPistonBW(true);
  MyGps.gpsPIDMove(1000, -2500, -1);
  timerForward(70, 200);
  timerForward(-100, 350);
  timerForward(100, 200);

  //push balls across alley and into goal
  MyGps.gpsPIDMove(0, 0, 1);
  //only set one side true
  setPistonBW(true);
  MyGps.gpsPIDMove(500, 75, -1);
  MyGps.gpsPIDMove(1800, 75, -1);
  MyGPs.gpsPIDMove(2200, 0, -1, 40);
  PIDAngleRotateAbs(135);
  // maybe set other wing true
  // setPistonBW(true);
  MyGPs.gpsPIDMove(2500, -200, -1, 50);
  MyGPs.gpsPIDMove(2600, -600, -1, 50);



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