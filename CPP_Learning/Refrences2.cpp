#include <iostream>

#include <iostream>
#include <string>
#include <utility>
#include <vector>


template <class T>
void SwapOld(T& a, T& b){
    auto tmp{a};
    a = b;
    b = tmp;
}

/* 
        auto tmp{static_cast<T&&>(a)}; -----> 
                we cast (a) to rvlaue ref and make tmp as ref to the data of (a) then (a) ref to 0 

        this technique enable us execute any code at the same time cause we do not transfer data but
        the transfering only for addreses
*/
template <class T>
void SwapModern(T& a, T& b){
    auto tmp{static_cast<T&&>(a)};
    a = static_cast<T&&>(b);
    b = static_cast<T&&>(tmp);
}


template <class T>
void SwapModernMove(T& a,T& b){
    auto tmp{std::move(a)};
    a = std::move(b); 
    b = std::move(tmp);
}


/////////////////////////////////////////////////////////////////////////
// Swap example using rvalue reference & std::move
/////////////////////////////////////////////////////////////////////////




/////////////////////////////////////////////////////////////////////////

int main() 
{

/////////////////////////////////////////////////////////////////////////
// Swap example using rvalue reference & std::move
/////////////////////////////////////////////////////////////////////////
    std::vector<std::string> vect_str_1{"this is the first  string"}; 
    std::vector<std::string> vect_str_2{"this is the second string"}; 


    // 1-  copy semantic
    std::cout << "      1- copy semantic        " << std::endl;    
    std::cout << "before swap; vect_str_1 addr = " << vect_str_1.data()
              << " & vect_str_2 addr = " <<  vect_str_2.data() << std::endl;

    SwapOld(vect_str_1, vect_str_2);

    std::cout << "after swap; vect_str_1 addr = " << vect_str_1.data()
              << " & vect_str_2 addr = " << vect_str_2.data() << std::endl;   

    std::cout  << "vect_str_1 data = " << vect_str_1[0] << std::endl;
    std::cout  << "vect_str_2 data = " << vect_str_2[0] << std::endl;



    // in move, we will not move the data, we only recall the data named
    // 2- Move Semantics Using static_cast
    std::cout << "      2- Move Semantics Using static_cast        " << std::endl;    
    std::cout << "before swap; vect_str_1 addr = " << vect_str_1.data()
              << " & vect_str_2 addr = " <<  vect_str_2.data() << std::endl;

    SwapModern(vect_str_1, vect_str_2);

    std::cout << "after swap; vect_str_1 addr = " << vect_str_1.data()
              << " & vect_str_2 addr = " << vect_str_2.data() << std::endl;   

    std::cout  << "vect_str_1 data = " << vect_str_1[0] << std::endl;
    std::cout  << "vect_str_2 data = " << vect_str_2[0] << std::endl;    




    // 3- Move Semantics Using std::move
    std::cout << "      3- Move Semantics Using std::move        " << std::endl;    
    std::cout << "before swap; vect_str_1 addr = " << vect_str_1.data()
              << " & vect_str_2 addr = " <<  vect_str_2.data() << std::endl;

    SwapModernMove(vect_str_1, vect_str_2);

    std::cout << "after swap; vect_str_1 addr = " << vect_str_1.data()
              << " & vect_str_2 addr = " << vect_str_2.data() << std::endl;   

    std::cout  << "vect_str_1 data = " << vect_str_1[0] << std::endl;
    std::cout  << "vect_str_2 data = " << vect_str_2[0] << std::endl;




/////////////////////////////////////////////////////////////////////////    


}
