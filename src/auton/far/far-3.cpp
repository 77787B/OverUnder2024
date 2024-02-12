#include "autonomous.h"
#include "parameters.h"
#include "my-timer.h"
#include "robot-config.h"
#include "GPS.h"

/**
 * Far 3: ? goal
*/
void far_3() {

//Center Rush
//Andrew ur gonna do this right?


  MyTimer autotimer;
  autotimer.reset();

  Brain.Screen.setCursor(11, 1);
  Brain.Screen.print("AutonTimer: %d               ", autotimer.getTime());
}