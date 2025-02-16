#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

class Student
{
private:
    string studentID;
    string studentName;
    double balance;
    string stopID;
    bool isActive;
    int attendance;

public:
    Student(string id, string n, string stop)
        : studentID(id), studentName(n), balance(0), stopID(stop), isActive(false) {};

    void payTransportFee(double fees)
    {
        balance += fees;
        if (balance >= 45000)
        {
            isActive = true;
            cout << studentName << " has activated their transport card!" << endl;
        }
    };
    void tapCard()
    {
        if (isActive)
        {
            cout << studentName << "'s attendance recorded." << endl;
            attendance++;
        }
        else
        {
            cout << "Access Denied! Please register yourself first!" << endl;
        }
    };

    string getName() { return studentName; }
    string getID() { return studentID; }
    string getStopID() { return stopID; }
};
class BusStop
{
private:
    string stopID;
    string location;
    vector<Student> studentsAtStop;

public:
    BusStop(string id, string loc)
        : stopID(id), location(loc) {};

    void assignStudent(Student s)
    {
        studentsAtStop.push_back(s);
    }
    void getStopDetails()
    {
        cout << "Stop ID: " << stopID << endl
             << "Location: " << location << endl
             << "Student assigned to the stop: " << endl;
        for (auto &s : studentsAtStop)
        {
            cout << "* " << s.getName() << endl;
        }
    }

    string getStopID()
    {
        return stopID;
    }
    string getStopLocation()
    {
        return location;
    }
};

class Route
{
private:
    int routeNum;
    vector<BusStop> busStops;

public:
    Route(int routeNum)
    {
        this->routeNum = routeNum;
    }
    void addBusStop(BusStop bs)
    {
        busStops.push_back(bs);
    };
    void getRouteDetails()
    {
        cout << "Route #: " << routeNum << endl
             << "Bus Stops on Route# " << routeNum << endl;
        int i = 1;
        for (auto &bs : busStops)
        {
            cout << i << ". Stop ID: " << bs.getStopID() << ", Stop location: " << bs.getStopLocation() << endl;
            i++;
        }
    }
};

class Bus
{
private:
    string busID;
    Route assignedRoute;

public:
    Bus(string id, Route r) : busID(id), assignedRoute(r) {};

    void assignRoute(Route r)
    {
        assignedRoute = r;
    }
};
class TransportationSystem
{
private:
    vector<Student> students;
    vector<Route> routes;
    vector<Bus> buses;

public:
    void registerStudent(Student s)
    {
        students.push_back(s);
    }
    void addRoute(Route r)
    {
        routes.push_back(r);
    }
    void addBuses(Bus b)
    {
        buses.push_back(b);
    }
    void assignStudentsToStops(Student s, BusStop &bs)
    {
        bs.assignStudent(s);
    }
    void recordAttendance(Student &s)
    {
        s.tapCard();
    }
};

int main()
{

    TransportationSystem system;

    Student s1("S001", "Alice", "Stop1");
    Student s2("S002", "Bob", "Stop2");

    system.registerStudent(s1);
    system.registerStudent(s2);

    BusStop stop1("Stop1", "Main Street");
    BusStop stop2("Stop2", "Park Avenue");

    system.assignStudentsToStops(s1, stop1);
    system.assignStudentsToStops(s2, stop2);

    stop1.getStopDetails();
    stop2.getStopDetails();

    Route route1(101);
    route1.addBusStop(stop1);
    route1.addBusStop(stop2);

    route1.getRouteDetails();

    Bus bus1("Bus001", route1);
    system.addBuses(bus1);

    Route route2(102);
    Bus bus2("Bus002", route2);
    system.addBuses(bus2);
    bus2.assignRoute(route1);

    s1.payTransportFee(20000);
    s1.payTransportFee(30000);
    s2.payTransportFee(45000);

    system.recordAttendance(s1);
    system.recordAttendance(s2);
    return 0;
}
