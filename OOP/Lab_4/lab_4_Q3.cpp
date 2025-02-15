#include <iostream>
using namespace std;

class Invoice
{
    string partNum;
    string description;
    int quantity;
    double pricePerItem;

public:
    Invoice(string pN, string descrip, int quan, double pr)
        : partNum(pN), description(descrip), quantity(quan), pricePerItem(pr) {}

    double getInvoiceAmount()
    {
        return quantity * pricePerItem;
    }

    void setPrice(double pr)
    {
        if (pr < 0)
            pricePerItem = 0.0;
        else
            pricePerItem = pr;
    }

    void setQuantity(int quan)
    {
        if (quan < 0)
            quantity = 0;
        else
            quantity = quan;
    }
};

int main()
{
    string itemPartNumber;
    string itemDescription;
    int itemsPurchased;
    double itemPrice;
    cout << "Enter the details of the item: " << endl;
    cout << "Part #: ";
    cin >> itemPartNumber;
    cout << "Description: ";
    cin.ignore();
    getline(cin, itemDescription);
    cout << "Quantity of items purchased: ";
    cin >> itemsPurchased;
    cout << "Price per Item: ";
    cin >> itemPrice;

    Invoice i1(itemPartNumber, itemDescription, itemsPurchased, itemPrice);

    cout << "Invoice Amount generated is : $" << i1.getInvoiceAmount() << endl;

    return 0;
}
