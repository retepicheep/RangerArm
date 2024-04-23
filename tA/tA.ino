
//--------------------------------
// RangerArm
// CCHS Basic Computer Electronics Class Project Spring 2024
// The RangerArm steers an Ultrasonic distance sensor at the end of
// an arm whose elevation/Y-vertical is control by a Servo Motor, and whose
// azmith/X-horizontal is controlled by a Stepper Motor. Also at the end of
// the arm is a "laser" pointer LED under control of code. User controls
// consist of a two-axis analog joystick with pushbutton, a 2 x 16 character
// LCD display, and an Active Buzzer.
//
// Team Assignments are as follows:
// Team A: Stepper Motor, horizontal platform position photo sensor. PIR sensors. Joystick X axis.
// Team B: Servo Motor, Ultrasonic distance sensor, Joystick Y axis.
// Team C: LCD Display, Active Buzzer, "Laser" pointer LED, Joystick push-button.
// Team T: Task Scheduler
//--------------------------------
// HERE IS THE LIBRARY CODE
// THE PINS REFERENCED HERE ARE PER THE ENGINEERING SPEC ASSIGNMENT
//--------------------------------
// Stepper Motor Library For Team A
#include <Stepper.h>
const int stepsPerRevolution = 2048;  // change this to fit the number of steps per revolution
Stepper myStepper(stepsPerRevolution, 2, 3, 4, 5);  //Set the name of the Stepper Motor object to "myStepper". Use pins D2-D5
const int rolePerMinute = 2;
//--------------------------------
// Servo Motor Library For Team B
#include <Servo.h>
Servo myservo;    //Set the name for the Servo Motor object to "myservo"
// Ultrasonic Sensor Library For Team B
#include "SR04.h"
SR04 sr04 = SR04(63,12);  //Set the name for the sensor object to "sr04". Echo pin D63, Trigger pin D12
//--------------------------------
// LCD Library For Team C
#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 8, 57, 58, 59, 60);  //Set name for the LCD object to "lcd". Use pins rs=D7, e=D8, d4-d7=D57-D60
//--------------------------------
// PINS NOT ASSIGNED ABOVE NEED TO BE INCLUDED IN THE VARIABLES SECTION BELOW
//--------------------------------
// GLOBAL VARIABLES AND CONSTANTS GO HERE (including hardware pin assignments)
//--------------------------------
// Team A Variables/Constants. Names start with tA...
int tAlightpin = A2;
const int tArolePerMinute = 17;         // Adjustable range of 28BYJ-48 stepper is 0~17 rpm
int tApos;
int currentDeg = -1;
//--------------------------------
// Team B Variables/Constants. Names start with tB...
const int tBpinServo = 9;
//--------------------------------
// Team C Variables/Constants. Names start with tC...

//--------------------------------
// Team T Variables/Constants. Names start with tT...
int tTschedulePhase = -1;
long tTlastSecond = 0;    //Hold's millis() sample from previous second
//--------------------------------
// Inter-Team Varibles/Constants. Names start with "t" followed by the capital letters of the teams sharing the memory.

//--------------------------------
void setup() {
  // put your setup code here, to run once:
  // Initialize Library Functions
  lcd.begin(16, 2);                     // For LCD Library, set LCD size
  myservo.attach(tBpinServo);           // For Servo Library, identify PWM signal pin
  myStepper.setSpeed(tArolePerMinute);  // For Stepper Motor Library, set rotation speed
  Serial.begin(38400);                  // For Serial Monitor (debugging tool) using 38,400 baud
  //--------------------------------
  //BE SURE TO INITIALIZE DIGITAL I/O PINS and ANALOG INPUT PINS IN THIS SECTION
  //--------------------------------
  //Team C setup code here (Team C is before others here so that the startup message can display while calibration occurs)

  //--------------------------------
  //Team A setup code here
  myStepper.setSpeed(rolePerMinute);

  fcnGotoX(50);

  // fcnCalibrateX();




  //*****************************************************************************
  //CALIBRATION
  //*****************************************************************************
  
  //*****************************************************************************
  //*****************************************************************************
  

  //--------------------------------
  //Team B setup code here

  //--------------------------------

}

void loop() {
  // put your main code here, to run repeatedly:
  // Time-based scheduler (Team T)
  switch (millis() & B11) {
    //--------------------------------
    case 0:   //For milliseconds whose last two bits are 0,0
    if (tTschedulePhase != 0) {   // ensure the team code only gets one execution every 4 milliseconds
      // Team A main code goes here. Tasks to be preformed include the following:
      // Read joystick X axis and use it to control Stepper Motor motion. 
      // Pass arm's horizontal position to Team C in an inter-team global variable
      // Read PIR sensors and pass to Team C in an inter-team global variable
      // DEBUG
      tTschedulePhase = 0;
    }
    break;
    //--------------------------------
    case 1:   //For milliseconds whose last two bits are 0,1
    if (tTschedulePhase != 1) {   // ensure the team code only gets one execution every 4 milliseconds
      // Team B main code goes here. Tasks to be preformed include the following:
      // Read joystick Y axis and use it to control Servo Motor motion.
      // Pass arm's vertical position to Team C in an inter-team global variable
      // Read Ultrasonic distance sensor and pass to Team C in an inter-team global variable
      tTschedulePhase = 1;
    }
    break;
    //--------------------------------
    case 2:   //For milliseconds whose last two bits are 1,0
    if (tTschedulePhase != 2) {   // ensure the team code only gets one execution every 4 milliseconds
      // Team C main code goes here. Tasks to be preformed include the following:
      // Read joystick push-buton and use it to control the "laser" pointer LED/Buzzer
      // Receive PIR status from Team A in an inter-team global variable, display on LCD, and beep Buzzer if needed
      // Receive arm X and Y position from Teams A and B in inter-team global variables and display on LCD
      // Receive distance sensor's distance from Team B in an inter-team global variable and display on LCD
      tTschedulePhase = 2;
    }
    break;
    //--------------------------------
    case 3:   //For milliseconds whose last two bits are 1,1
    if (tTschedulePhase != 3) {   // ensure the team code only gets one execution every 4 milliseconds
      // Team T main code goes here. Tasks to be preformed include the following:
      // For future Phase 2 serial communications between User I/O Deck and Machine I/O Base.
      // BELOW IS SAMPLE CODE FOR EXECUTING STATEMENTS ONCE A SECOND
      if (millis() >= (tTlastSecond + 1000)) {
        tTlastSecond = millis();  //remember when this executed so that the next execution will be 1000 ms later
        //Code here gets executed only once very second
      }
      tTschedulePhase = 3;
    }
    break;
    //--------------------------------
  }
}
//--------------------------------
// ADDED FUNCTIONS GO HERE
//--------------------------------
// Team A's Functions
// Function fcnCalibrateX
void fcnCalibrateX(){
  //the light sensor needs the correct pins still
  //i need to figure out what the photo sensor should read.
  //Turn the led on if it isnt already
  bool calibrated = false;
  while (calibrated != true) {
    int lightreading = analogRead(tAlightpin);
    if (lightreading == 100) {
      calibrated = true;
      currentDeg = 0;
    } else {
      myStepper.step(2048);
    }
  }
}
// Function fcnMoveX
// Function fcnGotoX
int fcnGotoX(int deg) {

  int moveDeg = currentDeg + deg;
  myStepper.step(moveDeg);
  currentDeg += moveDeg;
  int endDeg = fcnReadX();
  
  if (endDeg != deg) {
    return false;
  } else {
    return endDeg;
  }

}
// Function fcnReadX
int fcnReadX() {

  return currentDeg;

}

// Function fcnReadPIR
//--------------------------------
// Team B's Functions
// Function fcnMoveY
// Function fcnGotoY
// Function fcnReadY
// Function fcnReadDist
//--------------------------------
// Team C's Functions
// Function fcnDisplayXY
// Function fcnDisplayDist
// Function fcnDisplayPIR
// Function fcnDisplaySectors
// Function fcnFireOnOff
// Function fcnBuzzerOnOff
// Function fcnBuzzerBeep
//--------------------------------
// Team T's Functions
// FUTURE (PHASE 2) FUNCTIONS
// Function fcnSendToMachine
// Function fcnRcvFromMachine
// Function fcnSendToUser
// Function fcnRcvFromUser
//--------------------------------
// End of Sketch