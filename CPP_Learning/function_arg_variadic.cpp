#include <iostream>




/////////////////////////////////////////////////////////////////////////////////////
// Variadic Template
// Generic Programming
/////////////////////////////////////////////////////////////////////////////////////
void my_printf(const char* string) { std::cout << string; }

template <typename T, typename... Targs>
void my_printf(const char* string, T value, Targs... Fargs){
    for(;*string != '\0'; string++){
        if (*string == '%' && *++string != '%'){
            std::cout << value;
            my_printf(++string, Fargs...);
            return;
        }
        std::cout << *string;
    }
}

/////////////////////////////////////////////////////////////////////////////////////
// default arguments
// Generic Programming
/////////////////////////////////////////////////////////////////////////////////////
// class user {
//  public:
//   user(std::string name) : _name(name), _age(0) {}
//   user(std::string name, int age) : _name(name), _age(age) {}

//  private:
//   std::string _name;
//   int _age;
// };

// class user {
//  public:
//   user(std::string name) : user(name, 0) {}
//   user(std::string name, int age) : _name(name), _age(age) {}

//  private:
//   std::string _name;
//   int _age;
// };

class user {
    public:
        user(std::string name, int age = {}) : _name(name), _age(age){
            std::cout << "user_2 called via constructor: 1-name: " << _name << "    2-age: " << _age << std::endl;
            std::cout << "user_1 called via constructor: 1-name: " << _name << "    2-age: " << _age << std::endl;        
        }
    
    private:
        std::string _name;
        int _age;
};


int var{5};
// void fun1(int x, int y = var, int z);    // ERROR: default only for trailing
void fun1(int x, int y = var);              //OK
// args
void fun1(int x =0, int y){}                //// OK: default for y supplied in the same scope
// void fun1(int x = 5, int y);    // ERROR: redefinition of default argument


void fun2 (){
    var =10;
    fun1();     // fun1(0, 10)
}

int main() {


/////////////////////////////////////////////////////////////////////////////////////
// Variadic Template
// Generic Programming
/////////////////////////////////////////////////////////////////////////////////////
  auto x = 7.3;
  auto y = "Hello";
  auto z = 5; 
  my_printf("Value of x = %d and y = %d\n", x, y);

  my_printf("Value of x = %d and y = %d and z = %d\n", x, y,z);



/////////////////////////////////////////////////////////////////////////////////////
// default arguments
// Generic Programming
/////////////////////////////////////////////////////////////////////////////////////
    user user_1 {"ahmed"}; 
    user user_2 {"Tamer", 30}; 



}
    










