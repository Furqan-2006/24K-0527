#include <iostream>
#include <cstdlib>
using namespace std;

class Blend
{

public:
    void startBlending()
    {
        cout << "Blending..." << endl;
        for (volatile long i = 0; i < 1000000000; i++)
            ;
        cout << "Blending completed!" << endl;
    }
};
class Grind
{

public:
    void startGrinding()
    {
        cout << "Grinding..." << endl;
        for (volatile long i = 0; i < 1300000000; i++)
            ;
        cout << "Grinding completed!" << endl;
    }
};
class JuiceMaker
{

    Blend blender;
    Grind grinder;
    string fruits[4] = {"banana", "mango", "pineapple", "strawberry"};

public:
    void displayFruits()
    {
        int size = sizeof(fruits) / sizeof(string);
        cout << "Fruits Available: " << endl;
        for (int i = 0; i < size; i++)
        {
            cout << i + 1 << ". " << fruits[i] << endl;
        }
    }
    void blend()
    {
        blender.startBlending();
    }
    void grind()
    {
        grinder.startGrinding();
    }
};

int main()
{

    JuiceMaker j;
    j.displayFruits();
    cout << "Select one Option: " << endl
         << "1. Blend" << endl
         << "2. Grind" << endl
         << "Option: ";
    int option;
    cin >> option;
    switch (option)
    {
    case 1:
        j.blend();
        break;
    case 2:
        j.grind();
        break;

    default:
        cout << "Invalid Option!!" << endl;
        break;
    }

    return 0;
}