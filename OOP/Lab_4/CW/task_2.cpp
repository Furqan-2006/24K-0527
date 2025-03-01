#include <iostream>
#include <cmath>
using namespace std;

class Polynomial
{
private:
    double *coefficients;
    int degree;

public:
    // Default Constructor
    Polynomial() : degree(0)
    {
        coefficients = new double[1]{0};
    }

    // Parameterized Constructor
    Polynomial(int deg, const double coeffs[]) : degree(deg)
    {
        coefficients = new double[degree + 1];
        for (int i = 0; i <= degree; i++)
        {
            coefficients[i] = coeffs[i];
        }
    }

    // Copy Constructor
    Polynomial(const Polynomial &p) : degree(p.degree)
    {
        coefficients = new double[degree + 1];
        for (int i = 0; i <= degree; i++)
        {
            coefficients[i] = p.coefficients[i];
        }
    }

    // Move Constructor
    Polynomial(Polynomial &&p) noexcept : degree(p.degree), coefficients(p.coefficients)
    {
        p.coefficients = nullptr;
        p.degree = 0;
    }

    ~Polynomial()
    {
        delete[] coefficients;
    }

    int getDegree() const
    {
        return degree;
    }

    double evaluate(double x) const
    {
        double result = 0.0;
        for (int i = 0; i <= degree; i++)
        {
            result += coefficients[i] * pow(x, i);
        }
        return result;
    }

    Polynomial add(const Polynomial &p) const
    {
        int maxDegree = max(degree, p.degree);
        double *newCoeffs = new double[maxDegree + 1]{};

        for (int i = 0; i <= degree; i++)
        {
            newCoeffs[i] += coefficients[i];
        }
        for (int i = 0; i <= p.degree; i++)
        {
            newCoeffs[i] += p.coefficients[i];
        }

        return Polynomial(maxDegree, newCoeffs);
    }

    Polynomial multiply(const Polynomial &p) const
    {
        int newDegree = degree + p.degree;
        double *newCoeffs = new double[newDegree + 1]{};

        for (int i = 0; i <= degree; i++)
        {
            for (int j = 0; j <= p.degree; j++)
            {
                newCoeffs[i + j] += coefficients[i] * p.coefficients[j];
            }
        }

        return Polynomial(newDegree, newCoeffs);
    }

    void display() const
    {
        for (int i = degree; i >= 0; i--)
        {
            cout << coefficients[i] << "x^" << i;
            if (i > 0)
                cout << " + ";
        }
        cout << endl;
    }
};

int main()
{
    double coeffs1[] = {2, 3, 4};
    Polynomial p1(2, coeffs1);

    double coeffs2[] = {1, 2};
    Polynomial p2(1, coeffs2);

    cout << "Polynomial 1: ";
    p1.display();
    cout << "Polynomial 2: ";
    p2.display();

    Polynomial sum = p1.add(p2);
    cout << "Sum: ";
    sum.display();

    Polynomial product = p1.multiply(p2);
    cout << "Product: ";
    product.display();

    cout << "Evaluation of p1 at x=2: " << p1.evaluate(2) << endl;

    return 0;
}
