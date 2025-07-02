#include <iostream>

using namespace std;

bool checkForPrimeNumber(int number)
{
    for(int i = 2; i*i <= number; ++i)
    {
        if(number % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int number;
    cin >> number;
    cout << number << " is " << (checkForPrimeNumber(number) ? "It is Primer Number" : "It is not Primer number") << endl;
    return 0;
}