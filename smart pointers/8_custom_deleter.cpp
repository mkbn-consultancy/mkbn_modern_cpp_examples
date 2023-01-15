#include <iostream>
#include <memory>

struct MyObject{
    MyObject() {std::cout<<"creating the object\n";}
    ~MyObject() {std::cout<<"destructing the object\n";}
};

auto get_object_as_uniqe_ptr(){
    auto deleter = [](MyObject* p){
        std::cout<<"in the custom deleter code\n";
        delete p;
    };
    std::unique_ptr<MyObject,decltype(deleter)> pObj(new MyObject,deleter);
    return pObj;
}

auto get_object_as_shared_ptr(){
    auto deleter = [](MyObject* p){
        std::cout<<"in the custom deleter code\n";
        delete p;
    };
    std::shared_ptr<MyObject> pObj(new MyObject,deleter);
    return pObj;
}



int main(){
    auto pObj = get_object();
}