#include <iostream>

using namespace std;

/*
    1. It performs implict type conversions
*/

int implictConversions()
{
    float f = 3.5;
    int a;
    a = f; // 3
    a = static_cast<int>(f); // 3
    return 0;
}

/*
    2. use static_cast when conversion between types in provided through conversion operator or consversion 
*/

class MyInt{
    int x;
    public:
        MyInt(int _x = 0) : x{_x}
        {

        }

        operator string()
        {
            return to_string(x);
        }
};

int convertOperatorOrConstrctor()
{
    MyInt obj(3);

    string str1 = obj;

    string str2 = static_cast<string>(obj);

    obj = 30; // Not readable...
    obj = static_cast<MyInt>(30); // More readable
    return 0;
}

/*
    3. static cast is restrictive than c-style cast
    Example : char* to int* is allowed in C-style but not with static_cast
*/

int restrictiveStaticCast()
{
    char c; // 1 Byte  4 Byte
    int *p = (int*) &c; // SUCCESS
    *p = 5;  // Undefined behaviour

    int* ip = static_cast<int*>(&c); //  FAIL
    return 0;
}

/*
    4. Static_cast avoid cast from derived to private base pointer
*/

class Base {};

class Derived: private Base{};

int privateBase()
{
    Derived d1;
    Base *bp1 = (Base*) &d1; //  Allowed
    Base *bp2 = static_cast<Base*>(&d1); // Not allows

    return 0;
}

/*
    5. static_cast should be preperred when we are converting to void* OR from void*
*/

int voidConversions()
{
    int i = 0;
    void* v = static_cast<void*> (&i);
    int* ip = static_cast<int*>(v);
    return 0;
}


/*
    6. use for all upcasts, but never use for confused down cast
*/

class Base{}

class Derived1: public Base {};
class Derived2: public Base {};

int useForAllUpCastsButNotForConfusedDownCasts()
{
    Derived1 d1;
    Derived2 d2;

    Base *bp1 = static_cast<Base*> (&d1); // Up Casting is always works
    Base *bp2 = static_cast<Base*> (&d2); // 

    Derived1* d1p = static_cast<Derived1*>(bp2); // Not safe and undefined behaviour
    Derived2* d2p = static_cast<Derived2*>(bp1); // Not safe and undefined behaviour
    return 0;
}

int main()
{
    implictConversions();
    convertOperatorOrConstrctor();
    restrictiveStaticCast();
    return 0;
}

/*
    
*/