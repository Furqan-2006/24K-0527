#include "../include/teacher.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <ctime>

Teacher::Teacher(std::string id, std::string n) : Person(id, n) {}

void Teacher::payTransportFee(double amount)
{
    if (amount < 0)
    {
        std::cerr << "Invalid amount!" << std::endl;
        return;
    }
    *this += amount;
    std::cout << "Amount Deposited: " << amount << "\nCurrent Balance: " << balance << std::endl;
    if (balance >= 5000)
    {
        hasPaid = true;
        std::cout << "Fees paid! Teacher has activated their transport card." << std::endl;
    }
    else
    {
        std::cout << "Pay full fees (5000) to activate transport access." << std::endl;
    }
}

void Teacher::tapCard()
{
    std::cout << (hasPaid ? "Teacher attendance marked." : "Access Denied! Pay Fees.") << std::endl;
}

void Teacher::login()
{
    std::string enteredID;
    std::cout << "---- Teacher Login ----\nEnter ID: ";
    std::cin >> enteredID;

    if (enteredID != ID)
    {
        std::cout << "Invalid ID.\n";
        return;
    }

    srand(static_cast<unsigned>(time(nullptr)));
    int generatedOTP = 1000 + rand() % 9000;
    std::cout << "OTP sent: " << generatedOTP << std::endl;

    int enteredOTP;
    std::cout << "Enter OTP: ";
    std::cin >> enteredOTP;

    if (enteredOTP == generatedOTP)
    {
        std::cout << "Login successful. Welcome, " << name << "!" << std::endl;
    }
    else
    {
        std::cout << "Invalid OTP. Access Denied." << std::endl;
    }
}

void Teacher::saveToFile(const std::string &filename) const
{
    try
    {
        std::ofstream out(filename, std::ios::app);
        if (!out)
        {
            throw std::ios_base::failure("Failed to open file for writing: " + filename);
        }

        out << "Teacher," << ID << "," << name << "," << balance << "," << hasPaid << "\n";
        out.close();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception in saveToFile: " << e.what() << std::endl;
    }
}

void Teacher::loadFromFile(const std::string &filename)
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

            if (!getline(ss, type, ',') || type != "Teacher")
                continue;

            std::string balanceStr, paidStr;

            if (!getline(ss, ID, ',') || !getline(ss, name, ',') ||
                !getline(ss, balanceStr, ',') || !getline(ss, paidStr))
            {
                throw std::runtime_error("Corrupted teacher data: missing fields");
            }

            try
            {
                balance = std::stod(balanceStr);
                hasPaid = std::stoi(paidStr);
            }
            catch (const std::exception &e)
            {
                throw std::runtime_error("Conversion error: " + std::string(e.what()));
            }

            break; // Load only the first matching teacher
        }

        in.close();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception in loadFromFile: " << e.what() << std::endl;
    }
}
