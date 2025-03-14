#include "vex.h"
#include "robot_config.h"


using namespace std;
using namespace vex;


bool ClawSet = false;


// Intake task

int IntakeAction::JoyControl() 
{
// Bool to filter 
    bool PassState = false;
    
    while (1) 
    {


// If the claw is set down

        if(ClawSet)
        {
// If distance sensor detects a ring and filter is false
        if(DistanceSensor.objectDistance(mm) < 30  && !PassState)
        {
            Intake.stop();
            waitUntil(!Controller.ButtonR1.pressing());
            PassState = true;
// Set filter true to allow use intake after release button 
        } 


// If object is not detected, filter is set to false
        if(DistanceSensor.objectDistance(mm) > 30)
        {
            PassState = false;
        }



// Intake Control, if claw is down, speed is 70 pct
        if(Controller.ButtonR1.pressing())
                Intake.spin(fwd,70,pct);
             
        else if (Controller.ButtonR2.pressing())
            Intake.spin(fwd,-70,pct);

        else
        {
            Intake.stop();
        }
    }
    
    
// If claw is NOT set down
        else
        {
// Intake Control, speed is 100 pct 
            if(Controller.ButtonR1.pressing())
                Intake.spin(fwd,100,pct);

            else if (Controller.ButtonR2.pressing())
                Intake.spin(fwd,-100,pct);
        
            else
                Intake.stop();
        }

        wait(20,msec);
    
    }


// DONT REMOVE
    return 0;
}



