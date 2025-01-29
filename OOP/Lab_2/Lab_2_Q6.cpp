#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Subject
{
    string subjectName;
};

struct Student
{
    int studentID;
    vector<Subject> subjects;
};

int main()
{

    vector<Student> students;

    Student student1;
    student1.studentID = 101;
    student1.subjects.push_back({"Mathematics"});
    student1.subjects.push_back({"Physics"});
    student1.subjects.push_back({"Chemistry"});

    students.push_back(student1);

    Student student2;
    student2.studentID = 102;
    student2.subjects.push_back({"Biology"});
    student2.subjects.push_back({"English"});

    students.push_back(student2);

    for (const auto &student : students)
    {
        cout << "Student ID: " << student.studentID << endl;
        cout << "Subjects: ";
        for (const auto &subject : student.subjects)
        {
            cout << subject.subjectName << " ";
        }
        cout << endl;
    }

    return 0;
}
