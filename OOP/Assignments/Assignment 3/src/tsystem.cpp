#include "../include/tsystem.hpp"
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <limits>

TransportationSystem::TransportationSystem()
    : peopleCount(0), routeCount(0), busCount(0),
      peopleCapacity(10), routeCapacity(10), busCapacity(10)
{
    try
    {
        peoples = new Person *[peopleCapacity];
        routes = new Route[routeCapacity];
        buses = new Bus[busCapacity];
    }
    catch (const std::bad_alloc &e)
    {
        std::cerr << "Memory allocation failed during TransportationSystem initialization: " << e.what() << std::endl;
        throw; // Rethrow to allow caller to handle the failure
    }
}

TransportationSystem::~TransportationSystem()
{
    delete[] peoples;
    delete[] routes;
    delete[] buses;
}

void TransportationSystem::registerPeople(Person *s)
{
    if (s == nullptr)
    {
        std::cerr << "Cannot register a null person." << std::endl;
        return;
    }

    try
    {
        if (peopleCount == peopleCapacity)
        {
            peopleCapacity *= 2;
            Person **newPeoples = new Person *[peopleCapacity];
            if (!newPeoples)
            {
                throw std::bad_alloc();
            }

            for (int i = 0; i < peopleCount; i++)
                newPeoples[i] = peoples[i];
            delete[] peoples;
            peoples = newPeoples;
        }
        peoples[peopleCount++] = s;
    }
    catch (const std::bad_alloc &e)
    {
        std::cerr << "Memory allocation failed while resizing peoples array: " << e.what() << std::endl;
    }
}

void TransportationSystem::addRoute(Route r)
{
    try
    {
        if (routeCount == routeCapacity)
        {
            routeCapacity *= 2;
            Route *newRoutes = new Route[routeCapacity];
            if (!newRoutes)
            {
                throw std::bad_alloc();
            }

            for (int i = 0; i < routeCount; i++)
                newRoutes[i] = routes[i];
            delete[] routes;
            routes = newRoutes;
        }
        routes[routeCount++] = r;
    }
    catch (const std::bad_alloc &e)
    {
        std::cerr << "Memory allocation failed while resizing routes array: " << e.what() << std::endl;
    }
}

void TransportationSystem::addBuses(Bus b)
{
    try
    {
        if (busCount == busCapacity)
        {
            busCapacity *= 2;
            Bus *newBuses = new Bus[busCapacity];
            if (!newBuses)
            {
                throw std::bad_alloc();
            }

            for (int i = 0; i < busCount; i++)
                newBuses[i] = buses[i];
            delete[] buses;
            buses = newBuses;
        }
        buses[busCount++] = b;
    }
    catch (const std::bad_alloc &e)
    {
        std::cerr << "Memory allocation failed while resizing buses array: " << e.what() << std::endl;
    }
}
void TransportationSystem::loginMenu(TransportationSystem &system)
{
    static bool loaded = false;
    if (!loaded)
    {
        system.loadFromFiles();
        loaded = true;
    }

    int choice;
    while (true)
    {
        std::cout << "\n=== Login Menu ===\n";
        std::cout << "1. Student Login\n";
        std::cout << "2. Teacher Login\n";
        std::cout << "3. Staff Login\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (choice == 4)
            break;

        std::string id;
        std::cout << "Enter ID: ";
        std::getline(std::cin, id);

        bool found = false;
        for (int i = 0; i < system.peopleCount; ++i)
        {
            Person *p = system.peoples[i];

            if (p->getID() == id)
            {
                found = true;
                p->login();
                system.recordAttendance(*p);
                break;
            }
        }

        if (!found)
        {
            std::cout << "No user found with ID: " << id << "\n";
            std::cout << "Would you like to try again? (y/n): ";
            char retry;
            std::cin >> retry;
            if (retry != 'y' && retry != 'Y')
                break;
        }
    }

    std::cout << "Saving data before exit...\n";
    system.saveAllToFiles();
}

void TransportationSystem::loadFromFiles()
{
    // Load Students
    std::ifstream sFile("students.txt");
    if (sFile.is_open())
    {
        std::string line;
        while (getline(sFile, line))
        {
            if (line.rfind("Student,", 0) == 0) // Checks if the line starts with "Student,"
            {
                std::istringstream ss(line);
                std::string type, id, name, stopID;
                std::getline(ss, type, ',');   // Skip the "Student,"
                std::getline(ss, id, ',');     // Get ID
                std::getline(ss, name, ',');   // Get name
                std::getline(ss, stopID, ','); // Get stopID

                // Create a new Student object and register it
                auto *student = new Student(id, name, stopID);
                registerPeople(student);
            }
        }
        sFile.close();
    }

    // Load Teachers
    std::ifstream tFile("teachers.txt");
    if (tFile.is_open())
    {
        std::string line;
        while (getline(tFile, line))
        {
            if (line.rfind("Teacher,", 0) == 0) // Checks if the line starts with "Teacher,"
            {
                std::istringstream ss(line);
                std::string type, id, name;
                std::getline(ss, type, ','); // Skip the "Teacher,"
                std::getline(ss, id, ',');   // Get ID
                std::getline(ss, name, ','); // Get name

                // Create a new Teacher object and register it
                auto *teacher = new Teacher(id, name);
                registerPeople(teacher);
            }
        }
        tFile.close();
    }

    // Load Staff
    std::ifstream stFile("staff.txt");
    if (stFile.is_open())
    {
        std::string line;
        while (getline(stFile, line))
        {
            if (line.rfind("Staff,", 0) == 0) // Checks if the line starts with "Staff,"
            {
                std::istringstream ss(line);
                std::string type, id, name;
                std::getline(ss, type, ','); // Skip the "Staff,"
                std::getline(ss, id, ',');   // Get ID
                std::getline(ss, name, ','); // Get name

                // Create a new Staff object and register it
                auto *staff = new Staff(id, name);
                registerPeople(staff);
            }
        }
        stFile.close();
    }
}

void TransportationSystem::saveAllToFiles()
{

    std::ofstream studentFile("students.txt", std::ios::trunc);
    std::ofstream teacherFile("teachers.txt", std::ios::trunc);
    std::ofstream staffFile("staff.txt", std::ios::trunc);

    studentFile.close();
    teacherFile.close();
    staffFile.close();

    for (int i = 0; i < peopleCount; ++i)
    {
        if (auto *student = dynamic_cast<Student *>(peoples[i]))
        {
            student->saveToFile("students.txt");
        }
        else if (auto *teacher = dynamic_cast<Teacher *>(peoples[i]))
        {
            teacher->saveToFile("teachers.txt");
        }
        else if (auto *staff = dynamic_cast<Staff *>(peoples[i]))
        {
            staff->saveToFile("staff.txt");
        }
    }
}

void TransportationSystem::assignPersonsToStops(Person *s, BusStop &bs)
{
    if (s == nullptr)
    {
        std::cerr << "Cannot assign a null person to bus stop." << std::endl;
        return;
    }
    bs.assignPerson(s);
}

void TransportationSystem::recordAttendance(Person &p)
{
    try
    {
        p.tapCard();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error recording attendance: " << e.what() << std::endl;
    }
}
int TransportationSystem::getPeopleCount() const
{
    return peopleCount;
}