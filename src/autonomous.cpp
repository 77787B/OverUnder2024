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
  if (auton_choose == 0) {
    // change auton value here instead since we often have to change which auton function to run anyways
    auton_choose = 6;
  }
  
  setAutonMode();
  autonFlipper(true);
  autonInit();

  if (auton_choose == 1) auton_far_1(); 
  else if (auton_choose == 2) auton_near_awp_1_goal();
  else if (auton_choose == 3) auton_far_2();
  else if (auton_choose == 4) auton_near_elim_1_goal_3_over();
  else if (auton_choose == 5) auton_far_4balls(); 
  else if (auton_choose == 6) auton_near_elim_center_1st_1_goal_3_over();
}
// #endif

