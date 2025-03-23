#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Account
{
protected:
    int accNum;
    double balance;
    string accHolderName;
    vector<string> transactionHistory;

public:
    Account(int num, string name, double initialBalance = 0.0)
    {
        accNum = num;
        accHolderName = name;
        balance = initialBalance;
        transactionHistory.push_back("Account created with balance: $" + to_string(balance));
    }

    virtual void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            string transaction = "Deposited: $" + to_string(amount);
            transactionHistory.push_back(transaction);
            cout << transaction << " to Account " << accNum << endl;
        }
        else
        {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    virtual void withdraw(double amount)
    {
        if (amount > 0 && balance >= amount)
        {
            balance -= amount;
            string transaction = "Withdrawn: $" + to_string(amount);
            transactionHistory.push_back(transaction);
            cout << transaction << " from Account " << accNum << endl;
        }
        else
        {
            cout << "Insufficient funds or invalid withdrawal amount!" << endl;
        }
    }

    virtual void calculateInterest() {}

    virtual void printStatement()
    {
        cout << "\n--- Bank Statement ---\n";
        cout << "Account Number: " << accNum << endl
             << "Account Holder Name: " << accHolderName << endl
             << "Current Balance: $" << balance << endl;
        cout << "Transaction History:" << endl;
        for (const string &transaction : transactionHistory)
        {
            cout << " - " << transaction << endl;
        }
        cout << "----------------------\n";
    }

    void getAccountInfo()
    {
        cout << "Account Number: " << accNum << ", Holder: " << accHolderName << ", Balance: $" << balance << endl;
    }

    virtual ~Account() {}
};

class SavingsAccount : public Account
{
private:
    double interestRate;
    double minimumBalance;

public:
    SavingsAccount(int num, string name, double initialBalance, double rate, double minBal)
        : Account(num, name, initialBalance), interestRate(rate), minimumBalance(minBal) {}

    void calculateInterest() override
    {
        double interest = balance * (interestRate / 100);
        balance += interest;
        string transaction = "Interest added: $" + to_string(interest);
        transactionHistory.push_back(transaction);
        cout << transaction << " to Savings Account " << accNum << endl;
    }

    void withdraw(double amount) override
    {
        if (balance - amount >= minimumBalance)
        {
            Account::withdraw(amount);
        }
        else
        {
            cout << "Cannot withdraw! Minimum balance of $" << minimumBalance << " required." << endl;
        }
    }
};

class CheckingAccount : public Account
{
public:
    CheckingAccount(int num, string name, double initialBalance)
        : Account(num, name, initialBalance) {}

    void withdraw(double amount) override
    {
        if (balance >= amount)
        {
            Account::withdraw(amount);
        }
        else
        {
            cout << "Overdraft not allowed in Checking Account " << accNum << endl;
        }
    }
};

class FixedDepositAccount : public Account
{
private:
    double fixedInterestRate;
    int maturityDate;

public:
    FixedDepositAccount(int num, string name, double initialBalance, double rate, int maturity)
        : Account(num, name, initialBalance), fixedInterestRate(rate), maturityDate(maturity) {}

    void calculateInterest() override
    {
        double interest = balance * (fixedInterestRate / 100);
        string transaction = "Fixed Deposit Interest (not added until maturity): $" + to_string(interest);
        transactionHistory.push_back(transaction);
        cout << transaction << endl;
    }

    void withdraw(double amount) override
    {
        cout << "Withdrawals are not allowed from Fixed Deposit Account until maturity!" << endl;
    }
};

int main()
{
    SavingsAccount savings(1001, "Alice", 1500, 3.5, 500);
    CheckingAccount checking(1002, "Bob", 1000);
    FixedDepositAccount fixedDeposit(1003, "Charlie", 5000, 5.0, 12);

    cout << "\n--- Savings Account ---\n";
    savings.deposit(500);
    savings.withdraw(1200);
    savings.calculateInterest();
    savings.printStatement();

    cout << "\n--- Checking Account ---\n";
    checking.deposit(300);
    checking.withdraw(200);
    checking.printStatement();

    cout << "\n--- Fixed Deposit Account ---\n";
    fixedDeposit.calculateInterest();
    fixedDeposit.withdraw(1000);
    fixedDeposit.printStatement();

    return 0;
}
