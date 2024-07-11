#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

/////////////////////////////////////////////////////////////////////////////////////
// using-lambda app-1
//
/////////////////////////////////////////////////////////////////////////////////////
template <class T, class F>
void operation(T first, T last, F op) {
  for (auto it = first; it != last; it++) {
    op(*it);
  }
}




/////////////////////////////////////////////////////////////////////////////////////
// using-lambda app-2
//
/////////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////////////
// using-lambda app-3
//
/////////////////////////////////////////////////////////////////////////////////////




int main() {
/////////////////////////////////////////////////////////////////////////////////////
// using-lambda app-1
//
/////////////////////////////////////////////////////////////////////////////////////

  std::vector<int> numbers{10, 20, 30, 40, 50};

  operation(numbers.begin(), numbers.end(), [](int& number) { number++; });

  class increment {
   public:
    void operator()(int& number) const { number++; }
  };
  operation(numbers.begin(), numbers.end(), increment{});


  operation(numbers.begin(), numbers.end(),
            [](int number) { std::cout << number << "\n"; });


/////////////////////////////////////////////////////////////////////////////////////
// using-lambda app-2
//
/////////////////////////////////////////////////////////////////////////////////////
    int max = 0;
    int min = std::numeric_limits<int>::max();
    int sum = 0;

    // Iterate through the vector to calculate max, min, and sum
    for (int num : numbers) {
        if (num > max) {
            max = num;
        }
        if (num < min) {
            min = num;
        }
        sum += num;
    }

    std::cout << "Maximum: " << max << std::endl;
    std::cout << "Minimum: " << min << std::endl;
    std::cout << "Sum: " << sum << std::endl;

/////////////////////////////////////////////////////////////////////////////////////
// using-lambda app-3
//
/////////////////////////////////////////////////////////////////////////////////////
    auto minmaxsum = [&max, &min, sum](int number) mutable -> int {
        sum += number;
        if (number > max) max = number;
        if (number < min) min = number;
        std::cout << sum << "\n";
        return sum;
      };
    std::for_each(numbers.begin(), numbers.end(), minmaxsum);
    std::cout << "Min = " << min << " Max = " << max << " Sum = " << sum << "\n";





}
    










