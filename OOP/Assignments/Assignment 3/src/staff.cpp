#include "../include/staff.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>

Staff::Staff(std::string id, std::string n) : Person(id, n) {}

void Staff::payTransportFee(double amount)
{
    if (amount < 0)
    {
        std::cerr << "Invalid amount!" << std::endl;
        return;
    }

    *this += amount;

    std::cout << "Amount Deposited: " << amount
              << "\nCurrent Balance: " << balance << std::endl;

    if (balance >= 3500)
    {
        hasPaid = true;
        std::cout << "Fees paid! Staff member has activated their transport card." << std::endl;
    }
    else
    {
        std::cout << "Pay full fees (3500) to activate transport access." << std::endl;
    }
}

void Staff::tapCard()
{
    std::cout << (hasPaid ? "Staff attendance marked." : "Access Denied! Pay Fees.") << std::endl;
}

void Staff::login()
{
    std::string enteredID;

    std::cout << "---- Staff Login ----" << std::endl;
    std::cout << "Enter Staff ID: ";
    std::cin >> enteredID;

    if (enteredID == ID)
    {
        std::cout << "Login successful. Welcome, " << name << "!" << std::endl;
    }
    else
    {
        std::cout << "Login failed. Invalid ID." << std::endl;
    }
}

void Staff::saveToFile(const std::string &filename) const
{
    try
    {
        std::ofstream out(filename, std::ios::app);
        if (!out)
        {
            throw std::ios_base::failure("Failed to open file for writing: " + filename);
        }

        out << "Staff," << ID << "," << name << "," << balance << "," << hasPaid << "\n";
        out.close();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception in saveToFile: " << e.what() << std::endl;
    }
}

void Staff::loadFromFile(const std::string &filename)
{
    try
    {
        std::ifstream in(filename);
        if (!in)
        {
            throw std::ios_base::failure("Failed to open file for reading: " + filename);
        }

        std::string line;
        while (getline(in, line))
        {
            std::stringstream ss(line);
            std::string type;

            if (!getline(ss, type, ',') || type != "Staff")
                continue;

            if (!getline(ss, ID, ',') || !getline(ss, name, ','))
                throw std::runtime_error("Corrupted staff data: missing ID or name");

            std::string balanceStr, paidStr;
            if (!getline(ss, balanceStr, ',') || !getline(ss, paidStr))
                throw std::runtime_error("Corrupted staff data: missing balance or payment status");

            try
            {
                balance = std::stod(balanceStr);
                hasPaid = std::stoi(paidStr);
            }
            catch (const std::exception &e)
            {
                throw std::runtime_error("Conversion error: " + std::string(e.what()));
            }

            break;
        }

        in.close();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception in loadFromFile: " << e.what() << std::endl;
    }
}
