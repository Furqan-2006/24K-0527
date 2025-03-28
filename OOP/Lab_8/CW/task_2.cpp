#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Polynomial;

class PolynomialUtils {
public:
    static int evaluate(const Polynomial &p, int x);
    static Polynomial derivative(const Polynomial &p);
};

class Polynomial {
private:
    vector<int> coefficients; // Coefficients, index i represents x^i
    void trim(); // Removes leading zeros

public:
    Polynomial() {}
    Polynomial(const vector<int> &coeffs) : coefficients(coeffs) { trim(); }
    
    Polynomial operator+(const Polynomial &other) const;
    Polynomial operator-(const Polynomial &other) const;
    Polynomial operator*(const Polynomial &other) const;
    
    friend ostream &operator<<(ostream &out, const Polynomial &p);
    friend class PolynomialUtils;
};

void Polynomial::trim() {
    while (!coefficients.empty() && coefficients.back() == 0) {
        coefficients.pop_back();
    }
}

Polynomial Polynomial::operator+(const Polynomial &other) const {
    size_t maxSize = max(coefficients.size(), other.coefficients.size());
    vector<int> result(maxSize, 0);
    for (size_t i = 0; i < maxSize; i++) {
        if (i < coefficients.size()) result[i] += coefficients[i];
        if (i < other.coefficients.size()) result[i] += other.coefficients[i];
    }
    return Polynomial(result);
}

Polynomial Polynomial::operator-(const Polynomial &other) const {
    size_t maxSize = max(coefficients.size(), other.coefficients.size());
    vector<int> result(maxSize, 0);
    for (size_t i = 0; i < maxSize; i++) {
        if (i < coefficients.size()) result[i] += coefficients[i];
        if (i < other.coefficients.size()) result[i] -= other.coefficients[i];
    }
    return Polynomial(result);
}

Polynomial Polynomial::operator*(const Polynomial &other) const {
    vector<int> result(coefficients.size() + other.coefficients.size() - 1, 0);
    for (size_t i = 0; i < coefficients.size(); i++) {
        for (size_t j = 0; j < other.coefficients.size(); j++) {
            result[i + j] += coefficients[i] * other.coefficients[j];
        }
    }
    return Polynomial(result);
}

ostream &operator<<(ostream &out, const Polynomial &p) {
    if (p.coefficients.empty()) {
        out << "0";
        return out;
    }
    for (int i = p.coefficients.size() - 1; i >= 0; i--) {
        if (p.coefficients[i] == 0) continue;
        if (i != p.coefficients.size() - 1) out << (p.coefficients[i] > 0 ? " + " : " - ");
        else if (p.coefficients[i] < 0) out << "-";
        out << abs(p.coefficients[i]);
        if (i > 0) out << "x";
        if (i > 1) out << "^" << i;
    }
    return out;
}

int PolynomialUtils::evaluate(const Polynomial &p, int x) {
    int result = 0, power = 1;
    for (int coeff : p.coefficients) {
        result += coeff * power;
        power *= x;
    }
    return result;
}

Polynomial PolynomialUtils::derivative(const Polynomial &p) {
    if (p.coefficients.size() <= 1) return Polynomial({0});
    vector<int> deriv(p.coefficients.size() - 1);
    for (size_t i = 1; i < p.coefficients.size(); i++) {
        deriv[i - 1] = p.coefficients[i] * i;
    }
    return Polynomial(deriv);
}

int main() {
    Polynomial p1({2, 3, 0, 5}); // 5x^3 + 3x + 2
    Polynomial p2({1, -1, 4});   // 4x^2 - x + 1
    
    cout << "P1: " << p1 << endl;
    cout << "P2: " << p2 << endl;
    
    cout << "P1 + P2: " << (p1 + p2) << endl;
    cout << "P1 - P2: " << (p1 - p2) << endl;
    cout << "P1 * P2: " << (p1 * p2) << endl;
    
    cout << "P1 evaluated at x=2: " << PolynomialUtils::evaluate(p1, 2) << endl;
    cout << "Derivative of P1: " << PolynomialUtils::derivative(p1) << endl;
    return 0;
}
