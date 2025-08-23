#pragma once

#include "tsystem.hpp"


class Admin
{

private:
    TransportationSystem &system;

    void loadStudents(const std::string &filename);
    void loadTeachers(const std::string &filename);
    void loadStaff(const std::string &filename);

public:
    Admin(TransportationSystem &ts);

    void loadAllData();       // Load from files when needed
    void saveAllData();       // Save back to files
    // void registerNewPerson(); // Example function for registration
    void showMenu();          // Optional: user interface
};