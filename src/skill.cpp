#include "skill.h"
#include "parameters.h"
#include "my-timer.h"
#include "robot-config.h"
#include "GPS.h"
#include "basic-functions.h"

void skillInit() {
  MyGps.resetForwardPosGps();
}

void runSkill(){
    skillInit();
    skill_1();
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