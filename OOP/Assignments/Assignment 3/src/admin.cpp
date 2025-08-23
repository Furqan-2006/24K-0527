#include "../include/admin.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <limits>
#include <stdexcept>

// Constructor that takes a reference to the TransportationSystem
Admin::Admin(TransportationSystem &ts) : system(ts) {}

// Load all the data from the necessary files
void Admin::loadAllData()
{
    try
    {
        loadStudents("files/students.txt");
        loadTeachers("files/teachers.txt");
        loadStaff("files/staff.txt");
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error loading data: " << e.what() << std::endl;
    }
}

// Load student data from a file
void Admin::loadStudents(const std::string &filename)
{
    std::ifstream sFile(filename);
    if (!sFile.is_open())
    {
        std::cerr << "Failed to open students file: " << filename << std::endl;
        return;
    }

    std::string line;
    while (getline(sFile, line))
    {
        try
        {
            if (line.rfind("Student,", 0) == 0)
            {
                auto *student = new Student();
                std::ofstream temp("temp_student.txt");
                if (!temp.is_open())
                    throw std::runtime_error("Failed to create temp_student.txt");

                temp << line << "\n";
                temp.close();

                student->loadFromFile("temp_student.txt");
                system.registerPeople(student);
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << "Error loading student: " << e.what() << std::endl;
        }
    }
}

// Load teacher data from a file
void Admin::loadTeachers(const std::string &filename)
{
    std::ifstream tFile(filename);
    if (!tFile.is_open())
    {
        std::cerr << "Failed to open teachers file: " << filename << std::endl;
        return;
    }

    std::string line;
    while (getline(tFile, line))
    {
        try
        {
            if (line.rfind("Teacher,", 0) == 0)
            {
                auto *teacher = new Teacher();
                std::ofstream temp("temp_teacher.txt");
                if (!temp.is_open())
                    throw std::runtime_error("Failed to create temp_teacher.txt");

                temp << line << "\n";
                temp.close();

                teacher->loadFromFile("temp_teacher.txt");
                system.registerPeople(teacher);
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << "Error loading teacher: " << e.what() << std::endl;
        }
    }
}

// Load staff data from a file
void Admin::loadStaff(const std::string &filename)
{
    std::ifstream stFile(filename);
    if (!stFile.is_open())
    {
        std::cerr << "Failed to open staff file: " << filename << std::endl;
        return;
    }

    std::string line;
    while (getline(stFile, line))
    {
        try
        {
            if (line.rfind("Staff,", 0) == 0)
            {
                auto *staff = new Staff();
                std::ofstream temp("temp_staff.txt");
                if (!temp.is_open())
                    throw std::runtime_error("Failed to create temp_staff.txt");

                temp << line << "\n";
                temp.close();

                staff->loadFromFile("temp_staff.txt");
                system.registerPeople(staff);
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << "Error loading staff: " << e.what() << std::endl;
        }
    }
}

// Save all the data to the respective files
void Admin::saveAllData()
{
    try
    {
        std::ofstream studentFile("files/students.txt", std::ios::trunc);
        std::ofstream teacherFile("files/teachers.txt", std::ios::trunc);
        std::ofstream staffFile("files/staff.txt", std::ios::trunc);

        if (!studentFile || !teacherFile || !staffFile)
            throw std::runtime_error("One or more output files could not be opened.");

        studentFile.close();
        teacherFile.close();
        staffFile.close();

        for (int i = 0; i < system.getPeopleCount(); ++i)
        {
            try
            {
                if (auto *student = dynamic_cast<Student *>(system.peoples[i]))
                {
                    student->saveToFile("files/students.txt");
                }
                else if (auto *teacher = dynamic_cast<Teacher *>(system.peoples[i]))
                {
                    teacher->saveToFile("files/teachers.txt");
                }
                else if (auto *staff = dynamic_cast<Staff *>(system.peoples[i]))
                {
                    staff->saveToFile("files/staff.txt");
                }
            }
            catch (const std::exception &e)
            {
                std::cerr << "Error saving a record: " << e.what() << std::endl;
            }
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error saving data: " << e.what() << std::endl;
    }
}

// Admin menu with input protection
void Admin::showMenu()
{
    int choice;
    while (true)
    {
        std::cout << "\n=== Admin Menu ===\n";
        std::cout << "1. Load all data\n";
        std::cout << "2. Save all data\n";
        std::cout << "3. Register new person\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";

        if (!(std::cin >> choice))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clean input

        switch (choice)
        {
        case 1:
            loadAllData();
            std::cout << "Data loaded successfully.\n";
            break;
        case 2:
            saveAllData();
            std::cout << "Data saved successfully.\n";
            break;
        case 3:
            std::cout << "Functionality to register a new person can be added here.\n";
            break;
        case 4:
            return;
        default:
            std::cout << "Invalid choice, please try again.\n";
        }
    }
}
