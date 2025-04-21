#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Flight;

class Passenger
{
private:
    string passengerID;
    string name;

public:
    Passenger(string id, string nm) : passengerID(id), name(nm) {}

    string getID() const { return passengerID; }
    string getName() const { return name; }

    void requestBooking(Flight &flight);
    void requestCancellation(Flight &flight);
    void requestUpgrade(Flight &flight);
};

class Flight
{
private:
    string flightNumber;
    string departure;
    string arrival;
    int capacity;
    int bookedSeats;
    vector<string> passengerList;

public:
    Flight(string number, string dep, string arr, int cap)
        : flightNumber(number), departure(dep), arrival(arr), capacity(cap), bookedSeats(0) {}

    void bookSeat(const Passenger &p)
    {
        if (bookedSeats >= capacity)
        {
            cout << "Booking failed: No available seats on flight " << flightNumber << ".\n";
            return;
        }

        if (find(passengerList.begin(), passengerList.end(), p.getID()) != passengerList.end())
        {
            cout << "Passenger " << p.getName() << " already has a booking on this flight.\n";
            return;
        }

        passengerList.push_back(p.getID());
        bookedSeats++;
        cout << "Booking successful for " << p.getName() << " on flight " << flightNumber << ".\n";
    }

    void cancelSeat(const Passenger &p)
    {
        auto it = find(passengerList.begin(), passengerList.end(), p.getID());
        if (it == passengerList.end())
        {
            cout << "Cancellation failed: " << p.getName() << " does not have a booking on flight " << flightNumber << ".\n";
            return;
        }

        passengerList.erase(it);
        bookedSeats--;
        cout << "Booking cancelled for " << p.getName() << " on flight " << flightNumber << ".\n";
    }

    void upgradeSeat(const Passenger &p)
    {
        auto it = find(passengerList.begin(), passengerList.end(), p.getID());
        if (it == passengerList.end())
        {
            cout << "Upgrade failed: " << p.getName() << " does not have a booking to upgrade.\n";
            return;
        }

        cout << "Seat upgraded for " << p.getName() << " on flight " << flightNumber << ".\n";
    }

    void printFlightStatus() const
    {
        cout << "Flight: " << flightNumber << " | From: " << departure << " To: " << arrival
             << "\nCapacity: " << capacity << ", Booked: " << bookedSeats << "\n";
    }
};

void Passenger::requestBooking(Flight &flight)
{
    flight.bookSeat(*this);
}

void Passenger::requestCancellation(Flight &flight)
{
    flight.cancelSeat(*this);
}

void Passenger::requestUpgrade(Flight &flight)
{
    flight.upgradeSeat(*this);
}

int main()
{
    Flight f1("PK303", "Lahore", "Karachi", 2);
    Flight f2("PK404", "Islamabad", "Quetta", 1);

    Passenger p1("P001", "Ali");
    Passenger p2("P002", "Sara");
    Passenger p3("P003", "Hassan");

    p1.requestBooking(f1);
    p2.requestBooking(f1);
    p3.requestBooking(f1);

    f1.printFlightStatus();

    p2.requestCancellation(f1);
    p3.requestBooking(f1);

    p1.requestUpgrade(f1);
    p3.requestUpgrade(f2);

    f1.printFlightStatus();

    return 0;
}
