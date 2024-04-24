#include "autonomous.h"
#include "parameters.h"
#include "my-timer.h"
#include "robot-config.h"
#include "GPS.h"

void testTurnPid() {
  MyTimer autotimer;

  float degree = 180;

  autotimer.reset();
  PIDAngleRotateRel(degree, 100, 5, 0.1, 35, 1.5);
  printf ("\n===== turn: degree=%.f, PID=(5, 0.1, 35, 1.5): Elased=%.i =====\n", degree, autotimer.getTime());
  this_thread::sleep_for(1000);

  autotimer.reset();
  PIDAngleRotateRel(degree, 100, 4, 0.1, 35, 1.5);
  printf ("\n===== turn: degree=%.f, PID=(4, 0.1, 35, 1.5): Elased=%.i =====\n", degree, autotimer.getTime());
  this_thread::sleep_for(1000);

  autotimer.reset();
  PIDAngleRotateRel(degree, 100, 3, 0.1, 35, 1.5);
  printf ("\n===== turn: degree=%.f, PID=(3, 0.1, 35, 1.5): Elased=%.i =====\n", degree, autotimer.getTime());
  this_thread::sleep_for(1000);

  autotimer.reset();
  PIDAngleRotateRel(degree, 100, 2, 0.1, 35, 1.5);
  printf ("\n===== turn: degree=%.f, PID=(2, 0.1, 35, 1.5): Elased=%.i =====\n", degree, autotimer.getTime());
  this_thread::sleep_for(1000);
}
