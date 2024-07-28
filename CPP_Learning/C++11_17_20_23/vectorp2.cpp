// Vector Example
// Source: The C++ Programming Language (4th Edition), Bjarne Stroustrup

#include <iterator>


// Vector Example
// Source: The C++ Programming Language (4th Edition), Bjarne Stroustrup

//  ________
// |        | (elem) start of elements space - start of allocation space
// |        |
// |________| (space) end of elements space - start of extra space
// |        |
// |________| (last) end of extra space - end of allocation space

#include <memory>

template <class T, class A = std::allocator<T>>
class vector {
 public:
  using size_type = unsigned int;  // type used for vector sizes

  explicit vector(size_type n, const T& val = T(), const A& = A());
  vector(const vector& a);             // copy constructor
  vector& operator=(const vector& a);  // copy assignment
  vector(vector&& a);                  // move constructor
  vector& operator=(vector&& a);       // move assignment
  ~vector();

  size_type size() const { return _space - _elem; }
  size_type capacity() const { return _last - _elem; }
  void reserve(size_type n);                // increase capacity to n
  void resize(size_type n, const T& = {});  // increase size to n
  void push_back(const T&);                 // add an element at the end

  // TODO: Iterators

 private:
  T* _elem;   // start of allocation
  T* _space;  // end of element sequence, start of space allocated for possible
              // expansion
  T* _last;   // end of allocated space
  A _alloc;   // allocator
};



template <class T, class A>
vector<T, A>::vector(size_type n, const T& val, const A& a) : _alloc{a} {
  _elem = _alloc.allocate(n);  // get memory for elements

  std::iterator p = _elem;

  try {
    std::iterator end = _elem + n;
    for (; p != end; ++p) _alloc.construct(p, val);  // construct
    _last = _space = p;

  } catch (...) {
    for (std::iterator q = _elem; q != p; ++q)
      _alloc.destroy(q);  // destroy constructed elements

    _alloc.deallocate(_elem, n);  // free memory
    throw;                        // rethrow
  }
}

template <class For, class T>
void uninitialized_fill(For beg, For end, const T& x) {
  For p;
  try {
    for (p = beg; p != end; ++p)
      ::new (static_cast<void*>(&*p)) T(x);  // construct copy of x in *p
  } catch (...) {
    for (For q = beg; q != p; ++q) (&*q)->~T();  // destroy element
    throw;                                       // rethrow
  }
}

int main() {
  //
}