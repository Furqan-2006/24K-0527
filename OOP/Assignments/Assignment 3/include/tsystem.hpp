#pragma once

#include "Bus.hpp"
#include "Student.hpp"
#include "Teacher.hpp"
#include "Staff.hpp"

class Admin;

class TransportationSystem
{
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
    friend class Admin;

    TransportationSystem();
    ~TransportationSystem();

    void registerPeople(Person *s);
    void addRoute(Route r);
    void addBuses(Bus b);
    void assignPersonsToStops(Person *s, BusStop &bs);
    void recordAttendance(Person &p);
    void loginMenu(TransportationSystem &system);

    void loadFromFiles();
    void saveAllToFiles();

    int getPeopleCount() const;
};