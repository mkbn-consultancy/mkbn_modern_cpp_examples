#include <stdint.h>
#include <memory>
#include <iostream>
#include <numeric>

template <typename T>
class SpecialArray
{
public:
    SpecialArray(size_t size) : size_{size}, array_{new T[size]}{}
    size_t arraySize() {return size_;};
    T& valueAt(size_t index) {return array_.get()[index];};
    //...
private:
    size_t size_{};
    size_t capacity_{};
    std::unique_ptr<T>  array_{};
};

template <typename T>
class SpecialArrayIterator
{
   SpecialArrayIterator(SpecialArray<T>* p, int i)
    :curr_index_(i), parray_(p)
   {}
   SpecialArrayIterator operator ++();
   SpecialArrayIterator operator --();
   SpecialArrayIterator operator ++(int);
   SpecialArrayIterator operator --(int);
   T& operator *()
   {
     return parray_->valueAt(curr_index_);
   }
   bool operator ==(SpecialArray<T> &);
   // etc
private:
   std::unique_ptr<SpecialArray<T>> parray_;
   int curr_index_;
   // etc
};

template <typename T>
SpecialArrayIterator<T> begin(SpecialArray<T> & arr)
{
  return SpecialArrayIterator(&arr, 0);
}

template <typename T>
SpecialArrayIterator<T> end(SpecialArray<T> & arr)
{
  return SpecialArrayIterator(&arr, arr.arraySize());
}

int main(){
    SpecialArray<int> arr(10);
    for(auto i=0; i<10; ++i){
        arr.valueAt(i) = i+1;
    }

    //we would like to use std::accumulate to sum array's elements
    auto sum = std::accumulate(begin(arr), end(arr), 0);
}