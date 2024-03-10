#include "skill.h"
#include "parameters.h"
#include "my-timer.h"
#include "robot-config.h"
#include "GPS.h"
#include "basic-functions.h"

void skill_1_test_barrier_push_with_front() {
  // setPistonFW(true);

  timerForward(100, 300);
  timerForward(-100, 200);
  timerForward(100, 300);
}

void skill_1_test_barrier_push_with_back() {
  // setPistonFW(true);

  timerForward(-100, 300);
  timerForward(100, 200);
  timerForward(-100, 300);
}

void skill_1_() {
  // PIDAngleRotateAbs(90);
  MyGps.gpsPIDMove(-315, -350, -1, 50);


  return;
  setPistonFLW(true);
  this_thread::sleep_for(2000);
  setPistonFLW(false);
  this_thread::sleep_for(2000);

  setPistonFRW(true);
  this_thread::sleep_for(2000);
  setPistonFRW(false);
}

void skill_1() {
  MyTimer autotimer;
  autotimer.reset();

  MyGps.gpsPIDMove(-315, -310, -1, 50);
  PIDAngleRotateAbs(116);
  setPistonBW(true);
  setIntakeSpeed(-100);
  this_thread::sleep_for(100);
  setCatapultSpeed(75);
  this_thread::sleep_for(25000); // TODO: use this for real run
  // this_thread::sleep_for(2000);
  setCatapultSpeed(0);
  setPistonBW(false);
  this_thread::sleep_for(100);
  setIntakeSpeed(0);

  // // # push alliance triballs into goal
  PIDAngleRotateAbs(0);
  timerForward(-100, 300);

  // # drive thru alley
  MyGps.gpsPIDMove(200, 50, 1);
  MyGps.gpsPIDMove(1500, 50, 1);
  this_thread::sleep_for(100); // Drive long distance slides. Pause in middle to prevent sliding.
  MyGps.gpsPIDMove(2350, 50, 1);

  // # 1st push: on left side of goal
  setPistonFRW(true);
  PIDPosCurveAbs(1000, 500, 50);
  setIntakeSpeed(-100);
  timerForward(100, 300);
  this_thread::sleep_for(100);
  timerForward(-50, 200);
  this_thread::sleep_for(100);
  // PIDAngleRotateAbs(-15);
  // timerForward(-100, 300);
  timerForward(100, 300);
  setIntakeSpeed(0);
  // timerForward(50, 200);
  timerForward(-50, 200);
  setPistonFRW(false);
  printf ("\n===== 1st push: on left side of goal: Elased=%.i =====\n", autotimer.getTime());

  // # 2nd push: on left of front of goal
  MyGps.gpsPIDMove(2866, -400, -1, 50);
  MyGps.gpsPIDMove(2300, -500, 1, 50);
  // setPistonFW(true);
  setPistonFW(true);
  PIDPosCurveAbs(500, 1000, 50);
  PIDAngleRotateAbs(115);
  // setPistonFW(true);
  this_thread::sleep_for(100);
  setIntakeSpeed(-100);
  timerForward(100, 700);
  // setPistonFW(false);
  setPistonFW(false);
  this_thread::sleep_for(50);
  timerForward(-100, 100);
  setIntakeSpeed(0);
  printf ("\n===== 2nd push: on left of front of goal: Elased=%.i =====\n", autotimer.getTime());

  // # 3rd push: on middle of front of goal
  MyGps.gpsPIDMove(2360, -1230, -1, 50);
  PIDAngleRotateAbs(-90);
  setPistonFW(true);
  this_thread::sleep_for(100);
  PIDPosCurveAbs(550, 1250, 50);
  // PIDPosCurveAbs(600, 1500, 50);
  PIDAngleRotateAbs(90);
  setIntakeSpeed(-100);
  this_thread::sleep_for(50);
  timerForward(100, 600);
  setPistonFW(false);
  this_thread::sleep_for(50);
  timerForward(-100, 100);
  setIntakeSpeed(0);
  printf ("\n=====  3rd push: on middle of front of goal: Elased=%.i =====\n", autotimer.getTime());

  // # 4th push: on right of front of goal
  timerForward(-100, 400);
  PIDAngleRotateAbs(180);
  setPistonFW(true);
  MyGps.gpsPIDMove(1800, -2500, 1, 50);
  PIDAngleRotateAbs(70);
  setIntakeSpeed(-100);
  timerForward(100, 700);
  setPistonFW(false);
  this_thread::sleep_for(50);
  timerForward(-100, 100);
  setIntakeSpeed(0);
  // setPistonFLW(false);

  // MyGps.gpsPIDMove(2360, -2000, -1, 50);
  // PIDAngleRotateAbs(-90);
  // setPistonFLW(true);
  // this_thread::sleep_for(100);
  // PIDPosCurveAbs(600, 1250, 50);
  // PIDAngleRotateAbs(80);
  // setIntakeSpeed(-100);
  // timerForward(100, 700);
  // setIntakeSpeed(0);
  // // setPistonFW(false);
  // setPistonFLW(false);
  // timerForward(-100, 100);
  printf ("\n=====  4th push: on right of front of goal: Elased=%.i =====\n", autotimer.getTime());

  // # 5th push: on right side of goal
  MyGps.gpsPIDMove(2360, -2250, -1, 50);
  MyGps.gpsPIDMove(2400, -3000, 1, 50);
  // MyGps.gpsPIDMove(2600, -2500, -1, 50);
  // MyGps.gpsPIDMove(2600, -3220, 1, 50);
  // PIDAngleRotateAbs(145);
  // setPistonFW(true);
  setPistonFLW(true);
  this_thread::sleep_for(50);
  // PIDPosCurveAbs(550, 1250, 50);
  PIDPosCurveAbs(500, 1000, 50);
  // PIDPosCurveAbs(450, 900, 50);
  PIDAngleRotateAbs(10);
  setIntakeSpeed(-100);
  timerForward(100, 300);
  this_thread::sleep_for(100);
  timerForward(-50, 200);
  this_thread::sleep_for(100);
  timerForward(100, 300);
  setPistonFLW(false);
  setIntakeSpeed(0);

  printf ("\n===== skill_1: End: Elased=%.i =====\n", autotimer.getTime());
  Brain.Screen.setCursor(11, 1);
  Brain.Screen.print("AutonTimer: %d               ", autotimer.getTime());
}
