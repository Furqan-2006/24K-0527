#include <iostream>
using namespace std;

class Engine
{
private:
    bool isRunning;

public:
    Engine() : isRunning(false) {}

    void start()
    {
        if (!isRunning)
        {
            isRunning = true;
            cout << "Engine started.\n";
        }
        else
        {
            cout << "Engine is already running.\n";
        }
    }

    void stop()
    {
        if (isRunning)
        {
            isRunning = false;
            cout << "Engine stopped.\n";
        }
        else
        {
            cout << "Engine is already off.\n";
        }
    }
};

class Car
{
private:
    Engine engine;

public:
    void startCar()
    {
        cout << "Starting car...\n";
        engine.start();
    }

    void stopCar()
    {
        cout << "Stopping car...\n";
        engine.stop();
    }
};

int main()
{
    Car myCar;

    myCar.startCar();
    myCar.startCar();

    myCar.stopCar();
    myCar.stopCar();

    return 0;
}
