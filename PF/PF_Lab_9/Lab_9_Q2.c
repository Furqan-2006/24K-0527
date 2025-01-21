#include <stdio.h>

int evenOdd(int a)
{
    if (a % 2 == 0)
    {
        return 1;
    }
    return 0;
}
int main()
{
    int num;
    printf("Enter a number to check whether its even or odd: ");
    scanf(" %d", &num);
    if (evenOdd(num) == 1)
    {
        printf("The number is even.");
    }
    else
    {
        printf("The number is odd.");
    }

    return 0;
}