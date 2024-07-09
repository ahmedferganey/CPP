#include <iostream>
using namespace std;


int main() 
{
////////////////////////////////////////////////////////////////////////////////
// const pointer
////////////////////////////////////////////////////////////////////////////////
    int x = 10;
    const int* p1;             // pointer to constant
    int* const p2 = &x;        // constant pointer
    const int* const p3 = &x;  // constant pointer to constant

    p1 = &x;   // ok
   // *p1 = 20;  // error
   // p2 = &x;   // error
    *p2 = 10;

    const int y = 0;
    const int* const p4 = &y;  // error: object is const
    // int* const p3 = &y;  // error: object is const
    std::cout << p4 << "    " << "and:    "<< &y << std::endl;


}
