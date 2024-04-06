#include "autonomous.h"
#include "parameters.h"
#include "my-timer.h"
#include "robot-config.h"
#include "GPS.h"

void near_4() {

  MyTimer autotimer;
  autotimer.reset();

  printf ("\n===== near_4: Start =====\n");

  

  printf ("\n===== near_4: End: Elased=%.i =====\n", autotimer.getTime());

  Brain.Screen.setCursor(11, 1);
  Brain.Screen.print("AutonTimer: %d               ", autotimer.getTime());
}
