// Using auto for automatic type deduction
// Using auto is helpful with hard to find out types



#include <iostream>
#include <typeinfo> // for typeid
#include <vector>
using namespace std;


///////////////////////////////////////////////////////////////////////////////////
typedef unsigned int* Puint32_t; // old
using Pint32_t = unsigned int*;  // c++ type alias
///////////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////////

// Non-template function
void f1_non_template(std::vector<int>& arg) {
    for (std::vector<int>::iterator p = arg.begin(); p != arg.end(); ++p)
        *p = 7;
}

// Template function
template <class T>
void f1_template(std::vector<T>& arg) {
    for (typename std::vector<T>::iterator p = arg.begin(); p != arg.end(); ++p)
        *p = 7;
}
///////////////////////////////////////////////////////////////////////////////////

int main() 
{

///////////////////////////////////////////////////////////////////////////////////    
// Using auto for automatic type deduction
    
    int a1 {123};
    char a2 = 123;

    auto a3 = 123; // the type of a3 is int
        // auto a4;        // error: declaration of 'auto a4' has no initializer
    auto a5{123};

    std::cout << "a3 type is : " << typeid(a3).name() << std::endl;
    std::cout << "a3 type is : " << typeid(a5).name() << std::endl;

    auto x1 = {1,2,3};  // x1 type is std::initializer_list<int>
    int x2 = {2};       // x2 type is is std::initializer_list<int>


        // auto x3 = {1, 2.0};  // error: cannot deduce element type
        // auto x4{1, 2};       // error: not a single element    

    auto x5{3};


    std::cout << "x1 type is " << typeid(x1).name() << std::endl;
    std::cout << "x2 type is " << typeid(x2).name() << std::endl;
    std::cout << "x5 type is " << typeid(x5).name() << std::endl;
///////////////////////////////////////////////////////////////////////////////////    
// Using auto is helpful with hard to find out types


    std::vector<int> vec_int = {1, 2, 3, 4, 5};
    std::vector<double> vec_double = {1.1, 2.2, 3.3, 4.4, 5.5};

    // Using non-template function
    f1_non_template(vec_int);
    // f1_non_template(vec_double);  // Error

    // Using template function with different types
    f1_template(vec_int);
    f1_template(vec_double);




///////////////////////////////////////////////////////////////////////////////////    

}


