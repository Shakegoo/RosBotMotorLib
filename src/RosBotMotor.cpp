#include "RosBotMotor.h"

/* ===== RosBotMotorBase ===== */

void RosBotMotorBase::initMotorPins() {
    pinMode(IN1(), OUTPUT);
    pinMode(IN2(), OUTPUT);
    pinMode(IN3(), OUTPUT);
    pinMode(IN4(), OUTPUT);

    setSpeed(0); // coast by default
}

void RosBotMotorBase::writeMotorPins(int speed) {
    speed = constrain(speed, -255, 255);

    if (speed > 0) {
        analogWrite(IN1(), speed);
        digitalWrite(IN2(), LOW);

        analogWrite(IN3(), speed);
        digitalWrite(IN4(), LOW);

    } else if (speed < 0) {
        analogWrite(IN1(), -speed);
        digitalWrite(IN2(), HIGH);

        analogWrite(IN3(), -speed);
        digitalWrite(IN4(), HIGH);

    } else {
        // coast
        digitalWrite(IN1(), LOW);
        digitalWrite(IN2(), LOW);
        digitalWrite(IN3(), LOW);
        digitalWrite(IN4(), LOW);
    }
}

void RosBotMotorBase::setSpeed(int speed) {
    writeMotorPins(speed);
}

void RosBotMotorBase::brake() {
    digitalWrite(IN1(), HIGH);
    digitalWrite(IN2(), HIGH);
    digitalWrite(IN3(), HIGH);
    digitalWrite(IN4(), HIGH);
}

/* ===== M1 ===== */

RosBotMotorM1::RosBotMotorM1() {
    initMotorPins();
}

/* ===== M2 ===== */

RosBotMotorM2::RosBotMotorM2() {
    initMotorPins();
}
