#include <iostream>
using namespace std;

int Sum(int arrSize, int arr[])
{
    int sum = 0;
    for (int i = 0; i < arrSize; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int main()
{
    int arrSize;
    cout << "Enter the size of array: ";
    cin >> arrSize;
    int arr2;
    int *arr = &arr2;
    for (int i = 0; i < arrSize; i++)
    {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
        // cout << arr[i];
    }

    int result = Sum(arrSize, arr);
    cout << "Sum of elements of array is " << result << "." << endl;

    return 0;
}
