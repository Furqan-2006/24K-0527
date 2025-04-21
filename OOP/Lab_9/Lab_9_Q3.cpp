#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int id;
    float salary;

public:
    virtual void getData() {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Salary: ";
        cin >> salary;
    }

    virtual void displayData() const {
        cout << "Name: " << name << "\nID: " << id << "\nSalary: " << salary << endl;
    }

    virtual void bonus() const {
        cout << "Generic Person Bonus: " << salary * 0.05 << endl;
    }

    virtual ~Person() {}
};

class Admin : virtual public Person {
public:
    void getData() override {
        cout << "\n[Admin Data]\n";
        Person::getData();
    }

    void displayData() const override {
        cout << "\n[Admin Info]\n";
        Person::displayData();
    }

    void bonus() const override {
        cout << "Admin Bonus: " << salary * 0.10 << endl;
    }
};

class Account : virtual public Person {
public:
    void getData() override {
        cout << "\n[Account Data]\n";
        Person::getData();
    }

    void displayData() const override {
        cout << "\n[Account Info]\n";
        Person::displayData();
    }

    void bonus() const override {
        cout << "Account Bonus: " << salary * 0.08 << endl;
    }
};

class Master : public Admin, public Account {
public:
    void getData() override {
        cout << "\n[Master Data]\n";
        Person::getData(); 
    }

    void displayData() const override {
        cout << "\n[Master Info]\n";
        Person::displayData();
    }

    void bonus() const override {
        cout << "Master Bonus: " << salary * 0.15 << endl;
    }
};

int main() {
    Person* p;

    Admin admin;
    Account account;
    Master master;

    cout << "=== Admin ===\n";
    p = &admin;
    p->getData();
    p->displayData();
    p->bonus();

    cout << "\n=== Account ===\n";
    p = &account;
    p->getData();
    p->displayData();
    p->bonus();

    cout << "\n=== Master ===\n";
    p = &master;
    p->getData();
    p->displayData();
    p->bonus();

    return 0;
}
