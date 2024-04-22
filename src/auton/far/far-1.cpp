#include "autonomous.h"
#include "parameters.h"
#include "my-timer.h"
#include "robot-config.h"
#include "GPS.h"

/**
 * Far 1: AWP: 6 balls
 * 
 * Route:
 * 1. Get triball-under-bar
 * 1.1. Drive slowly to corner triball so our alliance ball follows a stable path
 * 2. Get corner triball
 * 3. Push in alliance triball and corner triball
 * 3.1. Rotate and push in triball-under-bar
 * 4. Get barrier-triball-on-right 
 * 4.1. Outtake it toward goal
 * 5. Get middle-barrier-triball
 * 6. Push all 3 triballs into goal
*/

void far_1() {

  MyTimer autotimer;
  autotimer.reset();
  printf ("\nfar_1:\n");

  // # Get alley triball
  setIntakeSpeed(80);
  PIDPosForwardAbs(80);
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
  PIDPosForwardAbs(-260);
  PIDAngleRotateAbs(-87);
  timerForward(-100, 350);
  setPistonBRW(false);

  //drop off alley triball
  // this_thread::sleep_for(100);
  PIDAngleRotateAbs(-15);
  PIDPosForwardAbs(450);
  PIDAngleRotateAbs(50);
  PIDPosForwardAbs(650, 350);
  PIDAngleRotateAbs(152);
  setIntakeSpeed(-100);
  this_thread::sleep_for(325);
  setIntakeSpeed(0);

  // # Get barrier left triball
  PIDAngleRotateAbs(-19);
  setIntakeSpeed(100);
  printf ("\n===== far_1: Before move=%.i =====\n", autotimer.getTime());
  PIDPosForwardAbs(375);
  printf ("\n===== far_1: After move=%.i =====\n", autotimer.getTime());
  this_thread::sleep_for(100);
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
  PIDPosForwardAbs(350);

  // push last three balls in
  PIDAngleRotateAbs(175);
  setPistonFW(true);
  setIntakeSpeed(-70); 
  this_thread::sleep_for(75);
  printf ("\n===== far_1: Before Push=%.i =====\n", autotimer.getTime());
  timerForward(100, 600);

  printf ("\n===== far_1: End: Elased=%.i =====\n", autotimer.getTime());
  Brain.Screen.setCursor(11, 1);
  Brain.Screen.print("AutonTimer: %d               ", autotimer.getTime());
}



void far_1_gps() {

  MyTimer autotimer;
  autotimer.reset();
  printf ("\nfar_1:\n");

  // # Get alley triball
  setIntakeSpeed(100);
  MyGps.gpsPIDMove(0, 60, 1, 50);
  this_thread::sleep_for(300);  
  setIntakeSpeed(0);

  // # Get corner triball
  MyGps.gpsPIDMove(105, -880, -1, 95); 
  setPistonBW(true);
  MyGps.gpsPIDMove(250, -1125, -1, 55);
  PIDAngleRotateAbs(-70);
  setPistonBLW(false);

  // # Push alliance and corner triballs into goal
  MyGps.gpsPIDMove(455, -1375, -1, 40);
  PIDAngleRotateAbs(-80);
  timerForward(-100, 350);
  setPistonBRW(false);

  //drop off alley triball
  MyGps.gpsPIDMove(500, -1250, 1, 80);
  MyGps.gpsPIDMove(975, -600, 1, 100);
  PIDAngleRotateAbs(151);
  setIntakeSpeed(-100);
  this_thread::sleep_for(400);
  setIntakeSpeed(0);

  // # Get barrier left triball
  setIntakeSpeed(90);
  MyGps.gpsPIDMove(975, -270, 1, 55);
  this_thread::sleep_for(150);
  setIntakeSpeed(0);

  // # Drop barrier left triball
  PIDAngleRotateAbs(155);
  setIntakeSpeed(-100);
  this_thread::sleep_for(400); //used to be 300, change back if going to move forward before outtaking
  setIntakeSpeed(0);

  // Get barrier middle triball
  setIntakeSpeed(100);
  MyGps.gpsPIDMove(1330, -175, 1, 100);
  this_thread::sleep_for(200);

  // push last three balls in
  setPistonFW(true);
  PIDAngleRotateAbs(177);
  setIntakeSpeed(-100); 
  this_thread::sleep_for(75);
  timerForward(100, 600);

  printf ("\n===== far_1: End: Elased=%.i =====\n", autotimer.getTime());
  Brain.Screen.setCursor(11, 1);
  Brain.Screen.print("AutonTimer: %d               ", autotimer.getTime());
}




// P.S try PIDPosCurveAbs(5, 400, 100); lol