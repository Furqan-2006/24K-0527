// *-*-*-*-*-*  MENTORSHIP SYSTEM  *-*-*-*-*-*

// !! To run these problem type the following in the termoinal or command prompt
// ** g++ main.cpp mentor.cpp student.cpp -o mentorSystem
// ** ./mentorSystem

//?? MAKE SURE TO OPEN "CMD" IN SAME DIRECTORY AS THE PROGRAM FILES

#include "mentor.hpp"
#include "student.hpp"

using namespace std;

class Skill
{
private:
    string skillID;
    string skillName;

public:
    string skillDescription;

    Skill(string id, string n) : skillID(id), skillName(n) {}

    string getSkillName() { return skillName; }
    string getSkillID() { return skillID; }

    void showSkillDetails()
    {
        cout << "Skill ID: " << getSkillID() << endl;
        cout << "Skill Name: " << getSkillName() << endl;
        cout << "Skill Description: " << skillDescription << endl;
    }

    void updateSkillDescription(string newDescription)
    {
        skillDescription = newDescription;
    }
};

class Sport
{
private:
    string sportsID;
    string sportsName;

public:
    string description;
    vector<Skill *> skillRequired;

    Sport(string id, string n) : sportsID(id), sportsName(n) {}

    string getSportName() { return sportsName; }
    string getSportID() { return sportsID; }

    void addSkill(Skill &s)
    {
        skillRequired.push_back(&s);
        cout << s.getSkillName() << " is added to the sport " << getSportName() << endl;
    }

    void removeSkill(Skill &s)
    {
        auto it = remove(skillRequired.begin(), skillRequired.end(), &s);
        if (it != skillRequired.end())
        {
            skillRequired.erase(it);
            cout << s.getSkillName() << " removed from " << getSportName() << endl;
        }
    }
};

int main()
{

    Mentor mentor1("M-1", "Coach Alex", 3);
    Mentor mentor2("M-2", "Aslam Saleem", 2);

    Student student1("S-1", "Ahmed Ali", 19);
    Student student2("S-2", "Abu Bakr", 18);
    Student student3("S-3", "Furqan", 18);

    Sport sport1("sp-1", "Football");
    Sport sport2("sp-2", "Baseball");

    Skill skill1("sk-1", "dribbling");
    Skill skill2("sk-2", "shooting");
    Skill skill3("sk-3", "block");
    Skill skill4("sk-4", "The Nutmeg");
    Skill skill5("sk-5", "Body Control");

    student1.updateSportsInterest("Football");
    student2.updateSportsInterest("Baseball");
    student3.updateSportsInterest("Football");

    // Assigning values

    mentor1.sportExpertise.push_back("Baseball");
    mentor2.sportExpertise.push_back("Football");

    mentor1.assignLearner(student2);
    mentor2.assignLearner(student1);
    mentor2.assignLearner(student3);

    mentor1.viewLearners();
    mentor2.viewLearners();

    mentor1.provideGuidance("Practice daily and focus on technique!");
    mentor2.provideGuidance("Practice daily and focus on technique!");

    student1.viewMentorDetails();
    student2.viewMentorDetails();
    student3.viewMentorDetails();

    mentor2.removeLearner(student1);
    mentor2.viewLearners();
    return 0;
}
