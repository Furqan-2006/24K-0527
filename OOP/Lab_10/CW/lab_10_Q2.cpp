#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

struct Employee
{
    int id;
    string name;
    string designation;
    int yearsOfService;
};

Employee parseLine(const string &line)
{
    stringstream ss(line);
    string item;
    Employee emp;

    getline(ss, item, ',');
    emp.id = stoi(item);

    getline(ss, item, ',');
    emp.name = item;

    getline(ss, item, ',');
    emp.designation = item;

    getline(ss, item, ',');
    emp.yearsOfService = stoi(item);

    return emp;
}

string employeeToLine(const Employee &emp)
{
    return to_string(emp.id) + "," + emp.name + "," + emp.designation + "," + to_string(emp.yearsOfService);
}

void writeDummyData(const string &filename)
{
    ofstream file(filename);

    vector<Employee> employees = {
        {1, "Ali", "Manager", 3},
        {2, "Chawla", "Developer", 1},
        {3, "Sajid", "Manager", 1},
        {4, "Muneeb", "Tester", 4},
        {5, "Ayesha", "Manager", 5}};

    for (const auto &emp : employees)
    {
        file << employeeToLine(emp) << endl;
    }

    file.close();
}

vector<Employee> readAllEmployees(const string &filename)
{
    ifstream file(filename);
    vector<Employee> employees;
    string line;

    while (getline(file, line))
    {
        employees.push_back(parseLine(line));
    }

    file.close();
    return employees;
}

vector<Employee> findQualifiedManagers(const vector<Employee> &employees)
{
    vector<Employee> result;
    for (const auto &emp : employees)
    {
        if (emp.designation == "Manager" && emp.yearsOfService >= 2)
        {
            result.push_back(emp);
        }
    }
    return result;
}

void overwriteFile(const string &filename, const vector<Employee> &employees)
{
    ofstream file(filename);

    for (const auto &emp : employees)
    {
        file << employeeToLine(emp) << endl;
    }

    file.close();
}

void writeIncrementedData(const string &filename, const vector<Employee> &employees)
{
    ofstream file(filename);

    int newId = 1;
    for (const auto &emp : employees)
    {
        Employee updated = emp;
        updated.id = newId++;
        updated.yearsOfService += 1;
        file << employeeToLine(updated) << endl;
    }

    file.close();
}

int main()
{
    string filename = "employees.txt";

    writeDummyData(filename);

    vector<Employee> employees = readAllEmployees(filename);

    vector<Employee> qualifiedManagers = findQualifiedManagers(employees);

    cout << "Qualified Managers:\n";
    for (const auto &emp : qualifiedManagers)
    {
        cout << emp.id << ", " << emp.name << ", " << emp.designation << ", " << emp.yearsOfService << endl;
    }

    overwriteFile(filename, qualifiedManagers);

    writeIncrementedData(filename, qualifiedManagers);

    cout << "\nFile has been updated with incremented IDs and years of service.\n";

    return 0;
}
