#include "RosBotMotorM1.h"
#include "RosBotMotorM2.h"

RosBotMotorM1 MotorRight;  // object for M1 output
RosBotMotorM2 MotorLeft;   // object for M2 output

void setup() {
    // start coasting by default (handled in constructors)
}

void loop() {
    MotorRight.setSpeed(255);  // forward
    MotorLeft.setSpeed(255);   // forward
    delay(1000);

    MotorRight.brake();         // active brake
    MotorLeft.brake();
    delay(1000);

    MotorRight.setSpeed(-255); // reverse
    MotorLeft.setSpeed(-255);
    delay(1000);

    MotorRight.setSpeed(0);    // coast
    MotorLeft.setSpeed(0);
    delay(1000);
}
