#ifndef ROSBOTMOTORM1_H
#define ROSBOTMOTORM1_H

#include <Arduino.h>

class RosBotMotorM1 {
public:
    RosBotMotorM1();          // no arguments, pins hardwired internally

    void setSpeed(int speed); // + forward, - reverse, 0 coast
    void brake();             // actively brake motors

private:
    // Hardwired pins for DRV8833 M1
    const int in1 = 5;
    const int in2 = 6;
    const int in3 = 9;
    const int in4 = 10;

    void writeMotorPins(int in1, int in2, int in3, int in4, int speed);
};

#endif
