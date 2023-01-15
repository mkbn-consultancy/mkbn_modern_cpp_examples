#include <functional>
#include <iostream>

int add(int first, int second)
{
    return first + second;
}

int main(){
    using namespace std::placeholders;  // for _1, _2, _3...
    auto add_func = std::bind(&add, _1, _2);
    std::cout<<"result = "<<add_func(4,5)<<std::endl;
}
