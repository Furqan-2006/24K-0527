#include <iostream>
#include <string>
using namespace std;

class Shape
{
    int length;
    int width;

public:
    Shape(int len = 0, int wid = 0) : length(len), width(wid) {}
    double Area() const
    {
        return length * width;
    }
    int operator+(const Shape &other)
    {
        int result(Area() + other.Area());
        return result;
    }
};
int main()
{
    Shape shape1(3, 4);
    Shape shape2(2, 10);
    int area = shape1 + shape2;
    cout << area;

    return 0;
}