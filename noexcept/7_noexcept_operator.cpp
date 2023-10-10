//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//
#include <iostream>
#include <string>

void a() {
    throw std::string("from a");
}

void b(){
    a();
}

void c() noexcept {
    b();
}

int main()
{
    try{
    b(); //will cause runtime error of std::terminate()
    }catch(...){}
    std::cout<<std::boolalpha<<noexcept(c())<<std::endl;    //true
    std::cout<<std::boolalpha<<noexcept(b())<<std::endl;    //false
    std::cout<<std::boolalpha<<noexcept(throw "hello")<<std::endl;    //false
}