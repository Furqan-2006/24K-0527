#include <stdio.h>

int main()
{
    int size;
    int max = 0, min = 0;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int num[size];

    for (int i = 0; i < size; i++)
    {
        printf("Enter integer_%d: ", i + 1);
        scanf("%d", &num[i]);
    }

    max = num[0];
    for (int i = 0; i < size; i++)
    {
        if (max < num[i])
        {
            max = num[i];
        }
    }

    min = num[0];
    for (int i = 0; i < size; i++)
    {

        if (min > num[i])
        {
            min = num[i];
        }
    }

    printf("\nThe maximum number in the array is '%d'.", max);
    printf("\nThe minimum number in the array is '%d'.", min);

    return 0;
}