#include<iostream>
using namespace std;

/*
    Method Overriding
    Late Binding
    Runtime Polymorphsim
*/

// class Parent{
//     public:
//         virtual void Print() // You are telling child classes that you can override this behaviour....
//         {
//             cout << "Parent  Print Method" <<  endl;
//         }

//         void show()
//         {
//             cout << "Parent show Method" <<  endl;
//         }
// };

// class Child: public Parent
// {
//     void Print()
//     {
//         cout << "Child Print Method" <<  endl;
//     }

//     void show()
//     {
//         cout << "Child show Method" <<  endl;
//     }
// };




class BasciCamera
{
    public:
        virtual void capture() = 0; // {there is no definition}
};


class ModernCamera : public BasciCamera
{
    public:
        void capture()
        {
            cout << "ModernCamera :: capture" << endl;
        }
};

class TraditionalCamera : public BasciCamera
{
    public:
        void capture()
        {
            cout << "TraditionalCamera :: capture" << endl;
        }
};

void captureImage(BasciCamera& tCamera) // base class reference can be referenced to child class instance....
{
    tCamera.capture(); // Code to interface principle
}

int main()
{
    TraditionalCamera mCamera;
    captureImage(mCamera);
    return 0;
}