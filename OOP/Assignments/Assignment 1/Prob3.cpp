#include <iostream>
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
    Driver() {};

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
    string *allowedLicenses;
    int licenseCount;

public:
    Vehicle(double rpd, string m, string licenses[], int count)
        : rentPerDay(rpd), model(m), licenseCount(count)
    {
        allowedLicenses = new string[licenseCount];
        for (int i = 0; i < licenseCount; i++)
        {
            allowedLicenses[i] = licenses[i];
        }
    }

    bool isEligible(string license)
    {
        for (int i = 0; i < licenseCount; i++)
        {
            if (allowedLicenses[i] == license)
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

    ~Vehicle()
    {
        delete[] allowedLicenses;
    }
};

class RentalSystem
{
private:
    Driver *users;
    int userCount;
    int capacity;
    Vehicle *vehicle[5];
    int vehicleCount;

public:
    RentalSystem() : userCount(0), vehicleCount(0), capacity(10)
    {
        users = new Driver[capacity];
    }

    void registerUser(string name, int age, string phone, string license, string CNIC)
    {
        if (userCount == capacity)
        {
            capacity *= 2;
            Driver *newUsers = new Driver[capacity];
            for (int i = 0; i < userCount; i++)
            {
                newUsers[i] = users[i];
            }
            delete[] users;
            users = newUsers;
        }
        users[userCount++] = Driver(name, age, phone, license, CNIC);
    }

    void addVehicle(string model, double rent, string licenses[], int count)
    {
        if (vehicleCount < 5)
        {
            vehicle[vehicleCount++] = new Vehicle(rent, model, licenses, count);
        }
        else
        {
            cout << "Garage is Full!" << endl;
        }
    }

    void rentVehicle(string id, string model, int days)
    {
        Driver *user = nullptr;

        for (int i = 0; i < userCount; i++)
        {
            if (users[i].getDriverID() == id)
            {
                user = &users[i];
                break;
            }
        }

        if (!user)
        {
            cout << "User not found! User may not be registered!" << endl;
            return;
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
        delete[] users;
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

    string licenses1[] = {"LTV", "HTV", "IDP", "PSV"};
    string licenses2[] = {"LTV", "IDP", "HTV", "PSV"};
    string licenses3[] = {"LTV", "IDP", "HTV", "PSV"};
    string licenses4[] = {"MC", "LTV", "HTV", "IDP", "PSV"};

    rentalSystem.addVehicle("Honda Civic 2020", 35.00, licenses1, 4);
    rentalSystem.addVehicle("MG GT 2023", 50.00, licenses2, 4);
    rentalSystem.addVehicle("Suzuki Kizashi 2019", 30.00, licenses3, 4);
    rentalSystem.addVehicle("Honda CB 150F 2020", 10.00, licenses4, 5);

    cout << "\n";
    rentalSystem.displayVehicles();

    string CNIC;
    string model;
    int rentDays;

    cout << "\nEnter your CNIC and vehicle model that you want to rent (make sure to type model exactly as displayed): " << endl;
    cout << "\nUser CNIC: ";
    getline(cin, CNIC);
    cout << "Model: ";
    getline(cin, model);
    cout << "Rent Days: ";
    cin >> rentDays;

    rentalSystem.rentVehicle(CNIC, model, rentDays);

    return 0;
}
