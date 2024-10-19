#include <stdio.h>

int main()
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
    printf("\nEnter numbers in range [0 , %d) \n", size);

    for (int i = 0; i < size; i++)
    {
        printf("Enter integer_%d: ", i + 1);
        scanf("%d", &arr[i]);
        if (arr[i] < 0 || arr[i] > (size - 1))
        {
            printf("Invalid Input! The input must be in range.");
            return 0;
        }
    }

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    int lastPrinted = -1;
    int repeated[size];
    for (int i = 0; i < size; i++)
    {
        repeated[i] = 0;
    }

    for (int i = 1; i < size; i++)
    {
        if (arr[i] == arr[i - 1] && arr[i] != lastPrinted)
        {
            repeated[i] = arr[i];
            lastPrinted = arr[i];
        }
    }

    for (int i = 0; i < size; i++)
    {
        if (repeated[i] != 0)
        {
            printf("'%d' ", repeated[i]);
        }
    }
    printf(" are the repeated numbers.");

    return 0;
}
