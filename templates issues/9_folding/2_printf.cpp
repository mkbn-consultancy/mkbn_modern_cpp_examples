//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//
#include <iostream>
#include <string>

template<typename ...Args>
void printf(Args&&... args) {
    //TODO: Rewrite the following implementation to print
    //a comma between the elements
    (std::cout <<  ... <<  std::forward<Args>(args)) << std::endl;
}

int main()
{
    int x = 8;
    printf("hello", ", ", 10, ", ", 90.0, ", ", x);
}