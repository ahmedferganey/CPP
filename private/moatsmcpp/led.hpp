#ifndef LED_H
#define LED_H

#pragma once

class led
{
private:
    int pin = 15;
    int count = 0;
    bool state = false;
public:
    void print();
    led();
    led(int pin, int count, bool state);
    ~led();


};

#endif
