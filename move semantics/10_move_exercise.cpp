/*
Modern C++ Course: MOVE SEMANTICS HANDS-ON EXERCISE

PART 1:

Create a class A with:
•	Data members:
    o	A pointer to an int as a private member
•	Methods:
    o	A constructor that accepts a reference to an int and allocates an int on the heap and sets it value from the ctor's parameter.

    For debugging: add a printout in the ctor as follows:
    "class A constructor: XXX" 
    (XXX = value of A's private int number).

    o	A copy constructor that handles the following code:
        A a1(3);
        A a2{a1};
        A a3{A{4}};
        For debugging: add a printout as follows:
        "class A copy constructor: XXX"
        (XXX = value of A's private int number).
        Try to compile with the flag -fno-elide-constructors

    o	A destructor that frees the memory associated with the int on the heap.
        For debugging: add a printout as follows (before freeing the int):
        "class A destructor: XXX"
        (XXX = value of A's private int number).
        If the private int pointer is nullptr, the value XXX should be printed is the string "nullptr".


    o	A public method get_number() that return the value of the private int member.

Run the following code:
A a1{3};
A a2{a1};
A a3{A{4}};
Can you explain the output?

PART 2:

Add the following methods to class A:
    o	A move constructor.
        For debugging: add a printout as follows:
        "class A move constructor: XXX"
        (XXX = value of A's private int number).

    o	A copy assignment operator.
        For debugging: add a printout as follows:
        "class A copy assignment operator: XXX"
        (XXX = value of A's private int number).


    o	A move assignment operator.
        For debugging: add a printout as follows:
        "class A move assignment operator: XXX"
        (XXX = value of A's private int number).

Run the following code:
std:vector<A> v;
v.push_back(A(5));
v.push_back(A{5});

A a5{7};
A a6{8};
A a7{9};
a6 = a5;
a7 = A{10};

PART 3:

Use the std::move function to force move semantics to be used when creating a new instance of class A.
Notice the following code and output:

A a8{11};
A a9{std::move(a8)};

*/
