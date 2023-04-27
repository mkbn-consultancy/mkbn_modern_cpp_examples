//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//
#include <iostream>

//TODO: Implement count_div_by_b_numbers_till_a

template<bool B>
struct IsDivBy{
    enum{result = B};
};

template<unsigned int a, unsigned int b>
struct count_div_by_b_numbers_till_a{
    enum{value = IsDivBy<(a%b==0)>::result + count_div_by_b_numbers_till_a<a-1,b>::value};
};


int main()
{
    std::cout<<"#numbers till 20 divided by 3 is: "<<
    count_div_by_b_numbers_till_a<20,0>::value<<std::endl;
}
