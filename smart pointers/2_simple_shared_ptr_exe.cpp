//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//
//based on https://medium.com/analytics-vidhya/c-shared-ptr-and-how-to-write-your-own-d0d385c118ad#:~:text=shared_ptr%20is%20a%20reference%2Dcounted,(object)%20on%20the%20heap.
#include <iostream>

template <class T>
class my_shared_ptr
{
public:
	my_shared_ptr() //...
	my_shared_ptr(T * ptr) //...

	/*** Copy Semantics ***/
	// copy constructor
	my_shared_ptr(const my_shared_ptr & obj)
	{
	}
	// copy assignment
	my_shared_ptr& operator=(const my_shared_ptr & obj){
	}

	/*** Move Semantics ***/
	// move constructor
	my_shared_ptr(my_shared_ptr && dyingObj)
	{
	}
	// move assignment
	my_shared_ptr& operator=(my_shared_ptr && dyingObj)
	{
	}

	~my_shared_ptr() {
	}


	T* operator->() { return _ptr; }
	T& operator*()  { return *(_ptr); }

	size_t get_count() const{
	}

private:
};

class Box
{
public:
    int length, width, height;
    Box() : length(0), width(0), height(0)
    {
    }
};

int main()
{
    my_shared_ptr<Box> obj;
    std::cout << obj.get_count() << std::endl; // prints 0
    my_shared_ptr<Box> box1(new Box());
    std::cout << box1.get_count() << std::endl; // prints 1
    my_shared_ptr<Box> box2(box1); // calls copy constructor
    std::cout << box1.get_count() << std::endl; // prints 2
    std::cout << box2.get_count() << std::endl; // also prints 2
 
    return 0;
}
