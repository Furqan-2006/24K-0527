#include <iostream>

class Inventory
{
public:
    double *prices;
    int size;

    Inventory(int s, double pr[])
    {
        size = s;
        prices = new double[size];

        for (int i = 0; i < size; i++)
        {
            prices[i] = pr[i];
        }
    }
    ~Inventory() {}

    Inventory(const Inventory &other)
    {
        size = other.size;
        prices = new double[size];
        for (int i = 0; i < size; i++)
        {
            this->prices[i] = other.prices[i];
        }
    }

    Inventory &operator=(const Inventory &other)
    {
        size = other.size;
        prices = new double[size];
        for (int i = 0; i < size; i++)
        {
            this->prices[i] = other.prices[i];
        }
    }

    void setPrice(int pos, double pr)
    {
        prices[pos] = pr;
    }

    void DisplayAll()
    {
        std::cout << "Prices: \n";
        for (int i = 0; i < size; i++)
        {
            std::cout << i + 1 << ". " << prices[i] << "\n";
        }
    }
};

int main()
{
    double pr[5] = {23.22, 10.00, 33.05, 1.99, 99};
    Inventory I1(5, pr);
    Inventory I2(I1);

    I2.setPrice(3, 0.00);

    I1.DisplayAll();
    I2.DisplayAll();
}
