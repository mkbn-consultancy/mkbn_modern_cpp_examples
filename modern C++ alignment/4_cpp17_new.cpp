//source: https://www.bfilipek.com/2019/08/newnew-align.html

//C++17 Code

#include <iostream>
#include <new>
#include <cassert>

void* operator new(std::size_t size) {
	auto ptr = malloc(size);
	if (!ptr)
		throw std::bad_alloc{};
	std::cout << "[old new:] " << size << ", ptr: " << ptr << '\n';
	return ptr;
}

void operator delete(void* ptr, std::size_t size) {
	std::cout << "[old delete,size:] " << size << ", ptr: " << ptr << '\n';
	free(ptr);
}

void operator delete(void* ptr) {
	std::cout << "[old delete:] ptr: " << ptr << '\n';
	free(ptr);
}

void* operator new(std::size_t size, std::align_val_t align) 
{
#if defined(_WIN32) || defined(__CYGWIN__)
    auto ptr = _aligned_malloc(size, static_cast<std::size_t>(align));
#else
    auto ptr = aligned_alloc(static_cast<std::size_t>(align), size);
#endif

    if (!ptr){
        throw std::bad_alloc{};
    }
    std::cout << "[aligned new:] " << size << ", align: " 
              << static_cast<std::size_t>(align) 
              << ", ptr: " << ptr << '\n';

    return ptr;
}

void operator delete(void* ptr, std::size_t size, std::align_val_t align) noexcept 
{
    std::cout << "[aligned delete,size:] " << size << ", align: " 
              << static_cast<std::size_t>(align) 
              << ", ptr : " << ptr << '\n';
#if defined(_WIN32) || defined(__CYGWIN__) 
    _aligned_free(ptr);
#else
    free(ptr);
#endif
}

void operator delete(void* ptr, std::align_val_t align) noexcept 
{
    std::cout << "[aligned delete] " 
              << static_cast<std::size_t>(align) 
              << ", ptr : " << ptr << '\n';
#if defined(_WIN32) || defined(__CYGWIN__)
    _aligned_free(ptr);
#else
    free(ptr);
#endif
}

class alignas(32) Vec3dAVX { 
    double x, y, z;
};

int main() {
    std::cout << "__STDCPP_DEFAULT_NEW_ALIGNMENT__ is " 
              << __STDCPP_DEFAULT_NEW_ALIGNMENT__ << std::endl;

    std::cout << "sizeof(Vec3dAVX) is " << sizeof(Vec3dAVX) << '\n';
    std::cout << "alignof(Vec3dAVX) is " << alignof(Vec3dAVX) << '\n';
    std::cout<<"[main:] allocating Vec3dAVX[10]: ----------------------\n";
    auto pVec = new Vec3dAVX[10];
    assert(reinterpret_cast<uintptr_t>(pVec) % alignof(Vec3dAVX) == 0);
    delete[] pVec;
    std::cout<<"[main:] allocating int[10]: ----------------------\n";
    auto p2 = new int[10];
    delete[] p2;
}
