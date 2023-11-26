#include "my-timer.h"

MyTimer::MyTimer(){
  startTime = Brain.Timer.value();
}


void MyTimer::reset(){
  startTime = Brain.Timer.value();
}

int MyTimer::getTime() const{
  return floor((Brain.Timer.value() - startTime) * 1000); // return time (msec) from startTime
}