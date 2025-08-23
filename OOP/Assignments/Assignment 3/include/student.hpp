#pragma once

#include "person.hpp"
#include "handler.hpp"

class Student : public Person, public FileIO
{
    std::string stopID;
    int attendance;
    std::string password;


public:
    Student(std::string id = "", std::string n = "", std::string sid = "");
    void payTransportFee(double amount) override;
    void tapCard() override;

    void saveToFile(const std::string &filename) const override;
    void loadFromFile(const std::string &filename) override;

    void login() override;
};