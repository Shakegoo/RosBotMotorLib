#ifndef ROSBOT_MOTOR_H
#define ROSBOT_MOTOR_H

#include <Arduino.h>

/*
 * Base class: shared DRV8833 motor behavior
 */
class RosBotMotorBase {
public:
    // speed: -255 .. +255
    // >0 forward, <0 reverse, 0 coast
    void setSpeed(int speed);
    void brake();

protected:
    // Hardwired pins supplied by derived classes
    virtual uint8_t IN1() const = 0;
    virtual uint8_t IN2() const = 0;
    virtual uint8_t IN3() const = 0;
    virtual uint8_t IN4() const = 0;

    void initMotorPins();

private:
    void writeMotorPins(int speed);
};

/*
 * Motor M1 (DRV8833 chip #1, hardwired pins)
 */
class RosBotMotorM1 : public RosBotMotorBase {
public:
    RosBotMotorM1();

protected:
    uint8_t IN1() const override { return 5; }
    uint8_t IN2() const override { return 6; }
    uint8_t IN3() const override { return 9; }
    uint8_t IN4() const override { return 10; }
};

/*
 * Motor M2 (DRV8833 chip #2, hardwired pins)
 */
class RosBotMotorM2 : public RosBotMotorBase {
public:
    RosBotMotorM2();

protected:
    uint8_t IN1() const override { return 7; }
    uint8_t IN2() const override { return 8; }
    uint8_t IN3() const override { return 11; }
    uint8_t IN4() const override { return 12; }
};

#endif
