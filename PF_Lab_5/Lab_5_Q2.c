#include <stdio.h>

int main()
{
    int num;
    printf("Input a Number: ");
    scanf("%d", &num);
    if (num > 0)
    {
        printf("It is a positive number, ");
        if (num % 2 == 0)
        {
            printf("And its also Even.");
        }
        else
        {
            printf("And its also Odd.");
        }
    }
    else if (num < 0)
    {
        printf("It is a Negative number.");
    }
    else
    {
        printf("It is Zero.");
    }

    return 0;
}