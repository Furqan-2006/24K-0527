#pragma once

#include "Route.hpp"

class Bus
{
private:
    std::string busID;
    Route *assignedRoute;

public:
    Bus();
    Bus(std::string id, Route &r);
    void assignRoute(Route *r);
    void changeRoute(Route *r);
};
