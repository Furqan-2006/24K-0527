#include <stdio.h>

int main()
{
    int num_1, num_2, num_3;

    printf("Enter Num_1: ");
    scanf("%d", &num_1);
    printf("Enter Num_2: ");
    scanf("%d", &num_2);
    printf("Enter Num_3: ");
    scanf("%d", &num_3);

    if (num_1 == num_2 && num_1 == num_3)
    {
        printf("All numbers are equal.\n");
    }
    else if ((num_1 != num_2) && (num_2 != num_3) && (num_3 != num_1))
    {
        if (num_1 > num_2)
        {
            if (num_1 > num_3)
            {
                printf("Num_1 is the greatest.\n");
            }
            else
            {
                printf("Num_3 is the greatest.\n");
            }
        }
        else
        {
            if (num_2 > num_3)
            {
                printf("Num_2 is the greatest.\n");
            }
            else
            {
                printf("Num_3 is the greatest.\n");
            }
        }
    }
    else
    {
        printf("Two numbers are equal.");
    }

    return 0;
}
