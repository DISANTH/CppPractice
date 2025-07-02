#include <iostream>

using namespace std;

/*
    1. when actual referred object/variable is not const
*/

void case1()
{
    const int a1 = 10;
    const int *b1 = &a1;
    int *d1 = const_cast<int*>(b1);
    *d1 = 15; // Invalid and Undefined Behaviour

    int a = 20;
    const int *b2 = &a2;
    int *d2 = const_cast<int*>(b2);
    *d2 = 30;
}

/*
    2. When we need to call different module function where it is taking npn const data and it won't change anything in it.
*/

void functionInAModule(int* data)
{
    int k = 20;
    cout << k+ (*data);
}

void case2()
{
    const int x = 20;
    const int *px = &x;
    functionInAModule(const_cast<int*>(px));
}


/*
    3. When we need to call different module function where it is taking npn const data and it won't change anything in it.
*/

int main()
{
    case1();
    case2();
    return 0;
}