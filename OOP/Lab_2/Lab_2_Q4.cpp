#include <iostream>
using namespace std;

struct Employee
{
    int empID;
    string empName;
    int salary;
};

struct Organization
{
    string orgName;
    string orgNum;
    Employee emp;
};

int main()
{
    Organization org;
    org.orgName = "NU-FAST";
    org.orgNum = "NUFAST123ABC";
    org.emp.empID = 127;
    org.emp.empName = "Linus Sebastian";
    org.emp.salary = 400000;

    cout << "The size of structure organization is: " << sizeof(Organization) << endl;
    cout << "Organization Name: " << org.orgName << endl;
    cout << "Organization Number: " << org.orgNum << endl;
    cout << "Employee ID: " << org.emp.empID << endl;
    cout << "Employee name: " << org.emp.empName << endl;
    cout << "Employee salary: " << org.emp.salary << endl;

    return 0;
}
