#include <iostream>
#include <memory>

struct MyObject {
    MyObject() { std::cout << "creating the object\n"; }
    ~MyObject() { std::cout << "destructing the object\n"; }
};

void deleter_function(MyObject*) {}

struct DeleterFunctionObject {
    void operator()(MyObject*) {}
    size_t some_data[10];
};

auto get_object() {
    auto deleter = [](MyObject* p) {
        std::cout << "in the custom deleter code\n";
        delete p;
    };
    return std::unique_ptr<MyObject, decltype(deleter)>{new MyObject, deleter};
}

int main() {
    auto x = std::unique_ptr<MyObject>();
    std::cout<<"unique ptr size with no deleter: "<<sizeof(x)<<std::endl;
    
    {
    auto pObj = get_object();
    std::cout << "size of object with lambda deleter: "<<sizeof(pObj) << std::endl;
    }

    {
    auto pObjWithFuncDeleter = std::unique_ptr<MyObject, DeleterFunctionObject>(
        new MyObject, DeleterFunctionObject());
    std::cout << "size of object with function object deleter: "<<sizeof(pObjWithFuncDeleter) << std::endl;
    }

    {
    auto pObjWithFuncObject = std::unique_ptr<MyObject, void (*)(MyObject*)>(
        new MyObject, deleter_function);
    std::cout << "size of object with func ptr deleter: "<<sizeof(pObjWithFuncObject) << std::endl;
    }
}