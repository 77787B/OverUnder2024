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
  //Push two balls into goal, rotate and ready for catapult
  PIDPosCurveAbs(605, 1024, 80);
  moveLeft(-65);
  this_thread::sleep_for(500);
  PIDAngleRotateAbs(-115);

  //Begin firing catapult
  setCataRotateStatus(1);
  this_thread::sleep_for(25000); //30000
  setCataRotateStatus(0);

//Drives away to push balls in
  angleRotateAbs(50, -145);
  PIDPosCurveAbs(1300, 1175, 60);
  PIDPosForwardAbs(850);
  PIDPosCurveAbs(1730, 1239, 60);
  timerForward(100, 500);
  PIDAngleRotateAbs(220);
  setIntakeSpeed(160);

  //Zigzag pattern - Intake triballs and push into goal
  PIDPosForwardAbs(70);
}
void runSkill(){
    skillInit();
    skill();
}