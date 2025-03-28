#include <iostream>
using namespace std;

class Fraction
{
protected:
    int numerator, denominator;

public:
    Fraction() {}
    Fraction(int n, int d) : numerator(n), denominator(d) {}

    int gcd(int a, int b)
    {
        return (b == 0) ? a : gcd(b, a % b);
    }
    void reduce()
    {
        int GCD = gcd(abs(numerator), abs(denominator));

        numerator /= GCD;
        denominator /= GCD;

        if (denominator < 0)
        {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

    void showFrac()
    {
        if (denominator < 0)
        {
            numerator = -numerator;
            denominator = -denominator;
        }
        cout << numerator << "/" << denominator << endl;
    }
    Fraction operator+(const Fraction &obj)
    {
        return Fraction(numerator * obj.denominator + obj.numerator * denominator, denominator * obj.denominator);
    }
    Fraction operator-(const Fraction &obj)
    {
        return Fraction(numerator * obj.denominator - obj.numerator * denominator, denominator * obj.denominator);
    }

    Fraction operator*(const Fraction &obj)
    {
        return Fraction(numerator * obj.numerator, denominator * obj.denominator);
    }
    Fraction operator/(const Fraction &obj)
    {
        return Fraction(numerator * obj.denominator, denominator * obj.numerator);
    }

    int operator==(const Fraction &other)
    {
        return (numerator == other.numerator && denominator == other.denominator);
    }
    int operator!=(const Fraction &other)
    {
        return (numerator != other.numerator && denominator != other.denominator);
    }

    int operator<(const Fraction &other)
    {
        return (numerator < other.numerator && denominator < other.denominator);
    }
    int operator>(const Fraction &other)
    {
        return (numerator > other.numerator && denominator > other.denominator);
    }
    int operator<=(const Fraction &other)
    {
        return (numerator <= other.numerator && denominator <= other.denominator);
    }
    int operator>=(const Fraction &other)
    {
        return (numerator >= other.numerator && denominator >= other.denominator);
    }

    friend ostream &operator<<(ostream &out, const Fraction &f);
    friend istream &operator>>(istream &in, Fraction &f);
};
ostream &operator<<(ostream &out, const Fraction &f)
{
    out << f.numerator << "/" << f.denominator << endl;
    return out;
}
istream &operator>>(istream &in, Fraction &f)
{
    char slash;
    in >> f.numerator >> slash >> f.denominator;
    if (f.denominator == 0)
    {
        throw invalid_argument("Denominator cannot be zero!");
    }

    return in;
}
int main()
{
    Fraction f1, f2;
    cout << "Enter two fractions (format: a/b): ";
    cin >> f1 >> f2;

    Fraction sum = f1 + f2;
    cout << "Sum: " << sum << endl;

    Fraction diff = f1 - f2;
    cout << "Difference: " << diff << endl;

    Fraction mul = f1 + f2;
    cout << "Product: " << mul << endl;

    Fraction div = f1 + f2;
    cout << "Quotient: " << div << endl;

    bool comp1 = f1 < f2;
    cout << "Lesser Fraction: " << (comp1 ? f1 : f2) << endl;
    
    bool comp2 = f1 > f2;
    cout << "Greater Fraction: " << (comp2 ? f1 : f2) << endl;

    return 0;
}
