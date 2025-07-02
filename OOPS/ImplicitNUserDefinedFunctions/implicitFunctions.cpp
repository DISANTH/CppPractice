
#include<iostream>
#include<cstring>
using namespace std;

class Monitor
{
private:
    string objectName;
    char* data; // Heap kind of data ... ....> address  

public:
    Monitor(string _objectName, char* dummy): objectName(_objectName)
    {
        cout << "Default Constructor" <<  endl;
        data = new char[100000];
        strcpy( this-> data, dummy);
    }

    ~Monitor()
    {
        //cout << "Destructor objectName :: " << objectName <<  endl;
        delete data;
    }

    Monitor(const Monitor& other)
    {
        this-> objectName = other.objectName;
        this-> data = new char[100000];
        strcpy( this-> data, other.data);
    }

    Monitor& operator=(const Monitor& other)
    {
        cout << "LValue Assignment is called" <<  endl;
        if(this == &other)
        {
            return *this;
        }

        if(this-> data)
            delete this-> data;
        this-> objectName = other.objectName;
        this-> data = new char[100000]; // new memory creation
        strcpy( this-> data, other.data);
        return *this;
    }

    Monitor(Monitor&& other) // Move Constructor
    {
        this->objectName = std::move(other.objectName);
        this->data = other.data;
        other.data  = nullptr;
    }

    Monitor& operator=(Monitor&& other) // Move assignment operator
    {
        cout << "RValue Assignment is called" <<  endl;
        if(this == &other)
        {
            return *this;
        }

        if(this-> data)
            delete this-> data;
        this-> objectName = other.objectName;
        this-> data = other.data;

        other.data = nullptr;
        return *this;
    }

    void setObjectName(string _objectName)
    {
        objectName = _objectName;
    }

    void printData()
    {
        if(this->data)
        {
            cout << "[" << objectName << "] " << "Data is exists Data : " << this->data << endl;
        }
        else{
            cout << "[" << objectName << "] " <<"Data is stolen" << endl;
        }
    }

    // How many methods are exists in this class
    /*
        1. Default Constructor
        2. Copy Constructor
        3. Default assignment operator
        4. Move Copy Constructor
        5. Move assignment operator
        6. Destructor
    */
};

int main()
{
    Monitor monitor1("monitor1",
        (char*)"DisanthfjhaskjfhkjasbfhasgfijahjghraGryuwryurgahhjasgfvhjASgfjghdaskfihasfhasghjagfjasgfhsgfhjASfghjfvshfghfhjgfgfgffjfjhfasjkgfskahfgaslgfaskgfkasjgfaskjgfkjasgfaskjgfhjasgfkjasgfhasfaskjgfaskfaskjaskjgfvgfafskkagfshffsvfvahskfashkfjgasfkasfavffashfvafhfvahf"); // Dangling address (Destroyed by someone)

    // Monitor monitor2(monitor1); // copy the members from monitor1;
    // monitor2.setObjectName("monitor2"); // Dangling address (Destroyed by someone)

    Monitor monitor2 = std::move(monitor1); // Copy Constructor, two copies... --> 1MB will be consumed here..
    

    //monitor3 = std::move(monitor1); // Assignment operator....   monitor1.operator=(monitor3)
    
    monitor2.setObjectName("monitor2");
    monitor1.printData();

    cout << endl;

    monitor2.printData();
    // monitor1
    // monitor2
    // monitor3 --> 

    // when will be move constructor will be called...?


    return 0;
}