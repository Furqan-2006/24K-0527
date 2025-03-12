#include <iostream>
using namespace std;

class Vehicle
{
protected:
    double price;

public:
    Vehicle(double p) { price = p; }
    virtual void showDetails() = 0;
};

class Car : public Vehicle
{
protected:
    int seatsCap;
    int doorNum;
    string fuelType;

public:
    Car(double p, int seats, int doors, string fuel) : Vehicle(p)
    {
        seatsCap = seats;
        doorNum = doors;
        fuelType = fuel;
    }
};

class Motorcycle : public Vehicle
{
protected:
    int cylNum;
    int gearNum;
    int wheelsNum;

public:
    Motorcycle(double p, int cyl, int gears, int wheels) : Vehicle(p)
    {
        cylNum = cyl;
        gearNum = gears;
        wheelsNum = wheels;
    }
};

class Audi : public Car
{
protected:
    string model;

public:
    Audi(double p, int seats, int doors, string fuel, string mod) : Car(p, seats, doors, fuel)
    {
        model = mod;
    }
    void showDetails() override
    {
        cout << "Price: " << price << endl
             << "Seating Capacity: " << seatsCap << endl
             << "Number of Doors: " << doorNum << endl
             << "Fuel type: " << fuelType << endl
             << "Model type: " << model << endl;
    }
};
class Yamaha : public Motorcycle
{
protected:
    string make;

public:
    Yamaha(double p, int cyl, int gears, int wheels, string mak) : Motorcycle(p, cyl, gears, wheels)
    {
        make = mak;
    }
    void showDetails() override
    {
        cout << "Price: " << price << endl
             << "Number of Cylinder: " << cylNum << endl
             << "Number of Gears: " << gearNum << endl
             << "Number of Wheels: " << wheelsNum << endl
             << "Make type: " << make << endl;
    }
};

int main()
{
    Audi audiCar(50000, 5, 4, "Petrol", "A4");

    Yamaha yamahaBike(15000, 2, 6, 2, "YZF-R1");

    cout << "Audi Car Details:" << endl;
    audiCar.showDetails();

    cout << "\nYamaha Motorcycle Details:" << endl;
    yamahaBike.showDetails();

    return 0;
}