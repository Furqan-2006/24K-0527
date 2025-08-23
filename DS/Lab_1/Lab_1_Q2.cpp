#include <iostream>
#include <cstring>

class MovieTicket
{
public:
    char *name;
    int seatNum;

    MovieTicket(const char *n, int s)
    {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        seatNum = s;
    }

    ~MovieTicket()
    {
        delete[] name;
    }

    MovieTicket(const MovieTicket &other)
    {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        this->seatNum = other.seatNum;
    }

    MovieTicket &operator=(const MovieTicket &other)
    {
        if (this != &other)
        {
            name = new char[strlen(other.name) + 1];
            strcpy(name, other.name);
            seatNum = other.seatNum;
        }
        return *this;
    }

    void displayAll()
    {
        std::cout << "Name: " << name << std::endl
                  << "SeatNum: " << seatNum << std::endl
                  << std::endl;
    }
    void setName(const char *n)
    {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }
};

int main()
{
    MovieTicket t1("thor", 3);
    MovieTicket t2(t1);
    MovieTicket t3 = t1;

    t1.displayAll();
    t2.displayAll();
    t3.displayAll();

    t2.setName("hulk");

    t1.displayAll();
    t2.displayAll();
}
