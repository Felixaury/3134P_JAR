/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       robol                                                     */
/*    Created:      7/8/2024, 3:20:47 PM                                      */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include <robot_config.h>


using namespace vex;
// PORQUE SON LAS PALABRAS EN ESPANOL! QUE RIDICULO! ES MUY DIFICIL PARA COMPRENDER LAS PALABRAS! POR FAVOR! 
// Variable global para la posición objetivo del brazo
double armTargetPosition = -1;  // -1 indica que no hay objetivo activo
competition Competition;
brain  Brain;
motor leftMotorA = motor(PORT11, ratio6_1, true);   
motor leftMotorB = motor(PORT12, ratio6_1, true);   
motor leftMotorC = motor(PORT13,  ratio6_1, true);    
motor_group LeftDriveSmart = motor_group(leftMotorA, leftMotorB, leftMotorC);
motor rightMotorA = motor(PORT18, ratio6_1, false);  
motor rightMotorB = motor(PORT19, ratio6_1, false); 
motor rightMotorC = motor(PORT20, ratio6_1, false);  
motor_group RightDriveSmart = motor_group(rightMotorA, rightMotorB, rightMotorC);
drivetrain Drivetrain = drivetrain(RightDriveSmart, LeftDriveSmart);
motor Intake = motor(PORT3, ratio18_1, true);
motor Arm = motor(PORT4, ratio36_1, false);
distance DistanceSensor = distance(PORT6);
controller Controller = controller(primary);
const int32_t InertialPort = PORT2;
rotation LadyB = rotation(PORT8);



//smartdrive Drivetrain = smartdrive(LeftDriveSmart, RightDriveSmart, DrivetrainInertial, 319.19, 320, 40, mm, 1);

Drive Chassis(ZERO_TRACKER_NO_ODOM,LeftDriveSmart,RightDriveSmart,InertialPort, 3.25, 0.6, 360,
//FOR HOLONOMIC DRIVES ONLY: Input your drive motors by position. This is only necessary for holonomic drives, otherwise this section can be left alone.
//LF:      //RF:    
PORT16,     -PORT17,

//LB:      //RB: 
PORT14,     -PORT15,

//If you are using position tracking, this is the Forward Tracker port (the tracker which runs parallel to the direction of the Chassis).
//If this is a rotation sensor, enter it in "PORT1" format, inputting the port below.
//If this is an encoder, enter the port as an integer. Triport A will be a "1", Triport B will be a "2", etc.
0,

//Input the Forward Tracker diameter (reverse it to make the direction switch):
2.75,

//Input Forward Tracker center distance (a positive distance corresponds to a tracker on the right side of the robot, negative is left.)
//For a zero tracker tank drive with odom, put the positive distance from the center of the robot to the right side of the drive.
//This distance is in inches:
-2,

//Input the Sideways Tracker Port, following the same steps as the Forward Tracker Port:
1,

//Sideways tracker diameter (reverse to make the direction switch):
-2.75,

//Sideways tracker center distance (positive distance is behind the center of the robot, negative is in front):
5.5

);

digital_out MoGo = digital_out(Brain.ThreeWirePort.A);
digital_out Claw = digital_out(Brain.ThreeWirePort.D);
digital_out Rachet = digital_out(Brain.ThreeWirePort.B);
digital_out BRAZO = digital_out(Brain.ThreeWirePort.G);

void tuned_constants()
{
Chassis.set_drive_constants(12, 0.8, 0.00, 1.2, 10); // Increase KD
  Chassis.set_heading_constants(6, .4, 0, 1, 0); // turning tune
 // Chassis.set_turn_constants(12, 0.25, 0.0005, 1.25, 15);
Chassis.set_turn_constants(12, 0.47, 0.008, 2.2, 15); // Increase KP, decrease KI, and decrease KD

  Chassis.set_swing_constants(12, 0.47, 0.008, 2.2, 15);
  Chassis.set_drive_exit_conditions(1.5, 300, 2200);
  Chassis.set_turn_exit_conditions(1, 300, 1500);
  Chassis.set_swing_exit_conditions(1, 300, 1500);
}



int current_auton_selection = 0;
bool auto_started = false;

void testing(void)
{
  NegativeCornerRed();
}


void pre_auton(void) {

tuned_constants();
Chassis.Gyro.calibrate();

  while (Chassis.Gyro.isCalibrating()) 
  {
    wait(25, msec);
  }
  Brain.Screen.clearScreen();
while(!auto_started){
    Brain.Screen.clearScreen();
    Controller.Screen.clearScreen();
    Brain.Screen.printAt(5, 20, "JAR Template v1.2.0");
    Brain.Screen.printAt(5, 40, "Battery Percentage:");
    Brain.Screen.printAt(5, 60, "%d", Brain.Battery.capacity());
    Brain.Screen.printAt(5, 80, "Chassis Heading Reading:");
    Brain.Screen.printAt(5, 100, "%f", Chassis.get_absolute_heading());
    Brain.Screen.printAt(5, 120, "Selected Auton:");
    Brain.Screen.printAt(5, 160, "LadyB Sensor Value:");
    Brain.Screen.printAt(5, 180, "%f", LadyB.position(vex::rotationUnits::deg));
    

    Controller.Screen.setCursor(2,2);
    switch(current_auton_selection){
      case 0:
        Brain.Screen.printAt(5, 140, "Negative Corner Blue");
        Controller.Screen.print("Negative Corner Blue");
        break;
      case 1:
        Brain.Screen.printAt(5, 140, "Positive Corner Blue");
        Controller.Screen.print("Positive Corner Blue");
        break;
      case 2:
        Brain.Screen.printAt(5, 140, "Negative Corner Red");
        Controller.Screen.print("Negative Corner Red");  
        break;
      case 3:
        Brain.Screen.printAt(5, 140, "Positive Corner Red");
        Controller.Screen.print("Positive Corner Red");
        break;
      case 4:
        Brain.Screen.printAt(5, 140, "Skills Auton");
        Controller.Screen.print("Skills Auton");
        break;

    }
    if(Brain.Screen.pressing()){
      while(Brain.Screen.pressing()) {}
      current_auton_selection ++;
    } else if (current_auton_selection == 5){
      current_auton_selection = 0;
    }
    task::sleep(100);
  }

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}


/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*---------------------------------------------------------------------------*/

void autonomous(void) {



switch(current_auton_selection){
      case 0:
        NegativeCornerBlue();
        break;
      case 1:
       PositiveCornerBlue();
        break;
      case 2:
        NegativeCornerRed(); 
        break;
      case 3:
        PositiveCornerRed();
        break;
      case 4:
        Skills1();
        break;


  }
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/



// Funciones estáticas para manejar los botones
void usercontrol(void) {
  
  while (1) {
    // Drivetrain control
    // Definir el umbral para la sensibilidad de los joysticks
int threshold = 5;  // Umbral mínimo para que los motores se muevan

// Leer los valores de los joysticks
int forwardBackward = Controller.Axis3.position();  // Eje vertical (avance/retroceso)
int turn = Controller.Axis1.position();  // Eje horizontal (giro)

// Aplicar umbral para evitar movimientos erráticos
if (abs(forwardBackward) < threshold) {
    forwardBackward = 0;  // Si el valor es muy bajo, detener el movimiento
}
if (abs(turn) < threshold) {
    turn = 0;  // Si el valor es muy bajo, detener el giro
}

// Calcular las velocidades para los dos lados del drivetrain
int drivetrainLeftSideSpeed = forwardBackward + turn;  // Velocidad de la rueda izquierda (avance + giro)
int drivetrainRightSideSpeed = forwardBackward - turn; // Velocidad de la rueda derecha (avance - giro)

// Suavizar los valores para evitar movimientos bruscos
drivetrainLeftSideSpeed = drivetrainLeftSideSpeed * 0.8;  // Ajustar factor de suavizado
drivetrainRightSideSpeed = drivetrainRightSideSpeed * 0.8; // Ajustar factor de suavizado

// Mover los motores con las velocidades calculadas
LeftDriveSmart.spin(forward, drivetrainLeftSideSpeed, percent);
RightDriveSmart.spin(forward, drivetrainRightSideSpeed, percent);


    // Intake control
    if (Controller.ButtonL2.pressing()) {
      Intake.spin(fwd, 100, pct);
    } else if (Controller.ButtonL1.pressing()) {
      Intake.spin(fwd, -100, pct);
    } else {
      Intake.stop(coast);
    }

    // Movimiento automático del brazo
    if (armTargetPosition != -1) {
      double currentAngle = LadyB.angle(rotationUnits::deg);

      if (currentAngle < armTargetPosition - 1) {  // Brazo debajo del objetivo
        Arm.setVelocity(50, percent);
        Arm.spin(forward);
      } else if (currentAngle > armTargetPosition + 1) {  // Brazo sobre el objetivo
        Arm.setVelocity(80, percent);
        Arm.spin(reverse);
      } else {
        // Brazo alcanzó la posición objetivo
        Arm.stop(hold);
        armTargetPosition = -1;  // Reseteamos el objetivo
      }
    } else {
      Arm.stop(hold);  // Si no hay un objetivo activo, detener el brazo
    }

    // Mogo piston control
    if (Controller.ButtonR2.pressing()) {
      MoGo.set(true);
    }
    if (Controller.ButtonR1.pressing()) {
      MoGo.set(false);
    }

    // ClawSet control
    if (Controller.ButtonR1.pressing()) {
      ClawSet = true;
    }
    if (Controller.ButtonR2.pressing()) {
      ClawSet = false;
    }

    if (ClawSet && !Claw.value()) {
      Claw.set(true);
    }
    if (!ClawSet && Claw.value()) {
      Claw.set(false);
    }

    // DOINKER control
    if (Controller.ButtonY.pressing()) {
      BRAZO.set(false);
    }
    if (Controller.ButtonA.pressing()) {
      BRAZO.set(true);
    }

    task::sleep(20);  // Espera pequeña para no sobrecargar el procesador
  }
}










//
// Main will set up the competition functions and callbacks.
//
int main() {

  

  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(Skills1);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  

  // Prevent main from exiting with an infinite loop.
  while (true) {
    Controller.Screen.clearScreen();
    Controller.Screen.print(Chassis.get_absolute_heading());
    wait(20, msec);
  }
}
                        


// como como comida es muy cuy. MUY CUY!!!
// JAJAJAJAJJJJJAAAAAA
// Ay son muy bonita cuy!