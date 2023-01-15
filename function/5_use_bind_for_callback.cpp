#include <iostream>
#include <functional>

class MyClass {
private:
    //just shorthand to avoid long typing
    typedef std::function<void (float result)> TCallback;

    //this function takes long time
    void longRunningFunction(TCallback callback)
    {
        //do some long running task
        //...
        //callback to return result
        callback(result);
    }

    //this function gets called by longRunningFunction after its done
    void afterCompleteCallback(float result)
    {
        std::cout << result;
    }

public:
    int longRunningFunctionAsync()
    {
        //create callback - this equivalent of safe function pointer
        auto callback = std::bind(&MyClass::afterCompleteCallback, 
            this, std::placeholders::_1);

        //normally you want to start below function on seprate thread, 
        //but for illustration we will just do simple call
        longRunningFunction(callback);
    }
};

