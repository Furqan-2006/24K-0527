#pragma once

#include "BusStop.hpp"

class Route
{
private:
    int routeNum;
    BusStop *busStops;
    int stopCount;
    int capacity;

public:
    Route();
    Route(int num);
    ~Route();
    void addBusStop(const BusStop &bs);
    bool operator==(const Route &other) const;
    void getRouteDetails() const;
};