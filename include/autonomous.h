#ifndef AUTONOMOUS_H_
#define AUTONOMOUS_H_

#include "vex.h"
#include "basic-functions.h"
#include "auton-functions.h"
#include "my-timer.h"

void far_1(void);
void far_2(void);
void far_3(void); 
void far_4(void);

void near_1(void);
void near_2(bool = true);
void near_3(void);
void near_4(void);

void testTurnPid();

int getAutonChoose();
void circulateAutonChoose();
void runAuton();
void printElased(MyTimer autotimer);

#endif
