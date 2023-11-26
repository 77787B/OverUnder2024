#ifndef EZIZE_H_
#define EZIZE_H_

// #include "my-timer.h"

using namespace vex;
#define delay this_thread::sleep_for
#define printScreen Brain.Screen.printAt
#define printController Controller1.Screen.print
#define clearController Controller1.Screen.clearLine
#define C1 Controller1.Axis1.value()
#define C2 Controller1.Axis2.value()
#define C3 Controller1.Axis3.value()
#define C4 Controller1.Axis4.value()
#define L1 Controller1.ButtonL1.pressing() 
#define L2 Controller1.ButtonL2.pressing()
#define R1 Controller1.ButtonR1.pressing()
#define R2 Controller1.ButtonR2.pressing()
#define BX Controller1.ButtonX.pressing()
#define BY Controller1.ButtonY.pressing()
#define BA Controller1.ButtonA.pressing()
#define BB Controller1.ButtonB.pressing()
#define LEFT Controller1.ButtonLeft.pressing()
#define RIGHT Controller1.ButtonRight.pressing()
#define UP Controller1.ButtonUp.pressing()
#define DOWN Controller1.ButtonDown.pressing()

#endif 