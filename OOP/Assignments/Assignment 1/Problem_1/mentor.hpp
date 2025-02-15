#ifndef MENTOR_HPP
#define MENTOR_HPP

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "student.hpp"

using namespace std;

class Mentor
{
private:
    string mentorID;
    string mentorName;
    int maxLearners; 

public:
    vector<string> sportExpertise;
    vector<Student *> assignedLearners;

    Mentor(string id, string n, int maxL) : mentorID(id), mentorName(n), maxLearners(maxL) {}

    string getMentorName() { return mentorName; }
    string getMentorID() { return mentorID; }

    void assignLearner(Student &s);
    void removeLearner(Student &s);
    void viewLearners();
    void provideGuidance(string guidance);
};

#endif