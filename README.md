# CCHS RangerArm Engineering Specification – Spring 2024 


## REVISION HISTORY 


<table>
  <tr>
   <td>
    <strong>Revision </strong>
   </td>
   <td>
    <strong>Date </strong>
   </td>
   <td>
    <strong>Change Log</strong>
   </td>
  </tr>
  <tr>
   <td>
    1.0 
   </td>
   <td>
    4/15/2024 
   </td>
   <td>
    Initial publication by Mr. Richmond
   </td>
  </tr>
  <tr>
   <td>
   </td>
   <td>
   </td>
   <td>
   </td>
  </tr>
  <tr>
   <td>
   </td>
   <td>
   </td>
   <td>
   </td>
  </tr>
  <tr>
   <td>
   </td>
   <td>
   </td>
   <td>
   </td>
  </tr>
</table>



## INTRODUCTION 

This engineering specification is for an intrusion detection proof-of-concept project called the  RangerArm. The RangerArm uses the following components of the ELEGOO Most Complete Starter Kit;  MEGA 2560 Microcontroller Board, Passive Infrared (PIR) detectors to sense motion of warm bodies,  Ultrasonic Sensor for detecting changes in distance of objects, Stepper Motor to horizontally direct the  Ultrasonic Sensor, Servo Motor to vertically direct the Ultrasonic Sensor, Pointer LED to “light-up” the  suspected intrusion, Analog Joystick to provide manual user control the direction motors, Active Beeper  to provide user notification/feedback, and LCD Display to display the status to the user. 


## TEAMS & RESPONSIBILITIES 

The project is to be developed by three student teams (each consisting of two students) and the teacher.


<table>
  <tr>
   <td><strong>TEAM </strong>
   </td>
   <td>
    <strong>Members </strong>
   </td>
   <td>
    <strong>Development Focus</strong>
   </td>
  </tr>
  <tr>
   <td>
    A 
   </td>
   <td>
    Gabe Losh 
<p>

   Peter Dillow
   </td>
   <td>
    Stepper Motor Control (horizontal positioning) 
<p>

   Horizontal Platform Position Sensor (photo resistor) 
<p>

   Passive Infrared (PIR) Sensors (warm body motion detection) Joystick Input X Axis (user I/O)
   </td>
  </tr>
  <tr>
   <td>
    B 
   </td>
   <td>
    Conrad Steelman Jedi Iorga
   </td>
   <td>
    Servo Motor Control (vertical positioning) 
<p>

   Ultrasonic Sensor (distance measuring) 
<p>

   Joystick Input Y Axis (user I/O)
   </td>
  </tr>
  <tr>
   <td>
    C 
   </td>
   <td>
    Lucy Dillow 
<p>

   Luke Gies
   </td>
   <td>
    “Laser” Pointer LED Control (target illumination) 
<p>

   LCD Display (user I/O) 
<p>

   Active Beeper (user I/O) 
<p>

   Joystick Pushbutton (user I/O)
   </td>
  </tr>
  <tr>
   <td>
    T 
   </td>
   <td>
    Mr. Richmond 
<p>

   (Teacher/Coach)
   </td>
   <td>
    Scheduler 
<p>

   Communications (possible Phase 2)
   </td>
  </tr>
</table>



### IMPORTANT 
Teams may NOT use AI to generate their code! Instead, teams are encouraged to first review the list of  Arduino language elements, and their detailed descriptions to try to code what they need, and to use  the Serial Monitor to experiment for the best coding solution (see also the Development Aids section).  Secondarily team members may consult each other, and as a last resort, they may use examples from  Arduino sketches found in the ELEGOO folders, on the Arduino web site, or elsewhere on the web. The  goal is to build good coding skills, and to ingrain coding techniques into your mind which occurs best by  doing, rather than copying.



## Code Review 

A periodic code review of each team’s work will be held in-class. The team’s adherence to the  requirements of this specification and the quality of the code they’ve written will be constructively  evaluated (but not graded – except for the assigned functions). The purpose is to help students improve  their coding skills. 


## Hardware Resources (MEGA 2560 I/O) 

To avoid conflict of hardware resources, the following MEGA 2560 I/O pins are designated for use by  specific hardware components and the associated teams according to the table below. 


<table>
  <tr>
   <td>
    <strong>MEGA 2560  I/O Pin</strong>
   </td>
   <td>
    <strong>Purpose </strong>
   </td>
   <td>
    <strong>Type of I/O </strong>
   </td>
   <td><strong>Team</strong>
   </td>
  </tr>
  <tr>
   <td>
    D0/RXD0 
   </td>
   <td>
    Reserved 
   </td>
   <td>
    For IDE Upload and Serial Monitor
   </td>
   <td>
   </td>
  </tr>
  <tr>
   <td>
    D1/TXD0 
   </td>
   <td>
    Reserved 
   </td>
   <td>
    For IDE Upload and Serial Monitor
   </td>
   <td>
   </td>
  </tr>
  <tr>
   <td>
    D2 
   </td>
   <td>
    Stepper Motor In1 
   </td>
   <td>
    Digital Output (PWM?) 
   </td>
   <td>
    A
   </td>
  </tr>
  <tr>
   <td>
    D3 
   </td>
   <td>
    Stepper Motor In2 
   </td>
   <td>
    Digital Output (PWM?) 
   </td>
   <td>
    A
   </td>
  </tr>
  <tr>
   <td>
    D4 
   </td>
   <td>
    Stepper Motor In3 
   </td>
   <td>
    Digital Output (PWM?) 
   </td>
   <td>
    A
   </td>
  </tr>
  <tr>
   <td>
    D5 
   </td>
   <td>
    Stepper Motor In4 
   </td>
   <td>
    Digital Output (PWM?) 
   </td>
   <td>
    A
   </td>
  </tr>
  <tr>
   <td>
    D6 
   </td>
   <td>
    Servo Motor PWM 
   </td>
   <td>
    Digital Output (PWM) 
   </td>
   <td>
    B
   </td>
  </tr>
  <tr>
   <td>
    D7 
   </td>
   <td>
    LCD Reg Select RS 
   </td>
   <td>
    Digital Output 
   </td>
   <td>
    C
   </td>
  </tr>
  <tr>
   <td>
    D8 
   </td>
   <td>
    LCD Enable E 
   </td>
   <td>
    Digital Output 
   </td>
   <td>
    C
   </td>
  </tr>
  <tr>
   <td>
    D9 
   </td>
   <td>
    Spare 
   </td>
   <td>
   </td>
   <td>
    A
   </td>
  </tr>
  <tr>
   <td>
    D10 
   </td>
   <td>
    Spare 
   </td>
   <td>
   </td>
   <td>
    B
   </td>
  </tr>
  <tr>
   <td>
    D11 
   </td>
   <td>
    Spare 
   </td>
   <td>
   </td>
   <td>
    C
   </td>
  </tr>
  <tr>
   <td>
    D12 
   </td>
   <td>
    Ultrasonic Sensor Trigger 
   </td>
   <td>
    Digital Output (PWM?) 
   </td>
   <td>
    B
   </td>
  </tr>
  <tr>
   <td>
    D13 
   </td>
   <td>
    “Laser” Pointer LED 
   </td>
   <td>
    Digital Output (PWM) 
   </td>
   <td>
    C
   </td>
  </tr>
  <tr>
   <td>
    D14/TXD3 
   </td>
   <td>
    PIR Sensor NE Quadrant 
   </td>
   <td>
    Digital Input 
   </td>
   <td>
    A
   </td>
  </tr>
  <tr>
   <td>
    D15/RXD3 
   </td>
   <td>
    PIR Sensor SE Quadrant 
   </td>
   <td>
    Digital Input 
   </td>
   <td>
    A
   </td>
  </tr>
  <tr>
   <td>
    D16/TXD2 
   </td>
   <td>PIR Sensor SW Quadrant* 
   </td>
   <td>
    Digital Input 
   </td>
   <td>
    A
   </td>
  </tr>
  <tr>
   <td>
    D17/RXD2 
   </td>
   <td>PIR Sensor NW Quadrant* 
   </td>
   <td>
    Digital Input 
   </td>
   <td>
    A
   </td>
  </tr>
  <tr>
   <td>
    D18/TXD1 
   </td>
   <td>
    Serial Communications* 
   </td>
   <td>
    Serial Port Output 
   </td>
   <td>
    T
   </td>
  </tr>
  <tr>
   <td>
    D19/RXD1 
   </td>
   <td>
    Serial Communications* 
   </td>
   <td>
    Serial Port Input 
   </td>
   <td>
    T
   </td>
  </tr>
  <tr>
   <td>
    A0/D54 
   </td>
   <td>
    Joystick X 
   </td>
   <td>
    Analog Input 
   </td>
   <td>
    A
   </td>
  </tr>
  <tr>
   <td>
    A1/D55 
   </td>
   <td>
    Joystick Y 
   </td>
   <td>
    Analog Input 
   </td>
   <td>
    B
   </td>
  </tr>
  <tr>
   <td>
    A2/D56 
   </td>
   <td>
    Photo Resistor 
   </td>
   <td>
    Analog Input (w/ pullup?) 
   </td>
   <td>
    C
   </td>
  </tr>
  <tr>
   <td>
    A3/D57 
   </td>
   <td>
    LCD Data Bus DB4 
   </td>
   <td>
    Digital I/O 
   </td>
   <td>
    C
   </td>
  </tr>
  <tr>
   <td>
    A4/D58 
   </td>
   <td>
    LCD Data Bus DB5 
   </td>
   <td>
    Digital I/O 
   </td>
   <td>
    C
   </td>
  </tr>
  <tr>
   <td>
    A5/D59 
   </td>
   <td>
    LCD Data Bus DB6 
   </td>
   <td>
    Digital I/O 
   </td>
   <td>
    C
   </td>
  </tr>
  <tr>
   <td>
    A6/D60 
   </td>
   <td>
    LCD Data Bus DB7 
   </td>
   <td>
    Digital I/O 
   </td>
   <td>
    C
   </td>
  </tr>
  <tr>
   <td>
    A7/D61 
   </td>
   <td>
    Active Buzzer 
   </td>
   <td>
    Digital Output 
   </td>
   <td>
    C
   </td>
  </tr>
  <tr>
   <td>
    A8/D62 
   </td>
   <td>
    Joystick Button 
   </td>
   <td>
    Digital Input w/ pullup 
   </td>
   <td>
    C
   </td>
  </tr>
  <tr>
   <td>
    A9/D63 
   </td>
   <td>
    Ultrasonic Sensor Echo 
   </td>
   <td>
    Digital Input (w/ Interrupt?) 
   </td>
   <td>
    B
   </td>
  </tr>
  <tr>
   <td>
    A10-A15 
   </td>
   <td>
    Spare 
   </td>
   <td>
    Request pins from teacher if needed
   </td>
   <td>
   </td>
  </tr>
  <tr>
   <td>
    D22-D53 
   </td>
   <td>
    Spare 
   </td>
   <td>
    Request pins from teacher if needed
   </td>
   <td>
   </td>
  </tr>
</table>



   Table Note: * = for possible use in Phase 2


## Memory Resources (Variables/Constants) 

Each team shall use no more than 1/6<sup>th </sup>of the available 8196 bytes of MEGA 2560 volatile RAM memory (1365 bytes maximum for each team, leaving 2/6 or 1/3 of the memory free for stack use so as to avoid  unstable operation). To avoid conflicting use of global variable and constant names, each team shall use  the variable/constant name prefixes according to the table below: 


<table>
  <tr>
   <td><strong>TEAM </strong>
   </td>
   <td>
    <strong>Global Variable & Constant Name Prefixes</strong>
   </td>
  </tr>
  <tr>
   <td>
    A 
   </td>
   <td>
    tA…
   </td>
  </tr>
  <tr>
   <td>
    B 
   </td>
   <td>
    tB…
   </td>
  </tr>
  <tr>
   <td>
    C 
   </td>
   <td>
    tC…
   </td>
  </tr>
  <tr>
   <td>
    T 
   </td>
   <td>
    tT…
   </td>
  </tr>
</table>

For global variable memory that will be shared between teams (such as horizontal and vertical arm  positions, sensor activity, sensor distance), the following variable name prefixes will be used: 


<table>
  <tr>
   <td><strong>TEAMS </strong>
   </td>
   <td>
    <strong>Global Variable & Constant Name Prefixes</strong>
   </td>
  </tr>
  <tr>
   <td>
    A & C 
   </td>
   <td>
    tAC…
   </td>
  </tr>
  <tr>
   <td>
    B & C 
   </td>
   <td>
    tBC…
   </td>
  </tr>
  <tr>
   <td>
    A & B 
   </td>
   <td>
    tAB…
   </td>
  </tr>
  <tr>
   <td>
    A & T 
   </td>
   <td>
    tAT…
   </td>
  </tr>
  <tr>
   <td>
    B & T 
   </td>
   <td>
    tBT…
   </td>
  </tr>
  <tr>
   <td>
    C & T 
   </td>
   <td>
    tCT…
   </td>
  </tr>
</table>



## Time Resources (Scheduler) 

To ensure sufficient CPU cycles for each team’s code to be serviced in a timely manner, a Scheduler will  be developed by the teacher/coach to provide each team with the ability to run their code as frequently  as every 4 milliseconds. The determination of time will be from the Arduino Millis() function. 


<table>
  <tr>
   <td><strong>TEAM </strong>
   </td>
   <td>
    <strong>Milliseconds (Millis()) whose binary value ends with…</strong>
   </td>
  </tr>
  <tr>
   <td>
    A 
   </td>
   <td>
    B00 (e.g. 0, 4, 8, 12, 16 … ms)
   </td>
  </tr>
  <tr>
   <td>
    B 
   </td>
   <td>
    B01 (e.g. 1, 5, 9, 13, 17… ms)
   </td>
  </tr>
  <tr>
   <td>
    C 
   </td>
   <td>
    B10 (e.g. 2, 6, 10, 14, 18… ms)
   </td>
  </tr>
  <tr>
   <td>
    T 
   </td>
   <td>
    B11 (e.g. 3, 7, 11, 15, 19… ms)
   </td>
  </tr>
</table>

Functions called during a team’s time slot shall have a maximum duration of 1000 milliseconds on an  irregular basis (no more than once every 4 seconds), preferably 500 milliseconds or less on a regular  basis (averaged over 16 seconds). Because each team’s code is allowed to consume from between 500 and 1000 ms when executed, teams are not guaranteed to be able to execute their code every 4  milliseconds (i.e. 250 times each second).


## External Libraries 

The following libraries from the ELEGOO Most Complete Starter Kit (aka Mega Project Kit or MEGA 2560  Kit) are available to simplify the development of component I/O software development. Other  components not listed in the table below are simple enough to not need a software library. 


<table>
  <tr>
   <td><strong>Team </strong>
   </td>
   <td>
    <strong>For This Component </strong>
   </td>
   <td>
    <strong>Use This Library </strong>
   </td>
   <td>
    <strong>Reference ELEGOO Lesson</strong>
   </td>
  </tr>
  <tr>
   <td>
    A 
   </td>
   <td>
    Stepper Motor 
   </td>
   <td>
    Stepper.h 
   </td>
   <td>
    31 (pg 206 to 213/233)
   </td>
  </tr>
  <tr>
   <td>
    B 
   </td>
   <td>
    Servo Motor 
   </td>
   <td>
    Servo.h 
   </td>
   <td>
    9 (pg 76 to 79/233)
   </td>
  </tr>
  <tr>
   <td>
    B 
   </td>
   <td>
    Ultrasonic Sensor 
   </td>
   <td>
    HC-SR04.h 
   </td>
   <td>
    10 (pg 80 to 84/233)
   </td>
  </tr>
  <tr>
   <td>
    C 
   </td>
   <td>
    LCD Display 
   </td>
   <td>
    LiquidCrystal.h 
   </td>
   <td>
    22 (pg 152 to 156/233)
   </td>
  </tr>
</table>



## Function Assignments 

Each team member is assigned to develop functions needed for the project according to the table below.  Team members will be scored on how successful they were in meeting the function requirements  described below with a possible point score of 400 points (equal in weight to four weekly quizzes) which  applies towards their course grade. At least one function from each student should be added during  each week’s code submission. It is recommended that students start by coding the easiest/simplest  assigned functions first so that they have something that can be reviewed during each weekly class. Students whose coded functions do not meet the requirements below will be given the chance to  improve their code for the subsequent week’s submission. All functions need to be completed by the  final class day of May 19 to receive the full 400 points. 

Note that these functions are not the only code that must be developed. Code for the “setup” and  “loop” sections of the sketch are also needed, and functions other than those required below may be  added if needed. Code in those sections as well as non-required functions will be evaluated, but will not  impact the grade point scores. Code for the “setup” and “loop” sections and other functions may be  written by one or both team members, and should call the required functions that the individual team  members have developed.


<table>
  <tr>
   <td>
    <strong>Team  </strong>
<p>

   <strong>Member</strong>
   </td>
   <td>
    <strong>Function name </strong>
   </td>
   <td>
    <strong>Function description</strong>
   </td>
  </tr>
  <tr>
   <td>
    A - Gabe 
   </td>
   <td>
    fcnCalibrateX 
   </td>
   <td>
    <strong><span style="text-decoration:underline;">Parameters passed to</span> </strong>function: (0) none 
<p>

   <strong><span style="text-decoration:underline;">Parameters returned from </span></strong>function: (1) Boolean True if Calibrate succeeded (arm positioned at zero degrees), Boolean False if  Calibrate failed (arm position unknown). 
<p>

   <strong>NOTES</strong>:  
<p>

   1) Because this function is only executed during “setup”, it is  allowed to use up to 30 seconds of execution time. 
<p>

   2) This function should cause the arm’s horizontal platform to  rotate while monitoring the Photo Sensor (aka Photo Resistor). 3) A white LED in the platform may shine light through a “tunnel” to the photo sensor in the base. The Team has the option to either permanently power the LED, or it may be placed under software  control, with it’s brightness regulated via PWM (Team A’s spare I/O  on pin D9 may be used for this).
   </td>
  </tr>
</table>



<table>
  <tr>
   <td>
    <strong>Team  </strong>
<p>

   <strong>Member</strong>
   </td>
   <td>
    <strong>Function name </strong>
   </td>
   <td>
    <strong>Function description</strong>
   </td>
  </tr>
  <tr>
   <td>
   </td>
   <td>
   </td>
   <td>
    4) Some level of ambient room light will leak through the clearance  between the gear platform and the base, partially illuminating the  sensor. However, only when the platform’s LED is directly over the  sensor will the sensor show maximum brightness. Some  experimentation will be needed to set a threshold that indicates  when the LED is directly over the sensor. 
<p>

   5) At the completion of successful calibration the arm must be  pointed directly head which is also the zero degree position.
   </td>
  </tr>
  <tr>
   <td>
    A - Gabe 
   </td>
   <td>
    fcnMoveX 
   </td>
   <td>
    <strong><span style="text-decoration:underline;">Parameters passed to</span> </strong>function: (1) an integer which if negative  moves the arm 15 degrees further left (counter-clockwise), and if  positive moves the arm 15 degrees further right (clockwise). If zero,  motion is halted (or no action if the arm is already stationary). <strong><span style="text-decoration:underline;">Parameters returned from </span></strong>function: (1) an integer indicating the  new absolute horizontal position of the arm in degrees from 0 to  359 if the move was successful. Returns -1 if the requested move  can’t be made (due to exceeding the horizontal range-of-motion  constant thresholds). 
<p>

   <strong><span style="text-decoration:underline;">NOTES:</span> </strong>
<p>

   1) A global variable will be needed by the function to remember  the last known horizontal position of the arm so that new motions  can be made relative to its last known position. 
<p>

   2) For Phase 1 the horizontal range of motion thresholds should be  270 (far left/counter-clockwise) and 90 (far right/clockwise). 3) The desired rate of horizontal rotation of the arm platform  should be about 417 milliseconds per 15 degrees. The maximum  RPM of the Stepper Motor shaft is approximately 17 RPM. With a  14 to 40 gear ratio, this should allow the platform to rotate at close  to 6 RPM, or 1/10<sup>th </sup>of a rotation per second (10 seconds per full rotation).
   </td>
  </tr>
  <tr>
   <td>
    A - Peter 
   </td>
   <td>
    fcnGotoX 
   </td>
   <td>
    <strong><span style="text-decoration:underline;">Parameters passed to</span> </strong>function: (1) an integer indicating the  desired absolute horizontal position of the arm, ranging from 0 to  359 degrees, with a desired resolution of 1 degree. 
<p>

   <strong><span style="text-decoration:underline;">Parameters returned from </span></strong>function: (1) an integer indicating the  new absolute horizontal position of the arm in degrees from 0 to  359. If the move was successful (i.e. no range limit occurred), the  returned value will equal the value passed to the function. 
<p>

   <strong>NOTES:  </strong>
<p>

   1) This function is allowed to use up to 10 seconds of execution  time (27.8 milliseconds per degree moved). 
<p>

   Notes for fcnMoveX also apply to this function.
   </td>
  </tr>
  <tr>
   <td>
    A - Peter 
   </td>
   <td>
    fcnReadX 
   </td>
   <td>
    <strong><span style="text-decoration:underline;">Parameters passed to</span> </strong>function: (0) none. 
<p>

   <strong><span style="text-decoration:underline;">Parameters returned from </span></strong>function: (1) an integer indicating the  current horizontal position of the arm in degrees from 0 to 359 if  the “setup” calibration was successful. Otherwise returns -1 (position unknown).
   </td>
  </tr>
</table>



<table>
  <tr>
   <td>
    <strong>Team  </strong>
<p>

   <strong>Member</strong>
   </td>
   <td>
    <strong>Function name </strong>
   </td>
   <td>
    <strong>Function description</strong>
   </td>
  </tr>
  <tr>
   <td>
    A - Peter 
   </td>
   <td>
    fcnReadPIR 
   </td>
   <td>
    <strong>Parameters passed to </strong>function: (0) none 
<p>

   <strong>Parameters returned from </strong>function: (1) a byte whose least  significant four bits show the individual PIR sensor status for all  four quadrants as follows:  
<p>

   * Least Significant Bit (LSB – aka Bit 0) for NorthEast (NE) quadrant,  * Bit 1 for SE quadrant,  
<p>

   * Bit 2 for SW quadrant,  
<p>

   * Bit 3 for NW quadrant. 
<p>

   Active PIR sensors will be indicated by a bit value of 1, inactive PIR  sensors will be indicated by a bit value of 0. 
<p>

   <strong>NOTES: </strong>
<p>

   1) The PIR sensors have a measurement angle of 110 degrees. With  four sensors each mounted 90 degrees from one another, this  provides a 20 degree overlap between quadrants. Therefore a  single warm body in morion may set off two PIR sensors. 2) For Phase 1 only the NE and NW quadrants will be used.
   </td>
  </tr>
  <tr>
   <td>B- Conrad 
   </td>
   <td>
    fcnMoveY 
   </td>
   <td>
    <strong><span style="text-decoration:underline;">Parameters passed to</span> </strong>function: (1) an integer which if negative  moves the arm 15 degrees down, and if positive moves the arm 15  degrees further up. If zero, motion is halted (or no action if the arm  is already stationary). 
<p>

   <strong><span style="text-decoration:underline;">Parameters returned from </span></strong>function: (1) an integer indicating the  new absolute horizontal position of the arm in degrees from 0 to  180 if the move was successful. Returns -1 if the requested move  can’t be made (due to exceeding the vertical range-of-motion  
<p>

   constant thresholds). 
<p>

   <strong>NOTES</strong>:  
<p>

   1) A global variable will be needed by the function to remember  the last known vertical position of the arm so that new motions  can be made relative to its last known position. 
<p>

   2) The team should set the vertical range-of-motion thresholds in  code to avoid the arm colliding with the base, and to avoid the arm  turning past the vertical position (180 degrees). 
<p>

   3) The speed at which the arm moves vertically should be carefully  controlled to avoid jerking the mechanism. The recommended rate  of rotation is about 417 ms for each 15 degrees (same as the  desired rate for horizontal motion). 
<p>

   4) 90 degrees should result in the arm being horizontal. 180  degrees should result in the arm being vertical.
   </td>
  </tr>
  <tr>
   <td>B- Conrad 
   </td>
   <td>
    fcnReadY 
   </td>
   <td>
    <strong><span style="text-decoration:underline;">Parameters passed to</span> </strong>function: (0) none. 
<p>

   <strong><span style="text-decoration:underline;">Parameters returned from </span></strong>function: (1) an integer indicating the  current vertical position of the arm in degrees from 0 to 180. If the  position is unknown the function should return -1.
   </td>
  </tr>
  <tr>
   <td>
    B- Jedi 
   </td>
   <td>
    fcnGotoY 
   </td>
   <td>
    <strong><span style="text-decoration:underline;">Parameters passed to</span> </strong>function: (1) an integer indicating the  desired absolute vertical position of the arm, ranging from 0 to 180 degrees, with a desired resolution of 1 degree. A value of 90 should  result in the arm being horizontal. A value of 180 should result In 
   </td>
  </tr>
</table>



<table>
  <tr>
   <td>
    <strong>Team  </strong>
<p>

   <strong>Member</strong>
   </td>
   <td>
    <strong>Function name </strong>
   </td>
   <td>
    <strong>Function description</strong>
   </td>
  </tr>
  <tr>
   <td>
   </td>
   <td>
   </td>
   <td>
    the arm being vertical. 
<p>

   <strong><span style="text-decoration:underline;">Parameters returned from </span></strong>function: (1) an integer indicating the  new absolute horizontal position of the arm in degrees from 0 to  180. If the move was successful, the returned value will equal the  parameter passed to the function. 
<p>

   <strong>NOTES:  </strong>
<p>

   1) This function is allowed to use up to 5 seconds of execution time (27.8 milliseconds per degree moved). 
<p>

   2) Notes for fcnMoveY also apply to this function.
   </td>
  </tr>
  <tr>
   <td>
    B- Jedi 
   </td>
   <td>
    fcnReadDist 
   </td>
   <td>
    <strong>Parameters passed to </strong>function: (0) none 
<p>

   <strong>Parameters returned from </strong>function: (1) an integer containing the distance measured by the Ultrasonic Sensor in inches with a value  between 0 and 158. 
<p>

   <strong>NOTES: </strong>
<p>

   1) The Ultrasonic Sensor measures a range of 2 to 400 cm. It’s  library only returns the distance in metric. This must be converted  to inches. 
<p>

   2) The Ultrasonic Sensor has a 15 degree measurement angle  (which is why we are using 15 degree sectors for this project).
   </td>
  </tr>
  <tr>
   <td>
    C – Lucy 
   </td>
   <td>
    fcnDisplayXY 
   </td>
   <td>
    <strong>Parameters passed to </strong>function: (2) #1 an integer of value 0 to 359  degrees indicating the horizontal (X) position of the arm. #2 an  integer of value 0 to 180 degrees indicating the vertical (Y) position  of the arm. 
<p>

   <strong>Parameters returned from </strong>function: (1) A Boolean value; true if the  input values are within the specified range, otherwise false. <strong>NOTES: </strong>
<p>

   1) This function will only write to the top line of the 2 x 16 LCD  display. 
<p>

   2) The display is 16 characters wide. The first 3 columns are  reserved for the PIR sensor status and a delimiting space. The last  two columns are reserved for displaying sector info. 
<p>

   3) The X position should be displayed in columns 4 through 7 in this  format “xHHH” (where “HHH” is the numeric X position value)  followed by a degree symbol in column 8 followed by a space in  column 9.  
<p>

   4) The Y position should be displayed in columns 10 through 13 in  this format “yVVV” (where “VVV” is the numeric Y position value) followed by a space in column 14 (no degree symbol for this value). 5) Initially it is OK to use the character “d” as the degree symbol, but the standard degree symbol (°) should be used prior to  completion (Phase 1b). 
<p>

   6) This function will necessitate re-writing information supplied to  other display functions. Therefore, memory written by functions  fcnDisplayPIR and fcnDisplaySectors will need to be included in this  function’s LCD.print() calls. 
<p>

   7) Likewise, this function will need to store it’s position input 
   </td>
  </tr>
</table>



<table>
  <tr>
   <td>
    <strong>Team  </strong>
<p>

   <strong>Member</strong>
   </td>
   <td>
    <strong>Function name </strong>
   </td>
   <td>
    <strong>Function description</strong>
   </td>
  </tr>
  <tr>
   <td>
   </td>
   <td>
   </td>
   <td>
    parameters in variable memory so that the other display functions  may re-display the information. 
<p>

   8) It is desirable that for position values less than 3 digits (e.g. 1  through 99) that the value be displayed right-justified with the  least significant digit always being in column 7/13 preceded by  leading zeros or spaces.
   </td>
  </tr>
  <tr>
   <td>
    C – Lucy 
   </td>
   <td>
    fcnFireOnOff 
   </td>
   <td>
    <strong>Parameters passed to </strong>function: (1) an integer containing the  desired brightness of the “Laser” pointer LED ranging from 0 (off)  to 100 (maximum brightness). 
<p>

   <strong>Parameters returned from </strong>function: (0) none. 
<p>

   <strong>NOTES: </strong>
<p>

   1) Use the MEGA’s Pulse Width Modulation capabilities to  modulate the brightness of the LED. 
<p>

   2) Note that the Arduino’s AnalogWrite() function value range is  different than the 0 to 100 range of this function’s input. Therefore  value conversion will be needed. 
<p>

   3) Any parameter passed to the function with a value greater than  100 should be treated as 100, and any value less than zero should  be treated as zero (this is known as “coding for boundary  conditions”).
   </td>
  </tr>
  <tr>
   <td>
    C – Lucy 
   </td>
   <td>
    fcnBuzzerOnOff 
   </td>
   <td>
    <strong>Parameters passed to </strong>function: (1) a Boolean value indicating the  desired state of the Active Buzzer; true for buzzer on, and false for  buzzer off. 
<p>

   <strong>Parameters returned from </strong>function: (0) none.
   </td>
  </tr>
  <tr>
   <td>
    C – Luke 
   </td>
   <td>
    fcnDisplayDist 
   </td>
   <td>
    <strong>Parameters passed to </strong>function: (2) #1 an integer of value 0 to 158 indicating the current distance to target measured in inches. #2 an  integer of value 0 to 158 indicating the previous distance to target (until stored room map memory is implemented, this should be a  value of zero).  
<p>

   <strong>Parameters returned from </strong>function: (1) A Boolean value; true if the  input parameters are both within the range of 0 to 999, otherwise  false. 
<p>

   <strong>NOTES: </strong>
<p>

   1) This function will only write to the bottom line of the 2 x 16 LCD. 2) The display is 16 characters wide. The first 3 columns are  reserved for the PIR sensor status and a delimiting space. The last  two columns are reserved for displaying sector info. 
<p>

   3) The current distance should be displayed in columns 4 through 7  in this format “cDDD” (where “DDD” is the numeric current  distance value) followed by an inch symbol (“) in column 8 followed  by a space in column 9.  
<p>

   4) The previous distance should be displayed in columns 10 through 13 in this format “pDDD” (where “DDD” is the numeric previous distance value followed by a space in column 14 (no inch  symbol for this value). If the previous distance value is zero, this 4  character field should become blank (spaces).
   </td>
  </tr>
</table>



<table>
  <tr>
   <td>
    <strong>Team  </strong>
<p>

   <strong>Member</strong>
   </td>
   <td>
    <strong>Function name </strong>
   </td>
   <td>
    <strong>Function description</strong>
   </td>
  </tr>
  <tr>
   <td>
   </td>
   <td>
   </td>
   <td>
    5) This function will necessitate re-writing information supplied to  other display functions. Therefore, memory written by functions  fcnDisplayPIR and fcnDisplaySectors will need to be included in this  function’s LCD.print() calls. 
<p>

   6) Likewise, this function will need to store it’s distance input  parameters in variable memory so that the other display functions  may re-display the information. 
<p>

   7) It is desirable that for distance values less than 3 digits (e.g. 1  through 99) that the value be displayed right-justified with the  least significant digit always being in column 7/13 preceded by  leading zeros or spaces.
   </td>
  </tr>
  <tr>
   <td>
    C – Luke 
   </td>
   <td>
    fcnDisplayPIR 
   </td>
   <td>
    <strong>Parameters passed to </strong>function: (1) a byte whose least significant 4  bits show the status of the four individual PIR sensors (see  fcnReadPIR for a description of the bit assignments). 
<p>

   <strong>Parameters returned from </strong>function: (0) none. 
<p>

   <strong>NOTES: </strong>
<p>

   1) The first two columns of both LCD lines will be used to display  the state of the four quadrant PIR sensors as follows: * Top line, 1<sup>st </sup>column will display “/” (forward slash) while the NW  (North West) quadrant sensor is active.  
<p>

   * Top line, 2<sup>nd </sup>column will display “\” (back slash) while the NE  quadrant sensor is active.  
<p>

   * Bottom line, 1<sup>st </sup>column will display “\” (back slash) while the SW  quadrant sensor is active.  
<p>

   * Bottom line, 2<sup>nd </sup>column will display “/” (forward slash) while the  SE quadrant sensor is active.  
<p>

   All slash characters will be replaced by spaces for those sensors  who are inactive. 
<p>

   2) This function will necessitate writing to both lines of the LCD  display. Therefore, memory written by functions fcnDisplayXY and  fcnDisplayDist and fcnDisplaySectors will need to be included in  this function’s LCD.print() calls. 
<p>

   3) Likewise, this function will need to store it’s PIR input parameter  in variable memory so that the other display functions may re display the information.
   </td>
  </tr>
  <tr>
   <td>
    C – Luke 
   </td>
   <td>
    fcnDisplaySectors (Phase 1b)
   </td>
   <td>
    <strong>Parameters passed to </strong>function: (2) #1 a byte containing the  horizontal 15 degree sector number 1 through 24. #2 a byte  containing the vertical 15 degree sector number 1 through 12. <strong>Parameters returned from </strong>function: (1) A Boolean value; true if the  parameters passed to the function are between 0 and 99, otherwise false. 
<p>

   <strong>NOTES: </strong>
<p>

   1) The last two columns of both LCD lines will be used to display  the sector numbers: 
<p>

   * Top line, columns 15 & 16 will display the vertical sector number.
   </td>
  </tr>
</table>



<table>
  <tr>
   <td>
    <strong>Team  </strong>
<p>

   <strong>Member</strong>
   </td>
   <td>
    <strong>Function name </strong>
   </td>
   <td>
    <strong>Function description</strong>
   </td>
  </tr>
  <tr>
   <td>
   </td>
   <td>
   </td>
   <td>
    * Bottom line, columns 15 & 16 will display the horizontal sector  number. 
<p>

   2) If either sector value is zero, the associated 2 character field shall  become blank (spaces). 
<p>

   3) This function will necessitate writing to both lines of the LCD  display. Therefore, memory written by functions fcnDisplayXY and  fcnDisplayDist and fcnDisplayPIR will need to be included in this  function’s LCD.print() calls. 
<p>

   4) Likewise, this function will need to store it’s sector number input  parameters in variable memory so that the other display functions  may re-display the information. 
<p>

   5) It is desirable that for single digit values (1 through 9) that the  single digit be displayed in column 16, with column 15 either  showing zero or blank (i.e. right-justified).
   </td>
  </tr>
  <tr>
   <td>
    C – Luke 
   </td>
   <td>
    fcnBuzzerBeep 
   </td>
   <td>
    <strong>Parameters passed to </strong>function: (3) #1 an integer containing the  number of beeps ranging from 1 to 5, #2 an integer containing the  on-duration of beeps in milliseconds from 50 to 1000, #3 an integer  containing the off-duration of the beeps in milliseconds from 50 to  1000. 
<p>

   <strong>Parameters returned from </strong>function: (1) a Boolean value; true if the  input parameters are within range, otherwise false. 
<p>

   <strong>NOTES: </strong>
<p>

   1) If only the Arduino delay() function is used, this function can  consume a considerable amount of time. But this is allowed for  Phase 1a. 
<p>

   2) By using the Arduino millis() function a call to the fcnBuzzerBeep  function can store the input parameters in variable memory to be  used in a “background” routine running in the program’s “loop()” function and still allow other functions to be called while on/off  timing is occurring. This is desirable for Phase 1b. 
<p>

   3) Input values outside of the range specified should be rejected  with no beeps occurring. 
<p>

   4) The function should be coded such that silent gaps only occur  between beeps, and not after the final beep.
   </td>
  </tr>
  <tr>
   <td>
    T – Mr. R 
   </td>
   <td>
    fcnSendToMachin e 
<p>

   (Phase 2)
   </td>
   <td>
    To be defined for a possible future Phase 2
   </td>
  </tr>
  <tr>
   <td>
    T – Mr. R 
   </td>
   <td>
    fcnRcvFromMachi ne 
<p>

   (Phase 2)
   </td>
   <td>
    To be defined for a possible future Phase 2
   </td>
  </tr>
  <tr>
   <td>
    T – Mr. R 
   </td>
   <td>
    fcnSendToUser 
<p>

   (Phase 2)
   </td>
   <td>
    To be defined for a possible future Phase 2
   </td>
  </tr>
  <tr>
   <td>
    T – Mr. R 
   </td>
   <td>
    fcnRcvFromUser (Phase 2)
   </td>
   <td>
    To be defined for a possible future Phase 2
   </td>
  </tr>
</table>



## Project Operation 


### Phase 1 (required) 

For Phase 1, a single MEGA 2560 microcontroller board will control the entire project, and the User I/O  control panel will be attached to the Machine I/O base. Because the user will be positioned behind the  arm, this should limit the horizontal travel of the arm to the forward half of the arc (between -90/270  degrees and +90 degrees). The Function Assignments in the above section may help supplement the  operational description below. At the end of Phase 1, the RangerArm should operate as follows: 


Upon startup… 


• The display should show this text: “CCHS RangerArm”, “Version x” where “x” can be a version  number which increments with each build of the software, or the date of the build. 
• The horizontal position of the arm should move to zero degrees (directly in front of the base). This positioning should be a byproduct of the horizontal calibration (see fcnCalibrateX for  details). 


• The vertical position of the arm should move to 90 degrees (approximately horizontal) After startup… 


• The PIR sensors for each quadrant should be continuously monitored and the on/off activity of  all PIR sensors displayed on the left two character positions of the LCD. Initially only the forward  two quadrants will be used (Phase 1). 


• When motion is detected by any PIR sensor, the Active Buzzer shall briefly sound once for 250  ms for each inactive to active PIR detection transition. 


• When the Joystick is moved left or right, the horizontal position of the arm shall move 15  degrees from its present position (counter-clockwise for left joystick motions, clockwise for right  joystick motions). At the end of the horizontal repositioning, if the joystick is back to it’s X idle  position, horizontal arm movement will cease. Motion will also cease if the arm reaches too far  to the right (90 degrees) or the left (270 degrees). In Phase 1, motion between 91 and 269  degrees should not be allowed. 


• When the Joystick is moved forward or back, the vertical position of the arm shall likewise move  up or down by 15 degrees. At the end of the vertical repositioning, if the joystick is back to it’s Y idle position, vertical arm movement will cease. Motion will also cease if the arm reaches too far  up (vertical or 180 degrees) or down (0 degrees or before colliding into the base). 


• When the user tries to move the arm beyond any of its horizontal or vertical motion limits, the  Active Buzzer shall emit two beeps each of 100 ms in duration with a 100 ms gap in-between. 
• There should be a “dead band” near the spring-return center position of the Joystick such that  when the joystick is close to center (the stick’s potentiometers are near mid-point), this is  considered idle. 


• Each second, the current horizontal and vertical position of the arm should be displayed in the  top line of the LCD. 


• While the arm is stationary, the ultrasonic sensor shall be read each second, and the distance  value displayed on the bottom line of the LCD.


• [As a later enhancement (Phase 1b), an array of 12 elements should store the previously read  distance value for each 15 degree sector of the 180 degree horizontal position, and the bottom  line of the LCD should also show (in addition to the current distance) the last distance read for  the present horizontal sector, along with the sector number (1 through 12).] 


• While the Joystick pushbutton is depressed, the “Laser” (pointer) LED should be on, and the  Active Buzzer sounded (or rapidly beeped) for the duration of the LED on state. 


• [As a later enhancement (Phase 1c), we may allow the user to enable or disable the sounding of  the Buzzer, and store the enable/disable state in the microcontroller’s EEPROM so that the  enable/disable state can be restored upon startup.] 

Below is a sample LCD display screen showing all PIR sensors active, horizontal x position of 123°, vertical  y position of 90°, current distance of 72 inches, previous distance of 123 inches, vertical sector = 1, and  horizontal sector = 6. 


<table>
  <tr>
   <td><p style="text-align: right">
Column > </p>

   </td>
   <td>1 
   </td>
   <td>2 
   </td>
   <td>3 
   </td>
   <td>4 
   </td>
   <td>5 
   </td>
   <td>6 
   </td>
   <td>7 
   </td>
   <td>8 
   </td>
   <td>9 
   </td>
   <td>10 
   </td>
   <td>11 
   </td>
   <td>12 
   </td>
   <td>13 
   </td>
   <td>14 
   </td>
   <td>15 
   </td>
   <td>16
   </td>
  </tr>
  <tr>
   <td><p style="text-align: right">
Top Line </p>

   </td>
   <td>/ 
   </td>
   <td>\ 
   </td>
   <td>
   </td>
   <td>x 
   </td>
   <td>1 
   </td>
   <td>2 
   </td>
   <td>3 
   </td>
   <td>° 
   </td>
   <td>
   </td>
   <td>y 
   </td>
   <td>0 
   </td>
   <td>9 
   </td>
   <td>0 
   </td>
   <td>
   </td>
   <td>0 
   </td>
   <td>1
   </td>
  </tr>
  <tr>
   <td>Bottom Line 
   </td>
   <td>\ 
   </td>
   <td>/ 
   </td>
   <td>
   </td>
   <td>c 
   </td>
   <td>0 
   </td>
   <td>7 
   </td>
   <td>2 
   </td>
   <td>“ 
   </td>
   <td>
   </td>
   <td>p 
   </td>
   <td>1 
   </td>
   <td>2 
   </td>
   <td>3 
   </td>
   <td>
   </td>
   <td>0 
   </td>
   <td>6
   </td>
  </tr>
</table>



### Phase 2 (optional, if time permits) 

For Phase 2, if time permits before the semester ends, the User I/O control panel and the Machine I/O  base will have separate microcontrollers, using RS-485 for two-wire, remote control communications  between them. This should allow the arm’s horizontal position to move a full 360 degrees. Operation of  Phase 2 will be identical with Phase 1 with the following exceptions. 


• All four quadrants of the Machine I/O base should be equipped with a separate PIR sensor. • The stored distance array of Phase 1b should be increased to 24 sectors. 


• [As a later enhancement (Phase 2b), the operation can become autonomous with the arm  automatically rotating to the quadrant with PIR sensor activity, and then doing a “sweep” of  every 15 degree sector to see if the distance reading has significantly changed from the last time,  and if it has, it can automatically fire its “laser” (pointer) LED at the suspected target.] 


• [As a further, later enhancement (Phase 2c), the stored distance array can increase to include  vertical sectors; another 24 array horizontal sector elements for each 15 degree vertical sector.  Because the practical vertical position of the arm ranges from 90/horizontal, to 180/vertical, the  array could increase to 24 horizontal sectors by 6 vertical sectors. Thus the autonomous distance  scan can also include vertical scans, capturing 3D map data of the room.]


## Development Sketch Template 

The teacher/coach will provide a template sketch, CCHS_RangerArm_Sketch_Template.ino that all teams  should use when editing their code. 


## Sketch/Software Build 

**On a weekly basis, no later than Sunday of each week, teams will submit their week’s “sprint” code to  the teacher by email or file sharing**. Monday mornings, before class, the teacher will merge the code  into a common sketch (aka “build”) to facilitate in-class evaluation. Teams should try to resolve any  compiler errors before submitting their code. On-time submissions will avoid a late submission point  deduction. 


## Development Aids 

Development teams may find the following Mega 2560 Kit lessons and associated sketch resources  helpful in developing their code. 


<table>
  <tr>
   <td>
    Team 
   </td>
   <td>
    For This Component 
   </td>
   <td>
    ELEGOO Most Complete Starter Kit Mega  Project Kit Lessons/Sketches.
   </td>
  </tr>
  <tr>
   <td>
    A 
   </td>
   <td>
    Stepper Motor 
   </td>
   <td>
    Lesson 31 (pg 206 to 213/233)
   </td>
  </tr>
  <tr>
   <td>
    A 
   </td>
   <td>
    Photocell 
   </td>
   <td>
    Lesson 26 (pg 175 to 179/233)
   </td>
  </tr>
  <tr>
   <td>
    A 
   </td>
   <td>
    PIR Sensor 
   </td>
   <td>
    Lesson 17 (pg 121 to 130/233)
   </td>
  </tr>
  <tr>
   <td>
    B 
   </td>
   <td>
    Servo Motor 
   </td>
   <td>
    Lesson 9 (pg 76 to 79/233)
   </td>
  </tr>
  <tr>
   <td>
    B 
   </td>
   <td>
    Ultrasonic Sensor 
   </td>
   <td>
    Lesson 10 (pg 80 to 84/233)
   </td>
  </tr>
  <tr>
   <td>
    C 
   </td>
   <td>
    LCD Display 
   </td>
   <td>
    Lesson 22 (pg 152 to 156/233_
   </td>
  </tr>
  <tr>
   <td>
    C 
   </td>
   <td>
    LED 
   </td>
   <td>
    Lessons 3 & 4 (pg 43 to 58/233)
   </td>
  </tr>
  <tr>
   <td>
    C 
   </td>
   <td>
    Active Buzzer 
   </td>
   <td>
    Lesson 6 (pg 64 to 67/233)
   </td>
  </tr>
  <tr>
   <td>A, B & C 
   </td>
   <td>
    Joystick 
   </td>
   <td>
    Lesson 13 (pg 97 to 101/233)
   </td>
  </tr>
  <tr>
   <td>A, B & C 
   </td>
   <td>Serial Monitor (for debug) 
   </td>
   <td>Lessons 1 & 25 (pg 28 to 31 & 169 to 174/233)
   </td>
  </tr>
</table>

The following Arduino web site resources may be useful in providing assistance with the libraries used  and Arduino’s built-in functions:


<table>
  <tr>
   <td colspan="3" >
    <strong>ARDUINO LANGUAGE</strong>
   </td>
  </tr>
  <tr>
   <td>
    Language Reference 
   </td>
   <td>
    https://www.arduino.cc/reference/en/
   </td>
   <td>
   </td>
  </tr>
  <tr>
   <td>
    String() objects 
<p>

   (Useful for formatting text in  Serial.println() and LCD.print()  functions)
   </td>
   <td>
    https://www.arduino.cc/reference/en/language/variables/data types/stringobject/
   </td>
   <td>
   </td>
  </tr>
  <tr>
   <td colspan="3" >
    <strong>ARDUINO OFFICIAL & UNOFFICIAL (User Contributed) LIBRARIES</strong>
   </td>
  </tr>
  <tr>
   <td>
    LiquidCrystal.h library 
   </td>
   <td>
    https://www.arduino.cc/reference/en/libraries/liquidcrystal/
   </td>
   <td>
   </td>
  </tr>
  <tr>
   <td>
    Stepper.h library 
   </td>
   <td>
    https://www.arduino.cc/reference/en/libraries/stepper/
   </td>
   <td>
   </td>
  </tr>
  <tr>
   <td>
    Servo.h library 
   </td>
   <td>
    https://www.arduino.cc/reference/en/libraries/servo/
   </td>
   <td>
   </td>
  </tr>
  <tr>
   <td>
    HC-SR04.h library 
<p>

   (For Ultrasonic Sensor)
   </td>
   <td>
    https://www.arduino.cc/reference/en/libraries/hc-sr04/
   </td>
   <td>
   </td>
  </tr>
</table>



## Debugging 

The Arduino IDE Serial Monitor and the Serial.println() function can be used as a debugging tool. To  handle the scenario where multiple teams are using the Serial Monitor, each team should start each line  of their debugging messages with the string “Tx:” where X is their team letter. To avoid the Serial  Monitor from slowing down code execution, the Serial Monitor baud rate should be set to 38400, both  in the sketch’s Serial.begin() statement, and in the Arduino IDE Serial Monitor.
