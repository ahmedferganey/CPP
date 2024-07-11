
#include <iostream>
#include <utility> // for std::move



/////////////////////////////////////////////////////////////////////////////////////
// Manager object example.
// TODO: implement the remaining constructors according to the rule of five.
/////////////////////////////////////////////////////////////////////////////////////

template <typename T, std::size_t N>
class array {
public:
    T* _data;

    /*
        Your code provides a starting point for implementing an array template class 
        and includes a destructor for cleanup. To fully implement the rule of five 
        (destructor, copy constructor, copy assignment operator, move constructor, 
        and move assignment operator), you need to add the remaining constructors 
        and assignment operators to manage the resources properly.
    */
    
    // Default constructor
    array() : _data(new T[N]) {}

    // Destructor
    ~array() {
        std::cout << "Destructor called" << std::endl;
        delete[] _data;
    }

    // Copy constructor
    array(const array& other) : _data(new T[N]) {
        for (std::size_t i = 0; i < N; ++i) {
            _data[i] = other._data[i];
            std::cout << "copy constructor called number :" << i << "=" << _data[i] << std::endl;
        }
    }

    // Copy assignment operator
    array& operator=(const array& other) {
        if (this != &other) {
            delete[] _data;
            _data = new T[N];
            for (std::size_t i = 0; i < N; ++i) {
                _data[i] = other._data[i];
                std::cout << "copy assignment constructor called number :" << i << "=" << _data[i] << std::endl;

            }
        }
        return *this;
    }

    // Move constructor
    array(array&& other) noexcept : _data(other._data) {
        other._data = nullptr;
    }

    // Move assignment operator
    array& operator=(array&& other) noexcept {
        if (this != &other) {
            delete[] _data;
            _data = other._data;
            other._data = nullptr;
        }
        return *this;
    }

    void* operator new(std::size_t, void* p) { return p; }
};

// Function to demonstrate usage
void f(int n) {
    int* p = new (std::nothrow) int[n]; // allocate n ints on the free store
    if (p == nullptr) {
        // handle allocation error
        std::cerr << "Allocation failed" << std::endl;
        return;
    }
    // ...
    operator delete(p, std::nothrow); // deallocate *p
}

int main() {

/////////////////////////////////////////////////////////////////////////////////////
// Manager object example.
// TODO: implement the remaining constructors according to the rule of five.
/////////////////////////////////////////////////////////////////////////////////////

    array<int, 3> myarray;

    auto p2 = new int[10];
    auto p3 = new (p2) int; // placement new

    // Clean up allocated memory
    delete[] p2;
    operator delete(p3, p2); // placement delete


    /*    
        array& operator=(const array& other) { .... }
    */
    //int arraycopyassigncostructor[5]{1,2,3,4,5};
    array<int, 3> arr1;
    arr1._data[0] = 1;
    arr1._data[1] = 2;
    arr1._data[2] = 3;

    array<int, 3> arr2;
    arr2 = arr1; // Uses copy assignment operator

    std::cout << "arr2: ";
    for (std::size_t i = 0; i < 3; ++i) {
        std::cout << arr2._data[i] << " ";
    }
    std::cout << std::endl;

    return 0;

}







