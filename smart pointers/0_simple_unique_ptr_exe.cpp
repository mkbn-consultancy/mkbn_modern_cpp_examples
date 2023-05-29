//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//

#include <iostream>

template <class T>
class my_unique_ptr
{
public:
    //constructors

    //destructor
	~my_unique_ptr() {
	}

    //assignment operator
	
    //operator ->

    //operator *

private:

};


//----------- Testing -----------//
class Data
{
public:
    Data(size_t id) : _id{id}{}
    ~Data() { std::cout<<"inside Data's destructor\n"; }
private:
    size_t _id;
};

int main()
{
    // creates a my_unique_ptr object holding a 'Box' object
    my_unique_ptr<Data> box1(new Data{1541});

    // creates a my_unique_ptr object holding an array of 'Box' objects
    my_unique_ptr<Data[]> dataArr(new Data[3]{1476,9873,8764});
    Data d1 = dataArr[0]; // index based access

    // my_unique_ptr<Data> box2 = box1; //should not compile!!
    // my_unique_ptr<Data> box2(box1); //should not compile!!

    my_unique_ptr<Data> box2(new Data{1541});
    // box2 = box1; //should not compile!!!
    box2 = std::move(box1);
    
    return 0;
}