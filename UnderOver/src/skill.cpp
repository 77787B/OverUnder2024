#include "skill.h"
#include "parameters.h"
#include "my-timer.h"
#include "robot-config.h"
#include "GPS.h"

const int pistonInterval = 400;

void skillInit() {

  MyGps.resetForwardPosGps();
}


void runSkill(){
    skillInit();
    skill();
}
