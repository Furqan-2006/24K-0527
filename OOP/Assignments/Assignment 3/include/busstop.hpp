#pragma once

#include "Person.hpp"

class BusStop {
private:
    std::string stopID;
    std::string location;
    Person **peopleAtStop;
    int peopleCount;
    int capacity;

public:
    BusStop(std::string id = "", std::string loc = "");
    ~BusStop();
    void assignPerson(Person *p);
    void getStopDetails() const;
    std::string getStopID() const;
    std::string getStopLocation() const;
};