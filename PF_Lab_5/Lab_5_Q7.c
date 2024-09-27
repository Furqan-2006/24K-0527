#include <stdio.h>

int main()
{
    int a, b;
    printf("Enter a number:");
    scanf("%d", &a);
    printf("Enter a number:");
    scanf("%d", &b);

    printf("\nValues before swaping:");
    printf("\na : %d", a);
    printf("\nb: %d", b);

    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    printf("\nValues after swaping:");
    printf("\na : %d", a);
    printf("\nb: %d", b);
    return 0;
}