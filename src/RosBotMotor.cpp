#include "RosBotMotor.h"

/* ===== Base class ===== */

void RosBotMotorBase::initMotorPins() {
    pinMode(A_PLUS(),  OUTPUT);
    pinMode(A_MINUS(), OUTPUT);
    pinMode(B_PLUS(),  OUTPUT);
    pinMode(B_MINUS(), OUTPUT);

    setSpeed(0); // coast by default
}

void RosBotMotorBase::writeMotorPins(int speed) {
    speed = constrain(speed, -255, 255);

    if (speed > 0) {
        // Forward: A+ and B+ PWM, A- and B- LOW
        analogWrite(A_PLUS(), speed);
        digitalWrite(A_MINUS(), LOW);

        analogWrite(B_PLUS(), speed);
        digitalWrite(B_MINUS(), LOW);

    } else if (speed < 0) {
        // Reverse: A- and B- PWM, A+ and B+ LOW
        digitalWrite(A_PLUS(), LOW);
        analogWrite(A_MINUS(), -speed);

        digitalWrite(B_PLUS(), LOW);
        analogWrite(B_MINUS(), -speed);

    } else {
        // Coast: all LOW
        digitalWrite(A_PLUS(),  LOW);
        digitalWrite(A_MINUS(), LOW);
        digitalWrite(B_PLUS(),  LOW);
        digitalWrite(B_MINUS(), LOW);
    }
}

void RosBotMotorBase::setSpeed(int speed) {
    writeMotorPins(speed);
}

void RosBotMotorBase::brake() {
    // Active brake: all HIGH
    digitalWrite(A_PLUS(),  HIGH);
    digitalWrite(A_MINUS(), HIGH);
    digitalWrite(B_PLUS(),  HIGH);
    digitalWrite(B_MINUS(), HIGH);
}

/* ===== M1 ===== */

RosBotMotorM1::RosBotMotorM1() {
    initMotorPins();
}

/* ===== M2 ===== */

RosBotMotorM2::RosBotMotorM2() {
    initMotorPins();
}
