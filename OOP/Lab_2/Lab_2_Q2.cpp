#include <iostream>
#include <cstdlib>

using namespace std;

void *addToArray(void *arr, int size, int addValue)
{
    int *intArr = static_cast<int *>(arr);
    for (int i = 0; i < size; i++)
    {
        intArr[i] += addValue;
    }
    return arr;
}

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        cout << "Usage: " << argv[0] << " <size> <elements>...\n";
        return 1;
    }

    int size = atoi(argv[1]);
    if (argc != size + 2)
    {
        cout << "Error: Please provide exactly " << size << " elements.\n";
        return 1;
    }

    int *arr = new int[size];

    for (int i = 0; i < size; i++)
    {
        arr[i] = atoi(argv[i + 2]);
    }

    int addValue = 5;
    arr = static_cast<int *>(addToArray(arr, size, addValue));

    cout << "Modified Array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    return 0;
}
