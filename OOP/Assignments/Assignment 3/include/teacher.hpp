#pragma once

#include "Person.hpp"
#include "handler.hpp"

class Teacher : public Person, public FileIO
{
public:
    Teacher(std::string id = "", std::string n = "");
    void payTransportFee(double amount) override;
    void tapCard() override;

    void saveToFile(const std::string &filename) const override;
    void loadFromFile(const std::string &filename) override;
    void login() override;

};