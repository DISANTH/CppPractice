#include <iostream>
using namespace std;

int getMultipliedData(int* data)
{
    return 10 * (*data); // Not changing anything in Data...
}

int basicPrep()
{
    int data = 10;
    const int *ptr = &data;
    int* nonConstPtr = const_cast<int*>(ptr);
    cout << getMultipliedData(nonConstPtr) << endl;
    return 0;
}

void unDefinedBehaviorWithConstCast()
{
    const int data = 100;
    const int* constPtr = &data;

    int* nonConstPtr = const_cast<int*>(constPtr);
    *nonConstPtr = 2000; // undefined problem

    cout << "*constPtr :: " << *constPtr << " data :: " << data << endl;
}

class Base
{
    public:
        void basic2(int* data) const
        {
            cout << "*data :: "<< *data << endl;
        }
};

int restrictiveStaticCast()
{
    char c; // 1 Byte  4 Byte
    int *p = (int*) &c; // SUCCESS
    *p = 5;  // Undefined behaviour

    int* ip = static_cast<int*>(&c); //  FAIL
    return 0;
}

class Base {};

class Derived: private Base{};

int privateBase()
{
    Derived d1;
    Base *bp1 = (Base*) &d1; //  Allowed
    Base *bp2 = static_cast<Base*>(&d1); // Not allows

    return 0;
}

int main()
{
    // double d = static_cast<double>(5)/2; // 1.0 * 5 / 2;
    // cout << "d :: " << d << endl;
    //basicPrep();

    //unDefinedBehaviorWithConstCast();
    // Base base;
    // int id = 27; 
    // const int* data = &id;
    // base.basic2(const_cast<int*>(data));


    privateBase();

    return 0;
}