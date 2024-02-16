#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);

#ifdef ROBOT1
  // motor Motor_BaseLF = motor(PORT15, ratio6_1, true);
  // motor Motor_BaseLM = motor(PORT14, ratio6_1, true);
  // motor Motor_BaseLB = motor(PORT13, ratio6_1, true);
  // motor Motor_BaseRF = motor(PORT18, ratio6_1, false);
  // motor Motor_BaseRM = motor(PORT10, ratio6_1, false);
  // motor Motor_BaseRB = motor(PORT16, ratio6_1, false);

  motor Motor_BaseLF = motor(PORT18, ratio6_1, true);
  motor Motor_BaseLM = motor(PORT10, ratio6_1, true);
  motor Motor_BaseLB = motor(PORT16, ratio6_1, true);
  motor Motor_BaseRF = motor(PORT15, ratio6_1, false);
  motor Motor_BaseRM = motor(PORT14, ratio6_1, false);
  motor Motor_BaseRB = motor(PORT13, ratio6_1, false);

  motor Motor_Intake1 = motor(PORT1, ratio6_1, false);
  //motor Motor_Intake2 = motor(PORT21, ratio6_1, false);
  motor Motor_Cata1 = motor(PORT12, ratio36_1, true);

  inertial IMU = inertial(PORT4);
  led PistonHH1 = led(Brain.ThreeWirePort.D); //High Hang
  led PistonHH2 = led(Brain.ThreeWirePort.G); //High Hang
  led PistonTB = led(Brain.ThreeWirePort.E); //Triball
  led PistonLH = led(Brain.ThreeWirePort.F); //Low Hang
  led PistonLW = led(Brain.ThreeWirePort.A); //Left Wing
  led PistonRW = led(Brain.ThreeWirePort.C); //Right Wing

  limit limit1 = limit(Brain.ThreeWirePort.H);//Cata LIMIT good


 
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
