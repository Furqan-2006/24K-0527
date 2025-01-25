#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    string name;
    float marks[5];
    float avgMarks;
    cout << "Input name and marks of five Subjects: " << endl;
    cin >> name >> marks[0] >> marks[1] >> marks[2] >> marks[3] >> marks[4];
    avgMarks = (marks[0] + marks[1] + marks[2] + marks[3] + marks[4]);

    cout << "Student Name: " << name << endl;
    cout << "Test Scores: " << fixed << setprecision(2) << marks[0] << " " << marks[1] << " " << marks[2] << " " << marks[3] << " " << marks[4] << " " << endl;
    cout << "Average test Scores: " << avgMarks << endl;
    return 0;
}