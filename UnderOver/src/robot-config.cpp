#include "vex.h"
#include "robot-config.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);

#ifdef ROBOT1
  motor Motor_BaseLF = motor(PORT20, ratio6_1, true);
  motor Motor_BaseLM = motor(PORT19, ratio6_1, true);
  motor Motor_BaseLB = motor(PORT18, ratio6_1, true);
  motor Motor_BaseRF = motor(PORT13, ratio6_1, true);
  motor Motor_BaseRM = motor(PORT12, ratio6_1, true);
  motor Motor_BaseRB = motor(PORT11, ratio6_1, true);
  motor Motor_Intake1 = motor(PORT17, ratio6_1, true);
  motor Motor_Cata1 = motor(PORT10, ratio36_1, true);

  inertial IMU = inertial(PORT5);
  led PistonE = led(Brain.ThreeWirePort.B); //Extension 1
  led PistonA = led(Brain.ThreeWirePort.G); //Extension 2
  limit limit1 = limit(Brain.ThreeWirePort.F);//Cata LIMIT

  

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
