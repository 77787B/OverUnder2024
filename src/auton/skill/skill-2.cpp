#include "skill.h"
#include "parameters.h"
#include "my-timer.h"
#include "robot-config.h"
#include "GPS.h"
#include "basic-functions.h"

void skill_2(){
  MyTimer autotimer;
  autotimer.reset();

  MyGps.gpsPIDMove(0, -400);



  printf ("\n===== skill_2: End: Elased=%.i =====\n", autotimer.getTime());
  Brain.Screen.print("AutonTimer: %d               ", autotimer.getTime());
}
