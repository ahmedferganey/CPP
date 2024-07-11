#include <iostream>

/////////////////////////////////////////////////////////////////////////////////////
// Enumerations
// Reference: The C++ Programming Language (4th Edition), Bjarne Stroustrup
/////////////////////////////////////////////////////////////////////////////////////
enum class Traffic_light {red, yellow, green};
enum class Warning { green, yellow, orange, red };


// Warning a1 = 7;                     // error : no int->Warning conversion
// int a2 = green;                     // error: green not in scope
// int a3 = Warning::green;            // error : no Warning->int conversion
// Warning a4 = Traffic_light::green;  // error : different types
// Warning a5 = Warning::green;        // OK

// enum class Warning : int { green, yellow, orange, red };
// enum class Warning : char { green, yellow, orange, red };

void print_warning_enum(){
    std::cout << static_cast<int> (Warning::green)      << std::endl;
    std::cout << static_cast<int> (Warning::yellow)     << std::endl;
    std::cout << static_cast<int> (Warning::orange)     << std::endl;
    std::cout << static_cast<int> (Warning::red)        << std::endl;    
}

/////////////////////////////////////////////////////////////////////////////////////
// enum-operators
// Reference: The C++ Programming Language (4th Edition), Bjarne Stroustrup
/////////////////////////////////////////////////////////////////////////////////////

enum class StatusFlags{
    data_received       = 0x01,
    rx_buffer_full      = 0x02,
    rx_error            = 0x04,
    data_transmitted    = 0x08,
    tx_buffer_empty     = 0x10,
    tx_error            = 0x20
};


constexpr StatusFlags operator| (StatusFlags a, StatusFlags b){
    return static_cast<StatusFlags>(static_cast<int>(a) | static_cast<int>(b));
}
constexpr StatusFlags operator& (StatusFlags a, StatusFlags b){
    return static_cast<StatusFlags>(static_cast<int>(a) & static_cast<int>(b));
}


void check_status_flags(StatusFlags status){
    
    StatusFlags l_ready_to_read{StatusFlags::data_received | 
                                StatusFlags::rx_buffer_full};
    if((status & l_ready_to_read) == l_ready_to_read){
        std::cout << "Read Data" << std::endl;
    }


    StatusFlags l_ready_to_write{StatusFlags::data_transmitted | 
                                 StatusFlags::tx_buffer_empty};
    if((status & l_ready_to_write) == l_ready_to_write){
       std::cout << "Write Data" << std::endl;
    }

    StatusFlags any_error {StatusFlags::rx_error | StatusFlags::tx_error};
    StatusFlags no_error  {static_cast<StatusFlags>(0)};
    if((status & any_error) != any_error){
        std::cout << "RX and/or TX Error" << std::endl;
    }
}


int main() {

/////////////////////////////////////////////////////////////////////////////////////
// Enumerations
// Reference: The C++ Programming Language (4th Edition), Bjarne Stroustrup
/////////////////////////////////////////////////////////////////////////////////////
    print_warning_enum();



/////////////////////////////////////////////////////////////////////////////////////
// Enumerations
// Reference: The C++ Programming Language (4th Edition), Bjarne Stroustrup
/////////////////////////////////////////////////////////////////////////////////////
    StatusFlags status{static_cast<StatusFlags>(0x3F)};
    check_status_flags(status);

    std::cout << (StatusFlags::rx_error < StatusFlags::tx_error) << std::endl;


}
    










