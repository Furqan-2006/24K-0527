#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char *argv[])
{
    string movName;
    float adultTicPrice, childTicPrice;
    int aTicSold, cTicSold;
    float charityPercentage;

    cout << "Movie Name: ";
    getline(cin, movName);
    cout << "Adult Ticket Price: ";
    cin >> adultTicPrice;
    cout << "Childern Ticket Price: ";
    cin >> childTicPrice;
    cout << "Adult Ticket Sold: ";
    cin >> aTicSold;
    cout << "Childern Ticket Sold: ";
    cin >> cTicSold;
    cout << "Percentage to be donated: ";
    cin >> charityPercentage;

    float grossAmount = (aTicSold * adultTicPrice) + (cTicSold * childTicPrice);
    float charityAmount = (charityPercentage * grossAmount) / 100;
    float netSale = grossAmount - charityAmount;
    system("cls");
    cout << "Movie Name: ----------------------- " << movName << endl;
    cout << "Number of Tickects Sold: ---------- " << (aTicSold + cTicSold) << endl;
    cout << "Gross Amount: --------------------- $" << fixed << setprecision(2) << grossAmount << endl;
    cout << "Percentage of Gross Amount Donated: " << fixed << setprecision(2) << charityPercentage << "%" << endl;
    cout << "Amount Donated: ------------------- $" << fixed << setprecision(2) << charityAmount << endl;
    cout << "Net Sale: ------------------------- $" << fixed << setprecision(2) << netSale << endl;
}