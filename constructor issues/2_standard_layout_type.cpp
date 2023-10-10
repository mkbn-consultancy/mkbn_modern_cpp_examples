#include <type_traits>
#include <iostream>

//---------- Standard Layout Type ----------//
//example 1:
struct SL
{
   // All members have same access:
   int i;
   int j;
   SL(int a, int b) : i(a), j(b) {} // User-defined constructor OK
};

//example 2: Base has no non-static data members
struct Base_1
{
   void Foo() {}
};

struct Derived_1 : public Base_1
{
   int x;
   int y;
};

//example 3: Not a standard layout type
//Derived is not standard layout because both it (the most derived class) 
//and Base have non-static data members
struct Base_2
{
   int i;
   int j;
};

struct Derived_2 : public Base_2
{
   int x;
   int y;
};

void test_standard_layout(){
    static_assert(std::is_standard_layout<SL>::value == true);
    static_assert(std::is_standard_layout<Derived_1>::value == true);
    static_assert(std::is_standard_layout<Derived_2>::value == false);
}

int main(){
    struct A { int x; };
    A a;

    // "px" is guaranteed to point to a.x
    int *px = (int*) &a;

    // guaranteed to point to a
    A *pa = (A*)px; 
}