#include <array>
#include <iostream>
#include <algorithm>
#include <functional>

int main()
{
    using namespace std::placeholders;  // for _1, _2, _3...
    std::array<int,10> arr{1,20,13,4,5,6,10,28,19,15};

    int divided_by = 5;
    auto lbd = [&divided_by](int num){return num%divided_by==0;};
    std::cout << std::count_if(std::begin(arr), std::end(arr) , std::bind(lbd, _1));
}