#ifndef LINE_H
#define LINE_H
#include <Arduino.h>
#include "driver.h"

class LineFollower
{
private:
    uint8_t ir1Pinm, ir2Pin;
    uint8_t in1, in2, in3, in4, ena, enb;
    int speed;
    unsigned long lturnDelay, rturnDelay;

    MotorDriver motorDriver; // Add this line

public:
    LineFollower(uint8_t ir1, uint8_t ir2,
                 uint8_t in1, uint8_t in2, uint8_t in3, uint8_t in4,
                 uint8_t ena, uint8_t enb, int speed = 200,
                 unsigned long lturnDelay = 500, unsigned long rturnDelay = 500);
    void begin();
    void followLine();
    void setTurnDelays(unsigned long leftDelay, unsigned long rightDelay);
};
#endif