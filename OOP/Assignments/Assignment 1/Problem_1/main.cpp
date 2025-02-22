#include <iostream>
using namespace std;

class Mentor;

class Student
{
private:
    string studentID;
    string studentName;
    int age;
    string *sportInterest;
    int interestCount;
    int maxInterests;

public:
    Mentor *mentorAssigned;

    Student(string id, string n, int a)
        : studentID(id), studentName(n), age(a), interestCount(0), maxInterests(5), mentorAssigned(nullptr)
    {
        sportInterest = new string[maxInterests];
    }

    ~Student()
    {
        delete[] sportInterest;
    }
    string getStudentName() { return studentName; }
    string getStudentID() { return studentID; }
    int getAge() { return age; }

    void registerForMentorship(Mentor *m);

    void viewMentorDetails();

    void updateSportsInterest(string sports)
    {
        if (interestCount < 5)
        {
            sportInterest[interestCount++] = sports;
        }
        else
        {
            cout << "Cannot add more interests. Limit reached!" << endl
                 << "Please focus on the ones you have already." << endl;
        }
    }
    void showStudentDetails()
    {
        cout << "Student ID: " << studentID << "\nName: " << studentName
             << "\nAge: " << age << "Sports Interests: \n";
        for (int i = 0; i < interestCount; i++)
        {
            cout << "- " << sportInterest[i] << "\n";
        }
    }
};

class Mentor
{
private:
    string mentorID;
    string mentorName;
    int maxLearners;
    string sportExpertise[5];
    int expertiseCount;
    Student **assignedLearners;

    int learnerCount;

public:
    Mentor(string id, string n, int maxL)
        : mentorID(id), mentorName(n), maxLearners(maxL), expertiseCount(0), learnerCount(0)
    {
        assignedLearners = new Student *[maxLearners];
    }

    ~Mentor()
    {
        delete[] assignedLearners;
    }

    string getMentorName() { return mentorName; }
    string getMentorID() { return mentorID; }

    void addExpertise(string expertise)
    {
        if (expertiseCount < 5)
        {
            sportExpertise[expertiseCount++] = expertise;
        }
        else
        {
            cout << "Limit Reached for this program! Cannot add more. Sorry!" << endl;
        }
    }
    void assignLearner(Student *s)
    {

        if (learnerCount < maxLearners)
        {
            assignedLearners[learnerCount++] = s;
            s->registerForMentorship(this);
            cout << "Registered Successfully!" << endl;
        }
        else
        {
            cout << "Cannot assign more learner as limit has reached." << endl;
        }
    }
    void removeLearner(Student *s)
    {
        for (int i = 0; i < learnerCount; i++)
        {
            if (assignedLearners[i] == s)
            {
                for (int j = i; j < learnerCount - 1; j++)
                {
                    assignedLearners[j] = assignedLearners[j + 1];
                }
                learnerCount--;
                s->registerForMentorship(nullptr);
                cout << "Learner removed Successfully!" << endl;
                return;
            }
        }
        cout << "Learner Not Found!" << endl;
    }
    void viewLearners()
    {
        cout << "Assigned Learners: " << endl;
        for (int i = 0; i < learnerCount; i++)
        {
            cout << "- " << assignedLearners[i]->getStudentName() << endl;
        }
    }
    void provideGuidance(string guidance)
    {
        cout << mentorName << " is providing guidance to students." << endl;
        cout << guidance << endl;
    };
};

void Student::registerForMentorship(Mentor *m)
{
    mentorAssigned = m;
    cout << studentName << " has been assigned to the mentor " << m->getMentorName() << endl;
}
void Student::viewMentorDetails()
{
    if (mentorAssigned)
    {
        cout << "Mentor Name: " << mentorAssigned->getMentorName() << endl
             << "Mentor ID: " << mentorAssigned->getMentorID() << endl;
    }
    else
    {
        cout << "No mentor assigned!" << endl;
    }
}
class Skill
{
private:
    string skillID;
    string skillName;

public:
    string skillDescription;

    Skill(string id = "", string n = " ") : skillID(id), skillName(n) {}

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
    Skill skillRequired[10];
    int skillCount;

    Sport(string id = "", string n = "") : sportsID(id), sportsName(n), skillCount(0) {}

    string getSportName() { return sportsName; }
    string getSportID() { return sportsID; }

    void addSkill(Skill &s)
    {
        if (skillCount < 10)
        {
            skillRequired[skillCount++] = s;
            cout << s.getSkillName() << " is added to the sport " << getSportName() << endl;
        }
        else
        {
            cout << "Cannot add any skill. Limit reached." << endl;
        }
    }

    void removeSkill(string skillID)
    {
        for (int i = 0; i < skillCount; i++)
        {
            if (skillRequired[i].getSkillID() == skillID)
            {
                for (int j = i; j < skillCount - 1; j++)
                {
                    skillRequired[j] = skillRequired[j + 1];
                }
                skillCount--;
                cout << "Skill removed Successfully!" << endl;
                return;
            }
        }
        cout << "Skill Not Found!" << endl;
    }
    void showSportDetails()
    {
        cout << "Sport ID: " << sportsID << endl
             << "Sport Name: " << sportsName << endl
             << "Description: " << description << endl
             << "Skills Required: " << endl;
        for (int i = 0; i < skillCount; i++)
        {
            cout << "- " << skillRequired[i].getSkillName() << endl;
        }
    }
};
int main()
{

    Student student1("S001", "Saad", 20);
    Student student2("S002", "Ali", 21);
    Student student3("S003", "Ahmed", 22);

    Mentor mentor("M001", "Ali", 3);

    mentor.addExpertise("Tennis");
    mentor.addExpertise("Football");

    student1.updateSportsInterest(string("Tennis"));
    student2.updateSportsInterest(string("Tennis"));
    student3.updateSportsInterest(string("Football"));

    mentor.assignLearner(&student1);
    mentor.assignLearner(&student2);
    mentor.assignLearner(&student3);

    Student student4("S004", "Bilal", 19);
    student4.updateSportsInterest("Tennis");
    mentor.assignLearner(&student4);

    student1.viewMentorDetails();

    mentor.viewLearners();

    mentor.provideGuidance("Focus on your footwork and serve technique in Tennis.");

    mentor.removeLearner(&student2);

    mentor.viewLearners();

    mentor.assignLearner(&student4);

    mentor.viewLearners();

    Sport tennis("T001", "Tennis");
    tennis.description = "A racket sport that can be played individually or in pairs.";
    Skill serve("SK001", "Serve");
    serve.skillDescription = "The act of putting the ball into play.";
    tennis.addSkill(serve);

    tennis.showSportDetails();

    serve.updateSkillDescription("The serve is the shot that starts a point in tennis.");
    serve.showSkillDetails();

    return 0;
}