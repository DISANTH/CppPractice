#include<iostream>
using namespace std;

class ClassA
{
	public:
		int a;
		virtual void display()
		{
		}
};

class ClassB: virtual public ClassA
{
	public:
		int b;
		void display()
		{
		}
};

int main()
{
	ClassA a;
	ClassB b;
	cout << "Sizeof classA :: " << sizeof(a) << endl;
	cout << "sizeof classB :: " << sizeof(b) << endl;
        return 0;
}
