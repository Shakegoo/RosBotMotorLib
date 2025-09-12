#include "RosBotMotorM2.h"

RosBotMotorM2::RosBotMotorM2() {
    // Initialize pins for M2
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);

    // Start coasting
    setSpeed(0);
}

void RosBotMotorM2::writeMotorPins(int in1, int in2, int in3, int in4, int speed) {
    if (speed > 0) {
        digitalWrite(in1, HIGH); digitalWrite(in2, LOW);
        digitalWrite(in3, HIGH); digitalWrite(in4, LOW);
    } else if (speed < 0) {
        digitalWrite(in1, LOW); digitalWrite(in2, HIGH);
        digitalWrite(in3, LOW); digitalWrite(in4, HIGH);
    } else { // speed == 0 → coast
        digitalWrite(in1, LOW); digitalWrite(in2, LOW);
        digitalWrite(in3, LOW); digitalWrite(in4, LOW);
    }
}

void RosBotMotorM2::setSpeed(int speed) {
    writeMotorPins(in1, in2, in3, in4, speed);
}

void RosBotMotorM2::brake() {
    digitalWrite(in1, HIGH); digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH); digitalWrite(in4, HIGH);
}
