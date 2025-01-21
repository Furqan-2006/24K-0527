#include <iostream>
using namespace std;

int main()
{
    string cusID, cusName;
    int unitConsumed;
    cout << "Enter Customer Name: ";
    cin >> cusName;
    cout << "Enter Customer ID: ";
    cin >> cusID;
    cout << "Enter units consumed: ";
    cin >> unitConsumed;

    float unitPrice;
    if (unitConsumed >= 0 && unitConsumed <= 199)
    {
        unitPrice = 16.20;
    }
    else if (unitConsumed >= 200 && unitConsumed < 300)
    {
        unitPrice = 20.10;
    }
    else if (unitConsumed >= 300 && unitConsumed < 500)
    {
        unitPrice = 27.10;
    }
    else
    {
        if (unitConsumed > 500)
        {
            unitPrice = 35.90;
        }
    }

    float billAmount = unitConsumed * unitPrice;
    float surcharge;
    if (billAmount > 18000)
    {
        surcharge = (15 * billAmount) / 100;
        billAmount += surcharge;
    }
    printf("\n");
    cout << "Customer ID: " << cusID << endl;
    cout << "Customer Name: " << cusName << endl;
    cout << "Unit Consumed: " << unitConsumed << endl;
    cout << "Price per Unit: " << unitPrice << endl;
    cout << "Surcharge: " << surcharge<<endl;
    cout << "Total Bill: " << billAmount << endl;

    return 0;
}