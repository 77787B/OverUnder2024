#ifndef AUTON_FUNCTIONS_H_
#define AUTON_FUNCTIONS_H_

void voltageForward(float);
void timerForward(float, int);
void timerForwardWithHeading(float, int, float);
void posForwardRel(float, float);
void posForwardAbs(float, float);
void posForwardRelWithHeading(float, float, float);
void posForwardAbsWithHeading(float, float, float);
void PIDPosForwardAbs(float);
void PIDPosForwardRel(float);
void PIDPosCurveRel(float, float, float=2);
void PIDPosCurveAbs(float, float, float=2);
void softStartTimerForward(float, float, int);
void timerRotate(float, int);
void angleRotateRel(float, float);
void angleRotateAbs(float, float);
void PIDAngleRotateRel(float);
void PIDAngleRotateAbs(float, float=0.75, float=0.05, float=0.3, float=0.8);
void softStartTimerRotate(float, float, int);
void autonShoot(int, float, float=0, float=3600, float=0, float=3600);
void timerWait(float);

void clearAutonMode(void);
void setAutonMode(void);

#endif
