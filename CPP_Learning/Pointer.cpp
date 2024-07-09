#include <iostream>
using namespace std;




int multiply (int* x, int* y){return *x * *y;};


int main() 
{
////////////////////////////////////////////////////////////////////////////////
// Pointers
// From: The C++ Programming Language (4th Edition), Bjarne Stroustrup
////////////////////////////////////////////////////////////////////////////////

    int a1{10};
    int* a2{&a1};     // pointer to a1.
    int** a3{&a2};      // addresss of the addres og a2
    int a4{*a2};      // getting int value a2 points to.

    int** a6;        // pointer to pointer
    int* a5[10];     // pointer to an array with 10 ints    ""an array of 10 pointers to int.""

    // pointer to function multiply
    int (* f1)(int* ,int* ) {multiply};

    // std::cout << "an(1,2,3,4,5,6) is " << a1 a2 a3 a4 a5 a6 << std::endl;

    // Print values and addresses
    std::cout << "a1: " << a1 << std::endl;
    std::cout << "a2: " << a2 << " (address of a1: " << &a1 << ")" << std::endl;
    std::cout << "a3: " << a3 << " (address of a2: " << &a2 << ")" << std::endl;
    std::cout << "a4: " << a4 << " (value pointed to by a2: " << *a2 << ")" << std::endl;
    std::cout << "a5: " << a5 << " (uninitialized array of 10 pointers to ints)" << std::endl;
    std::cout << "a6: " << a6 << " (uninitialized pointer to pointer to int)" << std::endl;


////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
// void* Example
// From: The C++ Programming Language (4th Edition), Bjarne Stroustrup
////////////////////////////////////////////////////////////////////////////////
    int value = 10;
    //int* pi;
    int* pi = &value;  // pi is a pointer to an int
    void* pv = pi;  // ok: implicit conversion of int* to void* , now pointing to the same int
    // pv is a void*, a generic pointer that can point to any data type.
    //


    // error: ISO C++ does not allow
    // indirection on operand of type 'void *'  "error: 'void*' is not a pointer-to-object type"
            //*pv;    
    // error: expression must be a pointer
    // to a complete object type "ISO C++ forbids incrementing a pointer of type 'void*'"
            //++pv;



    int* pi2 = static_cast<int*>(pv);    // explicit conversion back to int*
    std::cout << "pi2 points to value: " << *pi2 << std::endl;

    // pv is a void*, which cannot be directly dereferenced because it has no type information.
    // static_cast<int*>(pv) casts the void* back to an int*.
    // pi2 is declared as an int* and initialized with the result of the cast.
    double* pd1 = static_cast<double*>(pv);                        // error

    //double* pd2 = pv;                        // error
    //double* pd3 = pi;                        // error
    double* pd4 = static_cast<double*>(pv);  // unsafe
////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////
// null pointer
////////////////////////////////////////////////////////////////////////////////
    int* n1;

    // using null pointer is more readable
    int* n2 = nullptr;
    void* n3 = nullptr;
    /* 
    The statement void* n3 = nullptr; declares a void pointer named n3 and 
    initializes it to nullptr, indicating that it does not point to any valid 
    memory location. This is a type-safe and clear way to represent a null pointer 
    in modern C++ code. 
    */

    int* n4 = 0;     // Old
    int* n5 = NULL;  // Old, taken from C

    std::cout << n1 << std::endl;
    std::cout << n2 << std::endl;
    std::cout << n4 << std::endl;
    std::cout << n5 << std::endl;

    if (n4 == nullptr) {
      std::cout << "n4 is a null pointer\n";
    }
////////////////////////////////////////////////////////////////////////////////




}
