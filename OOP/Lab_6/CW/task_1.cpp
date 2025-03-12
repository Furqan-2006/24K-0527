#include <iostream>
#include <vector>
using namespace std;

class BankAccount
{
protected:
    int accountNum;
    double balance;
    bool frozen = false;

public:
    BankAccount(int accNum, double bal) : accountNum(accNum), balance(bal) {}
    virtual ~BankAccount() {}

    virtual void withdraw(double amount)
    {
        if (frozen)
        {
            cout << "Account " << accountNum << " is frozen. Withdrawal denied.\n";
            return;
        }
        if (balance >= amount)
        {
            balance -= amount;
            cout << "Withdrawn: $" << amount << " from Account " << accountNum << endl;
        }
        else
        {
            cout << "Insufficient balance!\n";
        }
    }

    virtual void deposit(double amount)
    {
        if (frozen)
        {
            cout << "Account " << accountNum << " is frozen. Deposit denied.\n";
            return;
        }
        balance += amount;
        cout << "Deposited: $" << amount << " to Account " << accountNum << endl;
    }

    virtual void getAccountDetails()
    {
        cout << "Account Number: " << accountNum << "\nBalance: $" << balance;
        if (frozen)
            cout << " (Frozen)";
        cout << endl;
    }

    void freezeAccount() { frozen = true; }
    void unfreezeAccount() { frozen = false; }
    double getBalance() { return balance; }
    void setBalance(double newBalance) { balance = newBalance; }
};

class SavingAccount : public BankAccount
{
    float interestRate;

public:
    SavingAccount(int accNum, double bal, float rate)
        : BankAccount(accNum, bal), interestRate(rate) {}

    void applyInterest()
    {
        double interest = balance * interestRate * (1.0 / 12) * 0.01;
        balance += interest;
        cout << "Interest Applied: $" << interest << " to Account " << accountNum << endl;
    }
};

class CheckingAccount : public BankAccount
{
    double overdraftLimit;

public:
    CheckingAccount(int accNum, double bal, double overdraft)
        : BankAccount(accNum, bal), overdraftLimit(overdraft) {}

    void withdraw(double amount) override
    {
        if (frozen)
        {
            cout << "Account " << accountNum << " is frozen. Withdrawal denied.\n";
            return;
        }
        if (balance - amount >= -overdraftLimit)
        {
            balance -= amount;
            cout << "Withdrawn: $" << amount << " from Account " << accountNum << endl;
        }
        else
        {
            cout << "Overdraft limit exceeded!\n";
        }
    }

    void setOverdraftLimit(double newLimit) { overdraftLimit = newLimit; }
};

class BusinessAccount : public BankAccount
{
    float corpTaxRate;

public:
    BusinessAccount(int accNum, double bal, float taxRate)
        : BankAccount(accNum, bal), corpTaxRate(taxRate) {}

    void deposit(double amount) override
    {
        if (frozen)
        {
            cout << "Account " << accountNum << " is frozen. Deposit denied.\n";
            return;
        }
        double tax = amount * corpTaxRate * 0.01;
        balance += (amount - tax);
        cout << "Deposited: $" << amount - tax << " (after tax) to Account " << accountNum << endl;
    }
};

class Customer
{
public:
    void deposit(BankAccount &acc, double amount)
    {
        acc.deposit(amount);
    }

    void withdraw(BankAccount &acc, double amount)
    {
        acc.withdraw(amount);
    }
};

class Employee
{
protected:
    string name;

public:
    Employee(string empName) : name(empName) {}
    virtual void performAction() = 0;
};

class Teller : public Employee
{
public:
    Teller(string empName) : Employee(empName) {}

    void performAction() override
    {
        cout << name << " (Teller) can deposit, withdraw, and freeze accounts.\n";
    }

    void deposit(BankAccount &acc, double amount)
    {
        acc.deposit(amount);
    }

    void withdraw(BankAccount &acc, double amount)
    {
        acc.withdraw(amount);
    }

    void freezeAccount(BankAccount &acc)
    {
        acc.freezeAccount();
        cout << "Teller " << name << " froze Account " << endl;
    }
};

class Manager : public Teller
{
public:
    Manager(string empName) : Teller(empName) {}

    void performAction() override
    {
        cout << name << " (Manager) can override limits, adjust balances, and unfreeze accounts.\n";
    }

    void overrideBalance(BankAccount &acc, double newBalance)
    {
        acc.setBalance(newBalance);
        cout << "Manager " << name << " set new balance: $" << newBalance << endl;
    }

    void adjustOverdraft(CheckingAccount &acc, double newLimit)
    {
        acc.setOverdraftLimit(newLimit);
        cout << "Manager " << name << " adjusted overdraft limit to $" << newLimit << endl;
    }

    void unfreezeAccount(BankAccount &acc)
    {
        acc.unfreezeAccount();
        cout << "Manager " << name << " unfroze Account\n";
    }
};

int main()
{
    vector<BankAccount *> accounts;
    accounts.push_back(new SavingAccount(1001, 5000, 1.2));
    accounts.push_back(new CheckingAccount(1002, 2000, 1000));
    accounts.push_back(new BusinessAccount(1003, 10000, 2));

    Teller teller("John");
    Manager manager("Alice");

    cout << "Initial Account Details:" << endl;
    for (auto acc : accounts)
    {
        acc->getAccountDetails();
        cout << "-------------------" << endl;
    }

    cout << "\nTeller Depositing $500 to Account 1001:" << endl;
    teller.deposit(*accounts[0], 500);

    cout << "\nManager Freezing Account 1002:" << endl;
    manager.freezeAccount(*accounts[1]);

    cout << "\nTrying to Withdraw from Frozen Account 1002:" << endl;
    teller.withdraw(*accounts[1], 100);

    cout << "\nManager Unfreezing Account 1002:" << endl;
    manager.unfreezeAccount(*accounts[1]);

    cout << "\nManager Adjusting Overdraft Limit of Account 1002 to $2000:" << endl;
    manager.adjustOverdraft(*static_cast<CheckingAccount *>(accounts[1]), 2000);

    cout << "\nFinal Account Details:" << endl;
    for (auto acc : accounts)
    {
        acc->getAccountDetails();
        cout << "-------------------" << endl;
    }

    for (auto acc : accounts)
    {
        delete acc;
    }

    return 0;
}
