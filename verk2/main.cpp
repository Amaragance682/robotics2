/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Wed Sep 25 2019                                           */
/*    Description:  Clawbot (Drivetrain) - Template                           */
/*                                                                            */
/*    Name:                                                                   */
/*    Date                                                                    */
/*    Class:                                                                  */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// ArmMotor             motor         2               
// Drivetrain           drivetrain    1, 10, A        
// ClawMotor            motor         9               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();/*
  Drivetrain.driveFor(forward, 1150, mm);
  Drivetrain.turnFor(left, 90, degrees);
  Drivetrain.driveFor(forward, 1150, mm);
  Drivetrain.turnFor(right, 90, degrees);
  Drivetrain.driveFor(forward, 1150, mm);
  Drivetrain.turnFor(right, 90, degrees);
  Drivetrain.driveFor(forward, 1150, mm);
  ArmMotor.setPosition(0, degrees);*/
  // Move the Arm up and hold the position for 2 seconds
  //6:1 = 24, 18:1 = 8, 36:1 = 4 sinnum það sem þú vilt
  ArmMotor.spinFor(forward, 90*7, degrees); 
  wait(2, seconds);
  // Lower the Arm and hold that position for 2 seconds
  ArmMotor.spinFor(reverse, 30*7, degrees);
  wait(2, seconds);
  // Stop the motor. The arm will now lower all the way down due to gravity
  
  ClawMotor.setPosition(0, degrees);
  ClawMotor.spinFor(forward, 90*9, degrees);
  wait(2, sec);
  ClawMotor.spinFor(reverse, 30*9, degrees);
  wait(2, sec);
  ClawMotor.spinFor(reverse, 60*9, degrees);
  wait(2, sec);
  ArmMotor.stop();
}
