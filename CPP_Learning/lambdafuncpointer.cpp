#include <iostream>
#include <vector>

/////////////////////////////////////////////////////////////////////////////////////
//  using-function-pointers
//
/////////////////////////////////////////////////////////////////////////////////////
template <class T>
void increment(T& number){
    number++;
}

template <class T>
void print(T& number){
    std::cout << number << std::endl;
}

template <class it, class T>
void operation(it first, it last, void (*op) (T&) ){
    for(auto iter = first; iter != last; iter++){
        op(*iter);
    }

}

int main() {
/////////////////////////////////////////////////////////////////////////////////////
//  using-function-pointers
//
/////////////////////////////////////////////////////////////////////////////////////
  std::vector<int> numbers{10, 20, 10, 40, 50};
  operation(numbers.begin(), numbers.end(), &increment<int>);
  operation(numbers.begin(), numbers.end(), &print<int>);

}
    










