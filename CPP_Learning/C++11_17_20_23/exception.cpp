#include <iostream>
#include <string>
#include <vector>

#include <cstdio>  // for file operations
#include <stdexcept>  // for std::runtime_error

/////////////////////////////////////////////////////////////////////////////////////
// execeptions
// Generic Programming
/////////////////////////////////////////////////////////////////////////////////////
struct some_error{
    std::string what;
};

int do_task(){
    int result =0;
    if(result){
        return result;
    } else{
        throw some_error{"problem..!"};
    }
}

void taskmaster(){
    try {
        auto result = do_task();
            // use result
    } catch (some_error error){
            // failure to do_task: handle problem
        std::cout << error.what << std::endl;
    }
}


void test(){
    try{
        std::vector<int> vec(-10);
    } catch (std::length_error&){
        std::cerr << "test failed: length error\n" << std::endl;
        throw;  // rethrow
    } catch (std::bad_alloc&){
        std::cerr << "test failed: memory exhaustion\n" << std::endl;
        std::terminate();   // terminate the program
    }
}


// Generic Programming, C++14
template <typename T, typename U>
auto add(T t, U u)  // no need for the suffix return type syntax
{
  return t + u;
}


/////////////////////////////////////////////////////////////////////////////////////
// resource-management
// Generic Programming
/////////////////////////////////////////////////////////////////////////////////////
// void use_file(const char* filename) {
//   std::FILE* file = std::fopen(filename, "r");
//   // use the file
//   std::fclose(file);
// }

// void use_file(const char* filename) {
//   std::FILE* file = std::fopen(filename, "r");
//   try {
//     // use the file
//   } catch (...) {  // catch every possible exception
//     std::fclose(file);
//     throw;
//   }
//   std::fclose(file);
// }

class FileHandler {
    public:
        FileHandler (const char* filename, const char* mode)
                    : file{std::fopen(filename, mode)} {
                        if (file == nullptr) throw std::runtime_error{"can not open file !!"};
                    } 
        // TODO: implement other constructors, e.g. move & copy
        ~FileHandler () {std::fclose(file);}

        operator std::FILE*() {return file;}     // implicit conversion operator


    private:
        std::FILE* file;
            
};

void usefile(const char* filename){
    FileHandler fh{filename, "r"};
    //use the file

    char buf[50];
    while(std::fgets(buf, sizeof buf, fh) != nullptr){
        std::cout << buf;
    }
    std::cout << '\n';
}

/////////////////////////////////////////////////////////////////////////////////////
// finally
// Generic Programming
/////////////////////////////////////////////////////////////////////////////////////
template <typename F>
struct Final
{
    /* data */
    Final(F f) : clean{f} {}
    ~Final(){clean();}

    F clean;
};

template <class F>
Final<F> finally(F f){
    return Final<F>(f);
}

void testfinally(){
    int* p = new int{7};
    auto act1 = finally([&]  {
        delete p;
        std::cout << "Good bye ! \n";
    });
    {
        auto act2 = finally([] {std::cout << "finally! \n";});
    }

}


/////////////////////////////////////////////////////////////////////////////////////
// noexcept
// Generic Programming
/////////////////////////////////////////////////////////////////////////////////////
void noexcept_test() noexcept{
    std::vector<int> vec(-10);
}

void try_test(){
    try{
        noexcept_test();
    }catch (std::length_error&){
        std::cerr << "length error \n";
    }
}






/////////////////////////////////////////////////////////////////////////////////////
// function-try-block
// Generic Programming
/////////////////////////////////////////////////////////////////////////////////////
class MyVector{
    public:
        MyVector(int size) try : _vec(size){
        }catch (std::exception&){
            std::cerr << "exception from MyVector \n";
        }    // implicit "throw;"


    private:
        std::vector<int> _vec;
};

void function_try_block_test() try{
    std::vector<int> vec(-10);
}catch(std::length_error&){
    std::cerr << "length error \n";
}









int main() {
/////////////////////////////////////////////////////////////////////////////////////
// execeptions
// Generic Programming
/////////////////////////////////////////////////////////////////////////////////////
    taskmaster();
    try {
        test();
    } catch (...) {
    } 




/////////////////////////////////////////////////////////////////////////////////////
// resource-management
// Generic Programming
/////////////////////////////////////////////////////////////////////////////////////
    usefile("../CMakeLists.txt");



/////////////////////////////////////////////////////////////////////////////////////
// finally
// Generic Programming
/////////////////////////////////////////////////////////////////////////////////////
    testfinally();






/////////////////////////////////////////////////////////////////////////////////////
// noexcept
// Generic Programming
/////////////////////////////////////////////////////////////////////////////////////
    //try_test();







/////////////////////////////////////////////////////////////////////////////////////
// function-try-block
// Generic Programming
/////////////////////////////////////////////////////////////////////////////////////

    function_try_block_test();

    try {
        MyVector vec{-10};
    } catch (std::exception&) {
        std::cerr << "exception caught from MyVector\n";
    }



}
    










