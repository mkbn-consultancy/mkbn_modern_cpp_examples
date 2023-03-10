//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//
#include <iostream>

class Example{
public:
    Example() : _var{10} {}
    void func()
    {
        int x = 0;
        [=]() { std::cout << "inside [=]: " << _var << x << std::endl; }();
        [&]() { std::cout << "inside [&]: " << _var << std::endl; }(); 
        [this]() {std::cout<< "inside [this]: " << _var <<std::endl; someFunc();}();
        // [tmp = *this]() {std::cout<<"inside [temp=*this]: " << tmp._var <<std::endl; }(); //C++14
        // [*this]() mutable { ++_var; 
        //                     std::cout<< "inside [*this]: " << _var <<std::endl; 
        //                   }();  //C++17
    }
    void someFunc() {_var++;}
public:
    int _var;
};

int main()
{
    Example e;
    e.func();
    std::cout<<e._var<<std::endl;
}
