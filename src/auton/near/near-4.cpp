#include "autonomous.h"
#include "parameters.h"
#include "my-timer.h"
#include "robot-config.h"
#include "GPS.h"

void near_4() {
  MyTimer autotimer;
  autotimer.reset();
  printf ("\n===== near_2: Start =====\n");

  // ## Rush to intake center ball
  setIntakeSpeed(100);
  MyGps.gpsPIDMove(0, 1200, 1, 100);
  this_thread::sleep_for(300);
  setIntakeSpeed(0);

  // ## Drop off center ball
  MyGps.gpsPIDMove(-15, 200, -1, 100);
  PIDAngleRotateAbs(115);
  setIntakeSpeed(-100);
  this_thread::sleep_for(700);
  setIntakeSpeed(0);

  // Get center barrier ball
  MyGps.gpsPIDMove(215, 400, 1, 100);
  // MyGps.gpsPIDMove()
  return;

  // ## Push alliance triball into goal
  setIntakeSpeed(60);
  MyGps.gpsPIDMove(-180, -45, 1, 20);
  this_thread::sleep_for(100);
  setIntakeSpeed(0);
  MyGps.gpsPIDMove(-615, 200, 1, 30);
  MyGps.gpsPIDMove(-650, 305, 1, 20);
  PIDAngleRotateAbs(-17);
  timerForward(10, 80);
  setIntakeSpeed(-100);
  this_thread::sleep_for(3000);

  // ## Get corner triball
  // MyGps.gpsPIDMove(-600, 175, -1);
  MyGps.gpsPIDMove(-625, 140, -1);
  setIntakeSpeed(0);
  PIDAngleRotateAbs(-45);
  setPistonBLW(true);
  this_thread::sleep_for(100);
  MyGps.gpsPIDMove(-245, -125, -1, 80);
  timerForward(80, 150);
  setPistonBLW(false);
  PIDAngleRotateAbs(85);

  // ## Push triballs over alley and touch horizontal bar
  MyGps.gpsPIDMove(-80, -215, 1, 40);
  setPistonFW(true);
  setIntakeSpeed(-100);
  MyGps.gpsPIDMove(715, -50, 1, 80);

  printf ("\n===== near_2: End: Elased=%.i =====\n", autotimer.getTime());
  Brain.Screen.setCursor(11, 1);
  Brain.Screen.print("AutonTimer: %d               ", autotimer.getTime());
}
