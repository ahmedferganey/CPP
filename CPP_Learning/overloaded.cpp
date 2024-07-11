#include <iostream>




/////////////////////////////////////////////////////////////////////////////////////
// Overloaded Functions
// Generic Programming
/////////////////////////////////////////////////////////////////////////////////////
// void print(int);          // print an int
// void print(const char*);  // print a C-style string

// ***

// void print(double);
// void print(long);

// void f() {
//   print(1L);   // print(long)
//   print(1.0);  // print(double)
//   print(1);    // error, ambiguous: print(long(1)) or print(double(1))?
// }

// ***
void print_overloaded(int);
void print_overloaded(const char*);
void print_overloaded(double);
void print_overloaded(long);
void print_overloaded(char);


void h(char c, int i, short s, float f) {
  print_overloaded(c);         // exact match: invoke print(char)
  print_overloaded(i);         // exact match: invoke print(int)
  print_overloaded(s);         // integral promotion: invoke print(int)
  print_overloaded(f);         // float to double promotion: print(double)
  print_overloaded('a');       // exact match: invoke print(char)
  print_overloaded(49);        // exact match: invoke print(int)
  print_overloaded(0);         // exact match: invoke print(int)
  print_overloaded("a");       // exact match: invoke print(const char*)
  print_overloaded(nullptr);   // nullptr_t to const char* promotion: invoke print(cost char*)
}
void f(int);
void g() {
  void f(double);
  f(1);  // call f(double)
}

void f1(char);
void f1(long);
void f2(char*);
void f2(int*);

void k(int i) {
  //f1(i);                     // ambiguous: f1(char) or f1(long)?
  //f2(0);                     // ambiguous: f2(char*) or f2(int*)?
  f2(static_cast<int*>(0));  // OK
}



int main() {


/////////////////////////////////////////////////////////////////////////////////////
// Overloaded Functions
// Generic Programming
/////////////////////////////////////////////////////////////////////////////////////







}
    










