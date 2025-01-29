#include <iostream>
using namespace std;

int *resizeArray(int *arr, int &cap)
{
    int newCap = cap + 2;
    int *newArray = new int[newCap];

    for (int i = 0; i < cap; i++)
    {
        newArray[i] = arr[i];
    }

    delete[] arr;
    cap = newCap;
    return newArray;
}

int main()
{
    int cap = 5;
    int size = 0;
    char choice;
    int *arr = new int[cap];

    do
    {
        if (cap <= size)
        {
            arr = resizeArray(arr, cap);
        }

        cout << "Enter an element: ";
        cin >> arr[size];
        size++;

        cout << "Do you want to add more elements? If yes, press 'y': ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    cout << "The array is: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
    delete[] arr;
    return 0;
}
