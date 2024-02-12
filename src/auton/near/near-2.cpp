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

printf ("\n===== near_2: Start =====\n");

  setPistonFW(true);
  // setPistonTB(true);
  this_thread::sleep_for(500);
  PIDAngleRotateAbs(-125);
  // setPistonTB(false);
  setPistonFW(false);

  // printf ("===== MyGps.gpsPIDMove: Rotate to align to alliance triball =====\n");
  // PIDAngleRotateAbs(-38);

  printf ("===== MyGps.gpsPIDMove: Move to center ball =====\n");
  setIntakeSpeed(100);
  MyGps.gpsPIDMove(500, -1150, -1);
  this_thread::sleep_for(400);
  setIntakeSpeed(0);

  printf ("===== MyGps.gpsPIDMove: Back to corner =====\n");
  MyGps.gpsPIDMove(-125, 50, 1);

  printf ("===== PIDAngleRotateAbs: Rotate to face back to hang bar =====\n");
  PIDAngleRotateAbs(45);

  printf ("===== MyGps.gpsPIDMove: Push balls across alley =====\n");
  setIntakeSpeed(-100);
  MyGps.gpsPIDMove(-695, -575, -1);
  this_thread::sleep_for(500);
  setIntakeSpeed(0);

  printf ("===== MyGps.gpsPIDMove: Push alliance triball: back to near starting position =====\n");
  MyGps.gpsPIDMove(50, 50, 1);
  PIDAngleRotateAbs(90);
  
  printf ("===== MyGps.gpsPIDMove: Push alliance triball: curve =====\n");
  PIDPosCurveAbs(760, 520, 50);

  printf ("===== MyGps.gpsPIDMove: Push alliance triball: push =====\n");
  timerForward(100, 300); 

  printf ("===== MyGps.gpsPIDMove: Position for manual drive =====\n");
  PIDAngleRotateAbs(-145);

  printf ("\n===== near_2: End: Elased=%.i =====\n", autotimer.getTime());

  Brain.Screen.setCursor(11, 1);
  Brain.Screen.print("AutonTimer: %d               ", autotimer.getTime());
}
