#include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
    string ID;

public:
    Person(string id = "") : ID(id) {}
    virtual void getData()
    {
        cout << "Enter Employee ID: ";
        cin >> ID;
    }

    virtual void displayData() const
    {
        cout << "Employee ID: " << ID << endl;
    }
    virtual ~Person() {}
};
class Admin : public Person
{
    string name;
    double mSal;

public:
    Admin(string id = "", string n = "", double sal = 0) : Person(id), name(n), mSal(sal) {}

    void getData() override
    {
        Person::getData();
        cout << "Enter Admin Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Monthly Salary: ";
        cin >> mSal;
    }
    void displayData() const override
    {
        Person::displayData();
        cout << "Admin Name: " << name << "\nMonthly Salary: " << mSal << "\nAnnual Bonus: " << bonus() << endl;
    }
    double bonus() const
    {
        return mSal * 12 * 0.05;
    }
};
class Accounts : public Person
{
    string name;
    double mSal;

public:
    Accounts(string id = "", string n = "", double sal = 0) : Person(id), name(n), mSal(sal) {}

    void getData() override
    {
        Person::getData();
        cout << "Enter Accounts Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Monthly Salary: ";
        cin >> mSal;
    }
    void displayData() const override
    {
        Person::displayData();
        cout << "Accounts Name: " << name << "\nMonthly Salary: " << mSal << "\nAnnual Bonus: " << bonus() << endl;
    }
    double bonus() const
    {
        return mSal * 12 * 0.05;
    }
};

int main()
{
    const int SIZE = 2;
    Person *employees[SIZE];

    employees[0] = new Admin();
    employees[1] = new Accounts();

    cout << "Enter Employees details: " << endl;
    for (int i = 0; i < SIZE; i++)
    {
        cout << "Employee " << i + 1 << ":\n";
        employees[i]->getData();
    }

    cout << "Employees details: " << endl;
    for (int i = 0; i < SIZE; i++)
    {
        cout << "Employee " << i + 1 << ":\n";
        employees[i]->displayData();
    }

    return 0;
}