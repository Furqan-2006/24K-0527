#include <iostream>
using namespace std;

class Account
{
    string userName;
    long int accountNum;
    double balance = 0.0;

public:
    Account(double bal, long int acc, string n) : balance(bal), accountNum(acc), userName(n) {}

    void credit(float cur)
    {
        balance += cur;
    }

    void debit(float cur)
    {
        if (cur > balance)
        {
            cout << "Insufficient Balance!" << endl;
        }
        else
        {
            balance -= cur;
        }
    }

    string getUserName()
    {
        return userName;
    }

    long int getAccountNum()
    {
        return accountNum;
    }

    double getBalance()
    {
        return balance;
    }
};

int main()
{
    Account A1(1000, 123456780, "Furqan");

    while (1)
    {
        cout << "\nChoose one of the following: " << endl;
        cout << "1. Credit" << endl;
        cout << "2. Debit" << endl;
        cout << "3. Balance Inquiry" << endl;
        cout << "4. Exit" << endl;

        int option;
        cout << "Option: ";
        cin >> option;

        switch (option)
        {
        case 1:
        {
            double amount;
            cout << "Enter the Amount: ";
            cin >> amount;
            A1.credit(amount);
            break;
        }
        case 2:
        {
            double amount;
            cout << "Enter the Amount: ";
            cin >> amount;
            A1.debit(amount);
            break;
        }
        case 3:
            cout << "USER NAME: " << A1.getUserName() << endl;
            cout << "ACCOUNT #: " << A1.getAccountNum() << endl;
            cout << "BALANCE: " << A1.getBalance() << endl;
            break;
        case 4:
            return 0;
        default:
            cout << "Invalid Option!" << endl;
            break;
        }
    }

    return 0;
}
