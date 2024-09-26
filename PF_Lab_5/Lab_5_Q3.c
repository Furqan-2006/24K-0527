#include <stdio.h>

int main()
{
    int num;
    printf("Input a Number: ");
    scanf("%d", &num);
    if ((num % 3 == 0) && (num % 5 == 0))
    {
        printf("Number is divisible by both 3 and 5.");
    }
    else if (num % 3 == 0 && num % 5 != 0)
    {
        printf("Number is divisible by 3 only.");
    }
    else if (num % 5 == 0 && num % 3 != 0)
    {
        printf("Number is divisible by 5 only.");
    }
    else
    {
        printf("Number is not divisible by any (3 or 5).");
    }

    return 0;
}