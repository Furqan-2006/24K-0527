#include <stdio.h>

int main()
{
    int num;
    printf("Input a Number: ");
    scanf("%d", &num);
    (num > 0) ? printf("Number is positive.") : 
    ((num < 0) ? printf("Number is negative.") : printf("Number is zero."));
    return 0;
}