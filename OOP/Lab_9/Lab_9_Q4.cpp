#include <iostream>
#include <string>
using namespace std;

class Student
{
public:
    virtual double getTuition(const string &status, int creditHours) const = 0;

    virtual ~Student() {}
};

class GraduateStudent : public Student
{
private:
    string researchTopic;

public:
    GraduateStudent(const string &topic) : researchTopic(topic) {}

    double getTuition(const string &status, int creditHours) const override
    {
        double tuitionRate = 0.0;

        if (status == "undergraduate")
        {
            tuitionRate = 200.0;
        }
        else if (status == "graduate")
        {
            tuitionRate = 300.0;
        }
        else if (status == "doctoral")
        {
            tuitionRate = 400.0;
        }

        return tuitionRate * creditHours;
    }

    void setResearchTopic(const string &topic)
    {
        researchTopic = topic;
    }

    string getResearchTopic() const
    {
        return researchTopic;
    }
};

int main()
{
    GraduateStudent gradStudent("Artificial Intelligence");

    cout << "Research Topic: " << gradStudent.getResearchTopic() << endl;

    string status = "graduate";
    int creditHours = 12;
    double tuition = gradStudent.getTuition(status, creditHours);

    cout << "Tuition for " << status << " student with " << creditHours
         << " credit hours: $" << tuition << endl;

    return 0;
}
