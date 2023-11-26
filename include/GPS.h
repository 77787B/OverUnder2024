#ifndef GPS_H_
#define GPS_H_

#include "vex.h"
#include "ReadWriteLock.h"

class GPS {
  private:
    // creadWriteLock gpsLock;
    // volatile float gpsPosX, gpsPosY, gpsHeading;
    volatile float xTarget, yTarget, headingTarget;
    float chassisRatio;
    int dirSign, scenario;
    float dLength, xDiff, yDiff, theta1, theta2, dTheta;

    float getLeftPosGps();
    float getRightPosGps();
    float getForwardPosGps();
    void resetLeftPosGps();
    void resetRightPosGps();
    float calTheta(float , float, int=1);
    
  public:
    GPS();
    void resetForwardPosGps();
    void setForwardPosGps(float, float);
    void updateGpsPos();
    void updateCrtPara();

    void gpsPIDCurve(float, float, float, float=100);
    void gpsCurveStep();
    void gpsPIDMove(float, float, int=1, int=90, std::string="PID");


    float getDistance(float, float);
    float getAngle(float, float, int=1);

    void posForwardRelWithHeadingGPS(float, float, float, float);
    void posForwardAbsWithHeadingGPS(float, float, float, float);

};

static GPS MyGps;
void MyGpsPos();

#endif