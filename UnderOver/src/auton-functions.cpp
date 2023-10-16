#include "vex.h"
#include "basic-functions.h"
#include "auton-functions.h"
#include "my-timer.h"
#include "PID.h"
#include "parameters.h"
#include "my-timer.h"
#include "iostream"
using namespace vex;
using namespace std;


void voltageForward(float _power){
  moveLeft(_power);
  moveRight(_power);
  this_thread::sleep_for(5);
}

void timerForward(float _power, int _duration) {
  printf ("timerForward: %.1f, %i, \n", _power, _duration);

  // move forward with _power for _duration msec
  // does not stop base when finishing
  moveForward(_power);
  this_thread::sleep_for(_duration);
  unlockBase();
}


void timerForwardWithHeading(float _power, int _duration, float _targetHeading) {
  auto myTimer = MyTimer();
  while (myTimer.getTime() < _duration) {
    float headingError = _targetHeading - getHeading();
    float powerTurn = headingError * 2.0; // kp = 2.0
    if (fabs(powerTurn) > 20) powerTurn = sign(powerTurn) * 20; // PLimit = 20
    moveLeft(_power + powerTurn);
    moveRight(_power - powerTurn);
  }
  unlockBase();
}

void posForwardRel(float _power, float _target) {
  // move forward with _power for _target displacement
  // does not stop base when finishing
  // use the sign of _power to determine direction
  float startPos = getForwardPos();
  moveForward(_power);
  while (fabs(getForwardPos() - startPos) < fabs(_target)) {}
  unlockBase();
}

void posForwardAbs(float _power, float _target) {
  // move forward with _power to _target position
  // does not stop base when finishing
  // use the sign of (_target - input) to determine direction
  float targetRel = _target - getForwardPos();
  float power = sign(targetRel) * fabs(_power);
  posForwardRel(power, targetRel);
}

void posForwardRelWithHeading(float _power, float _targetPos, float _targetHeading) {
  // move forward with _power for _targetPos displacement while sticking to _targetHeading angle
  // does not stop base when finishing
  // use the sign of _power to determine direction
  float startPos = getForwardPos();
  while (fabs(getForwardPos() - startPos) < fabs(_targetPos)) {
    float headingError = deg2range(_targetHeading - getHeading());
    float powerTurn = headingError * 5.0; // kp = 2.0
    if (fabs(powerTurn) > 20) powerTurn = sign(powerTurn) * 20; // PLimit = 20
    moveLeft(_power + powerTurn);
    moveRight(_power - powerTurn);
    this_thread::sleep_for(5);
  }
  unlockBase();
}

void posForwardAbsWithHeading(float _power, float _targetPos, float _targetHeading) {
  // move forward with _power to _target position while sticking to _targetHeading angle
  // does not stop base when finishing
  // use the sign of (_target - input) to determine direction
  float targetPosRel = _targetPos - getForwardPos();
  float power = sign(targetPosRel) * fabs(_power);
  posForwardRelWithHeading(power, targetPosRel, _targetHeading);
}

void PIDPosForwardAbs(float _target) {
  // move forward to _target position
  // stops base when finishing
  auto pid = PID();
  pid.setCoefficient(0.45, 0.03, 5);
  pid.setTarget(_target);
  pid.setIMax(30);
  pid.setIRange(10);
  pid.setErrorTolerance(5);
  pid.setDTolerance(20);
  pid.setJumpTime(20);
  while (!pid.targetArrived()){ //} && myTimer.getTime() < 1000 + abbs(target * 10)) {
    pid.update(getForwardPos());
    moveForward(pid.getOutput());
    Brain.Screen.setCursor(2, 1);
    Brain.Screen.print("Forward Position: %.1f                           ", getForwardPos());
    this_thread::sleep_for(5);
  }
  unlockBase();
}

void PIDPosForwardRel(float _target) {
  // move forward for _target displacement
  // stops base when finishing
  PIDPosForwardAbs(getForwardPos() + _target);
}

void PIDPosCurveRel(float left_target, float right_target, float tolerance) {
  // move curved to _target position
  // stops base when finishing

  // auto myTimer = MyTimer();
  float _target = (left_target + right_target) / 2;
  float ratio = left_target / right_target;
  auto pid = PID();
  float k = 1;
  pid.setCoefficient(1.05, 0.05, 1.5);
  pid.setTarget(_target);
  pid.setIMax(30);
  pid.setIRange(20);
  pid.setErrorTolerance(tolerance);
  pid.setDTolerance(5);
  pid.setJumpTime(20);
  while (!pid.targetArrived()){ //} && myTimer.getTime() < 1000 + abbs(target * 10)) {
    float leftPos_err = (getForwardPos() / _target) * left_target - getLeftPos();
    float rightPos_err = (getForwardPos() / _target) * right_target - getRightPos();
    pid.update(getForwardPos());
    float PIDoutput = pid.getOutput();
    if (fabs(PIDoutput) > 90) PIDoutput = sign(PIDoutput) * 90;
    if (ratio > 1){
      moveLeft(PIDoutput + k * leftPos_err);
      moveRight(PIDoutput / ratio + k * rightPos_err);
    }
    else{
      moveLeft(pid.getOutput() * ratio + k * leftPos_err);
      moveRight(pid.getOutput() + k * rightPos_err);
    }
    Brain.Screen.setCursor(2, 1);
    Brain.Screen.print("Forward Position: %.1f                           ", getForwardPos());
    this_thread::sleep_for(5);
  }
  resetForwardPos();
  unlockBase();
}

void PIDPosCurveAbs(float left_target, float right_target, float tolerance) {
  PIDPosCurveRel(getLeftPos() + left_target, getRightPos() + right_target, tolerance);
}

void softStartTimerForward(float _powerInit, float _powerFinal, int _duration) {
  // move forward with power gradually increase from _powerInit to _powerFinal within _duration msec
  // does not stop base when finishing
  auto myTimer = MyTimer();
  float step = (_powerFinal - _powerInit) / _duration;
  while (myTimer.getTime() < _duration) {
    moveForward(_powerInit + myTimer.getTime() * step);
    this_thread::sleep_for(5);
  }
  unlockBase();
}

void timerRotate(float _power, int _duration) {  
  // rotate clockwise with _power for _duration msec
  // does not stop base when finishing
  moveClockwise(_power);
  this_thread::sleep_for(_duration);
  resetForwardPos();
  unlockBase();
}

void angleRotateRel(float _power, float _target) {
  // rotate clockwise with _power for _target angle
  // does not stop base when finishing
  float startAngle = getHeading();
  float power = sign(_target) * fabs(_power);
  moveClockwise(power);
  while (fabs(getHeading() - startAngle) < fabs(_target)) {}
  resetForwardPos();
  unlockBase();
}

void angleRotateAbs(float _power, float _target) {
  // rotate clockwise with _power to _target angle
  // does not stop base when finishing
  angleRotateRel(_power, _target - getHeading());
}

void PIDAngleRotateRel(float _target) {
  // rotate clockwise with _power for _target angle
  // stops base when finishing
  PIDAngleRotateAbs(getHeading() + _target);
}

void PIDAngleRotateAbs(float _target, float kp, float ki, float kd, float tolerance) {
  printf ("PIDAngleRotateAbs: target=%.1f, \n", _target);

  // rotate clockwise with _power to _target angle
  // stops base when finishing

  // auto myTimer = MyTimer();
  auto pid = PID();
  // pid.setCoefficient(0.9, 0.1, 3);
  pid.setCoefficient(kp, ki, kd);
  pid.setTarget(_target);
  pid.setIMax(30);
  pid.setIRange(15);
  pid.setErrorTolerance(tolerance);
  //pid.setErrorTolerance(2.5);
  pid.setDTolerance(5);
  pid.setJumpTime(20);
  pid.setType("turn");
  while (!pid.targetArrived()){ // &&  myTimer.getTime() < 1000 + abbs(target * 3)) {
    pid.update(getHeading());
    moveClockwise(pid.getOutput());
    Brain.Screen.setCursor(1, 1);
    Brain.Screen.print("Heading: %.2f            ", getHeading());
    this_thread::sleep_for(5);
  }

  printf ("PIDAngleRotateAbs: end=%.1f, \n", getHeading());

  resetForwardPos();
  unlockBase();
}

void softStartTimerRotate(float _powerInit, float _powerFinal, int _duration) {
  // rotate clockwise with power gradually increase from _powerInit to _powerFinal within _duration msec
  // does not stop base when finishing
  auto myTimer = MyTimer();
  float step = (_powerFinal - _powerInit) / _duration;
  while (myTimer.getTime() < _duration) {
    moveClockwise(_powerInit + myTimer.getTime() * step);
  }
  resetForwardPos();
  unlockBase();
}


void timerWait(float _waittime){
  this_thread::sleep_for(_waittime);
}

static bool autonMode = false;
void clearAutonMode(void) {autonMode = false;}
void setAutonMode(void) {autonMode = true;}
