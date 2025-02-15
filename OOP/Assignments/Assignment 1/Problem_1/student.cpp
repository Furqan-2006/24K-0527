#include "student.hpp"
#include "mentor.hpp"

void Student::registerForMentorship(Mentor *m) { mentorAssigned = m; }
void Student::viewMentorDetails()
{
    if (mentorAssigned != nullptr)
    {
        cout << "Mentor ID: " << mentorAssigned->getMentorID() << endl;
        cout << "Mentor Name: " << mentorAssigned->getMentorName() << endl;
    }
    else
    {
        cout << "No mentor assigned yet." << endl;
    }
}

void Student::updateSportsInterest(string sports) { sportInterest.push_back(sports); }
