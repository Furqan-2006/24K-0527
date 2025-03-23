#include <iostream>
#include <string>
using namespace std;

class Currency
{
protected:
    double amount;
    string currencyCode;
    string currencySymbol;
    double exchangeRate;

public:
    Currency(double amt, string code, string symbol, double rate)
        : amount(amt), currencyCode(code), currencySymbol(symbol), exchangeRate(rate) {}

    virtual double convertToBase()
    {
        return amount * exchangeRate;
    }

    virtual double convertTo(double targetRate)
    {
        return convertToBase() / targetRate;
    }

    virtual void displayCurrency()
    {
        cout << currencySymbol << amount << " (" << currencyCode << ")" << endl;
    }
};

class Dollar : public Currency
{
public:
    Dollar(double amt) : Currency(amt, "USD", "$", 1.0) {}

    void displayCurrency() override
    {
        cout << "$" << amount << " (USD)" << endl;
    }
};

class Euro : public Currency
{
public:
    Euro(double amt) : Currency(amt, "EUR", "€", 1.1) {}

    void displayCurrency() override
    {
        cout << "€" << amount << " (EUR)" << endl;
    }
};

class Rupee : public Currency
{
public:
    Rupee(double amt) : Currency(amt, "INR", "₹", 0.012) {}

    void displayCurrency() override
    {
        cout << "₹" << amount << " (INR)" << endl;
    }
};

int main()
{
    Dollar usd(100);
    Euro eur(100);
    Rupee inr(100);

    usd.displayCurrency();
    cout << "Converted to base currency (USD): " << usd.convertToBase() << endl;

    eur.displayCurrency();
    cout << "Converted to USD: " << eur.convertTo(1.0) << endl;

    inr.displayCurrency();
    cout << "Converted to USD: " << inr.convertTo(1.0) << endl;

    return 0;
}
