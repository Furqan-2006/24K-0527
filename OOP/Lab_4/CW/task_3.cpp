#include <iostream>
using namespace std;

class DynamicArray
{
    int *data;
    int len;

public:
    DynamicArray() : data(nullptr), len(0) {} // Default Constructor

    DynamicArray(int n) : len(n) { data = new int[len]{}; } // parameterized constructor

    DynamicArray(const DynamicArray &arr) : len(arr.len) // Copy Constructor
    {
        data = new int[len];
        for (int i = 0; i < len; i++)
        {
            data[i] = arr.data[i];
        }
    }
    DynamicArray(DynamicArray &&arr) noexcept : len(arr.len), data(arr.data) // move Constructor
    {
        arr.len = 0;
        arr.data = nullptr;
    }
    DynamicArray &operator=(const DynamicArray &other) // Assignment Operator
    {
        if (this == &other)
            return *this;
        delete[] data;
        len = other.len;
        data = new int[len];
        for (int i = 0; i < len; i++)
        {
            data[i] = other.data[i];
        }
        return *this;
    }
    DynamicArray &operator=(DynamicArray &other) noexcept
    {
        if (this == &other)
        {
            return *this;
        }
        delete[] data;
        data = other.data;
        len = other.len;
        other.data = nullptr;
        other.len = 0;
        return *this;
    }

    ~DynamicArray()
    {
        delete[] data;
    }

    int size()
    {
        return len;
    }
    int &at(int index)
    {
        if (index < 0 || index >= len)
        {
            throw out_of_range("Index out of bounds!");
        }
        return data[index];
    }

    void resize(int newlen)
    {
        if (newlen == len)
        {
            return;
        }
        int *newData = new int[newlen];
        int copylen = (newlen > len) ? newlen : len;
        for (int i = 0; i < copylen; i++)
        {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        len = newlen;
    }

    void display() const
    {
        for (int i = 0; i < len; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    DynamicArray arr(5);
    for (int i = 0; i < arr.size(); i++)
    {
        arr.at(i) = i * 2;
    }
    cout << "Array contents: ";
    arr.display();

    DynamicArray arrCopy = arr;
    cout << "Copied array: ";
    arrCopy.display();

    DynamicArray arrMoved = move(arr);
    cout << "Moved array: ";
    arrMoved.display();

    arrCopy.resize(7);
    cout << "Resized copied array: ";
    arrCopy.display();

    return 0;
}