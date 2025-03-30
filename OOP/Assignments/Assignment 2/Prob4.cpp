#include <iostream>
#include <string>

using namespace std;

unsigned long hashPassword(const string &password)
{
    unsigned long hash = 5381;
    for (char c : password)
    {
        hash = (hash * 33) + c;
    }
    return hash;
}

class User
{
protected:
    string name;
    string ID;
    string email;
    unsigned long hashed_password;
    string *permission;
    int capacity;

public:
    User(string n = "", string id = "", string em = "", string pass = "", string perm[] = nullptr, int permSize = 0)
        : name(n), ID(id), email(em), hashed_password(hashPassword(pass)), capacity(permSize)
    {
        if (capacity > 0)
        {
            permission = new string[capacity];
            if (perm != nullptr)
            {
                for (int i = 0; i < permSize && i < capacity; i++)
                {
                    permission[i] = perm[i];
                }
            }
        }
        else
        {
            permission = nullptr;
        }
    }
    ~User()
    {
        delete[] permission;
    }

    bool authenticate(string password)
    {
        return hashPassword(password) == hashed_password;
    }

    virtual void display()
    {
        cout << "Name: " << name << "\nID: " << ID << "\nEmail: " << email << endl;
        cout << "Permissions: " << endl;
        for (int i = 0; i < capacity; i++)
        {
            if (!permission[i].empty())
            {
                cout << "- " << permission[i] << endl;
            }
        }
    }

    bool hasPermission(string action)
    {
        for (int i = 0; i < capacity; i++)
        {
            if (permission[i] == action)
            {
                return true;
            }
        }
        return false;
    }
};

class Student : public User
{
private:
    int *assignments;
    int capacity;

public:
    Student(string n = "", string id = "", string em = "", string pass = "", string perm[] = nullptr, int permSize = 0, int cap = 5)
        : User(n, id, em, pass, perm, permSize), capacity(cap)
    {
        assignments = new int[capacity];
        for (int i = 0; i < capacity; i++)
        {
            assignments[i] = 0;
        }
    }

    void submitAssignment(int index)
    {
        if (index >= 0 && index < capacity)
        {
            if (assignments[index] == 0)
            {
                assignments[index] = 1;
                cout << "Assignment " << index + 1 << " has been submitted!" << endl;
            }
            else
            {
                cout << "Can't submit again! Assignment is already submitted." << endl;
            }
        }
        else
        {
            cout << "Invalid Assignment Index!!" << endl;
        }
    }

    void display() override
    {
        User::display();
        cout << "Role: Student" << endl
             << "Assignments: \n";
        for (int i = 0; i < capacity; i++)
        {
            cout << "[A-" << (i + 1) << ": " << (assignments[i] ? "Submitted" : "Not Submitted") << "] ";
        }
        cout << endl;
    }

    ~Student()
    {
        delete[] assignments;
    }
};

class TA : public Student
{
    Student **students;
    int studentCapacity;
    int studentCount;
    string projects[2];
    int projectCount;

public:
    TA(string n = "", string id = "", string em = "", string pass = "", string perm[] = nullptr, int permSize = 0, int cap = 5, int stdCap = 10)
        : Student(n, id, em, pass, perm, permSize, cap), studentCapacity(stdCap), studentCount(0), projectCount(0)
    {
        students = new Student *[studentCapacity]; // Correct memory allocation
    }

    void assignStudent(Student *s)
    {
        if (studentCount < studentCapacity)
        {
            students[studentCount++] = s;
            cout << "Student Assigned to TA." << endl;
        }
        else
        {
            cout << "TA cannot take more than " << studentCapacity << " students" << endl;
        }
    }

    void startProject(string project)
    {
        if (projectCount < 2)
        {
            projects[projectCount++] = project;
            cout << "Project " << project << " started by TA." << endl;
        }
        else
        {
            cout << "Max project limit (2) reached!" << endl;
        }
    }

    void display() override
    {
        Student::display();
        cout << "Role: TA" << endl
             << "Projects: \n";
        for (int i = 0; i < projectCount; i++)
        {
            cout << (i + 1) << ". " << projects[i] << endl;
        }
        cout << "Students Assigned: " << studentCount << endl;
    }

    ~TA()
    {
        delete[] students;
    }
};

class Professor : public User
{
public:
    Professor(string n = "", string id = "", string em = "", string pass = "", string perm[] = nullptr, int permSize = 0)
        : User(n, id, em, pass, perm, permSize) {}

    void assignProject(TA &ta, string project)
    {
        ta.startProject(project);
    }

    void display() override
    {
        User::display();
        cout << "Role: Professor\n";
    }
};

void authenticateAndPerformAction(User *user, string action, string password)
{
    if (user->authenticate(password))
    {
        if (user->hasPermission(action))
        {
            cout << "Action \"" << action << "\" has been performed successfully." << endl;
        }
        else
        {
            cout << "User does not have permission!" << endl;
        }
    }
    else
    {
        cout << "Authentication failed!" << endl;
    }
}

int main()
{
    string studentPerms[] = {"submit assignment"};
    string taPerms[] = {"view projects", "manage_students"};
    string professorPerms[] = {"assign projects", "full_lab_access"};

    Student student1("Alice", "S001", "alice@example.com", "password123", studentPerms, 1, 5);
    TA ta1("Bob", "T001", "bob@example.com", "password456", taPerms, 2, 5, 10);
    Professor prof1("Dr. Smith", "P001", "smith@example.com", "securePass", professorPerms, 2);

    cout << "\nDisplaying Student Info:\n";
    student1.display();

    cout << "\nDisplaying TA Info:\n";
    ta1.display();

    cout << "\nDisplaying Professor Info:\n";
    prof1.display();

    return 0;
}
