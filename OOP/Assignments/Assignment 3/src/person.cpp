#include "../include/person.hpp"

Person::Person(std::string id, std::string n) : ID(id), name(n), balance(0), hasPaid(false) {}

std::string Person::getName() const { return name; }
std::string Person::getID() const { return ID; }
double Person::getBalance() const { return balance; }

void Person::operator+=(double amount)
{
    if (amount >= 0)
        balance += amount;
}

void Person::tapCard()
{
    std::cout << (hasPaid ? "Attendance Marked for: " + name : "Access Denied!") << std::endl;
}