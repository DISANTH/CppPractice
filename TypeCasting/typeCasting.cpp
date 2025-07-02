#include <iostream>
#include <typeinfo>

using namespace std;


// /*
//     1. dynamic_cast --> 
//     2. static_cast --> 
//     3. const_cast --> 
//     4. reinterpret_cast --> 
// */


class CDummy {
    int i,j; // 8 + 8
};

class CAddition {
    int x,y; // 4 + 4
  public:
    CAddition (int a, int b) { x=a; y=b; }

    // CAddition(const CDummy& cDummy)
    // {
    //     x = 5;
    //     y = 6;
    // }

    int result() { return x+y;}
};

int main () {

    CDummy d;
    CAddition d1(8,9);

    CAddition d2 = d1; // s1

    CAddition padd = static_cast<CAddition> (d);  // s2

    int a = static_cast<int>(10.5);

    cout << a << endl;

    //cout << padd->result() << endl;

    return 0;
}



// class Data
// {
//     private:
//         int x;
//     public:
//         Data(int _x): x(_x)
//         {

//         }

//         bool isValid() const
//         {
//             return x > 10;
//         }
// };

// int validateData(const Data& d)
// {
//     return d.isValid();
// }

// int main()
// {
//     Data d(2);

//     int a = 10.68989;

//     Data d2 = 2 ; // Data(2); // Creating + initilizing ==> Copy Constructor.
//     Data lValData(20);
//     cout << validateData(lValData) << endl;
//     cout << validateData(Data(40)) << endl;




//     return 0;
// }