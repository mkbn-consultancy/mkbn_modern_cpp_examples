//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//
// singletonAcquireRelease.cpp
//source: https://www.modernescpp.com/index.php/thread-safe-initialization-of-a-singleton

#include <atomic>
#include <iostream>
#include <future>
#include <mutex>
#include <thread>

constexpr auto tenMill= 10000000;

class MySingleton_Lock{
public:
  static MySingleton_Lock* getInstance()
  {
    MySingleton_Lock* sin= instance.load();
    if ( !sin ){
      std::lock_guard<std::mutex> myLock(myMutex);
      sin = instance.load();    //double check
      if( !sin ){
        sin = new MySingleton_Lock(); //preparing the shared data to be publish
        instance.store(sin);    //only now the sin will be published to other threads
      }
    }   
    return sin;
  }
private:
  MySingleton_Lock()= default;
  ~MySingleton_Lock()= default;
  MySingleton_Lock(const MySingleton_Lock&)= delete;
  MySingleton_Lock& operator=(const MySingleton_Lock&)= delete;
private:
  inline static std::atomic<MySingleton_Lock*> instance;
  inline static std::mutex myMutex;
};

//-----------------------------------------------------

class MySingleton{
public:
    static MySingleton* getInstance();
private:
    inline static std::atomic<MySingleton*> m_instance;
    inline static std::mutex m_mutex;
};

MySingleton* MySingleton::getInstance() {
    MySingleton* tmp = m_instance.load(std::memory_order_relaxed);
    std::atomic_thread_fence(std::memory_order_acquire);
    if (tmp == nullptr) {
        std::lock_guard<std::mutex> lock(m_mutex);
        tmp = m_instance.load(std::memory_order_relaxed);
        if (tmp == nullptr) {
            tmp = new MySingleton;
            std::atomic_thread_fence(std::memory_order_release);
            m_instance.store(tmp, std::memory_order_relaxed);
        }
    }
    return tmp;
}
/*
MySingleton* Singleton::getInstance() {
    MySingleton* tmp = m_instance.load(std::memory_order_acquire);
    if (tmp == nullptr) {
        std::lock_guard<std::mutex> lock(m_mutex);
        tmp = m_instance.load(std::memory_order_relaxed);
        if (tmp == nullptr) {
            tmp = new MySingleton;
            //-->use store with memory_order_release instead:
            m_instance.store(tmp, std::memory_order_release);
        }
    }
    return tmp;
}
*/
//-----------------------------------------------------
template<typename T>
concept SingletonC = requires(T a)
{
    T::getInstance();
};

template<SingletonC S>
std::chrono::duration<double> getTime(){

  auto begin= std::chrono::system_clock::now();
  for ( size_t i= 0; i <= tenMill; ++i){
       S::getInstance();
  }
  return std::chrono::system_clock::now() - begin;
  
};
//-----------------------------------------------------

int main(){
    // using Singleton_t = MySingleton_Lock;
    using Singleton_t = MySingleton;
    auto fut1= std::async(std::launch::async,getTime<Singleton_t>);
    auto fut2= std::async(std::launch::async,getTime<Singleton_t>);
    auto fut3= std::async(std::launch::async,getTime<Singleton_t>);
    auto fut4= std::async(std::launch::async,getTime<Singleton_t>);
    
    auto total= fut1.get() + fut2.get() + fut3.get() + fut4.get();
    
    std::cout << total.count() << std::endl;

}
