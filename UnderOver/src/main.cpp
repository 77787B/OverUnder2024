/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Motor18              motor         18              
// ---- END VEXCODE CONFIGURED DEVICES ----
#include "ezize.h"
#include "basic-functions.h"
#include "parameters.h"
#include "autonomous.h"
#include "my-timer.h"
#include "iostream"
#include "GPS.h"
#include "skill.h"


using namespace std;
using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

int auton_choose = 1;

void autonomous(void) {
  runAuton(auton_choose);
  // runSkill();
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/


void usercontrol(void) {

  int print_i = 0;
  int autocollide = 0;
  bool RightPressed = 0;
  bool UpPressed = 0;
  bool BxPressed = 0;
  bool R2Pressed = 0;
  bool BAPressed = 0;
  bool rotateStatus = 0;
  bool extensionStatus = 0;
  bool lowhangStatus = 0;
  float m_degree= Motor_Cata1.position(deg);
  // initCata();
  while(true) {

    int Ch1 = abbs(C1) < Joystick_LowerDeadzone ? 0 : C1;
    int Ch2 = abbs(C2) < Joystick_LowerDeadzone ? 0 : C2;
    int Ch3 = abbs(C3) < Joystick_LowerDeadzone ? 0 : C3;
    // int Ch4 = abbs(C4) < Joystick_LowerDeadzone ? 0 : C4;
    if ((abbs(Ch3) < 30 || sign(Ch3) == sign(Ch2)) && abbs(Ch2) > 80 && abbs(Ch2) > abbs(Ch1) + 40) autocollide = sign(Ch2);
    else if ((abbs(Ch3) >= 50 && !(Ch3 > 0 && autocollide == 1)) || (abbs(Ch2) < abbs(Ch1) && abbs(Ch1) > 40)) autocollide = 0;
    
    if (autocollide == 0) {
      moveLeft(Ch3 + 1 * Ch1);
      moveRight(Ch3 - 1 * Ch1);
    } 
    else {
      moveLeft(autocollide * 15);
      moveRight(autocollide * 15);
    }
        
    if (L1) setIntakeSpeed(100);
    else if (L2) setIntakeSpeed(-100);
    else setIntakeSpeed(0);

    if (BA && !BAPressed) {
      rotateStatus = !rotateStatus;
      setCataRotateStatus(rotateStatus);
      if(rotateStatus ==0) setCataStatus(4);
    }
    BAPressed = BA;

    if (BY) setCataStatus(4);
    if (BB) setCataStatus(3);
    if (R1) setCataStatus(2);
    if (R2) setCataStatus(5);
    // if (R2 && !R2Pressed) changeCataMode();
    // R2Pressed = R2;

    if (UP && !UpPressed){
      extensionStatus = !extensionStatus;
      setPistonE(extensionStatus);
    }
    UpPressed = UP;

    if (LEFT) setPistonE(false);



    if(DOWN) runAuton(auton_choose);
    if(RIGHT && !RightPressed) auton_choose = 3;
    RightPressed = RIGHT;

    // if(DOWN && R2) runSkill();

    if (BX && !BxPressed){
      lowhangStatus = !lowhangStatus;
      setPistonA(lowhangStatus);
    }
    BxPressed = BX;

    // if (RIGHT) setPistonA(false);

    //only when down and R2 are both pressed we run auton
    // if (DOWN && R2) {
    //   runAuton(auton_choose);
    //   //runSkill();
    // }

    // if (RIGHT && !RightPressed) auton_choose = ((auton_choose + 1) - 1) % 3 + 1;
    // RightPressed = RIGHT;

    m_degree = Motor_Cata1.position(deg)/3;
    Brain.Screen.setCursor(8, 1);
    Brain.Screen.print(m_degree);

    if (print_i == 0){
      // Brain.Screen.clearScreen();
      Brain.Screen.setCursor(1, 1);
      Brain.Screen.print("Heading: %.1f                             ", getHeading());
    
      Brain.Screen.setCursor(2, 1);
      Brain.Screen.print("ForwardPosition: %.1f                     ", getForwardPos());

      Brain.Screen.setCursor(7, 1);
      Brain.Screen.print("Auton choose: %d                          ", auton_choose);
    }
    print_i += 1;
    print_i %= 100;

    this_thread::sleep_for(5);
    
  }
}



//
// Main will set up the competition functions and callbacks.
//
int main() {
  wait(1000, msec);
  setPistonE(false);
  IMU.startCalibration();
  while (IMU.isCalibrating()) {
  }
  wait(1000, msec);

  thread Intake(intake);
  thread Catapult(catapult);
  thread GPSPosition(MyGpsPos);
  
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) wait(5, msec);
}
