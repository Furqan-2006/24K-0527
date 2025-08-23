#include "include/admin.hpp"
#include "include/tsystem.hpp"
#include <iostream>
#include <limits>
#include <exception>

int main()
{
    TransportationSystem system;

    try
    {

        system.loadFromFiles();
    }
    catch (const std::ios_base::failure &e)
    {
        std::cerr << "Error loading data from files: " << e.what() << std::endl;
        return 1;
    }
    catch (const std::exception &e)
    {
        std::cerr << "An unexpected error occurred during initialization: " << e.what() << std::endl;
        return 1;
    }

    int choice;
    while (true)
    {
        try
        {
            std::cout << "\n=== Main Menu ===\n";
            std::cout << "1. Login as Admin\n";
            std::cout << "2. Login as User (Student, Teacher, Staff)\n";
            std::cout << "3. Exit\n";
            std::cout << "Enter your choice: ";
            std::cin >> choice;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            if (choice == 3)
                break;

            if (choice == 1)
            {

                try
                {
                    Admin admin(system);
                    admin.showMenu();
                }
                catch (const std::exception &e)
                {
                    std::cerr << "Error during admin login: " << e.what() << std::endl;
                }
            }
            else if (choice == 2)
            {

                try
                {
                    system.loginMenu(system);
                }
                catch (const std::exception &e)
                {
                    std::cerr << "Error during user login: " << e.what() << std::endl;
                }
            }
            else
            {
                std::cout << "Invalid option, please try again.\n";
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << "Error processing menu choice: " << e.what() << std::endl;
        }
    }

    std::cout << "Exiting the system...\n";

    try
    {
        system.saveAllToFiles();
    }
    catch (const std::ios_base::failure &e)
    {
        std::cerr << "Error saving data to files: " << e.what() << std::endl;
        return 1;
    }
    catch (const std::exception &e)
    {
        std::cerr << "An unexpected error occurred while saving data: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
