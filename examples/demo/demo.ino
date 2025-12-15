#include <RosBotMotor.h>

// Tank sides
RosBotMotorM1 leftSide;   // M1 = LEFT motors
RosBotMotorM2 rightSide;  // M2 = RIGHT motors

void setup() {
    // Nothing required
}

void loop() {

    // --- LEFT ONLY: forward 2 seconds ---
    leftSide.setSpeed(150);
    rightSide.setSpeed(0);
    delay(2000);

    // Brake
    leftSide.brake();
    delay(1000);


    // --- RIGHT ONLY: forward 2 seconds ---
    leftSide.setSpeed(0);
    rightSide.setSpeed(150);
    delay(2000);

    // Brake
    rightSide.brake();
    delay(1000);


    // --- BOTH: forward 2 seconds ---
    leftSide.setSpeed(150);
    rightSide.setSpeed(150);
    delay(2000);

    // Brake
    leftSide.brake();
    rightSide.brake();
    delay(1000);


    // --- BOTH: reverse 2 seconds ---
    leftSide.setSpeed(-150);
    rightSide.setSpeed(-150);
    delay(2000);


    // --- BOTH: coast ---
    leftSide.setSpeed(0);
    rightSide.setSpeed(0);
    delay(2000);
}
