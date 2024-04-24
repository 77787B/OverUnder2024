#include "autonomous.h"
#include "parameters.h"
#include "my-timer.h"
#include "robot-config.h"
#include "GPS.h"

/**
 * Far 2: 6 goal
*/
void far_2() {
  MyTimer autotimer;
  autotimer.reset();
  printf ("\nfar_1:\n");

  // # Get alley triball
  setIntakeSpeed(80);
  PIDPosForwardAbs(80);
  this_thread::sleep_for(50);
  setIntakeSpeed(0);

  // # Get corner triball
  PIDAngleRotateAbs(-8);
  PIDPosForwardAbs(-1050);
  setPistonBW(true);
  PIDAngleRotateAbs(-37);
  PIDPosForwardAbs(-150);
  PIDAngleRotateAbs(-80);
  setPistonBLW(false);

  // # Push alliance and corner triballs into goal
  PIDAngleRotateAbs(-42);
  PIDPosForwardAbs(-260, 150);
  PIDAngleRotateAbs(-75);
  PIDPosForwardAbs(-200, 50, 100);
  PIDAngleRotateAbs(-87);
  timerForward(-100, 300);
  setPistonBRW(false);
  this_thread::sleep_for(100);
  PIDPosForwardAbs(30);
  PIDAngleRotateAbs(90);
  setIntakeSpeed(-80);
  this_thread::sleep_for(300);
  PIDAngleRotateAbs(-87);
  timerForward(-100, 300);
  printf ("\n===== far_1: Before move=%.i =====\n", autotimer.getTime());

  // // # Drop off alley triball
  // PIDAngleRotateAbs(-15);
  // PIDPosForwardAbs(450);
  // PIDAngleRotateAbs(50);
  // PIDPosForwardAbs(650, 350);
  // PIDAngleRotateAbs(152);
  // setIntakeSpeed(-100);
  // this_thread::sleep_for(300);
  // setIntakeSpeed(0);

  // # Get barrier left triball
  PIDPosForwardAbs(75);
  PIDAngleRotateAbs(19);
  setIntakeSpeed(100);
  printf ("\n===== far_1: Before move=%.i =====\n", autotimer.getTime());
  PIDPosForwardAbs(1200, 1000);
  printf ("\n===== far_1: After move=%.i =====\n", autotimer.getTime());
  this_thread::sleep_for(50);
  setIntakeSpeed(0);

  // # Drop barrier left triball
  PIDAngleRotateAbs(155);
  PIDPosForwardAbs(100);
  setIntakeSpeed(-100);
  this_thread::sleep_for(300);
  setIntakeSpeed(0);

  // Get barrier middle triball
  PIDAngleRotateAbs(60);
  setIntakeSpeed(100);

  printf ("\n===== far_1: barrier middle triball Before move=%.i =====\n", autotimer.getTime());
  PIDPosForwardAbs(425);
  printf ("\n===== far_1: barrier middle triball After move=%.i =====\n", autotimer.getTime());

  // Push last three triballs into goal
  PIDAngleRotateAbs(175);
  setPistonFW(true);
  setIntakeSpeed(-70); 
  // this_thread::sleep_for(75);
  printf ("\n===== far_1: Before Push=%.i =====\n", autotimer.getTime());
  timerForward(100, 600);

  printf ("\n===== far_1: End: Elased=%.i =====\n", autotimer.getTime());
  Brain.Screen.setCursor(11, 1);
  Brain.Screen.print("AutonTimer: %d               ", autotimer.getTime());
}
