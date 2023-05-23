#include <iostream>

template <typename T, size_t size>
T* begin(T (&c)[size]){
    return &c[0];
}

template <typename T, size_t size>
T* end(T (&c)[size]){
    return &c[0] + size;
}

int main(){
    int arr[] = {1,2,3,4,5,6};
    for(auto itr=begin(arr); itr!=end(arr); ++itr){
        std::cout<<*itr<<" ";
    }
    std::cout<<std::endl;
}