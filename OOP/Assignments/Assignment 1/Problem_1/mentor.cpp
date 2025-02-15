#include "mentor.hpp"

void Mentor::assignLearner(Student &s)
{
    if (assignedLearners.size() >= maxLearners)
    {
        cout << "Cannot Assign Learners! Max Limit Reached!" << endl;
    }
    else
    {
        assignedLearners.push_back(&s);
        s.registerForMentorship(this);
        cout << s.getStudentName() << " assigned to Mentor " << getMentorName() << endl;
    }
}

void Mentor::removeLearner(Student &s)
{
    auto it = remove(assignedLearners.begin(), assignedLearners.end(), &s);
    if (it != assignedLearners.end())
    {
        assignedLearners.erase(it);
        s.mentorAssigned = nullptr;
        cout << s.getStudentName() << " removed from Mentor " << getMentorName() << endl;
    }
}

void Mentor::viewLearners()
{
    if (assignedLearners.empty())
    {
        cout << "No assigned learners." << endl;
        return;
    }

    cout << "Learners assigned to " << mentorName << ":\n";
    for (Student *s : assignedLearners)
    {
        cout << "- " << s->getStudentName() << endl;
    }
}

void Mentor::provideGuidance(string guidance)
{
    if (assignedLearners.empty())
    {
        cout << "No students to provide guidance!" << endl;
        return;
    }

    for (Student *student : assignedLearners)
    {
        bool guidanceProvided = false;
        cout << "+ " << student->getStudentName() << " (Interests: ";
        for (const string &sport : student->sportInterest)
        {
            cout << sport << " ";
        }
        cout << ")\n";

        for (const string &interest : student->sportInterest)
        {
            if (find(sportExpertise.begin(), sportExpertise.end(), interest) != sportExpertise.end())
            {

                cout << "  -> Guidance for " << interest << ": " << guidance << endl;
                guidanceProvided = true;
            }
        }

        if (!guidanceProvided)

        {
            cout << "  -> No direct expertise in the student's interests. General guidance: " << guidance << endl;
        }
    }
}