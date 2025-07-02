#include<iostream>
using namespace std;

int basicReference()
{
    int i = 10; // Integer Literal
    string name = "Disanth";
    int j = 100;
    //int* ptr;

    int& iRef = i;

    iRef = j;

    j = 1000;

    iRef = j;

    cout << "i :: " << i << " ,  iRef :: " << iRef << endl;

    return 0;
}

void printName(const string& name)
{
    cout << "[lValue] name :: " << name <<  endl;
}


void printName(string&& name)
{
    cout << "[rValue] name :: " << name <<  endl;
}

string getFullName()
{
    string firstName = "John";
    string lastName = "Doe";

    string fullName = firstName + lastName; // "John" + "Doe" --> Temporary object (unnamed value)

    return fullName;
}

int main()
{
    string firstName = "DisanthfjhaskjfhkjasbfhasgfijahjghraGryuwryurgahhjasgfvhjASgfjghdaskfihasfhasghjagfjasgfhsgfhjASfghjfvshfghfhjgfgfgffjfjhfasjkgfskahfgaslgfaskgfkasjgfaskjgfkjasgfaskjgfhjasgfkjasgfhasfaskjgfaskfaskjaskjgfvgfafskkagfshffsvfvahskfashkfjgasfkasfavffashfvafhfvahf"; // 1MB
    string& duplicateName = firstName;

    printName("John");
    printName(std::move(firstName));

    // I don't want use this lValue at all....

    return 0;
}
