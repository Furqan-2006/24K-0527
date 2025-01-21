#include <stdio.h>

int main()
{
    int a, b, c;
    printf("Enter First Number(a): ");
    scanf("%d", &a);
    printf("Enter Second Number(b): ");
    scanf("%d", &b);
    c = a;
    a = b;
    b = c;
    printf("Values After swapping:\n");
    printf("a = %d \n", a);
    printf("b = %d \n", b);
    return 0;
}
