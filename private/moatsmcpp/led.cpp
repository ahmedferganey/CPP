#include "led.hpp"
#include <iostream>
led::led()
{
    std::cout << "constructor" << std::endl;

}

//led::led(int pin, int count, bool state)
//{
//    this->pin = pin;
//    this->count = count;
//    this->state = state;
//    std::cout << "paramaters" << ": " << pin << " " << count  << " " << state << std::endl;  
//}
led::led(int pin, int count, bool state) : pin(pin),count(count),state(state)
{

    std::cout << "paramaters" << ": " << pin << " " << count  << " " << state << std::endl;  
}
led::~led()
{
    std::cout << "destructor" << std::endl;

}
void led::print()
{
    std::cout << "mariam" << std::endl;
}
