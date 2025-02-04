#include <iostream>
using namespace std;

class Date
{
public:
    int month;
    int day;
    int year;

    void displayDate()
    {
        cout << month << "/" << day << "/" << year << endl;
    }
};

int main()
{
    Date d;
    d.day = 2;
    d.month = 4;
    d.year = 2014;

    d.displayDate();

    return 0;
}