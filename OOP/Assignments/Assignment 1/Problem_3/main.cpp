#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class Driver
{
private:
    string name;
    int age;
    string phoneNum;
    string licenseType; // learner, LTV, HTV, MC, PSV, IDP
    string CNIC;

public:
    Driver(string n, int a, string p, string l, string c) : name(n), age(a), phoneNum(p), licenseType(l), CNIC(c) {};

    void updateDetails(int newAge, string newPhoneNum, string newLicenseType)
    {
        age = newAge;
        phoneNum = newPhoneNum;
        licenseType = newLicenseType;
    }
    string getDriverID()
    {
        return CNIC;
    }
    string getLicenseType()
    {
        return licenseType;
    }
};
class Vehicle
{
private:
    double rentPerDay;
    string model;
    vector<string> allowedLicenses;

public:
    Vehicle(double rpd, string m, vector<string> al)
        : rentPerDay(rpd), model(m), allowedLicenses(al) {};

    bool isEligible(string lisence)
    {
        for (const auto &type : allowedLicenses)
        {
            if (type == lisence)
            {
                return true;
            }
        }
        return false;
    }

    void displayVehicle()
    {
        cout << left << "| " << setw(25) << model << "| Price per day: $" << setw(5) << rentPerDay << " |" << endl;
    }
    string getModel()
    {
        return model;
    }
    double getRent()
    {
        return rentPerDay;
    }
};

class RentalSystem
{
private:
    vector<Driver> users;
    Vehicle *vehicle[5];
    int vehicleCount = 0;

public:
    void registerUser(string name, int age, string phone, string license, string CNIC)
    {
        users.push_back(Driver(name, age, phone, license, CNIC));
    }
    void addvehicle(string model, double rent, vector<string> lincenses)
    {
        if (vehicleCount < 5)
        {
            vehicle[vehicleCount++] = new Vehicle(rent, model, lincenses);
        }
        else
        {
            cout << "Garage is Full!" << endl;
        }
    }

    void rentVehicle(string id, string model, int days)
    {
        Driver *user = nullptr;
        for (auto &u : users)
        {
            if (u.getDriverID() == id)
            {
                user = &u;
                break;
            }
        }

        if (!user)
        {

            cout << "User not found! User may not be registered!" << endl;
        }
        for (int i = 0; i < vehicleCount; i++)
        {
            if (vehicle[i]->getModel() == model)
            {
                if (vehicle[i]->isEligible(user->getLicenseType()))
                {
                    cout << "You have successfully rented " << model << "." << endl;
                    cout << "Total Rent: $" << vehicle[i]->getRent() * days << "." << endl;
                    
                }
                else
                {
                    cout << "Sorry! You are not eligible to rent this vehicle." << endl;
                }
                return;
            }
        }
        cout << "Vehicle Not Found!" << endl;
    }
    void displayVehicles()
    {
        cout << "----------------------------------------------------------------" << endl;
        for (int i = 0; i < vehicleCount; i++)
        {
            cout << "| " << i + 1 << ". ";
            vehicle[i]->displayVehicle();
        }
        cout << "----------------------------------------------------------------" << endl;
    }
    ~RentalSystem()
    {
        for (int i = 0; i < vehicleCount; i++)
        {
            delete vehicle[i];
        }
    }
};

int main()
{
    RentalSystem rentalSystem;

    rentalSystem.registerUser("Abu Bakr", 23, "+92-312-1234567", "LTV", "42201-1234567-1");
    rentalSystem.registerUser("Furqan", 23, "+92-302-1234567", "learner", "42201-1234567-3");
    rentalSystem.registerUser("Saahil", 23, "+92-333-1234567", "IDP", "42201-1234567-5");

    rentalSystem.addvehicle("Honda Civic 2020", 35.00, {"LTV", "HTV", "IDP", "PSV"});
    rentalSystem.addvehicle("MG GT 2023", 50.00, {"LTV", "IDP", "HTV", "PSV"});
    rentalSystem.addvehicle("Suzuki Kizashi 2019", 30.00, {"LTV", "IDP", "HTV", "PSV"});
    rentalSystem.addvehicle("Honda CB 150F 2020", 10.00, {"MC", "LTV", "HTV", "IDP", "PSV"});

    cout << "\n";
    rentalSystem.displayVehicles();

    string CNIC;
    string model;
    int rentDays;

    cout << "\nEnter your CNIC and vehicle model that you want to register (make sure to type model exactly as displayed): " << endl;
    // User input
    cout << "\nUser CNIC: ";
    getline(cin, CNIC);
    cout << "Model: ";
    getline(cin, model);
    cout << "Rent Days: ";
    cin >> rentDays;

    rentalSystem.rentVehicle(CNIC, model, rentDays);
    

    return 0;
}
