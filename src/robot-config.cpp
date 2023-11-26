#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);

#ifdef ROBOT1
  motor Motor_BaseLF = motor(PORT18, ratio6_1, true);
  motor Motor_BaseLM = motor(PORT19, ratio6_1, true);
  motor Motor_BaseLB = motor(PORT20, ratio6_1, true);
  motor Motor_BaseRF = motor(PORT11, ratio6_1, false);
  motor Motor_BaseRM = motor(PORT12, ratio6_1, false);
  motor Motor_BaseRB = motor(PORT13, ratio6_1, false);
  motor Motor_Intake1 = motor(PORT17, ratio6_1, false);
  //motor Motor_Intake2 = motor(PORT21, ratio6_1, false);
  motor Motor_Cata1 = motor(PORT10, ratio36_1, true);

  inertial IMU = inertial(PORT9);
  led PistonTB = led(Brain.ThreeWirePort.H); //Triball
  led PistonLH = led(Brain.ThreeWirePort.F); //Low Hang
  limit limit1 = limit(Brain.ThreeWirePort.G);//Cata LIMIT

 
#endif

#ifdef ROBOT2
  motor Motor_BaseLF = motor(PORT15, ratio6_1, true);
  motor Motor_BaseLM = motor(PORT14, ratio6_1, true);
  motor Motor_BaseLB = motor(PORT13, ratio6_1, true);
  motor Motor_BaseRF = motor(PORT18, ratio6_1, false);
  motor Motor_BaseRM = motor(PORT10, ratio6_1, false);
  motor Motor_BaseRB = motor(PORT16, ratio6_1, false);
  motor Motor_Intake1 = motor(PORT1, ratio6_1, false);
  //motor Motor_Intake2 = motor(PORT21, ratio6_1, false);
  motor Motor_Cata1 = motor(PORT12, ratio36_1, true);

  inertial IMU = inertial(PORT7);
  led PistonTB = led(Brain.ThreeWirePort.H); //Triball
  led PistonLH = led(Brain.ThreeWirePort.F); //Low Hang
  limit limit1 = limit(Brain.ThreeWirePort.G);//Cata LIMIT

#endif


// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}
