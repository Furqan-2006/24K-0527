#include <stdio.h>

int main()
{
    int size = 0;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int num[size];
    for (int i = 0; i < size; i++)
    {
        printf("Enter Element_%d: ", (i + 1));
        scanf("%d", &num[i]);
        if (num[i] > 9999 || num[i] < 0)
        {
            printf("Number must be greater than 0 and less than 9999.");
            return 0;
        }
    }
    int smallest = 9999;
    int sec_small = 9999;
    for (int i = 0; i < size; i++)
    {
        if (num[i] < smallest  )
        {
            sec_small = smallest;
            smallest = num[i];
        }
        else if (num[i]<sec_small && num[i] != smallest )
        {
            sec_small = num[i];
        }
        
    }
    // printf("\nThe smallest number is %d\n", smallest);
    printf("The second smallest number is %d\n", sec_small);

    return 0;
}