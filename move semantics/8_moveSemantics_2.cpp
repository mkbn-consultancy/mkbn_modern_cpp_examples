//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//
#include <string>
#include <memory>
#include <iostream>

template <typename T>
class Buffer
{
	enum {DEFAULT_SIZE=16};
public:
	Buffer() : _size{DEFAULT_SIZE}, _buffer{new T[DEFAULT_SIZE]}
	{ std::cout<<"default ctor\n"; }
	Buffer(std::string name, size_t size) :
		_name{std::move(name)}, _size{size}, _buffer{new T[size]}
	{ std::cout<<"parameterized ctor\n";}
	Buffer(const Buffer<T>& copy) : _name{copy._name}, _size{copy._size}, _buffer{new T[copy._size]}{
		T* source = copy._buffer.get();
		T* dest = _buffer.get();
		std::copy(source, source+copy._size, dest);
		std::cout<<"copy ctor\n";
	}
	Buffer& operator=(const Buffer<T>& copy){
		std::cout<<"operator=\n";
		if(this != &copy){
			_name = copy._name;
			if(_size != copy._size){
				_buffer = nullptr;
				_size = copy._size;
				_buffer = _size>0 ? new T[_size] : nullptr;
			}
			T* source = copy._buffer.get();
			T* dest = _buffer.get();
			std::copy(source, source+copy._size, dest);
		}
		return *this;
	}
	Buffer(Buffer<T>&& robj) : _name{std::move(robj._name)}, _size{robj._size},
		_buffer{std::move(robj._buffer)}
	{ std::cout<<"move ctor\n"; }
	Buffer& operator=(Buffer<T>&& robj){
		std::cout<<"move operator=\n";
		
		_buffer = nullptr;
		_size = robj._size;
		_buffer = std::move(robj._buffer);
		_name = std::move(robj._name);

		robj._buffer = nullptr;
		robj._size = 0;

		return *this;
	}
private:
	std::string	_name;
	size_t		_size;
	std::unique_ptr<T[]>	_buffer;
};

template<typename T>
Buffer<T> getBuffer(std::string name){
	Buffer<T> b{std::move(name), 128};
	return b;
}

int main()
{
	Buffer<int> b1;
	Buffer<int> b2{"buf2", 64};
	Buffer<int> b3 = b2;
	Buffer<int> b4 = getBuffer<int>("buf4");
	b1 = getBuffer<int>("buf5");
	return 0;
}
