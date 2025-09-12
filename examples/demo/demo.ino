#include "RosBotMotorM1.h"
#include "RosBotMotorM2.h"

RosBotMotorM1 MotorRight;  // M1 driver
RosBotMotorM2 MotorLeft;   // M2 driver

void setup() {
    Serial.begin(115200);  
    while (!Serial) { ; }  // wait for serial monitor
    Serial.println("Press ENTER to run the motor test...");  // <-- comment out to skip prompt
}

void loop() {
    // If you want automatic loop, comment out the following 4 lines:
    if (Serial.available()) {  
        char c = Serial.read();
        if (c == '\n' || c == '\r') {  // Enter pressed
            Serial.println("Running motor test...");  // <-- optional, comment out for auto-run
        } else return;  // skip rest of loop until Enter pressed
    }

    // Motor test sequence (always runs if above is commented)
    MotorRight.setSpeed(255);  // forward
    MotorLeft.setSpeed(255);
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

    Serial.println("Test complete. Press ENTER to repeat.");  // <-- comment out for auto-run
}
