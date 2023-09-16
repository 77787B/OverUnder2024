#include "vex.h"
#include "robot-config.h"
#include "basic-functions.h"
#include "parameters.h"
#include "PID.h"
#include "my-timer.h"
#include "ezize.h"
#include "iostream"
#include "roundRobinQueue.h"
using namespace std;

bool autonChecker = false;

void autonFlipper(bool _checker) { autonChecker = _checker; }

float abbs(float x) { return x >= 0 ? x : -x; }

float deg2rad(float deg) { return deg / 180.0 * PI; }

float rad2deg(float rad) { return rad / PI * 180.0; }

float sqrf(float x) { return x * x; }

int sign(float _input) {
  if (_input > 0) return 1;
  else if (_input < 0) return -1;
  else return 0;
}

float deg2range(float _degree){
  int _cir = int(_degree / 360);
  _degree -= _cir * 360;
  if (_degree > 180.0) _degree -= 360;
  if (_degree < -180.0) _degree += 360;
  return _degree;
}

void moveLeft(float _input) {
  // _input ranges from -100 : 100
  // powers all motors on left side of base with duty cycle _input%
  if (fabs(_input) > 100) _input = sign(_input) * 100;
  Motor_BaseLF.spin(directionType::fwd, (int)130 * _input, voltageUnits::mV);
  Motor_BaseLM.spin(directionType::fwd, (int)130 * _input, voltageUnits::mV);
  Motor_BaseLB.spin(directionType::fwd, (int)130 * _input, voltageUnits::mV);
}

void moveLeftVel(float _input) {
  // _input ranges from -100 : 100
  // powers all motors on left side of base with duty cycle _input%
  if (fabs(_input) > 100) _input = sign(_input) * 100;
  Motor_BaseLF.spin(directionType::fwd, (int)_input, velocityUnits::pct);
  Motor_BaseLM.spin(directionType::fwd, (int)_input, velocityUnits::pct);
  Motor_BaseLB.spin(directionType::fwd, (int) _input, velocityUnits::pct);
}

void lockLeft(void) {
  // locks all motors on left side of base
  Motor_BaseLF.stop(vex::brakeType::hold);
  Motor_BaseLM.stop(vex::brakeType::hold);
  Motor_BaseLB.stop(vex::brakeType::hold);
}

void unlockLeft(void) {
  // unlocks all motors on left side of base
  Motor_BaseLF.stop(vex::brakeType::coast);
  Motor_BaseLM.stop(vex::brakeType::coast);
  Motor_BaseLB.stop(vex::brakeType::coast);
}

void moveRight(float _input) {
  // _input ranges from -100 : 100
  // powers all motors on right side of base with duty cycle _input%
  if (fabs(_input) > 100) _input = sign(_input) * 100;
  Motor_BaseRF.spin(directionType::fwd, (int)130 * _input, voltageUnits::mV);
  Motor_BaseRM.spin(directionType::fwd, (int)130 * _input, voltageUnits::mV);
  Motor_BaseRB.spin(directionType::fwd, (int)130 * _input, voltageUnits::mV);
}

void moveRightVel(float _input) {
  // _input ranges from -100 : 100
  // powers all motors on right side of base with duty cycle _input%
  if (fabs(_input) > 100) _input = sign(_input) * 100;
  Motor_BaseRF.spin(directionType::fwd, (int) _input, velocityUnits::pct);
  Motor_BaseRM.spin(directionType::fwd, (int) _input, velocityUnits::pct);
  Motor_BaseRB.spin(directionType::fwd, (int) _input, velocityUnits::pct);
}

void lockRight(void) {
  // locks all motors on right side of base
  Motor_BaseRF.stop(vex::brakeType::hold);
  Motor_BaseRM.stop(vex::brakeType::hold);
  Motor_BaseRB.stop(vex::brakeType::hold);
}

void unlockRight(void) {
  // unlocks all motors on right side of base
  Motor_BaseRF.stop(vex::brakeType::coast);
  Motor_BaseRM.stop(vex::brakeType::coast);
  Motor_BaseRB.stop(vex::brakeType::coast);
}

void moveForward(float _input) {
  // move forward with _input% power
  moveLeft(_input);
  moveRight(_input);
}

void moveForwardVel(float _input) {
  // move forward with _input% speed
  moveLeftVel(_input);
  moveRightVel(_input);
}

void moveClockwise(float _input) {
  // rotate clockwise with _input% power
  moveLeft(_input);
  moveRight(-_input);
}
void lockBase(void) {
  // lock the base
  lockLeft();
  lockRight();
}

void unlockBase(void) {
  // unlock the base
  unlockLeft();
  unlockRight();
}

float getCrtVel(){
  return (Motor_BaseLM.velocity(pct) + Motor_BaseRM.velocity(pct)) / 2;
}

static volatile float _leftPosLast = 0, _rightPosLast = 0;

float getLeftPos() {
  // return the position of left side of base (mm from last reset position) according to encoder value
  return (Motor_BaseLF.position(deg)+Motor_BaseLM.position(deg)) * CHASSIS_GEAR_RATIO * (WHEEL_DIAMETER * 25.4 * 3.1416) / (2.0*360) - _leftPosLast; // return mm
}

float getRightPos() {
  // return the position of right side of base (mm from last reset position) according to encoder value
  return (Motor_BaseRF.position(deg)+Motor_BaseRM.position(deg)) * CHASSIS_GEAR_RATIO * (WHEEL_DIAMETER * 25.4 * 3.1416) / (2.0*360) - _rightPosLast; // return mm
  //return 0;
}

float getForwardPos() {
  // return the vertical position of base (mm from last reset position) according to encoder value
  return (getLeftPos() + getRightPos()) / 2;
}

void resetLeftPos() {
  // reset encoder on the left side of the base
  _leftPosLast = (Motor_BaseLF.position(deg)+Motor_BaseLM.position(deg)) * CHASSIS_GEAR_RATIO * (WHEEL_DIAMETER * 25.4 * 3.1416) / (2.0*360);
}

void resetRightPos() {
  // reset encoder on the right side of the base
  _rightPosLast = (Motor_BaseRF.position(deg)+Motor_BaseRM.position(deg)) * CHASSIS_GEAR_RATIO * (WHEEL_DIAMETER * 25.4 * 3.1416) / (2.0*360);
}

void resetForwardPos() {
  // reset encoders on both side of the base
  resetLeftPos();
  resetRightPos();
}

static float headingOffset = 0;

float getHeading() {
  // return the heading angle of robot in deg (+360 after a full clockwise turn, -360 after a counter-clockwise turn) 
  return IMU.rotation() + headingOffset;
}

void resetHeading() {
  IMU.resetRotation();
  headingOffset = 0;
}

void resetHeading(float _offset) {
  // reset current heading angle of robot 
  IMU.resetRotation();
  headingOffset = _offset;
}

float getPitch() {
  // return the pitch angle of robot in deg
  return IMU.pitch();
}

float intake_speed = 0;

void setIntakeSpeed(float _input){
  intake_speed = _input;
}

void intake() {

  while(true){
    if (fabs(intake_speed) > 100) intake_speed = sign(intake_speed) * 100;
    Motor_Intake1.spin(directionType::fwd, (int)130 * intake_speed, voltageUnits::mV);

    this_thread::sleep_for(5);
  }
}

// ---------cataStatus ---------
// 1 = ready to shoot  2 = shooting
// 0 = pulling down to preshoot pos
int cataMode = 1;
int cataStatus = 1;

void setCatapultStatus(int status){
  cataStatus = status;
}

void setCataRotateStatus(int status){
  rotateStatus = status;
}

void catapult(){
  //pid stuff
  auto cataPID = PID();
  cataPID.setCoefficient(5, 0, 0);
  cataPID.setTarget(0);
  cataPID.setIMax(25);
  cataPID.setIRange(10);
  cataPID.setErrorTolerance(2);
  cataPID.setDTolerance(20);
  cataPID.setJumpTime(50);
  //def
  double vel = 0, pos_last = 0, pos_crt = 0;
  double ready_Pos = Motor_Catapult.position(deg);

  //thread
  while(true){
    
    if (rotateStatus == 1){ //keep rotating
        Motor_Cata1.setVelocity(35,percent);
        Motor_Cata1.spin(fwd);
    }
    else if (cataStatus == 1){
      Motor_Cata1.stop(hold);
    }
    else if (cataStatus == 2){ //R1
      Motor_Cata1.setVelocity(127,percent);
      Motor_Cata1.spinToPosition(ready_Pos + 160,deg);
      wait(200, msec);
      setCataStatus(0);
    }
    else if (cataStatus == 0){ //AFTER 2
      Motor_Cata1.setVelocity(127,percent);
      Motor_Cata1.spinToPosition(ready_Pos + 360,deg);
      setCataStatus(1);
      ready_Pos = ready_Pos + 360;
    }
    else if (cataStatus == 4){ //Y
      if(limit1.PRESSED){
        setCataStatus(1);
        Motor_Cata1.resetPosition();

      }else{
        Motor_Cata1.setVelocity(20,percent);
        Motor_Cata1.spin(fwd);
        ready_Pos = 0;
      }
      // Motor_Cata1.resetPosition();
      // ready_Pos = 250;
      // Motor_Cata1.spinToPosition(250, degrees);
      // setCataStatus(1);
    }
    else if (cataStatus == 3){ //B
      Motor_Cata1.resetPosition();
      Motor_Cata1.spinToPosition(5, degrees);
      Motor_Cata1.resetPosition();
      //ready_Pos = Motor_Cata1.position(deg);
      setCataStatus(1);
    }
    else if (cataStatus == 5){ //R2
      if(cataMode==1){
        Motor_Cata1.setVelocity(127,percent);
        Motor_Cata1.spinToPosition(ready_Pos - 80,deg);
        wait(200, msec);
        cataMode=0;
        setCataStatus(1);}
      else if(cataMode==0){
        Motor_Cata1.setVelocity(127,percent);
        Motor_Cata1.spinToPosition(ready_Pos,deg);
        wait(200, msec);
        cataMode=1;
        setCataStatus(1);}
    }
    Brain.Screen.setCursor(3, 1);
    Brain.Screen.print("vel: %.1f                             ", vel);
    Brain.Screen.setCursor(4, 1);
    Brain.Screen.print("pos: %.1f                             ", Motor_Cata1.position(degrees));

    this_thread::sleep_for(5);
  }
  
}



void setPistonE(bool _input) {
  // set Expansion piston accordingly
  if (_input)  PistonE.off();
  else PistonE.on();
}

void setPistonA(bool _input) {
  // set Expansion piston accordingly
  if (_input)  PistonA.off();
  else PistonA.on();
}
