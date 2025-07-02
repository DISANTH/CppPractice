#include<iostream>
using namespace std;

/*
    Assume you want to Log the data when ever the transaction is started by creating one of the 
    flavour of transaction.

    So you decided to log it in constrctor of the base class...
*/
class Transaction
{
    public:
        Transaction()
        {

            /* 
                Here trying to call the respective  logTransaction method 
                implimentation but the actual derived class object part construction not done 
                yet because the parent part should constructed before child.

                So calling this method will try to invoke the this class and Linker error if it's pure virtual function.
            */
            logTransaction(); 
        }

        virtual void logTransaction()
        {
            cout << "[Transaction]" << endl;
        }
};

class BuyTransaction: public Transaction
{
    public:
        BuyTransaction(): Transaction()
        {

        }

        virtual void logTransaction()
        {
            cout << "[BuyTransaction]" << endl;
        }
};

int main()
{
    BuyTransaction buyTransaction;
    return 0;
}

