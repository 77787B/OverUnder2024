#ifndef AUTONOMOUS_H_
#define AUTONOMOUS_H_

#include "vex.h"
#include "basic-functions.h"
#include "auton-functions.h"

void auton_far_1(void);
void auton_far_2(void);
void auton_far_3(void); 
void auton_far_4balls(void);

void auton_near_awp_only(void);
void auton_near_awp_1_goal(void);
void auton_near_elim_1_goal_3_over(void);
void auton_near_elim_center_1st_1_goal_3_over(void);

void runAuton(int = 0);

#endif
