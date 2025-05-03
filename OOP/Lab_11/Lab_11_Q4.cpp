#include <iostream>
using namespace std;

template <typename T>
class Base
{
protected:
    T a, b;

public:
    Base(T a, T b) : a(a), b(b) {}

    void printProduct() const
    {
        cout << "Base product: " << a * b << endl;
    }
};

template <typename T>
class Derived : public Base<T>
{
    T c, d;

public:
    Derived(T a, T b, T c, T d) : Base<T>(a, b), c(c), d(d) {}

    void printProduct() const
    {
        Base<T>::printProduct();
        cout << "Derived product: " << c * d << endl;
    }
};

int main()
{
    Derived<int> obj(2, 3, 4, 5);
    obj.printProduct();

    return 0;
}
