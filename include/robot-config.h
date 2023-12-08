using namespace vex;
using signature = vision::signature;
extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor Motor_BaseLF;
extern motor Motor_BaseLM;
extern motor Motor_BaseLB;
extern motor Motor_BaseRF;
extern motor Motor_BaseRM;
extern motor Motor_BaseRB;
extern motor Motor_Intake1;
extern motor Motor_Intake2;
extern motor Motor_Cata1;
extern motor Motor_Cata2;
extern led PistonTB;
extern led PistonLH;
extern led PistonHH1;
extern led PistonHH2;
extern led PistonLW;
extern led PistonRW;
extern limit limit1;
extern inertial IMU;
// VEXcode devices
// Andew: as a code practice - can you modify this into an array of signatures?   
// eg array<signature, 5> signatures;
extern signature Vision18__SIG_1;
extern signature Vision18__SIG_2;
extern signature Vision18__SIG_3;
extern signature Vision18__SIG_4;
extern signature Vision18__SIG_5;
extern vision Vision18;





/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );
