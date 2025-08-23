#include <iostream>

using namespace std;

int main()
{
    double *arr = new double[7];

    cout << "Input the Daily Temp: " << endl;
    double sum = 0;
    for (int i = 0; i < 7; i++)
    {
        cout << "Day " << i + 1 << ": ";
        cin >> arr[i];
        sum += arr[i];
    }
    cout << endl
         << "Displaying all the input " << endl;
    double avrage = sum / 7;
    for (int i = 0; i < 7; i++)
    {
        cout << "Day " << i + 1 << ": " << *(arr + i) << endl;
    }
    cout << "Average: " << avrage << endl;

    delete[] arr;
    getchar();
}