#include <iostream>
using namespace std;

class Base{
    public:
        virtual void print()
        {
            cout << "Base" << endl;
        }

        virtual ~Base()
        {

        }
};

class Derived1: public Base{
    public:
        void print()
        {
            cout << "Derived1" << endl;
        }
};

class Derived2: public Base{
    public:
        void print()
        {
            cout << "Derived2" << endl;
        }
};

int main()
{
    Derived2 d2;

    //Base* bp = (Base*) &d1;
    

    Base* bp = dynamic_cast<Base*>(&d2);

    Derived2* dp = dynamic_cast<Derived2*>(bp); // safe

    if(dp)
    {
        cout << "dp is valid Derived2 type" <<  endl;
    }
    else{
        cout << "dp is not Derived2 type" <<  endl;
    }

    d2.print();
    bp->print(); // Expectation :: Derived1
    return 0;
}

/*
    1. works only for polymorphic classes
    2. It can be used to do up cast and downcast as well, but especially used for down_cast
    3. It determines the object type by RTTI (Run time type information)
    4. If we know the exact object type as compile time then preper static_cast
*/
