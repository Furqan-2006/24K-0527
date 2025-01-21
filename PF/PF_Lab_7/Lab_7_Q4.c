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

    int max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (max < arr[i])
            max = arr[i];
    }

    int repeated[max + 1];
    for (int i = 0; i <= max; i++)
    {
        repeated[i] = 0;
    }

    for (int i = 0; i < size; i++)
    {
        repeated[arr[i]]++;
    }

    for (int i = 0; i <= max; i++)
    {
        if (repeated[i] > 1)
            printf("'%d' ", i);
    }
    printf(" are the repeated numbers.");

    return 0;
}
