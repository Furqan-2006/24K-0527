#pragma once

#include <iostream>
#include <fstream>
#include <string>

class Person
{
protected:
    std::string ID;
    std::string name;
    double balance;
    bool hasPaid;

public:
    Person(std::string id = "", std::string n = "");
    virtual void payTransportFee(double amount) = 0;
    virtual void tapCard();
    virtual void login() = 0;

    virtual ~Person() {}

    std::string getName() const;
    std::string getID() const;
    double getBalance() const;

    void operator+=(double amount);
};