#include <type_traits>
#include <iostream>
#include <memory>
#include <assert.h>

template<class T>
struct is_shared_ptr{
    static constexpr bool value = false;
};
template<class T>
struct is_shared_ptr<std::shared_ptr<T>>{
    static constexpr bool value = true;
};

template<class T>
constexpr bool is_shared_ptr_v = is_shared_ptr<T>::value;

template<class T>
auto GetRawPtr(T t){
    if constexpr(std::is_pointer_v<T>){
        return t;
    }
    if constexpr(is_shared_ptr_v<T>){
        return t.get();
    }
    else{
        return nullptr;
    }
}

int main(){
    int* p = nullptr;
    int a = 5;
    std::shared_ptr<int> sp{p};
    static_assert(is_shared_ptr_v<decltype(sp)> == true);
    auto ptr = GetRawPtr(sp);
    static_assert(is_shared_ptr_v<decltype(ptr)> == false);
}

// g++ .\3_traits_get_raw_ptr.cpp -o getrawptr.exe -std=c++17