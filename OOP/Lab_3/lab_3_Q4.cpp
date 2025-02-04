#include <iostream>
#include <string>

using namespace std;

class Employee
{
public:
    string finName;
    string lastName;
    double monSalary = 0.0;

    void setMonSalary(double sal)
    {
        if (sal < 0)
        {
            monSalary = 0.0;
        }
        else
        {
            monSalary = sal;
        }
    }
};

int main()
{
    Employee e[2];
    double monSal[2];
    
    cout << "Enter monthly salary for employee 1: ";
    cin >> monSal[0];
    cout << "Enter monthly salary for employee 2: ";
    cin >> monSal[1];

    double yearlyInc[2];
    yearlyInc[0] = monSal[0] * 12;
    yearlyInc[1] = monSal[1] * 12;

    cout << "The yearly salary is: " << endl;
    cout << "Employee 1: " << yearlyInc[0] << endl;
    cout << "Employee 2: " << yearlyInc[1] << endl;

    double incentive[2];
    incentive[0] = (10 * monSal[0]) / 100;
    incentive[1] = (10 * monSal[1]) / 100;

    cout << "The salary after 10% increase is: " << endl;
    cout << "Employee 1: " << yearlyInc[0] + (incentive[0] * 12) << endl;
    cout << "Employee 2: " << yearlyInc[1] + (incentive[1] * 12) << endl;

    return 0;
}
