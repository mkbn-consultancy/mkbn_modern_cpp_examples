//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//
#include <iostream>

//TODO: Implement count_div_by_b_numbers_till_a

int numDiv(int n, int d){
    if(d==0){
        return 0;
    }
    if(n==0){
        return 0;
    }
    return (n%d==0) + numDiv(n-1,d);
}

int main()
{
    std::cout<<"#numbers till 20 divided by 3 is: "<<
                count_div_by_b_numbers_till_a<20,3>::value<<std::endl;

    int counter = 0;
    for(int i=20; i>0; i--){
        if(i%3==0){
            counter++;
        }
    }

    numDiv(20,3);
}
