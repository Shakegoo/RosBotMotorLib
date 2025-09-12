#ifndef ROSBOTMOTORM2_H
#define ROSBOTMOTORM2_H

#include <Arduino.h>

class RosBotMotorM2 {
public:
    RosBotMotorM2();          // no arguments, pins hardwired internally

    void setSpeed(int speed); // + forward, - reverse, 0 coast
    void brake();             // actively brake motors

private:
    // Hardwired pins for DRV8833 M2
    const int in1 = 7;
    const int in2 = 8;
    const int in3 = 12;
    const int in4 = 13;

    void writeMotorPins(int in1, int in2, int in3, int in4, int speed);
};

#endif
