#ifndef PID_H_
#define PID_H_

#include "my-timer.h"
#include "vex.h"
#include "mutex"

class PID {
private:
  float errorCurt, errorPrev, errorDev, errorInt;
  float P, I, D;
  bool firstTime;
  bool arrived;
  float kp, ki, kd;
  float target, errorTol, DTol;
  float IMax, IRange; // I < abs(IMAX) // I starts to increase when P < IRange
  float output;
  float jumpTime;
  MyTimer myTimer;
  std::string type;

public:
  PID();
  void setCoefficient(float, float, float);
  void setTarget(float);
  void setIMax(float);
  void setIRange(float);
  void setErrorTolerance(float);
  void clearErrorInt();
  void setDTolerance(float);
  void setJumpTime(float);
  void update(float input);
  bool targetArrived();
  float getI();
  float getOutput();
  void setType(std::string="normal");
};


#endif