//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//
#include <iostream>

int main(){
    int a = 2;

    decltype(a) x1 = a;

    decltype((a)) x2 = a;

    decltype(a)& x3 = a;

    decltype(5) x4 = a;

    decltype ((5)) x5 = a;

    decltype((5))& x6 = a;

    //see the types in c++ insights: https://cppinsights.io/s/90052556
}