#include <memory>
#include <iostream>

using namespace std;


class B;

class NewB;

class NewA
{      

    public:
        shared_ptr<NewB> newBShared;
        NewA()
        {
            cout << "NewA constructor called" << endl;
        }

        ~NewA()
        {
            cout << "NewA Destructor called" << endl;
        }
};

class A
{      

    public:
        shared_ptr<B> bShared; //
        A()
        {
            cout << "A constructor called" << endl;
        }

        ~A()
        {
            cout << "A Destructor called" << endl;
        }
};

class NewB{
    public:
        weak_ptr<NewA> weakBPtr;
        NewB()
        {
            cout << "NewB constructor called" << endl;
        }

        ~NewB()
        {
            cout << "NewB Destructor called" << endl;
        }
};

class B
{
    public:
        shared_ptr<A> aShared;

        B()
        {
            cout << "B constructor called" << endl;
        }

        ~B()
        {
            cout << "B Destructor called" << endl;
        }
};


void problemWithoutWeakPointer()
{
    shared_ptr<A> aPtr(new A()); // shared pointer of B
    shared_ptr<B> bPtr(new B()); // shared pointer of A

    aPtr->bShared = bPtr;

    bPtr->aShared = aPtr;
}

void solWithoutWeakPointer()
{
    shared_ptr<NewA> aPtr(new NewA());
    shared_ptr<NewB> bPtr(new NewB());

    aPtr->newBShared = bPtr;

    bPtr->weakBPtr = aPtr;
}

void checkWeakPointer()
{
    shared_ptr<int> sharedPtr = make_shared<int>(15);
    weak_ptr<int> weakPtr = sharedPtr;

    cout << "reference count :: " << sharedPtr.use_count() << endl;

    if(auto flag = weakPtr.lock())
    {
        std::cout << " value is  :: " << *sharedPtr << endl;
    }
    else{
        std::cout << " sharedPtr is not available " << endl;
    }

    sharedPtr.reset();

    if(weakPtr.lock())
    {
        std::cout << " value is  :: " << *sharedPtr << endl;
    }
    else{
        std::cout << " sharedPtr is not available " << endl;
    }
}

int main()
{

    //problemWithoutWeakPointer();
    solWithoutWeakPointer();
    return 0;
}