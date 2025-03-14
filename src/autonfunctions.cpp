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
    float ActualDist = abs(Chassis.get_left_position_in());
    while(abs(Chassis.get_left_position_in()) < abs(73 + ActualDist))
    wait(20,msec);
    MoGo.set(true);

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
Claw.set(true);
Chassis.drive_distance(-28);
Claw.set(false);
wait(25, msec);

Chassis.turn_to_angle(-100.5);
Intake.spin(forward, 100, pct);
Chassis.drive_distance(19.5);
wait(250, msec);
Chassis.drive_distance(-8);
Chassis.turn_to_angle(-78);
Chassis.turn_to_angle(-160);
Chassis.drive_distance(13);
wait(250, msec);
/*wait(250, msec);
Chassis.turn_to_angle(-97.5);
Chassis.drive_distance(-17);
Chassis.turn_to_angle(-45);
Chassis.drive_distance(15);
Chassis.turn_to_angle(-250)*/
}
///////////////////////////////////////////////////////////////////////////////////////////////////////

void PositiveCornerBlue()
{

    Arm.setVelocity(100,pct);
    Intake.setMaxTorque(100,pct);
    Intake.setVelocity(100,pct);
    Claw.set(true);
    wait(100,msec);

    Chassis.drive_distance(5);
    wait(200,msec);
    Arm.spin(forward);
    while(LadyB.position(degrees) < 140) {
    wait(500, msec); // Espera breve para evitar un bucle excesivo
    }
    wait(100, msec);
    Arm.stop();
    wait(100,msec);

    Arm.setVelocity(50,pct);
    Arm.spin(reverse);
    while(LadyB.position(degrees) > 5) {
    wait(10, msec); // Espera breve para evitar un bucle excesivo
    }
    Arm.stop();

    Chassis.turn_to_angle(20);
    Chassis.drive_distance(-22);
    Chassis.drive_distance(-7);
    Claw.set(false);
    Chassis.drive_distance(-3);
    Chassis.turn_to_angle(122);
    Intake.spin(forward,100,pct);       
    Chassis.drive_distance(27);
    

    /*Chassis.drive_distance(-24);
    Chassis.drive_distance(-5);
    Claw.set(false);
    wait(100,msec);
    Intake.spin(fwd,100,pct);

    Chassis.drive_distance(3);
    Chassis.turn_to_angle(90);
    Chassis.drive_distance(20);
    Chassis.drive_distance(5);
    Chassis.drive_distance(-5);
    wait(200,msec);

    Chassis.turn_to_angle(20);
    Chassis.drive_distance(42);
    wait(200,msec);

    Chassis.drive_distance(-5);
    Chassis.drive_distance(6);
    Chassis.drive_distance(-10);
    wait(200,msec);


    Chassis.turn_to_angle(200);
    Arm.spinToPosition(140,deg,false);
    //wait(200,msec);*/
    //Intake.stop();
    //Chassis.drive_distance(35);

   
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
void NegativeCornerRed()
{
Claw.set(true);
Chassis.drive_distance(-20);
Claw.set(false);
Intake.spin(reverse,100,pct);
wait(1000, msec);
Chassis.turn_to_angle(-285);
Chassis.drive_distance(17);
wait(500, msec);
Chassis.drive_distance(-25);
Chassis.turn_to_angle(-255);
Chassis.drive_distance(25);
Chassis.drive_distance(-28);
Chassis.turn_to_angle(-220);
Chassis.drive_distance(20);
Chassis.drive_distance(-30);
 /*Claw.set(true);
 Chassis.drive_distance(-28);
 Claw.set(false);
 wait(25, msec);
 Intake.spin(forward,100,pct);
 Chassis.turn_to_angle(100.5);
 Chassis.drive_distance(19.5);
 wait(250, msec);
 Chassis.drive_distance(-8);
 Chassis.turn_to_angle(78);
 Chassis.drive_distance(10.5);
 wait(250, msec);
 Chassis.turn_to_angle(98);
 Chassis.drive_distance(-17);
 Chassis.turn_to_angle(45);
 Chassis.drive_distance(15);
 Chassis.turn_to_angle(250);
 Chassis.drive_distance(40);
 Intake.stop();*/

}

///////////////////////////////////////////////////////////////////////////////////////////////////////
 


void PositiveCornerRed()
{
    Intake.setMaxTorque(100,pct);
Intake.setVelocity(90,pct);
Claw.set(false);
Claw.set(true);
Arm.setVelocity(100,pct);
    Chassis.drive_distance(6);
    Arm.spinToPosition(345,deg);
    wait(500, msec);
    Arm.spinToPosition(10,deg);
    wait(300, msec);
    Claw.set(true);
    Chassis.drive_distance(-27);
    Claw.set(false);
    Intake.spin(reverse,100,pct);
    wait(500,msec);
    Chassis.turn_to_angle(225);
    wait(500,msec);
    Chassis.drive_distance(20);
    wait(500, msec);
    Chassis.turn_to_angle(310);
    Chassis.drive_distance(35);
    wait(500,msec);
    Chassis.drive_distance(-12);
    Chassis.turn_to_angle(75);
    Chassis.drive_distance(25);

    ///Intake.setMaxTorque(100,pct);
    //Intake.setVelocity(100,pct);
    //Claw.set(true);
    //wait(100,msec);
    //Chassis.drive_distance(-24);
    //Chassis.drive_distance(-5);
    //Claw.set(false);
    //wait(100,msec);
    //Intake.spin(reverse,100,pct);
    //Chassis.drive_distance(3);
    //Chassis.turn_to_angle(270);
    //Chassis.drive_distance(20);
    //Chassis.drive_distance(5);
    //Chassis.drive_distance(-5);
    //wait(200,msec);
    ///Chassis.turn_to_angle(285);
    ///Arm.spinToPosition(150,deg,false);
    ///wait(200,msec);
    ///Intake.stop();
    ///Chassis.drive_distance(-35);



}


///////////////////////////////////////////////////////////////////////////////////////////////////////



void Skills1()
{
    


}
  