#ifndef AUTONOMOUS_H_
#define AUTONOMOUS_H_

#include "vex.h"
#include "basic-functions.h"
#include "auton-functions.h"

void far_1(void);
void far_2(void);
void far_3(void); 
void far_4(void);

void near_1(void);
void near_2(void);
void near_3(void);
void near_4(void);

int getAutonChoose();
void circulateAutonChoose();
void runAuton();

#endif