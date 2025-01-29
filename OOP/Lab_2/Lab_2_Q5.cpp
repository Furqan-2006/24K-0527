#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Person
{
    string id;
    string name;
};

bool cmpByID(Person &a, Person &b)
{
    return a.id < b.id;
}

bool cmpByFirstChar(Person &a, Person &b)
{
    return a.name[0] < b.name[0];
}

void printPersons(vector<Person> &persons)
{
    for (const auto &p : persons)
    {
        cout << "ID: " << p.id << ", NAME: " << p.name << endl;
    }
}

int main()
{
    int N;
    cout << "Enter the number of persons: ";
    cin >> N;
    vector<Person> persons(N);

    for (int i = 0; i < N; i++)
    {
        cout << "Enter ID for person " << i + 1 << ": ";
        cin >> persons[i].id;
        cout << "Enter Name for person " << i + 1 << ": ";
        cin >> persons[i].name;
    }

    sort(persons.begin(), persons.end(), cmpByID);
    cout << "Sort by ID: " << endl;
    printPersons(persons);

    sort(persons.begin(), persons.end(), cmpByFirstChar);
    cout << "Sort by first character of name: " << endl;
    printPersons(persons);

    return 0;
}
