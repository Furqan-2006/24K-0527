#include <iostream>
#include <string>
using namespace std;

class Car
{
protected:
    string model;
    float price;

public:
    Car(string m) : model(m), price(0) {}

    virtual void setPrice(float p) = 0;

    string getModel() const
    {
        return model;
    }

    float getPrice() const
    {
        return price;
    }

    virtual void displayInfo() const
    {
        cout << "Model: " << model << ", Price: " << price << endl;
    }

    virtual ~Car() {}
};

class Color : public Car
{
private:
    string color;

public:
    Color(string m, string c) : Car(m), color(c) {}

    void setPrice(float p) override
    {

        price = (color == "Red") ? p + 10000 : p;
    }

    void displayInfo() const override
    {
        cout << "Color Car - Model: " << model
             << ", Color: " << color
             << ", Price: " << price << endl;
    }
};

class Company : public Car
{
private:
    string company;

public:
    Company(string m, string comp) : Car(m), company(comp) {}

    void setPrice(float p) override
    {

        price = (company == "LuxuryAuto") ? p + 50000 : p;
    }

    void displayInfo() const override
    {
        cout << "Company Car - Model: " << model
             << ", Company: " << company
             << ", Price: " << price << endl;
    }
};

int main()
{
    Color car1("Model-X", "Red");
    car1.setPrice(2000000);
    car1.displayInfo();

    Company car2("Model-Z", "LuxuryAuto");
    car2.setPrice(3000000);
    car2.displayInfo();

    return 0;
}
