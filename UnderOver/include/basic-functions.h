#ifndef BASIC_FUNCTIONS_H_
#define BASIC_FUNCTIONS_H_

#include "robot-config.h"
#include "parameters.h"
#include "vex.h"

// using namespace vex;
//autonchecker
void autonFlipper(bool);
// Calculation
float abbs(float);
float deg2rad(float);
float rad2deg(float);
float sqrf(float);
int sign(float);
float deg2range(float);

// Output functions
void moveLeft(float);
void moveLeftVel(float);
void lockLeft(void);
void unlockLeft(void);
void moveRight(float);
void moveRightVel(float);
void lockRight(void);
void unlockRight(void);
void moveForward(float);
void moveForwardVel(float);
void moveClockwise(float);
void lockBase(void);
void unlockBase(void);
float getCrtVel();

// Input functions

float getLeftPos();
float getRightPos();
float getForwardPos();
void resetLeftPos();
void resetRightPos();
void resetForwardPos();

float getHeading();
void resetHeading();
void resetHeading(float);
float getPitch();

//OverUnder

//Intake
void setIntakeSpeed(float);
void intake();

//Cata
void setCatapultStatus(int);
void catapult();

/*
void catapultStatus(bool);
void catapult();
void catapultShoot();
void catapultHold();
void cata_matchload(bool);
*/

void catapult();


//Piston
void setPistonA(bool);
void setPistonE(bool);
void setPistonW(bool);


void speed_volt(float, int);

#endif