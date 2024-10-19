#include <stdio.h>

int main()
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    for (int i = 0; i < size; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
        if (arr[i] < 0 || arr[i] >= size)
        {
            printf("Invalid input! %d is out of range [0, %d)\n", arr[i], size);
            return 1;  
        }
    }

    int foundDuplicate = 0;
    printf("Numbers occurring more than once: ");

    for (int i = 0; i < size; i++)
    {
        int index = arr[i];
        if (arr[index] >= 0)
        {
            arr[index] = -arr[index];
        }
        else
        {
            printf("%d ", index);
            foundDuplicate = 1;
            arr[index] = -10000;
        }
    }

    if (!foundDuplicate)
    {
        printf("None");
    }

    printf("\n");

    return 0;
}
