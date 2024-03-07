#include "autonomous.h"
#include "parameters.h"
#include "my-timer.h"
#include "robot-config.h"
#include "GPS.h"


void autonInit(void) {
  resetHeading();
  resetForwardPos();
  MyGps.resetForwardPosGps();
}

const int num_of_choices = 8;

static int auton_choose = 6; // Default auton_choose

int getAutonChoose() {
  return auton_choose;
}

void circulateAutonChoose() {
  auton_choose = ((auton_choose + 1) - 1) % num_of_choices + 1;
}

// #ifdef ROBOT1
void runAuton() {
  setAutonMode();
  autonFlipper(true);
  autonInit();

  if (auton_choose == 1) far_1(); 
  else if (auton_choose == 2) near_1();
  else if (auton_choose == 3) far_2();
  else if (auton_choose == 4) near_2();
  else if (auton_choose == 5) far_3(); 
  else if (auton_choose == 6) near_3();
  else if (auton_choose == 7) far_4();
  else if (auton_choose == 8) near_4();
}
// #endif

