#include <iostream>
using namespace std;

int main()
{
    int arr[7] = {2, 31, 4, 8, 4, 8, 19};
    int *ar2 = arr;
    int sum = 0;

    for (int i = 0; i < 7; i++)
    {
        sum += (*ar2++);
    }

    cout << "Sum: " << sum << endl;

    return 0;
}