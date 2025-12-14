#include <RosBotMotor.h>

// Create motor instances
RosBotMotorM1 motorM1;
RosBotMotorM2 motorM2;

void setup() {
    // Nothing needed here
}

void loop() {

    // Forward for 1 second
    motorM1.setSpeed(150);
    motorM2.setSpeed(150);
    delay(1000);

    // Active brake for 1 second
    motorM1.brake();
    motorM2.brake();
    delay(1000);

    // Reverse for 1 second
    motorM1.setSpeed(-150);
    motorM2.setSpeed(-150);
    delay(1000);

    // Coast for 1 second
    motorM1.setSpeed(0);
    motorM2.setSpeed(0);
    delay(1000);

    // Pause before repeating
    delay(1000);
}
