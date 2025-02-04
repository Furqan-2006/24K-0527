#include <iostream>
using namespace std;

class Glass
{
public:
    int liquidLevel = 200;

    void Drink(int milliliters)
    {
        if (milliliters > liquidLevel)
        {
            cout << "Not enough liquid!\n";
            return;
        }

        liquidLevel -= milliliters;

        if (liquidLevel < 100)
        {
            Refill();
        }
    }

    void Refill()
    {
        liquidLevel = 200;
    }

    void ShowLevel()
    {
        cout << "Current liquid level: " << liquidLevel << " ml\n";
    }
};

int main()
{
    Glass water;
    int option, sip;

    while (true)
    {
        cout << "\n1. Drink\n2. Refill\n3. Show water level\n4. Exit\nChoose an option: ";
        cin >> option;

        switch (option)
        {
        case 1:
            cout << "Enter amount to drink: ";
            cin >> sip;
            water.Drink(sip);
            break;
        case 2:
            water.Refill();
            break;
        case 3:
            water.ShowLevel();
            break;
        case 4:
            cout << "Exiting program...\n";
            return 0;
        default:
            cout << "Invalid option! Try again.\n";
        }
    }
}
