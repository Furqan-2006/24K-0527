#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class BigInteger
{
    vector<int> digits;
    bool isNegative;

public:
    BigInteger() : isNegative(false)
    {
        digits.push_back(0);
    }
    BigInteger(string num);

    void trim();
    static BigInteger add(const BigInteger &a, const BigInteger &b);
    static BigInteger subtract(const BigInteger &a, const BigInteger &b);

    friend ostream &operator<<(ostream &out, const BigInteger &num);
    friend istream &operator>>(istream &in, BigInteger &num);

    BigInteger operator+(const BigInteger &other) const;
    BigInteger operator-(const BigInteger &other) const;
    bool operator==(const BigInteger &other) const;
    bool operator!=(const BigInteger &other) const;
    bool operator<(const BigInteger &other) const;
    bool operator>(const BigInteger &other) const;
};

void BigInteger::trim()
{
    while (!digits.empty() && digits.back() == 0)
    {
        digits.pop_back();
    }
    if (digits.empty())
    {
        isNegative = false;
        digits.push_back(0);
    }
}
BigInteger::BigInteger(string num)
{
    if (num.empty())
    {
        throw invalid_argument("Empty string is not a valid number");
    }
    isNegative = (num[0] == '-');
    if (isNegative && num.length() == 1)
    {
        throw invalid_argument("'-' alone is not a valid number");
    }
    for (int i = num.length() - 1; i >= (isNegative ? 1 : 0); i--)
    {
        if (!isdigit(num[i]))
        {
            throw invalid_argument("Invalid character in number");
        }
        digits.push_back(num[i] - '0');
    }
    trim();
}

BigInteger BigInteger::add(const BigInteger &a, const BigInteger &b)
{
    BigInteger result;
    result.digits.clear();
    int carry = 0;
    size_t maxSize = max(a.digits.size(), b.digits.size());
    for (int i = 0; i < maxSize || carry; i++)
    {
        int sum = carry;
        if (i < a.digits.size())
            sum += a.digits[i];
        if (i < b.digits.size())
            sum += b.digits[i];
        result.digits.push_back(sum % 10);
        carry = sum / 10;
    }
    result.trim();
    return result;
}

BigInteger BigInteger::subtract(const BigInteger &a, const BigInteger &b)
{
    if (a < b)
    {
        BigInteger result = subtract(b, a);
        result.isNegative = true;
        return result;
    }

    BigInteger result;
    result.digits.clear();
    int borrow = 0;
    for (size_t i = 0; i < a.digits.size(); i++)
    {
        int diff = a.digits[i] - borrow - (i < b.digits.size() ? b.digits[i] : 0);
        borrow = (diff < 0);
        if (borrow)
        {
            diff += 10;
        }
        result.digits.push_back(diff);
    }
    result.trim();
    return result;
}

BigInteger BigInteger::operator+(const BigInteger &other) const
{
    if (isNegative == other.isNegative)
    {
        BigInteger sum = add(*this, other);
        sum.isNegative = isNegative;
        return sum;
    }
    return isNegative ? subtract(other, *this) : subtract(*this, other);
}

BigInteger BigInteger::operator-(const BigInteger &other) const
{
    if (isNegative != other.isNegative)
    {
        BigInteger sum = add(*this, other);
        sum.isNegative = isNegative;
        return sum;
    }

    if (*this < other)
    {
        BigInteger result = subtract(other, *this);
        result.isNegative = !isNegative;
        return result;
    }
    return subtract(*this, other);
}

bool BigInteger::operator==(const BigInteger &other) const
{
    return isNegative == other.isNegative && digits == other.digits;
}
bool BigInteger::operator!=(const BigInteger &other) const
{
    return !(*this == other);
}
bool BigInteger::operator<(const BigInteger &other) const
{
    if (isNegative != other.isNegative)
        return isNegative;
    if (digits.size() != other.digits.size())
    {
        return isNegative ? digits.size() > other.digits.size() : digits.size() < other.digits.size();
    }
    for (int i = digits.size() - 1; i >= 0; i--)
    {
        if (digits[i] != other.digits[i])
            return isNegative ? digits[i] > other.digits[i] : digits[i] < other.digits[i];
    }
    return false;
}

bool BigInteger::operator>(const BigInteger &other) const
{
    return other < *this;
}
ostream &operator<<(ostream &out, const BigInteger &num)
{
    if (num.isNegative)
        out << "-";
    for (int i = num.digits.size() - 1; i >= 0; i--)
    {
        out << num.digits[i];
    }
    return out;
}

istream &operator>>(istream &in, BigInteger &num)
{
    string str;
    in >> str;
    num = BigInteger(str);
    return in;
}

int main()
{
    BigInteger num1, num2;
    cout << "Enter two large integers: \n";
    cout << "Integer 1: ";
    cin >> num1;
    cout << "Integer 2: ";
    cin >> num2;

    cout << "Sum: " << (num1 + num2) << endl;
    cout << "Difference: " << (num1 - num2) << endl;
    cout << "Comparison: " << (num1 == num2 ? "Equal" : "Not Equal") << endl;

    return 0;
}