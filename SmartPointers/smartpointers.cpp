#include<iostream>
using namespace std;

class Something
{
    public:
        int x{5};
};

int main()
{
    Something some;
    (some.x)++;
    cout << "some.x :: " << some.x << endl;
    return 0;
}