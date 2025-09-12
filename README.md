Rosbot DRV8833 Hardwired Motor Driver Library

ℹ️ About

This is a simple library for controlling the dual DRV8833 motor drivers on the Kittenbot Rosbot, because driver pins are hardwired and there is lack of documentation on it.
This library is designed to fill the gap for users who need a no-fuss solution for the pre-configured hardware setup on this specific device.
For ease of others who simply want to know the pinouts, M1 is pins 5 & 6, 9 & 10. While M2 is 7 & 8, 12 & 13

🛠️ Installation

Navigate to your Arduino IDE's libraries folder.

Copy this entire library folder into the libraries folder.

Restart the Arduino IDE.



ℹ️ Functions

setSpeed(int speed): Sets the motor speed and direction. Accepts values from -255 (full reverse) to 255 (full forward).

A value of 0 allow coasting.

stop(): Immediately stops the motor.



💻 Usage

The library simplifies controlling the two motors. The hardwired pins are abstracted away, so you only need to call simple functions.

Example:

#include "RosBotMotorM1.h"

\#include "RosBotMotorM2.h"



RosBotMotorM1 MotorRight;  // object for M1 output

RosBotMotorM2 MotorLeft;   // object for M2 output



void setup() {

&nbsp;   // start coasting by default (handled in constructors)

}



void loop() {

&nbsp;   MotorRight.setSpeed(255);  // forward

&nbsp;   MotorLeft.setSpeed(255);   // forward

&nbsp;   delay(1000);



&nbsp;   MotorRight.brake();         // active brake

&nbsp;   MotorLeft.brake();

&nbsp;   delay(1000);



&nbsp;   MotorRight.setSpeed(-255); // reverse

&nbsp;   MotorLeft.setSpeed(-255);

&nbsp;   delay(1000);



&nbsp;   MotorRight.setSpeed(0);    // coast

&nbsp;   MotorLeft.setSpeed(0);

&nbsp;   delay(1000);

}



🐞 Issues

This library was created by a single developer to solve the lack of information on Kittenbot's Rosbot board pinouts for one of it's DRV8833 motor driver. If you encounter any bugs or issues, please report them on the GitHub issues page. I will address and fix them as my time allows.



📜 License

This project is for non-commercial use only. It is distributed under the GNU General Public License v3.0, with the explicit restriction that no commercial application or redistribution is permitted.

📞 Contact

Email: g-69106811@moe-dl.edu.my


