``` c++
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    1, 10, D        
// ClawMotor            motor         3               
// ArmMotor             motor         8               
// Distance             distance      6               
// Light                light         C               
// ---- END VEXCODE CONFIGURED DEVICES ----

//!!Code automatically generated by 'ROBOTC' configuration wizard               !!//
#include "vex.h"

using namespace vex;


int main()
{
    vexcodeInit();
    while(1==1) // = while true
    {
        while (Light.brightness() > 10) // meðan ljós er stærra en 10
        {
            Brain.Screen.print("Lit Area");
            if(Distance.objectDistance(mm) < 200)
            {
              int n = rand() % 2; // random 1 eda 2 sem stjornar hvada att robotinn fer i
              if (n == 1)
              {
                Drivetrain.turn(left);
              } 
              else 
              {
                Drivetrain.turn(right);
              }
            }
            else
            {
            Drivetrain.drive(forward); // ef ekkert er fyrir robotinum fer hann afram
            }
        }
        
    }
}
```

