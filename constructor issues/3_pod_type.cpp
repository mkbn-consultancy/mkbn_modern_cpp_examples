#include <iostream>
#include <type_traits>

//standard layout = 
//  C struct memory layout is the same C++ class layout
//trivial =
//  Object can be initialized staticly (no user defined ctor/dtor/=)
//POD = standard layout + trivial

struct N { // neither trivial nor standard-layout
    int i;
    int j;
    virtual ~N();
};

struct T { // trivial but not standard-layout
    int i;
private:
    int j;
};

struct SL { // standard-layout but not trivial
    int i;
    int j;
    ~SL();
};

struct POD { // both trivial and standard-layout
    int i;
    int j;
};

template <typename T>
void printCategory(){
    std::cout<<"trivial: "<<std::boolalpha<<std::is_trivial_v<T><<std::endl;
    std::cout<<"standard layout: "<<std::boolalpha<<std::is_standard_layout_v<T><<std::endl;
    std::cout<<"POD: "<<std::boolalpha<<std::is_pod<T>::value<<std::endl;
}
int main(){
    std::cout<<"class N: \n";
    printCategory<N>();
    std::cout<<"--------\n";
    std::cout<<"class T: \n";
    printCategory<T>();
    std::cout<<"--------\n";
    std::cout<<"class SL:\n";
    printCategory<SL>();
    std::cout<<"--------\n";
    std::cout<<"class POD:\n";
    printCategory<POD>();
}