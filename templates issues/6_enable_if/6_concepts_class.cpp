#include <concepts>
#include <iostream>
#include <vector>

template<class T>
concept BufferC = requires(T t){
    t[0];
    std::begin(t);
    std::end(t);
};

template<BufferC T>
auto first_element_in_buffer(T&& buf){
    return buf[0];
}

int main(){
    std::vector<int> vec{1,2,3,4,5};
    std::cout<<first_element_in_buffer(vec)<<std::endl;

    int arr[]{5,4,3,2,1};
    std::cout<<first_element_in_buffer(arr)<<std::endl;

    //ERROR:
    //std::cout<<first_element_in_buffer(5)<<std::endl;
}