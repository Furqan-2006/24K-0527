#include <iostream>
using namespace std;

class Shape
{
public:
    virtual float getArea() const = 0;
    virtual ~Shape() {}
};

class Rectangle : public Shape
{
private:
    float length, width;

public:
    Rectangle(float l, float w) : length(l), width(w) {}

    float getArea() const override
    {
        return length * width;
    }
};

class Triangle : public Shape
{
private:
    float base, height;

public:
    Triangle(float b, float h) : base(b), height(h) {}

    float getArea() const override
    {
        return 0.5f * base * height;
    }
};

int main()
{
    Shape *rect = new Rectangle(5.0f, 3.0f);
    Shape *tri = new Triangle(4.0f, 6.0f);

    cout << "Area of Rectangle: " << rect->getArea() << endl;
    cout << "Area of Triangle: " << tri->getArea() << endl;

    delete rect;
    delete tri;

    return 0;
}
