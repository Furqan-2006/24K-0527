#include <iostream>
using namespace std;

class Person {
protected:
    string ID;
    string name;
    double balance;
    bool hasPaid;

public:
    Person(string id = "", string n = "") : ID(id), name(n), balance(0), hasPaid(false) {}

    virtual void payTransportFee(double amount) = 0;
    virtual void tapCard() {
        cout << (hasPaid ? "Attendance Marked for: " + name : "Access Denied!") << endl;
    }
    string getName() { return name; }
    string getID() { return ID; }
    double getBalance() { return balance; } // Added for completeness

    void operator+=(double amount) {
        if (amount >= 0) balance += amount; // Prevent negative amounts
    }
};

class Student : public Person {
    string stopID;
    int attendance;

public:
    Student(string id = "", string n = "", string sid = "") 
        : Person(id, n), stopID(sid), attendance(0) {}

    void payTransportFee(double amount) override {
        if (amount < 0) {
            cout << "Invalid amount!" << endl;
            return;
        }
        *this += amount;
        cout << "Amount Deposited: " << amount << "\nCurrent Balance: " << balance << endl;
        if (balance >= 45000) {
            hasPaid = true;
            cout << "Fees paid! Student has activated their transport card." << endl;
        } else {
            cout << "Pay full fees (45000) to activate transport access." << endl;
        }
    }
    void tapCard() override {
        if (hasPaid) {
            cout << "Attendance Recorded for " << name << "!" << endl;
            attendance++;
        } else {
            cout << "YOU ARE NOT ALLOWED! PAY FEES TO GET ACCESS!" << endl;
        }
    }
};

class Teacher : public Person {
public:
    Teacher(string id = "", string n = "") : Person(id, n) {}
    void payTransportFee(double amount) override {
        if (amount < 0) {
            cout << "Invalid amount!" << endl;
            return;
        }
        *this += amount;
        cout << "Amount Deposited: " << amount << "\nCurrent Balance: " << balance << endl;
        if (balance >= 5000) {
            hasPaid = true;
            cout << "Fees paid! Teacher has activated their transport card." << endl;
        } else {
            cout << "Pay full fees (5000) to activate transport access." << endl;
        }
    }
    void tapCard() override {
        cout << (hasPaid ? "Teacher attendance marked." : "Access Denied! Pay Fees.") << endl;
    }
};

class Staff : public Person {
public:
    Staff(string id = "", string n = "") : Person(id, n) {}
    void payTransportFee(double amount) override {
        if (amount < 0) {
            cout << "Invalid amount!" << endl;
            return;
        }
        *this += amount;
        cout << "Amount Deposited: " << amount << "\nCurrent Balance: " << balance << endl;
        if (balance >= 3500) {
            hasPaid = true;
            cout << "Fees paid! Staff member has activated their transport card." << endl;
        } else {
            cout << "Pay full fees (3500) to activate transport access." << endl;
        }
    }
    void tapCard() override {
        cout << (hasPaid ? "Staff attendance marked." : "Access Denied! Pay Fees.") << endl;
    }
};

class BusStop {
private:
    string stopID;
    string location;
    Person **peopleAtStop;
    int peopleCount;
    int capacity;

public:
    BusStop(string id = "", string loc = "")
        : stopID(id), location(loc), peopleCount(0), capacity(10) {
        peopleAtStop = new Person *[capacity];
    }

    ~BusStop() {
        delete[] peopleAtStop; // Only delete the array, not individual pointers
    }

    void assignPerson(Person *p) {
        if (peopleCount == capacity) {
            capacity *= 2;
            Person **newPeople = new Person *[capacity];
            for (int i = 0; i < peopleCount; i++) {
                newPeople[i] = peopleAtStop[i];
            }
            delete[] peopleAtStop;
            peopleAtStop = newPeople;
        }
        peopleAtStop[peopleCount++] = p;
    }
    void getStopDetails() {
        cout << "Stop ID: " << stopID << endl
             << "Location: " << location << endl
             << "People assigned to the stop: " << endl;
        for (int i = 0; i < peopleCount; i++) {
            cout << "* " << peopleAtStop[i]->getName() << endl;
        }
    }
    string getStopID() { return stopID; }
    string getStopLocation() { return location; }
};

class Route {
private:
    int routeNum;
    BusStop *busStops;
    int stopCount;
    int capacity;

public:
    Route() : routeNum(0), stopCount(0), capacity(10) {
        busStops = new BusStop[capacity];
    }
    Route(int num) : routeNum(num), stopCount(0), capacity(10) {
        busStops = new BusStop[capacity];
    }
    ~Route() {
        delete[] busStops;
    }
    void addBusStop(BusStop bs) {
        if (stopCount == capacity) {
            capacity *= 2;
            BusStop *newStops = new BusStop[capacity];
            for (int i = 0; i < stopCount; i++) {
                newStops[i] = busStops[i];
            }
            delete[] busStops;
            busStops = newStops;
        }
        busStops[stopCount++] = bs;
    }
    bool operator==(const Route &other) const {
        if (stopCount != other.stopCount) return false;
        for (int i = 0; i < stopCount; i++) {
            if (busStops[i].getStopID() != other.busStops[i].getStopID()) {
                return false;
            }
        }
        return true;
    }
    void getRouteDetails() {
        cout << "Route #: " << routeNum << endl
             << "Bus Stops on Route# " << routeNum << endl;
        for (int i = 0; i < stopCount; i++) {
            cout << i << ". Stop ID: " << busStops[i].getStopID() 
                 << ", Stop location: " << busStops[i].getStopLocation() << endl;
        }
    }
};

class Bus {
private:
    string busID;
    Route *assignedRoute;

public:
    Bus() : assignedRoute(nullptr) {}
    Bus(string id, Route &r) : busID(id), assignedRoute(&r) {}
    void assignRoute(Route *r) { assignedRoute = r; }
    void changeRoute(Route *r) { assignedRoute = r; }
};

class TransportationSystem {
private:
    Person **peoples;
    int peopleCount;
    int peopleCapacity;
    Route *routes;
    int routeCount;
    int routeCapacity;
    Bus *buses;
    int busCount;
    int busCapacity;

public:
    TransportationSystem()
        : peopleCount(0), routeCount(0), busCount(0),
          peopleCapacity(10), routeCapacity(10), busCapacity(10) {
        peoples = new Person *[peopleCapacity];
        routes = new Route[routeCapacity];
        buses = new Bus[busCapacity];
    }

    ~TransportationSystem() {
        delete[] peoples; // Only delete array, objects managed elsewhere
        delete[] routes;
        delete[] buses;
    }

    void registerPeople(Person *s) {
        if (peopleCount == peopleCapacity) {
            peopleCapacity *= 2;
            Person **newPeoples = new Person *[peopleCapacity];
            for (int i = 0; i < peopleCount; i++) {
                newPeoples[i] = peoples[i];
            }
            delete[] peoples;
            peoples = newPeoples;
        }
        peoples[peopleCount++] = s;
    }
    void addRoute(Route r) {
        if (routeCount == routeCapacity) {
            routeCapacity *= 2;
            Route *newRoutes = new Route[routeCapacity];
            for (int i = 0; i < routeCount; i++) {
                newRoutes[i] = routes[i];
            }
            delete[] routes;
            routes = newRoutes;
        }
        routes[routeCount++] = r;
    }
    void addBuses(Bus b) {
        if (busCount == busCapacity) {
            busCapacity *= 2;
            Bus *newBuses = new Bus[busCapacity];
            for (int i = 0; i < busCount; i++) {
                newBuses[i] = buses[i];
            }
            delete[] buses;
            buses = newBuses;
        }
        buses[busCount++] = b;
    }
    void assignPersonsToStops(Person *s, BusStop &bs) {
        bs.assignPerson(s);
    }
    void recordAttendance(Person &p) {
        p.tapCard();
    }
};

int main() {
    // Creating People
    Student s1("S101", "Alice", "BS1");
    Student s2("S102", "Bob", "BS2");
    Teacher t1("T201", "Mr. Smith");
    Teacher t2("T202", "Ms. Johnson");
    Staff staff1("ST301", "John");
    Staff staff2("ST302", "Emily");

    // Paying Fees
    s1.payTransportFee(30000);    // Partial Payment
    s1.payTransportFee(15000);    // Full Payment Done
    s2.payTransportFee(45000);    // Full Payment Done
    t1.payTransportFee(5000);     // Full Payment Done
    t2.payTransportFee(2500);     // Partial Payment
    staff1.payTransportFee(3500); // Full Payment Done
    staff2.payTransportFee(1000); // Partial Payment

    // Creating Bus Stops
    BusStop stop1("BS1", "Main Gate");
    BusStop stop2("BS2", "Library");
    BusStop stop3("BS3", "Hostel");

    // Assigning Persons to Bus Stops
    stop1.assignPerson(&s1);
    stop1.assignPerson(&t1);
    stop2.assignPerson(&s2);
    stop3.assignPerson(&staff1);
    stop3.assignPerson(&staff2);

    // Creating Routes and Adding Stops
    Route route1(101);
    route1.addBusStop(stop1);
    route1.addBusStop(stop2);

    Route route2(102);
    route2.addBusStop(stop1);
    route2.addBusStop(stop2);
    route2.addBusStop(stop3);

    // Checking if two routes are the same
    if (route1 == route2)
        cout << "Routes 101 and 102 are the same.\n";
    else
        cout << "Routes 101 and 102 are different.\n";

    // Creating Buses and Assigning Routes
    Bus bus1("Bus_A1", route1);
    Bus bus2("Bus_B2", route2);

    // Creating Transportation System
    TransportationSystem ts;
    ts.registerPeople(&s1);
    ts.registerPeople(&s2);
    ts.registerPeople(&t1);
    ts.registerPeople(&t2);
    ts.registerPeople(&staff1);
    ts.registerPeople(&staff2);
    ts.addRoute(route1);
    ts.addRoute(route2);
    ts.addBuses(bus1);
    ts.addBuses(bus2);

    // Marking Attendance
    cout << "\n--- TAPPING CARDS ---\n";
    ts.recordAttendance(s1);     // ✅ Allowed
    ts.recordAttendance(s2);     // ✅ Allowed
    ts.recordAttendance(t1);     // ✅ Allowed
    ts.recordAttendance(t2);     // ❌ Denied
    ts.recordAttendance(staff1); // ✅ Allowed
    ts.recordAttendance(staff2); // ❌ Denied

    // Display Route and Stop Details
    cout << "\n--- ROUTE DETAILS ---\n";
    route1.getRouteDetails();
    route2.getRouteDetails();

    cout << "\n--- BUS STOP DETAILS ---\n";
    stop1.getStopDetails();
    stop2.getStopDetails();
    stop3.getStopDetails();

    return 0;
}