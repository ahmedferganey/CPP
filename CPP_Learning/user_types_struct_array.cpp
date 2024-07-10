#include <iostream>
#include <string>
#include <cstring>


/////////////////////////////////////////////////////////////////////////////////////
// Structures-1
// From: The C++ Programming Language (4th Edition), Bjarne Stroustrup
/////////////////////////////////////////////////////////////////////////////////////
struct Address {
  const char* name;
  int number;
  const char* street;
  const char* town;
  char state[2];
  const char* zip;
};

void print_addr_1(Address* p){
    std::cout << p->name << '\n'
              << p->number << ' ' << p->street << '\n'
              << p->town << '\n'
              << p->state[0] << p->state[1] << ' ' << p->zip << '\n';

}
void print_addr_2(const Address& r){
    std::cout << r.name << '\n'
              << r.number << ' ' << r.street << '\n'
              << r.town << '\n'
              << r.state[0] << r.state[1] << ' ' << r.zip << '\n';
}

/////////////////////////////////////////////////////////////////////////////////////
// Structures-2
// From: The C++ Programming Language (4th Edition), Bjarne Stroustrup
/////////////////////////////////////////////////////////////////////////////////////
constexpr size_t buffer_size = 14;

struct data {
    char buffer[buffer_size];
};


/////////////////////////////////////////////////////////////////////////////////////
// Structures-3
// From: The C++ Programming Language (4th Edition), Bjarne Stroustrup
/////////////////////////////////////////////////////////////////////////////////////
struct addr{
    public:
      addr(const std::string n, int nu, const std::string& s,
          const std::string& t, const std::string& st)
      : _name(n), _number(nu), _street(s), _town(t), _state(st){};        
      void print() const;

    private:
        std::string _name;
        int _number;
        std::string _street;
        std::string _town;
        std::string _state;
};  


void addr::print() const {
  std::cout << _name << '\n'
            << _number << ' ' << _street << '\n'
            << _town << '\n'
            << _state << '\n';
}

/////////////////////////////////////////////////////////////////////////////////////
// Structures-4 "struct-fields"
// From: The C++ Programming Language (4th Edition), Bjarne Stroustrup
/////////////////////////////////////////////////////////////////////////////////////
struct Status
{
    /* data */
  unsigned int TXE : 1;   // Transmit data register empty
  unsigned int TC : 1;    // Transmission complete
  unsigned int RXNE : 1;  // Read data register not empty
  unsigned int ERR : 3;   // Error
  unsigned int : 26;      // Reserved

};

struct Data
{
    /* data */
  unsigned int DATA : 8;  // Data
  unsigned int : 24;      // Reserved

};

struct Uart {
  Status SR;  // Status register
  Data DR;    // Data register
};


/////////////////////////////////////////////////////////////////////////////////////
// Structures-5 "Better handling of arrays with structures"
// From: The C++ Programming Language (4th Edition), Bjarne Stroustrup
/////////////////////////////////////////////////////////////////////////////////////
struct  point
{
    /* data */
    int x,y;
};

std::ostream& operator<<(std::ostream& os, point& p){
    std::cout << "{" << p.x << "," << p.y << "}";
    return os;
}

template<typename T, std::size_t N>
struct array{
    T elem[N];

    T* begin() noexcept { return elem; }
    const T* begin() const noexcept { return elem; }

    T* end() noexcept { return elem + N; }
    const T* end() const noexcept { return elem + N; }


    constexpr std::size_t size() const noexcept {return N;}

    T& operator[](std::size_t n) { return elem[n]; }
    const T& operator[](std::size_t n) const { return elem[n]; }

    void print(){
        for (int i = 0; i != size(); ++i) std::cout << elem[i] << '\n';
    }

};





int main() {

/////////////////////////////////////////////////////////////////////////////////////
// Structures-1
// From: The C++ Programming Language (4th Edition), Bjarne Stroustrup
/////////////////////////////////////////////////////////////////////////////////////
    Address jd;
    jd.name = "Jim Dandy";
    jd.number = 61;

    Address jd2 = {"Jim Dandy",      61,         "South St",
                   "New Providence", {'N', 'J'}, "07974"};

    Address jd3 = {.name = "Jim Dandy",
                   .number = 61,
                   .street = "South St",
                   .town = "New Providence",
                   .state = {'N', 'J'},
                   .zip = "07974"};

     print_addr_2(jd2);
     print_addr_1(&jd2);


/////////////////////////////////////////////////////////////////////////////////////
// Structures-2
// From: The C++ Programming Language (4th Edition), Bjarne Stroustrup
/////////////////////////////////////////////////////////////////////////////////////
    data output;
    strcpy(output.buffer, "i love mariam");

    //char input_buffer[buffer_size];
    //input_buffer = output.buffer;  // error: array type 'char [10]'
                                 // is not assignable
   
    data input = output;
    std::cout << input.buffer << "\n";

/////////////////////////////////////////////////////////////////////////////////////
// Structures-3
// From: The C++ Programming Language (4th Edition), Bjarne Stroustrup
/////////////////////////////////////////////////////////////////////////////////////
  addr fg{"Jim Dandy", 61, "South St", "New Providence", "NJ"};
  fg.print();



/////////////////////////////////////////////////////////////////////////////////////
// Structures-4 "struct-fields"
// From: The C++ Programming Language (4th Edition), Bjarne Stroustrup
/////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////
// Structures-5 "Better handling of arrays with structures"
// From: The C++ Programming Language (4th Edition), Bjarne Stroustrup
/////////////////////////////////////////////////////////////////////////////////////
    array<int, 3> arr1{1,2,3};

    for (auto it = arr1.begin(); it != arr1.end(); ++it){
        std::cout << *it << std::endl;
    }


    
    array<point, 3> arr2{point{1, 2}, point{3, 4}, point{5, 6}};
    arr2.print();
}
    










