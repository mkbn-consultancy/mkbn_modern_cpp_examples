#include <functional>
#include <iostream>

int add(int first, int second)
{
    return first + second;
}

int main(){
    auto f = std::function<int(int,int)>{add};
    std::cout<<f(4,5)<<std::endl;

    auto f2 = std::bind(&add,4,5);
    std::cout<<f2()<<std::endl;

    auto add_func = std::bind(&add, 4, 5);
    std::cout<<"result = "<<add_func()<<std::endl;
}
