#include <iostream>
#include <string>
using namespace std;

static int srnum = 0;

class Wallet
{
private:
    const int srno = ++srnum;
    double balance;

    double depositLimit = 5000000;
    double depositedAmount;

    double withdrawLimit = 5000000;
    double withdrawnAmount;

public:
    Wallet() : balance(0), depositedAmount(0), withdrawnAmount(0) {}

    bool topUp(double amount)
    {
        if (amount <= 0)
        {
            cerr << "Invalid top-up amount: " << amount << "\nAmount must be positive.\n";
            return false;
        }
        if (depositedAmount + amount > depositLimit)
        {
            cerr << "Deposit failed: Daily limit of PKR " << depositLimit << " exceeded.\n";
            return false;
        }

        balance += amount;
        depositedAmount += amount;
        cout << "Deposited: PKR " << amount << endl;
        return true;
    }

    bool withdraw(double amount)
    {
        if (amount <= 0)
        {
            cerr << "Invalid withdrawal amount: " << amount << "\nAmount must be positive.\n";
            return false;
        }
        if (withdrawnAmount + amount > withdrawLimit)
        {
            cerr << "Withdrawal failed: Daily limit of PKR " << withdrawLimit << " exceeded.\n";
            return false;
        }
        if (balance < amount)
        {
            cerr << "Withdrawal failed: Insufficient balance.\n";
            return false;
        }

        balance -= amount;
        withdrawnAmount += amount;
        cout << "Withdrawn: PKR " << amount << endl;
        return true;
    }

    void showBalance() const
    {
        cout << "Wallet [" << srno << "] Balance: PKR " << balance << endl;
    }
};

class User
{
private:
    string userID;
    string name;
    Wallet wallet;

public:
    User(string id, string n) : userID(id), name(n) {}

    void deposit(double amount)
    {
        wallet.topUp(amount);
    }

    void withdraw(double amount)
    {
        wallet.withdraw(amount);
    }

    void checkBalance() const
    {
        cout << "User: " << name << " (" << userID << ")\n";
        wallet.showBalance();
    }
};

int main()
{
    User u1("U001", "Ali");
    User u2("U002", "Fatima");

    u1.deposit(2000000);
    u1.withdraw(500000);
    u1.withdraw(2500000);
    u1.checkBalance();

    cout << "\n";

    u2.deposit(6000000);
    u2.deposit(4000000);
    u2.withdraw(1000000);
    u2.checkBalance();

    return 0;
}
