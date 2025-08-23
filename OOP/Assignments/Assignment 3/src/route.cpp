#include "../include/route.hpp"
#include <iostream>
#include <stdexcept>

Route::Route() : routeNum(0), stopCount(0), capacity(10)
{
    try
    {
        busStops = new BusStop[capacity];
    }
    catch (const std::bad_alloc &e)
    {
        std::cerr << "Memory allocation failed for busStops: " << e.what() << std::endl;
        throw; // Rethrow to allow caller to handle the failure
    }
}

Route::Route(int num) : routeNum(num), stopCount(0), capacity(10)
{
    try
    {
        busStops = new BusStop[capacity];
    }
    catch (const std::bad_alloc &e)
    {
        std::cerr << "Memory allocation failed for busStops: " << e.what() << std::endl;
        throw; // Rethrow to allow caller to handle the failure
    }
}

Route::~Route()
{
    delete[] busStops;
}

void Route::addBusStop(const BusStop &bs)
{
    try
    {
        if (stopCount == capacity)
        {
            capacity *= 2;
            BusStop *newStops = new BusStop[capacity];
            if (!newStops)
            {
                throw std::bad_alloc();
            }

            for (int i = 0; i < stopCount; i++)
                newStops[i] = busStops[i];
            delete[] busStops;
            busStops = newStops;
        }

        busStops[stopCount++] = bs;
    }
    catch (const std::bad_alloc &e)
    {
        std::cerr << "Memory allocation failed while resizing busStops: " << e.what() << std::endl;
    }
}

bool Route::operator==(const Route &other) const
{
    if (stopCount != other.stopCount)
        return false;
    for (int i = 0; i < stopCount; i++)
    {
        if (busStops[i].getStopID() != other.busStops[i].getStopID())
            return false;
    }
    return true;
}

void Route::getRouteDetails() const
{
    std::cout << "Route #: " << routeNum << std::endl
              << "Bus Stops on Route# " << routeNum << std::endl;
    for (int i = 0; i < stopCount; i++)
    {
        try
        {
            std::cout << i << ". Stop ID: " << busStops[i].getStopID()
                      << ", Stop location: " << busStops[i].getStopLocation() << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << "Error accessing stop details: " << e.what() << std::endl;
        }
    }
}
