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

  //Vision Sensor 
  signature Vision18__SIG_1 = signature (1, 6605, 9541, 8073, 775, 1489, 1132, 3, 0);
  signature Vision18__SIG_2 = signature (2, 8191, 10083, 9137, -1527, -507, -1017, 3, 0);
  signature Vision18__SIG_3 = signature (3, 8239, 12205, 10222, -1081, -461, -772, 3, 0);
  signature Vision18__SIG_4 = signature (4, -3257, -2055, -2656, 8633, 11867, 10250, 3, 0);
  vision Vision18 = vision (PORT8, 65, Vision18__SIG_1, Vision18__SIG_2, Vision18__SIG_3);
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
  led PistonE1 = led(Brain.ThreeWirePort.A); //Extension 1
  led PistonE2 = led(Brain.ThreeWirePort.B); //Extension 2
  led PistonA = led(Brain.ThreeWirePort.C); 
  //Vision Sensor 
  signature Vision18__SIG_1 = signature (1, 6605, 9541, 8073, 775, 1489, 1132, 3, 0);
  signature Vision18__SIG_2 = signature (2, 8191, 10083, 9137, -1527, -507, -1017, 3, 0);
  signature Vision18__SIG_3 = signature (3, 8239, 12205, 10222, -1081, -461, -772, 3, 0);
  signature Vision18__SIG_4 = signature (4, -3257, -2055, -2656, 8633, 11867, 10250, 3, 0);
  vision Vision18 = vision (PORT8, 65, Vision18__SIG_1, Vision18__SIG_2, Vision18__SIG_3);
#endif

#ifdef ROBOT3
  motor Motor_BaseLF = motor(PORT17, ratio6_1, true);
  motor Motor_BaseLM = motor(PORT18, ratio6_1, true);
  motor Motor_BaseLB = motor(PORT19, ratio6_1, true);
  motor Motor_BaseRF = motor(PORT14, ratio6_1, false);
  motor Motor_BaseRM = motor(PORT13, ratio6_1, false);
  motor Motor_BaseRB = motor(PORT7, ratio6_1, false);
  motor Motor_Intake1 = motor(PORT9, ratio6_1, false);
  motor Motor_Intake2 = motor(PORT10, ratio6_1, false);
  motor Motor_Flywheel1 = motor(PORT5, ratio6_1, false);
  motor Motor_Flywheel2 = motor(PORT18, ratio6_1, false);
  inertial IMU = inertial(PORT7);
  led PistonE1 = led(Brain.ThreeWirePort.A); //Extension 1
  led PistonE2 = led(Brain.ThreeWirePort.B); //Extension 2
  led PistonA = led(Brain.ThreeWirePort.C); 
  //Vision Sensor 
  signature Vision18__SIG_1 = signature (1, 6605, 9541, 8073, 775, 1489, 1132, 3, 0);
  signature Vision18__SIG_2 = signature (2, 8191, 10083, 9137, -1527, -507, -1017, 3, 0);
  signature Vision18__SIG_3 = signature (3, 8239, 12205, 10222, -1081, -461, -772, 3, 0);
  signature Vision18__SIG_4 = signature (4, -3257, -2055, -2656, 8633, 11867, 10250, 3, 0);
  signature Vision18__SIG_5 = signature (1, -3449, -2575, -3012, 9399, 13493, 11446, 2.5, 0);
  vision Vision18 = vision (PORT18, 65, Vision18__SIG_1, Vision18__SIG_2, Vision18__SIG_3, Vision18__SIG_4, Vision18__SIG_5);

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
