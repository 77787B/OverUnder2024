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

}
void runSkill(){
    skillInit();
    skill();
}