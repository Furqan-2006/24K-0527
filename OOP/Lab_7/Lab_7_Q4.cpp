#include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
    string name, address, phoneNumber, email;

public:
    Person(string n, string addr, string phone, string mail)
        : name(n), address(addr), phoneNumber(phone), email(mail) {}

    virtual void displayInfo()
    {
        cout << "Name: " << name << "\nAddress: " << address
             << "\nPhone: " << phoneNumber << "\nEmail: " << email << endl;
    }
};

class Student : public Person
{
private:
    string coursesEnrolled;
    double GPA;
    int enrollmentYear;

public:
    Student(string n, string addr, string phone, string mail,
            string courses, double gpa, int year)
        : Person(n, addr, phone, mail), coursesEnrolled(courses), GPA(gpa), enrollmentYear(year) {}

    void displayInfo() override
    {
        Person::displayInfo();
        cout << "Courses Enrolled: " << coursesEnrolled
             << "\nGPA: " << GPA << "\nEnrollment Year: " << enrollmentYear << endl;
    }
};

class Professor : public Person
{
private:
    string department, coursesTaught;
    double salary;

public:
    Professor(string n, string addr, string phone, string mail,
              string dept, string courses, double sal)
        : Person(n, addr, phone, mail), department(dept), coursesTaught(courses), salary(sal) {}

    void displayInfo() override
    {
        Person::displayInfo();
        cout << "Department: " << department
             << "\nCourses Taught: " << coursesTaught
             << "\nSalary: $" << salary << endl;
    }
};

class Staff : public Person
{
private:
    string department, position;
    double salary;

public:
    Staff(string n, string addr, string phone, string mail,
          string dept, string pos, double sal)
        : Person(n, addr, phone, mail), department(dept), position(pos), salary(sal) {}

    void displayInfo() override
    {
        Person::displayInfo();
        cout << "Department: " << department
             << "\nPosition: " << position
             << "\nSalary: $" << salary << endl;
    }
};

class Course
{
private:
    string courseId, courseName, instructor;
    int credits;
    string schedule;

public:
    Course(string id, string name, string instr, int cr, string sched)
        : courseId(id), courseName(name), instructor(instr), credits(cr), schedule(sched) {}

    void displayCourse()
    {
        cout << "Course ID: " << courseId
             << "\nCourse Name: " << courseName
             << "\nInstructor: " << instructor
             << "\nCredits: " << credits
             << "\nSchedule: " << schedule << endl;
    }
};

int main()
{
    Student s1("Alice Johnson", "123 Elm St", "555-1234", "alice@email.com", "Math, Science", 3.8, 2022);
    Professor p1("Dr. Smith", "456 Oak St", "555-5678", "smith@email.com", "Computer Science", "C++ Programming", 85000);
    Staff st1("John Doe", "789 Pine St", "555-9012", "johndoe@email.com", "Admin", "Clerk", 45000);
    Course c1("CS101", "Introduction to Programming", "Dr. Smith", 4, "MWF 10:00-11:00 AM");

    cout << "\n--- Student Info ---\n";
    s1.displayInfo();
    cout << "\n--- Professor Info ---\n";
    p1.displayInfo();
    cout << "\n--- Staff Info ---\n";
    st1.displayInfo();
    cout << "\n--- Course Info ---\n";
    c1.displayCourse();

    return 0;
}
