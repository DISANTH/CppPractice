#include<iostream>
using namespace std;

class Parent
{
    public:
        int x{3};

        void printAll()
        {
            cout << "x :: " << x << " y : "<< y << " z :: " << z <<  endl;
        }

    protected:
        int y{2};
        /*
        y: {
            private to outside world
            public to subclass
        }
        */
    private:
        int z{1};

        /*
        z: {
            private to outside world
            private to subclass
        }
        */
};

class Child1: public Parent
{
    /*
        public inheritance
            parent public will be public - no acess
            parent protected will be public here - no acess
            parent private will be private - no acess
    */
    public: 
        void printAll()
        {
            cout << "x :: " << x << " y : "<< y << " z :: " << z <<  endl;
        }
};

class Child2: protected Parent
{
    /*
        protected inheritance
            parent public will be public - no acess
            parent protected will be private here - no acess
            parent private will be private - no acess
    */
};

class Child3: private Parent
{
     /*
        private inheritance
            parent private will be public - no acess
            parent private will be private here - no acess
            parent private will be private - no acess
    */
};

int main()
{
    Child1 instanceOfParent;
    //cout << instanceOfParent.x << instanceOfParent.y <<  endl;
    instanceOfParent.printAll();
    return 0;
}


