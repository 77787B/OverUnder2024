#include "autonomous.h"
#include "parameters.h"
#include "my-timer.h"
#include "robot-config.h"
#include "GPS.h"

/**
 * Far 4: AWP: 5 balls
 * 
 * Route:
 * 
*/

void far_4() {
  printf ("\nfar_4:\n");

  MyTimer autotimer;
  autotimer.reset();


  printf ("\n===== far_4: End: Elased=%.i =====\n", autotimer.getTime());
  return;
}