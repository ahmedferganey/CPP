#include <iostream>
#include <string>

/////////////////////////////////////////////////////////////////////////////////////
// Better handling of arrays with structures without-unions.
// From: The C++ Programming Language (4th Edition), Bjarne Stroustrup
/////////////////////////////////////////////////////////////////////////////////////
enum type {str, num};

struct entry {
    char const* name;
    type t;
    char const* s;  // use s if t==str
    int i;          // use i if t==num 
};

void print_entry(entry& p){
    std::cout << p.name << " = ";
    if (p.t == str){
        std::cout << p.s << "\n";
    }
    else{
        std::cout << p.i << "\n";
    }
}

/////////////////////////////////////////////////////////////////////////////////////
// Better handling of arrays with structures with-unions.cc.
// From: The C++ Programming Language (4th Edition), Bjarne Stroustrup
/////////////////////////////////////////////////////////////////////////////////////
enum TypeWithUnion {string, numb};


union user_types_unions
{
    /* data */
    unsigned int reg;
    struct 
    {
        /* data */
        unsigned int TXE : 1;   // Transmit data register empty
        unsigned int TC : 1;    // Transmission complete
        unsigned int RXNE : 1;  // Read data register not empty
        unsigned int ERR : 3;   // Error
        unsigned int : 26;      // Reserved
    }bit_fields;    
};


struct EntryWithUnion {
    char const* name;
    TypeWithUnion t;
    union {
        char const* s;
        int i;
    } value ;   
};

void print_entry_With_Union(EntryWithUnion& p) {
  std::cout << p.name << " = ";

  if (p.t == string) {
    std::cout << p.value.s << "\n";
  } else {
    std::cout << p.value.i << "\n";
  }
}


/////////////////////////////////////////////////////////////////////////////////////
// Better handling of arrays with structures misusing-unions.
// From: The C++ Programming Language (4th Edition), Bjarne Stroustrup
/////////////////////////////////////////////////////////////////////////////////////
union dirty_stuff {
    long int i;
    long int* p;
};



/////////////////////////////////////////////////////////////////////////////////////
// Controlled Unions
// From: The C++ Programming Language (4th Edition), Bjarne Stroustrup
/////////////////////////////////////////////////////////////////////////////////////
class Entry{
     public:
        Entry(){};
        Entry(std::string name, int num) 
              : _name{name}, _type{Tag::number}, _number{num} {};
        Entry(std::string name, std::string str) 
              : _name{name}, _type{Tag::text} 
              {
                new (&_text) std::string{str}; // NOLINT
              };

        ~Entry();                        // non-default destructor
        Entry(const Entry&);             // copy constructor
        Entry& operator=(const Entry&);  // copy assignment constructor
        Entry(Entry&&);                  // move constructor
        Entry& operator=(Entry&&);       // move assignment constructor    


        struct bad_entry {};  // used for exceptions
    

        int Number() const;
        void Number(int);

        std::string Text() const;
        void Text(const std::string&);

    private:
        std::string _name;
        enum class Tag {number, text};
        Tag _type;
        union {
            int _number;
            std::string _text;
        };
};





int main() {

/////////////////////////////////////////////////////////////////////////////////////
// Better handling of arrays with structures without-unions.
// From: The C++ Programming Language (4th Edition), Bjarne Stroustrup
/////////////////////////////////////////////////////////////////////////////////////
    entry entry1{.name = "Car Manufacturer", .t = str, .s = "BMW"};
    entry entry2{.name = "Person Height", .t = num, .i = 185};

    print_entry(entry1);
    print_entry(entry2);


/////////////////////////////////////////////////////////////////////////////////////
// Better handling of arrays with structures with-unions.cc.
// From: The C++ Programming Language (4th Edition), Bjarne Stroustrup
/////////////////////////////////////////////////////////////////////////////////////
    EntryWithUnion entry3{.name = "Car Manufacturer", .t = string, .value = {.s = "VW"}};
    EntryWithUnion entry4{.name = "Person Height", .t = numb, .value = {.i = 185}};  
    print_entry_With_Union(entry3);
    print_entry_With_Union(entry4);


/////////////////////////////////////////////////////////////////////////////////////
// Better handling of arrays with structures misusing-unions.
// From: The C++ Programming Language (4th Edition), Bjarne Stroustrup
/////////////////////////////////////////////////////////////////////////////////////
    long int x{0x10};

    dirty_stuff bad{.p = &x};
    std::cout << "bad.i = " << std::hex << bad.i << std::endl;

    dirty_stuff dangerous{.i = bad.i};
    std::cout << "*dangerous.p = " << *dangerous.p << std::endl;

    // less bad than above is to use explicit type conversion operator "used in Embedded reinterpret_cast"
    auto pointer = reinterpret_cast<long int*>(bad.i);
    std::cout << "*pointer = " << *pointer << std::endl;


/////////////////////////////////////////////////////////////////////////////////////
// Controlled Unions
// From: The C++ Programming Language (4th Edition), Bjarne Stroustrup
/////////////////////////////////////////////////////////////////////////////////////
  //
    Entry entry8{"Temperature", 40};
    Entry entry9{"Car Model", "BMW"};   
    entry8.Number();
    entry9.Text();  
    Entry entry10{entry8};
    entry10 = entry9;


}
    




/////////////////////////////////////////////////////////////////////////////////////
// Controlled Unions
// From: The C++ Programming Language (4th Edition), Bjarne Stroustrup
/////////////////////////////////////////////////////////////////////////////////////
int Entry::Number() const {
  std::cout << "Read number" << std::endl;
  if (_type != Tag::number) throw bad_entry{};
  return _number;  // NOLINT
};

std::string Entry::Text() const {
  std::cout << "Read text" << std::endl;
  if (_type != Tag::text) throw bad_entry{};
  return _text;  // NOLINT
};

void Entry::Number(int num) {
  std::cout << "Write number" << std::endl;
  if (_type == Tag::text) {
    _text.std::string::~string();  // explicitly destroy string //NOLINT
    _type = Tag::number;
  }
  _number = num;  // NOLINT
}

void Entry::Text(const std::string& str) {
  std::cout << "Write text" << std::endl;
  if (_type == Tag::text)
    _text = str;  // NOLINT
  else {
    new (&_text)           // NOLINT
        std::string{str};  // placement new: explicitly construct string
    _type = Tag::text;
  }
}

Entry::Entry(const Entry& source) {
  std::cout << "copy constructor" << std::endl;
  _name = source._name;  // NOLINT
  _type = source._type;  // NOLINT
  if (source._type == Tag::text) {
    new (&_text) std::string{source._text};  // placement new //NOLINT
  } else {
    _number = source._number;  // NOLINT
  }
}

Entry& Entry::operator=(const Entry& source) {
  std::cout << "copy assignment operator" << std::endl;
  _name = source._name;
  if (_type == Tag::text && source._type == Tag::text) {
    _text = source._text;  // usual string assignment //NOLINT
    return *this;
  }

  if (_type == Tag::text) {
    _text.std::string::~string();  // explicit destroy //NOLINT
  }

  switch (source._type) {
    case Tag::number:
      _number = source._number;  // NOLINT
      break;

    case Tag::text:
      new (&_text) std::string{source._text};  // placement new //NOLINT
      _type = source._type;
  }
  return *this;
}

Entry::~Entry() {
  std::cout << "destructor" << std::endl;
  if (_type == Tag::text)
    _text.std::string::~string();  // explicit destroy //NOLINT
}

// TODO: Add move and move assignment constructors




