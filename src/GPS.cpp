#include "vex.h"
#include "basic-functions.h"
#include "auton-functions.h"
#include "my-timer.h"
#include "PID.h"
#include "parameters.h"
#include "my-timer.h"
#include "GPS.h"
using namespace vex;


GPS::GPS(){
}

float GPS::getLeftPosGps() {
  // return the position of left side of base (mm from last reset position) according to encoder value
  return (Motor_BaseLM.position(deg)+Motor_BaseLB.position(deg)) * CHASSIS_GEAR_RATIO * (WHEEL_DIAMETER * 25.4 * 3.1416) / (2.0*360); // return mm
}

float GPS::getRightPosGps() {
  // return the position of right side of base (mm from last reset position) according to encoder value
  return (Motor_BaseRM.position(deg)+Motor_BaseRB.position(deg)) * CHASSIS_GEAR_RATIO * (WHEEL_DIAMETER * 25.4 * 3.1416) / (2.0*360); // return mm
}

float GPS::getForwardPosGps() {
  // return the vertical position of base (mm from last reset position) according to encoder value
  return (getLeftPosGps() + getRightPosGps()) / 2;
}

void GPS::resetLeftPosGps() {
  // reset encoder on the left side of the base
  Motor_BaseLB.resetPosition();
  Motor_BaseLM.resetPosition();
}

void GPS::resetRightPosGps() {
  // reset encoder on the right side of the bases
  Motor_BaseRB.resetPosition();
  Motor_BaseRM.resetPosition();
}

void GPS::resetForwardPosGps() {
  // reset gps coordinate,    skip reseting of motor encoders because 
  // that might modify gpsPosX and gpsPosY indeterministically
  gpsPosX = 0.0;
  gpsPosY = 0.0;
}

void GPS::setForwardPosGps(float _x, float _y) {
  // reset gps coordinate,    skip reseting of motor encoders because 
  // that might modify gpsPosX and gpsPosY indeterministically
  gpsPosX = _x;
  gpsPosY = _y;
}

float GPS::calTheta(float _dx, float _dy, int _direct){
  float theta = rad2deg(atan(_dx/_dy));
  if (_direct * _dy  < 0){
    if (_dy * _dx > 0) theta -= 180;
    else theta += 180;
  }
  return theta;
}

void GPS::updateGpsPos(){
  static float lastForwardPos = getForwardPosGps();
  static float lastHeading = getHeading();
  static float lastPitch = getPitch();
  static float currForwardPos, currHeading;

  static float lastGpsX = gpsPosX;
  static float lastGpsY = gpsPosY;

  currForwardPos = getForwardPosGps();
  currHeading = getHeading();
  lastPitch = getPitch();

  // gpsLock.writeLock();
  float factor = cos(deg2rad(lastPitch));
  gpsPosX += factor*(currForwardPos - lastForwardPos) * sin(deg2rad(0.5 * (currHeading + lastHeading)));
  gpsPosY += factor*(currForwardPos - lastForwardPos) * cos(deg2rad(0.5 * (currHeading + lastHeading)));
  gpsHeading = currHeading;
  // gpsLock.writeLock();

  lastForwardPos = currForwardPos;
  lastHeading = currHeading;
  Brain.Screen.setCursor(9, 1);
  Brain.Screen.print("GPS:  x:  %.1f   y:  %.1f", gpsPosX, gpsPosY);

  if ((lastGpsX - gpsPosX) > 1 || (lastGpsY - gpsPosY) > 1) {
    printf("Last GPS:  x:  %.1f   y:  %.1f\n", lastGpsX, lastGpsY);
    printf("GPS:  x:  %.1f   y:  %.1f\n", gpsPosX, gpsPosY);
    lastGpsX = gpsPosX;
    lastGpsY = gpsPosY;
  }
}

void GPS::gpsPIDCurve(float _xTarget, float _yTarget, float _headingTarget, float _duration){
  auto pid = PID();
  pid.setCoefficient(0.2, 0, 0);
  pid.setTarget(0);
  pid.setIMax(25);
  pid.setIRange(10);
  pid.setErrorTolerance(2);
  pid.setDTolerance(20);
  pid.setJumpTime(50);
  auto myTimer = MyTimer();
  static float maxVel = 0;
  xTarget = _xTarget;
  yTarget = _yTarget;
  headingTarget = _headingTarget;
  
  while (!pid.targetArrived()){
    maxVel = 90 / _duration * myTimer.getTime();
    if (maxVel > 90) maxVel = 90;
    
    pid.update(-dLength * dirSign);
    gpsCurveStep();

    float PIDoutput = pid.getOutput();;
    if (fabs(PIDoutput) > maxVel) {PIDoutput = sign(PIDoutput) * maxVel;}
    float chassisVel[2] = {PIDoutput, PIDoutput / chassisRatio};

    Brain.Screen.setCursor(10, 1);
    Brain.Screen.print("Ratio: %.1f                           ", chassisRatio);

    moveLeftVel(chassisVel[0]);
    moveRightVel(chassisVel[1]);
    this_thread::sleep_for(5);
  }
  unlockBase();
}

void GPS::gpsCurveStep(){
  updateCrtPara();
  static float arcR = 0;
  // float vecTheta = rad2deg(atan((xTarget - gpsPosX) / (yTarget - gpsPosY)));
  // float RTheta = 180 - gpsHeading - vecTheta - dTheta;
  if (scenario == 1) arcR = dLength * cos(deg2rad(theta1)) / sin(deg2rad(dTheta));
  else if (scenario == 2){
    float theta3 = (theta1 + theta2) / 2;
    float dTheta3 = theta1 + theta3;
    float dLength3 = (3 * theta1 + theta2)/(4 * (theta1 + theta2)) * dLength;
    arcR = dLength3 * cos(deg2rad(theta1)) / sin(deg2rad(dTheta3));
  }
  chassisRatio = (arcR + CHASSISRADIUS) / (arcR - CHASSISRADIUS);
}

void GPS::updateCrtPara(){
  xDiff = xTarget - gpsPosX;
  yDiff = yTarget - gpsPosY;
  dLength = sqrt(sqrf(xDiff) + sqrf(yDiff));
  dTheta = abbs(headingTarget - gpsHeading);
  theta1 = rad2deg(acos(xDiff*sin(deg2rad(gpsHeading)) + yDiff*cos(deg2rad(gpsHeading))) / sqrtf(sqrf(xDiff) + sqrf(yDiff)));
  theta2 = rad2deg(acos(xDiff*sin(deg2rad(headingTarget)) + yDiff*cos(deg2rad(headingTarget))) / sqrtf(sqrf(xDiff) + sqrf(yDiff)));
  if ((sin(deg2rad(gpsHeading)) * yDiff - cos(deg2rad(gpsHeading)) * xDiff) * (sin(deg2rad(headingTarget)) * yDiff - cos(deg2rad(headingTarget)) * xDiff)) scenario = 1;
  else scenario = 2;
  if (fabs(theta2) > 90) dirSign = -1;
  else dirSign = 1;
}

void GPS::gpsPIDMove(float _xTarget, float _yTarget, int _direct, int _maxPower, std::string mode) {
  // 1 is forward, -1 is backward
  xTarget = _xTarget;
  yTarget = _yTarget;
  updateCrtPara();
  float _targetHeading = calTheta(xDiff, yDiff, _direct);
  
  if (fabs(gpsHeading - _targetHeading) > 1 || mode != "continue") PIDAngleRotateAbs(_targetHeading, 4, 0.1, 35, 1.5);
  softStartTimerForward(getCrtVel(), _maxPower*_direct, _maxPower);
  // if heading option move straight to target with heading on
  if (mode == "heading") posForwardAbsWithHeading(_maxPower, dLength*_direct, _targetHeading);
  // else we use heading for 75% distance and finish with PID forward
  else {
    posForwardAbsWithHeading(_maxPower, 0.75*dLength*_direct, _targetHeading);
    PIDPosForwardAbs(dLength*_direct);
  }
}



float GPS::getDistance(float _xTarget, float _yTarget){
  // 1 is forward, -1 is backward
  xTarget = _xTarget;
  yTarget = _yTarget;
  updateCrtPara();
  return dLength;
}

float GPS::getAngle(float _xTarget, float _yTarget, int _direct){
  // 1 is forward, -1 is backward
  xTarget = _xTarget;
  yTarget = _yTarget;
  updateCrtPara();
  float _targetHeading = calTheta(xDiff, yDiff, _direct);
  return _targetHeading;
}

void GPS::posForwardRelWithHeadingGPS(float _power, float _targetPos, float _xGoal, float _yGoal) {
  // move forward with _power for _targetPos displacement while sticking to _targetHeading angle
  // does not stop base when finishing
  // use the sign of _power to determine direction
  float startPos = getForwardPos();
  while (fabs(getForwardPos() - startPos) < fabs(_targetPos)) {
    float _targetHeading = calTheta(_xGoal - gpsPosX, _yGoal - gpsPosY);
    float headingError = deg2range(_targetHeading - getHeading());
    float powerTurn = headingError * 2; // kp = 2.0
    if (fabs(powerTurn) > 20) powerTurn = sign(powerTurn) * 20; // PLimit = 20
    moveLeft(_power + powerTurn);
    moveRight(_power - powerTurn);
    this_thread::sleep_for(5);
  }
  unlockBase();
}

void GPS::posForwardAbsWithHeadingGPS(float _power, float _targetPos, float _xGoal, float _yGoal) {
  // move forward with _power to _target position while sticking to _targetHeading angle
  // does not stop base when finishing
  // use the sign of (_target - input) to determine direction
  float targetPosRel = _targetPos - getForwardPos();
  float power = sign(targetPosRel) * fabs(_power);
  float _targetHeading = calTheta(_xGoal - gpsPosX, _yGoal - gpsPosY);
  posForwardRelWithHeading(power, targetPosRel, _targetHeading);
}

void MyGpsPos(){
  // Thread Function, My GPS, use main to call
  while(1){
    MyGps.updateGpsPos();
    this_thread::sleep_for(1);
  }
}
