#include <type_traits>
#include <iostream>

//---------- Trivial Type ----------//

/*Since there are no explicit constructors,
there exists a default constructor*/
struct Trivial_1 {
	int i;

private:
	int j;
};

/* In Trivial2 structure, the presence of the
Trivial2(int a, int b) constructor requires
that you provide a default constructor. For
the type to qualify as trivial, we must
explicitly default that constructor.*/
struct Trivial_2 {
	int i;
	Trivial_2(int a, int b){
		i = a;
	}
	Trivial_2() = default;
};

void test_trivial_type(){
    static_assert(std::is_trivial<Trivial_1>::value, "Trivial_1 should be trivial");
    //if we will comment out the default ctor from Trivial_2, it won't be trivial anymore!    
    static_assert(std::is_trivial<Trivial_2>::value, "Trivial_2 should be trivial");
}

