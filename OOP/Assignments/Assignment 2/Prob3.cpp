//*                                         ---- RAMADAN BOX DELIVERY SYSTEM -----

#include <iostream>
#include <string>

using namespace std;

class Vehicle
{
protected:
    string vID;
    static int activeDeliveries;

public:
    Vehicle(string id = "") : vID(id)
    {
        activeDeliveries++;
    }
    virtual void calculateRoute()
    {
        cout << "Calculating the Optimal Delivery Route ..." << endl;
    }
    virtual void estimateTime()
    {
        cout << "Estimating delivery time ..." << endl;
    }
    virtual void move()
    {
        cout << "Moving ..." << endl;
    }
    virtual void deliverPackage(string packageID)
    {
        cout << "Delivering package " << packageID << " ..." << endl;
    }
    static int getActiveDeliveries()
    {
        return activeDeliveries;
    }
    friend void resolveConflict(Vehicle &v1, Vehicle &v2);
    friend bool operator==(const Vehicle &v1, const Vehicle &v2);
    virtual ~Vehicle() {}
};
int Vehicle::activeDeliveries = 0;
bool operator==(const Vehicle &v1, const Vehicle &v2)
{
    return v1.vID == v2.vID;
}

class RamadanDrone : public Vehicle
{
public:
    RamadanDrone(string id) : Vehicle(id) {}

    void calculateRoute() override
    {
        cout << "Calculating Optimal aerial route for fast delivery ..." << endl;
    }
    void move() override
    {
        cout << "Flying through the air at high speed!" << endl;
    }

    void deliverPackage(string packageID) override
    {
        cout << "Drone delivering package " << packageID << " via aerial route." << endl;
    }
    void deliverPackage(string packageID, string urgency)
    {
        if (urgency == "urgent")
        {
            cout << "Activating high-speed mode for urgent delivery of package " << packageID << endl;
        }
        else
        {
            deliverPackage(packageID);
        }
    }
};
class RamadanTimeShip : public Vehicle
{
public:
    RamadanTimeShip(string id) : Vehicle(id) {}
    void calculateRoute() override
    {
        cout << "Verifying Historical accuracy ..." << endl;
        cout << "Selecting time-travel route ..." << endl;
    }
    void move() override
    {
        cout << "Commencing Time-Travel ..." << endl;
    }
    void deliverPackage(string packageID) override
    {
        cout << "TimeShip delivering package " << packageID << " ..." << endl;
    }
    void deliverPackage(string packageID, string urgency)
    {
        if (urgency == "urgent")
        {
            cout << "Priority set to HIGH for the delivery of package " << packageID << endl;
        }
        else
        {
            deliverPackage(packageID);
        }
    }
};
class RamadanHyperPod : public Vehicle
{
public:
    RamadanHyperPod(string id) : Vehicle(id) {}

    void calculateRoute() override
    {
        cout << "Calculating underground tunnel network for optimal delivery..." << endl;
    }

    void move() override
    {
        cout << "Zooming through hyperloop tunnels at high speed!" << endl;
    }

    void deliverPackage(string packageID) override
    {
        cout << "HyperPod delivering bulk package " << packageID << " via underground tunnels." << endl;
    }
};

// Friend function for AI conflict resolution
void resolveConflict(Vehicle &v1, Vehicle &v2)
{
    cout << "Resolving conflict between " << v1.vID << " and " << v2.vID << "..." << endl;

    if (v1 == v2)
    {
        cout << "Both vehicles are equally efficient. Assigning delivery to the first available vehicle..." << endl;
    }
    else
    {
        cout << "Choosing the most efficient vehicle for delivery..." << endl;
    }
}

class OperatorControlPanel
{
public:
    static void command(Vehicle &v, string action, string packageID)
    {
        if (action == "Deliver")
        {
            v.deliverPackage(packageID);
        }
    }

    static void command(Vehicle &v, string action, string packageID, string urgencyLevel)
    {
        if (action == "Deliver")
        {
            if (RamadanDrone *drone = dynamic_cast<RamadanDrone *>(&v))
            {
                drone->deliverPackage(packageID, urgencyLevel);
            }
            else if (RamadanTimeShip *timeShip = dynamic_cast<RamadanTimeShip *>(&v))
            {
                timeShip->deliverPackage(packageID, urgencyLevel);
            }
            else
            {
                v.deliverPackage(packageID);
            }
        }
    }
};

int main()
{
    RamadanDrone drone("Drone-001");
    RamadanTimeShip timeShip("TimeShip-001");
    RamadanHyperPod hyperPod("HyperPod-001");

    cout << "Total active deliveries: " << Vehicle::getActiveDeliveries() << endl;

    OperatorControlPanel::command(drone, "Deliver", "PCK123");
    OperatorControlPanel::command(timeShip, "Deliver", "PCK456", "urgent");
    OperatorControlPanel::command(hyperPod, "Deliver", "PCK789");

    // Conflict resolution test
    resolveConflict(drone, hyperPod);

    cout << "Total active deliveries after operations: " << Vehicle::getActiveDeliveries() << endl;

    return 0;
}
