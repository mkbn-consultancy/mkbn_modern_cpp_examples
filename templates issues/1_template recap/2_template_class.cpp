template<class T>
class Array
{
public:
    void add(T val);
private:
    T* _arr;
};

template<class T>
void Array<T>::add(T val){}