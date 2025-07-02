#include <iostream>
using namespace std;

class MyInt{
    int x;
    public:
        explicit MyInt(int _x = 0) : x{_x}
        {

        }

        operator string()
        {
            return to_string(x);
        }

        void print()
        {
            cout << "MyInt::x :: " << x << endl;
        }
};

void printMyInt(MyInt integerData)
{
    integerData.print();
}

int main()
{
    // MyInt integerData(28);
    // std::string data = integerData; // copy constructor

    printMyInt(23);
    return 0;
}