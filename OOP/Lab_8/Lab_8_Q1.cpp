#include <iostream>
#include <string>
using namespace std;
class Number
{
    int number;

public:
    Number(int n) : number(n) {}
    Number &operator--()
    {
        number *= 4;
        return *this;
    }
    Number operator--(int)
    {
        Number temp = *this;
        number /= 4;
        return temp;
    }
    void display() const
    {
        cout << "Number: " << number << endl;
    }
};
int main()
{
    Number num(2);

    cout << "Original: ";
    num.display();

    cout << "--Original";
    --num;
    num.display();
    cout << "Original--";
    
    num--;
    num.display();
    return 0;
}