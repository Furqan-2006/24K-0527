#include <iostream>
#include <exception>
using namespace std;

class ArrayIndexOutOfBounds : public exception
{
public:
    const char *what() const noexcept override
    {
        return "Array index out of bounds!";
    }
};

template <typename T>
class SafeArray
{
    T *data;
    int size;

public:
    SafeArray(int s) : size(s)
    {
        data = new T[size];
    }

    ~SafeArray()
    {
        delete[] data;
    }

    T &operator[](int index)
    {
        if (index < 0 || index >= size)
            throw ArrayIndexOutOfBounds();
        return data[index];
    }

    int getSize() const
    {
        return size;
    }
};

int main()
{
    try
    {
        SafeArray<int> arr(5);
        for (int i = 0; i < arr.getSize(); ++i)
            arr[i] = i * 2;

        cout << "Element at index 2: " << arr[2] << endl;

        cout << "Element at index 10: " << arr[10] << endl;
    }
    catch (const ArrayIndexOutOfBounds &e)
    {
        cerr << "Exception: " << e.what() << endl;
    }

    return 0;
}
