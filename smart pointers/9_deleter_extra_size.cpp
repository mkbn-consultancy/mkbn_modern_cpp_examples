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
    {
    auto pObj = get_object();
    std::cout << sizeof(pObj) << std::endl;
    }

    {
    auto pObjWithFuncDeleter = std::unique_ptr<MyObject, DeleterFunctionObject>(
        new MyObject, DeleterFunctionObject());
    std::cout << sizeof(pObjWithFuncDeleter) << std::endl;
    }

    {
    auto pObjWithFuncObject = std::unique_ptr<MyObject, void (*)(MyObject*)>(
        new MyObject, deleter_function);
    std::cout << sizeof(pObjWithFuncObject) << std::endl;
    }
}