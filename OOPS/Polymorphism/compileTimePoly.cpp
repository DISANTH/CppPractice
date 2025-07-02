

#include<iostream>
using namespace std;

//Method Overaloading

class Sum
{
    public:

        int add(int x, int y) --> // --> add_intX_intY
        {
            return x + y;
        }

        void add(int x, int y, int z) //  --> add_intX_intY_intZ
        {

        }

        float add(float x, float y)
        {

        }
};

int main()
{
    add(1,2);
    add(1,2,3);
    add(1.2, 2,5); // Flexibility to the user....
    return 0;
}


//Method Overaloading
class Matrix
{
    private:
        double x1, y1, x2, y2;
    
    public:
        Matrix(double _x1, double _y1, double _x2, double _y2): x1(_x1), y1(_y1), x2(_x2), y2(_y2)
        {

        }

        void print()
        {
            cout <<  endl;
            cout << x1 << " "<< y1 << endl;
            cout << x2 << " "<< y2 << endl;
            cout <<  endl;
        }

        friend Matrix operator+(const Matrix& m1, const Matrix &m2)
        {
            Matrix m3(m1.x1 + m2.x1 , m1.y1 + m2.y1 , m1.x2 + m2.x2, m1.y2+m2.y2);
            return m3;
        }

        // operator<();

        // operator=();

        // operator*();

        // operator[]();
};

// A = 
// [ 1.0  2.0 ]
// [ 3.0  4.0 ]

// B = 
// [ 4.0  3.0 ]
// [ 2.0  0.0 ]


// C = 
// [ 5.0  5.0 ]
// [ 5.0  4.0 ]




int main()
{
    Matrix m1(1.0,2.0,3.0,4.0);
    Matrix m2(4.0,3.0,2.0,0.0);

    Matrix m3 = m1+m2; // operator+(m1,m2); 01110  +  110011 --> 
    m3.print();

    m1 = m2;

    //cout << (1+2) << endl;

    m1.print();
    return 0;
}