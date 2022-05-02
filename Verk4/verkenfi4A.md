``` c++
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*   This program will have the robot move left when it senses higher         */
/*   reflectivity than the threshold (Light maximum reflectivity +            */
/*   Dark maximum reflectivity / 2) and will move to the right when it        */
/*   senses less reflectivity than the threshold.                             */
/*                                                                            */
/*   IMPORTANT: In order for this program to work correctly, the Line         */
/*   Tracker needs to be mounted facing down towards the ground, close        */
/*   to the ground.                                                           */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// LineTrackerLeft      line          A               
// LeftMotor            motor         1               
// RightMotor           motor         10              
// LineTrackerRight     line          B               
// RangeFinderC         sonar         C, D            
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

float threshold;
bool jeff = true;
int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  wait(1, seconds);
  threshold = 30;
  while (RangeFinderC.distance(mm) > 200) {
    RightMotor.spin(forward);
    LeftMotor.spin(forward);
    wait(200, msec);
    Brain.Screen.setCursor(1, 1);
    Brain.Screen.clearScreen();
    wait(5, msec);
    // If the reflectivity is greater than the threshold it will move the LeftMotor forward
    if (LineTrackerLeft.reflectivity() > threshold) {
      LeftMotor.spin(forward);
      RightMotor.stop();
    } 
    if(LineTrackerRight.reflectivity() > threshold) {
      RightMotor.spin(forward);
      LeftMotor.stop();
    } else {
      // If the reflectivity is less than the threshold it will move the RightMotor forward
      LeftMotor.spin(forward);
      RightMotor.spin(forward);
    }
    wait(5, msec);
  }
  LeftMotor.stop();
  RightMotor.stop();
}
```
