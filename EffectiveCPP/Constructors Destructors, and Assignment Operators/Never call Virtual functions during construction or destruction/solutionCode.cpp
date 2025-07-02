#include <iostream>
#include <string>
using namespace std;

/*
    Assume you want to Log the data when ever the transaction is started by creating one of the 
    flavour of transaction.

    So you decided to log it in constrctor of the base class...
*/
class Transaction
{
    public:
        Transaction(std::string logData)
        {
            logTransaction(logData);
        }

        void logTransaction(std::string logData)
        {
            cout << logData << endl;
        }
};

class BuyTransaction: public Transaction
{
    public:
        BuyTransaction(): Transaction(constructLogString())
        {

        }

        static std::string constructLogString()
        {
            return string("[BuyTransaction]");
        }
};

int main()
{
    BuyTransaction buyTransaction;
    return 0;
}

