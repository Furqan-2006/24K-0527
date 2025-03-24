#include <iostream>
#include <string>
#include <random>

using namespace std;

random_device rd;
mt19937 gen(rd());
uniform_int_distribution<int> dist(1, 10);

class MegaGhost;

class Ghost
{
protected:
    string workerName;
    int scareLevel; // range: 1- 10

public:
    Ghost(string name) : workerName(name), scareLevel(dist(gen)) {}

    virtual void haunt() = 0;

    int getScareLevel() { return scareLevel; }

    friend ostream &operator<<(ostream &os, const Ghost &g)
    {
        os << "Ghost: " << g.workerName << ", Scare level: " << g.scareLevel;
        return os;
    }

    Ghost *operator+(const Ghost &other);
};
class MegaGhost : public Ghost
{
public:
    MegaGhost(string name, int scareLvl) : Ghost(name)
    {
        scareLevel = scareLvl;
    }

    void haunt() override
    {
        cout << "MegaGhost haunts in a terrifying way with combined power!" << endl;
    }
};

Ghost *Ghost::operator+(const Ghost &other)
{
    return new MegaGhost("MegaGhost", scareLevel + other.scareLevel);
}

class Poltergeist : virtual public Ghost
{
public:
    Poltergeist(string name) : Ghost(name) {}

    void haunt() override
    {
        cout << workerName << " moves objects around!" << endl;
    }
};

class Banshee : public Ghost
{
public:
    Banshee(string name) : Ghost(name) {}

    void haunt() override
    {
        cout << workerName << " screams loudly!" << endl;
    }
};

class ShadowGhost : virtual public Ghost
{
public:
    ShadowGhost(string name) : Ghost(name) {}

    void haunt() override
    {
        cout << workerName << " whispers creepily..." << endl;
    }
};

class ShadowPoltergeist : public Poltergeist, public ShadowGhost
{
public:
    ShadowPoltergeist(string name) : Ghost(name), Poltergeist(name), ShadowGhost(name) {}

    void haunt() override
    {
        Poltergeist::haunt();
        ShadowGhost::haunt();
    }
};

class Visitor
{
protected:
    string vName;
    int bravery; // range: 1-10

public:
    Visitor(string name, int braveryLevel) : vName(name), bravery(braveryLevel) {}

    void reactToHaunt(int scareLevel)
    {
        if (scareLevel < bravery)
        {
            cout << vName << " laughs at the ghost!" << endl;
        }
        else if (scareLevel > bravery)
        {
            cout << vName << " screams and runs away!" << endl;
        }
        else
        {
            cout << vName << " gets a shaky voice..." << endl;
        }
    }
};

class HauntedHouse
{
protected:
    string houseName;
    Ghost **ghosts;
    int capacity;
    int ghostCount;

public:
    HauntedHouse(string name, int cap) : houseName(name), capacity(cap), ghostCount(0)
    {
        ghosts = new Ghost *[capacity];
    }

    ~HauntedHouse()
    {
        for (int i = 0; i < ghostCount; i++)
        {
            delete ghosts[i];
        }
        delete[] ghosts;
    }

    void addGhost(Ghost *g)
    {
        if (ghostCount < capacity)
        {
            ghosts[ghostCount++] = g;
        }
        else
        {
            cout << "No space left to add more ghosts!" << endl;
        }
    }

    void displayInfo()
    {
        cout << "Haunted House: " << houseName << endl;
        for (int i = 0; i < ghostCount; i++)
        {
            cout << *ghosts[i] << endl;
        }
    }

    void hauntVisitors(Visitor visitors[], int visitorCount)
    {
        if (ghostCount == 0)
        {
            cout << "No ghosts are haunting today..." << endl;
            return;
        }

        for (int i = 0; i < visitorCount; i++)
        {
            int totalScare = 0;
            for (int j = 0; j < ghostCount; j++)
            {
                totalScare += ghosts[j]->getScareLevel();
            }
            visitors[i].reactToHaunt(totalScare / ghostCount);
        }
    }
};

void visit(HauntedHouse &house, Visitor visitors[], int visitorCount)
{
    house.displayInfo();
    house.hauntVisitors(visitors, visitorCount);
}

int main()
{

    HauntedHouse house("Spooky Mansion", 3);

    house.addGhost(new Poltergeist("Poltergeist"));
    house.addGhost(new Banshee("Banshee"));
    house.addGhost(new ShadowGhost("ShadowGhost"));

    Visitor visitors[3] = {
        Visitor("Alice", 2),
        Visitor("Bob", 6),
        Visitor("Charlie", 9)};

    visit(house, visitors, 3);

    return 0;
}
