#include "../include/bus.hpp"
#include <iostream>
#include <stdexcept>

Bus::Bus() : assignedRoute(nullptr) {}

Bus::Bus(std::string id, Route &r) : busID(id), assignedRoute(&r) {}

void Bus::assignRoute(Route *r)
{
    try
    {
        if (r == nullptr)
        {
            throw std::invalid_argument("Attempted to assign a null route to the bus.");
        }
        assignedRoute = r;
        std::cout << "Route assigned to Bus " << busID << "." << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error assigning route: " << e.what() << std::endl;
    }
}

void Bus::changeRoute(Route *r)
{
    if (r == nullptr)
    {
        std::cerr << "Cannot change to a null route." << std::endl;
        return;
    }
    assignedRoute = r;
    std::cout << "Route changed for Bus " << busID << "." << std::endl;
}
