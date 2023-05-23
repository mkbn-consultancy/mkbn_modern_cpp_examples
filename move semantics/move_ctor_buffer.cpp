#include <iostream>

template <class T>
class Buffer{
public:
    Buffer() = default;
    Buffer(const Buffer& b){
        //deep copy
        size_ = b.size_;
        capacity_ = b.capacity_;
        buffer_name = b.buffer_name;
        data_ = new T[size_];
        std::copy(std::begin(b.data_), std::end(b.data_),data_);
    }
    Buffer(Buffer&& b){
        //move data to this
        size_ = b.size_;
        capacity_ = b.capacity_;
        data_ = b.data_;
        b.data_ = nullptr;
        buffer_name = std::move(b.buffer_name);
    }
    Buffer& operator=(const Buffer& b){
        if(this != &b){
            //delete prev data
            delete[] data_;
            //copy new data
            size_ = b.size_;
            capacity_ = b.capacity_;
            buffer_name = b.buffer_name;
            data_ = new T[size_];
            std::copy(std::begin(b.data_), std::end(b.data_),data_);
        }
        return *this;
    }
    Buffer& operator=(Buffer&& b){
        if(this != &b){
            //delete prev data
            delete[] data_;
            //copy new data
            size_ = b.size_;
            capacity_ = b.capacity_;
            buffer_name = std::move(b.buffer_name);
            data_ = b.data_;
            b.data_ = nullptr;
        }
        return *this;
    }
private:
    T* data_{};
    size_t size_{};
    size_t capacity_{};
    std::string buffer_name;
};

template <class T>
void g(T&& obj){
}

template <class T>
void f(T&& obj){
    g(std::forward(obj));
}
/*
lvx --> f(T& obj) --> g(T&& obj) 
Get() --> f(T&& obj) --> g(T&& obj)
*/

int main(){
    Buffer<int> b1, b2;
    b1 = Buffer<int>();
}