#include <iostream>
using namespace std;

void function()
{
    cout << "Hello from function" << endl;
}

class Monitor
{
    public:
        Monitor() = default;

        void operator()(int x, int y)
        {
            cout << "x :: " << x << " y :: " << y << endl;
        }

        void operator()()
        {
            cout << "Functor " << endl;
        }
};

int main()
{
    Monitor m1; // callable object
    m1();
    m1(4,5);
    return 0;
}