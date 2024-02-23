#include "skill.h"
#include "parameters.h"
#include "my-timer.h"
#include "robot-config.h"
#include "GPS.h"
#include "basic-functions.h"

void skill_2(){
  MyTimer autotimer;
  autotimer.reset();

  // MyGps.gpsPIDMove(0, -300, -1, 50);
  // MyGps.gpsPIDMove(400, -500, -1, 50);
  MyGps.gpsPIDMove(300, -300, -1, 20);
  PIDAngleRotateAbs(-90);
  timerForward(-100, 400);

  // MyGps.gpsPIDMove(600, -300, -1, 50);


  printf ("\n===== skill_2: End: Elased=%.i =====\n", autotimer.getTime());
  Brain.Screen.print("AutonTimer: %d               ", autotimer.getTime());
}
