#include <stdio.h>

int main()
{
    int size, sum = 0;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int input[size];
    for (int i = 0; i < size; i++)
    {
        printf("Enter integer_%d: ", i + 1);
        scanf("%d", &input[i]);
    }
    for (int i = 0; i < size; i++)
    {
        sum += input[i];
    }
    printf("Sum of the elements of the array is %d.", sum);

    return 0;
}