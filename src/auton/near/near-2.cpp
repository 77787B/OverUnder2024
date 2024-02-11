#include "autonomous.h"
#include "parameters.h"
#include "my-timer.h"
#include "robot-config.h"
#include "GPS.h"

/**
 * Near 2: Elim: 1 goal, 3 over (2-3 seconds before going to center)
 * 1. Get corner triball
 * 2. Get center triball
 * 3. Push triballs over barrier
 * 4. Push allowance triball into goal
*/

/**
 * Same starting position as AWP (more likely for corner tribail to go across)
*/
void near_2() {
  
  MyTimer autotimer;
  autotimer.reset();

  Brain.Screen.setCursor(11, 1);
  Brain.Screen.print("AutonTimer: %d               ", autotimer.getTime());
}
