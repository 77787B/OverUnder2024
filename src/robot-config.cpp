#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);

#ifdef ROBOT1
  motor Motor_BaseLF = motor(PORT15, ratio6_1, true);
  motor Motor_BaseLM = motor(PORT19, ratio6_1, true);
  motor Motor_BaseLB = motor(PORT17, ratio6_1, true);
  motor Motor_BaseRF = motor(PORT13, ratio6_1, false);
  motor Motor_BaseRM = motor(PORT12, ratio6_1, false);
  motor Motor_BaseRB = motor(PORT14, ratio6_1, false);
  motor Motor_Intake1 = motor(PORT20, ratio6_1, false);
  motor Motor_Intake2 = motor(PORT11, ratio6_1, true);
  motor Motor_Cata1 = motor(PORT16, ratio36_1, true);

  inertial IMU = inertial(PORT2);
  led PistonHH = led(Brain.ThreeWirePort.F); //High Hang
  // led PistonFW = led(Brain.ThreeWirePort.H); //Front Wing
  led PistonFLW = led(Brain.ThreeWirePort.H);
  led PistonFRW = led(Brain.ThreeWirePort.D);
  led PistonBLW = led(Brain.ThreeWirePort.G); //Back Left Wing
  led PistonBRW = led(Brain.ThreeWirePort.E); //Back Right Wing

  limit limit1 = limit(Brain.ThreeWirePort.B); //Cata LIMIT 
#endif

#ifdef ROBOT2
  motor Motor_BaseLF = motor(PORT1, ratio6_1, true);
  motor Motor_BaseLM = motor(PORT2, ratio6_1, true);
  motor Motor_BaseLB = motor(PORT3, ratio6_1, true);
  motor Motor_BaseRF = motor(PORT6, ratio6_1, false);
  motor Motor_BaseRM = motor(PORT8, ratio6_1, false);
  motor Motor_BaseRB = motor(PORT7, ratio6_1, false);
  motor Motor_Intake1 = motor(PORT11, ratio6_1, false);
  //motor Motor_Intake2 = motor(PORT21, ratio6_1, false);
  motor Motor_Cata1 = motor(PORT16, ratio36_1, true);



  inertial IMU = inertial(PORT5);
  led PistonHH1 = led(Brain.ThreeWirePort.D); //Triball
  led PistonHH2 = led(Brain.ThreeWirePort.G); //Low Hang
  led PistonTB = led(Brain.ThreeWirePort.F); //Triball
  led PistonLH = led(Brain.ThreeWirePort.E); //Low Hang
  limit limit1 = limit(Brain.ThreeWirePort.H);//Cata LIMIT

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
