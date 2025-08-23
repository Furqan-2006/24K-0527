#include "../include/student.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>

Student::Student(std::string id, std::string n, std::string sid)
    : Person(id, n), stopID(sid), attendance(0) {}

void Student::payTransportFee(double amount)
{
    if (amount < 0)
    {
        std::cerr << "Invalid amount!" << std::endl;
        return;
    }

    *this += amount;

    std::cout << "Amount Deposited: " << amount
              << "\nCurrent Balance: " << balance << std::endl;

    if (balance >= 45000)
    {
        hasPaid = true;
        std::cout << "Fees paid! Student has activated their transport card." << std::endl;
    }
    else
    {
        std::cout << "Pay full fees (45000) to activate transport access." << std::endl;
    }
}

void Student::tapCard()
{
    if (hasPaid)
    {
        std::cout << "Attendance Recorded for " << name << "!" << std::endl;
        attendance++;
    }
    else
    {
        std::cerr << "YOU ARE NOT ALLOWED! PAY FEES TO GET ACCESS!" << std::endl;
    }
}

void Student::login()
{
    std::string enteredID, enteredPassword;

    std::cout << "---- Student Login ----" << std::endl;
    std::cout << "Enter Student ID: ";
    std::cin >> enteredID;

    std::cout << "Enter Password: ";
    std::cin >> enteredPassword;

    if (enteredID == ID && enteredPassword == password)
    {
        std::cout << "Login successful. Welcome, " << name << "!" << std::endl;
    }
    else
    {
        std::cout << "Login failed. Invalid credentials." << std::endl;
    }
}

void Student::saveToFile(const std::string &filename) const
{
    try
    {
        std::ofstream out(filename, std::ios::app);
        if (!out)
        {
            throw std::ios_base::failure("Failed to open file for writing: " + filename);
        }

        out << "Student," << ID << "," << name << "," << balance << "," << hasPaid << ","
            << stopID << "," << attendance << "\n";
        out.close();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception in saveToFile: " << e.what() << std::endl;
    }
}

void Student::loadFromFile(const std::string &filename)
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

            if (!getline(ss, type, ',') || type != "Student")
                continue;

            std::string balanceStr, paidStr, attendanceStr;

            if (!getline(ss, ID, ',') || !getline(ss, name, ',') ||
                !getline(ss, balanceStr, ',') || !getline(ss, paidStr, ',') ||
                !getline(ss, stopID, ',') || !getline(ss, attendanceStr))
            {
                throw std::runtime_error("Corrupted student data: missing fields");
            }

            try
            {
                balance = std::stod(balanceStr);
                hasPaid = std::stoi(paidStr);
                attendance = std::stoi(attendanceStr);
            }
            catch (const std::exception &e)
            {
                throw std::runtime_error("Conversion error: " + std::string(e.what()));
            }

            break; // Load only first student entry
        }

        in.close();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception in loadFromFile: " << e.what() << std::endl;
    }
}
