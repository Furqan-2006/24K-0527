#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
class Mentor;


class Student
{
private:
    string studentID;
    string studentName;
    int age;

public:
    vector<string> sportInterest = {};
    Mentor *mentorAssigned;

    Student(string id, string n, int a) : studentID(id), studentName(n), age(a), mentorAssigned(nullptr) {}

    string getStudentName() { return studentName; }
    string getStudentID() { return studentID; }
    int getAge() { return age; }

    void registerForMentorship(Mentor *m);

    void viewMentorDetails();
    
    void updateSportsInterest(string sports);
};

#endif