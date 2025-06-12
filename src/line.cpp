#include <Arduino.h>
#include "line.h"
#include "driver.h"

LineFollower::LineFollower(uint8_t ir1, uint8_t ir2,
                           uint8_t in1, uint8_t in2, uint8_t in3, uint8_t in4,
                           uint8_t ena, uint8_t enb, int speed,
                           unsigned long lturnDelay, unsigned long rturnDelay)
    : ir1Pinm(ir1), ir2Pin(ir2), in1(in1), in2(in2), in3(in3), in4(in4),
      ena(ena), enb(enb), speed(speed), lturnDelay(lturnDelay), rturnDelay(rturnDelay),
      motorDriver(in1, in2, in3, in4, ena, enb, speed, speed, true, true) {};

void LineFollower::begin()
{
    pinMode(ir1Pinm, INPUT);
    pinMode(ir2Pin, INPUT);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
    pinMode(ena, OUTPUT);
    pinMode(enb, OUTPUT);

    motorDriver.begin();
}

void LineFollower::followLine()
{
    int ir1State = digitalRead(ir1Pinm);
    int ir2State = digitalRead(ir2Pin);

    if (ir1State == LOW && ir2State == LOW)
    {
        motorDriver.setMotor(speed, speed, true, true); // Move forward
    }
    else if (ir1State == HIGH && ir2State == LOW)
    {
        motorDriver.turnLeft(); // Turn left
    }
    else if (ir1State == LOW && ir2State == HIGH)
    {
        motorDriver.turnRight(); // Turn right
    }
    else
    {
        motorDriver.stop(); // Stop if both sensors are off the line
    }
}
void LineFollower::setTurnDelays(unsigned long leftDelay, unsigned long rightDelay)
{
    lturnDelay = leftDelay;
    rturnDelay = rightDelay;
}