#include <iostream>
using namespace std;

class Circle
{
    float radius;
    const float PI = 3.1416;

public:
    Circle(float rad) : radius(rad) {}

    void getArea()
    {
        double area = PI * (radius * radius);
        cout << "The Area of circle is: " << area << endl;
    }

    void getPerimeter()
    {
        double perimeter = 2 * PI * radius;
        cout << "The Perimeter of the circle is: " << perimeter << endl;
    }
};

int main()
{
    Circle c1(2), c2(6), c3(18);

    c1.getArea();
    c2.getArea();
    c3.getArea();
    cout << "\n";

    c1.getPerimeter();
    c2.getPerimeter();
    c3.getPerimeter();

    return 0;
}
