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

    using namespace std::placeholders;  // for _1, _2, _3...
    auto add_func = std::bind(&add, _1, _2);
    std::cout<<"result = "<<add_func(4,5)<<std::endl;
}
