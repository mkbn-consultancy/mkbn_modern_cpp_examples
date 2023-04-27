//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//
//based on https://medium.com/analytics-vidhya/c-shared-ptr-and-how-to-write-your-own-d0d385c118ad#:~:text=shared_ptr%20is%20a%20reference%2Dcounted,(object)%20on%20the%20heap.
#include <iostream>

template <class T>
class my_shared_ptr
{
public:
	my_shared_ptr() : _ptr(nullptr), _refCount(new size_t(0)){}
	my_shared_ptr(T * ptr) : _ptr(ptr), _refCount(new size_t(1)){}

	/*** Copy Semantics ***/
	// copy constructor
	my_shared_ptr(const my_shared_ptr & obj)
	{
		_ptr = obj._ptr; // share the underlying pointer
		_refCount = obj._refCount; // share refCount
		if (nullptr != obj._ptr)
		{
			// if the pointer is not null, increment the refCount
			(*_refCount)++; 
		}
	}
	// copy assignment
	my_shared_ptr& operator=(const my_shared_ptr & obj){
		// cleanup any existing data
		// Assign incoming object's data to this object
		this->ptr = obj.ptr; // share the underlying pointer
		this->refCount = obj.refCount; // share refCount
		if (nullptr != obj.ptr)
		{
			// if the pointer is not null, increment the refCount
			(*this->refCount)++; 
		}
	}

	/*** Move Semantics ***/
	// move constructor
	my_shared_ptr(my_shared_ptr && dyingObj)
	{
		this->ptr = dyingObj.ptr; // share the underlying pointer
		this->refCount = dyingObj.refCount; // share refCount
		dyingObj.ptr = dyingObj.refCount = nullptr; // clean up dyingObj
	}
	// move assignment
	my_shared_ptr& operator=(my_shared_ptr && dyingObj)
	{
		// cleanup any existing data
		
		this->ptr = dyingObj.ptr; // share the underlying pointer
		this->refCount = dyingObj.refCount; // share refCount
		dyingObj.ptr = dyingObj.refCount = nullptr; // clean up dyingObj
	}

	~my_shared_ptr() {
			cleanup();
	}


	T* operator->() { return _ptr; }
	T& operator*()  { return *(_ptr); }

	size_t get_count() const{
		return *_refCount; // *this->refCount
	}
	T* get() const{
		return _ptr;
	}

private:
	void cleanup(){
		(*_refCount)--;
		if (*_refCount == 0){
			if (nullptr != _ptr){
				delete _ptr;
			}
			delete _refCount;
		}
	}
private:
	T* _ptr = nullptr;
	size_t* _refCount = nullptr;
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
