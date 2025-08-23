#include <iostream>
#include <cstring>

class Teacher
{
public:
    char *name;
    char *subject;
    int experience;

    Teacher(const char *n, const char *s, int exp)
    {
        name = new char[strlen(n) + 1];
        strcpy(name, n);

        subject = new char[strlen(s) + 1];
        strcpy(subject, s);

        experience = exp;
    }

    ~Teacher()
    {
        delete[] name;
        delete[] subject;
    }

    Teacher(const Teacher &other)
    {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        subject = new char[strlen(other.subject) + 1];
        strcpy(subject, other.subject);

        experience = other.experience;
    }

    Teacher &operator=(const Teacher &other)
    {
        if (this != &other)
        {
            name = new char[strlen(other.name) + 1];
            strcpy(name, other.name);
            subject = new char[strlen(other.subject) + 1];
            strcpy(subject, other.subject);

            experience = other.experience;
        }
        return *this;
    }

    void display()
    {
        std::cout << "Name: "
                  << name << std::endl
                  << "Subject: "
                  << subject << std::endl
                  << "Experience:"
                  << experience << std::endl
                  << std::endl;
    }
};

int main()
{
    std::cout << "With Rule of Three (Deep Copy)" << std::endl;
    Teacher t1("Ali", "Math", 10);
    Teacher t2 = t1;

    t1.display();
    t2.display();

    Teacher t3("Raza", "ICP", 5);

    t3.display();
    
    t3 = t1;
    t1.display();
    t2.display();
    t3.display();
}