#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    float arr[20] = {2.0, 3, 12, 1.4, 21, 43, 12, 42, 3.23, 12, 12.3, 43, 56, 34, 23, 2.5, 46, 2, 4, 52};
    float firLarge = arr[0], secLarge = arr[0];
    float *ar2 = arr;
    for (int i = 0; i < 20; i++)
    {
        ar2++;
        if (*ar2 > firLarge)
        {
            firLarge = *ar2;
        }
                if ((*ar2 > secLarge) && (firLarge != *ar2))
        {
            secLarge = *ar2;
        }
    }

    cout << "First Large: " << firLarge << endl;
    cout << "Second Large: " << secLarge << endl;

    return 0;
}
