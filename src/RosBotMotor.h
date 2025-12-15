#ifndef ROSBOT_MOTOR_H
#define ROSBOT_MOTOR_H

#include <Arduino.h>

/*
 * Base class: shared DRV8833 tank-side behavior
 * One instance = one driver = two motors (A + B channels)
 */
class RosBotMotorBase {
public:
    // speed: -255 .. +255
    // >0 forward, <0 reverse, 0 coast
    void setSpeed(int speed);
    void brake();

protected:
    // Hardwired pins provided by derived classes
    virtual uint8_t A_PLUS()  const = 0;
    virtual uint8_t A_MINUS() const = 0;
    virtual uint8_t B_PLUS()  const = 0;
    virtual uint8_t B_MINUS() const = 0;

    void initMotorPins();

private:
    void writeMotorPins(int speed);
};

/*
 * M1: LEFT SIDE (two motors, pins 5,6,9,10)
 */
class RosBotMotorM1 : public RosBotMotorBase {
public:
    RosBotMotorM1();

protected:
    uint8_t A_PLUS()  const override { return 5; }
    uint8_t A_MINUS() const override { return 6; }
    uint8_t B_PLUS()  const override { return 9; }
    uint8_t B_MINUS() const override { return 10; }
};

/*
 * M2: RIGHT SIDE (two motors, pins 7,8,12,13)
 */
class RosBotMotorM2 : public RosBotMotorBase {
public:
    RosBotMotorM2();

protected:
    uint8_t A_PLUS()  const override { return 7; }
    uint8_t A_MINUS() const override { return 8; }
    uint8_t B_PLUS()  const override { return 12; }
    uint8_t B_MINUS() const override { return 13; }
};

#endif
