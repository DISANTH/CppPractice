#include<iostream>

using namespace std;

class MyVector
{
    public:
        MyVector()
        {
            cout << "Default COnstructor called" << endl;
        }

        constexpr MyVector(const MyVector&)
        {
            cout << "Copy Constructor called" << endl;
        }

        MyVector(MyVector &&other)
        {
            cout << "Move COnstructor called" << endl;
        }

        MyVector& operator=(MyVector& other)
        {
            cout << "Move Assignment operator called" << endl;
            return *this;
        }
};

MyVector& getVector()
{
    MyVector myVec;
    return myVec;
}

int main()
{
    MyVector myVec(std::move(getVector()));
    return 0;
}