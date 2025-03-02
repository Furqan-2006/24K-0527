#include <iostream>
using namespace std;

class Engine
{
public:
    Engine() { cout << "Engine constructed.\n"; }
    ~Engine() { cout << "Engine destroyed.\n"; }

    void start() { cout << "Engine started.\n"; }
    void stop() { cout << "Engine stopped.\n"; }
};

class Car
{
private:
    Engine engine; // Composition: Car owns Engine

public:
    Car() { cout << "Car constructed.\n"; }
    ~Car() { cout << "Car destroyed.\n"; }

    void startCar() { engine.start(); }
    void stopCar() { engine.stop(); }
};

int main()
{
    cout << "Creating a Car...\n";
    Car myCar;
    myCar.startCar();
    myCar.stopCar();
    cout << "Car is going out of scope...\n";
    return 0;
}
