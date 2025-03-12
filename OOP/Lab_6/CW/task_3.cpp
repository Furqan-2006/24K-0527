#include <iostream>
#include <vector>
using namespace std;

class Employee
{
protected:
    int id;
    string name;

public:
    Employee(int empId, const string &empName) : id(empId), name(empName) {}
    virtual ~Employee() {}
    virtual void showInfo() const { cout << "Employee ID: " << id << ", Name: " << name << endl; }
};

class IOrderTaker
{
public:
    virtual void takeOrder(const string &order) = 0;
    virtual ~IOrderTaker() {}
};

class IOrderPreparer
{
public:
    virtual void prepareOrder(const string &order) = 0;
    virtual ~IOrderPreparer() {}
};

class IBiller
{
public:
    virtual void generateBill(double amount) = 0;
    virtual ~IBiller() {}
};

class Waiter : public Employee, public IOrderTaker
{
public:
    Waiter(int empId, const string &empName) : Employee(empId, empName) {}
    void takeOrder(const string &order) override
    {
        cout << "Waiter " << name << " took order: " << order << endl;
    }
};

class Chef : public Employee, public IOrderPreparer
{
public:
    Chef(int empId, const string &empName) : Employee(empId, empName) {}
    void prepareOrder(const string &order) override
    {
        cout << "Chef " << name << " is preparing: " << order << endl;
    }
};

class Cashier : public Employee, public IBiller
{
public:
    Cashier(int empId, const string &empName) : Employee(empId, empName) {}
    void generateBill(double amount) override
    {
        cout << "Cashier " << name << " generated bill: $" << amount << endl;
    }
};

class Manager : public Employee, public IOrderTaker, public IBiller
{
public:
    Manager(int empId, const string &empName) : Employee(empId, empName) {}
    void takeOrder(const string &order) override
    {
        cout << "Manager " << name << " took order: " << order << endl;
    }
    void generateBill(double amount) override
    {
        cout << "Manager " << name << " generated bill: $" << amount << endl;
    }
};

class Menu
{
protected:
    string menuName;

public:
    Menu(const string &name) : menuName(name) {}
    virtual ~Menu() {}
    virtual double calculateTotal(double basePrice) const = 0;
};

class FoodMenu : public Menu
{
public:
    FoodMenu() : Menu("Food Menu") {}
    double calculateTotal(double basePrice) const override
    {
        return basePrice * 1.1;
    }
};

class BeverageMenu : public Menu
{
public:
    BeverageMenu() : Menu("Beverage Menu") {}
    double calculateTotal(double basePrice) const override
    {
        return basePrice * 1.15;
    }
};

int main()
{
    vector<Employee *> employees;
    employees.push_back(new Waiter(1, "Alice"));
    employees.push_back(new Chef(2, "Bob"));
    employees.push_back(new Cashier(3, "Charlie"));
    employees.push_back(new Manager(4, "Dave"));

    for (auto emp : employees)
    {
        emp->showInfo();
    }

    Waiter *waiter = dynamic_cast<Waiter *>(employees[0]);
    if (waiter)
        waiter->takeOrder("Burger and Coke");

    Chef *chef = dynamic_cast<Chef *>(employees[1]);
    if (chef)
        chef->prepareOrder("Burger");

    Cashier *cashier = dynamic_cast<Cashier *>(employees[2]);
    if (cashier)
        cashier->generateBill(15.0);

    Manager *manager = dynamic_cast<Manager *>(employees[3]);
    if (manager)
    {
        manager->takeOrder("Pasta");
        manager->generateBill(25.0);
    }

    for (auto emp : employees)
        delete emp;

    return 0;
}
