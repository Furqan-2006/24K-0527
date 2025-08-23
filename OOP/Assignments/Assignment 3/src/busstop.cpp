#include "../include/busstop.hpp"
#include <iostream>
#include <stdexcept>

BusStop::BusStop(std::string id, std::string loc)
    : stopID(id), location(loc), peopleCount(0), capacity(10)
{
    try
    {
        peopleAtStop = new Person *[capacity];
    }
    catch (const std::bad_alloc &e)
    {
        std::cerr << "Memory allocation failed for peopleAtStop: " << e.what() << std::endl;
        throw;
    }
}

BusStop::~BusStop()
{
    delete[] peopleAtStop;
}

void BusStop::assignPerson(Person *p)
{
    if (p == nullptr)
    {
        std::cerr << "Cannot assign a null person to the bus stop." << std::endl;
        return;
    }

    try
    {
        if (peopleCount == capacity)
        {
            capacity *= 2;
            Person **newPeople = new Person *[capacity];

            for (int i = 0; i < peopleCount; i++)
            {
                newPeople[i] = peopleAtStop[i];
            }

            delete[] peopleAtStop;
            peopleAtStop = newPeople;
        }
        peopleAtStop[peopleCount++] = p;
    }
    catch (const std::bad_alloc &e)
    {
        std::cerr << "Memory allocation failed while resizing peopleAtStop: " << e.what() << std::endl;
        throw; // Optional: propagate to caller
    }
    catch (const std::exception &e)
    {
        std::cerr << "Unexpected error in assignPerson: " << e.what() << std::endl;
    }
}

void BusStop::getStopDetails() const
{
    std::cout << "Stop ID: " << stopID << std::endl
              << "Location: " << location << std::endl
              << "People assigned to the stop: " << std::endl;
    for (int i = 0; i < peopleCount; i++)
    {
        if (peopleAtStop[i] != nullptr)
        {
            std::cout << "* " << peopleAtStop[i]->getName() << std::endl;
        }
        else
        {
            std::cerr << "Error: Null person at index " << i << std::endl;
        }
    }
}

std::string BusStop::getStopID() const { return stopID; }
std::string BusStop::getStopLocation() const { return location; }
