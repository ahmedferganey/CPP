#include <iostream>
using namespace std;

struct str {

    double a;
    int b;
};


/////////////////////////////////////////////////////////////////////////////////////
// Using decltype is helpful in generic programming
// Generic Programming

template <typename T, typename U>
auto add(T t, U u) -> decltype(t+u) // suffix return type syntax
{
    return t+u;
}
/////////////////////////////////////////////////////////////////////////////////////



int main() {

    decltype(str::a) x{0};
    decltype(str::b) y{0};

    std::cout << "x type is " << typeid(x).name() << std::endl;

    std::cout << "y type is " << typeid(y).name() << std::endl;


/////////////////////////////////////////////////////////////////////////////////////
// Using decltype is helpful in generic programming

    auto result1{add(4.5,3.5)};
    std::cout << "result1 type is " << typeid(result1).name() << std::endl;

    auto result2{add(5, 5)};
    std::cout << "result2 type is " << typeid(result2).name() << std::endl;
/////////////////////////////////////////////////////////////////////////////////////

}
    










