#include <iostream>
using namespace std;

class Student
{
private:
    const int roll_no;

public:
    Student(int roll) : roll_no(roll) {}

    void display() const
    {
        cout << "Student Roll Number: " << roll_no << endl;
    }
};

int main()
{
    int roll;
    cout << "Enter roll number: ";
    cin >> roll;

    Student s(roll);
    s.display();

    return 0;
}
