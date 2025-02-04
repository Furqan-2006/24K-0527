#include <iostream>
#include <string>

using namespace std;

class User
{

public:
    int age;
    string name;
};

int main()
{
    User u1;
    u1.name = "Teo";
    u1.age = 24;
    cout << "My name is " << u1.name << " and I am " << u1.age << " years old.";
    return 0;
}