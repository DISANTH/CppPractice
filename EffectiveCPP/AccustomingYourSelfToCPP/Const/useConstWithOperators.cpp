
#include <iostream>
using namespace std;

class Rational
{
    private:
        int x, y;
    public:

        Rational& operator=(const Rational& other)
        {
            cout << "Assignment operator called "  << endl;
            return *this;
        }

        /*
            Here const return type in this function restrict the user to do some typo errors
            Ex...

            if(instane1 * instance2 = instance3) // Here user intention is to do comparision on both the arguments but typed assignment. 
                                                    So due const return type from multiplication operator, compiler will throw an error. See the example in main function
            {     
            }
        */
        friend const Rational operator*(const Rational& lhs, const Rational& rhs)
        {
            return lhs;
        }
};

int main()
{
    Rational r1,r2,r3;
    r1 * r2 = r3; // This will throw compilation error, that const cannot be assigned.
    return 0;
}