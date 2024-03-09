#include "autonomous.h"
#include "parameters.h"
#include "my-timer.h"
#include "robot-config.h"
#include "GPS.h"

/**
 * Near 3: Elim: rush center, 1 goal, 3 over
 * 1. Get center triball
 * 2. Get corner triball
 * 3. Push triballs over barrier
 * 4. Push alliance triball into goal
*/

void near_3() {
  MyTimer autotimer;
  autotimer.reset();
 
  printf ("\n===== near_3: Start =====\n");

  printf ("\n===== near_3: End: Elased=%.i =====\n", autotimer.getTime());
  
  Brain.Screen.setCursor(11, 1);
  Brain.Screen.print("AutonTimer: %d               ", autotimer.getTime());
}

