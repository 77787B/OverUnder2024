#include "autonomous.h"
#include "parameters.h"
#include "my-timer.h"
#include "robot-config.h"
#include "GPS.h"


void autonInit(void) {
  setPistonTB(false);
  resetHeading();
  resetForwardPos();
  MyGps.resetForwardPosGps();
}


// #ifdef ROBOT1
void runAuton(int auton_choose) {
  
  setAutonMode();
  autonFlipper(true);
  autonInit();

  if (auton_choose == 1) auton_far_1(); 
  else if (auton_choose == 2) auton_near_2_awp_1_ball();
  else if (auton_choose == 3) auton_far_2();
  else if (auton_choose == 4) auton_near_2();
  else if (auton_choose == 5) auton_far_4balls(); 
  // else if (auton_choose == 5) 
  // else if (auton_choose == 6) 
}
// #endif

