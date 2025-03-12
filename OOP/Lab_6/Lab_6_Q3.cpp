#include <iostream>
using namespace std;

class Student
{
    int ID;
    string name;

public:
    Student(int id, string n) : ID(id), name(n) {}
    void getStudentDetails()
    {
        cout << "Student ID: " << ID << endl
             << "Student Name: " << name << endl;
    }
};
class Marks : public Student
{
protected:
    int marks_oop, marks_pf, marks_ds, marks_db;

public:
    Marks(int oop, int pf, int ds, int db, int id, string n)
        : marks_oop(oop), marks_db(db), marks_ds(ds), marks_pf(pf), Student(id, n) {}

    void getMarks()
    {
        cout << "OOP marks: " << marks_oop << endl
             << "PF marks: " << marks_pf << endl
             << "DS marks: " << marks_ds << endl
             << "DB marks: " << marks_db << endl;
    }
};
class Result : public Marks
{
protected:
    int total_marks;
    double avg_marks;

public:
    Result(int oop, int pf, int ds, int db, int id, string n)
        : Marks(oop, pf, ds, db, id, n)
    {
        total_marks = oop + pf + db + ds;
        avg_marks = total_marks / 4;
    }

    void display()
    {
        cout << "Total Marks: " << total_marks << endl
             << "Average marks: " << avg_marks << endl;
    }
};

int main()
{
    Result s1(45, 48, 44, 49, 345328, "Furqan");

    s1.getStudentDetails();
    s1.getMarks();
    s1.display();

    return 0;
}