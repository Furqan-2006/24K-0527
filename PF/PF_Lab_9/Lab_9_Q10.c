#include <stdio.h>

void minMax(int arr[], int size)
{
    int min, max;
    min = max = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    printf("The maximium value in array is %d.\n", max);
    printf("The minimum value in array is %d.\n", min);
}
int main()
{
    int numbers[10] = {22, 34, 123, 4, 52, 2, 15, 64, 23, 12};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    minMax(numbers, size);

    return 0;
}