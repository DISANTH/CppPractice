#include <iostream>

using namespace std;

class Car
{
    public:
        string brand;
        int year;
}

class BankAccount
{
    private:
        double amount;
        string name;
        string accNo; // Disanth transactions earlier, accNo  --> transactionID [Database]
        int savedPin;

    string getAmount(BankAccount* this, int pin) // 
    {
        // UPI PIN
        try
        {
            if(pin !== this->savedPin)
            {
                throw InvalidLogin("Entered Pin is not matching");
            }
        }
        catch(Exception &e)
        {
            throw InvalidLogin("Entered Pin is not matching");
        }

        return this->amount;
    }

    bool setAmount(double deposited)
    {
        // check password (authentication)
        // Weather he deposited or not // Successful
        // amount += 
    }

    bool setName(string newName, vector<Document> proofDocuments)
    {

    }

    /**
        This is not making sense to give setter for account number
     */
    // bool setAccNo(string newAccNo)
    // {

    // }
};

int main()
{

    BankAccount *disanth = new BankAccount; // Heap
    BankAccount prsanna; // Stack

    prsanna.getAmount(123456); // ==> getAmount(&prasanna, 12345);


    Car myCar;
    myCar.brand = "Benz";
    myCar.year = 2018;

    myCar.brand = "Mahindra";
    myCar.year = 2025;

    cout << "Brand :: " << myCar.brand << " , Year: " << myCar.year << std::endl;
    return 0;
}