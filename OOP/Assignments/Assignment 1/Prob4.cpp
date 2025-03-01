#include <iostream>
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
    Student(string id = "", string n = "", string stop = "")
        : studentID(id), studentName(n), balance(0), stopID(stop), isActive(false), attendance(0) {};

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
    Student *studentsAtStop;
    int studentCount;
    int capacity;

public:
    BusStop(string id = "", string loc = "")
        : stopID(id), location(loc), studentCount(0), capacity(10)
    {
        studentsAtStop = new Student[capacity];
    };

    ~BusStop()
    {
        delete[] studentsAtStop;
    }

    void assignStudent(Student s)
    {
        if (studentCount == capacity)
        {
            capacity *= 2;
            Student *newStudents = new Student[capacity];
            for (int i = 0; i < studentCount; i++)
            {
                newStudents[i] = studentsAtStop[i];
            }
            delete[] studentsAtStop;
            studentsAtStop = newStudents;
        }
        studentsAtStop[studentCount++] = s;
    }
    void getStopDetails()
    {
        cout << "Stop ID: " << stopID << endl
             << "Location: " << location << endl
             << "Student assigned to the stop: " << endl;
        for (int i = 0; i < studentCount; i++)
        {
            cout << "* " << studentsAtStop[i].getName() << endl;
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
    BusStop *busStops;
    int stopCount;
    int capacity;

public:
    Route(int num = 1) : routeNum(num), stopCount(0), capacity(10)
    {
        busStops = new BusStop[capacity];
    }

    void addBusStop(BusStop bs)
    {
        if (stopCount == capacity)
        {
            capacity *= 2;
            BusStop *newStops = new BusStop[capacity];
            for (int i = 0; i < stopCount; i++)
            {
                newStops[i] = busStops[i];
            }
            delete[] busStops;
            busStops = newStops;
        }
        busStops[stopCount++] = bs;
    };
    void getRouteDetails()
    {
        cout << "Route #: " << routeNum << endl
             << "Bus Stops on Route# " << routeNum << endl;
        int i = 1;
        for (int i = 0; i < stopCount; i++)
        {
            cout << i << ". Stop ID: " << busStops[i].getStopID() << ", Stop location: " << busStops[i].getStopLocation() << endl;
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
    Bus() {};
    Bus(string id, Route r) : busID(id), assignedRoute(r) {};

    void assignRoute(Route r)
    {
        assignedRoute = r;
    }
    void changeRoute(Route r)
    {
        assignedRoute = r;
    }
};

class TransportationSystem
{
private:
    Student *students;
    int studentCount;
    int studentCapacity;

    Route *routes;
    int routeCount;
    int routeCapacity;

    Bus *buses;
    int busCount;
    int busCapacity;

public:
    TransportationSystem()
        : studentCount(0), routeCount(0), busCount(0),
          studentCapacity(10), routeCapacity(10), busCapacity(10)
    {
        students = new Student[studentCapacity];
        routes = new Route[routeCapacity];
        buses = new Bus[busCapacity];
    };

    ~TransportationSystem()
    {
        delete[] students;
        delete[] routes;
        delete[] buses;
    }
    void registerStudent(Student s)
    {
        if (studentCount == studentCapacity)
        {
            studentCapacity *= 2;
            Student *newStudents = new Student[studentCapacity];
            for (int i = 0; i < studentCount; i++)
            {
                newStudents[i] = students[i];
            }
            delete[] students;
            students = newStudents;
        }
        students[studentCount++] = s;
    }
    void addRoute(Route r)
    {
        if (routeCount == routeCapacity)
        {
            routeCapacity *= 2;
            Route *newRoutes = new Route[routeCapacity];
            for (int i = 0; i < routeCount; i++)
            {
                newRoutes[i] = routes[i];
            }
            delete[] routes;
            routes = newRoutes;
        }
        routes[routeCount++] = r;
    }
    void addBuses(Bus b)
    {
        if (busCount == busCapacity)
        {
            busCapacity *= 2;
            Bus *newBuses = new Bus[busCapacity];
            for (int i = 0; i < busCount; i++)
            {
                newBuses[i] = buses[i];
            }
            delete[] buses;
            buses = newBuses;
        }
        buses[busCount++] = b;
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
