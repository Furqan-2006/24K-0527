#include <stdio.h>

int main()
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int values[size];

    for (int i = 0; i < size; i++)
    {
        printf("Enter integer_%d: ", i + 1);
        scanf("%d", &values[i]);
    }

    // Printing Original Array
    printf("THe original array is: ");
    printf("{");
    for (int i = 0; i < size; i++)
    {
        printf("%d", values[i]);
        if (i < (size - 1))
        {
            printf(", ");
        }
    }
    printf("}\n");

    // Printing Reversed Array
    printf("The reversed array is: ");
    printf("{");
    for (int i = (size - 1); i >= 0; i--)
    {
        printf("%d", values[i]);
        if (i > 0)
        {
            printf(", ");
        }
    }
    printf("}\n");
    return 0;
}