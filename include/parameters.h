#ifndef PARAMETERS_H_
#define PARAMETERS_H_

#include "vex.h"

static int CRTCOLOR = 1; // 1 is red, 0 is blue

const float Movement_LowerLimit = 5;
const float Joystick_LowerDeadzone = 5;
volatile static float gpsPosX, gpsPosY, gpsHeading;

static const float PI = 3.1416;


#ifdef ROBOT1
  static const float WHEEL_DIAMETER = 4.0;
  static const float CHASSIS_GEAR_RATIO = 0.5;
  static const float CHASSISRADIUS = 205; //mm
  static const float kGyro = 1800.0 / 1800.0;
  static const float CATAPULT_SPEED = 60;
  static const float CATAPULT_RATIO = 3;
  static const float INTAKEMIDPOS = 50.0;
  
#endif

#ifdef ROBOT2
  static const float WHEEL_DIAMETER = 4.0;
  static const float CHASSIS_GEAR_RATIO = 0.5;
  static const float CHASSISRADIUS = 205; //mm
  static const float kGyro = 1800.0 / 1800.0;
  static const float CATAPULT_SPEED = 60;
  static const float CATAPULT_RATIO = 3;
  static const float INTAKEMIDPOS = 50.0;

#endif 

#endif


