//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//
#include <iostream>
#include <string>
#include <memory>

struct Employee
{
    //Get params by value as Sink Parameters
    Employee(std::string name, int id, int salary) : 
        _name(std::move(name)), _id(id), _salary(salary){}

    void print() const{
        std::cout<<"name: "<<_name<<", id: "<<_id<<", salary: "<<_salary<<std::endl;
    }
private:
    std::string _name;
    int _id;
    int _salary;
};

struct Contact
{
    //Get params by value as Sink Parameters
    Contact(std::string name, std::string phoneNum) :
        _name(std::move(name)), _phoneNum(std::move(phoneNum)){}

    void print(){
        std::cout<<"name: "<<_name<<", phone number: "<<_phoneNum<<std::endl;
    }
private:
    std::string _name;
    std::string _phoneNum;
};

template<typename T, typename...Args>
std::shared_ptr<T> create(Args&&...args){
    return std::make_shared<T>(std::forward<Args>(args)...);
}

int main(){

    std::shared_ptr<int> p1 = create<int>(5);
    std::cout<<*p1<<std::endl;

    std::shared_ptr<std::string> s = create<std::string>("hello");
    std::cout<<*s<<std::endl;

    std::shared_ptr<Employee> e = create<Employee>("Bob", 324567, 10000);
    e->print();

    std::shared_ptr<Contact> c = create<Contact>("Joe","0503987342");
    c->print();
}