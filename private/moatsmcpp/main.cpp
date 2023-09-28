#include <iostream>
#include "led.hpp"

int main (){

    //led ledgreen;
    //ledgreen.print();
    led ledred(13,3,false);
    ledred.print();
    std::cout << "finish" << std::endl;  

}