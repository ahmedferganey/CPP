#include <iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////////////
// References
// From: The C++ Programming Language (4th Edition), Bjarne Stroustrup
///////////////////////////////////////////////////////////////////////////////////////////////////
    /*
        The function void increment(int &aa) { ++aa; } is a simple C++ function designed to 
        increment an integer by one. 
    */
   void increment(int &aa) { ++aa; }
   void f() 
    {
        int x = 1;
        increment(x);  // x=2
    }
    int var =20;

    int &fun1() {return var;}
    /*
        The statement int &fun1() { return var; } defines a function fun1 that returns a reference to an integer.
    */
///////////////////////////////////////////////////////////////////////////////////////////////////




///////////////////////////////////////////////////////////////////////////////////////////////////
// References Rvale ref
// From: The C++ Programming Language (4th Edition), Bjarne Stroustrup
///////////////////////////////////////////////////////////////////////////////////////////////////
    std::string get_long_string()
    {
        return "This function returns very looooong string, which will be expansive "
         "to copy";
    }
///////////////////////////////////////////////////////////////////////////////////////////////////


int main() 
{

///////////////////////////////////////////////////////////////////////////////////////////////////
// References
// From: The C++ Programming Language (4th Edition), Bjarne Stroustrup
///////////////////////////////////////////////////////////////////////////////////////////////////
    int x1 ={10};

    int& x2{x1};
    ++x2;
    std::cout << x2 << std::endl;

    //int &x2;      // error: 'x2' declared as reference but not initialize
    //int &x3{20};  // error: cannot bind non-const lvalue reference of type 'int&'
                  // to an rvalue of type
    const double &cdr{1};  // OK
    fun1() = 10;
///////////////////////////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////////////////////////
// References Rvale ref
// From: The C++ Programming Language (4th Edition), Bjarne Stroustrup
///////////////////////////////////////////////////////////////////////////////////////////////////
    std::string str = get_long_string();
    std::string& r1{str};   // lvalue reference, bind r1 to var (an lvalue)

    // &    lvalue
    // &&   Rvalue


    //std::string& r2{get_long_string()};   // error can not bind lvalue reference, to temporary(rvalue)
    const std::string& r3{get_long_string()};   // // ok: const can bind to rvalue

    /*
        The error and its solution in your examples highlight an important aspect of C++: 
        the binding of references to temporary (rvalue) objects. 
        In C++, an lvalue reference (non-const) cannot bind to a temporary object (rvalue). 
        This is because an lvalue reference expects a named variable (lvalue) that persists 
        beyond the current expression.
        In C++, a const lvalue reference can bind to a temporary object (rvalue). 
        This is because a const reference ensures that the temporary object is not modified 
        and allows the temporary object to be extended to the lifetime of the reference.
    */



  //std::string&& rr1{str};  // error: cannot bind rvalue reference to lvalue
  std::string&& rr2{get_long_string()};        // ok: rvalue reference to rvalue
  const std::string&& rr3{get_long_string()};  // no need to use it





///////////////////////////////////////////////////////////////////////////////////////////////////


}
