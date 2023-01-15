// enum Enum1;                     // Illegal in C++03 and C++11; no size is explicitly specified.
enum Enum2 : unsigned int;      // Legal in C++11.
enum class Enum3;               // Legal in C++11, because enum class declarations have a default type of "int".
enum class Enum4: unsigned int; // Legal C++11.

//trying to forward declaration
// enum SomeEnum_e;

// void func(SomeEnum_e* s){
// }

//trying to forward declaration
enum class SomeEnum_e;

void func(SomeEnum_e s){
}

int main(){}