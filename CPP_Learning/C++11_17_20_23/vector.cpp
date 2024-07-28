#include <iostream>
#include <string>
#include <vector>
#include <memory>

/*  Important Example  */

/////////////////////////////////////////////////////////////////////////////////////
//  Memorry management using vector class
// Generic Programming
/////////////////////////////////////////////////////////////////////////////////////
// vector_base struct definition remains the same
template <typename T, typename A = std::allocator<T>>
struct vector_base {
  vector_base(const A& a, typename A::size_type n, typename A::size_type m = 0)
      : _alloc{a},
        _elem{_alloc.allocate(n + m)},
        _space{_elem + n},
        _last{_elem + n + m} {}

  ~vector_base() { _alloc.deallocate(_elem, _last - _elem); }

  vector_base(const vector_base&) = delete;
  vector_base& operator=(const vector_base&) = delete;

  vector_base(vector_base&& other) noexcept
      : _alloc{std::move(other._alloc)},
        _elem{other._elem},
        _space{other._space},
        _last{other._last} {
    other._elem = other._space = other._last = nullptr;
  }

  vector_base& operator=(vector_base&& other) noexcept {
    if (this != &other) {
      _alloc.deallocate(_elem, _last - _elem);
      _alloc = std::move(other._alloc);
      _elem = other._elem;
      _space = other._space;
      _last = other._last;
      other._elem = other._space = other._last = nullptr;
    }
    return *this;
  }

  A _alloc;   // allocator
  T* _elem;   // start of allocation
  T* _space;  // end of element sequence, start of space allocated for possible expansion
  T* _last;   // end of allocated space
};

template <typename T, typename A = std::allocator<T>>
class vector {
 public:
  using size_type = typename A::size_type;

  explicit vector(size_type n, const T& val = T{}, const A& alloc = A{});

  vector(const vector& other);             // copy constructor
  vector& operator=(const vector& other);  // copy assignment

  vector(vector&& other) noexcept;             // move constructor
  vector& operator=(vector&& other) noexcept;  // move assignment

  ~vector() { destroy_elements(); }

  size_type size() const { return _vb._space - _vb._elem; }
  size_type capacity() const { return _vb._last - _vb._elem; }

  void reserve(size_type);                // increase capacity
  void resize(size_type, const T& = {});  // change the number of elements
  void clear() { resize(0); }             // make the vector empty
  void push_back(const T&);               // add an element at the end

  T& operator[](size_type i) { return _vb._elem[i]; }  // element access
  const T& operator[](size_type i) const { return _vb._elem[i]; }  // const element access

  // TODO: Iterators

 private:
  vector_base<T, A> _vb;
  void destroy_elements();
};

template <class T, class A>
vector<T, A>::vector(size_type n, const T& val, const A& a)
    : _vb{a, n} {
  for (T* p = _vb._elem; p != _vb._space; ++p)
    std::allocator_traits<A>::construct(_vb._alloc, p, val);
}

template <class T, class A>
vector<T, A>::vector(const vector& other)
    : _vb{std::allocator_traits<A>::select_on_container_copy_construction(other._vb._alloc), other.size()} {
  std::uninitialized_copy(other._vb._elem, other._vb._space, _vb._elem);
}

template <class T, class A>
vector<T, A>& vector<T, A>::operator=(const vector& other) {
  if (this != &other) {
    vector tmp(other);
    std::swap(*this, tmp);
  }
  return *this;
}

template <class T, class A>
vector<T, A>::vector(vector&& other) noexcept
    : _vb{std::move(other._vb)} {}

template <class T, class A>
vector<T, A>& vector<T, A>::operator=(vector&& other) noexcept {
  if (this != &other) {
    _vb = std::move(other._vb);
  }
  return *this;
}

template <class T, class A>
void vector<T, A>::destroy_elements() {
  for (T* p = _vb._elem; p != _vb._space; ++p)
    std::allocator_traits<A>::destroy(_vb._alloc, p);
}

template <class T, class A>
void vector<T, A>::reserve(size_type n) {
  if (n > capacity()) {
    vector_base<T, A> new_vb{_vb._alloc, size(), n - size()};
    std::uninitialized_move(_vb._elem, _vb._space, new_vb._elem);
    destroy_elements();
    _vb = std::move(new_vb);
  }
}

template <class T, class A>
void vector<T, A>::resize(size_type n, const T& val) {
  if (n > size()) {
    reserve(n);
    for (T* p = _vb._space; p != _vb._elem + n; ++p)
      std::allocator_traits<A>::construct(_vb._alloc, p, val);
  } else {
    for (T* p = _vb._elem + n; p != _vb._space; ++p)
      std::allocator_traits<A>::destroy(_vb._alloc, p);
  }
  _vb._space = _vb._elem + n;
}

template <class T, class A>
void vector<T, A>::push_back(const T& val) {
  if (_vb._space == _vb._last) reserve(size() ? 2 * size() : 1);
  std::allocator_traits<A>::construct(_vb._alloc, _vb._space++, val);
}

int main() {


/////////////////////////////////////////////////////////////////////////////////////
//  Memorry management using vector class
// Generic Programming
/////////////////////////////////////////////////////////////////////////////////////
  vector<int> v(5, 42);  // initialize vector with 5 elements, each of value 42
  v.push_back(84);       // add 84 to the end of the vector

  for (size_t i = 0; i < v.size(); ++i)
    std::cout << v[i] << " ";  // output: 42 42 42 42 42 84

  v.resize(3);  // resize to 3 elements

  for (size_t i = 0; i < v.size(); ++i)
    std::cout << v[i] << " ";  // output: 42 42 42

  return 0;


}
    










