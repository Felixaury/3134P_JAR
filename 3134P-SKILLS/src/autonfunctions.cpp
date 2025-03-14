#include "vex.h"
#include "robot_config.h"

#define open true


int Takemogo()
{
    while(abs(Chassis.get_left_position_in()) < 35)
    wait(20,msec);
    MoGo.set(true);

    return 0;
}

int Takemogo2()
{
    float ActualDist = abs(Chassis.get_left_position_in());
    while(abs(Chassis.get_left_position_in()) < abs(28 + ActualDist))
    wait(20,msec);
    MoGo.set(true);

    return 0;
}

int Takemogo3()
{
    wait(1100,msec);
    return 0;
}

int Takemogo4()
{
    wait(1100,msec);
    MoGo.set(true);

    return 0;
}



int HoldRing()
{
    while(DistanceSensor.objectDistance(mm) > 30)
    Intake.spin(fwd,100,pct);
    
    Intake.stop();
    return 0;
}






















// AUTONS

///////////////////////////////////////////////////////////////////////////////////////////////////////

void NegativeCornerBlue()
{
    
    
    
}

///////////////////////////////////////////////////////////////////////////////////////////////////////

void PositiveCornerBlue()
{



   
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
void NegativeCornerRed()
{
    

}

///////////////////////////////////////////////////////////////////////////////////////////////////////
 


void PositiveCornerRed()
{
    


}


///////////////////////////////////////////////////////////////////////////////////////////////////////


 
void Skills1()
{
//SET UP//
Intake.setMaxTorque(100,pct);
Intake.setVelocity(90,pct);
Claw.set(false);
Claw.set(true);
Arm.setVelocity(100,pct);
wait(100,msec);

//SCORE PRELOAD//
Arm.spinToPosition(345,deg,false);
wait(1000,msec);
Arm.spinToPosition(3,deg,false);

//GRAB MOBILE GOAL//
Intake.spin(reverse,80,pct);
Chassis.drive_distance(-9);
Chassis.turn_to_angle(90);
wait(100,msec);
Chassis.drive_distance(-20);
wait(100,msec);
Chassis.drive_distance(-1);
Claw.set(false);
wait(100,msec);

//GRAB 2 RINGS//
Chassis.turn_to_angle(180);
Chassis.drive_distance(28);
Intake.spin(reverse,100,pct);
Chassis.drive_distance(-8);
Chassis.turn_to_angle(205);
Chassis.drive_distance(40);
Chassis.turn_to_angle(320);
wait(1000,msec); 
//HIGH STAKE//
Arm.spinToPosition(50,deg,false);
Chassis.drive_distance(20);
Chassis.drive_distance(-4);
Chassis.turn_to_angle(270);
Chassis.drive_distance(7);
Intake.spin(reverse,0,pct);
Arm.spinToPosition(345,deg,false);
wait(1000,msec);
Arm.spinToPosition(3,deg,false);

//FILL MOGO//
Intake.spin(reverse,100,pct);
Chassis.drive_distance(-13);
Chassis.turn_to_angle(5); 
Chassis.drive_distance(35, 0, 5, 9);
Chassis.drive_distance(15, 0, 12, 9);
wait(500,msec);
Chassis.drive_distance(-15);
Chassis.turn_to_angle(270);
Chassis.drive_distance(10);
Chassis.drive_distance(-7);
Chassis.turn_to_angle(135);
Chassis.drive_distance(-15);
Claw.set(true);

//new mogo//
Chassis.drive_distance(13);
Chassis.turn_to_angle(270);
Chassis.drive_distance(-50);
Chassis.drive_distance(-8, 0, 6, 9);
wait(100,msec);
Claw.set(false);
wait(100,msec);
Chassis.turn_to_angle(180);
Chassis.drive_distance(16);
Chassis.turn_to_angle(225);
Chassis.drive_distance(15);

/* (DONT INCLUDE BAD CODE) SCORE 2 RINGS//
Chassis.drive_distance(10);     
Chassis.turn_to_angle(270);
wait(100,msec);
Chassis.drive_distance(20);
wait(100,msec);
Chassis.drive_distance(-9);
Chassis.drive_distance(32);
Chassis.drive_distance(-5);

//SCORE 1 RING//
Chassis.drive_distance(-14);
Chassis.turn_to_angle(300);
Chassis.drive_distance(16);
Chassis.drive_distance(-4);
Chassis.drive_distance(7);
Chassis.turn_to_angle(140);
Chassis.drive_distance(10);*/

}
