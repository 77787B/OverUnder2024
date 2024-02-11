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
extern led PistonHH;
extern led PistonFW;
extern led PistonBW;
extern limit limit1;
extern inertial IMU;
// VEXcode devices
// Andew: as a code practice - can you modify this into an array of signatures?   
// eg array<signature, 5> signatures;






/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );
