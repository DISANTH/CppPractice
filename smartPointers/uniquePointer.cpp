#include <iostream>
#include <memory>

using namespace std;

template <class T>
class MyUniquePointer
{
private:
    T *data_pointer{nullptr};

    void _cleanUp()
    {
        if (data_pointer)
            delete data_pointer;
    }

public:
    MyUniquePointer() : data_pointer(nullptr)
    {
    }

    MyUniquePointer(T *ptr) : data_pointer(ptr)
    {
    }

    MyUniquePointer(const MyUniquePointer &other) = delete;

    MyUniquePointer &operator=(const MyUniquePointer &other) = delete;

    MyUniquePointer(MyUniquePointer &&other)
    {
        this->data_pointer = other.data_pointer;
        other.data_pointer = nullptr;
    }

    MyUniquePointer &operator=(MyUniquePointer &&other)
    {
        _cleanUp();

        this->data_pointer = other.data_pointer;
        other.data_pointer = nullptr;
    }

    T *operator->()
    {
        return data_pointer;
    }

    T &operator*()
    {
        return *(this->data_pointer);
    }

    T *release()
    {
        T *rawPtr = this->data_pointer;
        this->data_pointer = nullptr;
        return rawPtr;
    }

    operator bool()
    {
        if(data_pointer)
            return true;
        return false;
    }

    ~MyUniquePointer()
    {
        _cleanUp();
    }
};

void basicUniquePointer()
{
    std::unique_ptr<int> uniqPtr1(new int(2));
    std::unique_ptr<int> uniqPtr2(new int(3));
    if (uniqPtr1)
    {
        cout << "unique1 :: " << *uniqPtr1 << endl;
    }

    if (uniqPtr2)
    {
        cout << "unique2 :: " << *uniqPtr2 << endl;
    }

    unique_ptr<int> uniqPtr3 = std::move(uniqPtr2);

    if (uniqPtr3)
    {
        cout << "unique3 :: " << *uniqPtr3 << endl;
    }

    if (!uniqPtr2)
    {
        cout << "unique2 is not valid anymore " << endl;
    }
}

void changeUniquePointerOwnerShip()
{
    MyUniquePointer<int> uniqPtr(new int(10));

    if (uniqPtr)
    {
        cout << "uniqPtr  value :: " << *uniqPtr << endl;
    }

    int *rawPointer = uniqPtr.release();

    if (!uniqPtr)
    {
        cout << "uniqPtr  is not valid anymore" << endl;
    }

    cout << "value of raw pointer :: " << *rawPointer << endl;
}

// int main()
// {
//     changeUniquePointerOwnerShip();
//     return 0;
// }


//

// Uq (raw pointer);

// Stack    Heap(delete)


int main()
{
    MyUniquePointer<int> disanth(new int(1000));

    MyUniquePointer<int> nitish(std::move(disanth));

    if(disanth)
    {
        cout <<"disanth valid" << endl;
    }
    else{
        cout <<"disanth invalid" << endl;
    }

    if(nitish)
    {
        cout <<"nitish valid " << *nitish << endl;
    }
    else{
        cout <<"nitish invalid" << endl;
    }

    cout << disanth << endl;

    cout << nitish << endl;

    return 0;
}


// data(8bytes) ----> [] (2MB)


// Rectangle b;

// Rectangle a = b; (copy constructor)

// Rectangle a = std:::move(b); //(move constructor);


// a = std::move(c);

//b will exist with undefined state;