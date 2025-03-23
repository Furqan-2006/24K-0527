#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Shape
{
protected:
    string color;
    double borderThickness;

public:
    Shape(string c = "black", double bt = 1.0) : color(c), borderThickness(bt) {}

    virtual void draw() const = 0;
    virtual double calculateArea() const = 0;
    virtual double calculatePerimeter() const = 0;

    virtual ~Shape() {}
};

class Circle : public Shape
{
private:
    double radius;
    pair<double, double> center;

public:
    Circle(double r, pair<double, double> c, string col = "black", double bt = 1.0)
        : Shape(col, bt), radius(r), center(c) {}

    void draw() const override
    {
        cout << "Drawing Circle at (" << center.first << ", " << center.second << ") with radius " << radius << endl;
    }

    double calculateArea() const override
    {
        return M_PI * radius * radius;
    }

    double calculatePerimeter() const override
    {
        return 2 * M_PI * radius;
    }
};

class Rectangle : public Shape
{
private:
    double width, length;
    pair<double, double> topLeftCorner;

public:
    Rectangle(double w, double l, pair<double, double> tlc, string col = "black", double bt = 1.0)
        : Shape(col, bt), width(w), length(l), topLeftCorner(tlc) {}

    void draw() const override
    {
        cout << "Drawing Rectangle at (" << topLeftCorner.first << ", " << topLeftCorner.second
             << ") with width " << width << " and height " << length << endl;
    }

    double calculateArea() const override
    {
        return width * length;
    }

    double calculatePerimeter() const override
    {
        return 2 * (width + length);
    }
};

class Triangle : public Shape
{
private:
    pair<double, double> vertex1, vertex2, vertex3;

    double distance(pair<double, double> p1, pair<double, double> p2) const
    {
        return sqrt(pow(p2.first - p1.first, 2) + pow(p2.second - p1.second, 2));
    }

public:
    Triangle(pair<double, double> v1, pair<double, double> v2, pair<double, double> v3,
             string col = "black", double bt = 1.0)
        : Shape(col, bt), vertex1(v1), vertex2(v2), vertex3(v3) {}

    void draw() const override
    {
        cout << "Drawing Triangle with vertices at (" << vertex1.first << ", " << vertex1.second
             << "), (" << vertex2.first << ", " << vertex2.second
             << "), (" << vertex3.first << ", " << vertex3.second << ")" << endl;
    }

    double calculatePerimeter() const override
    {
        return distance(vertex1, vertex2) + distance(vertex2, vertex3) + distance(vertex3, vertex1);
    }

    double calculateArea() const override
    {
        double s = calculatePerimeter() / 2;
        return sqrt(s * (s - distance(vertex1, vertex2)) * (s - distance(vertex2, vertex3)) * (s - distance(vertex3, vertex1)));
    }
};

class Polygon : public Shape
{
private:
    vector<pair<double, double>> vertices;

    double distance(pair<double, double> p1, pair<double, double> p2) const
    {
        return sqrt(pow(p2.first - p1.first, 2) + pow(p2.second - p1.second, 2));
    }

public:
    Polygon(vector<pair<double, double>> verts, string col = "black", double bt = 1.0)
        : Shape(col, bt), vertices(verts) {}

    void draw() const override
    {
        cout << "Drawing Polygon with " << vertices.size() << " vertices." << endl;
    }

    double calculatePerimeter() const override
    {
        double perimeter = 0.0;
        for (int i = 0; i < vertices.size(); i++)
        {
            perimeter += distance(vertices[i], vertices[(i + 1) % vertices.size()]);
        }
        return perimeter;
    }

    double calculateArea() const override
    {
        double area = 0.0;
        int n = vertices.size();
        for (int i = 0; i < n; i++)
        {
            int j = (i + 1) % n;
            area += vertices[i].first * vertices[j].second;
            area -= vertices[j].first * vertices[i].second;
        }
        return fabs(area) / 2.0;
    }
};

int main()
{
    Circle c(5, {2, 3}, "red", 1.5);
    c.draw();
    cout << "Circle Area: " << c.calculateArea() << endl;
    cout << "Circle Perimeter: " << c.calculatePerimeter() << endl;

    Rectangle r(4, 6, {1, 1}, "blue", 2.0);
    r.draw();
    cout << "Rectangle Area: " << r.calculateArea() << endl;
    cout << "Rectangle Perimeter: " << r.calculatePerimeter() << endl;

    Triangle t({0, 0}, {3, 0}, {3, 4}, "green", 1.0);
    t.draw();
    cout << "Triangle Area: " << t.calculateArea() << endl;
    cout << "Triangle Perimeter: " << t.calculatePerimeter() << endl;

    vector<pair<double, double>> polyVertices = {{0, 0}, {4, 0}, {4, 3}, {2, 5}, {0, 3}};
    Polygon p(polyVertices, "yellow", 1.2);
    p.draw();
    cout << "Polygon Area: " << p.calculateArea() << endl;
    cout << "Polygon Perimeter: " << p.calculatePerimeter() << endl;

    return 0;
}
