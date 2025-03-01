#include <iostream>
using namespace std;

class Car
{
public:
    mutable int hp;
    mutable int seatingCap;
    mutable int noOfSpeakers;

    Car(int hp, int seats, int ns) : hp(hp), seatingCap(seats), noOfSpeakers(ns) {};

    void updateCar(int hp, int seats, int speakers) const
    {
        this->hp = hp;
        this->seatingCap = seats;
        this->noOfSpeakers = speakers;
    }
    void displayCarDetails()
    {
        cout << "Engine Horsepower: " << hp << endl;
        cout << "Seating Capacity: " << seatingCap << endl;
        cout << "Number of Speakers: " << noOfSpeakers << endl;
    }
};

int main()
{
    Car myCar(150, 5, 6);

    std::cout << "Before Update:\n";
    myCar.displayCarDetails();

    myCar.updateCar(200, 4, 8);

    std::cout << "\nAfter Update:\n";
    myCar.displayCarDetails();
    return 0;
}