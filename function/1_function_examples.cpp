#include <iostream>
#include <functional>

int main()
{
    auto func = std::function<void(int)>{
        [](int v)
        { std::cout << "value is " << v << std::endl; }
    };
    func(12);
}